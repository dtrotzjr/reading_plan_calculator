/***************************************************************************
	KJVChapter.cpp  -  Implementation for KJVChapter class
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


#include "KJVChapter.h"
#include "KJVResource.h"

int KJVChapter::m_nChapterNumber = ID_GENESIS_001;

void KJVChapter::setVerses(int nVerses)
{
	m_nVerses = nVerses;
}

int KJVChapter::getVerses() const
{
	return m_nVerses;
}

KJVChapter::KJVChapter()
{
	// Check to see if this object has already been created if so we
	// need to reset this counter for this new object. Typically only
	// one KJVBible object should exist but someone may create more than
	// one, and here is where we will check for it. Also see the 
	// constructor for CBooks the same idea is used there as well.
	if(m_nChapterNumber > ID_REVELATION_022)
		m_nChapterNumber = ID_GENESIS_001;

	switch (m_nChapterNumber)
		{


		case ID_GENESIS_001:
			m_nVerses = 31;
			break;

		case ID_GENESIS_002:
			m_nVerses = 25;
			break;

		case ID_GENESIS_003:
			m_nVerses = 24;
			break;

		case ID_GENESIS_004:
			m_nVerses = 26;
			break;

		case ID_GENESIS_005:
			m_nVerses = 32;
			break;

		case ID_GENESIS_006:
			m_nVerses = 22;
			break;

		case ID_GENESIS_007:
			m_nVerses = 24;
			break;

		case ID_GENESIS_008:
			m_nVerses = 22;
			break;

		case ID_GENESIS_009:
			m_nVerses = 29;
			break;

		case ID_GENESIS_010:
			m_nVerses = 32;
			break;

		case ID_GENESIS_011:
			m_nVerses = 32;
			break;

		case ID_GENESIS_012:
			m_nVerses = 20;
			break;

		case ID_GENESIS_013:
			m_nVerses = 18;
			break;

		case ID_GENESIS_014:
			m_nVerses = 24;
			break;

		case ID_GENESIS_015:
			m_nVerses = 21;
			break;

		case ID_GENESIS_016:
			m_nVerses = 16;
			break;

		case ID_GENESIS_017:
			m_nVerses = 27;
			break;

		case ID_GENESIS_018:
			m_nVerses = 33;
			break;

		case ID_GENESIS_019:
			m_nVerses = 38;
			break;

		case ID_GENESIS_020:
			m_nVerses = 18;
			break;

		case ID_GENESIS_021:
			m_nVerses = 34;
			break;

		case ID_GENESIS_022:
			m_nVerses = 24;
			break;

		case ID_GENESIS_023:
			m_nVerses = 20;
			break;

		case ID_GENESIS_024:
			m_nVerses = 67;
			break;

		case ID_GENESIS_025:
			m_nVerses = 34;
			break;

		case ID_GENESIS_026:
			m_nVerses = 35;
			break;

		case ID_GENESIS_027:
			m_nVerses = 46;
			break;

		case ID_GENESIS_028:
			m_nVerses = 22;
			break;

		case ID_GENESIS_029:
			m_nVerses = 35;
			break;

		case ID_GENESIS_030:
			m_nVerses = 43;
			break;

		case ID_GENESIS_031:
			m_nVerses = 55;
			break;

		case ID_GENESIS_032:
			m_nVerses = 32;
			break;

		case ID_GENESIS_033:
			m_nVerses = 20;
			break;

		case ID_GENESIS_034:
			m_nVerses = 31;
			break;

		case ID_GENESIS_035:
			m_nVerses = 29;
			break;

		case ID_GENESIS_036:
			m_nVerses = 43;
			break;

		case ID_GENESIS_037:
			m_nVerses = 36;
			break;

		case ID_GENESIS_038:
			m_nVerses = 30;
			break;

		case ID_GENESIS_039:
			m_nVerses = 23;
			break;

		case ID_GENESIS_040:
			m_nVerses = 23;
			break;

		case ID_GENESIS_041:
			m_nVerses = 57;
			break;

		case ID_GENESIS_042:
			m_nVerses = 38;
			break;

		case ID_GENESIS_043:
			m_nVerses = 34;
			break;

		case ID_GENESIS_044:
			m_nVerses = 34;
			break;

		case ID_GENESIS_045:
			m_nVerses = 28;
			break;

		case ID_GENESIS_046:
			m_nVerses = 34;
			break;

		case ID_GENESIS_047:
			m_nVerses = 31;
			break;

		case ID_GENESIS_048:
			m_nVerses = 22;
			break;

		case ID_GENESIS_049:
			m_nVerses = 33;
			break;

		case ID_GENESIS_050:
			m_nVerses = 26;
			break;


		case ID_EXODUS_001:
			m_nVerses = 22;
			break;

		case ID_EXODUS_002:
			m_nVerses = 25;
			break;

		case ID_EXODUS_003:
			m_nVerses = 22;
			break;

		case ID_EXODUS_004:
			m_nVerses = 31;
			break;

		case ID_EXODUS_005:
			m_nVerses = 23;
			break;

		case ID_EXODUS_006:
			m_nVerses = 30;
			break;

		case ID_EXODUS_007:
			m_nVerses = 25;
			break;

		case ID_EXODUS_008:
			m_nVerses = 32;
			break;

		case ID_EXODUS_009:
			m_nVerses = 35;
			break;

		case ID_EXODUS_010:
			m_nVerses = 29;
			break;

		case ID_EXODUS_011:
			m_nVerses = 10;
			break;

		case ID_EXODUS_012:
			m_nVerses = 50;
			break;

		case ID_EXODUS_013:
			m_nVerses = 22;
			break;

		case ID_EXODUS_014:
			m_nVerses = 31;
			break;

		case ID_EXODUS_015:
			m_nVerses = 27;
			break;

		case ID_EXODUS_016:
			m_nVerses = 36;
			break;

		case ID_EXODUS_017:
			m_nVerses = 16;
			break;

		case ID_EXODUS_018:
			m_nVerses = 27;
			break;

		case ID_EXODUS_019:
			m_nVerses = 25;
			break;

		case ID_EXODUS_020:
			m_nVerses = 26;
			break;

		case ID_EXODUS_021:
			m_nVerses = 36;
			break;

		case ID_EXODUS_022:
			m_nVerses = 31;
			break;

		case ID_EXODUS_023:
			m_nVerses = 33;
			break;

		case ID_EXODUS_024:
			m_nVerses = 18;
			break;

		case ID_EXODUS_025:
			m_nVerses = 40;
			break;

		case ID_EXODUS_026:
			m_nVerses = 37;
			break;

		case ID_EXODUS_027:
			m_nVerses = 21;
			break;

		case ID_EXODUS_028:
			m_nVerses = 43;
			break;

		case ID_EXODUS_029:
			m_nVerses = 46;
			break;

		case ID_EXODUS_030:
			m_nVerses = 38;
			break;

		case ID_EXODUS_031:
			m_nVerses = 18;
			break;

		case ID_EXODUS_032:
			m_nVerses = 35;
			break;

		case ID_EXODUS_033:
			m_nVerses = 23;
			break;

		case ID_EXODUS_034:
			m_nVerses = 35;
			break;

		case ID_EXODUS_035:
			m_nVerses = 35;
			break;

		case ID_EXODUS_036:
			m_nVerses = 38;
			break;

		case ID_EXODUS_037:
			m_nVerses = 29;
			break;

		case ID_EXODUS_038:
			m_nVerses = 31;
			break;

		case ID_EXODUS_039:
			m_nVerses = 43;
			break;

		case ID_EXODUS_040:
			m_nVerses = 38;
			break;


		case ID_LEVITICUS_001:
			m_nVerses = 17;
			break;

		case ID_LEVITICUS_002:
			m_nVerses = 16;
			break;

		case ID_LEVITICUS_003:
			m_nVerses = 17;
			break;

		case ID_LEVITICUS_004:
			m_nVerses = 35;
			break;

		case ID_LEVITICUS_005:
			m_nVerses = 19;
			break;

		case ID_LEVITICUS_006:
			m_nVerses = 30;
			break;

		case ID_LEVITICUS_007:
			m_nVerses = 38;
			break;

		case ID_LEVITICUS_008:
			m_nVerses = 36;
			break;

		case ID_LEVITICUS_009:
			m_nVerses = 24;
			break;

		case ID_LEVITICUS_010:
			m_nVerses = 20;
			break;

		case ID_LEVITICUS_011:
			m_nVerses = 47;
			break;

		case ID_LEVITICUS_012:
			m_nVerses = 8;
			break;

		case ID_LEVITICUS_013:
			m_nVerses = 59;
			break;

		case ID_LEVITICUS_014:
			m_nVerses = 57;
			break;

		case ID_LEVITICUS_015:
			m_nVerses = 33;
			break;

		case ID_LEVITICUS_016:
			m_nVerses = 34;
			break;

		case ID_LEVITICUS_017:
			m_nVerses = 16;
			break;

		case ID_LEVITICUS_018:
			m_nVerses = 30;
			break;

		case ID_LEVITICUS_019:
			m_nVerses = 37;
			break;

		case ID_LEVITICUS_020:
			m_nVerses = 27;
			break;

		case ID_LEVITICUS_021:
			m_nVerses = 24;
			break;

		case ID_LEVITICUS_022:
			m_nVerses = 33;
			break;

		case ID_LEVITICUS_023:
			m_nVerses = 44;
			break;

		case ID_LEVITICUS_024:
			m_nVerses = 23;
			break;

		case ID_LEVITICUS_025:
			m_nVerses = 55;
			break;

		case ID_LEVITICUS_026:
			m_nVerses = 46;
			break;

		case ID_LEVITICUS_027:
			m_nVerses = 34;
			break;


		case ID_NUMBERS_001:
			m_nVerses = 54;
			break;

		case ID_NUMBERS_002:
			m_nVerses = 34;
			break;

		case ID_NUMBERS_003:
			m_nVerses = 51;
			break;

		case ID_NUMBERS_004:
			m_nVerses = 49;
			break;

		case ID_NUMBERS_005:
			m_nVerses = 31;
			break;

		case ID_NUMBERS_006:
			m_nVerses = 27;
			break;

		case ID_NUMBERS_007:
			m_nVerses = 89;
			break;

		case ID_NUMBERS_008:
			m_nVerses = 26;
			break;

		case ID_NUMBERS_009:
			m_nVerses = 23;
			break;

		case ID_NUMBERS_010:
			m_nVerses = 36;
			break;

		case ID_NUMBERS_011:
			m_nVerses = 35;
			break;

		case ID_NUMBERS_012:
			m_nVerses = 16;
			break;

		case ID_NUMBERS_013:
			m_nVerses = 33;
			break;

		case ID_NUMBERS_014:
			m_nVerses = 45;
			break;

		case ID_NUMBERS_015:
			m_nVerses = 41;
			break;

		case ID_NUMBERS_016:
			m_nVerses = 50;
			break;

		case ID_NUMBERS_017:
			m_nVerses = 13;
			break;

		case ID_NUMBERS_018:
			m_nVerses = 32;
			break;

		case ID_NUMBERS_019:
			m_nVerses = 22;
			break;

		case ID_NUMBERS_020:
			m_nVerses = 29;
			break;

		case ID_NUMBERS_021:
			m_nVerses = 35;
			break;

		case ID_NUMBERS_022:
			m_nVerses = 41;
			break;

		case ID_NUMBERS_023:
			m_nVerses = 30;
			break;

		case ID_NUMBERS_024:
			m_nVerses = 25;
			break;

		case ID_NUMBERS_025:
			m_nVerses = 18;
			break;

		case ID_NUMBERS_026:
			m_nVerses = 65;
			break;

		case ID_NUMBERS_027:
			m_nVerses = 23;
			break;

		case ID_NUMBERS_028:
			m_nVerses = 31;
			break;

		case ID_NUMBERS_029:
			m_nVerses = 40;
			break;

		case ID_NUMBERS_030:
			m_nVerses = 16;
			break;

		case ID_NUMBERS_031:
			m_nVerses = 54;
			break;

		case ID_NUMBERS_032:
			m_nVerses = 42;
			break;

		case ID_NUMBERS_033:
			m_nVerses = 56;
			break;

		case ID_NUMBERS_034:
			m_nVerses = 29;
			break;

		case ID_NUMBERS_035:
			m_nVerses = 34;
			break;

		case ID_NUMBERS_036:
			m_nVerses = 13;
			break;


		case ID_DEUTERONOMY_001:
			m_nVerses = 46;
			break;

		case ID_DEUTERONOMY_002:
			m_nVerses = 37;
			break;

		case ID_DEUTERONOMY_003:
			m_nVerses = 29;
			break;

		case ID_DEUTERONOMY_004:
			m_nVerses = 49;
			break;

		case ID_DEUTERONOMY_005:
			m_nVerses = 33;
			break;

		case ID_DEUTERONOMY_006:
			m_nVerses = 25;
			break;

		case ID_DEUTERONOMY_007:
			m_nVerses = 26;
			break;

		case ID_DEUTERONOMY_008:
			m_nVerses = 20;
			break;

		case ID_DEUTERONOMY_009:
			m_nVerses = 29;
			break;

		case ID_DEUTERONOMY_010:
			m_nVerses = 22;
			break;

		case ID_DEUTERONOMY_011:
			m_nVerses = 32;
			break;

		case ID_DEUTERONOMY_012:
			m_nVerses = 32;
			break;

		case ID_DEUTERONOMY_013:
			m_nVerses = 18;
			break;

		case ID_DEUTERONOMY_014:
			m_nVerses = 29;
			break;

		case ID_DEUTERONOMY_015:
			m_nVerses = 23;
			break;

		case ID_DEUTERONOMY_016:
			m_nVerses = 22;
			break;

		case ID_DEUTERONOMY_017:
			m_nVerses = 20;
			break;

		case ID_DEUTERONOMY_018:
			m_nVerses = 22;
			break;

		case ID_DEUTERONOMY_019:
			m_nVerses = 21;
			break;

		case ID_DEUTERONOMY_020:
			m_nVerses = 20;
			break;

		case ID_DEUTERONOMY_021:
			m_nVerses = 23;
			break;

		case ID_DEUTERONOMY_022:
			m_nVerses = 30;
			break;

		case ID_DEUTERONOMY_023:
			m_nVerses = 25;
			break;

		case ID_DEUTERONOMY_024:
			m_nVerses = 22;
			break;

		case ID_DEUTERONOMY_025:
			m_nVerses = 19;
			break;

		case ID_DEUTERONOMY_026:
			m_nVerses = 19;
			break;

		case ID_DEUTERONOMY_027:
			m_nVerses = 26;
			break;

		case ID_DEUTERONOMY_028:
			m_nVerses = 68;
			break;

		case ID_DEUTERONOMY_029:
			m_nVerses = 29;
			break;

		case ID_DEUTERONOMY_030:
			m_nVerses = 20;
			break;

		case ID_DEUTERONOMY_031:
			m_nVerses = 30;
			break;

		case ID_DEUTERONOMY_032:
			m_nVerses = 52;
			break;

		case ID_DEUTERONOMY_033:
			m_nVerses = 29;
			break;

		case ID_DEUTERONOMY_034:
			m_nVerses = 12;
			break;


		case ID_JOSHUA_001:
			m_nVerses = 18;
			break;

		case ID_JOSHUA_002:
			m_nVerses = 24;
			break;

		case ID_JOSHUA_003:
			m_nVerses = 17;
			break;

		case ID_JOSHUA_004:
			m_nVerses = 24;
			break;

		case ID_JOSHUA_005:
			m_nVerses = 15;
			break;

		case ID_JOSHUA_006:
			m_nVerses = 27;
			break;

		case ID_JOSHUA_007:
			m_nVerses = 26;
			break;

		case ID_JOSHUA_008:
			m_nVerses = 35;
			break;

		case ID_JOSHUA_009:
			m_nVerses = 27;
			break;

		case ID_JOSHUA_010:
			m_nVerses = 43;
			break;

		case ID_JOSHUA_011:
			m_nVerses = 23;
			break;

		case ID_JOSHUA_012:
			m_nVerses = 24;
			break;

		case ID_JOSHUA_013:
			m_nVerses = 33;
			break;

		case ID_JOSHUA_014:
			m_nVerses = 15;
			break;

		case ID_JOSHUA_015:
			m_nVerses = 63;
			break;

		case ID_JOSHUA_016:
			m_nVerses = 10;
			break;

		case ID_JOSHUA_017:
			m_nVerses = 18;
			break;

		case ID_JOSHUA_018:
			m_nVerses = 28;
			break;

		case ID_JOSHUA_019:
			m_nVerses = 51;
			break;

		case ID_JOSHUA_020:
			m_nVerses = 9;
			break;

		case ID_JOSHUA_021:
			m_nVerses = 45;
			break;

		case ID_JOSHUA_022:
			m_nVerses = 34;
			break;

		case ID_JOSHUA_023:
			m_nVerses = 16;
			break;

		case ID_JOSHUA_024:
			m_nVerses = 33;
			break;


		case ID_JUDGES_001:
			m_nVerses = 36;
			break;

		case ID_JUDGES_002:
			m_nVerses = 23;
			break;

		case ID_JUDGES_003:
			m_nVerses = 31;
			break;

		case ID_JUDGES_004:
			m_nVerses = 24;
			break;

		case ID_JUDGES_005:
			m_nVerses = 31;
			break;

		case ID_JUDGES_006:
			m_nVerses = 40;
			break;

		case ID_JUDGES_007:
			m_nVerses = 25;
			break;

		case ID_JUDGES_008:
			m_nVerses = 35;
			break;

		case ID_JUDGES_009:
			m_nVerses = 57;
			break;

		case ID_JUDGES_010:
			m_nVerses = 18;
			break;

		case ID_JUDGES_011:
			m_nVerses = 40;
			break;

		case ID_JUDGES_012:
			m_nVerses = 15;
			break;

		case ID_JUDGES_013:
			m_nVerses = 25;
			break;

		case ID_JUDGES_014:
			m_nVerses = 20;
			break;

		case ID_JUDGES_015:
			m_nVerses = 20;
			break;

		case ID_JUDGES_016:
			m_nVerses = 31;
			break;

		case ID_JUDGES_017:
			m_nVerses = 13;
			break;

		case ID_JUDGES_018:
			m_nVerses = 31;
			break;

		case ID_JUDGES_019:
			m_nVerses = 30;
			break;

		case ID_JUDGES_020:
			m_nVerses = 48;
			break;

		case ID_JUDGES_021:
			m_nVerses = 25;
			break;


		case ID_RUTH_001:
			m_nVerses = 22;
			break;

		case ID_RUTH_002:
			m_nVerses = 23;
			break;

		case ID_RUTH_003:
			m_nVerses = 18;
			break;

		case ID_RUTH_004:
			m_nVerses = 22;
			break;


		case ID_1SAMUEL_001:
			m_nVerses = 28;
			break;

		case ID_1SAMUEL_002:
			m_nVerses = 36;
			break;

		case ID_1SAMUEL_003:
			m_nVerses = 21;
			break;

		case ID_1SAMUEL_004:
			m_nVerses = 22;
			break;

		case ID_1SAMUEL_005:
			m_nVerses = 12;
			break;

		case ID_1SAMUEL_006:
			m_nVerses = 21;
			break;

		case ID_1SAMUEL_007:
			m_nVerses = 17;
			break;

		case ID_1SAMUEL_008:
			m_nVerses = 22;
			break;

		case ID_1SAMUEL_009:
			m_nVerses = 27;
			break;

		case ID_1SAMUEL_010:
			m_nVerses = 27;
			break;

		case ID_1SAMUEL_011:
			m_nVerses = 15;
			break;

		case ID_1SAMUEL_012:
			m_nVerses = 25;
			break;

		case ID_1SAMUEL_013:
			m_nVerses = 23;
			break;

		case ID_1SAMUEL_014:
			m_nVerses = 52;
			break;

		case ID_1SAMUEL_015:
			m_nVerses = 35;
			break;

		case ID_1SAMUEL_016:
			m_nVerses = 23;
			break;

		case ID_1SAMUEL_017:
			m_nVerses = 58;
			break;

		case ID_1SAMUEL_018:
			m_nVerses = 30;
			break;

		case ID_1SAMUEL_019:
			m_nVerses = 24;
			break;

		case ID_1SAMUEL_020:
			m_nVerses = 42;
			break;

		case ID_1SAMUEL_021:
			m_nVerses = 15;
			break;

		case ID_1SAMUEL_022:
			m_nVerses = 23;
			break;

		case ID_1SAMUEL_023:
			m_nVerses = 29;
			break;

		case ID_1SAMUEL_024:
			m_nVerses = 22;
			break;

		case ID_1SAMUEL_025:
			m_nVerses = 44;
			break;

		case ID_1SAMUEL_026:
			m_nVerses = 25;
			break;

		case ID_1SAMUEL_027:
			m_nVerses = 12;
			break;

		case ID_1SAMUEL_028:
			m_nVerses = 25;
			break;

		case ID_1SAMUEL_029:
			m_nVerses = 11;
			break;

		case ID_1SAMUEL_030:
			m_nVerses = 31;
			break;

		case ID_1SAMUEL_031:
			m_nVerses = 13;
			break;


		case ID_2SAMUEL_001:
			m_nVerses = 27;
			break;

		case ID_2SAMUEL_002:
			m_nVerses = 32;
			break;

		case ID_2SAMUEL_003:
			m_nVerses = 39;
			break;

		case ID_2SAMUEL_004:
			m_nVerses = 12;
			break;

		case ID_2SAMUEL_005:
			m_nVerses = 25;
			break;

		case ID_2SAMUEL_006:
			m_nVerses = 23;
			break;

		case ID_2SAMUEL_007:
			m_nVerses = 29;
			break;

		case ID_2SAMUEL_008:
			m_nVerses = 18;
			break;

		case ID_2SAMUEL_009:
			m_nVerses = 13;
			break;

		case ID_2SAMUEL_010:
			m_nVerses = 19;
			break;

		case ID_2SAMUEL_011:
			m_nVerses = 27;
			break;

		case ID_2SAMUEL_012:
			m_nVerses = 31;
			break;

		case ID_2SAMUEL_013:
			m_nVerses = 39;
			break;

		case ID_2SAMUEL_014:
			m_nVerses = 33;
			break;

		case ID_2SAMUEL_015:
			m_nVerses = 37;
			break;

		case ID_2SAMUEL_016:
			m_nVerses = 23;
			break;

		case ID_2SAMUEL_017:
			m_nVerses = 29;
			break;

		case ID_2SAMUEL_018:
			m_nVerses = 33;
			break;

		case ID_2SAMUEL_019:
			m_nVerses = 43;
			break;

		case ID_2SAMUEL_020:
			m_nVerses = 26;
			break;

		case ID_2SAMUEL_021:
			m_nVerses = 22;
			break;

		case ID_2SAMUEL_022:
			m_nVerses = 51;
			break;

		case ID_2SAMUEL_023:
			m_nVerses = 39;
			break;

		case ID_2SAMUEL_024:
			m_nVerses = 25;
			break;


		case ID_1KINGS_001:
			m_nVerses = 53;
			break;

		case ID_1KINGS_002:
			m_nVerses = 46;
			break;

		case ID_1KINGS_003:
			m_nVerses = 28;
			break;

		case ID_1KINGS_004:
			m_nVerses = 34;
			break;

		case ID_1KINGS_005:
			m_nVerses = 18;
			break;

		case ID_1KINGS_006:
			m_nVerses = 38;
			break;

		case ID_1KINGS_007:
			m_nVerses = 51;
			break;

		case ID_1KINGS_008:
			m_nVerses = 66;
			break;

		case ID_1KINGS_009:
			m_nVerses = 28;
			break;

		case ID_1KINGS_010:
			m_nVerses = 29;
			break;

		case ID_1KINGS_011:
			m_nVerses = 43;
			break;

		case ID_1KINGS_012:
			m_nVerses = 33;
			break;

		case ID_1KINGS_013:
			m_nVerses = 34;
			break;

		case ID_1KINGS_014:
			m_nVerses = 31;
			break;

		case ID_1KINGS_015:
			m_nVerses = 34;
			break;

		case ID_1KINGS_016:
			m_nVerses = 34;
			break;

		case ID_1KINGS_017:
			m_nVerses = 24;
			break;

		case ID_1KINGS_018:
			m_nVerses = 46;
			break;

		case ID_1KINGS_019:
			m_nVerses = 21;
			break;

		case ID_1KINGS_020:
			m_nVerses = 43;
			break;

		case ID_1KINGS_021:
			m_nVerses = 29;
			break;

		case ID_1KINGS_022:
			m_nVerses = 53;
			break;


		case ID_2KINGS_001:
			m_nVerses = 18;
			break;

		case ID_2KINGS_002:
			m_nVerses = 25;
			break;

		case ID_2KINGS_003:
			m_nVerses = 27;
			break;

		case ID_2KINGS_004:
			m_nVerses = 44;
			break;

		case ID_2KINGS_005:
			m_nVerses = 27;
			break;

		case ID_2KINGS_006:
			m_nVerses = 33;
			break;

		case ID_2KINGS_007:
			m_nVerses = 20;
			break;

		case ID_2KINGS_008:
			m_nVerses = 29;
			break;

		case ID_2KINGS_009:
			m_nVerses = 37;
			break;

		case ID_2KINGS_010:
			m_nVerses = 36;
			break;

		case ID_2KINGS_011:
			m_nVerses = 21;
			break;

		case ID_2KINGS_012:
			m_nVerses = 21;
			break;

		case ID_2KINGS_013:
			m_nVerses = 25;
			break;

		case ID_2KINGS_014:
			m_nVerses = 29;
			break;

		case ID_2KINGS_015:
			m_nVerses = 38;
			break;

		case ID_2KINGS_016:
			m_nVerses = 20;
			break;

		case ID_2KINGS_017:
			m_nVerses = 41;
			break;

		case ID_2KINGS_018:
			m_nVerses = 37;
			break;

		case ID_2KINGS_019:
			m_nVerses = 37;
			break;

		case ID_2KINGS_020:
			m_nVerses = 21;
			break;

		case ID_2KINGS_021:
			m_nVerses = 26;
			break;

		case ID_2KINGS_022:
			m_nVerses = 20;
			break;

		case ID_2KINGS_023:
			m_nVerses = 37;
			break;

		case ID_2KINGS_024:
			m_nVerses = 20;
			break;

		case ID_2KINGS_025:
			m_nVerses = 30;
			break;


		case ID_1CHRONICLES_001:
			m_nVerses = 54;
			break;

		case ID_1CHRONICLES_002:
			m_nVerses = 55;
			break;

		case ID_1CHRONICLES_003:
			m_nVerses = 24;
			break;

		case ID_1CHRONICLES_004:
			m_nVerses = 43;
			break;

		case ID_1CHRONICLES_005:
			m_nVerses = 26;
			break;

		case ID_1CHRONICLES_006:
			m_nVerses = 81;
			break;

		case ID_1CHRONICLES_007:
			m_nVerses = 40;
			break;

		case ID_1CHRONICLES_008:
			m_nVerses = 40;
			break;

		case ID_1CHRONICLES_009:
			m_nVerses = 44;
			break;

		case ID_1CHRONICLES_010:
			m_nVerses = 14;
			break;

		case ID_1CHRONICLES_011:
			m_nVerses = 47;
			break;

		case ID_1CHRONICLES_012:
			m_nVerses = 40;
			break;

		case ID_1CHRONICLES_013:
			m_nVerses = 14;
			break;

		case ID_1CHRONICLES_014:
			m_nVerses = 17;
			break;

		case ID_1CHRONICLES_015:
			m_nVerses = 29;
			break;

		case ID_1CHRONICLES_016:
			m_nVerses = 43;
			break;

		case ID_1CHRONICLES_017:
			m_nVerses = 27;
			break;

		case ID_1CHRONICLES_018:
			m_nVerses = 17;
			break;

		case ID_1CHRONICLES_019:
			m_nVerses = 19;
			break;

		case ID_1CHRONICLES_020:
			m_nVerses = 8;
			break;

		case ID_1CHRONICLES_021:
			m_nVerses = 30;
			break;

		case ID_1CHRONICLES_022:
			m_nVerses = 19;
			break;

		case ID_1CHRONICLES_023:
			m_nVerses = 32;
			break;

		case ID_1CHRONICLES_024:
			m_nVerses = 31;
			break;

		case ID_1CHRONICLES_025:
			m_nVerses = 31;
			break;

		case ID_1CHRONICLES_026:
			m_nVerses = 32;
			break;

		case ID_1CHRONICLES_027:
			m_nVerses = 34;
			break;

		case ID_1CHRONICLES_028:
			m_nVerses = 21;
			break;

		case ID_1CHRONICLES_029:
			m_nVerses = 30;
			break;


		case ID_2CHRONICLES_001:
			m_nVerses = 17;
			break;

		case ID_2CHRONICLES_002:
			m_nVerses = 18;
			break;

		case ID_2CHRONICLES_003:
			m_nVerses = 17;
			break;

		case ID_2CHRONICLES_004:
			m_nVerses = 22;
			break;

		case ID_2CHRONICLES_005:
			m_nVerses = 14;
			break;

		case ID_2CHRONICLES_006:
			m_nVerses = 42;
			break;

		case ID_2CHRONICLES_007:
			m_nVerses = 22;
			break;

		case ID_2CHRONICLES_008:
			m_nVerses = 18;
			break;

		case ID_2CHRONICLES_009:
			m_nVerses = 31;
			break;

		case ID_2CHRONICLES_010:
			m_nVerses = 19;
			break;

		case ID_2CHRONICLES_011:
			m_nVerses = 23;
			break;

		case ID_2CHRONICLES_012:
			m_nVerses = 16;
			break;

		case ID_2CHRONICLES_013:
			m_nVerses = 22;
			break;

		case ID_2CHRONICLES_014:
			m_nVerses = 15;
			break;

		case ID_2CHRONICLES_015:
			m_nVerses = 19;
			break;

		case ID_2CHRONICLES_016:
			m_nVerses = 14;
			break;

		case ID_2CHRONICLES_017:
			m_nVerses = 19;
			break;

		case ID_2CHRONICLES_018:
			m_nVerses = 34;
			break;

		case ID_2CHRONICLES_019:
			m_nVerses = 11;
			break;

		case ID_2CHRONICLES_020:
			m_nVerses = 37;
			break;

		case ID_2CHRONICLES_021:
			m_nVerses = 20;
			break;

		case ID_2CHRONICLES_022:
			m_nVerses = 12;
			break;

		case ID_2CHRONICLES_023:
			m_nVerses = 21;
			break;

		case ID_2CHRONICLES_024:
			m_nVerses = 27;
			break;

		case ID_2CHRONICLES_025:
			m_nVerses = 28;
			break;

		case ID_2CHRONICLES_026:
			m_nVerses = 23;
			break;

		case ID_2CHRONICLES_027:
			m_nVerses = 9;
			break;

		case ID_2CHRONICLES_028:
			m_nVerses = 27;
			break;

		case ID_2CHRONICLES_029:
			m_nVerses = 36;
			break;

		case ID_2CHRONICLES_030:
			m_nVerses = 27;
			break;

		case ID_2CHRONICLES_031:
			m_nVerses = 21;
			break;

		case ID_2CHRONICLES_032:
			m_nVerses = 33;
			break;

		case ID_2CHRONICLES_033:
			m_nVerses = 25;
			break;

		case ID_2CHRONICLES_034:
			m_nVerses = 33;
			break;

		case ID_2CHRONICLES_035:
			m_nVerses = 27;
			break;

		case ID_2CHRONICLES_036:
			m_nVerses = 23;
			break;


		case ID_EZRA_001:
			m_nVerses = 11;
			break;

		case ID_EZRA_002:
			m_nVerses = 70;
			break;

		case ID_EZRA_003:
			m_nVerses = 13;
			break;

		case ID_EZRA_004:
			m_nVerses = 24;
			break;

		case ID_EZRA_005:
			m_nVerses = 17;
			break;

		case ID_EZRA_006:
			m_nVerses = 22;
			break;

		case ID_EZRA_007:
			m_nVerses = 28;
			break;

		case ID_EZRA_008:
			m_nVerses = 36;
			break;

		case ID_EZRA_009:
			m_nVerses = 15;
			break;

		case ID_EZRA_010:
			m_nVerses = 44;
			break;


		case ID_NEHEMIAH_001:
			m_nVerses = 11;
			break;

		case ID_NEHEMIAH_002:
			m_nVerses = 20;
			break;

		case ID_NEHEMIAH_003:
			m_nVerses = 32;
			break;

		case ID_NEHEMIAH_004:
			m_nVerses = 23;
			break;

		case ID_NEHEMIAH_005:
			m_nVerses = 19;
			break;

		case ID_NEHEMIAH_006:
			m_nVerses = 19;
			break;

		case ID_NEHEMIAH_007:
			m_nVerses = 73;
			break;

		case ID_NEHEMIAH_008:
			m_nVerses = 18;
			break;

		case ID_NEHEMIAH_009:
			m_nVerses = 38;
			break;

		case ID_NEHEMIAH_010:
			m_nVerses = 39;
			break;

		case ID_NEHEMIAH_011:
			m_nVerses = 36;
			break;

		case ID_NEHEMIAH_012:
			m_nVerses = 47;
			break;

		case ID_NEHEMIAH_013:
			m_nVerses = 31;
			break;


		case ID_ESTHER_001:
			m_nVerses = 22;
			break;

		case ID_ESTHER_002:
			m_nVerses = 23;
			break;

		case ID_ESTHER_003:
			m_nVerses = 15;
			break;

		case ID_ESTHER_004:
			m_nVerses = 17;
			break;

		case ID_ESTHER_005:
			m_nVerses = 14;
			break;

		case ID_ESTHER_006:
			m_nVerses = 14;
			break;

		case ID_ESTHER_007:
			m_nVerses = 10;
			break;

		case ID_ESTHER_008:
			m_nVerses = 17;
			break;

		case ID_ESTHER_009:
			m_nVerses = 32;
			break;

		case ID_ESTHER_010:
			m_nVerses = 3;
			break;


		case ID_JOB_001:
			m_nVerses = 22;
			break;

		case ID_JOB_002:
			m_nVerses = 13;
			break;

		case ID_JOB_003:
			m_nVerses = 26;
			break;

		case ID_JOB_004:
			m_nVerses = 21;
			break;

		case ID_JOB_005:
			m_nVerses = 27;
			break;

		case ID_JOB_006:
			m_nVerses = 30;
			break;

		case ID_JOB_007:
			m_nVerses = 21;
			break;

		case ID_JOB_008:
			m_nVerses = 22;
			break;

		case ID_JOB_009:
			m_nVerses = 35;
			break;

		case ID_JOB_010:
			m_nVerses = 22;
			break;

		case ID_JOB_011:
			m_nVerses = 20;
			break;

		case ID_JOB_012:
			m_nVerses = 25;
			break;

		case ID_JOB_013:
			m_nVerses = 28;
			break;

		case ID_JOB_014:
			m_nVerses = 22;
			break;

		case ID_JOB_015:
			m_nVerses = 35;
			break;

		case ID_JOB_016:
			m_nVerses = 22;
			break;

		case ID_JOB_017:
			m_nVerses = 16;
			break;

		case ID_JOB_018:
			m_nVerses = 21;
			break;

		case ID_JOB_019:
			m_nVerses = 29;
			break;

		case ID_JOB_020:
			m_nVerses = 29;
			break;

		case ID_JOB_021:
			m_nVerses = 34;
			break;

		case ID_JOB_022:
			m_nVerses = 30;
			break;

		case ID_JOB_023:
			m_nVerses = 17;
			break;

		case ID_JOB_024:
			m_nVerses = 25;
			break;

		case ID_JOB_025:
			m_nVerses = 6;
			break;

		case ID_JOB_026:
			m_nVerses = 14;
			break;

		case ID_JOB_027:
			m_nVerses = 23;
			break;

		case ID_JOB_028:
			m_nVerses = 28;
			break;

		case ID_JOB_029:
			m_nVerses = 25;
			break;

		case ID_JOB_030:
			m_nVerses = 31;
			break;

		case ID_JOB_031:
			m_nVerses = 40;
			break;

		case ID_JOB_032:
			m_nVerses = 22;
			break;

		case ID_JOB_033:
			m_nVerses = 33;
			break;

		case ID_JOB_034:
			m_nVerses = 37;
			break;

		case ID_JOB_035:
			m_nVerses = 16;
			break;

		case ID_JOB_036:
			m_nVerses = 33;
			break;

		case ID_JOB_037:
			m_nVerses = 24;
			break;

		case ID_JOB_038:
			m_nVerses = 41;
			break;

		case ID_JOB_039:
			m_nVerses = 30;
			break;

		case ID_JOB_040:
			m_nVerses = 24;
			break;

		case ID_JOB_041:
			m_nVerses = 34;
			break;

		case ID_JOB_042:
			m_nVerses = 17;
			break;


		case ID_PSALM_001:
			m_nVerses = 6;
			break;

		case ID_PSALM_002:
			m_nVerses = 12;
			break;

		case ID_PSALM_003:
			m_nVerses = 8;
			break;

		case ID_PSALM_004:
			m_nVerses = 8;
			break;

		case ID_PSALM_005:
			m_nVerses = 12;
			break;

		case ID_PSALM_006:
			m_nVerses = 10;
			break;

		case ID_PSALM_007:
			m_nVerses = 9;
			break;

		case ID_PSALM_008:
			m_nVerses = 20;
			break;

		case ID_PSALM_009:
			m_nVerses = 18;
			break;

		case ID_PSALM_010:
			m_nVerses = 7;
			break;

		case ID_PSALM_011:
			m_nVerses = 8;
			break;

		case ID_PSALM_012:
			m_nVerses = 6;
			break;

		case ID_PSALM_013:
			m_nVerses = 7;
			break;

		case ID_PSALM_014:
			m_nVerses = 5;
			break;

		case ID_PSALM_015:
			m_nVerses = 11;
			break;

		case ID_PSALM_016:
			m_nVerses = 15;
			break;

		case ID_PSALM_017:
			m_nVerses = 50;
			break;

		case ID_PSALM_018:
			m_nVerses = 9;
			break;

		case ID_PSALM_019:
			m_nVerses = 14;
			break;

		case ID_PSALM_020:
			m_nVerses = 9;
			break;

		case ID_PSALM_021:
			m_nVerses = 13;
			break;

		case ID_PSALM_022:
			m_nVerses = 31;
			break;

		case ID_PSALM_023:
			m_nVerses = 6;
			break;

		case ID_PSALM_024:
			m_nVerses = 10;
			break;

		case ID_PSALM_025:
			m_nVerses = 22;
			break;

		case ID_PSALM_026:
			m_nVerses = 12;
			break;

		case ID_PSALM_027:
			m_nVerses = 14;
			break;

		case ID_PSALM_028:
			m_nVerses = 9;
			break;

		case ID_PSALM_029:
			m_nVerses = 11;
			break;

		case ID_PSALM_030:
			m_nVerses = 12;
			break;

		case ID_PSALM_031:
			m_nVerses = 24;
			break;

		case ID_PSALM_032:
			m_nVerses = 11;
			break;

		case ID_PSALM_033:
			m_nVerses = 22;
			break;

		case ID_PSALM_034:
			m_nVerses = 22;
			break;

		case ID_PSALM_035:
			m_nVerses = 28;
			break;

		case ID_PSALM_036:
			m_nVerses = 12;
			break;

		case ID_PSALM_037:
			m_nVerses = 40;
			break;

		case ID_PSALM_038:
			m_nVerses = 22;
			break;

		case ID_PSALM_039:
			m_nVerses = 13;
			break;

		case ID_PSALM_040:
			m_nVerses = 17;
			break;

		case ID_PSALM_041:
			m_nVerses = 13;
			break;

		case ID_PSALM_042:
			m_nVerses = 11;
			break;

		case ID_PSALM_043:
			m_nVerses = 5;
			break;

		case ID_PSALM_044:
			m_nVerses = 26;
			break;

		case ID_PSALM_045:
			m_nVerses = 17;
			break;

		case ID_PSALM_046:
			m_nVerses = 11;
			break;

		case ID_PSALM_047:
			m_nVerses = 9;
			break;

		case ID_PSALM_048:
			m_nVerses = 14;
			break;

		case ID_PSALM_049:
			m_nVerses = 20;
			break;

		case ID_PSALM_050:
			m_nVerses = 23;
			break;

		case ID_PSALM_051:
			m_nVerses = 19;
			break;

		case ID_PSALM_052:
			m_nVerses = 9;
			break;

		case ID_PSALM_053:
			m_nVerses = 6;
			break;

		case ID_PSALM_054:
			m_nVerses = 7;
			break;

		case ID_PSALM_055:
			m_nVerses = 23;
			break;

		case ID_PSALM_056:
			m_nVerses = 13;
			break;

		case ID_PSALM_057:
			m_nVerses = 11;
			break;

		case ID_PSALM_058:
			m_nVerses = 11;
			break;

		case ID_PSALM_059:
			m_nVerses = 17;
			break;

		case ID_PSALM_060:
			m_nVerses = 12;
			break;

		case ID_PSALM_061:
			m_nVerses = 8;
			break;

		case ID_PSALM_062:
			m_nVerses = 12;
			break;

		case ID_PSALM_063:
			m_nVerses = 11;
			break;

		case ID_PSALM_064:
			m_nVerses = 10;
			break;

		case ID_PSALM_065:
			m_nVerses = 13;
			break;

		case ID_PSALM_066:
			m_nVerses = 20;
			break;

		case ID_PSALM_067:
			m_nVerses = 7;
			break;

		case ID_PSALM_068:
			m_nVerses = 35;
			break;

		case ID_PSALM_069:
			m_nVerses = 36;
			break;

		case ID_PSALM_070:
			m_nVerses = 5;
			break;

		case ID_PSALM_071:
			m_nVerses = 24;
			break;

		case ID_PSALM_072:
			m_nVerses = 20;
			break;

		case ID_PSALM_073:
			m_nVerses = 28;
			break;

		case ID_PSALM_074:
			m_nVerses = 23;
			break;

		case ID_PSALM_075:
			m_nVerses = 10;
			break;

		case ID_PSALM_076:
			m_nVerses = 12;
			break;

		case ID_PSALM_077:
			m_nVerses = 20;
			break;

		case ID_PSALM_078:
			m_nVerses = 72;
			break;

		case ID_PSALM_079:
			m_nVerses = 13;
			break;

		case ID_PSALM_080:
			m_nVerses = 19;
			break;

		case ID_PSALM_081:
			m_nVerses = 16;
			break;

		case ID_PSALM_082:
			m_nVerses = 8;
			break;

		case ID_PSALM_083:
			m_nVerses = 18;
			break;

		case ID_PSALM_084:
			m_nVerses = 12;
			break;

		case ID_PSALM_085:
			m_nVerses = 13;
			break;

		case ID_PSALM_086:
			m_nVerses = 17;
			break;

		case ID_PSALM_087:
			m_nVerses = 7;
			break;

		case ID_PSALM_088:
			m_nVerses = 18;
			break;

		case ID_PSALM_089:
			m_nVerses = 52;
			break;

		case ID_PSALM_090:
			m_nVerses = 17;
			break;

		case ID_PSALM_091:
			m_nVerses = 16;
			break;

		case ID_PSALM_092:
			m_nVerses = 15;
			break;

		case ID_PSALM_093:
			m_nVerses = 5;
			break;

		case ID_PSALM_094:
			m_nVerses = 23;
			break;

		case ID_PSALM_095:
			m_nVerses = 11;
			break;

		case ID_PSALM_096:
			m_nVerses = 13;
			break;

		case ID_PSALM_097:
			m_nVerses = 12;
			break;

		case ID_PSALM_098:
			m_nVerses = 9;
			break;

		case ID_PSALM_099:
			m_nVerses = 9;
			break;

		case ID_PSALM_100:
			m_nVerses = 5;
			break;

		case ID_PSALM_101:
			m_nVerses = 8;
			break;

		case ID_PSALM_102:
			m_nVerses = 28;
			break;

		case ID_PSALM_103:
			m_nVerses = 22;
			break;

		case ID_PSALM_104:
			m_nVerses = 35;
			break;

		case ID_PSALM_105:
			m_nVerses = 45;
			break;

		case ID_PSALM_106:
			m_nVerses = 48;
			break;

		case ID_PSALM_107:
			m_nVerses = 43;
			break;

		case ID_PSALM_108:
			m_nVerses = 13;
			break;

		case ID_PSALM_109:
			m_nVerses = 31;
			break;

		case ID_PSALM_110:
			m_nVerses = 7;
			break;

		case ID_PSALM_111:
			m_nVerses = 10;
			break;

		case ID_PSALM_112:
			m_nVerses = 10;
			break;

		case ID_PSALM_113:
			m_nVerses = 9;
			break;

		case ID_PSALM_114:
			m_nVerses = 8;
			break;

		case ID_PSALM_115:
			m_nVerses = 18;
			break;

		case ID_PSALM_116:
			m_nVerses = 19;
			break;

		case ID_PSALM_117:
			m_nVerses = 2;
			break;

		case ID_PSALM_118:
			m_nVerses = 29;
			break;

		case ID_PSALM_119:
			m_nVerses = 176;
			break;

		case ID_PSALM_120:
			m_nVerses = 7;
			break;

		case ID_PSALM_121:
			m_nVerses = 8;
			break;

		case ID_PSALM_122:
			m_nVerses = 9;
			break;

		case ID_PSALM_123:
			m_nVerses = 4;
			break;

		case ID_PSALM_124:
			m_nVerses = 8;
			break;

		case ID_PSALM_125:
			m_nVerses = 5;
			break;

		case ID_PSALM_126:
			m_nVerses = 6;
			break;

		case ID_PSALM_127:
			m_nVerses = 5;
			break;

		case ID_PSALM_128:
			m_nVerses = 6;
			break;

		case ID_PSALM_129:
			m_nVerses = 8;
			break;

		case ID_PSALM_130:
			m_nVerses = 8;
			break;

		case ID_PSALM_131:
			m_nVerses = 3;
			break;

		case ID_PSALM_132:
			m_nVerses = 18;
			break;

		case ID_PSALM_133:
			m_nVerses = 3;
			break;

		case ID_PSALM_134:
			m_nVerses = 3;
			break;

		case ID_PSALM_135:
			m_nVerses = 21;
			break;

		case ID_PSALM_136:
			m_nVerses = 26;
			break;

		case ID_PSALM_137:
			m_nVerses = 9;
			break;

		case ID_PSALM_138:
			m_nVerses = 8;
			break;

		case ID_PSALM_139:
			m_nVerses = 24;
			break;

		case ID_PSALM_140:
			m_nVerses = 13;
			break;

		case ID_PSALM_141:
			m_nVerses = 10;
			break;

		case ID_PSALM_142:
			m_nVerses = 7;
			break;

		case ID_PSALM_143:
			m_nVerses = 12;
			break;

		case ID_PSALM_144:
			m_nVerses = 15;
			break;

		case ID_PSALM_145:
			m_nVerses = 21;
			break;

		case ID_PSALM_146:
			m_nVerses = 10;
			break;

		case ID_PSALM_147:
			m_nVerses = 20;
			break;

		case ID_PSALM_148:
			m_nVerses = 14;
			break;

		case ID_PSALM_149:
			m_nVerses = 9;
			break;

		case ID_PSALM_150:
			m_nVerses = 6;
			break;


		case ID_PROVERBS_001:
			m_nVerses = 33;
			break;

		case ID_PROVERBS_002:
			m_nVerses = 22;
			break;

		case ID_PROVERBS_003:
			m_nVerses = 35;
			break;

		case ID_PROVERBS_004:
			m_nVerses = 27;
			break;

		case ID_PROVERBS_005:
			m_nVerses = 23;
			break;

		case ID_PROVERBS_006:
			m_nVerses = 35;
			break;

		case ID_PROVERBS_007:
			m_nVerses = 27;
			break;

		case ID_PROVERBS_008:
			m_nVerses = 36;
			break;

		case ID_PROVERBS_009:
			m_nVerses = 18;
			break;

		case ID_PROVERBS_010:
			m_nVerses = 32;
			break;

		case ID_PROVERBS_011:
			m_nVerses = 31;
			break;

		case ID_PROVERBS_012:
			m_nVerses = 28;
			break;

		case ID_PROVERBS_013:
			m_nVerses = 25;
			break;

		case ID_PROVERBS_014:
			m_nVerses = 35;
			break;

		case ID_PROVERBS_015:
			m_nVerses = 33;
			break;

		case ID_PROVERBS_016:
			m_nVerses = 33;
			break;

		case ID_PROVERBS_017:
			m_nVerses = 28;
			break;

		case ID_PROVERBS_018:
			m_nVerses = 24;
			break;

		case ID_PROVERBS_019:
			m_nVerses = 29;
			break;

		case ID_PROVERBS_020:
			m_nVerses = 30;
			break;

		case ID_PROVERBS_021:
			m_nVerses = 31;
			break;

		case ID_PROVERBS_022:
			m_nVerses = 29;
			break;

		case ID_PROVERBS_023:
			m_nVerses = 35;
			break;

		case ID_PROVERBS_024:
			m_nVerses = 34;
			break;

		case ID_PROVERBS_025:
			m_nVerses = 28;
			break;

		case ID_PROVERBS_026:
			m_nVerses = 28;
			break;

		case ID_PROVERBS_027:
			m_nVerses = 27;
			break;

		case ID_PROVERBS_028:
			m_nVerses = 28;
			break;

		case ID_PROVERBS_029:
			m_nVerses = 27;
			break;

		case ID_PROVERBS_030:
			m_nVerses = 33;
			break;

		case ID_PROVERBS_031:
			m_nVerses = 31;
			break;


		case ID_ECCLESIASTES_001:
			m_nVerses = 18;
			break;

		case ID_ECCLESIASTES_002:
			m_nVerses = 26;
			break;

		case ID_ECCLESIASTES_003:
			m_nVerses = 22;
			break;

		case ID_ECCLESIASTES_004:
			m_nVerses = 16;
			break;

		case ID_ECCLESIASTES_005:
			m_nVerses = 20;
			break;

		case ID_ECCLESIASTES_006:
			m_nVerses = 12;
			break;

		case ID_ECCLESIASTES_007:
			m_nVerses = 29;
			break;

		case ID_ECCLESIASTES_008:
			m_nVerses = 17;
			break;

		case ID_ECCLESIASTES_009:
			m_nVerses = 18;
			break;

		case ID_ECCLESIASTES_010:
			m_nVerses = 20;
			break;

		case ID_ECCLESIASTES_011:
			m_nVerses = 10;
			break;

		case ID_ECCLESIASTES_012:
			m_nVerses = 14;
			break;


		case ID_SONGS_001:
			m_nVerses = 17;
			break;

		case ID_SONGS_002:
			m_nVerses = 17;
			break;

		case ID_SONGS_003:
			m_nVerses = 11;
			break;

		case ID_SONGS_004:
			m_nVerses = 16;
			break;

		case ID_SONGS_005:
			m_nVerses = 16;
			break;

		case ID_SONGS_006:
			m_nVerses = 13;
			break;

		case ID_SONGS_007:
			m_nVerses = 13;
			break;

		case ID_SONGS_008:
			m_nVerses = 14;
			break;


		case ID_ISAIAH_001:
			m_nVerses = 31;
			break;

		case ID_ISAIAH_002:
			m_nVerses = 22;
			break;

		case ID_ISAIAH_003:
			m_nVerses = 26;
			break;

		case ID_ISAIAH_004:
			m_nVerses = 6;
			break;

		case ID_ISAIAH_005:
			m_nVerses = 30;
			break;

		case ID_ISAIAH_006:
			m_nVerses = 13;
			break;

		case ID_ISAIAH_007:
			m_nVerses = 25;
			break;

		case ID_ISAIAH_008:
			m_nVerses = 22;
			break;

		case ID_ISAIAH_009:
			m_nVerses = 21;
			break;

		case ID_ISAIAH_010:
			m_nVerses = 34;
			break;

		case ID_ISAIAH_011:
			m_nVerses = 16;
			break;

		case ID_ISAIAH_012:
			m_nVerses = 6;
			break;

		case ID_ISAIAH_013:
			m_nVerses = 22;
			break;

		case ID_ISAIAH_014:
			m_nVerses = 32;
			break;

		case ID_ISAIAH_015:
			m_nVerses = 9;
			break;

		case ID_ISAIAH_016:
			m_nVerses = 14;
			break;

		case ID_ISAIAH_017:
			m_nVerses = 14;
			break;

		case ID_ISAIAH_018:
			m_nVerses = 7;
			break;

		case ID_ISAIAH_019:
			m_nVerses = 25;
			break;

		case ID_ISAIAH_020:
			m_nVerses = 6;
			break;

		case ID_ISAIAH_021:
			m_nVerses = 17;
			break;

		case ID_ISAIAH_022:
			m_nVerses = 25;
			break;

		case ID_ISAIAH_023:
			m_nVerses = 18;
			break;

		case ID_ISAIAH_024:
			m_nVerses = 23;
			break;

		case ID_ISAIAH_025:
			m_nVerses = 12;
			break;

		case ID_ISAIAH_026:
			m_nVerses = 21;
			break;

		case ID_ISAIAH_027:
			m_nVerses = 13;
			break;

		case ID_ISAIAH_028:
			m_nVerses = 29;
			break;

		case ID_ISAIAH_029:
			m_nVerses = 24;
			break;

		case ID_ISAIAH_030:
			m_nVerses = 33;
			break;

		case ID_ISAIAH_031:
			m_nVerses = 9;
			break;

		case ID_ISAIAH_032:
			m_nVerses = 20;
			break;

		case ID_ISAIAH_033:
			m_nVerses = 24;
			break;

		case ID_ISAIAH_034:
			m_nVerses = 17;
			break;

		case ID_ISAIAH_035:
			m_nVerses = 10;
			break;

		case ID_ISAIAH_036:
			m_nVerses = 22;
			break;

		case ID_ISAIAH_037:
			m_nVerses = 38;
			break;

		case ID_ISAIAH_038:
			m_nVerses = 22;
			break;

		case ID_ISAIAH_039:
			m_nVerses = 8;
			break;

		case ID_ISAIAH_040:
			m_nVerses = 31;
			break;

		case ID_ISAIAH_041:
			m_nVerses = 29;
			break;

		case ID_ISAIAH_042:
			m_nVerses = 25;
			break;

		case ID_ISAIAH_043:
			m_nVerses = 28;
			break;

		case ID_ISAIAH_044:
			m_nVerses = 28;
			break;

		case ID_ISAIAH_045:
			m_nVerses = 25;
			break;

		case ID_ISAIAH_046:
			m_nVerses = 13;
			break;

		case ID_ISAIAH_047:
			m_nVerses = 15;
			break;

		case ID_ISAIAH_048:
			m_nVerses = 22;
			break;

		case ID_ISAIAH_049:
			m_nVerses = 26;
			break;

		case ID_ISAIAH_050:
			m_nVerses = 11;
			break;

		case ID_ISAIAH_051:
			m_nVerses = 23;
			break;

		case ID_ISAIAH_052:
			m_nVerses = 15;
			break;

		case ID_ISAIAH_053:
			m_nVerses = 12;
			break;

		case ID_ISAIAH_054:
			m_nVerses = 17;
			break;

		case ID_ISAIAH_055:
			m_nVerses = 13;
			break;

		case ID_ISAIAH_056:
			m_nVerses = 12;
			break;

		case ID_ISAIAH_057:
			m_nVerses = 21;
			break;

		case ID_ISAIAH_058:
			m_nVerses = 14;
			break;

		case ID_ISAIAH_059:
			m_nVerses = 21;
			break;

		case ID_ISAIAH_060:
			m_nVerses = 22;
			break;

		case ID_ISAIAH_061:
			m_nVerses = 11;
			break;

		case ID_ISAIAH_062:
			m_nVerses = 12;
			break;

		case ID_ISAIAH_063:
			m_nVerses = 19;
			break;

		case ID_ISAIAH_064:
			m_nVerses = 12;
			break;

		case ID_ISAIAH_065:
			m_nVerses = 25;
			break;

		case ID_ISAIAH_066:
			m_nVerses = 24;
			break;


		case ID_JEREMIAH_001:
			m_nVerses = 19;
			break;

		case ID_JEREMIAH_002:
			m_nVerses = 37;
			break;

		case ID_JEREMIAH_003:
			m_nVerses = 25;
			break;

		case ID_JEREMIAH_004:
			m_nVerses = 31;
			break;

		case ID_JEREMIAH_005:
			m_nVerses = 31;
			break;

		case ID_JEREMIAH_006:
			m_nVerses = 30;
			break;

		case ID_JEREMIAH_007:
			m_nVerses = 34;
			break;

		case ID_JEREMIAH_008:
			m_nVerses = 22;
			break;

		case ID_JEREMIAH_009:
			m_nVerses = 26;
			break;

		case ID_JEREMIAH_010:
			m_nVerses = 25;
			break;

		case ID_JEREMIAH_011:
			m_nVerses = 23;
			break;

		case ID_JEREMIAH_012:
			m_nVerses = 17;
			break;

		case ID_JEREMIAH_013:
			m_nVerses = 27;
			break;

		case ID_JEREMIAH_014:
			m_nVerses = 22;
			break;

		case ID_JEREMIAH_015:
			m_nVerses = 21;
			break;

		case ID_JEREMIAH_016:
			m_nVerses = 21;
			break;

		case ID_JEREMIAH_017:
			m_nVerses = 27;
			break;

		case ID_JEREMIAH_018:
			m_nVerses = 23;
			break;

		case ID_JEREMIAH_019:
			m_nVerses = 15;
			break;

		case ID_JEREMIAH_020:
			m_nVerses = 18;
			break;

		case ID_JEREMIAH_021:
			m_nVerses = 14;
			break;

		case ID_JEREMIAH_022:
			m_nVerses = 30;
			break;

		case ID_JEREMIAH_023:
			m_nVerses = 40;
			break;

		case ID_JEREMIAH_024:
			m_nVerses = 10;
			break;

		case ID_JEREMIAH_025:
			m_nVerses = 38;
			break;

		case ID_JEREMIAH_026:
			m_nVerses = 24;
			break;

		case ID_JEREMIAH_027:
			m_nVerses = 22;
			break;

		case ID_JEREMIAH_028:
			m_nVerses = 17;
			break;

		case ID_JEREMIAH_029:
			m_nVerses = 32;
			break;

		case ID_JEREMIAH_030:
			m_nVerses = 24;
			break;

		case ID_JEREMIAH_031:
			m_nVerses = 40;
			break;

		case ID_JEREMIAH_032:
			m_nVerses = 44;
			break;

		case ID_JEREMIAH_033:
			m_nVerses = 26;
			break;

		case ID_JEREMIAH_034:
			m_nVerses = 22;
			break;

		case ID_JEREMIAH_035:
			m_nVerses = 19;
			break;

		case ID_JEREMIAH_036:
			m_nVerses = 32;
			break;

		case ID_JEREMIAH_037:
			m_nVerses = 21;
			break;

		case ID_JEREMIAH_038:
			m_nVerses = 28;
			break;

		case ID_JEREMIAH_039:
			m_nVerses = 18;
			break;

		case ID_JEREMIAH_040:
			m_nVerses = 16;
			break;

		case ID_JEREMIAH_041:
			m_nVerses = 18;
			break;

		case ID_JEREMIAH_042:
			m_nVerses = 22;
			break;

		case ID_JEREMIAH_043:
			m_nVerses = 13;
			break;

		case ID_JEREMIAH_044:
			m_nVerses = 30;
			break;

		case ID_JEREMIAH_045:
			m_nVerses = 5;
			break;

		case ID_JEREMIAH_046:
			m_nVerses = 28;
			break;

		case ID_JEREMIAH_047:
			m_nVerses = 7;
			break;

		case ID_JEREMIAH_048:
			m_nVerses = 47;
			break;

		case ID_JEREMIAH_049:
			m_nVerses = 39;
			break;

		case ID_JEREMIAH_050:
			m_nVerses = 46;
			break;

		case ID_JEREMIAH_051:
			m_nVerses = 64;
			break;

		case ID_JEREMIAH_052:
			m_nVerses = 34;
			break;


		case ID_LAMENTATIONS_001:
			m_nVerses = 22;
			break;

		case ID_LAMENTATIONS_002:
			m_nVerses = 22;
			break;

		case ID_LAMENTATIONS_003:
			m_nVerses = 66;
			break;

		case ID_LAMENTATIONS_004:
			m_nVerses = 22;
			break;

		case ID_LAMENTATIONS_005:
			m_nVerses = 22;
			break;


		case ID_EZEKIEL_001:
			m_nVerses = 28;
			break;

		case ID_EZEKIEL_002:
			m_nVerses = 10;
			break;

		case ID_EZEKIEL_003:
			m_nVerses = 27;
			break;

		case ID_EZEKIEL_004:
			m_nVerses = 17;
			break;

		case ID_EZEKIEL_005:
			m_nVerses = 17;
			break;

		case ID_EZEKIEL_006:
			m_nVerses = 14;
			break;

		case ID_EZEKIEL_007:
			m_nVerses = 27;
			break;

		case ID_EZEKIEL_008:
			m_nVerses = 18;
			break;

		case ID_EZEKIEL_009:
			m_nVerses = 11;
			break;

		case ID_EZEKIEL_010:
			m_nVerses = 22;
			break;

		case ID_EZEKIEL_011:
			m_nVerses = 25;
			break;

		case ID_EZEKIEL_012:
			m_nVerses = 28;
			break;

		case ID_EZEKIEL_013:
			m_nVerses = 23;
			break;

		case ID_EZEKIEL_014:
			m_nVerses = 23;
			break;

		case ID_EZEKIEL_015:
			m_nVerses = 8;
			break;

		case ID_EZEKIEL_016:
			m_nVerses = 63;
			break;

		case ID_EZEKIEL_017:
			m_nVerses = 24;
			break;

		case ID_EZEKIEL_018:
			m_nVerses = 32;
			break;

		case ID_EZEKIEL_019:
			m_nVerses = 14;
			break;

		case ID_EZEKIEL_020:
			m_nVerses = 49;
			break;

		case ID_EZEKIEL_021:
			m_nVerses = 32;
			break;

		case ID_EZEKIEL_022:
			m_nVerses = 31;
			break;

		case ID_EZEKIEL_023:
			m_nVerses = 49;
			break;

		case ID_EZEKIEL_024:
			m_nVerses = 27;
			break;

		case ID_EZEKIEL_025:
			m_nVerses = 17;
			break;

		case ID_EZEKIEL_026:
			m_nVerses = 21;
			break;

		case ID_EZEKIEL_027:
			m_nVerses = 36;
			break;

		case ID_EZEKIEL_028:
			m_nVerses = 26;
			break;

		case ID_EZEKIEL_029:
			m_nVerses = 21;
			break;

		case ID_EZEKIEL_030:
			m_nVerses = 26;
			break;

		case ID_EZEKIEL_031:
			m_nVerses = 18;
			break;

		case ID_EZEKIEL_032:
			m_nVerses = 32;
			break;

		case ID_EZEKIEL_033:
			m_nVerses = 33;
			break;

		case ID_EZEKIEL_034:
			m_nVerses = 31;
			break;

		case ID_EZEKIEL_035:
			m_nVerses = 15;
			break;

		case ID_EZEKIEL_036:
			m_nVerses = 38;
			break;

		case ID_EZEKIEL_037:
			m_nVerses = 28;
			break;

		case ID_EZEKIEL_038:
			m_nVerses = 23;
			break;

		case ID_EZEKIEL_039:
			m_nVerses = 29;
			break;

		case ID_EZEKIEL_040:
			m_nVerses = 49;
			break;

		case ID_EZEKIEL_041:
			m_nVerses = 26;
			break;

		case ID_EZEKIEL_042:
			m_nVerses = 20;
			break;

		case ID_EZEKIEL_043:
			m_nVerses = 27;
			break;

		case ID_EZEKIEL_044:
			m_nVerses = 31;
			break;

		case ID_EZEKIEL_045:
			m_nVerses = 25;
			break;

		case ID_EZEKIEL_046:
			m_nVerses = 24;
			break;

		case ID_EZEKIEL_047:
			m_nVerses = 23;
			break;

		case ID_EZEKIEL_048:
			m_nVerses = 35;
			break;


		case ID_DANIEL_001:
			m_nVerses = 21;
			break;

		case ID_DANIEL_002:
			m_nVerses = 49;
			break;

		case ID_DANIEL_003:
			m_nVerses = 30;
			break;

		case ID_DANIEL_004:
			m_nVerses = 37;
			break;

		case ID_DANIEL_005:
			m_nVerses = 31;
			break;

		case ID_DANIEL_006:
			m_nVerses = 28;
			break;

		case ID_DANIEL_007:
			m_nVerses = 28;
			break;

		case ID_DANIEL_008:
			m_nVerses = 27;
			break;

		case ID_DANIEL_009:
			m_nVerses = 27;
			break;

		case ID_DANIEL_010:
			m_nVerses = 21;
			break;

		case ID_DANIEL_011:
			m_nVerses = 45;
			break;

		case ID_DANIEL_012:
			m_nVerses = 13;
			break;


		case ID_HOSEA_001:
			m_nVerses = 11;
			break;

		case ID_HOSEA_002:
			m_nVerses = 23;
			break;

		case ID_HOSEA_003:
			m_nVerses = 5;
			break;

		case ID_HOSEA_004:
			m_nVerses = 19;
			break;

		case ID_HOSEA_005:
			m_nVerses = 15;
			break;

		case ID_HOSEA_006:
			m_nVerses = 11;
			break;

		case ID_HOSEA_007:
			m_nVerses = 16;
			break;

		case ID_HOSEA_008:
			m_nVerses = 14;
			break;

		case ID_HOSEA_009:
			m_nVerses = 17;
			break;

		case ID_HOSEA_010:
			m_nVerses = 15;
			break;

		case ID_HOSEA_011:
			m_nVerses = 12;
			break;

		case ID_HOSEA_012:
			m_nVerses = 14;
			break;

		case ID_HOSEA_013:
			m_nVerses = 16;
			break;

		case ID_HOSEA_014:
			m_nVerses = 9;
			break;


		case ID_JOEL_001:
			m_nVerses = 20;
			break;

		case ID_JOEL_002:
			m_nVerses = 32;
			break;

		case ID_JOEL_003:
			m_nVerses = 21;
			break;


		case ID_AMOS_001:
			m_nVerses = 15;
			break;

		case ID_AMOS_002:
			m_nVerses = 16;
			break;

		case ID_AMOS_003:
			m_nVerses = 15;
			break;

		case ID_AMOS_004:
			m_nVerses = 13;
			break;

		case ID_AMOS_005:
			m_nVerses = 27;
			break;

		case ID_AMOS_006:
			m_nVerses = 14;
			break;

		case ID_AMOS_007:
			m_nVerses = 17;
			break;

		case ID_AMOS_008:
			m_nVerses = 14;
			break;

		case ID_AMOS_009:
			m_nVerses = 15;
			break;


		case ID_OBADIAH_001:
			m_nVerses = 21;
			break;


		case ID_JONAH_001:
			m_nVerses = 17;
			break;

		case ID_JONAH_002:
			m_nVerses = 10;
			break;

		case ID_JONAH_003:
			m_nVerses = 10;
			break;

		case ID_JONAH_004:
			m_nVerses = 11;
			break;


		case ID_MICAH_001:
			m_nVerses = 16;
			break;

		case ID_MICAH_002:
			m_nVerses = 13;
			break;

		case ID_MICAH_003:
			m_nVerses = 12;
			break;

		case ID_MICAH_004:
			m_nVerses = 13;
			break;

		case ID_MICAH_005:
			m_nVerses = 15;
			break;

		case ID_MICAH_006:
			m_nVerses = 16;
			break;

		case ID_MICAH_007:
			m_nVerses = 20;
			break;


		case ID_NAHUM_001:
			m_nVerses = 15;
			break;

		case ID_NAHUM_002:
			m_nVerses = 13;
			break;

		case ID_NAHUM_003:
			m_nVerses = 19;
			break;


		case ID_HABAKKUK_001:
			m_nVerses = 17;
			break;

		case ID_HABAKKUK_002:
			m_nVerses = 20;
			break;

		case ID_HABAKKUK_003:
			m_nVerses = 19;
			break;


		case ID_ZEPHANIAH_001:
			m_nVerses = 18;
			break;

		case ID_ZEPHANIAH_002:
			m_nVerses = 15;
			break;

		case ID_ZEPHANIAH_003:
			m_nVerses = 20;
			break;


		case ID_HAGGAI_001:
			m_nVerses = 15;
			break;

		case ID_HAGGAI_002:
			m_nVerses = 23;
			break;


		case ID_ZECHARIAH_001:
			m_nVerses = 21;
			break;

		case ID_ZECHARIAH_002:
			m_nVerses = 13;
			break;

		case ID_ZECHARIAH_003:
			m_nVerses = 10;
			break;

		case ID_ZECHARIAH_004:
			m_nVerses = 14;
			break;

		case ID_ZECHARIAH_005:
			m_nVerses = 11;
			break;

		case ID_ZECHARIAH_006:
			m_nVerses = 15;
			break;

		case ID_ZECHARIAH_007:
			m_nVerses = 14;
			break;

		case ID_ZECHARIAH_008:
			m_nVerses = 23;
			break;

		case ID_ZECHARIAH_009:
			m_nVerses = 17;
			break;

		case ID_ZECHARIAH_010:
			m_nVerses = 12;
			break;

		case ID_ZECHARIAH_011:
			m_nVerses = 17;
			break;

		case ID_ZECHARIAH_012:
			m_nVerses = 14;
			break;

		case ID_ZECHARIAH_013:
			m_nVerses = 9;
			break;

		case ID_ZECHARIAH_014:
			m_nVerses = 21;
			break;


		case ID_MALACHI_001:
			m_nVerses = 14;
			break;

		case ID_MALACHI_002:
			m_nVerses = 17;
			break;

		case ID_MALACHI_003:
			m_nVerses = 18;
			break;

		case ID_MALACHI_004:
			m_nVerses = 6;
			break;


		case ID_MATTHEW_001:
			m_nVerses = 25;
			break;

		case ID_MATTHEW_002:
			m_nVerses = 23;
			break;

		case ID_MATTHEW_003:
			m_nVerses = 17;
			break;

		case ID_MATTHEW_004:
			m_nVerses = 25;
			break;

		case ID_MATTHEW_005:
			m_nVerses = 48;
			break;

		case ID_MATTHEW_006:
			m_nVerses = 34;
			break;

		case ID_MATTHEW_007:
			m_nVerses = 29;
			break;

		case ID_MATTHEW_008:
			m_nVerses = 34;
			break;

		case ID_MATTHEW_009:
			m_nVerses = 38;
			break;

		case ID_MATTHEW_010:
			m_nVerses = 42;
			break;

		case ID_MATTHEW_011:
			m_nVerses = 30;
			break;

		case ID_MATTHEW_012:
			m_nVerses = 50;
			break;

		case ID_MATTHEW_013:
			m_nVerses = 58;
			break;

		case ID_MATTHEW_014:
			m_nVerses = 36;
			break;

		case ID_MATTHEW_015:
			m_nVerses = 39;
			break;

		case ID_MATTHEW_016:
			m_nVerses = 28;
			break;

		case ID_MATTHEW_017:
			m_nVerses = 27;
			break;

		case ID_MATTHEW_018:
			m_nVerses = 35;
			break;

		case ID_MATTHEW_019:
			m_nVerses = 30;
			break;

		case ID_MATTHEW_020:
			m_nVerses = 34;
			break;

		case ID_MATTHEW_021:
			m_nVerses = 46;
			break;

		case ID_MATTHEW_022:
			m_nVerses = 46;
			break;

		case ID_MATTHEW_023:
			m_nVerses = 39;
			break;

		case ID_MATTHEW_024:
			m_nVerses = 51;
			break;

		case ID_MATTHEW_025:
			m_nVerses = 46;
			break;

		case ID_MATTHEW_026:
			m_nVerses = 75;
			break;

		case ID_MATTHEW_027:
			m_nVerses = 66;
			break;

		case ID_MATTHEW_028:
			m_nVerses = 20;
			break;


		case ID_MARK_001:
			m_nVerses = 45;
			break;

		case ID_MARK_002:
			m_nVerses = 28;
			break;

		case ID_MARK_003:
			m_nVerses = 35;
			break;

		case ID_MARK_004:
			m_nVerses = 41;
			break;

		case ID_MARK_005:
			m_nVerses = 43;
			break;

		case ID_MARK_006:
			m_nVerses = 56;
			break;

		case ID_MARK_007:
			m_nVerses = 37;
			break;

		case ID_MARK_008:
			m_nVerses = 38;
			break;

		case ID_MARK_009:
			m_nVerses = 50;
			break;

		case ID_MARK_010:
			m_nVerses = 52;
			break;

		case ID_MARK_011:
			m_nVerses = 33;
			break;

		case ID_MARK_012:
			m_nVerses = 44;
			break;

		case ID_MARK_013:
			m_nVerses = 37;
			break;

		case ID_MARK_014:
			m_nVerses = 72;
			break;

		case ID_MARK_015:
			m_nVerses = 47;
			break;

		case ID_MARK_016:
			m_nVerses = 20;
			break;


		case ID_LUKE_001:
			m_nVerses = 80;
			break;

		case ID_LUKE_002:
			m_nVerses = 52;
			break;

		case ID_LUKE_003:
			m_nVerses = 38;
			break;

		case ID_LUKE_004:
			m_nVerses = 44;
			break;

		case ID_LUKE_005:
			m_nVerses = 39;
			break;

		case ID_LUKE_006:
			m_nVerses = 49;
			break;

		case ID_LUKE_007:
			m_nVerses = 50;
			break;

		case ID_LUKE_008:
			m_nVerses = 56;
			break;

		case ID_LUKE_009:
			m_nVerses = 62;
			break;

		case ID_LUKE_010:
			m_nVerses = 42;
			break;

		case ID_LUKE_011:
			m_nVerses = 54;
			break;

		case ID_LUKE_012:
			m_nVerses = 59;
			break;

		case ID_LUKE_013:
			m_nVerses = 35;
			break;

		case ID_LUKE_014:
			m_nVerses = 35;
			break;

		case ID_LUKE_015:
			m_nVerses = 32;
			break;

		case ID_LUKE_016:
			m_nVerses = 31;
			break;

		case ID_LUKE_017:
			m_nVerses = 37;
			break;

		case ID_LUKE_018:
			m_nVerses = 43;
			break;

		case ID_LUKE_019:
			m_nVerses = 48;
			break;

		case ID_LUKE_020:
			m_nVerses = 47;
			break;

		case ID_LUKE_021:
			m_nVerses = 38;
			break;

		case ID_LUKE_022:
			m_nVerses = 71;
			break;

		case ID_LUKE_023:
			m_nVerses = 56;
			break;

		case ID_LUKE_024:
			m_nVerses = 53;
			break;


		case ID_JOHN_001:
			m_nVerses = 51;
			break;

		case ID_JOHN_002:
			m_nVerses = 25;
			break;

		case ID_JOHN_003:
			m_nVerses = 36;
			break;

		case ID_JOHN_004:
			m_nVerses = 54;
			break;

		case ID_JOHN_005:
			m_nVerses = 47;
			break;

		case ID_JOHN_006:
			m_nVerses = 71;
			break;

		case ID_JOHN_007:
			m_nVerses = 53;
			break;

		case ID_JOHN_008:
			m_nVerses = 59;
			break;

		case ID_JOHN_009:
			m_nVerses = 41;
			break;

		case ID_JOHN_010:
			m_nVerses = 42;
			break;

		case ID_JOHN_011:
			m_nVerses = 57;
			break;

		case ID_JOHN_012:
			m_nVerses = 50;
			break;

		case ID_JOHN_013:
			m_nVerses = 38;
			break;

		case ID_JOHN_014:
			m_nVerses = 31;
			break;

		case ID_JOHN_015:
			m_nVerses = 27;
			break;

		case ID_JOHN_016:
			m_nVerses = 33;
			break;

		case ID_JOHN_017:
			m_nVerses = 26;
			break;

		case ID_JOHN_018:
			m_nVerses = 40;
			break;

		case ID_JOHN_019:
			m_nVerses = 42;
			break;

		case ID_JOHN_020:
			m_nVerses = 31;
			break;

		case ID_JOHN_021:
			m_nVerses = 25;
			break;


		case ID_ACTS_001:
			m_nVerses = 26;
			break;

		case ID_ACTS_002:
			m_nVerses = 47;
			break;

		case ID_ACTS_003:
			m_nVerses = 26;
			break;

		case ID_ACTS_004:
			m_nVerses = 37;
			break;

		case ID_ACTS_005:
			m_nVerses = 42;
			break;

		case ID_ACTS_006:
			m_nVerses = 15;
			break;

		case ID_ACTS_007:
			m_nVerses = 60;
			break;

		case ID_ACTS_008:
			m_nVerses = 40;
			break;

		case ID_ACTS_009:
			m_nVerses = 43;
			break;

		case ID_ACTS_010:
			m_nVerses = 48;
			break;

		case ID_ACTS_011:
			m_nVerses = 30;
			break;

		case ID_ACTS_012:
			m_nVerses = 25;
			break;

		case ID_ACTS_013:
			m_nVerses = 52;
			break;

		case ID_ACTS_014:
			m_nVerses = 28;
			break;

		case ID_ACTS_015:
			m_nVerses = 41;
			break;

		case ID_ACTS_016:
			m_nVerses = 40;
			break;

		case ID_ACTS_017:
			m_nVerses = 34;
			break;

		case ID_ACTS_018:
			m_nVerses = 28;
			break;

		case ID_ACTS_019:
			m_nVerses = 41;
			break;

		case ID_ACTS_020:
			m_nVerses = 38;
			break;

		case ID_ACTS_021:
			m_nVerses = 40;
			break;

		case ID_ACTS_022:
			m_nVerses = 30;
			break;

		case ID_ACTS_023:
			m_nVerses = 35;
			break;

		case ID_ACTS_024:
			m_nVerses = 27;
			break;

		case ID_ACTS_025:
			m_nVerses = 27;
			break;

		case ID_ACTS_026:
			m_nVerses = 32;
			break;

		case ID_ACTS_027:
			m_nVerses = 44;
			break;

		case ID_ACTS_028:
			m_nVerses = 31;
			break;


		case ID_ROMANS_001:
			m_nVerses = 32;
			break;

		case ID_ROMANS_002:
			m_nVerses = 29;
			break;

		case ID_ROMANS_003:
			m_nVerses = 31;
			break;

		case ID_ROMANS_004:
			m_nVerses = 25;
			break;

		case ID_ROMANS_005:
			m_nVerses = 21;
			break;

		case ID_ROMANS_006:
			m_nVerses = 23;
			break;

		case ID_ROMANS_007:
			m_nVerses = 25;
			break;

		case ID_ROMANS_008:
			m_nVerses = 39;
			break;

		case ID_ROMANS_009:
			m_nVerses = 33;
			break;

		case ID_ROMANS_010:
			m_nVerses = 21;
			break;

		case ID_ROMANS_011:
			m_nVerses = 36;
			break;

		case ID_ROMANS_012:
			m_nVerses = 21;
			break;

		case ID_ROMANS_013:
			m_nVerses = 14;
			break;

		case ID_ROMANS_014:
			m_nVerses = 23;
			break;

		case ID_ROMANS_015:
			m_nVerses = 33;
			break;

		case ID_ROMANS_016:
			m_nVerses = 27;
			break;


		case ID_1CORINTHIANS_001:
			m_nVerses = 31;
			break;

		case ID_1CORINTHIANS_002:
			m_nVerses = 16;
			break;

		case ID_1CORINTHIANS_003:
			m_nVerses = 23;
			break;

		case ID_1CORINTHIANS_004:
			m_nVerses = 21;
			break;

		case ID_1CORINTHIANS_005:
			m_nVerses = 13;
			break;

		case ID_1CORINTHIANS_006:
			m_nVerses = 20;
			break;

		case ID_1CORINTHIANS_007:
			m_nVerses = 40;
			break;

		case ID_1CORINTHIANS_008:
			m_nVerses = 13;
			break;

		case ID_1CORINTHIANS_009:
			m_nVerses = 27;
			break;

		case ID_1CORINTHIANS_010:
			m_nVerses = 33;
			break;

		case ID_1CORINTHIANS_011:
			m_nVerses = 34;
			break;

		case ID_1CORINTHIANS_012:
			m_nVerses = 31;
			break;

		case ID_1CORINTHIANS_013:
			m_nVerses = 13;
			break;

		case ID_1CORINTHIANS_014:
			m_nVerses = 40;
			break;

		case ID_1CORINTHIANS_015:
			m_nVerses = 58;
			break;

		case ID_1CORINTHIANS_016:
			m_nVerses = 24;
			break;


		case ID_2CORINTHIANS_001:
			m_nVerses = 24;
			break;

		case ID_2CORINTHIANS_002:
			m_nVerses = 17;
			break;

		case ID_2CORINTHIANS_003:
			m_nVerses = 18;
			break;

		case ID_2CORINTHIANS_004:
			m_nVerses = 18;
			break;

		case ID_2CORINTHIANS_005:
			m_nVerses = 21;
			break;

		case ID_2CORINTHIANS_006:
			m_nVerses = 18;
			break;

		case ID_2CORINTHIANS_007:
			m_nVerses = 16;
			break;

		case ID_2CORINTHIANS_008:
			m_nVerses = 24;
			break;

		case ID_2CORINTHIANS_009:
			m_nVerses = 15;
			break;

		case ID_2CORINTHIANS_010:
			m_nVerses = 18;
			break;

		case ID_2CORINTHIANS_011:
			m_nVerses = 33;
			break;

		case ID_2CORINTHIANS_012:
			m_nVerses = 21;
			break;

		case ID_2CORINTHIANS_013:
			m_nVerses = 14;
			break;


		case ID_GALATIANS_001:
			m_nVerses = 24;
			break;

		case ID_GALATIANS_002:
			m_nVerses = 21;
			break;

		case ID_GALATIANS_003:
			m_nVerses = 29;
			break;

		case ID_GALATIANS_004:
			m_nVerses = 31;
			break;

		case ID_GALATIANS_005:
			m_nVerses = 26;
			break;

		case ID_GALATIANS_006:
			m_nVerses = 18;
			break;


		case ID_EPHESIANS_001:
			m_nVerses = 23;
			break;

		case ID_EPHESIANS_002:
			m_nVerses = 22;
			break;

		case ID_EPHESIANS_003:
			m_nVerses = 21;
			break;

		case ID_EPHESIANS_004:
			m_nVerses = 32;
			break;

		case ID_EPHESIANS_005:
			m_nVerses = 33;
			break;

		case ID_EPHESIANS_006:
			m_nVerses = 24;
			break;


		case ID_PHILLIPIANS_001:
			m_nVerses = 30;
			break;

		case ID_PHILLIPIANS_002:
			m_nVerses = 30;
			break;

		case ID_PHILLIPIANS_003:
			m_nVerses = 21;
			break;

		case ID_PHILLIPIANS_004:
			m_nVerses = 23;
			break;


		case ID_COLOSIANS_001:
			m_nVerses = 29;
			break;

		case ID_COLOSIANS_002:
			m_nVerses = 23;
			break;

		case ID_COLOSIANS_003:
			m_nVerses = 25;
			break;

		case ID_COLOSIANS_004:
			m_nVerses = 18;
			break;


		case ID_1THESSALONIANS_001:
			m_nVerses = 10;
			break;

		case ID_1THESSALONIANS_002:
			m_nVerses = 20;
			break;

		case ID_1THESSALONIANS_003:
			m_nVerses = 13;
			break;

		case ID_1THESSALONIANS_004:
			m_nVerses = 18;
			break;

		case ID_1THESSALONIANS_005:
			m_nVerses = 28;
			break;


		case ID_2THESSALONIANS_001:
			m_nVerses = 12;
			break;

		case ID_2THESSALONIANS_002:
			m_nVerses = 17;
			break;

		case ID_2THESSALONIANS_003:
			m_nVerses = 18;
			break;


		case ID_1TIMOTHY_001:
			m_nVerses = 20;
			break;

		case ID_1TIMOTHY_002:
			m_nVerses = 15;
			break;

		case ID_1TIMOTHY_003:
			m_nVerses = 16;
			break;

		case ID_1TIMOTHY_004:
			m_nVerses = 16;
			break;

		case ID_1TIMOTHY_005:
			m_nVerses = 25;
			break;

		case ID_1TIMOTHY_006:
			m_nVerses = 21;
			break;


		case ID_2TIMOTHY_001:
			m_nVerses = 18;
			break;

		case ID_2TIMOTHY_002:
			m_nVerses = 26;
			break;

		case ID_2TIMOTHY_003:
			m_nVerses = 17;
			break;

		case ID_2TIMOTHY_004:
			m_nVerses = 22;
			break;


		case ID_TITUS_001:
			m_nVerses = 16;
			break;

		case ID_TITUS_002:
			m_nVerses = 15;
			break;

		case ID_TITUS_003:
			m_nVerses = 15;
			break;


		case ID_PHILEMON_001:
			m_nVerses = 25;
			break;


		case ID_HEBREWS_001:
			m_nVerses = 14;
			break;

		case ID_HEBREWS_002:
			m_nVerses = 18;
			break;

		case ID_HEBREWS_003:
			m_nVerses = 19;
			break;

		case ID_HEBREWS_004:
			m_nVerses = 16;
			break;

		case ID_HEBREWS_005:
			m_nVerses = 14;
			break;

		case ID_HEBREWS_006:
			m_nVerses = 20;
			break;

		case ID_HEBREWS_007:
			m_nVerses = 28;
			break;

		case ID_HEBREWS_008:
			m_nVerses = 13;
			break;

		case ID_HEBREWS_009:
			m_nVerses = 28;
			break;

		case ID_HEBREWS_010:
			m_nVerses = 39;
			break;

		case ID_HEBREWS_011:
			m_nVerses = 40;
			break;

		case ID_HEBREWS_012:
			m_nVerses = 29;
			break;

		case ID_HEBREWS_013:
			m_nVerses = 25;
			break;


		case ID_JAMES_001:
			m_nVerses = 27;
			break;

		case ID_JAMES_002:
			m_nVerses = 26;
			break;

		case ID_JAMES_003:
			m_nVerses = 18;
			break;

		case ID_JAMES_004:
			m_nVerses = 17;
			break;

		case ID_JAMES_005:
			m_nVerses = 20;
			break;


		case ID_1PETER_001:
			m_nVerses = 25;
			break;

		case ID_1PETER_002:
			m_nVerses = 25;
			break;

		case ID_1PETER_003:
			m_nVerses = 22;
			break;

		case ID_1PETER_004:
			m_nVerses = 19;
			break;

		case ID_1PETER_005:
			m_nVerses = 14;
			break;


		case ID_2PETER_001:
			m_nVerses = 21;
			break;

		case ID_2PETER_002:
			m_nVerses = 22;
			break;

		case ID_2PETER_003:
			m_nVerses = 18;
			break;


		case ID_1JOHN_001:
			m_nVerses = 10;
			break;

		case ID_1JOHN_002:
			m_nVerses = 29;
			break;

		case ID_1JOHN_003:
			m_nVerses = 24;
			break;

		case ID_1JOHN_004:
			m_nVerses = 21;
			break;

		case ID_1JOHN_005:
			m_nVerses = 21;
			break;


		case ID_2JOHN_001:
			m_nVerses = 13;
			break;


		case ID_3JOHN_001:
			m_nVerses = 14;
			break;


		case ID_JUDE_001:
			m_nVerses = 25;
			break;


		case ID_REVELATION_001:
			m_nVerses = 20;
			break;

		case ID_REVELATION_002:
			m_nVerses = 29;
			break;

		case ID_REVELATION_003:
			m_nVerses = 22;
			break;

		case ID_REVELATION_004:
			m_nVerses = 11;
			break;

		case ID_REVELATION_005:
			m_nVerses = 14;
			break;

		case ID_REVELATION_006:
			m_nVerses = 17;
			break;

		case ID_REVELATION_007:
			m_nVerses = 17;
			break;

		case ID_REVELATION_008:
			m_nVerses = 13;
			break;

		case ID_REVELATION_009:
			m_nVerses = 21;
			break;

		case ID_REVELATION_010:
			m_nVerses = 11;
			break;

		case ID_REVELATION_011:
			m_nVerses = 19;
			break;

		case ID_REVELATION_012:
			m_nVerses = 17;
			break;

		case ID_REVELATION_013:
			m_nVerses = 18;
			break;

		case ID_REVELATION_014:
			m_nVerses = 20;
			break;

		case ID_REVELATION_015:
			m_nVerses = 8;
			break;

		case ID_REVELATION_016:
			m_nVerses = 21;
			break;

		case ID_REVELATION_017:
			m_nVerses = 18;
			break;

		case ID_REVELATION_018:
			m_nVerses = 24;
			break;

		case ID_REVELATION_019:
			m_nVerses = 21;
			break;

		case ID_REVELATION_020:
			m_nVerses = 15;
			break;

		case ID_REVELATION_021:
			m_nVerses = 27;
			break;

		case ID_REVELATION_022:
			m_nVerses = 21;
			break;

		}
	m_nChapterNumber++;
}
