/*Creation of Plain html file using xml class*/
#include<iostream>
#include"chtml.h"
using namespace std;
int main()
{
	try{
	xml obj;
	obj.openln_tag("html");
	obj.openln_tag("head");
	obj.writeln_tag("title","Welcome");
	obj.closeln_tag("head");
	obj.openln_tag("body");
	obj.openln_tag("ul");
	obj.writeln_tag("li","one");
	obj.writeln_tag("li","two");
	obj.writeln_tag("li","three");
	obj.writeln_tag("li","four");
	obj.close_tag("ul");
	obj.close_tag("body");
	obj.close_tag("html");
	obj.dump("sample");
	}
	catch(const char *msg){
		cout<<msg;
	}
	return 0;
}
