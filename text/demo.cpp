/*

  Daren Kostov
  this is a file showing some of the functionality of Text
  a demo file

*/

#include "text.h"
#include "iostream"


int main(){

  //initialize Text from many types
  Text thisText="this text";
  Text charText='t';
  Text anotherText=Text("another text");
  Text numText=32000;
  Text emptyText;


  char charArray[]="this char array";
  Text charArrayText=charArray;
  

  //concatinate Text with types
  std::cout << (thisText+" : "+anotherText+'\n');
  std::cout << "32k: "+numText << "\n";


  //get each char of a Text
  for(int i=0; i<thisText.len(); i++){
    std::cout << thisText.getCharAt(i)+Text("\n");
  }

  //more concatination
  std::cout<< charArray+Text(" and ")+anotherText+"\n\n";


  //get each char of a Text concatination
  for(int i=0; i<(thisText+" and a number: "+numText).len(); i++){
    std::cout << (thisText+" and a number: "+numText).getCharAt(i)+Text(" ");
  }
  std::cout << '\n';


  //+= operator
  thisText+="??";
  emptyText+=thisText+" "+anotherText+"!!";
  std::cout << emptyText << '\n';  

  //comparison
  std::cout << (thisText=="this text??"? "true" : "false") << '\n';
  std::cout << (thisText=="this tExt??"? "true" : "false") << '\n';
  std::cout << (Text('j')=="j"? "true" : "false") << '\n';


  //std::cout & std::cin overloads

  std::cout << thisText.val() << '\n';//vs
  std::cout << thisText << '\n';//vs

  Text input;
  std::cout << "type something and then hit [ENTER]: ";
  std::cin >> input;
  std::cout << "you typed: \""+input+"\", with length "+input.len()+'\n';

    
}