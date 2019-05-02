#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <vector>
#include <sstream>
#include <thread>
#include <chrono>

std::mutex file_mutex;
const std::string FILE_NAME = "primenumbers.txt";

// Timer structure to compute execution time
struct Timer {
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<float> duration;

	Timer() {
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer() {
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float sec = duration.count();
		std::cout << "Timer took: " << sec << "s " << std::endl;
	}
};

// funtion to calculate primes between begin and end and store the primes found int the file.
void calculate_primes(int begin, int end, std::ofstream& file) {
	bool isPrime = false;
	std::string primes;

	for (int i = begin; i < end; i++) {
		isPrime = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				isPrime = false;
				// break;
			}
		}

		if (isPrime) {
			primes.append(std::to_string(i));
			primes.append("\n");
		}
	}

	std::lock_guard<std::mutex> guard(file_mutex);
	std::cout << primes;
	file << primes;
}

// function to calculate sum of numbers stored in a file specified by the file name passed as argument
int calculate_sum(std::string name) {
	std::ifstream file(name);
	std::string line;
	int temp = 0, sum = 0;

	if (file.is_open()) {
		while (getline(file, line)) {
			std::stringstream(line) >> temp;
			sum += temp;
		}
	}
	file.close();
	return sum;
}

// Function to create worker threads for calculating primes,
// args: upper_limit: the number upto which we need to calculate primes
// num_of_threads: specifies the number of threads to be spawned
void create_workers(int upper_limit, int num_of_threads) {
	Timer timer;
	if (upper_limit <= 0 || num_of_threads <= 0) return;
	int span = upper_limit / num_of_threads;
	int start = 2;
	int end = span;
	std::ofstream output(FILE_NAME);

	//std::thread* TV = new std::thread[num_of_threads];
	std::vector <std::thread> tv;

	for (int i = 0; i < num_of_threads; i++) {
		//TV[i] = std::thread(calculate_primes, start, end, std::ref(output));
		tv.push_back(std::thread(calculate_primes, start, end, std::ref(output)));
		start = end;
		end += span;
		if (i == num_of_threads - 2) end = upper_limit;
	}

	for (int i = 0; i < num_of_threads; i++) {
		//TV[i].join();
		tv[i].join();
	}

	output.close();
}

int main() {
	create_workers(100, 4);
	int sum = calculate_sum(FILE_NAME);
	std::cout << "The sum of primes is :" << sum << std::endl;
	return 0;
}
