#include<iostream>
#include"chtml.h"
using namespace std;
int main()
{
	xml obj;
	obj.open_tag("html");
	obj.open_tag("head");
	obj.open_tag("style");
	obj.insert_text("p{color:red;font:Arial;}");
	obj.insert_text("\n #navbar{color:blue;}");
	obj.close_tag("style");
	obj.close_tag("head");
	obj.open_tag("body");
	obj.write_tag("p","abcdefghijklmnopqrstuvwxyz");
	obj.open_tag("h1","id","navbar");
	obj.insert_text("Hello world");
	obj.close_tag("h1");
	obj.close_tag("body");
	obj.close_tag("html");
	obj.dump("sample");
	return 0;
}
