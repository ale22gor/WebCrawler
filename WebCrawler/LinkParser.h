#include "HtmlParser.h"
#include <cstring>
#pragma once
class LinkParser :
	public HtmlParser
{
	int Iterrator;

public:
	LinkParser();
	~LinkParser();
	virtual void parseStr(const char* str);
};

