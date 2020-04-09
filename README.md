# CHTML
   CHTML is a library built using c++ for writing html documents.It has no dependencies on other projects,only on the C++ standard library.
# Building
   For use in a project you can copy the chtml.h file present in lib folder.
# Usage
   The basis of this library is the xml class and the html class.
   The xml class has functions to create the tag struture.(Refer file version1.0api.md in api folder)
   
   A sample of what you can do using xml class            
            
            xml obj;
            obj.open_tag("p");//opens a p tag
            obj.insert_text("Hello");//writes text 
            obj.close_tag("p");//closes the p tag
            obj.set_attribute("p","style","font:Arial;color:red;");//adds inline style to the p tag
            obj.dump("somefile","html");//dumps the code to the file
   The html class inherits xml class and also has advanced functions such as to add lists,links..etc(Refer file version1.0api.md in api folder)
   
   A sample of what you can do using html class
         
         html obj;
         obj.add_header("Hello world",3)//creates a h3 tag with hello world as the text in it
         obj.add_title("Welcome")//creates a title tag with Welcome as the text in it
         obj.add_link("#abcd","Click me")//creates a link with given name
         obj.add_stylesheet("somefile.css");//adds an external stylesheet
         string fruits[]={"apple","mango","grapes","banana"};
         obj.add_list(fruits,"ol")//creates an ordered list of fruits.
         obj.dump("sample","html");
 # API
   Refer file version1.0api.md present in api folder for api reference
              
# Examples
   A number of examples are included in the examples folder to get you started.
    
