/*Creation of a Plain html file using html class*/
#include<iostream>
#include"chtml.h"
using namespace std;
int main()
{
	try{
	html obj;
	obj.add_title("Welcome");
	obj.add_header("Hello World",2);
	obj.add_para("abcdefghijklmnopqrstuvwxyz");
	obj.add_link("#abcd","Click me");
	string fruits[]={"apple","banana","mango","guava","grapes"};
	obj.add_list(fruits,"ol");
	string items[3][4]={{"Name","Qty","Price","Location"},{"Apple","120","11","Hyderabad"},{"Mango","97","20","Mumbai"}};
	obj.add_table(items);
	obj.open_tag("div");
	obj.add_button("Press here");
	obj.close_tag("div");
	obj.openln_tag("div");
	obj.insert_text("this is a form");
	obj.closeln_tag("div");
	obj.dump("sample");
	}
	catch(const char *msg){
		cout<<msg;
	}
	return 0;
}
