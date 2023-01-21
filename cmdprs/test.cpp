#include <iostream>
#include <vector>
#include <cstring>


#include "./parser.h"

using namespace std;


int main (){
   Parser parser=Parser();


   {
      string aliases[100]={"test"};
      string args[100]={"txt", "txt", "txt"};
      parser.addCommand(Command(1, aliases, "desc", 3, args, "any any any", "long desc"));
   }

   parser.readLn();
   
   cout << parser.getArgumentString(2) << '\n';
   
return 0;

}
