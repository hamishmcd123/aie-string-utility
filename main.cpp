#include <iostream>
#include <thread>
#include "string.hpp"



int main() {
	String test1 = "abc";
	std::cout << test1[5];
	std::cout << test1;

	std::this_thread::sleep_for(std::chrono::seconds(2));
}