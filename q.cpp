/*!**************************************************************************************************************************************************************************************************************************************************************\file       q.hpp
\file       q.cpp
\par        Author:          Najih
\par        Email:           n.hajasheikallaudin
\par        Course:          RSE1202    
\par        Section:         RSE
\par        Tutorial:        Assignment 2
\par        File created on: 18/01/2024
\brief      Read data from file and decrypt the file based on keywords found

\par        File information:
            This file is contains 1 function definitions to called by main in q-driver.
            Functions:
            - void extract(char const *filename, char const **keyword);                                                       // reading data from file and identify the keywords found in the file and print the word next to the keyword 
                                                                                                                              // if the word next is also a keyword print that word and not the word after that
****************************************************************************************************************************************************************************************************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>                                                                                                            // required for GETLINE VERSION
#include <string>

using namespace std;                                                                                                          // using namespace std so that we dont need ot type std:: for functions include
const int MAX_WORDS = 1000;

namespace hlp2 {
//################################################################################################################################################################################################################################################################
  void extract(char const *filename, char const **keyword){
//================================================================================================================================================================================================================================================================
//|                                                                              READ FILE SECTION                                                                                                                                                               |
//================================================================================================================================================================================================================================================================
    ifstream inputfile;                                                                                                       // setting file to be opened for reading
    inputfile.open(filename);                                                                                                 // opening the file
    if (!inputfile.is_open()) {                                                                                               // check if the file can be opened
        cout << "File " << filename << " not found." << endl;                                                                 // print to error stream if file cannot be opend
        inputfile.close(); return;                                                                                            // closing the file if cannot be opened
    } 
//****************************************************************************************************************************************************************************************************************************************************************
  string word;  
  bool currentWordIsKeyword = false, prevWordIsKeyword = false, active = false;
//================================================================================================================================================================================================================================================================
//|                                                                        GET VERSION ( using .get() )                                                                                                                                                          |
//================================================================================================================================================================================================================================================================

  int word_count=0; char character;
  string wordarray[MAX_WORDS];                                                                                                // allocating storage for words in file

  while (inputfile.get(character)){                                                                                           // getting each character from file
    if (character != ' ' && character != '\n' ) { word +=character;}                                                          // if the character is not ' ' or '\n' add to word to form a word 
    else{wordarray[word_count++] = word; word.clear();}                                                                       // if character is ' ' or '\n' then store the formed word to wordarray and clear string variable word
  }

  for (int i=0; i<word_count; i++){
    currentWordIsKeyword = false;                                                                                             // to check if the current word is a keyword
    for (int j = 0; keyword[j] != nullptr; j++) {
      if (wordarray[i] == keyword[j]) {                                                                                       // checking if any words stored in wordarray are keyword
        currentWordIsKeyword = true;                                                                                          // if a keyword is found then update flag currentWordIsKeyword = true and leave loop
        break;
      }
    }
    if (prevWordIsKeyword && currentWordIsKeyword){ cout << wordarray[i] << ' '; currentWordIsKeyword = false; active=true; } // if the previous word was a keyword and the current word is a keyword print  current word and set currentWordIsKeyword = false
    else if (prevWordIsKeyword && !currentWordIsKeyword && active == false) { cout << wordarray[i] << ' '; }                  // if the previous word was a keyword and the current word is not  print the current word
    prevWordIsKeyword = currentWordIsKeyword; active = false;                                                                 // update the flag for the next iteration
  }
  cout << "\n"; inputfile.close();
  
//================================================================================================================================================================================================================================================================
//|                                                                   GETLINE VERSION ( using .getline() )                                                                                                                                                       |
//================================================================================================================================================================================================================================================================
/*
  string line;
  while (getline(inputfile, line)) {                                                                                          // read line by line from the file
    istringstream string(line);

    while (string >> word) {                                                                                                  // process each word in the line
      currentWordIsKeyword = false;                                                                                           // to check if the current word is a keyword
      for (int i = 0; keyword[i] != nullptr; i++) {
        if (word == keyword[i]) {                                                                                             // checking if any words stored in wordarray are keyword
          currentWordIsKeyword = true;                                                                                        // if a keyword is found then update flag currentWordIsKeyword = true and leave loop
          break;
        }
      }
      if (prevWordIsKeyword && currentWordIsKeyword){ cout << word << ' '; currentWordIsKeyword = false; active=true; }       // if the previous word was a keyword and the current word is a keyword print the current word and set currentWordIsKeyword = false
      else if (prevWordIsKeyword && !currentWordIsKeyword && active == false) { cout << word << ' '; }                        // If the previous word was a keyword and the current word is not print the current word
      prevWordIsKeyword = currentWordIsKeyword; active = false;                                                               // update the flag for the next iteration
    }  
  }
  cout << "\n"; inputfile.close();                                                                                            // Write a newline to standard output stream after processing each line // Close the file stream              
*/
  }
//################################################################################################################################################################################################################################################################
}
