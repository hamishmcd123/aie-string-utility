
class String {
public:

	String(); 

	String(const char* _cstr);
	
	String(const String& _str); 

	size_t Length();

	String& Append(const String& _str);

	String& ToLower();

	String& ToUpper();

	int FindCharacter(char _chr); 

	int Replace(char _findcharacter, char _replacecharacter);

	String ReadFromConsole(); 

	void WriteToConsole(); 

	bool friend operator==(const String& lhs, const String& rhs); 

	char operator[] (const String& _str);

	bool operator< (const String& _str) const;

	String operator= (const String& _str); 

private:
	


};