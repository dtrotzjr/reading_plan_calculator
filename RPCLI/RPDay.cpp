/***************************************************************************
	Day.cpp  -  Implementation for CDay class
                             -------------------
    begin                : Sat Jan 03 18:00:00 PST 2004
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


#include "RPDay.h"

CDay::CDay() : CSELStack()
{

}

CDay::CDay(RPDate date) : CSELStack()
{
	m_date = date;
}

CDay::~CDay()
{

}

RPDate CDay::getDate()
{
	return m_date;
}
		
void CDay::setDate(const RPDate& date)
{
	m_date = date;
}

int CDay::getVerses()
{
    return this->m_nTotalVerses;
}
