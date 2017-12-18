from bs4 import BeautifulSoup
from datetime import datetime
from notification import generate_notification
import requests
import random
import re
import os

FILE = 'last_date.txt'

DEFAULT_DATE = '01/01/2000'

URL = 'http://exam.dtu.ac.in/result.htm'

user_agents = [
    'Mozilla/5.0 (Windows; U; Windows NT 5.1; it; rv:1.8.1.11) Gecko/20071127 Firefox/2.0.0.11',
    'Opera/9.25 (Windows NT 5.1; U; en)',
    'Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.1.4322; .NET CLR 2.0.50727)',
    'Mozilla/5.0 (compatible; Konqueror/3.5; Linux) KHTML/3.5.5 (like Gecko) (Kubuntu)',
    'Mozilla/5.0 (Windows NT 5.1) AppleWebKit/535.19 (KHTML, like Gecko) Chrome/18.0.1025.142 Safari/535.19',
    'Mozilla/5.0 (Macintosh; Intel Mac OS X 10.7; rv:11.0) Gecko/20100101 Firefox/11.0',
    'Mozilla/5.0 (Macintosh; Intel Mac OS X 10.6; rv:8.0.1) Gecko/20100101 Firefox/8.0.1',
    'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.19 (KHTML, like Gecko) Chrome/18.0.1025.151 Safari/535.19',
    'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:41.0) Gecko/20100101 Firefox/41.0'
]


def conv_string_date(date):
    year = str(date.year)
    month = str(date.month)
    day = str(date.day)
    return(day+'/'+month+'/'+year)


def get_notification_date(link):
    table_row = link.parent.parent.parent
    date_col = table_row.contents[7]
    font_tag = date_col.find('font')
    date_text = font_tag.text
    if len(font_tag.text) == 10:
        return conv_datetime(date_text)
    if date_text == '-----------':
        return conv_datetime(DEFAULT_DATE)
    if ')' in date_text:
        date_text.replace(')', '')
        return conv_datetime(date_text[-10:])
    return conv_datetime(date_text[-10:])



def create_file(path):
    file = open(path, 'w')
    file.write(DEFAULT_DATE)
    file.close()


def write_last_date(date):
    file = open(FILE, 'w')
    file.write(conv_string_date(date))
    file.close()


def conv_datetime(string):
    return datetime.strptime(string, '%d/%m/%Y')


def is_notif_new(date):
    if not os.path.isfile(FILE):
        create_file(FILE)
    file = open(FILE, 'r')
    data = DEFAULT_DATE
    for line in file:
        data = line
    last_date = conv_datetime(data)

    return last_date < date


def main():
    headers = {'User-Agent': user_agents[random.randint(0, 8)]}

    r = requests.get(URL, headers=headers)
    r.raise_for_status()
    html = r.text.encode('utf-8')

    soup = BeautifulSoup(html, 'lxml')

    latest_link = soup.find('a', href=re.compile('.pdf$'))
    date = get_notification_date(latest_link)

    if is_notif_new(date):
        links = soup.find_all('a', href=re.compile('.pdf$'))
        for link in links:
            if is_notif_new(get_notification_date(link)):
                generate_notification('DTU Results', link.text)
            else:
                break
    else:
        generate_notification('DTU Results', 'No new notification!')

    write_last_date(date)

if __name__ == '__main__':
    main()