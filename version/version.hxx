/*
Copyright (c) 2024 Daren Kostov

License: GPLv3

Version- a class that just stores a version

*/

#pragma once

#include <string>

class Version{

  public:

    //sub-versions
    int patch;
    int minor;
    int major;


    //==constructors
    
    // default: 0.0.0
    Version();

    // major, minor, patch
    Version(const int&, const int&, const int&);
  
    // must be in "{major}.{minor}.{patch}" format
    Version(const std::string&);
  
    // must be in "{major}.{minor}.{patch}" format
    Version(const char*);

    ~Version();

    //==operator overloads

    bool operator==(const Version&)const;
    bool operator!=(const Version&)const;

    bool operator<(const Version&)const;
    bool operator<=(const Version&)const;

    bool operator>(const Version&)const;
    bool operator>=(const Version&)const;
  
  
    //==misc

    // gives you a string in the "{major}.{minor}.{patch}" format
    std::string toString()const;
  

  
};
