/***************************************************************************
	MultDays.h  -  Interface for CMultDays class
                             -------------------
    begin                : Sat Mar 24 19:15:31 PST 2001
    copyright            : (C) 2001-2005 by David Trotz Jr
    email                : dtrotzjr@readingplanner.com
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

#ifndef _MULTDAYS_H_
#define _MULTDAYS_H_


#include "RPUtils.h"
#include "RPDay.h"
#include "RPDate.h"


//Forward references
class RPDate;


/*!	CMultDays is a storage class designed to hold an array of CDay objects.
	It is used to store all of the days which have a reading selection assigned
	to them.
*/
class CMultDays  
{
public:
	/*! Default Constructor */
	CMultDays();
	/*! Overloaded Constructor.
		\param begin is the starting date of assignment range.
		\param end is the ending date of assignment range.
		\param dayFlags is an integer representing the days of the week being
		assigned to.
	*/
	CMultDays(RPDate& begin, RPDate& end, DAYFLAGS dayFlags);
	/*! Default Copy Constructor */
	CMultDays(CMultDays& rhs);
	/*! Deconstructor */
	~CMultDays();
	/*! Assignment Operator */
	const CMultDays& operator=(const CMultDays& rhs);
	/*!	Returns the total number of days stored */
	int getTotalDays() const;
	/*!	Returns the date of the last Day stored in the container
		/return A copy of the last objects date object.
		/note Be careful to not call this on an empty container.
		*/
	RPDate getEndDate() const;
	/*! Insert a Day into the array.
		\param day is a CDay object which needs to be initialized, it is
		important that this day's date be calculated using the nextReadingDay
		function if you want the added day to fit the rest of the days in the
		array.
	*/
	bool addDay(CDay& day);
	/*!	Add a SELECTION to a particular day in the array.
		\param nDayNum is the index to the day in the array being added to.
		\param sel is the SELECTION being added into the CDay object in the array.
	*/
	void addSelToDay(int nDayNum,SELECTION sel);
	/*!	Replaces a particular day in the array with a different CDay object.
		\param nDayNum is the index to the day in the array being replaced.
		\param day is the new CDay object replacing the existing day.
	*/
	void setDay(int nDayNum,CDay day);
	/*! Returns a copy of a specific day.
		\param nDayNum is the index to the day in the array being returned.
		\return A copy of the CDay object at the dayNum index.
	*/
	CDay getDay(int nDayNum) const;
	/*!	Resizes the array of CDay objects.

		WARNING: Care must be taken when resizing because if the size is larger
		than the initialized size all new CDay objects created will take on the
		default day defined in the CDay class. This is typically used to
		truncate a CMultDays which is longer than is needed.
		\return true if successful (Not implemented)
	*/
	bool resizeDays(int nSize);
	/*!	Returns the total number of CDay objects in the array
		\return int value representing the total size of the array
	*/
	int getSize() const;
	/*!	Erases current array and creates a new array using the given parameters
		\param begin is the starting date of assignment range.
		\param end is the ending date of assignment range.
		\param dayFlags is an integer representing the days of the week being
		assigned to.
	*/
	void reInitialize(RPDate& begin, RPDate& end, DAYFLAGS dayFlags);
	/*! Deletes all CDay objects and sets the size to 0 */
	void clear();
	/*! Specifies if the dayIndex passed in is the last day in the set
		\param dayIndex is the day we are checking for.
		\return true if it is the last day in the set.
	*/
	bool dayInRange(int dayIndex) const;
private:
	/*! Size of array */
	int m_nNumDays;
	/*! Array which stores the CDay objects array */
	CDay* m_pDays;
};

#endif // _MULTDAYS_H_

