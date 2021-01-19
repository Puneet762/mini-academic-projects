
import re
import urllib.request
import urllib.parse
from selenium import webdriver
from bs4 import BeautifulSoup

SEARCH_FOR = input("Search for: ")
TO_FIND = input("Regex to search for in websites: ")
SEARCH_FUNCTION = re.compile(TO_FIND)

VISITED = list()
ADDED = list()

QUERRY = urllib.parse.urlencode({'q': SEARCH_FOR})
DRIVER = webdriver.chrome.webdriver.WebDriver(executable_path='C:/Users/admin/Downloads/chromedriver_win32/chromedriver.exe')
FILE_OUTPUT = open('result.txt', 'wb')

print('FLipcart:')
F_URL = 'https://www.flipkart.com/search?%s'
MY_URL = (F_URL) % QUERRY
DRIVER.get(MY_URL)
SOUP = BeautifulSoup(DRIVER.execute_script('return document.documentElement.innerHTML;'),
                     'html.parser')
main_content = SOUP.find_all('div', class_='_4ddWXP')
links = []
productlink = []

for _4ddWXP in main_content:
      for link in _4ddWXP.find_all('a',href=True):
        print(link['href'])
        links.append(link['href'])
#print(SOUP.prettify())
for _4ddWXP in main_content:
    for link in _4ddWXP.find_all('a', href=True):
        page_url = ("https://www.flipkart.com" + link['href'])
        if page_url in VISITED:
            continue
        else:
            VISITED.append(page_url)
        print(f'Crawling ......{(page_url)}')
        DRIVER.get(page_url)
        page = DRIVER.execute_script('return document.documentElement.innerHTML;')
        found = re.findall(SEARCH_FUNCTION, page)
        for one_of in found:
            print('- {}'.format(one_of))
            if one_of in ADDED:
                continue
            else:
                ADDED.append(one_of)
            FILE_OUTPUT.write(one_of.encode("utf8") + '\n'.encode('utf8'))

# for result in SOUP.find_all('a', attrs={'class':'result__a'}):
#     page_url = result.get('href')
#     if page_url in VISITED:
#         continue
#     else:
#         VISITED.append(page_url)
#     print('Crawling .....'.format(page_url))
#     DRIVER.get(page_url)
#     page = DRIVER.execute_script('return document.documentElement.innerHTML;')
#     found = re.findall(SEARCH_FUNCTION, page)
#     for one_of in found:
#         print('- {}'.format(one_of))
#         if one_of in ADDED:
#             continue
#         else:
#             ADDED.append(one_of)
#         FILE_OUTPUT.write(one_of.encode("utf8") + '\n'.encode('utf8'))

print('Bing:')
BING_URL = 'https://www.bing.com/search?%s' % QUERRY
DRIVER.get(BING_URL)
SOUP = BeautifulSoup(DRIVER.execute_script('return document.documentElement.innerHTML;'),
                     'html.parser')

# for result in SOUP.find_all('li', attrs={'class':'b_algo'}):
#     page_url = result.find('a').get('href')
#     if page_url in VISITED:
#         continue
#     else:
#         VISITED.append(page_url)
#     print('Crawling {} ...'.format(page_url))
#     DRIVER.get(page_url)
#     page = DRIVER.execute_script('return document.documentElement.innerHTML;')
#     found = re.findall(SEARCH_FUNCTION, page)
#     for one_of in found:
#         print('- {}'.format(one_of))
#         if one_of in ADDED:
#             continue
#         else:
#             ADDED.append(one_of)
#         FILE_OUTPUT.write(one_of.encode("utf8") + '\n'.encode('utf8'))

# print('SHOPCLUES:')
# YAHOO_URL = 'https://www.shopclues.com/search?%s' % QUERRY
# DRIVER.get(YAHOO_URL)
# SOUP = BeautifulSoup(DRIVER.execute_script('return document.documentElement.innerHTML;'),
#                      'html.parser')
# main_content2 = SOUP.find_all('div', class_='row')
# links = []
# for row in main_content2:
#       for link in row.find_all('a',href=True):
#         print(link['href'])
#         links.append(link['href'])
#
# for row in main_content2:
#     for link in row.find_all('a', href=True):
#         page_url = ("https://www.shopclues.com/" + link['href'])
#     if page_url in VISITED:
#         continue
#     else:
#         VISITED.append(page_url)
#     print('Crawling {} ...'.format(page_url))
#     DRIVER.get(page_url)
#     page = DRIVER.execute_script('return document.documentElement.innerHTML;')
#     found = re.findall(SEARCH_FUNCTION, page)
#     for one_of in found:
#         print('- {}'.format(one_of))
#         if one_of in ADDED:
#             continue
#         else:
#             ADDED.append(one_of)
#         FILE_OUTPUT.write(one_of.encode("utf8") + '\n'.encode('utf8'))

FILE_OUTPUT.close()
