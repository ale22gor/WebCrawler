#include "HtmlParser.h"
#include <cstring>
#include <regex>
#include <iostream>
#pragma once
class LinkParser :
	public HtmlParser
{

public:
	LinkParser();
	~LinkParser();
	 void parseStr(const char* str);
};

