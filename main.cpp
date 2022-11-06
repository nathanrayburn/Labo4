//---------------------------------------------------------
// Fichier        : main.cpp
// Auteur(s)      : Nathan Rayburn - Leonard Klassen
// Date           : 06 / 11 / 2022
// But            : This program is designed to get the yearly calendar
//                  from the years between 1800 and 2100 by using our custom library date
// Compilateur    : Mingw-w64
//---------------------------------------------------------

#include <iostream>
#include <limits>
#include "date.h"
#include "iomanip"
using namespace std;

int main() {

    // init
    const int YEAR_MIN = 1800;
    const int YEAR_MAX = 2100;
          int userYear;
          string calendar;

    // user input for year
    do{

        cout << "Veuillez saisir une date [1800 - 2100]\n";
        cin >> userYear;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }while(userYear < YEAR_MIN or userYear > YEAR_MAX);


    calendar = getYear(userYear);        // get the calendar
    cout << left << setw(1) << calendar;  // display the calendar
    return 0;
}
