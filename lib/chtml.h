#include<fstream>
#include"def.h"
using namespace std;
class html{
	private:	string filename;
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
					GOTOH;
					fout<<"<title>"<<title_content<<"</title>"<<"\n</head>\n<body>\n</body>\n</html>";
				}
				void add_heading(string heading_content,int heading_size=1,string style=SHED)
				{
					CHECK;
					if(heading_size>=1&&heading_size<=6)
					{	
						GOTOB;
						fout<<"<h"<<heading_size<<" "<<"style=\""<<style<<"\">"<<heading_content<<"</h"<<heading_size<<">"<<"\n</body>\n</html>";
					}
					else
						throw "Please choose heading tag size from one of{1,2,3,4,5,6}";
				}
				void add_paragraph(string para,string style=SPAR)
				{
					CHECK;
					GOTOB;
					fout<<"<p style=\""<<style<<"\">"<<para<<"</p>"<<"\n</body>\n</html>";
				}
				void add_link(string linkurl,string linkname)
				{
					CHECK;
					GOTOB;
					fout<<"<a href=\""<<linkurl<<"\">"<<linkname<<"</a>"<<"\n</body>\n</html>";
				}
				void add_button(string button_name)
				{
					CHECK;
					GOTOB;
					fout<<"<button>"<<button_name<<"</button>"<<"\n</body>\n</html>";
				}
				template<size_t LEN>
				void add_list(string (&list)[LEN],string type="ul")
				{
					CHECK;
					if(type=="ul"||type=="ol")
					{
						GOTOB;
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
					GOTOB;
					fout<<"<img src=\""<<imageurl<<"\""<<" "<<"alt=\""<<alt<<"\""<<" "<<"width=\""<<width<<"\""<<" "<<"height=\""<<height<<"\">"<<"\n</body>\n</html>";
				}
				template<size_t ROW,size_t COL>
				void add_table(string (&table)[ROW][COL],string style=STAB)
				{
					CHECK;
					GOTOB;
					fout<<"<table style=\""<<style<<"\">\n";
					for(int i=0;i<ROW;i++)
					{
						fout<<"<tr>\n";
						for(int j=0;j<COL;j++)
						{
							if(i==0)
								fout<<"<th style=\""<<style<<"\">"<<table[i][j]<<"</th>\n";
							else
								fout<<"<td style=\""<<style<<"\">"<<table[i][j]<<"</th>\n";
						}
						fout<<"</tr>\n";
					}
					fout<<"</table>"<<"\n</body>\n</html>";
				}
};
