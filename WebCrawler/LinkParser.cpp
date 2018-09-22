#include "LinkParser.h"



LinkParser::LinkParser()
{
}


LinkParser::~LinkParser()
{
}

void LinkParser::parseStr(const char * str)
{
	char linkSequence[]{ '<','a' };
	const char * pch;
	pch = strchr(str, linkSequence[Iterrator]);
	while (pch != NULL)
	{
		printf("found at %d\n", pch - str + 1);
		pch = strchr(pch + 1, linkSequence[Iterrator]);
	}
}
