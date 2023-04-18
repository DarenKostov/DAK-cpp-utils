/*
  Daren Kostov

  Licence: GPLv3

  
  
  This is a demo for the SCMDPRS

*/

#include "scmdprs.h"


int main(){

  
  std::vector<std::string> commands =readLine();


  std::cout << "you inputted:\n";
  int i=0;
  for(auto command : commands){
    printf("%d: %s\n", i++, command.c_str());
  }


  

}



