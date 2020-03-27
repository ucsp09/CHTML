# API REFERENCE:

# CLASS html
      This is a writer for html documents.
      
# Constructors Summary
      html()
          Creates a new file named sample.html with some default tags written. 
      html(string user_filename)
          Creates a new file with the given name with some default tags written.
     
# Member Functions Summary
    Modifier and type                Function and Description
    public  void                    add_title(string title_content)
                                    adds a <title> tag with given content.
    public  void                    add_heading(string heading_content,int heading_size=1,string style=SHED)
                                    adds a <h1> tag with some default styling unless specified.
    public  void                    add_paragraph(string para,string style=SPAR)
                                    adds a <p> tag with some default styling unless specified.
    public  void                    add_link(string linkurl,string linkname)
                                    adds a <a> tag with url and linkname.
    public  void                    add_button(string button_name)
                                    adds a <button> tag with given name.
    public  void                    add_list(string (&list)[LEN],string type="ul")
                                    adds a <ul> tag with <li> tags by default unless specified.
    public  void                    add_image(string imageurl,string alt="user_image",int width=100,int height=100)
                                    adds an <img> tag with some default attributes unless specified.
    public  void                    add_table(string (&table)[ROW][COL],string style=STAB)
                                    adds a <table> tag along with <th>,<td>,<tr> tag.
                                    
# Constructor Detail
        html()
          Description: 
            Creates a new file named sample.html with some tags already written it.
          Parameters:
            Takes no parameters.    
        html(string user_filename)
          Description:
            Creates a new file with given name with some tags already written in it.
          Parameters:
            user_filename=string type

# Function Detail
        public void add_title(string title_content)
          Description:
            Adds a title tag as shown <title>title_content</title>
          Parameters:
            title_content=string type
        public void add_heading(string heading_content,int heading_size=1,string style=SHED)
          Description:
            Adds a header tag as shown <h1 style="SHED">heading_content</h1>
          Parameters:
            heading_content=string type
            heading_size=int type takes value from 1 to 6
            style=string type should be of the form "color:blue;font:Arial;"
          Exceptions:
            if heading_size not between 1 to 6 throws an exception
        public void add_paragraph(string para,string style=SPAR)
          Description:
            Adds a paragraph tag as shown <p style="SPAR">para</p>
          Parameters:
            para=string type
            style=string type should be of the form "color:black;font:Arial;"
        public void add_link(string linkurl,string linkname)
          Description:
            Adds a link tag as shown <a href="linkurl">linkname</a>
          Parameters:
            linkurl=string type
            linkname=string type
        public void add_button(string button_name)
          Description:
            Adds a button tag as shown <button>button_name</button>
          Parameters:
            button_name=string type
        public void add_list(string(&list)[LEN],string type="ul")
          Description:
            Adds a list tag as shown    <ul>
                                        <li>list[0]</li>
                                        <li>list[1]</li>
                                        .
                                        .
                                        .
                                        .
                                        <li>list[LEN-1]</li>
                                        </ul>
          Parmeters:
            list[]=string array
            type=string type takes  value either "ul" or "ol" 
          Exception:
            throws an exception if type value is not "ol" or "ul"
        public void add_image(string imageurl,string alt="user_image",int width=100,int height=100)
          Decription:
            Adds an image tag as shown <img src="imageurl" alt="user_image" width="100" height="100">
          Parameters:
            imageurl=string type
            alt=string type displays this name if image cant be displayed
            width=int type
            height=int type
        public void add_table(string (&table)[ROW][COL],string style=STAB)
          Description:
            Adds table tag as shown   <table style="STAB">
                                      <tr>
                                      <th style="STAB">table[0][0]</th>
                                      <th style="STAB">table[0][1]</th>
                                      <th style="STAB">table[0][2]</th>
                                      .
                                      .
                                      .
                                      </tr>
                                      <tr>
                                      <td style="STAB">table[1][0]</td>
                                      <td style="STAB">table[1][1]</td>
                                      <td style="STAB">table[1][2]</td>
                                      .
                                      .
                                      .
                                      </tr>
                                      <tr>
                                      <td style="STAB">table[2][0]</td>
                                      <td style="STAB">table[2][1]</td>
                                      <td style="STAB">table[2][2]</td>
                                      .
                                      .
                                      .
                                      </tr>
                                      .
                                      .
                                      .
                                      </table>
           Parameters:
             table[][]=2d string array
             style=string type should be of the form "color:blue;font:Arial;"

