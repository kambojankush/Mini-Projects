#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <mutex>
#include <thread>
#include <condition_variable>

struct User {
    int id;
    int group;
    int access_position;
    int arrival_time;
    int usage;
};

const int NUM_OF_RECORDS = 10;

int CURRENT_GROUP = 0;

int CURRENT_GROUP_TOTAL_COUNT = 0;
int CURRENT_GROUP_COMPLETED = 0;

int GROUP_TOTAL_COUNT[2] = { 0 };

int DB_LOCKS[10] = { 0 };

std::mutex mutex_db , mutex_group;

std::condition_variable cond_db[NUM_OF_RECORDS], cond_group;

bool change = true;

int DB_WAIT_COUNT = 0;
int GROUP_WAIT_COUNT = 0;

void change_current_group() {
    if (change) {
        std::unique_lock<std::mutex> locker(mutex_group);
        if (CURRENT_GROUP_COMPLETED == CURRENT_GROUP_TOTAL_COUNT) {
            printf("\nAll users from Group %d finished their execution\n", CURRENT_GROUP);
            CURRENT_GROUP = (CURRENT_GROUP == 1) ? 2 : 1;
            CURRENT_GROUP_COMPLETED = 0;
            CURRENT_GROUP_TOTAL_COUNT = GROUP_TOTAL_COUNT[CURRENT_GROUP - 1];
            change = false;
            printf("The users from Group %d start their execution\n\n", CURRENT_GROUP);
            cond_group.notify_all();
        }
        locker.unlock();
    }
}

void request_thread(User u) {

    // Arrival message
    printf("User %d from Group %d arrives to the DBMS\n", u.id, u.group);

    //  Check Current Group
    std::unique_lock<std::mutex> locker(mutex_group);
    while (CURRENT_GROUP != u.group) {
        printf("User %d is waiting due to its group\n", u.id);
        GROUP_WAIT_COUNT++;
        cond_group.wait(locker);
    }
    locker.unlock();
    
    // If the position is free, lock for current process else wait
    std::unique_lock<std::mutex> locker2(mutex_db);
    while (DB_LOCKS[u.access_position - 1] != 0) {
        printf("User %d is waiting: position %d of the database is being used by user %d\n", u.id, u.access_position, DB_LOCKS[u.access_position - 1]);
        DB_WAIT_COUNT++;
        cond_db[u.access_position-1].wait(locker2);
    }
    DB_LOCKS[u.access_position - 1] = u.id;
    locker2.unlock();
    
    // Access required position
    printf("User %d is accessing the position %d of the database for %d second(s)\n", u.id, u.access_position, u.usage);
    // simulate usage
    std::this_thread::sleep_for(std::chrono::seconds(u.usage));
    printf("User %d finished its execution\n", u.id);

    // Release db lock and signal others waiting in queue
    locker2.lock();
    DB_LOCKS[u.access_position - 1] = 0;
    cond_db[u.access_position - 1].notify_one();
    CURRENT_GROUP_COMPLETED++;
    //Update Current Group
    change_current_group();
    locker2.unlock();
}

int main() {
    int NUM_OF_USERS = 0;

    // To store input data
    std::vector <User> user_queue;
    User temp;

    std::cin >> CURRENT_GROUP;

    // Input Data
    while (std::cin >> temp.group >> temp.access_position >> temp.arrival_time >> temp.usage) {
        temp.id = NUM_OF_USERS + 1;
        user_queue.push_back(temp);

        GROUP_TOTAL_COUNT[temp.group - 1]++;
        NUM_OF_USERS++;
    }

    std::thread *tid = new std::thread[NUM_OF_USERS];
    CURRENT_GROUP_TOTAL_COUNT = GROUP_TOTAL_COUNT[CURRENT_GROUP - 1];

    // check current group
    change_current_group();

    // Request thread Creation
    for (int i = 0; i < NUM_OF_USERS; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(user_queue[i].arrival_time));
        tid[i] = std::thread(request_thread, user_queue[i]);
    }

    for (int i = 0; i < NUM_OF_USERS; i++) {
        tid[i].join();
    }

    // Summary
    printf("\nTotal Requests:\n\tGroup 1: %d\n\tGroup 2: %d\n", GROUP_TOTAL_COUNT[0], GROUP_TOTAL_COUNT[1]);
    printf("\nRequests that waited:\n\tDue to its group: %d\n\tDue to a locked position: %d\n", GROUP_WAIT_COUNT, DB_WAIT_COUNT);

    return 0;
}