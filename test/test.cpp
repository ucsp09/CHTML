#include<iostream>
#include"chtml.h"
using namespace std;
int main()
{
	try{
		html obj;
		obj.create_file("sample");
		obj.add_title("Welcome");
		obj.add_heading("Hello World");
		string cars[3][2]={{"Car","Price"},{"BMW","100k"},{"Lamborgini","200k"}};
		obj.add_table(cars);
		obj.add_paragraph("abcdefghijklmnopqrstuvxyzabcdefghijklmnopqrstuvwxyz");
		string names[]={"vegeta","goku","gohan","jiren","hit","frieza"};
		obj.add_list(names,"ol");
	}
	catch(const char* msg){
		cout<<msg;
	}
	return 0;
}
