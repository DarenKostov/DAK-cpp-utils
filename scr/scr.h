/*
  Daren Kostov
  SCR- Simple Csv Reader

  You are free to use this as long as your usage doesnt violate the GPLv3 licence

*/

#include <string>
#include <list>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>

#ifndef SIMPLE_CSV_READER
#define SIMPLE_CSV_READER


class SCR{

  private:
    //thats where we store all of the colmns
    std::vector<std::string> columns;

    //the file stream
    std::fstream file;




  public:
    //constructor, takes the path to the file as an argument
    SCR(std::string);

    //constructor, empty
    SCR();
    
    //opens a file, takes the path of the file as an argument, returns 0 if sucess
    int open(std::string);

    //closes the file that is open, returns 0 if success
    int close();

    //reads the column at the given index and outputs the contents to a vector
    template<class T>
    int read(int column, std::vector<T>& output){
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
              output.push_back((T)word);

            index++;
        }
      }
    
      //get back at the top of the file
      file.clear();
      file.seekg(0);

      return 0;
    
    }

    //reads the column given and outputs the contents to a vector
    template<class T>
    int read(std::string column, std::vector<T>& output){
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




    
};

#endif



