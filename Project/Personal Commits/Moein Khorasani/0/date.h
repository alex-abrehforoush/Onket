#ifndef DATE_H
#define DATE_H

#include <QString>

#include <time.h>
#include <iostream>
#include <string>

using namespace  std;

class Date
{

    int year=2020;
    int month=1;
    int day=1;
    int hour=0;
    int minute=0;
   time_t now=time(NULL);
public:


   int getYear()const{return this->year;}
   int getMonth()const{return this->month;}
   int getDay()const{return this->day;}
   int getHour()const{return this->hour;}
   int getMinute()const{return this->minute;}


   void setYear(int year);
 void setMonth(int month);
 void setDay(int day);
 void setHour(int hour);
 void setMinute(int minute);


    Date(int year=2020,int month=1,int day=1,int hour=0,int minute=0);
     void goToCurrentDate();


   QString toString();

    Date operator= (const Date& rvalue);
    bool operator== (const Date& rvalue)const;
    bool operator!= (const Date& rvalue)const;
    bool isBeforThan(const Date& rvalue)const;
    bool isAfterThan(const Date& rvalue)const;

    bool operator> (const Date& rvalue)const{return this->isAfterThan(rvalue);}
      bool operator< (const Date& rvalue)const{return this->isBeforThan(rvalue);}
      bool operator>= (const Date& rvalue)const{return (*this>rvalue || *this==rvalue);}
        bool operator<= (const Date& rvalue)const{return (*this<rvalue || *this==rvalue);}


};

#endif // DATE_H
