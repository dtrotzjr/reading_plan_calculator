/***************************************************************************
	KJVBook.h  -  Interface for KJVBook class
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

#ifndef _KJVBook_h_
#define _KJVBook_h_


#ifndef __palmos__
#include <string>
#include <stdlib.h>
using std::string;
#endif // __palmos__

#ifdef __palmos__
#include "RPString.h"
#define string RPString
#endif // __palmos__

#include "KJVChapter.h"
		
/*! KJVBook is the middle man in the KJVBible class. KJVBook tracks all the
	chapters in a given book, giving access to how many verses are in a given
	chapter of the book or the entire book itself. Also tracked here is whether
	the given book will be included in a reading plan.
*/
class KJVBook
{
public:
	/*! Default Constructor */
	KJVBook();
	/*! Copy Constructor */
	KJVBook(KJVBook& rhs);
	/*! Deconstructor */
	~KJVBook();
	/*! Assignment Operator */
	const KJVBook& operator =(const KJVBook& rhs);

	/*!	Returns the name of the book
		\return A copy of the book name (platform dependant)*/
	string getName() const;
	/*! Sets the name of the book
		\param strName is the name to be assigned to the given KJVBook object
	*/
	void setName(string strName);
	/*! Gets the total chapters in the given book.
		\return Total number of chapters in the book.
	*/
	int getChapters() const;
	/*! Gets the total verses in the given book.
		\return Total number of verses in the book.
	*/
	int getVerses() const;
	/*! Gets the total verses in a given chapter.
		\param nChapter is which chapter is being queried
		\return Total number of verses in a given chapter.
	*/
	int getVerses(const int& nChapter) const;
	/*! Selects the book to be added to a reading assignment.
		\param bnSelect is true if it is being assigned.
	*/
	void select(bool bnSelect);
	/*! Returns whether a book is set to be assigned.
		\return True if it is set to be assigned.
	*/
	bool isSelected() const;
private:
	/*! Array storing the chapters in the given book. */
	KJVChapter* m_pChapters;
	/*!	Name of the book. */
	string m_strBookName;
	/*! Total Chapters in the given book. */
	int m_nChapters;
	/*! This is used during construction of a KJVBible object, incrementing
		through each book as they are created. This value indirectly tells
		the	constructor how many chapters are in the book.
	*/
	static int m_bookNumber;
	/*! Stores whether the book is selected for assignment. */
	bool m_bnSelected;
};
#endif //_KJVBook_h_

