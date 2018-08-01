/***************************************************************************
	KJVBible.h  -  Interface for KJVBible class
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

#ifndef _KJVBible_h_
#define _KJVBible_h_

#include "KJVBook.h"


#ifndef __palmos__
#include <string.h>
#include <stdlib.h>
using std::string;
#endif // __palmos__

#ifdef __palmos__
#include "RPString.h"
#define string RPString
#endif // __palmos__


/*! KJVBible is a class used to track reading selections from the bible.
	As it's name states it is based upon the KJV verse scheme. This is a
	limitation of the class but so far has not provided any obstacles. Books can
	be selected for assignment to a reading plan, and other information such as
	chapter/verse count can be obtained from this class.
*/
class KJVBible  
{
public:
	/*! Default Constructor */
	KJVBible();
	/*! Deconstructor */
	~KJVBible();

	/*! Returns the total chapters in the given book.
		\param strName is a string of the name of the book to query.
		\return The total number of chapters in the requested book.
		A return of -1 indicates a failed match to the book number.
	*/
	int getChapters(string strName) const;
	/*! Returns the total chapters in the given book.

		Note: You can use the enumerated book values for nBookNum.
		\param nBookNum is book number to query.
		\return The total number of chapters in the requested book.
		A return of -1 indicates a failed match to the book number.
	*/
	int getChapters(int nBookNum)  const;
	/*! Returns the total verses in the given book.
		\param strName is a string of the name of the book to query
		\return The total number of verses in the requested book.
		A return of -1 indicates a failed match to the book name.
	*/
	long getVerses(string strName)  const;
	/*! Returns the total verses in the given book.

		Note: You can use the enumerated book values for nBookNum.
		\param nBookNum is book number to query.
		\return The total number of verses in the requested book.
		A return of -1 indicates a failed match to the book number.
	*/
	long getVerses(int nBookNum)  const;
	/*! Returns the total verses in the given book/chapter combo.
		\param strName is a string of the name of the book to query.
		\param nChapter is the chapter number of the book to query.
		\return The total number of verses in the requested book/chapter combo.
		A return of -1 indicates a failed match to the book/chapter combo.
	*/
	long getVerses(string strName, int nChapter)  const;
	/*! Returns the total verses in the given book/chapter combo.

		Note: You can use the enumerated book values for nBookNum.
		\param nBookNum is book number to query.
		\param nChapter is the chapter number of the book to query.
		\return The total number of verses in the requested book/chapter combo.
		A return of -1 indicates a failed match to the book/chapter combo.
	*/
	long getVerses(int nBookNum,int nChapter)  const;
	/*!	Returns the name of a requested book/

		Note: You can use the enumerated book values for nBookNum.
		\param nBookNum is book number to query.
		\return A const of the internal string name. If it fails it returns the
		bookname for the first book in the KJVBible (not the best option I know)
	*/
	string getName(int nBookNum)  const;
	/*! Selects/De-selects the requested book to be assigned for reading/

		Note: You can use the enumerated book values for nBookNum.
		\param nBookNum is book number to set.
		\param bnSelect is the value to set the book to. A value of true implies
		that it is to be assigned for reading.
	*/
	bool select(int nBookNum, bool bnSelect);
	/*! Selects/De-selects the requested range of books to be assigned for reading.

		Note: You can use the enumerated book values for the range values.
		\param nLow is the first book to be set in the range.
		\param nHigh is the last book to be set in the range.
		\param bnSelect is the value to set the range to. A value of true implies
		that it is to be assigned for reading.
	*/
	void selectRange(int nLow, int nHigh, bool bnSelect);
	/*! Checks if a book has been selected for reading.

		Note: You can use the enumerated book values for nBookNum.
		\param nBookNum is book number to query.
		\return A bool indicating selection status. A value of true implies
		that it is to be assigned for reading.
	*/
	bool isSelected(int nBookNum)  const;
	/*! Checks whether a specified range of books have been selected for reading.

		Note: You can use the enumerated book values for the range values.
		\param nLow is the first book to be queried in the range.
		\param nHigh is the last book to be queried in the range.
		\return A bool indicating selection status. A value of true implies
		that it is to be assigned for reading.
	*/
	bool isSelected(int nLow, int nHigh)  const;
private:
	/*!	An array of books in the KJVBible scheme */
	KJVBook m_Books[66];
};

#endif //_KJVBible_h_

