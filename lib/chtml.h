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
};
