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
int dayDateIndex(int month, int day, int year);
string getMonthByIndex(int monthNumber);

/*
 * This function is designed to get the number of days of a month
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
 * This function is designed to create year and return it by string
 */
string getYear(int year)
{
    string yearCalendar;
    int daysInMonth;

    // Title of the calendar
    yearCalendar += "  Calendrier " + to_string(year) + "\n"
                                                        "----------------------";


    // Get the date of the first day of the year
    int dayToStartMonth = dayDateIndex (1, 1, year);

    // Create calendar for each month (months 0 - 11)
    for (int month = 0; month < 12; month++)
    {


        // Display the month
        yearCalendar += "\n  " + getMonthByIndex (month) + " " + to_string(year) +"\n" ;

        // Display the header
        yearCalendar += "  L  M  M  J  V  S  D\n";


        int indexDay;

        daysInMonth = numberOfDays (month, year);

        // Create the right amount of spaces for the start off point of the month
        for (indexDay = 0; indexDay < dayToStartMonth; indexDay++){yearCalendar += "   ";}

        for (int day = 1; day <= daysInMonth; day++)
        {
            // Create spaces according to single-digits or double-digits

            if(day <= 9)
            {
                yearCalendar += "  ";             // Number of spaces for single-digits

            }else{
                yearCalendar += " ";             // Number of spaces for double-digits

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
/*
 * This function is designed to get a months name by index
 */
string getMonthByIndex(int monthNumber)
{
    static string monthsInYear[] = {"Janiver", "Fevrier", "Mars","Avril", "Mai", "Juin",
                       "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};

    return (monthsInYear[monthNumber]);
}
/* This function is designed to return the index
 * day of the week for the first month of the year
 *
  */
int dayDateIndex(int month,int day, int year)
{
    //calculate day date reference -- > https://artofmemory.com/blog/how-to-calculate-the-day-of-the-week/
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
    int startDaysOfEachMonth[] = { 0, 3, 3, 6, 1, 4, 6, 2,5, 0, 3, 5 };
    year --; // year before current calendar

    /*
     * Calculate which day corresponds to which date (Monday, Tuesday etc..) by year and month
     * The original formula:
     * (Year Code + Month Code + Century Code + Date Number - Leap Year Code) mod 7
     * Formula returns a index and corresponds to a day
     * 0         Sunday
     * 1         Monday
     * 2         Tuesday
     * 3         Wednesday
     * 4         Thursday
     * 5         Friday
     * 6         Saturday
    */
    int startingDay = ( year + year/4 + year/400 + day + startDaysOfEachMonth[month-1] - year/100) % 7;
    
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
