#include <iostream>
#include <vector>
#include <string>


#include "./command.h"
#include "./parser.h"

using namespace std;

//constructor
Parser::Parser(){
  currentCommandString=new string[1];
  
  char alias[100][100]={""};
  char description[100]="";
  char args[100][100]={""};
  char argsDescription[100]="";
  char extraDescription[300]="";
  emptyCommand=Command(1, alias, description, 1, args, argsDescription, extraDescription);
  
  
}

Parser::~Parser(){
  delete[] currentCommandString;
}

//add from a Command pointer
void Parser::addCommand(Command* input){
  allCommandDef.push_back(Command(*input));
}
//add from a Command pointer vector
void Parser::addCommands(vector<Command*> input){
  for(vector<Command*>::iterator i=input.begin(); i!=input.end(); i++){
    addCommand(*i);
    // allCommandDef.push_back(**i);       
  }
}

//add from a Command
void Parser::addCommand(Command input){
  allCommandDef.push_back(Command(input));
}
//add from a Command vector
void Parser::addCommands(vector<Command> input){
  for(vector<Command>::iterator i=input.begin(); i!=input.end(); i++){
    addCommand(*i);
    // allCommandDef.push_back(**i);       
  }
}
 
bool Parser::removeCommand(string in){
  
  for(auto i=allCommandDef.begin(); i!=allCommandDef.end(); i++){
    if(i->aliases[0]==in)
      allCommandDef.erase(i);
    return true; 
  }
    return false; 
}

 
Command Parser::commandDefAt(int i){
  //add i to the pointer (go to index i) and derefrence it
  return *(allCommandDef.begin()+i);
}
   
vector<Command> Parser::getAllCommands(){
  return allCommandDef;
}
  
  


void Parser::readLn(){
  char input[99];
  
  char output[99][99];
  
  cin.getline(input, 99);

  int j=0;
  int word=0;
  
  //loop through until you meet a /0
  for(int i=0; i<99; i++){
    //once a you see a ' ' go to the next word
    if(input[i]==' '){
      output[word][i-j]='\0';
      j=++i;
      word++;
      //continue;
    }  
  
    output[word][i-j]=input[i];
    
    if(input[i]=='\0'){
      // word++;
      break;     
    }
  }
  
  
  currentCommandLength=word+1;
  
  
  //make a string of all the commands separated by " "
  string outputstring[currentCommandLength];
   for(int i=0; i<currentCommandLength; i++){
    outputstring[i]=output[i];
  }
  
  
  //free the memory in the command
  delete[] currentCommandString;
  
  
  //word is your amount of arguments
  
  
  if(setCurrentCommand(string(output[0]))){
    //fix the command length
    currentCommandLength=min(currentCommandLength, currentCommandDef->argsAmount);
    
    
    currentCommandString=new string[currentCommandLength];
    fixArgs(outputstring, currentCommandLength);
  }else{//if it could find an alias the command inputed was invalid
    //the current command is nothing, empty
    currentCommandDef=&emptyCommand;
    currentCommandString=new string[1];
    currentCommandString[0]=currentCommandDef->aliases[0];
    
  }
  
}


string Parser::getArgumentString(int i){
  if(i>=currentCommandLength)
    return string("");
  return currentCommandString[i];
}



bool Parser::setCurrentCommand(string input){
  
  int count=0;
  bool skipErasing=false;
  for(vector<Command>::iterator i=allCommandDef.begin(); i!=allCommandDef.end(); i++){//all commands loop
    count++;
    for(int j=0; j<(*i).aliasesAmount; j++){//aliases loop
      
      //if our cmd is any valid alias
      if((*i).aliases[j]==input){
        //set the curComDef to the adress of the command
        currentCommandDef=&(*i);        
        return true;
      }
    }
  }

  return false;
}


//fix with "what"
void Parser::fixArgs(string* what, int amount){
  
  for(int i=0, j=0; i<amount; i++, j++){//loop through all of the args definitions (if its int, bool, str, ect)

      if(currentCommandDef->args[i]=="cmd"){
        currentCommandString[i]=currentCommandDef->aliases[0];
      }else if(currentCommandDef->args[i]=="str"){
        //do nothing, we arent using strings
      }else if(currentCommandDef->args[i]=="txt"){
        //do nothing it's already a string
        currentCommandString[i]=what[j];
      }else if(currentCommandDef->args[i]=="int"){
        //convert to int
        currentCommandString[i]=what[j];
      }else if(currentCommandDef->args[i]=="bool"){
        //convert to bool
        currentCommandString[i]=what[j];
      }else if(currentCommandDef->args[i]=="''"){
        //take in whatever is in the quotes
      
        //make sure we start with empty string
        currentCommandString[i]="";
      
        //if we start with quotes
        if(what[j][0]=='\''){
          
            //we end with quites as well?
            if(what[j][what[j].length()-1]=='\''){ 
              //yes?
              //remove first and last charcter and onto the next argument
              for(int k=1; k<what[j].length()-1; k++)
                currentCommandString[i]+=what[j][k];
              continue;
            }
        
        
        
          //no?
          //add the word (without the starting "'") and loop until we find the ending quotes 
        
          for(int k=1; k<what[j].length(); k++)
            currentCommandString[i]+=what[j][k];
        
          //THIS WILL CAUSE  A SEGFAULT WHEN THE USER DOEST END WITH A QUOTE
          //BUT THIS IS AN INTENDED FEATURE REST ASSURED
          while(true){
          
          
            //the words were initially separated by spaces
            currentCommandString[i]+=" ";
          
            //next word
            j++;  
          
            //we end with quites?
            if(what[j][what[j].length()-1]=='\''){ 
              //yes?
              //add the word (withut the ending ') to our argument and onto the next argument 
              for(int k=0; k<what[j].length()-1; k++)
                currentCommandString[i]+=what[j][k];
              break;
            }

            //no? add the entire word to the argument and onto the next word
            currentCommandString[i]+=what[j];
          }
        
        
        }
    
      }else
        currentCommandString[i]=""; 

    
    
  }
  
}

