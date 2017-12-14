import threading
from queue import Queue
from spider import Spider
from general import *
from domain import *

PROJECT_NAME = input('Enter Project Name: ')
HOMEPAGE = input('Enter Homepage URL: ')
DOMAIN_NAME = get_domain_name(HOMEPAGE)
QUEUED_FILE = PROJECT_NAME + '/queue.txt'
CRAWLED_FILE = PROJECT_NAME + '/crawled.txt'
NO_OF_THREADS = 8
queue = Queue()
Spider(PROJECT_NAME, HOMEPAGE, DOMAIN_NAME)


# create worker threads (will die when main exits)
def create_workers():
    for _ in range(NO_OF_THREADS):
        t = threading.Thread(target=work)
        t.daemon = True
        t.start()


# Do the next job in the queue
def work():
    while True:
        url = queue.get()
        Spider.crawl_page(threading.current_thread().name, url)
        queue.task_done()


# each queued link is treated as a job
def create_jobs():
    for link in file_to_set(QUEUED_FILE):
        queue.put(link)
    queue.join()
    crawl()


# crawl if there are items in the queue
def crawl():
    queue_links = file_to_set(QUEUED_FILE)
    if len(queue_links) > 0:
        print(str(len(queue_links)) + ' links in the queue')
        create_jobs()


create_workers()
crawl()