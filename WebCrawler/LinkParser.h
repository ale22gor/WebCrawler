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
	virtual void parseStr(const char* str);
};

