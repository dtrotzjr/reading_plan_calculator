/***************************************************************************
	Day.h  -  Interface for CDay class
                             -------------------
    begin        : Sat Jan 03 18:00:00 PST 2004
    copyright    : (C) 2001-2005 by David Trotz Jr
    email        : dtrotzjr@readingplanner.com
    description	 : 
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

#ifndef _DAY_H_
#define _DAY_H_

#include "SELStack.h"
#include "RPDate.h"
/*!	CDay class extends CSELStack by adding date information to the stack of
	SELECTIONS allowing for more sophisticated storage of SELECTIONS by
	attaching the date they are assigned to be read
*/
class CDay : public CSELStack
{
	public:
	/*!	Default Construtor */
		CDay();
    /*! Overloaded Construtor takes a RPDate object to initialize the date of the CDay object */
		CDay(RPDate date);
	/*!	Default Deconstructor */
		~CDay();
	/*!	Returns the date of an object of this class.
		\return A copy of m_date
	*/
		RPDate getDate();
	/*! Sets the date of an object of this class
		\param date is the initialized date you want to assing to this CDay object
	*/
    void setDate(const RPDate& date);
    /*! Returns the total number of verses assigned to a day.
        /return the total verses.
    */
    int getVerses();
	private:
	/*!	Date attached to this stack */
		RPDate m_date;
};

#endif // _DAY_H_

