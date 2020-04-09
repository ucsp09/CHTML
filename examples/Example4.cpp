/*Creation of html file with inline styling using html class*/
#include<iostream>
#include"chtml.h"
using namespace std;
int main()
{
	try{
	html obj;
	obj.add_header("Hello world","style","font:Arial;color:red;",3);
	obj.add_title("Welcome");
	obj.add_para("abcdefghijklmnopqrstuvwxyz");
	obj.set_attribute("p","style","text-align:center;",1);
	unordered_map<string,string> atts;
	atts["type"]="password";
	atts["placeholder"]="Enter your password";
	atts["name"]="user_password";
	atts["id"]="pwd";
	obj.openln_tag("input");
	obj.set_attribute("input",atts,1);
	obj.open_tag("div","class","row");
	obj.open_tag("div","class","col1");
	obj.add_button("b1");
	obj.closeln_tag("div");
	obj.open_tag("div","class","col2");
	obj.add_button("b2");
	obj.closeln_tag("div");
	obj.closeln_tag("div");
	obj.set_attribute("div","style","color:red;",1);
	obj.set_attribute("div","style","color:blue;",2);
	obj.set_attribute("div","style","color:green;",3);
	obj.dump("sample");
	}
	catch(const char *msg){
		cout<<msg;
	}
	return 0;
}
