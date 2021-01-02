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
  ifstream myIFile(iFile);
  ofstream myOFile(oFile);

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

  string iFile = "EDI850.txt";
  string oFile = "test2.txt";
  string oFile2 = "test.txt";

  removenewlines(iFile, oFile2);
  split(iFile, oFile, '~', 0, 'Y');

  return 0;

}