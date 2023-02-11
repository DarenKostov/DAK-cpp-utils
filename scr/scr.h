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

    //stores the column data at the given index in a std::string vector
    int store(int column, std::vector<std::string>& output);

    //stores the column data in a std::string vector
    int store(std::string column, std::vector<std::string>& output);




    
};

#endif



