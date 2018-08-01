/***************************************************************************
	RPUtils.h  -  Various tools and definitions.
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

/** \file RPUtils.h
 * This file contains misc tools and type definitions needed to create a
	reading plan.

	General Steps to creating a plan:
	
	1) Create a KJVBible object.

	2) Have the UI prompt for what books to be read and set the selections in
	the KJVBible object.

	3) Have the UI prompt for a start date and end date and days of week to read
	on.

	4) Create a CMultDays object with the start date, end date, and daysFlags
	parameters set.

	5) Create an empty CSELStack object.

	6) Call buildKJVBible with the CMultDays object and the CSELStack object.

	7) Call calcReadingDays with the CMultDays object and the CSELStack object.

	8) The ReadingPlan is in the CMultDays object, use it to display or save the plan.

	
 */

#ifndef _UTILS_H_
#define _UTILS_H_

// Forward References
class RPDate;
class KJVBible;
class CSELStack;
class CMultDays;

// Since some Palms are slow, and calculating a new plan can take some time
// The following function will provide feedback to users when run on a Palm.
#ifdef __palmos__
#include "ReadingPlanner.h"
static void AnimateProgress(UInt16 count);
#endif

/*!	This type is used to track whether a day of the week is to be assigned a reading
*/
typedef unsigned char DAYFLAGS;

/*!	This enum is used for the DAYFLAGS type. It stores each day like as boolean.
*/
enum RPWeekday
{
	SUNDAY 		= 1,
	MONDAY 		= 2,
	TUESDAY		= 4,
	WEDNESDAY 	= 8,
	THURSDAY 	= 16,
	FRIDAY		= 32,
	SATURDAY	= 64
};

/*! This enum is used for easy access to book numbers */
enum RPBooks
{		GENESIS, 		EXODUS, 		LEVITICUS, 		NUMBERS, 		DEUTERONOMY,
		JOSHUA, 		JUDGES, 		RUTH, 			ISAMUEL, 		IISAMUEL,
		IKINGS, 		IIKINGS,    	ICHRONICLES,	IICHRONICLES, 	EZRA,
		NEHEMIAH, 		ESTHER, 		JOB,			PSALMS, 		PROVERBS,
		ECCLESIASTES,	SONG_OF_SONGS,	ISAIAH,			JEREMIAH,		LAMENTATIONS,
		EZEKIEL, 		DANIEL, 		HOSEA, 			JOEL, 			AMOS,
		OBADIAH, 		JONAH, 			MICAH, 			NAHUM, 			HABAKKUK,
		ZEPHANIAH, 		HAGGAI,			ZECHARIAH, 		MALACHI, 		MATTHEW,
		MARK, 			LUKE, 			JOHN, 			ACTS, 			ROMANS,
		ICORINTHIANS, 	IICORINTHIANS, 	GALATIANS, 		EPHESIANS, 		PHILIPPIANS,
		COLOSIANS, 		ITHESSALONIANS,	IITHESSALONIANS,ITIMOTHY,		IITIMOTHY,
		TITUS, 			PHILEMON, 		HEBREWS, 		JAMES, 			IPETER,
		IIPETER,		IJOHN, 			IIJOHN, 		IIIJOHN, 		JUDE,
		REVELATION
};

/*! calcTotalDays determines how many days will be assigned a reading in the
	time span given and using only the days flagged.
	\param begin is the starting date of the time span.
	\param end is the ending date of the time span.
	\param dayFlags are the days of the week allowed to have readings assigned
	to them.
	\return An int containing the total days of reading in the time span.
	*/
unsigned int calcTotalDays(RPDate& begin, RPDate& end, DAYFLAGS dayFlags);

/*!	nextReadingDay returns the date of the next reading date to be read on
	according to the date given and the dayFlags variable.
	\param beginDate is the date to start from.
	\param dayFlags are the days of the week allowed to have readings assigned
	to them.
	\return A RPDate object containing the date of the next reading assignment.
*/
RPDate nextReadingDay(RPDate beginDate, DAYFLAGS dayFlags);

/* This is an easy way to build a selection or reading to be assigned using the
	KJVBible class.

	Note: This is NOT the only way to create a stack for the calcReadingDays
	function. Your stack can have book/chapter combos in any order you want it
	to be in.
	\param bible is the KJVBible object, which has been initialized with books
	selected to be assigned.
	\param SEL_List is an empty CSELStack object which will store the selection
	of readings to be assigned.
*/
void buildKJVSEL(const KJVBible* bible, CSELStack& SEL_List);

/*! calcReadingDays is where everything comes together. This is where the plan
	is actually created.
	\param SEL_List holds a stack of reading selections to draw from.
	\param Days holds the actual reading plan as it is created in
	calcReadingDays.
	\return true if the creation of the plan was a success.
*/
bool calcReadingDays(CSELStack& SEL_List/*IN*/, CMultDays& Days /*OUT*/);

#endif // _UTILS_H_

