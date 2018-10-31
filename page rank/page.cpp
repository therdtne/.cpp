/*
NAME: Trent Herdtner
EMAIL: therdtne@usc.edu
DESCRIPTION: This file includes constructor for Page class
			and addLink function.
*/
#include "page.h"

Page::Page(int i, const string &u)
{
	id = i; //initialization 
	url = u; //initialization
}
void Page::addLink(int id)
{
	links.push_back(id); //push back id of link
}
