import socket
import errno
from threading import Thread

HEADER_LENGTH = 10
client_socket = None
# ip = "192.168.137.1"
# port = 6969


# Connects to the server
def connect(ip, port, my_username, error_callback):
    global client_socket

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        # Connect to a given ip and port
        client_socket.connect((ip, port))
    except Exception as e:
        # Connection error
        error_callback('Connection error: {}'.format(str(e)))
        return False

    username = my_username.encode('utf-8')
    username_header = f"{len(username):<{HEADER_LENGTH}}".encode('utf-8')
    client_socket.send(username_header + username)

    return True


# Sends a message to the server
def send(message):
    message = message.encode('utf-8')
    message_header = f"{len(message):<{HEADER_LENGTH}}".encode('utf-8')
    client_socket.send(message_header + message)


def start_listening(incoming_message_callback, error_callback):
    Thread(target=listen, args=(incoming_message_callback, error_callback), daemon=True).start()


# Listens for incomming messages
def listen(incoming_message_callback, error_callback):
    while True:

        try:
            while True:

                username_header = client_socket.recv(HEADER_LENGTH)

                if not len(username_header):
                    error_callback('Connection closed by the server')

                username_length = int(username_header.decode('utf-8').strip())

                username = client_socket.recv(username_length).decode('utf-8')

                message_header = client_socket.recv(HEADER_LENGTH)
                message_length = int(message_header.decode('utf-8').strip())
                message = client_socket.recv(message_length).decode('utf-8')

                # Print message
                incoming_message_callback(username, message)

        except Exception as e:
            error_callback('Reading error: {}'.format(str(e)))
