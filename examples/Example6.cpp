/*Creation of a html file with embedded styling using html class*/
#include<iostream>
#include"chtml.h"
using namespace std;
int main()
{
	try{
	html obj;
	obj.add_title("Welcome");
	obj.add_header("Hello",2);
	obj.add_para("p","class","pwd");
	obj.add_header("world","id","qwd",3);
	obj.add_style("tag","h2","color:red;font:Arial;");
	obj.add_style("class","pwd","color:blue;");
	obj.add_style("id","qwd","color:green;");
	obj.dump("sample");
	}
	catch(const char *msg){
		cout<<msg;
	}
	return 0;
}
