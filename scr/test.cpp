#include <iostream>
#include "scr.h"
#include <vector>


using namespace std;


int main(){

  SCR reader;

  reader.open("data.csv");



  cout << "shapes\n";
  vector<string> shapes;
  reader.read(2, shapes);
  for(auto i=shapes.begin(); i!=shapes.end(); i++){
    cout << *i << ", " << flush;
  }
  cout << "\n";
  
  cout << "id\n";
  vector<int> ids;
  reader.read(1, ids);
  for(auto i=ids.begin(); i!=ids.end(); i++){
    cout << *i << ", " << flush;
  }
  cout << "\n";

  
  reader.close();

}