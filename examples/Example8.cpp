#include<iostream>
#include"chtml.h"
using namespace std;
int main()
{
	html obj;
	obj.add_title("Welcome");
	obj.add_header("hello",1);
	obj.add_header("hello",2);
	obj.add_header("hello",3);
	obj.add_header("hello",4);
	obj.add_header("hello",5);
	obj.add_header("hello",6);
	obj.add_stylesheet("sample.css");
	obj.add_stylesheet("sample2.css");
	return 0;
}
