import os


# create a new directory for every new project
def create_project_dir(directory):
    if not os.path.exists(directory):
        os.makedirs(directory)
        print('Created Project: {}'.format(directory))


# write new files
def write_file(path, data):
    file = open(path, 'w')
    file.write(data)
    file.close()


# create queue and crawled files (if not exits)
def create_data_files(project_name, base_url):
    queue = project_name + '/queue.txt'
    crawled = project_name + '/crawled.txt'

    if not os.path.isfile(queue):
        write_file(queue, base_url)

    if not os.path.isfile(crawled):
        write_file(crawled, '')


# write data to existing file
def append_to_file(path, data):
    with open(path, 'a') as file:
        file.write(data + '\n')


# delete data from file
def delete_file_contents(path):
    with open(path, 'w'):
        pass


# write data from file to a set
def file_to_set(file_name):
    results = set()
    with open(file_name, 'rt') as file:
        for line in file:
            results.add(line.replace('\n', ''))
    return results


# write data from a set to file
def set_to_file(links, file_name):
    delete_file_contents(file_name)
    for link in sorted(links):
        append_to_file(file_name, link)














