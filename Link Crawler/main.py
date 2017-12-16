import threading
from queue import Queue
from spider import Spider
from general import *


queue = Queue()


# create worker threads (will die when main exits)
def create_workers(no_of_threads):
    for _ in range(no_of_threads):
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
def create_jobs(queued_file):
    for link in file_to_set(queued_file):
        queue.put(link)
    queue.join()
    crawl(queued_file)


# crawl if there are items in the queue
def crawl(queued_file):
    queue_links = file_to_set(queued_file)
    if len(queue_links) > 0:
        print(str(len(queue_links)) + ' links in the queue')
        create_jobs(queued_file)