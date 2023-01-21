/*
  Daren Kostov
  this struct is a command, which includes its aliaces and arguments
  
*/



#include <string>
typedef std::string string;


#ifndef COMMAND
#define COMMAND


struct Command{

  string* aliases;  //valid variations of the command, the 0th index is the main command
  string description; //what the command is actualy about, does it pick up apples? pears?
  string longDescription; //like description but with more details, could include tips as well 
  string argsDescription; //what are actually the arguments, amount of apples? pears?
  int aliasesAmount; //amount of aliases, self explanatory
  int argsAmount; //amount of arguments, self explanatory

  
  // template <class arr1, class arr2>
  Command(int AliasesAmount, const string* Aliases, const string Description, int ArgsAmount, const string ArgsDescription, const string LongDescription){
   
    //command aliases copy over
    aliases= new string[AliasesAmount];
    for(int i=0; i<AliasesAmount; i++){
      //copy the input into the internal variable
      aliases[i]=Aliases[i];
    }  

    //copy over descriptions
    description=Description;
    argsDescription=ArgsDescription;
    
    //copy over amounts
    aliasesAmount=AliasesAmount;  
    argsAmount=ArgsAmount;  
    longDescription=LongDescription;
  }
  
  
  //copy constructor
  Command(const Command &input){
    //copy over descriptions
    description=input.description;
    argsDescription=input.argsDescription;
    longDescription=input.longDescription;
    
    
    //copy over amounts
    aliasesAmount=input.aliasesAmount;  
    argsAmount=input.argsAmount;  
    
    //command aliases copy over
    aliases= new string[input.aliasesAmount];
    for(int i=0; i<input.aliasesAmount; i++){
      //copy the input into the internal variable
      aliases[i]=input.aliases[i];
    }  

  }
  
  //empty command
  Command(){
    aliases= new string[0];
  }
  
  //deconstructor, we dont want memory leaks now do we
  ~Command(){
    delete[] aliases;
  }
  
  void operator=(Command in){//sets the command to another command
    
    //free up the memory used
    delete[] aliases;
    
    //command aliases copy over
    aliases= new string[in.aliasesAmount];
    for(int i=0; i<in.aliasesAmount; i++){
      //copy the input into the internal variable
      aliases[i]=in.aliases[i];
    }  

    
    //copy over descriptions
    description=in.description;
    argsDescription=in.argsDescription;
    
    //copy over amounts
    aliasesAmount=in.aliasesAmount;  
    argsAmount=in.argsAmount; 
    longDescription=in.longDescription; 
  }
  
};

#endif
