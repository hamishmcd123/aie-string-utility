#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "string.hpp"


int main() {
// Test Cases 
	String teststring = "This is the test"; 
	String teststring2 = "test2";
	int successful_tests = 0;

	std::stringstream testresults; 
	std::cout << "Test 0 - Length done... \n";
		if (teststring.Length() == 16) {
			testresults << "Test 0, Length, Successful" << '\n';
			successful_tests++;
		}
		else {
			testresults << "Test 0, Length, Failed" << '\n';
		}

		std::cout << "Test 1 - Append done... \n";
		if (teststring.Append(teststring2) == "This is the testtest2") {
			testresults << "Test 1, Append, Successful" << '\n';
			successful_tests++;
		}
		else {
			testresults << "Test 1 Append Failed" << '\n';
		}
		
		std::cout << "Test 2 - ToLower done... \n"; 
		if (teststring.ToLower() == "this is the testtest2") {
			testresults << "Test 2, ToLower, Successful" << '\n';
			successful_tests++;
		}
		else {
			testresults << "Test 2, ToLower, Failed" << '\n';
		}
		
		std::cout << "Test 3 - ToUpper done... \n";
		if (teststring.ToUpper() == "THIS IS THE TESTTEST2") {
			testresults << "Test 3, ToUpper, Successful" << '\n';
			successful_tests++;
		}
		else {
			testresults << "Test 3, ToUpper, Failed" << '\n';
		}

		std::cout << "Test 4 - FindCharacter done... \n"; 
		if (teststring.FindCharacter('T') == 0) {
			testresults << "Test 4, FindCharacter, Successful" << '\n';
			successful_tests++; 
		}
		else {
			testresults << "Test 4, FindCharacter, Failed" << '\n';
		}

		std::cout << "Test 5 - Replace done... \n";
		if (teststring.Replace('E', 'A') == 3 && teststring == "THIS IS THA TASTTAST2") {
			testresults << "Test 5, Replace, Successful" << '\n';
			successful_tests++; 
		}
		else {
			testresults << "Test 5, Replace, Failed" << '\n';
		}

		// Read and write to/from console don't need testing -> based on >> and << operators... 

		std::cout << "Test 6 - Equality operator done...\n";
		String equalitytest = "THIS IS THA TASTTAST2";
		if (teststring == equalitytest) {
			testresults << "Test 6, Equality Operator, Succesful" << '\n';
			successful_tests++;
		}
		else {
			testresults << "Test 6, Equality Operator, Failed" << '\n';
		}
	
		std::cout << "Test 7 - Subscript Operator done... \n";
		if (teststring[0] == 'T') {
			testresults << "Test 7, Subscript Operator, Successful" << '\n';
			successful_tests++;
		}
		else {
			testresults << "Test 7, Subscript Operator, Failed" << '\n';
		}

		std::cout << "Test 8 - Assignment Operator done... \n";
		String assignmenttest = "yeahman"; 
		teststring = assignmenttest; 
		if (teststring == "yeahman") {
			testresults << "Test 8, Assignment Operator, Successful" << '\n';
			successful_tests++;
		}
		else {
			testresults << "Test 8, Assignment Operator, Failed" << '\n';
		}
		
		std::cout << "Test 9 - LessThan Operator done... \n";
		String abc = "abc"; 
		String efg = "efg";
		if ((abc < efg) == true) {
			testresults << "Test 9, LessThan Operator, Successful" << '\n';
			successful_tests++;
		}
		else {
			testresults << "Test 9, LessThan Operator, Failed" << '\n';
		}




	std::time_t t = std::time(nullptr); 
	std::tm tm = *std::localtime(&t);

	std::stringstream timess;
	timess << "Date: " << std::put_time(&tm, "%F") << "\n" << "Time: " << std::put_time(&tm, "%T") 
	<< "\n" << "Success Rate: " << std::to_string(successful_tests / 9 * 100) << "%" << '\n';
	std::string time = timess.str(); 
	std::string results = testresults.str();

	std::ofstream output; 
	output.open("log.csv", std::ios::app);
	output << '\n' << '\n' << time << "Test Case, Function, Outcome" << "\n" << results;
	output.close();

	return 0;
}