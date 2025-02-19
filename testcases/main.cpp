#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "string.hpp"
#include "testfunctions.hpp"


int main() {

	String teststring = "Test string 1"; 
	String teststring2 = "Test string 2";
	String teststring3; 

	int successful_tests = 0;
	std::stringstream testresults; 

	lengthTest(teststring, teststring3, testresults, successful_tests);
	appendTest(teststring, teststring2, teststring3, testresults, successful_tests);
	toLowerTest(teststring, teststring2, teststring3, testresults, successful_tests);
	toUpperTest(teststring, teststring2, teststring3, testresults, successful_tests);
	findCharacterTest(teststring, teststring2, teststring3, testresults, successful_tests);
	replaceTest(teststring, teststring2, teststring3, testresults, successful_tests);
	equalityTest(teststring, teststring2, teststring3, testresults, successful_tests);
	subscriptTest(teststring, teststring2, teststring3, testresults, successful_tests);
	lessThanTest(teststring, teststring2, teststring3, testresults, successful_tests);


	std::time_t t = std::time(nullptr); 
	std::tm tm = *std::localtime(&t);

	std::stringstream timess;
	timess << "Date: " << std::put_time(&tm, "%F") << "\n" << "Time: " << std::put_time(&tm, "%T") 
	<< "\n" << "Success Rate: " << std::to_string(successful_tests / 20.0f * 100) << "%" << '\n';
	std::string time = timess.str(); 
	std::string results = testresults.str();

	std::ofstream output; 
	output.open("log.csv", std::ios::app);
	output << '\n' << '\n' << time << "Test Case, Function, Outcome" << "\n" << results;
	output.close();

	return 0;
}