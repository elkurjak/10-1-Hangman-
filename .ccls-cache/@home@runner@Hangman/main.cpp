#include <iostream>

#include <cstring>
using namespace std;



// find the unique values in a string


int findNumOfUniqueCharInStr(string myString) {

  const int L = myString.length();

  char unique[L]; // set all to NULL

  int n, k;

  // setup unique to store the first value of the string and then
  // all NULLs

  unique[0] = myString[0];

  // initialize all other spots in unique to be NULL aka '\0'

  for (n = 1; n < L; n++) {

    unique[n] = '\0';

  }

  int j = 1;

  bool FLAG;

  // fill unique
  for (n = 1; n < L; n++) {

    FLAG = false; // meaning it does not exist

    for (k = 0; k < L; k++) {

      if (myString[n] == unique[k]) // then found it does exist

        FLAG = true;

    }

    // if it didn't exist we will add it in to unique

    if (FLAG == false) {

      unique[j] = myString[n];

      j++;

    }

  }

 

  return j;

}
int main() {
  string word;
  string guess;
  cin >> word;
  cin >> guess;
  
  int length = findNumOfUniqueCharInStr(word);

  int parts = 0;

  

  for(int i = 0; i < 26; i++){
     if (word.find(guess[i]) != string::npos){
       length--;
     }
     else{
       parts++;
     }
    if (parts == 10){
      cout << "LOSE";
      break;
    }
    if(length == 0){
      cout <<"WIN";
      break;
    }
  }  
}