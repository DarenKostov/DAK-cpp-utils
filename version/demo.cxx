#include <iostream>
#include <string>
#include "version.hxx"

std::string falseTrue(bool in){
  return in? "true" : "false";
}

void compare(const Version& left, const Version& right){
  std::cout << left.toString() << " == " << right.toString() << " = " << falseTrue(left==right) << '\n';
  std::cout << left.toString() << " != " << right.toString() << " = " << falseTrue(left!=right) << '\n';
  std::cout << left.toString() << " < " << right.toString() << " = " << falseTrue(left<right) << '\n';
  std::cout << left.toString() << " <= " << right.toString() << " = " << falseTrue(left<=right) << '\n';
  std::cout << left.toString() << " > " << right.toString() << " = " << falseTrue(left>right) << '\n';
  std::cout << left.toString() << " >= " << right.toString() << " = " << falseTrue(left>=right) << '\n';

}

int main(){

  Version myVer1="51.43.79";
  
  compare(myVer1, Version("51.43.79"));  
  std::cout << "=====\n";

  compare(myVer1, Version("51.43.82"));  
  std::cout << "=====\n";

  compare(myVer1, Version("51.54.79"));  
  std::cout << "=====\n";

  compare(myVer1, Version("52.43.79"));  
  std::cout << "=====\n";

  compare(myVer1, Version(50, 100, 79));  
  std::cout << "=====\n";

  std::string ver="50.888.999";
  compare(myVer1, Version(ver));  
  std::cout << "=====\n";

}
