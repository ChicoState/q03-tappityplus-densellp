#include <cmath>
#include "tappity.h"

using std::round;

/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(std::string reference)
{
  // If the string is not empty take first branch
  if (reference.size() > 0){
    solution = reference;
  } else {
    // If the string is empty, reference is empty
    reference = "";
  }
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
  userInput = input;
  return;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
  int diffCount; // Used for storing the value of different characters
  // Statements used to determine larger of 2 strings
  if (solution.size() > userInput.size()){
    diffCount = solution.size() - userInput.size();
  } else if (userInput.size() > solution.size()){
    diffCount = userInput.size() - solution.size();
  } else {
    // Strings are the same size, there is no difference
    diffCount = 0;
  }
  return abs(diffCount);
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
  int correct = 0; // Number of similar characters in strings
  double percent = 0.0; // percentage of accuracy

  int itter = 0; // Used for itterating through the smallest string
  int limit = 0; // Used for itterating to the size of the smallest string

  if (userInput.size() == 0 && solution.size() == 0){ // If both are empty, they are the same
    return 100;
  }

  // Check which string is smaller 
  if (userInput.size() < solution.size()){
    limit = userInput.size();
  } else {
    limit = solution.size();
  }

  // Itterate through the smallest string size
  while(itter < limit){
    if(userInput[itter] == solution[itter]){
      correct++;
    }
    itter++;
  }

  // Divide correct variable by the larger string
  if (userInput.size() > solution.size()){
    percent = (double)((double)correct/(double)userInput.size());
  } else {
    percent = (double)((double)correct/(double)solution.size());
  }

  return round(percent*100);
}
