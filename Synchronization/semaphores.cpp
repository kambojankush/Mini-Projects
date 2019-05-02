#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class semaphore
{
private:
    std::mutex mu;
    std::condition_variable cond;
    unsigned long available; // Initialized with num of resources available.

public:
    semaphore(int n = 1) {
        available = n;
    }

    void notify() {
        std::lock_guard<std::mutex> locker(mu);
        ++available;
        cond.notify_one();
    }

    void wait() {
        std::unique_lock<std::mutex> locker(mu);
        while(!available) // Handle spurious wake-ups.
            cond.wait(locker);
        --available;
    }

    bool try_wait() {
        std::lock_guard<std::mutex> locker(mu);
        if(available) {
            --available;
            return true;
        }
        return false;
    }
};

semaphore SEAT(5);
std::mutex display_mu;

void see_movie() {
    SEAT.wait();
    std::thread::id this_id = std::this_thread::get_id();
    std::unique_lock<std::mutex> locker(display_mu);
    std::cout << this_id << " is watching the movie" << std::endl;
    locker.unlock();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    SEAT.notify();
}

int main() {
    std::thread t[10];

    for (int i = 0; i < 10; i++) {
        t[i] = std::thread(see_movie);
    }

    for (int i = 0; i < 10; i++) {
        t[i].join();
    }

    return 0;
}