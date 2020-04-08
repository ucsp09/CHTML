#include<iostream>
#include"chtml.h"
using namespace std;
int main()
{
	xml obj;
	obj.open_tag("html");
	obj.openln_tag("head");
	obj.writeln_tag("title","Welcome");
	obj.open_tag("link","rel","stylesheet");
	obj.set_attribute("link","type","text/css",1);
	obj.set_attribute("link","href","sample.css",1);
	obj.closeln_tag("head");
	obj.openln_tag("body");
	obj.openln_tag("h1");
	obj.insert_text("hello");
	obj.close_tag("h1");
	obj.close_tag("body");
	obj.close_tag("html");
	obj.dump();
	return 0;
}
