#include "vector"
#pragma once

class HtmlParser
{
protected:
	std::vector<std::string> listOfElements;
public:
	virtual void parseStr(const char* str) = 0;
};

