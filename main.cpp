#include <iostream>
#include <thread>
#include "string.hpp"



int main() {
	String test1 = "abc";
	String test2; 
	test2.ReadFromConsole();
	std::cout << test2;

	std::this_thread::sleep_for(std::chrono::seconds(2));
}