// Reads a text file and adds the specified number of newlines at the given delimiter

#include <iostream>
#include <fstream>
#include <string>

#include "split.h"

using namespace std;

int removenewlines(string iFile, string oFile) {

  string data;
  ifstream myIFile(iFile);
  ofstream myOFile(oFile);

  while(getline(myIFile, data)) {

    myOFile << data;

  }

  myOFile.close();
  myIFile.close();

  return 0;

}

int split(string iFile, string oFile, char delimiter, int newlines, char keepdelimiter) {

  string data;
  ifstream myIFile;
  ofstream myOFile;

  myIFile.open(iFile);
  if (!myIFile.is_open()) {
    cout << "Error opening file!";
  }

  myOFile.open(oFile);
  if (!myOFile.is_open()) {
    cout << "Error creating file!";
  }

  while(getline(myIFile, data, delimiter)) {

    myOFile << data;

    if (toupper(keepdelimiter) == 'Y') {
      myOFile << delimiter;
    }

    for (int i = 0; i < newlines; i++) {
      myOFile << endl;
    }

  }

  myOFile.close();
  myIFile.close();

  return 0;

}

int main() {

  // removenewlines("EDI850.txt", "single.txt");
  // split("single.txt", "test.txt", '~', 1, 'Y');
  split("EDI850.txt", "test.txt", '~', 1, 'Y');

  return 0;

}