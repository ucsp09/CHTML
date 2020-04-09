#include<fstream>
#include<unordered_map>
#define APP data=data+"\n</body>\n</html>"
#define DUMP fout.open(filename);fout<<data;fout.close()	
using namespace std;
class base{
	protected:	ofstream fout;
				string filename;
				string extension;
				string data;
				long pos;
				int init;
	public:		void dump(string fname,string ext="html")
				{
					extension=ext;
					filename=fname+"."+extension;
					if(init==2)
						APP;
					DUMP;
				}
};
class xml:public base{
	public:		void open_tag(string tag)
				{
					data=data+"<"+tag+">";	
				}
				void openln_tag(string tag)
				{
					data=data+"\n<"+tag+">";
				}
				void open_tag(string tag,string att,string val)
				{
					data=data+"\n<"+tag+" "+att+"=\""+val+"\">";
				}
				void insert_text(string text)
				{
					data=data+text;
				}
				void close_tag(string tag)
				{
					data=data+"</"+tag+">";
				}
				void closeln_tag(string tag)
				{
					data=data+"\n</"+tag+">";
				}
				void write_tag(string tag,string text)
				{
					data=data+"<"+tag+">"+text+"</"+tag+">";
				}
				void writeln_tag(string tag,string text)
				{
					data=data+"\n<"+tag+">"+text+"</"+tag+">";
				}
				void remove_tag(string tag,string upto="close",int occurence=1)
				{
					string _tag="<"+tag;
					size_t found;
					if(occurence==1)
						found=data.find(_tag);
					else if(occurence==-1)
						found=data.rfind(_tag);
					else
					{
						found=data.find(_tag);
						int count=1;
						while(count!=occurence)
						{
							found=data.find(_tag,found+_tag.length()+1);
							count++;
						}
					}
					if(found==string::npos)
						throw "This tag is already removed or not present";
					else
					{
						if(upto=="open")
						{
							size_t end=data.find(">",found+1);
							data.erase(found,end-found+1);
						}
						else if(upto=="text")
						{
							size_t end=data.find("<",found+1);
							data.erase(found,end-found);
						}
						else if(upto=="close")
						{
							
							string tag_="</"+tag+">";
							size_t end=data.find(tag_,found+1);
							end=end+_tag.length();
							data.erase(found,end-found+2);
						}
						else
							throw "upto takes value- open or text or close";
					}
				}
				void set_attribute(string tag,unordered_map<string,string> att,int occurence=-1)
				{
					string _tag="<"+tag;
					size_t found;
					if(occurence==1)
						found=data.find(_tag);
					else if(occurence==-1)
						found=data.rfind(_tag);
					else
					{
						found=data.find(_tag);
						int count=1;
						while(count!=occurence)
						{
							found=data.find(_tag,found+_tag.length()+1);
							count++;
						}
					}
					unordered_map<string,string>::iterator it;
					string temp;
					for(it=att.begin();it!=att.end();++it)
						temp=temp+" "+it->first+"="+"\""+it->second+"\"";
					if(found==string::npos)
						data=data+"\n"+_tag+temp+">";
					else
						data.insert(found+tag.length()+1,temp);										
				}
				void set_attribute(string tag,string att,string val,int occurence=-1)
				{
					string _tag="<"+tag;
					size_t found;
					if(occurence==1)
						found=data.find(_tag);
					else if(occurence==-1)
						found=data.rfind(_tag);
					else
					{
						found=data.find(_tag);
						int count=1;
						while(count!=occurence)
						{
							found=data.find(_tag,found+_tag.length()+1);
							count++;
						}
					}
					string temp=" "+att+"=\""+val+"\"";
					if(found==string::npos)
						data=data+"\n"+_tag+temp+">";
					else
						data.insert(found+tag.length()+1,temp);
				}
}; 
class html:public xml{
	public:		html()
				{
					init=2;
					data=data+"<DOCTYPE html>\n<html>\n<head>\n<style>\n</style>\n</head>\n<body>";
				}
				void add_title(string text)
				{
					size_t found=data.find("<head>");
					string temp="\n<title>"+text+"</title>";
					data.insert(found+6,temp);	
				}
				void add_header(string text,int size=1)
				{
					if(size>=1&&size<=6)
					{
						string tag="h"+to_string(size);
						writeln_tag(tag,text);	
					}
					else
						throw "Size should be inclusive(1,6)";		
				} 
				void add_header(string text,string att,string val,int size=1)
				{
					if(size>=1&&size<=6)
					{
						string tag="h"+to_string(size);
						data=data+"\n<"+tag+" "+att+"=\""+val+"\">"+text+"</"+tag+">";	
					}
					else
						throw "Size should be inclusive(1,6)";		
				} 
				void add_para(string text)
				{
					writeln_tag("p",text);
				}
				void add_para(string text,string att,string val)
				{
					data=data+"\n<p"+" "+att+"=\""+val+"\">"+text+"</p>";
				}
				void add_button(string bname)
				{
					write_tag("button",bname);
				}
				void add_link(string url,string lname)
				{
					data=data+"\n<a href=\""+url+"\">"+lname+"</a>";
				}
				void add_image(string src)
				{
					data=data+"\n<img src=\""+src+"\">";
				}
				template<size_t LEN>
				void add_list(string (&list)[LEN],string type="ul")
				{
					if(type=="ul"||type=="ol")
					{
						openln_tag(type);
						for(int i=0;i<LEN;i++)
							write_tag("li",list[i]);
						insert_text("\n");
						closeln_tag(type);
					}
					else
						throw "Type should be either ul or ol";
				}
				template<size_t ROW,size_t COL>
				void add_table(string (&table)[ROW][COL])
				{
					openln_tag("table");
					for(int j=0;j<COL;j++)
						write_tag("th",table[0][j]);
					for(int i=1;i<ROW;i++)
						for(int j=0;j<COL;j++)
							write_tag("tr",table[i][j]);
					insert_text("\n");
					closeln_tag("table");
				}
				void add_style(string selector_type,string selector_name,string att)
				{
					size_t found=data.find("<style>");
					string temp,_temp;
					size_t _found;
					if(selector_type=="tag")
					{
						_temp=selector_name+"{";
						_found=data.find(_temp);
						if(_found==string::npos)
						{
							temp=temp+"\n"+selector_name+"{\n"+att+"\n}";
							data.insert(found+7,temp);
						}
						else
							data.insert(_found+selector_name.length()+2,att);
					}
					else if(selector_type=="id")
					{
						_temp="#"+selector_name+"{";
						_found=data.find(_temp);
						if(_found==string::npos)
						{
							temp=temp+"\n"+"#"+selector_name+"{\n"+att+"\n}";
							data.insert(found+7,temp);
						}
						else
							data.insert(_found+selector_name.length()+2,att);
					}
					else if(selector_type=="class")
					{
						_temp="."+selector_name+"{";
						_found=data.find(_temp);
						if(_found==string::npos)
						{
							temp=temp+"\n"+"."+selector_name+"{\n"+att+"\n}";
							data.insert(found+7,temp);
						}
						else
							data.insert(_found+selector_name.length()+2,att);
					}
					else
						throw "Selector type should be tag or id or class";
				}
				void add_stylesheet(string url)
				{
					size_t found =data.find("<head>");
					string temp="\n<link rel=\"stylesheet\" type=\"text/css\" href=\""+url+"\"/>";
					data.insert(found+6,temp);
				}
};
