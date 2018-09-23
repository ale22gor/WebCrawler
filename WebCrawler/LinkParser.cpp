#include "LinkParser.h"



LinkParser::LinkParser()
{
}


LinkParser::~LinkParser()
{
}

void LinkParser::parseStr(const char * str)
{
	std::regex reg{ "<a href=\".+?\"" };
	std::smatch match;
	std::string what{str};
	std::regex_search(what,match,reg);
	for (auto x : match)
		std::cout <<"!!!"<< x << "!!!!";
	
}
