/***************************************************************************
	KJVChapter.h  -  Interface for KJVChapter class
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

#ifndef _KJVChapter_h_
#define _KJVChapter_h_


/*! KJVChapter is the most basic unit of a KJVBible object. Basic purpose is to
	store the total number of verses the given chapter has. Future
	implemetations may contain whether the chapter is selected to be read.
*/
class KJVChapter
{
public:
	/* Default Constructor */
	KJVChapter();
	/*! Sets the total verses the given chapter has. 
			\param nVerses is the total number of verses to set this chapter as having.
	*/
	void setVerses(int nVerses);
	/*! Gets the total verses the given chapter has */
	int getVerses() const;

private:
	//! The total verse the given chapter has, See KJVResource.h for the actual values.
	int m_nVerses;
	/*! This is used during construction of a KJVBible object, incrementing
		through each chapter as they are created. This value indirectly tells
		the	constructor how many verses are in the chapter.
	*/
	static int m_nChapterNumber;
};

#endif //_KJVChapter_h_

