/*
Copyright (c) 2024 Daren Kostov

License: GPLv3

Version- a class that just stores a version

*/

#include "version.hxx"
#include <cmath>
#include <cstring>

Version::Version(){
  patch=0;
  minor=0;
  major=0;
}

Version::Version(const int& a, const int& b, const int& c){
  patch=c;
  minor=b;
  major=a;
}

Version::Version(const std::string& input){
  int majorMinorPos=input.find('.', 0);  
  int minorPatchPos=input.find('.', majorMinorPos+1);  

  major=std::stoi(input.substr(0, majorMinorPos));
  minor=std::stoi(input.substr(majorMinorPos+1, minorPatchPos-majorMinorPos-1));
  patch=std::stoi(input.substr(minorPatchPos+1));
  
}

Version::Version(const char* input){

  //reset all sub-versions
  patch=0;
  minor=0;
  major=0;
  
  int length=std::strlen(input);
  int i{0};

  //handle patch, most right side
  for(;input[length-i-1]!='.'; i++){
    patch+=(input[length-i-1]-'0')*std::pow(10, i);
  }

  //handle minor, middle
  for(int j{++i};input[length-i-1]!='.'; i++){
    minor+=(input[length-i-1]-'0')*std::pow(10, i-j);
  }

  //handle major, most left side
  for(int j{++i}; i<length; i++){
    major+=(input[length-i-1]-'0')*std::pow(10, i-j);
  }

  
}

Version::~Version(){
}


bool Version::operator==(const Version& right)const{
  return major==right.major && minor==right.minor && patch==right.patch;
}

bool Version::operator!=(const Version& right)const{
  return major!=right.major || minor!=right.minor || patch!=right.patch;
}

bool Version::operator<(const Version& right)const{
  return std::tie(major, minor, patch) < std::tie(right.major, right.minor, right.patch);
}

bool Version::operator<=(const Version& right)const{
  return std::tie(major, minor, patch) <= std::tie(right.major, right.minor, right.patch);
}

bool Version::operator>(const Version& right)const{
  return std::tie(major, minor, patch) > std::tie(right.major, right.minor, right.patch);
}

bool Version::operator>=(const Version& right)const{
  return std::tie(major, minor, patch) >= std::tie(right.major, right.minor, right.patch);
}


std::string Version::toString()const{
  return std::to_string(major)+'.'+std::to_string(minor)+'.'+std::to_string(patch);
}


