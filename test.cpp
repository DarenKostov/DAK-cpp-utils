#include <iostream>


#include "./parser.h"

using namespace std;


int main (){
   char ALLCOMMANDS[10][10][10]={
      {"command1", "com1", "c1"},
      {"command2", "com2", "c2"},
      {"command3", "com3", "c3"},
      {"command4", "com4", "c4"},
   };
   
   char ALLCOMMANDSDESCRIPTION[10][50]={
      "command 1 description",
      "command 2 description",
      "command 3 description",
      "command 4 description",
   };
   
   //str, int, float, bool, 
   char ALLCOMMANDSARGS[][10][10]={
      {},
      {"int"},
      {"float"},
      {"str"}
   };
   
   char ALLCOMMANDSARGSDESC[10][20]={
      "none",
      "integer",
      "floating point",
      "string"
   };
   
   
   Parser parser= Parser(ALLCOMMANDS, ALLCOMMANDSDESCRIPTION, ALLCOMMANDSARGS, ALLCOMMANDSARGSDESC);
   
   parser.readLn();
   
   
      cout << parser.returnWholeCommand(i) << endl;
   
   
return 0;

}
