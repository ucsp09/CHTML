# CHTML
   A library built using c++ for writing and editing static html pages.
# Description:
   The Aim is to utilize the String handling features available in C++ to create a library named chtml.h which has some classes written in it.Users can create objects of these classes and by simply invoking functions can create html files such as adding headers,paragraphs,links,tables,lists,images,butons and manymore.They can also include styling in their html documents.So, now users can simply create html files using C++ without actually writing them in editors as they traditionally did.Also they can edit already existing html files.
# Classes Available:
   There are two classes available to the users one is named xml which contains functions to only open tags,close tags,insert text,set attributes.Other one is named html which contains many more functions.Users who dont know html tag structure can use class html,whereas people who know the html tag structure can use both xml and html class.
# Contributions:
   If anyone is interested in contribution to this library they can simply fork the repository ,add some features and generate a pull request.
# Steps to Run:
       1.Create a folder in your pc.
       2.Copy the header file chtml.h(present in lib folder) to your folder.
       3.Create a .cpp file in the same folder with any name.
       4.Now include chtml.h in this .cpp file as shown below
  
              #include<iostream>
              #include"chtml.h"
              using namespace std;
              int main()
              {
              return 0;
              }
       5.Now see the list of availbale functions in api.md in api folder.Start using them.   
       6.dump() function is necessary to dump the code to the html file otherwise the changes made will not appear in the file.
       7.View test files in test folder and examples in example folder for further clarity.
