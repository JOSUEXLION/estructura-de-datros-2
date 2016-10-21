/*
INTEGRANTES:

Richard Hearn 8-906-1268
Michael Abril CC-1116-263511
Osmar Berrocal 8-808-957
Alberto Juarez 8-853-1956

*/


#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "Date.h"

using namespace std;

Date:: Date(void) : // constructor por default 
	month(0), day(0), year(0), hour(0), minute(0), second(0){}

Date::Date (int month, int day, int year, int hour, int minute, int second) : // constructor con parametros 
	month(month), day(day), year(year), 
	hour(hour), minute(minute), second(second) {}
//accesors 
void Date::setMonth(int& month) {
	this->month = month;
}

void Date::setDay(int& day) {
	this->day = day;
}

void Date::setYear(int& year) {
	this->year = year;
}

void Date::setHour(int& hour) {
	this->hour = hour;
}

void Date::setMinute(int& minute) {
	this->minute = minute;
}

void Date::setSecond(int& second) {
	this->second = second;
}
	//mutators 
int Date::getMonth(void) const {
	return month;   
}

int Date::getDay(void) const {
	return day;   
}	    

int Date::getYear(void) const {
	return year;   
}

int Date::getHour(void) const {
	return hour;   
}

int Date::getMinute(void) const {
	return minute;   
}	    

int Date::getSecond(void) const {
	return second;   
}	    
// operator == (comparacion de dos  objetos)
bool Date::operator== (const Date &rhs) {

	if ( (this->getMonth() != rhs.getMonth()) ||
       (this->getDay() != rhs.getDay()) ||
       (this->getYear() != rhs.getYear()) ||
	   (this->getHour() != rhs.getHour()) ||
	   (this->getMinute() != rhs.getMinute()) ||
	   (this->getSecond() != rhs.getSecond()) 
	   ) {

		return false;
	}
	else {
		return true;
	}
}
// operator < (compara si un objeto es menor que otro)
bool Date::operator< (const Date &rhs) {

  if (this->getYear() != rhs.getYear()) {
    if (this->getYear() < rhs.getYear()) 
      return true;
    else
      return false;
  } 

  if (this->getMonth() != rhs.getMonth()) {
    if (this->getMonth() < rhs.getMonth()) 
      return true;
    else
      return false;
  } 

  if (this->getDay() != rhs.getDay()) {
    if (this->getDay() < rhs.getDay()) 
      return true;
    else
      return false;
  } 

  if (this->getHour() != rhs.getHour()) {
    if (this->getHour() < rhs.getHour()) 
      return true;
    else
      return false;
  } 

  if (this->getMinute() != rhs.getMinute()) {
    if (this->getMinute() < rhs.getMinute()) 
      return true;
    else
      return false;
  } 

  if (this->getSecond() < rhs.getSecond()) {
      return true;
  }
  else {
      return false;
  } 

}
// &operator<<  
 ostream &operator<<(ostream &stream, const Date &d) {

  stream << d.getMonth() << "/" << d.getDay() << "/" << d.getYear();
  stream << " " << d.getHour() << ":" << d.getMinute() << ":" << d.getSecond();
  return stream;
}

//&operator>>

istream &operator>>(istream &stream, Date &d) {

  char buffer[10];
  
  stream.getline(buffer, 4, '/');
  int value = atoi (buffer);
  d.setMonth(value);

  stream.getline(buffer, 4, '/');
  value = atoi (buffer);
  d.setDay(value);

  stream.getline(buffer, 6, ' ');
  value = atoi (buffer);
  d.setYear(value);

  stream.getline(buffer, 4, ':');
  value = atoi (buffer);
  d.setHour(value);

  stream.getline(buffer, 4, ':');
  value = atoi (buffer);
  d.setMinute(value);

  stream.getline(buffer, 4);
  value = atoi (buffer);
  d.setSecond(value);

  return stream;
}
