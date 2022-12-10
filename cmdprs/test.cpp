#include <iostream>
#include <vector>
#include <cstring>


#include "./parser.h"

using namespace std;


int main (){
   
   char*** ALLCOMMANDS= new char**[10];
   
   for(int i=0; i<1; i++){
      ALLCOMMANDS[i]=new char*[10];  
      for(int j=0; j<3; j++){
         ALLCOMMANDS[i][j]=new char[10];  
      }
   }   
   
   
      
      
   strcpy(ALLCOMMANDS[0][0], "command1");
   strcpy(ALLCOMMANDS[0][1], "com1");
   strcpy(ALLCOMMANDS[0][2], "c1");
   

   cout << "start\n";
   
   
      // {"command1", "com1", "c1"},
      // {"command2", "com2", "c2"},
      // {"command3", "com3", "c3"},
      // {"command4", "com4", "c4"},
   
   
   
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
   
   
   cout << "mid\n";
   Parser parser= Parser(ALLCOMMANDS, ALLCOMMANDSDESCRIPTION, ALLCOMMANDSARGS, ALLCOMMANDSARGSDESC);
   
   cout << "end\n";
   parser.readLn();
   
   
      cout << parser.returnCommand(0) << endl;
   
   
return 0;

}
