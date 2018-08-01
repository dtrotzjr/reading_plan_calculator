/***************************************************************************
	KJVBook.cpp  -  Implementation for KJVBook class
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

#include "KJVBook.h"
#include "RPUtils.h"

int KJVBook::m_bookNumber = GENESIS;

KJVBook::KJVBook(KJVBook& rhs)
{
 	m_bnSelected = rhs.m_bnSelected;
 	m_bookNumber = rhs.m_bookNumber;
 	m_nChapters = rhs.m_nChapters;
 	m_strBookName = rhs.m_strBookName;
    if(m_nChapters)  // make sure there are actually chapters to create.
    {
     	m_pChapters = new KJVChapter[m_nChapters];
 		for(int count = 0; count < m_nChapters; count++)
   			m_pChapters[count] = rhs.m_pChapters[count];
    }else
    	m_pChapters = NULL;
}

const KJVBook& KJVBook::operator =(const KJVBook& rhs)
{
 	m_bnSelected = rhs.m_bnSelected;
 	m_bookNumber = rhs.m_bookNumber;
 	m_nChapters = rhs.m_nChapters;
 	m_strBookName = rhs.m_strBookName;
    if(m_nChapters)  // make sure there are actually chapters to create.
    {
     	m_pChapters = new KJVChapter[m_nChapters];
 		for(int count = 0; count < m_nChapters; count++)
   			m_pChapters[count] = rhs.m_pChapters[count];
    }else
    	m_pChapters = NULL;
    return *this;
}

KJVBook::~KJVBook()
{
	delete [] m_pChapters;
}

KJVBook::KJVBook()
{
  if(m_bookNumber > REVELATION)
	m_bookNumber = GENESIS;
  
  m_bnSelected = false;

  switch (m_bookNumber)
    {
	// Old Testament Books
    case GENESIS:
      m_strBookName = "Genesis";
      m_nChapters = 50;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case EXODUS:
      m_strBookName = "Exodus";
      m_nChapters = 40;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case LEVITICUS:
      m_strBookName = "Leviticus";
      m_nChapters = 27;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case NUMBERS:
      m_strBookName = "Numbers";
      m_nChapters = 36;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case DEUTERONOMY:
      m_strBookName = "Deuteronomy";
      m_nChapters = 34;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case JOSHUA:
      m_strBookName = "Joshua";
      m_nChapters = 24;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case JUDGES:
      m_strBookName = "Judges";
      m_nChapters = 21;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case RUTH:
      m_strBookName = "Ruth";
      m_nChapters = 4;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case ISAMUEL:
      m_strBookName = "1Samuel";
      m_nChapters =31;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case IISAMUEL:
      m_strBookName = "2Samuel";
      m_nChapters = 24;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case IKINGS:
      m_strBookName = "1Kings";
      m_nChapters = 22;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case IIKINGS:
      m_strBookName = "2Kings";
      m_nChapters = 25;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case ICHRONICLES:
      m_strBookName = "1Chronicles";
      m_nChapters = 29;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case IICHRONICLES:
      m_strBookName = "2Chronicles";
      m_nChapters = 36;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case EZRA:
      m_strBookName = "Ezra";
      m_nChapters = 10;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case NEHEMIAH:
      m_strBookName = "Nehemiah";
      m_nChapters = 13;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case ESTHER:
      m_strBookName = "Esther";
      m_nChapters = 10;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case JOB:
      m_strBookName = "Job";
      m_nChapters = 42;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case PSALMS:
      m_strBookName = "Psalm";
      m_nChapters = 150;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case PROVERBS:
      m_strBookName = "Proverbs";
      m_nChapters = 31;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case ECCLESIASTES:
      m_strBookName = "Ecclesiastes";
      m_nChapters = 12;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case SONG_OF_SONGS:
      m_strBookName = "Songs of Solomon";
      m_nChapters = 8;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case ISAIAH:
      m_strBookName = "Isaiah";
      m_nChapters = 66;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case JEREMIAH:
      m_strBookName = "Jeremiah";
      m_nChapters = 52;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case LAMENTATIONS:
      m_strBookName = "Lamentations";
      m_nChapters =5;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case EZEKIEL:
      m_strBookName = "Ezekiel";
      m_nChapters = 48;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case DANIEL:
      m_strBookName = "Daniel";
      m_nChapters = 12;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case HOSEA:
      m_strBookName = "Hosea";
      m_nChapters = 14;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case JOEL:
      m_strBookName = "Joel";
      m_nChapters = 3;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case AMOS:
      m_strBookName = "Amos";
      m_nChapters = 9;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case OBADIAH:
      m_strBookName = "Obadiah";
      m_nChapters = 1;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case JONAH:
      m_strBookName = "Jonah";
      m_nChapters = 4;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case MICAH:
      m_strBookName = "Micah";
      m_nChapters = 7;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case NAHUM:
      m_strBookName = "Nahum";
      m_nChapters =3;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case HABAKKUK:
      m_strBookName = "Habakkuk";
      m_nChapters =3;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case ZEPHANIAH:
      m_strBookName = "Zephaniah";
      m_nChapters =3;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case HAGGAI:
      m_strBookName = "Haggai";
      m_nChapters = 2;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case ZECHARIAH:
      m_strBookName = "Zechariah";
      m_nChapters = 14;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case MALACHI:
      m_strBookName = "Malachi";
      m_nChapters = 4;
      m_pChapters = new KJVChapter[m_nChapters];
      break;

      // New Testament Books
    case MATTHEW:
      m_strBookName = "Matthew";
      m_nChapters = 28;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case MARK:
      m_strBookName = "Mark";
      m_nChapters = 16;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case LUKE:
      m_strBookName = "Luke";
      m_nChapters = 24;
      m_pChapters = new KJVChapter[24];
      break;
    case JOHN:
      m_strBookName = "John";
      m_nChapters = 21;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case ACTS:
      m_strBookName = "Acts";
      m_nChapters = 28;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case ROMANS:
      m_strBookName = "Romans";
      m_nChapters = 16;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case ICORINTHIANS:
      m_strBookName = "1Corinthians";
      m_nChapters = 16;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case IICORINTHIANS:
      m_strBookName = "2Corinthians";
      m_nChapters = 13;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case GALATIANS:
      m_strBookName = "Galatians";
      m_nChapters = 6;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case EPHESIANS:
      m_strBookName = "Ephesians";
      m_nChapters = 6;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case PHILIPPIANS:
      m_strBookName = "Phillipians";
      m_nChapters =4;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case COLOSIANS:
      m_strBookName = "Colossians";
      m_nChapters =4;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case ITHESSALONIANS:
      m_strBookName = "1Thessalonians";
      m_nChapters =5;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case IITHESSALONIANS:
      m_strBookName = "2Thessalonians";
      m_nChapters = 3;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case ITIMOTHY:
      m_strBookName = "1Timothy";
      m_nChapters = 6;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case IITIMOTHY:
      m_strBookName = "2Timothy";
      m_nChapters = 4;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case TITUS:
      m_strBookName = "Titus";
      m_nChapters = 3;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case PHILEMON:
      m_strBookName = "Philemon";
      m_nChapters = 1;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case HEBREWS:
      m_strBookName = "Hebrews";
	  m_nChapters = 13;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case JAMES:
      m_strBookName = "James";
      m_nChapters =5;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case IPETER:
      m_strBookName = "1Peter";
      m_nChapters = 5;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case IIPETER:
      m_strBookName = "2Peter";
      m_nChapters = 3;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case IJOHN:
      m_strBookName = "1John";
      m_nChapters =5;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case IIJOHN:
      m_strBookName = "2John";
      m_nChapters = 1;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case IIIJOHN:
      m_strBookName = "3John";
      m_nChapters = 1;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case JUDE:
      m_strBookName = "Jude";
      m_nChapters = 1;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
    case REVELATION:
      m_strBookName = "Revelation";
      m_nChapters = 22;
      m_pChapters = new KJVChapter[m_nChapters];
      break;
	}
  m_bookNumber++;
}

void KJVBook::setName(string strName)
{
  m_strBookName = strName;
}

string KJVBook::getName() const
{
  return m_strBookName;
}

int KJVBook::getChapters() const
{
  return m_nChapters;
}

int KJVBook::getVerses() const
{
  int verses = 0;
  for(int count = 0; count < m_nChapters; count++)
  {
	verses += m_pChapters[count].getVerses();
  }
	 return verses;
}
int KJVBook::getVerses(const int& nChapter) const
{
	if(nChapter <= m_nChapters)
		return m_pChapters[nChapter].getVerses();
	return -1;
}

void KJVBook::select(bool bnSelect)
{
	m_bnSelected = bnSelect;
}

bool KJVBook::isSelected() const
{
	return m_bnSelected;
}
