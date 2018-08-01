/***************************************************************************
	SELStack.h  -  Interface for CSELStack class
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

#ifndef _SELSTACK_H_
#define _SELSTACK_H_

/*!
	SELECTION is a node for the CSELStack class
*/
struct SELECTION
{
    //! The book number starts at 0
    int m_nBookNum;
    //! The chapter number starts at 0
    int m_nChapterNum;
    //! Indicates whether the following verses represent the entire chapter or not.
    bool m_bnFullChapter;
    //! The starting verse (0 based) in the current selection.
    long m_nStartVerse;
    //! The ending verse (0 based) in the current selection.
    long m_nEndVerse;
    //! Points to the next node in the list.
    SELECTION* m_pNext;
};

typedef SELECTION* SEL_PTR;

/*!
	CSELStack is a "first in/first out" stack used to store selections which
	the function calcReadingDays will use to draw reading selections from.
*/
class CSELStack
{
	public:
	/*!	Default Construtor */
		CSELStack();
	/*!	Default Deconstructor */
		~CSELStack();
	/*! Copy Construtor */
		CSELStack(const CSELStack& rhs);
	/*! Assignement operator */
		const CSELStack& operator=(const CSELStack& rhs);
	/*! Pushes a SELECTION onto the stack, pushes to the back of the stack
		\param sel is the SELECTION being pushed to the stack
	*/
		void push(SELECTION sel);
	/*!	Pops a SELECTION from the stack, draws from the front of the stack
		\return a copy of the top SELECTION
	*/
		SELECTION pop();
	/*! Removes all the SELECTIONS which are currently stored in the stack */
		void clear();
	/*! Returns whether the stack is currently empty */
		bool isEmpty() const;
		/*! Returns the current number of SELECTIONS being stored
			\return A bool value. A true value implies object is empty.
		*/
		unsigned int size() const;
		/*! Returns the sum of the total number of verses all of the stored
			SELECTION nodes.
			\return Total nodes in stack
		*/
		unsigned int getTotalVerses() const;
		/*! Allows a peek at the top node without removing it from the stack
			\return Copy of top node
		*/
		SELECTION peek() const;
	protected:
		/*!	Points to the front of the stack */
		SEL_PTR m_pTop;
		/*!	Points to the back of the stack */
		SEL_PTR m_pCurr;
		/*!	The sum of the total number of verses all of the stored SELECTION nodes. */
		unsigned int m_nTotalVerses;
		/*! The current number of SELECTIONS being stored */
		unsigned int m_nSize;
};

#endif // _SELSTACK_H_

