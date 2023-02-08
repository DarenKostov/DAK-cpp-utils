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

SCR::SCR(){
  //do nothing
}


  
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


//read given an idex
int SCR::read(int column, std::vector<std::string>& output){
  std::string line, word;
  getline(file, line);

  //loop though every line
  while (file.good()) {

      getline(file, line);
      std::stringstream ss(line);
      int index=0;
    
      //loop through every value
      while (getline(ss, word, ',')) {
        if(index==column)
          output.push_back(word);

        index++;
    }
  }

  //get back at the top of the file
  file.clear();
  file.seekg(0);

  return 0;

}

int SCR::read(std::string column, std::vector<std::string>& output){
  int columnInt=-1;

  int i=0;
  for(auto ptr=columns.begin(); ptr!=columns.end(); ptr++){
    i++;
    if(*ptr==column){
      columnInt=i;
      break;
    }
    
  }

return read(columnInt, output);

  
}



