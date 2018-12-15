// -*- mode: c++; tab-width: 4 -*-
// File: main.cpp---------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 1

#include "tools.hpp"

void run();

int main() {
    banner();
    run();
    bye();
}

// Prompts the user to enter their first name, last name and year of birth.
// Prints out the first name, last name, and age.
void run() {
    string firstname, lastname;
    int birthyear, age;

    cout << "Please enter your first name: ";
    cin >> firstname;
    if (!cin.good()) fatal("Error reading first name. Exiting..."); 

    cout << "Please enter your last name: ";
    cin >> lastname;
    if (!cin.good()) fatal("Error reading last name. Exiting...");

    cout << "Please enter the year of your birth: ";
    cin >> birthyear;
    if (!cin.good()) fatal("Error reading birth year. Exiting...");

    const time_t rawtime = time( nullptr );
    struct tm* timeinfo = localtime( &rawtime );
    const int thisyear = 1900 + timeinfo->tm_year;
    age = thisyear - birthyear;

    cout << firstname << " " << lastname << " becomes " << age 
         << " years old in 2018.";
}

