#include <iostream>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <thread>

std::deque<int> q;
std::mutex mu;

void producer() {
	int count = 10;
	while (count > 0) {
		std::unique_lock<std::mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		count--;
	}
}

// busy waiting
void consumer() {
	int data = 0;
	while (data != 1) {
		std::unique_lock<std::mutex> locker(mu);
		if (!q.empty()) {
			data = q.back();
			q.pop_back();
			locker.unlock();
			std::cout << "Consumer got a value from shared queue: " << data << std::endl;
		}
		else {
			locker.unlock();
		}
	}
}

int main() {
	std::thread p(producer);
	std::thread c(consumer);
	p.join();
	c.join();

	return 0;
}