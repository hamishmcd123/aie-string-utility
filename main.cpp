#include <iostream>
#include <thread>
#include "string.hpp"



int main() {
	String teststring = "This is a test string using the string utility";
	std::cout << '\n';
	std::cout << "Original string: " << teststring << '\n';
	std::cout << '\n';
	std::cout << teststring.ToUpper() << '\n';
	std::cout << '\n';
	std::cout << teststring.ToLower() << '\n';
	std::cout << '\n';
	teststring.WriteToConsole(); 
	std::cout << '\n';
	std::cout << "Relacing 'i' with 'a' -- replacements : " << teststring.Replace('i', 'a') << '\n' << teststring;
	std::cout << '\n';
	String teststring2 = "This is a string to append"; 
	std::cout << '\n';
	std::cout << teststring2 << '\n';
	std::cout << '\n';
	std::cout <<teststring.Append(teststring2);
	std::cout << '\n';
	std::cout << '\n';
	teststring = "abc"; 
	teststring2 = "efg";
	std::cout << teststring;
	std::cout << '\n';
	std::cout << '\n';
	std::cout << teststring2;
	std::cout << '\n';
	std::cout << '\n';
	std::cout << (teststring < teststring2);
	std::this_thread::sleep_for(std::chrono::seconds(10));
}