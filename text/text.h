/*
  Daren Kostov
  Text- string but made by me  
  
  code should be hosted on:
  https://github.com/DarenKostov/DAK-cpp-utils

  
  You are free to use it for any purpose, as long as it doesn't violate the GPL3 licence.
  (you might want to use this if you don't have access to std::string)

  resources used:
  https://www.geeksforgeeks.org/operator-overloading-c/
  https://stackoverflow.com/questions/56387509/this-argument-to-member-function-select-has-type-const-selectparam-but-fu
  https://stackoverflow.com/questions/39808976/operator-overloading-for-primitive-types-in-c

  http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html
  https://www.geeksforgeeks.org/difference-between-const-int-const-int-const-and-int-const/

*/



//watch out for the capitalization of "text" in the comments
//"Text" refers to the class, "text" refers to where the the char array is stored

class Text{
  public:
    //whenever I say char array I mean char pointer pointing to a char array

    Text(); //make an empty Text
    Text(char); //make a Text from a single char
    Text(const char*); //make a Text from a char array
    Text(const Text&); //make a Text from a Text
    // Text(Text); //make a Text from Text, from Text, from Text that is also made from Test....
    ~Text(); //deconstructor, makes sure no memory leaks occur
  
    // plus operator
    const Text operator+(char); //Concatenates the text and a char into a Text
    const Text operator+(const char*); //Concatenates the text and char array into a Text
    const Text operator+(Text); //Concatenates the 2 texts into a Text
    
    //equals operator
    Text& operator=(char); //sets our text to the data in a char
    Text& operator=(const char*); //sets our text to the data in a char array
    Text& operator=(Text); //sets our text to the data in the Text input
    
    //plus equals operator
    Text& operator+=(char); // Concatenates the char given to this text, returns the result
    Text& operator+=(const char*); // Concatenates the char array given to this text, returns the result
    Text& operator+=(Text); // Concatenates the text given to this text, returns the result
    
    //equals equals operator
    bool operator==(char); //returns weather the text is equal to a char
    bool operator==(const char*); //returns weather the text is equal to a char array
    bool operator==(Text); //returns weather the text is equal to a text in a Text

    //functions that dont modify anything
    char& operator[](int) const; //returns the character at that index; note you can set the character with this as well
    int len()const; //returns the length of this text
    char* val()const; //returns the text in the form of a char array
    Text getText()const; //returns a copy Text of the class itself
    int getId()const; //returns the id of the Text, purely for debugging purposes
   
     //alias functions
    char& charAt(int)const; //returns the character at this index
    char getCharAt(int)const; //returns the character at this index; note you can NOT set the character with this
    int getLength()const; //returns the length of this text
    char* getCharArr()const; //returns the text in the form of a char array
    char* charArr()const; //returns the text in the form of a char array
    
    /*
      note:
      Want to concatinate 2 Texts into a char array? Just do:
      (text1+text2).val()
  
      what to concatinate 2 char arrays into a char array? just do:
      (Text(char1)+char2).val()
  
    */
  
  
  // casts
  operator char*(); //cast it to a char array, essentially the same as ".val()"
  operator const char*(); //cast it to a char array, essentially the same as ".val()"... but a const
  operator char(); //cast it to a single character, if the length is more than 1 itll cast the 1st character, essentally the same as "[0]" BUT you make a copy here
  
  
  private:
    char* text; //the char array
    int length; //the length of the char array
    int id; //the id of this Text, purely for debugging purposes
    
    
};

// char a[100]="qwerty";
// char b[100]="qwerty";
// bool c=a==b;

//working in reverse, concatenating, setting, etc Text to other things


// char*& operator=(char*&, Text&);

