#include "string.hpp"
#include <iostream>

String::String() {
	start = nullptr; 
	length = 0;
}

String::String(const char* _cstr) {
	int templength = 0;
	for (int i = 0; *(_cstr + i) != '\0'; i++) {
		templength++;
	}

	length = templength;

	start = new char[length]; 

	for (int i = 0; *(_cstr + i) != '\0'; i++) {
		*(start + i) = *(_cstr + i);
	}

}

const size_t String::Length() {
	return length;
}

char& String::operator[] (size_t index) {
		if (index < length) {
			return *(start + index);
		}
		else {
			throw(index);
		}
}

std::ostream& operator<<(std::ostream& os, String& _str) {
	for (int i = 0; i < (_str.Length()); i++) {
		os << _str[i];
	}
	return os;
}

void String::WriteToConsole() {
	std::cout << *(this) << '\n';
}

String::~String() {
	if (start != nullptr) {
		delete[] start;
	}
}

String& String::ToLower() {
	for (int i = 0; i < length; i++) {

		(*this)[i] = (char)(std::tolower((*this)[i]));
	}
	return *this;
}

String& String::ToUpper() {
	for (int i = 0; i < length; i++) {
		(*this)[i] = (char)(std::toupper((*this)[i]));
	}
	return *this;
}


String::String(const String& _str) {
	length = _str.length;
	start = new char[length + 1];
	for (int i = 0; i < length; i++) {
		start[i] = _str[i];
	}
	start[length] = '\0';
}

const char& String::operator[] (size_t index) const {
	try {
		if (index < length) {
			return *(start + index);
		}
		else {
			throw(index);
		}
	}
	catch (size_t index) {
		std::cout << '\n' << "Exception Caught - You cannot access an index outside of range!";
	}
}


bool operator==(const String& lhs, const String& rhs) {
	// First check to see if lengths are even equal...
	if (lhs.length != rhs.length) {
		return false;
	}
	
	for (int i = 0; i < lhs.length; i++) {
		if (lhs[i] != rhs[i]) {
			return false;
		}
	}

	return true; 
}

String& String::Append(const String& _str) {

	size_t templength = this->length + _str.length; 

	char* newstart = new char[templength + 1];

	for (int i = 0; i < (this->length) ; i++) {
		newstart[i] = (*this)[i];
	}

	int j = 0;

	for (int i = this->length; i < templength; i++) {
		newstart[i] = _str[j];
		j++;
	}

	newstart[templength] = '\0';

	delete[] this->start;

	this->start = newstart;
	this->length = templength;
	return *this;
}

int String::FindCharacter(const char& _chr) const {
	int index = 0;
	for (int i = 0; i < this->length; i++) {
		if (_chr == (*this)[i]) {
			return index; 
		}
		index++;
	}
	return -1; 
}

int String::Replace(const char _findcharacter, const char _replacecharacter) {
	int replacecount = 0; 
	for (int i = 0; i < this->length; i++) {
		if ((*this)[i] == _findcharacter) {
			(*this)[i] = _replacecharacter; 
			replacecount++;
		}
	}
	return replacecount;
}

String& String::operator=(const String& _str) {
	if (!(*this == _str)) {
		delete[] this->start;
		this->length = _str.length;
		this->start = new char[_str.length + 1];
		for (int i = 0; i < this->length; i++) {
			start[i] = _str[i];
		}
		start[length] = '\0';
	}
	return *this;
}


bool String::operator<(const String& _str) const {
	int comparison = std::strcmp(this->start, _str.start);
	if (comparison < 0) {
		return true;
	}
	else {
		return false;
	}
}


String& operator+=(String& _str, const char _chr) {
	size_t templength = _str.length + 1;
	char* newstart = new char[templength + 1];
	for (int i = 0; i < _str.length; i++) {
		newstart[i] = _str[i];
	}
	newstart[templength - 1] = _chr; 
	newstart[templength] = '\0';

	delete[] _str.start; 

	_str.start = newstart; 
	_str.length = templength;

	return _str;
}

std::istream& operator>>(std::istream& is, String& _str) {
	std::istream::sentry s(is);

	if (s) {
		while (is) {
			char c = is.get();
			if (std::isspace(c) || is.eof()) break;
			if (std::isalnum(c)) {
				_str += c;
			}
		}
	}


	return is;
}

String& String::ReadFromConsole() {
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin >> *this; 
	return *this;
}