#include "string.hpp" 

#define	CLEAR "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define RED "\033[31m"

void lengthTest(const String& _str1, const String& _str2, std::stringstream& testresults, int& successful_tests);
void resetTestStrings(String& _str1, String& _str2, String& _str3); 
void appendTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests);
void toLowerTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests);
void toUpperTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests);
void findCharacterTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests);
void replaceTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests);
void equalityTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests);
void subscriptTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests);
void lessThanTest(String& _str1, String& _str2, String& _str3, std::stringstream& testsresults, int& successful_tests);