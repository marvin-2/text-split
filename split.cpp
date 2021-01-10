#include "split.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int removenewlines(string iFile, string oFile) {

  string data;
  ifstream myIFile;
  ofstream myOFile;

  myIFile.open(iFile);
  if (!myIFile.is_open()) {
    throw runtime_error("Error! Cannot open input file: " + iFile + '\n');
  }

  myOFile.open(oFile);
  if (!myOFile.is_open()) {
    myIFile.close();
    throw runtime_error("Error! Cannot create file: " + oFile + '\n');
  }

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
    throw runtime_error("Error! Cannot open input file: " + iFile + '\n');
  }

  myOFile.open(oFile);
  if (!myOFile.is_open()) {
    myIFile.close();
    throw runtime_error("Error! Cannot create file: " + oFile + '\n');
  }

  while(getline(myIFile, data, delimiter)) {

    myOFile << data;

    if (toupper(keepdelimiter) == 'Y') {
      myOFile << delimiter;
    }

    for (int i = 0; i < newlines; i++) {
      myOFile << '\n';
    }

  }

  myOFile.close();
  myIFile.close();

  return 0;
}