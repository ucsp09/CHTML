#include<iostream>
#include"chtml.h"
using namespace std;
int main()
{
	try{
		html obj;
		obj.add_title("Welcome");
		obj.add_header("Hello World");
		string cars[3][2]={{"Car","Price"},{"BMW","100k"},{"Lamborgini","200k"}};
		obj.add_table(cars);
		obj.add_paragraph("abcdefghijklmnopqrstuvxyzabcdefghijklmnopqrstuvwxyz");
		string names[]={"vegeta","goku","gohan","jiren","hit","frieza"};
		obj.add_list(names,"ol");
		obj.dump("sample");
	}
	catch(const char* msg){
		cout<<msg;
	}
	return 0;
}
