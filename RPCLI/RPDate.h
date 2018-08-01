/***************************************************************************
	RPDate.h  -  Interface for RPDate class
                             -------------------
	begin                	: Sat Mar 24 19:15:31 PST 2001
	copyright            	: (C) 2001-2005 by David Trotz Jr
							:	Original date class (C) Copyright 2001 under
								Peter Chapin
								P.O. Box 317
								Randolph Center, VT 05061
								pchapin@sover.net

	email                	: dtrotzjr@readingplanner.com
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
#ifndef RPDate_H
#define RPDate_H

#ifndef __palmos__
#include <string>
#include <stdlib.h>
using std::string;
#endif // __palmos__

#ifdef __palmos__
#include <DateTime.h>
#include "RPString.h"
#define string RPString
#endif // __palmos__

#ifdef _WX_WIN
#include <wx/wx.h>
#include <wx/datetime.h>
#endif // _WX_WIN
/*!RPDate is a date class which is able to deal with leap years. Written
   originally by Peter Chapin chapin@sover.net, it has since been revised to
   include features specific for the ReadingPlanner hence the new name RPDate.
*/
class RPDate {
public:
	/*! Default constructor. Defaults to Jan 1, 1970 */
	RPDate() { m_nDay = 1; m_nMonth = 1; m_nYear = 1970; }
	/*! Overloaded constructor.

		Note that the year should be a full four digits. This function also
		performs some sanity checks. It will force the m_nDay, m_nMonth, and m_nYear values into
		range.

		\param day is day of month.
		\param month is month in year.
		\param year is well, year. Duh. ;-)
	*/
	RPDate(int day, int month, int year)
		{ setDate(day, month, year); }
		
#ifdef __palmos__
	/*! Casting Operator for Palm OS* from DateType */
	RPDate(const DateType& rhs){ setDate(rhs.day, rhs.month, rhs.year + 1904); };
	/*! Casting Operator for Palm OS back to DateType*/
	operator DateType() const;
#endif // __palmos__

#ifdef _WX_WIN
	/*! Casting Operator for wxWindows from wxDateTime */
	RPDate(const wxDateTime* rhs){ setDate(rhs->GetDay(), rhs->GetMonth() + 1, rhs->GetYear()); };
#endif // _WX_WIN

	/*! Sets the date with the given values.
		\param day is day of month .
		\param month is month in year.
		\param year is well, year. Did you have to read this far to find that out?. ;-)
	*/
	void setDate(int day, int month, int year);
	/*! Gets the day of the month.
		\return An int containting the day of the month.
	*/
	int getDay()   const { return m_nDay; }
	/*! Gets the month of the year.
		\return An int containting the month of the year.
	*/
	int getMonth() const { return m_nMonth; }
	/*!	Gets the year.
		\return An int containting the year.
	*/
	int getYear()  const { return m_nYear; }
	/*!	Advance the RPDate by given number of days. If delta is negative
		this function will back the RPDate up. Delta is long data type because
		on some	systems int will only give +/- about 32,000. That
		corresponds to less than 100 years. Not enough in some cases
	*/
	void advanceDate(long delta = 1);
	/*!	Returns the number of days in the current month.
		\return An int containing the total number of days in the month.
	*/
	int  monthLength() const;
	
	/*! Returns the name of the current weekday in a string.
		\return A string containing the current weekday name.
	*/
	string getDayOfWeekString() const;
	/*! Returns the current month name in a string.
		\return A string containing the current month name.
	*/
	string getMonthString();
	/*! Returns the current month name abbreviated in a string.
		\return A string containing the current abbreviated month name.
	*/
	string getMonthAbbr();
	/*!	Returns a full date string like "Friday, January 09, 2004".
		\return A string of the unabreviated date.
	*/
	string getFullDateString();
	/*!	Returns a full date string with the month abbreviated 
			like "Friday, Jan 09, 2004".
		\return A string of the date.
	*/
	string getFullAbbrDateString();
	/*!	Returns a formal date string like "03/16/2004".
		\return A string of the formal date format.
	*/
	string getFormalDateString();

private:
	/*! Returns whether a year is a leap year.
		\return True if it is a leap year.
	*/
	bool isLeap() const;
	/*!	Advances the RPDate by one day. Used internally only, to advance one
		day call advance(1)
	*/
	void nextDate();
	/*!	Advances the RPDate back by one day. Used internally only, to advance
		one day call advance(-1)
	*/
	void previousDate();
	
	/*! Stores the current day of the month */
	int m_nDay;
	/*! Stores the current month of the year */
	int m_nMonth;
	/*! Stores the current year */
	int m_nYear;

};

  //
  // Non-member Functions
  //
	/*! Is-equal-to operator	*/
	bool operator==(const RPDate &left, const RPDate &right);
	/*! Less-than operator	*/
	bool operator< (const RPDate &left, const RPDate &right);
	/*! Not-equal-to operator	*/
	inline bool operator!=(const RPDate &left, const RPDate &right)
		{ return !(left == right); }
	/*! Less-than or equal-to operator	*/
	inline bool operator<=(const RPDate &left, const RPDate &right)
		{ return left < right || left == right; }
	/*! Greater-than operator */
	inline bool operator>(const RPDate &left, const RPDate &right)
		{ return !(left <= right); }
	/*!	Greater-than or equal-to operator */
	inline bool operator>=(const RPDate &left, const RPDate &right)
	{ return !(left < right); }


	/*!	The function figures out how many days difference there is between
		two RPDates. This function returns long for the same reason
		that the argument to RPDate::advance() is long. See above.
		\return A long containing the total number of days between the two dates
	*/
	long operator-(const RPDate &left, const RPDate &right);
	/*! Returns the day of the week as an integer
		\param day is day of month.
		\param month is month in year.
		\param year is year, we have been over this already.
		\return An int containing the day of the week 0=SUNDAY, 1=MONDAY, etc...
	*/
	int dayofweek(int day, int month, int year);
	/*! Returns the day of the week as an integer
		\param rhs is the date being queried.
		\return An int containing the day of the week 0=SUNDAY, 1=MONDAY, etc...
	*/
	int dayofweek(const RPDate& rhs);

#endif // _RPDATE_H_

