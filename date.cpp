//---------------------------------------------------------
// Fichier        : date.cpp
// Auteur(s)      : Nathan Rayburn - Leonard Klassen
// Date           : 06 / 11 / 2022
// But            : This file is designed to create a yearly calendar
// Compilateur    : Mingw-w64
//---------------------------------------------------------

#include <string>
#include "date.h"
using namespace std;



//Init
int dayDateIndex(int year);
string getMonthByIndex(int monthNumber);

/*
 * This function is designed to get the number of days of a month
 * Return type int
*/
int numberOfDays (int monthIndex, int year)
{
    bool leap = (year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)); // Calculate leap year
    int numberOfDays;

    //Month Index should always have a case since months go from 0 to 11
    switch(monthIndex)
    {
        case 0 :
            numberOfDays = 31;
            break;
        case 1 :
            if (leap)
                numberOfDays = 29;
            else
                numberOfDays = 28;
            break;
        case 2 :
            numberOfDays = 31;
            break;
        case 3 :
            numberOfDays = 30;
            break;
        case 4 :
            numberOfDays = 31;
            break;
        case 5 :
            numberOfDays = 30;
            break;
        case 6 :
        case 7 :
            numberOfDays = 31;
            break;
        case 8 :
            numberOfDays = 30;
            break;
        case 9 :
            numberOfDays = 31;
            break;
        case 10 :
            numberOfDays = 30;
            break;
        case 11 :
            numberOfDays = 31;
            break;
    }
    return numberOfDays;
}

/*
 * This function is designed to create year
 * Return type string
 */
string getYear(int year)
{
    string yearCalendar;
    int daysInMonth;

    // Title of the calendar
    yearCalendar += "  Calendrier " + to_string(year) + "\n" "----------------------";

    // get the start of point of the first month of the year
    int dayToStartMonth = dayDateIndex(year);

    // Parse through each month of the year and create calendar (months 0 - 11)
    for (int month = 0; month < 12; month++)
    {


        // Display the month
        yearCalendar += "\n  " + getMonthByIndex (month) + " " + to_string(year) +"\n" ;

        // Display the header
        yearCalendar += "  L  M  M  J  V  S  D\n";


        int indexDay; // ( Current day Counter )

        daysInMonth = numberOfDays (month, year);

        // Create the right amount of spaces for the start off point of the month
        for (indexDay = 0; indexDay < dayToStartMonth; indexDay++){yearCalendar += "   ";}

        // Parse through each day of the month
        for (int day = 1; day <= daysInMonth; day++)
        {
            // Create spaces according to single-digits or double-digits

            if(day <= 9)
            {
                yearCalendar += "  ";             // 2 spaces for single-digits

            }else{
                yearCalendar += " ";             // 1 for double-digits

            }


            yearCalendar += to_string(day); // Add day
            indexDay ++;                        // Update index

            // every 7 days add a return to line
            if (indexDay >= 7)
            {
                indexDay = 0;
                yearCalendar += "\n";
            }

        }

        // avoiding adding double returns at the end of the month if a return has already been added
        // due to the last day being the end of the last week ( \n is automatically added every 7 days )
       if (indexDay){yearCalendar += "\n";}

        dayToStartMonth = indexDay;
    }
    return yearCalendar;
}
/* This function is designed to get a months name by index
 * Return type string
 */
string getMonthByIndex(int monthNumber)
{
    static string monthsInYear[] = {"Janiver", "Fevrier", "Mars","Avril", "Mai", "Juin",
                       "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};

    return (monthsInYear[monthNumber]);
}
/* This function is designed to return the index
 * day of the week for the first month of the year
 * Return type int
  */
int dayDateIndex(int year)
{
    // Only need to know when the first day of the first month starts
    const int MONTH = 1;
    const int DAY = 1;
    // calculate day date reference -- > https://artofmemory.com/blog/how-to-calculate-the-day-of-the-week/
    // Code example reference       -- >
    // https://www.codespeedy.com/how-to-find-day-from-date-in-cpp/#:~:text=(d%2Bm%2By%2B%5B,stands%20for%20the%20century%20number.
    //
    /*
     * January = 0
     * February = 3
     * March = 3
     * April = 6
     * May = 1
     * June = 4
     * July = 6
     * August = 2
     * September = 5
     * October = 0
     * November = 3
     * December = 5
    */
    int monthCode[] = { 0, 3, 3, 6, 1, 4, 6, 2,5, 0, 3, 5 };
    year -= MONTH < 3;

    /*
     * Calculate which day corresponds to which date (Monday, Tuesday etc..) by year and month
     * The original formula:
     * (Year Code + Month Code + Century Code + Date Number - Leap Year Code) mod 7
     * Formula returns an index and corresponds to a day
     * 0         Sunday
     * 1         Monday
     * 2         Tuesday
     * 3         Wednesday
     * 4         Thursday
     * 5         Friday
     * 6         Saturday
    */
    int startingDay = ( year + monthCode[MONTH-1] + year/4 + year/400 + DAY  - year/100) % 7;

    /* Convert the index order
     * 0         Monday
     * 1         Tuesday
     * 2         Wednesday
     * 3         Thursday
     * 4         Friday
     * 5         Saturday
     * 6         Sunday
     */
    if(startingDay == 0)
    {
        startingDay = 6;
    }else{
        startingDay --;
    }

    return startingDay;
}
