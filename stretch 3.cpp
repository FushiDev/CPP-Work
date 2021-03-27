#include<iostream>
using namespace std;


//stretch 3 - This is where I was before lab started - not done yet
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

int tomorrowDate(int month, int day, int year){
    int formatDate[3] = {month,day,year};
    if(day != lastDay(month, year)){
      formatDate[1] = (day+1);
      cout << "next day is " << formatDate[0] << " " << formatDate[1] << " " <<formatDate[2];
      return 0;
    }
    else if (day == lastDay(month,year) && month != 12) {
      formatDate[0] = (month + 1);
      formatDate[1] = 1;
      cout << "next day is " << formatDate[0] << " " << formatDate[1] << " " <<formatDate[2];
      return 0;
    }
    else if(day == lastDay(month,year) && month == 12){
        formatDate[0] = 1;
        formatDate[1] = 1;
        formatDate[2] = (year + 1);
        cout << "next day is " << formatDate[0] << " " << formatDate[1] << " " <<formatDate[2];
        return 0;
    }
}

//Perfect
int main() {
    char choice = 'y';
    while(choice == 'y'){
        cout << "enter a date as mm dd yyyy: ";
        int month, day, year;
        cin >> month >> day >> year;
        tomorrowDate(month, day, year);
        cout << endl;
        cout << "continue? (y/n): ";
        cin >> choice;

    }
}
