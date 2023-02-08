/*
  Daren Kostov
  SCR- Simple Csv Reader

  Licenced  under GPLv3
*/






#include "scr.h"

using namespace std;

SCR::SCR(string path){
  // file.open(path, ios::in);
  open(path);
}

SCR::SCR(){}


  
int SCR::open(string path){
  file.open(path, ios::in); 

  //get the 1st line
  string line, word;
  getline(file, line);
  stringstream ss(line);

  //populate our columns
  while (getline(ss, word, ',')) {
    columns.push_back(word);
  }

  //get back at the top of the file
  file.clear();
  file.seekg(0);

  
  //return 0 if success, 1if failuare
  return 1-(int)(bool)file;

}

int SCR::close(){
  file.close();

  //most definitly likely not the way to do it
  return (int)(bool)file;
}


