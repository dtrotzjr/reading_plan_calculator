/***************************************************************************
	MultDays.cpp  -  Implementation for CMultDays class
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

//#include "ReadingPlanner.h"
#include "MultDays.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// I have decided that this class must be initialized with dates because 
// everything about this class depends on them.
CMultDays::CMultDays()
{
	m_nNumDays = 0;
	m_pDays = 0;
}

CMultDays::CMultDays(CMultDays& rhs)
{
  m_nNumDays = rhs.m_nNumDays;
  if(m_nNumDays)
  {
  	m_pDays = new CDay[m_nNumDays];
    for(int count = 0; count < m_nNumDays; count++)
    	m_pDays[count] = rhs.m_pDays[count];
  }else m_pDays = NULL;
}
const CMultDays& CMultDays::operator=(const CMultDays& rhs)
{
  m_nNumDays = rhs.m_nNumDays;

  if(m_pDays)
  	delete [] m_pDays;

  if(m_nNumDays)
  {
  	m_pDays = new CDay[m_nNumDays];
    for(int count = 0; count < m_nNumDays; count++)
    	m_pDays[count] = rhs.m_pDays[count];
  }else m_pDays = NULL;
  return *this;
}
CMultDays::~CMultDays()
{
	clear();
}

CMultDays::CMultDays(RPDate& begin, RPDate& end, DAYFLAGS dayFlags)
{
	RPDate currDate = begin;
	m_nNumDays = calcTotalDays(begin, end, dayFlags);
	currDate.advanceDate(-1);
	m_pDays = new CDay[m_nNumDays];
	for(int i = 0; i < m_nNumDays; i++)
	{
		currDate = nextReadingDay(currDate, dayFlags);
		m_pDays[i].setDate(currDate);
	}
}

int CMultDays::getSize() const
{
	return m_nNumDays;
}

CDay CMultDays::getDay(int nDayNum) const
{
	return m_pDays[nDayNum];
}

void CMultDays::addSelToDay(int nDayNum,SELECTION sel)
{
	m_pDays[nDayNum].push(sel);
}

void CMultDays::setDay(int nDayNum,CDay day)
{
	m_pDays[nDayNum] = day;
}

bool CMultDays::addDay(CDay& day)
{
	if(m_nNumDays == 0)
	{
		m_pDays = new CDay[1];
		m_pDays[0] = day;
		m_nNumDays = 1;
	}else
	{
		CDay* pTempDay = new CDay[m_nNumDays + 1];
		for(int count = 0; count < m_nNumDays; count++)
		{
			pTempDay[count] = m_pDays[count];
		}
		
		pTempDay[m_nNumDays] = day;
		m_nNumDays++;

		delete [] m_pDays;
		m_pDays = pTempDay;
	}
	return true;	

}

// Beware of resizing larger than the current size, as the date will be 
// set to the default date of the RPDate class.
bool CMultDays::resizeDays(int nSize)
{
	if(m_nNumDays == 0)
	{
		m_pDays = new CDay[nSize];
		m_nNumDays = nSize;
	}else
	{
		CDay* pTempDay = new CDay[nSize];
		if(nSize > m_nNumDays)
		{
			for(int count = 0; count < m_nNumDays; count++)
			{
				pTempDay[count] = m_pDays[count];
			}
		}else
		{
			for(int count = 0; count < nSize; count++)
			{
				pTempDay[count] = m_pDays[count];
			}
		}
		m_nNumDays = nSize;

		delete [] m_pDays;
		m_pDays = pTempDay;
	}
	return true;	

}

int CMultDays::getTotalDays() const
{
	return m_nNumDays;
}

void CMultDays::reInitialize(RPDate& begin, RPDate& end, DAYFLAGS dayFlags)
{
    clear();
	RPDate currDate = begin;
	m_nNumDays = calcTotalDays(begin, end, dayFlags);
	currDate.advanceDate(-1);
	m_pDays = new CDay[m_nNumDays];
	for(int i = 0; i < m_nNumDays; i++)
	{
		currDate = nextReadingDay(currDate, dayFlags);
		m_pDays[i].setDate(currDate);
	}
}

void CMultDays::clear()
{
	if(m_pDays)
		delete [] m_pDays;
	m_pDays = NULL;
	m_nNumDays = 0;
}

RPDate CMultDays::getEndDate() const
{
	return m_pDays[m_nNumDays - 1].getDate();
}

bool CMultDays::dayInRange(int dayIndex) const
{
	return ((dayIndex > 0) && (dayIndex < m_nNumDays));
}

