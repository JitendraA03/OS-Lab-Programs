#include <iostream>
#include <thread>
#include <atomic>

int i = 0;
int j = 1;
std::atomic<int> flag_i(0);
std::atomic<int> flag_j(0);
std::atomic<int> turn(0);

int counter = 0;

void critical_section() {
	counter++;
}

void process_i() {
	for(int k = 0; k < 1e6; ++k) {
		flag_i = true;
		turn = j;
	
		while(flag_j && turn == j);
	
		critical_section();
		
		flag_i = false;
	}
}

void process_j() {
	for(int k = 0; k < 1e6; ++k) {
		flag_j = true;
		turn = i;
	
		while(flag_i && turn == i);
	
		critical_section();
	
		flag_j = false;
	}
}

int main() {
	std::thread jobA(process_i);
	std::thread jobB(process_j);
	
	jobA.join();
	jobB.join();
	
	std::cout << counter;
	
	return 0;
}
