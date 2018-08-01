/***************************************************************************
 KJVBible.cpp  -  Implementation for KJVBible class
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
#include "KJVBible.h"

KJVBible::KJVBible()
{
}

KJVBible::~KJVBible()
{
}

int KJVBible::getChapters(string strName) const
{
    string strCurr;     // This is redundant I know but MobileStudio for Palm OS
    // does not extend the == operator to const objects. I want
    // to keep constancy and this is the safest way.
    
    for(int count = 0;count < 66 ;count++)
    {
        strCurr = getName(count);
        if(strCurr == strName)
            return getChapters(count);
    }
    return -1;
}

int KJVBible::getChapters(int nBookNum) const
{
    if(nBookNum >= 0 && nBookNum < 66)
        return m_Books[nBookNum].getChapters();
    else
        return -1;
}

long KJVBible::getVerses(string strName) const
{
    long totalVerses = -1;
    string strCurr;     // This is redundant I know but MobileStudio for Palm OS
    // does not extend the == operator to const objects. I want
    // to keep constancy and this is the safest way.
    
    for(int bookNum = 0; bookNum < 66; bookNum++)
    {
        strCurr = getName(bookNum);
        if(strCurr == strName)
        {
            totalVerses = m_Books[bookNum].getVerses();
            break;
        }
    }
    return totalVerses;
}

string KJVBible::getName(int book) const
{
    if(book >= 0 && book < 66)
        return m_Books[book].getName();
    
    return m_Books[0].getName();
}

long KJVBible::getVerses(string strName,int nChapter) const
{
    int count;
    string strCurr;     // This is redundant I know but MobileStudio for Palm OS
    // does not extend the == operator to const objects. I want
    // to keep constancy and this is the safest way.
    
    for(count = 0; count < 66; count++)
        strCurr = getName(count);
    if(strCurr == strName)
        return m_Books[count].getVerses(nChapter);
    return -1;
}

long KJVBible::getVerses(int nBookNum,int nChapter) const
{
    if(nBookNum >= 0 && nBookNum < 66)
        return m_Books[nBookNum].getVerses(nChapter);
    return -1;
}

long KJVBible::getVerses(int nBookNum) const
{
    if(nBookNum >= 0 && nBookNum < 66)
        return m_Books[nBookNum].getVerses();
    return -1;
}

void KJVBible::selectRange(int nLow, int nHigh, bool bnSelect)
{
    if(nLow < nHigh && nLow >= 0 && nHigh < 66)
        for(int count = nLow; count <= nHigh; count++)
            m_Books[count].select(bnSelect);
}

bool KJVBible::select(int nBookNum, bool bnSelect)
{
    if(nBookNum >= 0 && nBookNum < 66){
        m_Books[nBookNum].select(bnSelect);
        return true;
    }
    return false;
}

bool KJVBible::isSelected(int nBookNum) const
{
    if(nBookNum >= 0 && nBookNum <= 65){
        return m_Books[nBookNum].isSelected();
    }
    return false;
}

bool KJVBible::isSelected(int nLow, int nHigh) const
{
    if(nLow < nHigh && nLow >= 0 && nHigh <= 65)
    {
        for(int count = nLow; count <= nHigh; count++)
        {
            if(!m_Books[count].isSelected())
                return false;
        }
    }else return false;
    return true;
}


