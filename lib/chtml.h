#include<fstream>
#define OPEN fout.open(filename)
#define INIT fout<<"<!DOCTYPE html>\n<html>\n<body>\n</body>\n</html>"
#define SEEKP fout.seekp(-16,ios_base::end);
#define CLOSE fout.close()
#define CHECK if(!fout.is_open())throw "Please create a file first using create_file()"
using namespace std;
class html{
	private:		string filename;
				long pos;
				ofstream fout;
	public:		void create_file(string user_filename)
				{
					user_filename+=".html";
					filename=user_filename;
					OPEN;
					INIT;
				}
				void add_title(string title_content)
				{	
					CHECK;
					SEEKP;
					fout<<"<title>"<<title_content<<"</title>"<<"\n</body>\n</html>";
				}
	void add_link(string linkurl,string linkname)
				{
					CHECK;
					SEEKP;
					fout<<"<a href=\""<<linkurl<<"\">"<<linkname<<"</a>"<<"\n</body>\n</html>";
				}
				void add_button(string button_name)
				{
					CHECK;
					SEEKP;
					fout<<"<button>"<<button_name<<"</button>"<<"\n</body>\n</html>";
				}
				template<size_t LEN>
				void add_list(string (&list)[LEN],string type="ul")
				{
					CHECK;
					if(type=="ul"||type=="ol")
					{
						SEEKP;
						fout<<"<"<<type<<">\n";
						for(int i=0;i<LEN;i++)
							fout<<"<li>"<<list[i]<<"</li>\n";
						fout<<"</"<<type<<">"<<"\n</body>\n</html>";
					}
					else
						throw "Please choose list type from one of these{ul,ol}";
				}
				void add_image(string imageurl,string alt="user_image",int width=100,int height=100)
				{
					CHECK;
					SEEKP;
					fout<<"<img src=\""<<imageurl<<"\""<<" "<<"alt=\""<<alt<<"\""<<" "<<"width=\""<<width<<"\""<<" "<<"height=\""<<height<<"\">"<<"\n</body>\n</html>";
				}
				template<size_t ROW,size_t COL>
				void add_table(string (&table)[ROW][COL])
				{
					CHECK;
					SEEKP;
					fout<<"<table>\n";
					for(int i=0;i<ROW;i++)
					{
						fout<<"<tr>\n";
						for(int j=0;j<COL;j++)
						{
							if(i==0)
								fout<<"<th>"<<table[i][j]<<"</th>\n";
							else
								fout<<"<td>"<<table[i][j]<<"</td>\n";
						}
						fout<<"</tr>\n";
					}
					fout<<"</table>"<<"\n</body>\n</html>";
				}
};
