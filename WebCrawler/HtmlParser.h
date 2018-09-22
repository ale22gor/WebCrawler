#include "vector"
#pragma once

class HtmlParser
{
	std::vector<std::string> listOfElements;
	virtual void parseStr(const char* str) = 0;
};

