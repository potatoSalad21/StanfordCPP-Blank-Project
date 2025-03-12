/*
 * File: simpio.cpp
 * ----------------
 * This file implements the simpio.h interface.
 */

#include "simpio.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
 * Implementation notes: getInteger, getReal
 * -----------------------------------------
 * Each of these functions reads a complete input line and then uses the
 * <sstream> library to parse that line into a value of the desired type.
 * If that fails, the implementation asks the user for a new value.
 */

int getInteger(string prompt) {
  int value;
  string line;
  while (true) {
    cout << prompt;
    getline(cin, line);
    // Trim leading/trailing whitespace and newlines
    line.erase(0, line.find_first_not_of(" \n\r\t")); // Trim leading
    line.erase(line.find_last_not_of(" \n\r\t") + 1); // Trim trailing
    istringstream stream(line);
    stream >> value;
    if (!stream.fail() && stream.eof())
      break; // Check if fully consumed
    cout << "Illegal integer format. Try again." << endl;
    if (prompt == "")
      prompt = "Enter an integer: ";
  }
  return value;
}
double getReal(string prompt) {
  double value;
  string line;
  while (true) {
    cout << prompt;
    getline(cin, line);

    line.erase(0, line.find_first_not_of(" \n\r\t"));
    line.erase(line.find_last_not_of(" \n\r\t") + 1);

    if (line.empty()) {
      continue;
    }

    istringstream stream(line);
    if (stream >> value) {
      char leftover;
      if (!(stream >> leftover)) {
        return value;
      }
    }

    cout << "Illegal numeric format. Try again." << endl;
    if (prompt.empty())
      prompt = "Enter a number: ";
  }
}

/*
 * Implementation notes: getLine
 * -----------------------------
 * The getLine function simply combines the process of displaying a
 * prompt and reading an input line into a single call.  The primary
 * reason for including this function in the library is to ensure
 * that the process of reading integers, floating-point numbers, and
 * strings remains as consistent as possible.
 */

string getLine(string prompt) {
  string line;
  cout << prompt;
  getline(cin, line);
  return line;
}
