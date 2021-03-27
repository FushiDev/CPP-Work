#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


bool isLeapYear(int year){
    if(year % 4 == 0 && year % 100 != 0){
        return true;
    }
    else if (year % 4 == 0 && year % 100 == 0){
        if (year % 400 != 0){

            return false;
        }
        else if(year % 400 == 0){
            return true;
        }
    }
    else if(year % 4 != 0) {
        return false;
    }
}

int lastDay(int month, int year){
    int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month <= 0 && month >= 13){
        return 0;
    }
    if (isLeapYear(year) == 1 && month == 2){
        return 29;
    }
    else{
        return months[month - 1];
    }

}




int main(){

    string nameArray[30]; //list of names
    int dateArray[30][3] = {0}; //list of birthday. [num][month/day/year]
    int cnt = 0;

    string name; //you can guess what these are.
    int day;
    int month;
    int year;

    ifstream BirthdayFile;
    BirthdayFile.open("birthdays.txt");


    while(!BirthdayFile.fail()){
        BirthdayFile >> name; //>> month >> temp >> day >> temp >> year;
        BirthdayFile >> month;
        BirthdayFile.get();
        BirthdayFile >> day;
        BirthdayFile.get();
        BirthdayFile >> year;
        nameArray[cnt] = name;
        dateArray[cnt][0] = month;
        dateArray[cnt][1] = day;
        dateArray[cnt][2] = year;
        cnt += 1;
    }






    /*
    for(int i = 0; i < cnt-1; ++i){
        cout << nameArray[i] << endl;     //These are just to quickly print out the names and dates.Not necessary for it to work, just bug checks.
    }
    for(int i = 0; i < cnt-1; ++i){
        cout << dateArray[i][2] << endl;
    }
    */

    cout << "Current date?" << endl;
    int m, d, y;
    cin >> m;
    cin.get();
    cin >> d;
    cin.get();
    cin >> y;



    if(!BirthdayFile.is_open()){
        cout << "No file detected!" << endl;
        return 1;
    }

    BirthdayFile.close();

    //Everything From This Point Down is to check when the next birthday is.

    int ClosestPerson = 0;
    int closestDaysAway = 365;

    for(int i = 0; i < 30; ++i){


        int daysAway = 365;

        if(m == dateArray[i][0] && (dateArray[i][1] - d) >= 0){ //If Current month matches birthday month
            daysAway = (dateArray[i][1] - d);
            }

        if(m < dateArray[i][0] && dateArray[i][0] != 0){ //if current month is before birthday month
            daysAway = lastDay(m,y) - d;
            for(int x = m+1; x < dateArray[i][0]; ++x){
                daysAway += lastDay(x,y);
            }
            daysAway += dateArray[i][1];
        }


        if(m > dateArray[i][0] && dateArray[i][0] != 0){ //if current month is after birthday month
            daysAway = lastDay(m,y);
            for(int x = m+1; x < (dateArray[i][0] - m + 12); ++x){
                daysAway += lastDay(x,y);
            }
            daysAway += dateArray[i][1];

        }



        if (daysAway < closestDaysAway){
            closestDaysAway = daysAway;
            ClosestPerson = i;
            }

    }

    int age = 0;
    cout << "Next birthday:" << endl << nameArray[ClosestPerson] << endl << "in " << closestDaysAway << " days" << endl << "will turn "<< y - dateArray[ClosestPerson][2] << endl;






























}
