/*
  Daren Kostov
  Some functions (shortcuts) that manipulate a vector that I am too tired (lazy) to rewrite for each new project I start.
*/

#pragma once

#include <cstddef>
#include <vector>

namespace vectUtil {

//removes an element from a vector at the specifed index; returns whether it was a success or not; destroys order
template <class T>
bool removeAtIndex(std::vector<T>&, size_t);

//removes all instances of an element from a vector, give the element itself, not an index; returns whether it was a success or not
template <class T>
bool removeElement(std::vector<T>&, T);
  
//gives you the index of the first occurrence of the element given (if non existant it'll give you the size of the vector)
template <class T>
size_t findIndex(const std::vector<T>&, T);

//return whether or not the vector contains the specified element
template <class T>
bool containsElement(const std::vector<T>&, T);

//return the amount of times an elemnt is contained in the specified vector
template <class T>
size_t countElements(const std::vector<T>&, T);

//return whether or not the inputted index is less than size() and greater-or-equal to 0
template <class T>
bool withinBounds(const std::vector<T>&, size_t);

//returns whether or not the element is contained more than once in the specified vector
template <class T>
bool isElementADuplicate(const std::vector<T>&, T);

//erases all duplicates in a vector; destroys order
template <class T>
void eraseDuplicates(std::vector<T>&);

//adds an element to the back of the arary if it is not a duplicate, returns whether it was successfull or not
template <class T>
bool pushBackWithoutDuplicates(std::vector<T>&, T);
  
}
