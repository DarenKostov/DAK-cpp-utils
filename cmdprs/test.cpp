#include <iostream>
#include <vector>
#include <cstring>


#include "./parser.h"

using namespace std;


int main (){
   Parser parser=Parser();


   {
      string aliases[100]={"test", "t"};
      string args[100]={"cmd", "aqs", "aqs"};
      parser.addCommand(Command(2, aliases, "desc", 3, args, "any any any", "long desc"));
   }

   parser.readLn();

   cout << "=========\n";
   cout << parser.getArgumentString(0) << '\n';
   cout << parser.getArgumentString(1) << '\n';
   cout << parser.getArgumentString(2) << '\n';
   
return 0;

}
