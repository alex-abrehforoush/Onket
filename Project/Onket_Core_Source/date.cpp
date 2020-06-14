#include "date.h"

void Date:: setYear(int year)
{
    if(year<=0)
        return;
   else if(year<100)
    {
        year+=2000;
        this->year=year;
        return;
    }
    else if(year>100 && year<200)
       {
         this->year=year+1900;
        }
    else
    {
        this->year=year;
        return;
    }
}


void Date::setMonth(int month)
{
    if(month<12 && month>0)
        this->month=month;
    return;
}

void Date:: setDay(int day)
{
    if(day>0)
        this->day=day;
    return;
}

void Date:: setHour(int hour)
{
    if(hour<24&& hour>=0)
        this->hour=hour;
    return;
}

void Date::setMinute(int minute)
{
    if(minute>=0 && minute<60)
        this->minute=minute;
}


Date::Date(int year,int month,int day,int hour,int minute)

{
   this->setYear(year);
    this->setMonth(month);
     this->setDay(day);
     this->setHour(hour);
     this->setMinute(minute);

}

void Date:: goToCurrentDate()
{
   this->setYear(localtime(& now)->tm_year);
    this->setMonth(localtime(& now)->tm_mon);
    this->setDay(localtime(& now)->tm_mday);
    this->setHour(localtime(& now)->tm_hour);
    this->setMinute(localtime(& now)->tm_min);



}

QString Date:: toString()
{


    char date[40];
    QString res;
    sprintf(date,"date:\t%d/%d/%d\ttime:\t%d:%d",year,month,day,    hour,minute);
    res=date;
    return res;


}

Date Date:: operator= (const Date& rvalue)
{
    this->year=rvalue.year;
    this->month=rvalue.month;
    this->day=rvalue.day;
    this->hour=rvalue.hour;
    this->minute=rvalue.minute;

    return rvalue;

}


bool Date:: operator==(const Date &rvalue)const
{
    if(this->year==rvalue.year && this->month==rvalue.month && this->day==rvalue.day && this->hour==rvalue.hour && this->minute==rvalue.minute)
        return true;
    else
        return false;
}

bool Date:: operator!=(const Date &rvalue)const
{
    return !(*this == rvalue);
}


 bool Date:: isBeforThan(const Date& rvalue)const
 {
     if(this->year<rvalue.year)
         return true;
     else if(this->year>rvalue.year)
         return false;
     else
     {
         if(this->month<rvalue.month)
             return true;
         else if(this->month>rvalue.month)
             return false;
         else
         {
             if(this->day<rvalue.day)
                 return true;
             else if(this->day>rvalue.day)
                 return false;
             else
             {
                 if(this->hour<rvalue.hour)
                     return true;
                 else if(this->hour>rvalue.hour)
                     return false;
                 else
                 {
                     if(this->minute<rvalue.minute)
                         return true;
                     else if(this->minute>rvalue.minute)
                         return false;
                     else
                         return false;
                 }
             }
         }
     }


 }

  bool Date:: isAfterThan(const Date& rvalue)const
  {
      return rvalue.isBeforThan(*this);
  }

