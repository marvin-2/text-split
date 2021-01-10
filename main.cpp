// Reads a text file and adds the specified number of newlines at the given delimiter

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#include "split.h"

using namespace std;

int main() {

  char option = ' ';

  cout << "\nText Split Program\n\n"  
       << "Options\n" 
       << "R - Remove Newlines\n" 
       << "S - Split by Separator\n"
       << "X - Exit\n";


  while (toupper(option) != 'X') {

    cout << "\nSelect an option: ";
    cin >> option;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid option. Try again.\n";

    } else if (toupper(option) == 'R') {
      removenewlines("two.txt", "removenewlines.txt");
      cout << "Output file removenewlines.txt created.\n";

    } else if (toupper(option) == 'S') {
      split("one.txt", "splitseparator.txt", '~', 1, 'Y');
      cout << "Output file splitseparator.txt created.\n";

    } else if (toupper(option) == 'X') {
      cout << "Bye!\n";

    } else {
      cout << "Invalid option. Try again.\n";
    }

  }

  //// Error handling
  // try {
  //   split("one.txt", "splitseparator.txt", '~', 1, 'Y');
  // } catch (const runtime_error& e) {
  //   cout << e.what();
  //   throw e;
  // }

  return 0;
}