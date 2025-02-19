#include "testfunctions.hpp"
#include "sstream"


void resetTestStrings(String& _str1, String& _str2, String& _str3) {
	// Resets the contents of teststrings; 
	_str1 = "Test string 1"; 
	_str2 = "Test string 2";
	_str3.Clear();
}


void lengthTest(const String& _str1, const String& _str2, std::stringstream& testresults, int& successful_tests) {
	// Test 0 Length - non-empty string
	if (_str1.Length() == 13) {
		std::cout << GREEN << "Test 0, Length - non-empty string, Successful" << CLEAR << '\n';
		testresults << "Test 0, Length - non-empty string, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: teststring length not correct. Expected 13 got: " << _str1.Length() << CLEAR << '\n';
		testresults << "Test 0, Length - non-empty string, Failed" << '\n';
	}
	// Test 1 Length - empty string
	if (_str2.Length() == 0) {
		std::cout << GREEN << "Test 1, Length - empty string, Successful" << CLEAR << '\n';
		testresults << "Test 1, Length - empty string, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: teststring3 length not correct. Expected 0 got: " << _str2.Length() << CLEAR << '\n';
		testresults << "Test 1, Length - empty string, Failed" << '\n';
	}
}
void appendTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests) {
	// Test 2 Append - non-empty self and non-empty non-self
	resetTestStrings(_str1, _str2, _str3);
	if ((_str1.Append(_str2)) == "Test string 1Test string 2") {
		std::cout << GREEN << "Test 2, Append - non-empty self and non-empty non-self, Successful" << CLEAR << '\n';
		testsresults << "Test 2, Append - non-empty self and non-empty non-self, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: non-empty self and non-empty non-self append not correct. Expected Test string 1Test string 2 got: " << _str1 << CLEAR << '\n';
		testsresults << "Test 2, Append - non-empty self and non-empty non-self, Failed" << '\n';
	}
	// Test 3 Append - non-empty self append
	resetTestStrings(_str1, _str2, _str3);
	if ((_str2.Append(_str2)) == "Test string 2Test string 2") {
		std::cout << GREEN << "Test 3, Append - non-empty self , Successful" << CLEAR <<'\n';
		testsresults << "Test 3, Append - non-empty self, Successful" << '\n'; 
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: non-empty self append not correct. Expected Test string 2Test string 2 got: " << _str2 << CLEAR << '\n';
		testsresults << "Test 3, Append - non-empty self, Failed" << '\n';
	}
	// Test 4 Append - Empty self and non-empty non-self
	resetTestStrings(_str1, _str2, _str3);
	if ((_str3.Append(_str1) == "Test string 1")) {
		std::cout << GREEN << "Test 4, Append - empty self and non-empty non-self, Successful" << CLEAR << '\n';
		testsresults << "Test 4, Append - empty self and non-empty non-self, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: empty self and non-empty non-self append not correct. Expected Test string1 got: " << _str3 << CLEAR << '\n';
		testsresults << "Test 4, Append - empty self and non-empty non-self, Failed" << '\n';
	}
	// Test 5 - non-empty self and empty non-self 
	resetTestStrings(_str1, _str2, _str3);
	if ((_str1.Append(_str3)) == "Test string 1") {
		std::cout << GREEN << "Test 5, Append - non-empty self and empty non-self, Successful" << CLEAR << '\n';
		testsresults << "Test 5, Append - non-empty self and empty non-self, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED <<"Error: non-empty and empty non-self append not correct. Expected Tests string 1 got: " << _str1 << CLEAR <<'\n';
		testsresults << "Test 5, Append - non-empty self and empty non-self, Failed" << '\n';
	}
	// Test 6 - empty self append 
	resetTestStrings(_str1, _str2, _str3); 
	if (!(_str3.Append(_str3).Length() > 0)) {
		std::cout << GREEN << "Test 6, Append - empty self, Successful" << CLEAR << '\n';
		testsresults << "Test 6, Append - empty self, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: empty self append not correct. Expected NULL got: " << _str3 << CLEAR << '\n';
		testsresults << "Test 6, Append - empty self, Failed" << '\n';
	}
}

void toLowerTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests) {
	resetTestStrings(_str1, _str2, _str3);
	// Test 7 ToLower - non-empty string 
	if ((_str1.ToLower()) == "test string 1") {
		std::cout << GREEN << "Test 7, ToLower - non-empty string, Successful" << CLEAR << '\n';
		testsresults << "Test 7, ToLower - non-empty string, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: non-empty tolower not correct. Expected test string 1 got: " << _str1 << CLEAR << '\n';
		testsresults << "Test 7, ToLower - non-empty string, Failed" << '\n';
	}
	// Test 8 ToLower - empty string
	resetTestStrings(_str1, _str2, _str3);
	if (!(_str3.ToLower().Length() > 0)) {
		std::cout << GREEN << "Test 8, ToLower - empty string, Successful" << CLEAR << '\n';
		testsresults << "Test 8, ToLower - empty string, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: empty tolower not correct. Expected NULL got: " << _str3 << CLEAR << '\n';
		testsresults << "Test 8, ToLower - empty string, Failed" << '\n';
	}
}

void toUpperTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests) {
	resetTestStrings(_str1, _str2, _str3);
	// Test 9 ToUpper - non-empty string 
	if ((_str1.ToUpper() == "TEST STRING 1")) {
		std::cout << GREEN << "Test 9, ToUpper - non-empty string, Successful" << CLEAR << '\n';
		testsresults << "Test 9, ToUpper - non-empty string, Successful" <<'\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: non-empty toupper not correct. Expected TEST STRING 1 got: " << _str1 << CLEAR << '\n';
		testsresults << "Test 9, ToUpper - non-empty string, Failed" << '\n';
	}
	// Test 10 ToUpper - empty string 
	if (!(_str3.ToLower().Length() > 0)) {
		std::cout << GREEN << "Test 10, ToUpper - empty string, Successful" << CLEAR << '\n';
		testsresults << "Test 10, ToUpper - empty string, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: empty toupper not correct. Expected NULL got: " << _str3 << CLEAR << '\n';
		testsresults << "Test 10, ToUpper - empty string, Failed" << '\n';
	}
}

void findCharacterTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests) {
	resetTestStrings(_str1, _str2, _str3); 
	// Test 11 - FindCharacter - Non-empty, char is present
	if ((_str1.FindCharacter('e') == 1)) {
		std::cout << GREEN << "Test 11, FindCharacter - non-empty string char present, Successful" << CLEAR << '\n';
		testsresults << "Test 11, FindCharacter - non-empty string char present, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: findcharacter non-empty string char present not correct. Expected 1 got: " << _str1.FindCharacter('e') << CLEAR<< '\n';
		testsresults << "Test 11, FindCharacter - non-empty string char present, Failed" << '\n';
	}
	// Test 12 - FindCharacter - Non-empty, char is not present
	if ((_str1.FindCharacter('z') == -1)) {
		std::cout << GREEN << "Test 12, FindCharacter - non-empty string char not present, Successful" << CLEAR << '\n';
		testsresults << "Test 12, FindCharacter - non-empty string char not present, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: findcharacter non-empty string char not present not correct. Expected -1 got: " << _str1.FindCharacter('z') << CLEAR << '\n';
		testsresults << "Test 12, FindCharacter - non-empty string char not present, Failed" << '\n';
	}
	// Test 13 - FindCharacter - empty 
	if ((_str3.FindCharacter('z') == -1)) {
		std::cout << GREEN << "Test 13, FindCharacter - empty string, Successful" << CLEAR << '\n';
		testsresults << "Test 13, FindCharacter - empty string, Successful" << '\n';
	}
	else {
		std::cout << RED << "Error: findcharacter empty string not correct. Expected -1 got: " << _str3.FindCharacter('z') << CLEAR << '\n';
		testsresults << "Test 13, FindCharacter - empty string, Failed" << '\n';
	}

}

void replaceTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests) {
	resetTestStrings(_str1, _str2, _str3); 
	// Test 14 - Replace - non-empty char present 
	if ((_str1.Replace('e', 'a') == 1 && _str1 == "Tast string 1")) {
		std::cout << GREEN << "Test 14, Replace - non-empty char present, Successful" << CLEAR << '\n';
		testsresults << "Test 14, Replace - non-empty char present, Successful" << '\n';
		successful_tests++;
	}
	else {
		resetTestStrings(_str1, _str2, _str3);
		std::cout << RED << "Error: replace non-empty char present not correct. Expected 1 got: " << _str1.Replace('e', 'a') << CLEAR << '\n';
		testsresults << "Test 14, Replace - non-empty char present, Failed" << '\n';
	}
	// Test 15 - Replace - non-empty char not present
	resetTestStrings(_str1, _str2, _str3); 
	if ((_str1.Replace('z', 'e') == 0)) {
		std::cout << GREEN << "Test 15, Replace - non-empty char not present, Successful" << CLEAR << '\n';
		testsresults << "Test 15, Replace - non-empty char not present, Successful" << '\n';
		successful_tests++;
	}
	else {
		resetTestStrings(_str1, _str2, _str3);
		std::cout << RED << "Error: replace non-empty char not present not correct. Expected 0 got: " << _str1.Replace('z', 'e') << CLEAR << '\n';
		testsresults << "Test 15, Replace - non-empty char not present, Failed" << '\n';
	}
	// Test 16 - Replace - empty char
	if ((_str3.Replace('z', 'e') == 0)) {
		std::cout << GREEN << "Test 16, Replace - empty, Successful" << CLEAR << '\n';
		testsresults << "Test 16, Replace - empty, Successful" << '\n';
		successful_tests++;
	}
	else {
		resetTestStrings(_str1, _str2, _str3);
		std::cout << RED << "Error: replace empty not correct. Expected 0 got: " << _str3.Replace('z', 'e') << CLEAR << '\n';
		testsresults << "Test 16, Replace - empty, Failed" << '\n';
	}

}

void equalityTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests) {
	resetTestStrings(_str1, _str2, _str3);
	//Creating temporary string for comparison
	String temp = "Test string 1";
	String temp2;
	// Test 17 - Equality - identical strings
		if ((_str1 == temp)) {
			std::cout << GREEN << "Test 17, Equality - identical strings, Successful" << CLEAR << '\n';
			testsresults << "Test 17, Equality - identical strings, Successful" << '\n';
			successful_tests++;
		}
		else {
			std::cout << RED << "Error: equality identical strings not correct. Expected 1 got: " << (_str1 == temp) << CLEAR << '\n';
			testsresults << "Test 17, Equality - identical strings, Failed" << '\n';
		}
	// Test 18 - Equality - different strings 
		if (!(_str1 == _str2)) {
			std::cout << GREEN << "Test 18, Equality - different strings, Successful" << CLEAR << '\n';
			testsresults << "Test 18, Equality - different strings, Successful" << '\n';
			successful_tests++;
		}
		else {
			std::cout << RED << "Error: equality different strings not correct. Expected 0 got : " << (_str1 == _str2) << CLEAR << '\n';
			testsresults << "Test 18, Equality - different strings, Failed" << '\n';
			}
	// Test 19 - Equality - empty and non-empty
		if (!(_str3 == _str1)) {
			std::cout << GREEN << "Test 19, Equality - empty and non-empty, Successful" << CLEAR << '\n';
			testsresults << "Test 19, Equality - empty and non-empty, Successful" << '\n';
			successful_tests++;
		}
		else {
			std::cout << RED << "Error: equality empty and non-empty not correct. Expected 0 got : " << (_str3 == _str1) << CLEAR << '\n';
			testsresults << "Test 19, Equality - empty and non-empty, Failed" << '\n';
		}
	// Test 20 - Equality - empty and empty 
		if ((_str3 == temp2)) {
			std::cout << GREEN << "Test 20, Equality - empty and empty, Successful" << CLEAR << '\n';
			testsresults << "Test 20, Equality - empty and empty, Successful" << '\n';
			successful_tests++;

		}
		else {
			std::cout << RED << "Error: equality empty and empty not correct. Expected 1 got : " << (_str3 == temp2) << CLEAR << '\n';
			testsresults << "Test 20, Equality - empty and empty, Failed" << '\n';
		}
}

void subscriptTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests) {
	resetTestStrings(_str1, _str2, _str3);
	// Test 21 - Subscript - non-empty
	if ((_str1[1] == 'e')) {
		std::cout << GREEN << "Test 21, Subscript - non-empty, Successful" << CLEAR << '\n';
		testsresults << "Test 21, Subscript - non-empty, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: subscript non empty not correct. Expected e got: " << _str1[1] << CLEAR << '\n';
		testsresults << "Test 21, Subscript - non-empty, Failed" << '\n';
	}
	// Test 22 - Subscript - empty
	if ((_str3[1]) == '\0') {
		std::cout << GREEN << "Test 22, Subscript - empty, Successful" << CLEAR << '\n';
		testsresults << "Test 22, Subscript - empty, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: subscript empty not correct. Expected NULL got: " << _str3[1] << CLEAR << '\n';
		testsresults << "Test 22, Subscript - empty, Failed" << '\n';
	}
}
void lessThanTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests) {
	resetTestStrings(_str1, _str2, _str3);
	// Test 23 - Identical strings
	if (!(_str1 < _str1)) {
		std::cout << GREEN << "Test 23, LessThan - identical strings, Successful" << CLEAR << '\n';
		testsresults << "Test 23, LessThan - identical strings, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: lessthan identical not correct. Expected 0 got: " << (_str1 < _str1) << CLEAR << '\n';
		testsresults << "Test 23, LessThan, identical strings, Failed";
	}
	// Test 24 - empty string and non-empty
	if ((_str3 < _str1)) {
		std::cout << GREEN << "Test 24, LessThan - empty and non-empty, Successful" << CLEAR << '\n';
		testsresults << "Test 24, LessThan - empty and non-empty, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: lessthan empty and non-empty not correct. Expected 1 got : " << (_str3 < _str1) << CLEAR << '\n';
		testsresults << "Test 24, LessThan - empty and non-empty, Failed" << '\n';
	}

	// Test 25 - Both empty 
	String temp;
	if (!(_str3 < temp)) {
		std::cout << GREEN << "Test 25, LessThan - both empty, Successful" << CLEAR << '\n';
		testsresults << "Test 25, LessThan - both empty, Successful" << '\n';
		successful_tests++;
	}
	else {
		std::cout << RED << "Error: lessthan both empty not correct. Expected 0 got :" << (_str3 < temp) << CLEAR << '\n';
		testsresults << "Test 25, LessThan - both empty, Failed" << '\n';
	}

	// Test 26 - non-empty and empty
	if (!(_str1 < _str3)) {
		std::cout << GREEN << "Test 26, LessThan - non-empty and empty, Successful" << CLEAR << '\n';
		testsresults << "Test 26, LessThan - non-empty and empty, Successful" << '\n';
	}
	else {
		std::cout << RED << "Error: lessthan non-empty and empty. Expected 0 got :" << (_str1 < _str3) << CLEAR << '\n';
		testsresults << "Test 26, LessThan - non-empty and empty, Failed" << '\n';
	}
	// Test 27 - abc and abcd
	String abc = "abc";
	String abcd = "abcd";
	if ((abc < abcd)) {
	std::cout << GREEN << "Test 27, LessThan - abc and abcd, Successful" << CLEAR << '\n';
	testsresults << "Test 27, LessThan - abc and abcd, Successful" << '\n';
	}
}

