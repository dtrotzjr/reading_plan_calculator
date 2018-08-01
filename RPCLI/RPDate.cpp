/***************************************************************************
    RPDate.cpp  -  IMplementation for RPDate class
                             -------------------
    begin                   : Sat Mar 24 19:15:31 PST 2001
    copyright               : (C) 2001-2005 by David Trotz Jr
                            :   Original date class (C) Copyright 2001 under
                                Peter Chapin
                                P.O. Box 317
                                Randolph Center, VT 05061
                                pchapin@sover.net

    email                   : dtrotzjr@readingplanner.com
 ***************************************************************************/

/****************************************************************************
*                                                                           *
*        This file is part of ReadingPlanner                                *
*                                                                           *
*    ReadingPlanner is free software; you can redistribute it and/or modify *
*    it under the terms of the GNU General Public License as published by   *
*    the Free Software Foundation; either version 2 of the License, or      *
*    (at your option) any later version.                                    *
*                                                                           *
*    ReadingPlanner is distributed in the hope that it will be useful,      *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of         *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
*    GNU General Public License for more details.                           *
*                                                                           *
*    You should have received a copy of the GNU General Public License      *
*    along with ReadingPlanner; if not, write to the Free Software          *
*    Foundation, Inc.                                                       *
*        59 Temple Place, Suite 330,                                        *
*        Boston, MA  02111-1307  USA                                        *
*                                                                           *
*                                                                           *
****************************************************************************/
/****************************************************************************
This file defines a simple RPDate abstract data type. RPDate objects will
handle RPDates between Jan 1, 1800 and Dec 31, 2099. Any attempt to set a
RPDate object outside that range, either directly or by way of a
computation, will have undefined effects.

The interface to RPDate objects uses 1-based numbering: January is month
1, February is month 2, and so on. Furthermore, the first day of the
month is day 1. Years must be full, four digit years.


REVISION HISTORY

+ Dec 21, 2001: Cosmetic adjustments. Someday it might be nice to make this
  into a really useful class. For now it makes a good demonstration of the
  basics of classes and information hiding.

+ Mar 21, 1999: First official release.

+ Sept 2003: Revised by David Trotz for ReadingPlanner changed name to RPDate

****************************************************************************/

#include "RPDate.h"
#include <stdio.h>

  //---------------------------------------------
  //           Private Member Functions
  //---------------------------------------------

  //
  // RPDate::is_leap() const
  //
  // This function returns true if the year is a leap year.
  //
  bool RPDate::isLeap() const
  {
    bool result = false;

    if (           (m_nYear %   4 == 0)) result = true;
    if ( result && (m_nYear % 100 == 0)) result = false;
    if (!result && (m_nYear % 400 == 0)) result = true;

    return result;
  }


  //
  // RPDate::month_length() const
  //
  // This function returns the number of days in the current month.
  //
  int RPDate::monthLength() const
  {
    // Lookup table gives number of days in each month.
	static const int month_lengths[] = {
      31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

	int length = month_lengths[m_nMonth - 1];

    // Now perhaps make a correction if the month is Feb.
	if (m_nMonth == 2 && isLeap()) length++;

    return length;
  }


  //
  // RPDate::next()
  //
  // This function has to deal with the fact that the number of days in
  // each month is different. Furthermore, the number of days in Feb is
  // a function of the year.
  //
  void RPDate::nextDate()
  {
    // Try incrememting the day. If it overflows the month, make a correction.
	if (++m_nDay > monthLength()) {
      m_nDay = 1;
      if (++m_nMonth > 12) {
        m_nMonth = 1;
        ++m_nYear;
      }
    }
  }


  //
  // RPDate::previous()
  //
  // This function works similarly to RPDate::next().
  //
  void RPDate::previousDate()
  {
    int fix_day = 0;

    // Try decrementing the day.
    if (--m_nDay < 1) {
      fix_day = true;
      if (--m_nMonth < 1) {
        m_nMonth = 12;
        --m_nYear;
      }
    }

    // If we wrapped over a month boundary, set the day to the last day
    // of the new (and now current) month.
    //   
	if (fix_day) m_nDay = monthLength();
  }


  //--------------------------------------------
  //           Public Member Functions
  //--------------------------------------------

  //
  // RPDate::set(int, int, int)
  //
  // This function initializes the date to values given to us by the
  // client. We don't trust the client to give us sensible values.
  //
  void RPDate::setDate(int day, int month, int year)
  {
    m_nDay = day; m_nMonth = month; m_nYear = year;

    // If we get a year < 100 it probably means the client is giving us
    // just a two digit year. We will take any two digit year below 50
    // to mean 2000 to 2050. This hack will help make this Date class
    // well behaved even when two digit years are used (by silly
    // people).
    //
    if (m_nYear < 100) {
      if (m_nYear < 50) m_nYear += 2000;
      else m_nYear += 1900;
    }

    // Year check. If the client gives us a year that's really far off,
    // it's probably an error. We'll deal with that by just artificially
    // restricting the year.

    if (m_nYear < 1800) m_nYear = 1800;
    if (m_nYear > 2099) m_nYear = 2099;

    // Month Check. It would be cooler to advance the date appropriately
    // so that, for example, the 13th month would end up being the first
    // month of the next year. However, I don't see why we should make
    // excuses for the client's errors. The point of this is just to be
    // sure that our class doesn't get blamed for dumping core.

    if (m_nMonth <  1) m_nMonth =  1;
    if (m_nMonth > 12) m_nMonth = 12;

    // Day Check.

    if (m_nDay < 1 ) m_nDay = 1;
	if (m_nDay > monthLength()) m_nDay = monthLength();
  }

  //
  // RPDate::advance(long)
  //
  // This function advances (or backs up) a date by the specified number
  // of days. This implementation is highly inefficient although it will
  // come up with the right answer eventually.
  //
  void RPDate::advanceDate(long delta)
  {
    long count;

    // If delta == 0 we're done already.
    if (delta == 0) return;

    // If we're trying to step forward...
    if (delta >  0) {
	  for (count = delta; count > 0; count--) nextDate();
    }

    // We're trying to step backward... 
    else {
	  for (count = -delta; count > 0; count--) previousDate();
    }
  }


  //-----------------------------------------
  //           Non-Member Functions
  //-----------------------------------------

  //
  // operator==(const RPDate &, const RPDate &)
  //
  // Returns true if two dates are equal. This function does not need to
  // be a friend because it does not attempt to access the private
  // section of Date. It will continue to work even if the
  // implementation of Date is changed.
  //
  bool operator==(const RPDate &left, const RPDate &right)
  {
	if (left.getYear()  == right.getYear()  &&
		left.getMonth() == right.getMonth() &&
		left.getDay()   == right.getDay()     )
		return 1;

    return 0;
  }


  //
  // operator<(const RPDate &, const RPDate &)
  //
  // Returns true if the left operand is before the right operand.
  //
  bool operator<(const RPDate &left, const RPDate &right)
  {
	if (left.getYear() <  right.getYear()) return 1;
	if (left.getYear() == right.getYear()) {
	  if (left.getMonth() <  right.getMonth()) return 1;
	  if (left.getMonth() == right.getMonth()) {
        if (left.getDay() <  right.getDay()) return 1;
      }
    }
    return 0;
  }


  //
  // operator-(const RPDate &, const RPDate &)
  //
  // This function is also way slow. But it will come up with the right
  // answer.
  //
  long operator-(const RPDate &left, const RPDate &right)
  {
    long result = 0;

    // Handle the simple case first.
    if (left == right) return 0;

    // Make copies of the parameters that I can change.
    RPDate my_left  = left;
    RPDate my_right = right;

    // If my_right is small, advance it until it matches my_left.
    while (my_left > my_right) {
	  my_right.advanceDate(1);
      result++;
    }

    // If my_left is small, advance it until it matches my_right.
    while (my_right > my_left) {
	  my_left.advanceDate(1);
      result--;
    }

    return result;
  }

#ifdef __palmos__
  RPDate::operator DateType() const
  {
	DateType date; 
	date.year = getYear() - 1904;
	date.month = getMonth();
	date.day = getDay();
	return date;		
  }	
#endif // __palmos__

// ********	GLOBAL FUNCTIONS	******** //

int dayofweek(const RPDate& rhs)   /* 0=sunday, 1=monday, etc. */
{
   return dayofweek(rhs.getDay(),rhs.getMonth(), rhs.getYear());
}

string RPDate::getMonthString()
{
	string retVal;
	switch(m_nMonth)
    {
    case 1:
    	retVal = "January";
        break;
    case 2:
    	retVal = "February";
        break;
    case 3:
    	retVal = "March";
        break;
    case 4:
    	retVal = "April";
        break;
    case 5:
    	retVal = "May";
        break;
    case 6:
    	retVal = "June";
        break;
    case 7:
    	retVal = "July";
        break;
    case 8:
    	retVal = "August";
        break;
    case 9:
    	retVal = "September";
        break;
    case 10:
    	retVal = "October";
        break;
    case 11:
    	retVal = "November";
        break;
    case 12:
    	retVal = "December";
        break;
    default:
    	retVal = "";
    }
	return retVal;
}
string RPDate::getMonthAbbr()
{ 	
	string retVal;

	switch(m_nMonth)
    {
    case 1:
    	retVal = "Jan";
        break;
    case 2:
    	retVal = "Feb";
        break;
    case 3:
    	retVal = "Mar";
        break;
    case 4:
    	retVal = "Apr";
        break;
    case 5:
    	retVal = "May";
        break;
    case 6:
    	retVal = "Jun";
        break;
    case 7:
    	retVal = "Jul";
        break;
    case 8:
    	retVal = "Aug";
        break;
    case 9:
    	retVal = "Sep";
        break;
    case 10:
    	retVal = "Oct";
        break;
    case 11:
    	retVal = "Nov";
        break;
    case 12:
    	retVal = "Dec";
        break;
    default:
    	retVal = "";
    }
	return retVal;
}

string RPDate::getDayOfWeekString() const
{
  string retval;
  switch(dayofweek(*this))
  {
  case 0:
  	retval = "Sunday";
    break;
  case 1:
  	retval = "Monday";
    break;
  case 2:
  	retval = "Tuesday";
    break;
  case 3:
  	retval = "Wednesday";
    break;
  case 4:
  	retval = "Thursday";
    break;
  case 5:
  	retval = "Friday";
    break;
  case 6:
  	retval = "Saturday";
    break;
  }
	return retval;
}

string RPDate::getFullDateString()
{
  string retval;
  char buff[16];
	retval = getDayOfWeekString();
	retval += ", ";
  retval += getMonthString();
  // Check if we need a leading 0 for our date
  if(m_nDay < 10)
  	retval += " 0";
  else
  	retval +=" ";

  // Convert and append the day and the year

#ifndef __palmos__ 
  sprintf(buff, "%d", m_nDay);
  retval += buff;
  retval += ", ";
  sprintf(buff, "%d", m_nYear);
  retval += buff;
#endif // __palmos__

#ifdef __palmos__	// This section for PalmOS only.
  StrIToA(buff, m_nDay);
  retval += buff;
  retval += ", ";
  StrIToA(buff, m_nYear);
  retval += buff;
#endif // __palmos__

  return retval;

}

string RPDate::getFullAbbrDateString()
{
  string retval;
  char buff[16];
	retval = getDayOfWeekString();
	retval += ", ";
  retval += getMonthAbbr();
  // Check if we need a leading 0 for our date
  if(m_nDay < 10)
  	retval += " 0";
  else
  	retval +=" ";

  // Convert and append the day and the year

#ifndef __palmos__ 
  sprintf(buff, "%d", m_nDay);
  retval += buff;
  retval += ", ";
  sprintf(buff, "%d", m_nYear);
  retval += buff;
#endif // __palmos__

#ifdef __palmos__	// This section for PalmOS only.
  StrIToA(buff, m_nDay);
  retval += buff;
  retval += ", ";
  StrIToA(buff, m_nYear);
  retval += buff;
#endif // __palmos__

  return retval;

}

string RPDate::getFormalDateString()
{
  string retval = "";
  char buff[16];

#ifndef __palmos__
  if(m_nMonth < 10)
  	retval += "0";
  sprintf(buff, "%d", m_nMonth);
  retval += buff;
  retval += "/";
  if(m_nDay < 10)
  	retval += "0"; 
  sprintf(buff, "%d", m_nDay);
  retval += buff;
  retval += "/";
  sprintf(buff, "%d", m_nYear);
  retval += buff;
#endif // __palmos__

#ifdef __palmos__	// This section for PalmOS only.
  if(m_nMonth < 10)
  	retval += "0";
  StrIToA(buff, m_nMonth);
  retval += buff;
  retval += "/";
  if(m_nDay < 10)
  	retval += "0";
  StrIToA(buff, m_nDay);
  retval += buff;
  retval += "/";
  StrIToA(buff, m_nYear);
  retval += buff;
#endif // __palmos__

  return retval;

}

// Copyright Glenn Rhoads'
// Retrieved from:
// http://remus.rutgers.edu/~rhoads/Code/day_of_week.c

int dayofweek(int day, int month, int year)   /* 0=sunday, 1=monday, etc. */
{
   int a = (14-month) / 12;
   int y = year - a;
   int m = month + 12*a - 2;

   return (day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
}
