/*

    @Author: Kathryn Jenner
    @Date: 1/22/2023
    @Clocks.cpp is designed to display a "time" in both 24 hour and 12 hour time. The clock starts at 1:22:01 pm and hours, minutes and seconds can
     be added to it. The time does not "tick" and will only move with user input.


*/

#include <iostream>
#include <iomanip>

using namespace std;

int hour = 13;  // global hour variable
int minute = 22;    //global minute variable
int second = 1;     //global second variable


//adds an hour to the global hour variable. Sets back to zero if hour would be 24
void addHour() {
    hour++;

    if (hour > 23) {
        hour = 0;
    }
}

//adds a minute to the global minute variable. If minutes would become 60 sets minutes to 0 and adds one to hour.
void addMinute() {
    minute++;

    if (minute > 59) {
        minute = 0;
        addHour();
    }
}

//adds a second to the global second variable. If seconds would become 60 sets seconds to 0 and adds one to minute.
void addSecond() {
    second++;

    if (second > 59) {
        second = 0;
        addMinute();
    }
}

 //displays time in the 12 hour format.
void display12Hour() {

    //AM time display
    if (hour < 13 && hour == 0) {
        cout << setfill('0') << setw(2) << hour+12 << ":" << setw(2) << minute << ":" << setw(2) << second;
        cout << "AM";
    }

    //Fixes issue where 12 would be displayed as 0
    else if (hour < 12) {
        cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
        cout << "AM";
    }

    //PM time display
    else if (hour == 12) {
        cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
        cout << "PM";
    }

    //Fixes issue wher 12 would be displayed as 0
    else {
        cout << setfill('0') << setw(2) << hour-12 << ":" << setw(2) << minute << ":" << setw(2) << second;
        cout << "PM";
    }
}

//Displays time in 24 hour format
void display24Hour() {
    cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
}


//Text formatting for the "clocks" the time display is done by a different function
// -> see display24Hour() and display12Hour() for more information
void displayTime() {
    cout << setfill('*') << setw(25) << "" << "     " << setw(25) << "" << endl;
    cout << setfill(' ') << "*" << setw(5) << "" << "12-Hour Clock" << setw(5) << "" << "*     ";
    cout << setfill(' ') << "*" << setw(5) << "" << "24-Hour Clock" << setw(5) << "" << "*"<<endl;
    cout << setfill(' ') << "*" << setw(6) << "";
    display12Hour();
    cout << setfill(' ')<< setw(7) << "" << "*     *"<<setw(7)<<"";
    display24Hour();
    cout << setfill(' ') << setw(8) << "" <<"*" << endl;


    cout << setfill('*') << setw(25) << "" << "     " << setw(25) << "" << endl;
   
}


//Text formatting for the menu
void displayMenu() {
    cout << setfill('*') << setw(25) << ""<< endl;
    cout << "* 1 - Add One Hour " << setfill(' ') << setw(6) << "*" << endl;
    cout << "* 2 - Add One Minute " << setfill(' ') << setw(4) << "*" << endl;
    cout << "* 3 - Add One Second " << setfill(' ') << setw(4) << "*" << endl;
    cout << "* 4 - Exit Program " << setfill(' ') << setw(6) << "*" << endl;
    cout << setfill('*') << setw(25) << ""<< endl;
}





int main()
{
    int userAns = 0; //user input

    while (userAns != 4) { //main loop runs program until 4 is typed loop ends

        system("cls"); // clears console after each display
        displayTime();  //display clocks
        displayMenu();  //display menu
     

        if (userAns == 1) //if one is typed add an hour
            addHour();

        else if (userAns == 2) //if two is typed add a minute
            addMinute();

        else if (userAns == 3) //if three is typed ad a second
            addSecond();

        cin >> userAns;


    }

   
}

