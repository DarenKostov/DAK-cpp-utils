/*
  Daren Kostov

  sources:
  https://stackoverflow.com/questions/3487717/erasing-multiple-objects-from-a-stdvector
  https://en.cppreference.com/w/cpp/algorithm/remove
  https://en.cppreference.com/w/cpp/algorithm/unique
*/


#include "vectorUtils.hxx"
#include <algorithm>

template <class T>
bool vectUtil::removeAtIndex(std::vector<T>& vect, size_t index){

  //avoid out of bounds errors
  if(!vectUtil::withinBounds(vect, index)){
    return false;
  }

  // https://stackoverflow.com/questions/3487717/erasing-multiple-objects-from-a-stdvector
  vect[index]=vect.back();
  vect.pop_back();

}


template <class T>
size_t vectUtil::findIndex(const std::vector<T>& vect, T element){
  return std::find(vect.begin(), vect.end(), element)-vect.begin();
}



template <class T>
bool vectUtil::removeElement(std::vector<T>& vect, T element){

  size_t oldSize=vect.size();

  // https://en.cppreference.com/w/cpp/algorithm/remove
  vect.erase(std::remove(vect.begin(), vect.end(), element), vect.end());
  
  //did the size of the vector change? if so we must have removed at least 1 element, aka, success
  return oldSize>vect.size();
  
}

template <class T>
bool vectUtil::containsElement(const std::vector<T>& vect, T element){
  return std::find(vect.begin(), vect.end(), element)!=vect.end();
}


template <class T>
size_t vectUtil::countElements(const std::vector<T>& vect, T element){
  return std::count(vect.begin(), vect.end(), element);
}

template <class T>
bool vectUtil::withinBounds(const std::vector<T>& vect, size_t index){
  return index>0 && index<vect.size();
}

template <class T>
bool vectUtil::isElementADuplicate(const std::vector<T>& vect, T element){
  return vectUtil::countElements(vect, element)>1;
}

template <class T>
void vectUtil::eraseDuplicates(std::vector<T>& vect){
  
  //https://en.cppreference.com/w/cpp/algorithm/unique
  auto duplicateBegin=std::unique(vect.begin(), vect.end());
  vect.erase(duplicateBegin, vect.end());

  std::sort(vect.begin(), vect.end());

  duplicateBegin=std::unique(vect.begin(), vect.end());
  vect.erase(duplicateBegin, vect.end());

}

template <class T>
bool pushBackWithoutDuplicates(std::vector<T>& vect, T element){
  if(vectUtil::containsElement(vect, element)){
    return false;
  }

  vect.push_back(element);
  return true;
}
 

