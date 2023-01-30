#include <iostream>
#include <string.h>
using namespace std;

class Date{

        int day, month, year;

        // Returns the no. of days in the provided month by also considering leap year
        int daysInMonth(int month,int year){
                int days = 31;
                switch(month){
                        case 2 : if(year%4 == 0) // if the year is leap
                                         days = 29; // return 29
                                 else
                                         days = 28; // Otherwise return 28
                                break;
                        case 4:
                        case 6:
                        case 9:
                        case 11: days = 30; // For any of these months return 30
                                 break;

                }
return days;
}
  public:
                Date():day(1),month(1),year(2000){} // If no arguments are given initialized to 1/1/2000

                Date(int d, int m, int y):day(d),month(m),year(y){}

                // Returns the string of the date
                string toString(){
                        return to_string(day)+"/"+to_string(month)+"/"+to_string(year);
                }

void operator ++(int){
                        // If the current day is the last day in the current month
                        if(day == daysInMonth(month,year)){
                                // Set day to 1st
                                day = 1;

                                // Check whether this is the last month or not
                                if(month == 12)
                                {
                                        // if it is the last month reset month to 1 and increment year
                                        month = 1;
                                        year++;
                                }else
                                {
                                        // If not just increment the month
                                        month++;
                                }
                        }else
                        {
                                // Otherwise just increment the day
                                day++;
                        }
                }


};


int main()
{
        system("clear");

        Date d1;
        int d, m, y;

        cout<<"Enter the date \nday : ";
        cin>>d;
        cout<<"month : ";
        cin>>m;
        cout<<"year : ";
        cin>>y;

        d1 = Date(d,m,y);

        cout<<"Before increment => "<<d1.toString()<<endl;
        d1++;

        cout<<"After increment => "<<d1.toString()<<endl;

        return 0;
}
