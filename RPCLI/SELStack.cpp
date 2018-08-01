/***************************************************************************
	SELStack.cpp  -  Implementation for CSELStack class
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

#include "SELStack.h"

#define NULL 0 
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSELStack::CSELStack()
{
  m_nSize = 0;
  m_nTotalVerses = 0;
	m_pTop = NULL;
	m_pCurr = NULL;
}


CSELStack::~CSELStack()
{
	clear();
}

CSELStack::CSELStack(const CSELStack& rhs)
{	
    m_nSize = 0;
	m_pTop = NULL;
	m_pCurr = NULL;
    m_nTotalVerses = 0;

	if(rhs.isEmpty())
		return;
	
	SEL_PTR pCurr = rhs.m_pTop;
	while(pCurr->m_pNext)
	{
		push(*pCurr);
		pCurr = pCurr->m_pNext;
	}
	push(*pCurr);

}

const CSELStack& CSELStack::operator=(const CSELStack& rhs)
{
	clear();
	
	if(rhs.isEmpty())
		return rhs; // I am not sure what to do here...
	
	SEL_PTR pCurr = rhs.m_pTop;
	while(pCurr->m_pNext)
	{
		push(*pCurr);
		pCurr = pCurr->m_pNext;
	}
	push(*pCurr);
	
	return *this;
}


void CSELStack::push(SELECTION sel)
{
	if(m_nSize)
	{
		m_pCurr->m_pNext = new SELECTION;
		m_pCurr = m_pCurr->m_pNext;
		m_pCurr->m_pNext = NULL;
    }
    else
	{
		m_pTop = new SELECTION;
		m_pTop->m_pNext = NULL;
        m_pCurr = m_pTop;
    }
	
	m_pCurr->m_nBookNum = sel.m_nBookNum;
	m_pCurr->m_nChapterNum = sel.m_nChapterNum;
	m_pCurr->m_nStartVerse = sel.m_nStartVerse;
	m_pCurr->m_nEndVerse = sel.m_nEndVerse;
	m_pCurr->m_bnFullChapter = sel.m_bnFullChapter;
  m_nTotalVerses += (m_pCurr->m_nEndVerse - m_pCurr->m_nStartVerse);
	m_nSize++;
}


SELECTION CSELStack::pop()
{
	SELECTION retVal = *m_pTop;
    SEL_PTR pTemp = m_pTop;
    if(m_pTop->m_pNext)
    {
        m_pTop = m_pTop->m_pNext;
        m_nSize--;
    }
    else
    {
        m_pTop = NULL;
        m_nSize = 0;
    }
    m_nTotalVerses -= (pTemp->m_nEndVerse - pTemp->m_nStartVerse);
    delete pTemp;
	return retVal;
}

void CSELStack::clear()
{
	while(!isEmpty())
	{
        pop();
	}
	m_pTop = NULL;
	m_pCurr = NULL;
}

bool CSELStack::isEmpty() const
{
	if(m_nSize > 0)
    	return false;
    return true;
}

unsigned int CSELStack::size() const
{ 
	return m_nSize; 
}

unsigned int CSELStack::getTotalVerses() const
{
	return m_nTotalVerses;
}

SELECTION CSELStack::peek() const
{
    return *m_pTop;
}

