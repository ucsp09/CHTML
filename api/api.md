# API REFERENCE

## CLASS base
      This is the base class which cannot be instantiated.
      
### Member Functions Summary
      
      Modifier and type               Function and Description
      public void                       dump()
                                           dumps the code written to sample.html
      public void                        dump(string fname,string ext)
                                            dumps the code written to specified filename.ext 
      public void			edit(string fname,string ext)
      					   enables editing of existing files
### Function Detail

   #### public void dump()
       Description:
           dumps the code to sample.html by default.
       Parameters:
            No parameters.
   #### public void dump(string fname,string ext)
       Description:
           dumps the code to filename.ext
       Parameters:
           fname=give filename
	   ext=give extension without dot
  #### public void edit(string fname,string ext)
      Description:
          enables the user to edit existing files.
      Parameters:
          fname=give filename
	  ext=give extension without dot

## CLASS xml:public base
       This is the xml class which inherits publicly the base class.It can be instantiated.
       
### Member Functions Summary
 
       Modifier and type               Function and Description
       public void                        open_tag(string tag)
                                                opens a tag
	 public void	      	      openln_tag(string tag)
                                                opens a tag in a new line
	 public void			      open_tag(string tag,string att,string val)
                                                opens a tag with given attribute and value
	 public void				insert_text(string text)
                                                inserts a text
	 public void				close_tag(string tag)
                                                closes a tag
	 public void			      closeln_tag(string tag)
                                                closes a tag in a newline
	 public void				write_tag(string tag,string text)
                                                opens a tag inserts text and close the tag
	 public void			      writeln_tag(string tag,string text)
                                                opens a tag in a newline inserts text and closes the tag
	 public void			      set_attribute(string tag,unordered_map<string,string> att,int occurence=-1)
                                                adds given attributes to specified tag inline
	 public void			      set_attribute(string tag,string att,string val,int occurence=-1)
                                                adds given attribute and value to specified tag inline
### Function Detail

   #### public void open_tag(string tag)
         Description:
            opens a tag
         Parameters:
            tag=give tagname
   #### public void openln_tag(string tag)
         Description:
            opens a tag new line
         Parameters:
            tag=give tagname
   #### public void open_tag(string tag,string att,string val)
         Description:   
            opens a tag with given attribute and value
         Parameters:
            tag=give tagname
            att=give attribute name
            val=give atrribute's value name
   #### public void insert_text(string text)
         Description:
             inserts a text
         Parameters:
             text=give text data
   #### public void close_tag(string tag)
         Description:
            closes the tag
         Parameters:
            tag=give tagname
   #### public void closeln_tag(string tag)
         Desciption:
            closes the tag in a newline
         Parameters:
            tag=give tagname
   #### public void write_tag(string tag,string text)
        Description:
            opens a tag inserts text and closes that tag.
         Parameters:
            tag=give tagname
            text=give text data
  #### public void writeln_tag(string tag,string text)
       Description:
           opens a tag inserts text closes a tag in a newline
       Parameters:
           tag=give tagname
           text=give text data
 #### public void set_attribute(string tag,unordered_map<string,string> att,int occurence=-1)
       Description:   
          adds given attributes to specified tag inline
       Parameters:
          tag=give tagname
          att=give attributes and values in the form of unordered_map
          occurence=give occurence number n to set attribute to nth tag default is -1 which means last.
       Exceptions:
            throws exceptions if given 0
            if the tag does nto exist it automatically creates a tag and sets attribute for it.
 #### public void set_attribute(string tag,string att,string val,int occurence=-1)
       Description:      
           adds given attribute and value to specified tag inline
       Parameters:
          tag=give tagname
          att=give attribute name
          val=give attribute's value name
          occurence=give occurence number n to set attribute to nth tag default is -1 which means last.
       Exceptions:
            throws exceptions if given 0
            if the tag does nto exist it automatically creates a tag and sets attribute for it.   
            
## CLASS html:public xml
      This is a class which inherits the xml class publicly and can be instantiated.

### Constructors Summary
       html()
            Creates a new object with some default html structure loaded.

### Member Functions Summary

      Modifier and type                Function and Description
      public void                         add_title(string text)
                                                adds title tag with given text        
	public void                         add_header(string text,int size=1)
                                                adds header tag h1-h6 with specified text
	public void                         add_header(string text,string att,string val,int size=1)
                                                adds header tag with specified text and specified attributes inline 
	public void                         add_para(string text)
                                                adds p tag with specified text
	public void                         add_para(string text,string att,string val)
                                                adds p tag with specified text and specified attributes inline
	public void                         add_button(string bname)
                                                adds button tag with given name
	public void                         add_link(string url,string lname)
                                                adds a link i.e 'a' tag
	public void                         add_image(string src)
                                                adds an img tag
	                                    template<size_t LEN>
	public void                         add_list(string (&list)[LEN],string type="ul")
                                                adds a ul or ol list
	                                    template<size_t ROW,size_t COL>
	public void                         add_table(string (&table)[ROW][COL])
                                                adds a table
	public void                         add_style(string selector_type,string selector_name,string att)
                                                adds attributes to the style tag i.e; embedded style
      public void                         add_stylesheet(string url)
                                                adds an external stylesheet
                   
### Constructor Detail

   #### html()
      Description: 
        Creates a new object with some tags already written it when dumped.
      Parameters:
        Takes no parameters.    
### Function Detail

   #### public void add_title(string text)
       Description:     
         adds title tag with given text
       Parameters:
         text=give title content
   #### public void add_header(string text,int size=1)
       Description:
         adds header tag h1-h6 with specified text
       Parameters:
         text=give header content
         size=give value inclusive(1,6)
       Exception:
         throws an exception if size is less than 1 or greater than 6   
   #### public void add_header(string text,string att,string val,int size=1)
       Description:
          adds header tag with specified text and specified attributes inline
       Parameters:
          text=give header content
          att=give attribute name
          val=give attribute val
          size=give value inclusive(1,6)
       Exception:
         throws an exception if size is less than 1 or greater than 6   
   #### public void add_para(string text)
       Description:
         adds p tag with specified text
       Parameters:
         text=give paragraph content  
   #### public void add_para(string text,string att,string val)
       Description:
         adds p tag with specified text and specified attributes inline
       Parameters:
          text=give paragraph content
          att=give attribute name
          val=give attribute val
   #### public void add_button(string bname)
       Description:
         adds button tag with given name
       Parameters:
          bname=give button name
   #### public void add_link(string url,string lname)
       Description:
          adds a link i.e 'a' tag
       Parameters:
         url=give url
         lname=give link name to be displayed
   #### public void add_image(string src)
       Description:
         adds an img tag
       Parameters:
         src=give url of image
   #### template<size_t LEN> public void add_list(string (&list)[LEN],string type="ul")
       Description:
          adds a ul or ol list
       Parameters:
          string(&list)[LEN] =give a list of strings
          type=give list type either ul or ol
       Exception:
            throws an exception if type is not ol or ul
   #### template<size_t ROW,size_t COL> public void add_table(string (&table)[ROW][COL])
       Description:
          adds a table
       Parameters:
          string(&table)[ROW][COL]=give a 2d array of strings  
   #### public void add_style(string selector_type,string selector_name,string att)
       Description:
           adds attributes to the style tag i.e; embedded style
       Parameters:
           selector_type=give either tag or id or class
           selector_name=give the selector name
           att=give style attributes as a string
      Exception:
           thrws an exception if selector is not tag or id or class       
   #### public void add_stylesheet(string url)
       Description:
           adds an external stylesheet
       Parameters:
           url=give url of stylesheet
