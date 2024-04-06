/*!**************************************************************************************************************************************************************************************************************************************************************
\file       q.hpp
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
            - void extract(char const *filename, char const **keyword);                                                       // dreading data from file and identify the keywords found in the file and print the word next to the keyword 
                                                                                                                              // if the word next is also a keyword print that word and not the word after that
****************************************************************************************************************************************************************************************************************************************************************/
#ifndef Q_HPP_
#define Q_HPP_
namespace hlp2 { void extract(char const *filename, char const **keywords); }
#endif
