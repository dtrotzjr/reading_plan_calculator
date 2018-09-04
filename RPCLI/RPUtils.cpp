/***************************************************************************
 RPUtils.h  -  Various tools and    definitions.
 -------------------
 begin         : Sat Jan 03 18:00:00 PST 2004
 copyright     : (C) 2001-2005 by David Trotz    Jr
 email     : dtrotzjr@readingplanner.com
 description     :
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

#include "RPUtils.h"
#include "RPDay.h"
#include "RPDate.h"
#include "KJVBible.h"
#include "MultDays.h"

unsigned int calcTotalDays(RPDate& begin, RPDate& end, DAYFLAGS    dayFlags)
{
    RPDate tempDays    = begin;
    unsigned int intTotalDays = 0;
    long intTotalSpan = end - begin + 1;
    long intThisDay;
    
    for( int count = 0; count < intTotalSpan; count++)
    {
        intThisDay = dayofweek(tempDays.getDay(), tempDays.getMonth(), tempDays.getYear());
        switch(intThisDay)
        {
            case 0:
                if(dayFlags & SUNDAY)
                    intTotalDays++;
                break;
            case 1:
                if(dayFlags & MONDAY)
                    intTotalDays++;
                break;
            case 2:
                if(dayFlags & TUESDAY)
                    intTotalDays++;
                break;
            case 3:
                if(dayFlags & WEDNESDAY)
                    intTotalDays++;
                break;
            case 4:
                if(dayFlags & THURSDAY)
                    intTotalDays++;
                break;
            case 5:
                if(dayFlags & FRIDAY)
                    intTotalDays++;
                break;
            case 6:
                if(dayFlags & SATURDAY)
                    intTotalDays++;
                break;
        }
        tempDays.advanceDate(1);
    }
    
    return intTotalDays;
    
}

RPDate nextReadingDay(RPDate beginDate,    DAYFLAGS dayFlags)
{
    
    bool done = false;
    while(!done)
    {
        beginDate.advanceDate(1);
        switch(dayofweek(beginDate))
        {
            case 0:
                if(dayFlags & SUNDAY)
                    done = true;
                break;
            case 1:
                if(dayFlags & MONDAY)
                    done = true;
                break;
            case 2:
                if(dayFlags & TUESDAY)
                    done = true;
                break;
            case 3:
                if(dayFlags & WEDNESDAY)
                    done = true;
                break;
            case 4:
                if(dayFlags & THURSDAY)
                    done = true;
                break;
            case 5:
                if(dayFlags & FRIDAY)
                    done = true;
                break;
            case 6:
                if(dayFlags & SATURDAY)
                    done = true;
                break;
        }
    }
    return beginDate;
}

void buildKJVSEL(const KJVBible* bible,    CSELStack& SEL_List)
{
    SELECTION SELTemp;
    
    for(int    mainCount = 0; mainCount <= REVELATION;    mainCount++)
    {
        if(bible->isSelected(mainCount))
        {
            for(int    chapterCount = 0; chapterCount < bible->getChapters(mainCount);    chapterCount++)
            {
                SELTemp.m_nBookNum = mainCount;
                SELTemp.m_nChapterNum =    chapterCount;
                SELTemp.m_pNext = NULL;
                SELTemp.m_nStartVerse = 0;
                SELTemp.m_nEndVerse = bible->getVerses(mainCount,chapterCount) - 1;
                SELTemp.m_bnFullChapter = true;
                SEL_List.push(SELTemp);
            }
        }
    }
}

bool calcReadingDays(CSELStack&    SEL_List/*IN*/,    CMultDays& Days    /*OUT*/)
{
    CDay dayCurrDay;            // Current day to be assigned selection
    SELECTION SELCurr;            // Curent SELECTION from the std::list SEL_List
    unsigned int intAverageVerses =    0;   //    The average number of verses to    be read    each day
    unsigned long longCurrVerses = 0;            // Tracks the number of    verses assigned    thus far to the    day
    int intDayCount    = 0;        // Tracks which    day we are one
    unsigned int nVerseThreshold = 0;        // Constantly recalculated threshold for current verse count.
    int reSizeQtr;                //
    
    
    // If we have more days to read than actual    chapters we need to resize our number of days. Otherwise impratical results will apply.
    reSizeQtr = SEL_List.size() + (SEL_List.size() / 4);
    if(Days.getSize() > reSizeQtr)
    {
        Days.resizeDays(reSizeQtr);
    }
    intAverageVerses = SEL_List.getTotalVerses() / Days.getSize();
    SELCurr = SEL_List.peek();
    
    // Iterate the days
    do
    {
#ifdef __palmos__
        AnimateProgress(intDayCount);
#endif
        
        longCurrVerses =    SELCurr.m_nEndVerse - SELCurr.m_nStartVerse;
        
        // If we get a large chapter that meets/exceeds    the quota then we are done for this day
        if(longCurrVerses >= intAverageVerses &&    intAverageVerses != 0)
        {
            SELECTION SELOrig = SELCurr = SEL_List.pop();
            unsigned int currSpanDay = 1;
            long totalSpan = longCurrVerses / intAverageVerses; // Total days this reading spans
            if(totalSpan > 1)
            {
                SELCurr.m_nEndVerse /= totalSpan;
                SELCurr.m_bnFullChapter = false;
            }
            Days.addSelToDay(intDayCount, SELCurr);
            intDayCount++;
            
            // Some days we find that a    chapter    really is worth    3 days reading like
            // Psalm 119 could be. This    assigns    that reading to    an appropiate number of    days.
            while(currSpanDay++ < totalSpan)
            {
                SELCurr.m_nStartVerse = SELCurr.m_nEndVerse + 1;
                if(currSpanDay == totalSpan)
                    SELCurr.m_nEndVerse = SELOrig.m_nEndVerse;
                else
                    SELCurr.m_nEndVerse = (SELOrig.m_nEndVerse / totalSpan) * currSpanDay;
                if(Days.dayInRange(intDayCount))
                {
                    Days.addSelToDay(intDayCount, SELCurr);
                    intDayCount++;
                }else return false; // We needed to place a reading and for some reason we ran out of days
            }
            
            if(/*Days.dayInRange(intDayCount) && */ SEL_List.getTotalVerses())
            {
                intAverageVerses = SEL_List.getTotalVerses() / (Days.getSize() - intDayCount);
                SELCurr    = SEL_List.peek();
            }
        }else // Iterate the daily selection till daily    quota is met
        {
            while(true)
            {
                Days.addSelToDay(intDayCount, SEL_List.pop());
                if(SEL_List.getTotalVerses())
                    SELCurr    = SEL_List.peek();
                else
                {
                    intDayCount++;
                    break;
                }
                longCurrVerses += SELCurr.m_nEndVerse - SELCurr.m_nStartVerse;
                // I really want to run some statistics on this value and see if it can be dynamically adjusted to
                // better distribute readings.
                nVerseThreshold    = (intAverageVerses / 20) + intAverageVerses; // 110% of the daily quota.
                
                if( longCurrVerses >= intAverageVerses &&
                   longCurrVerses <    nVerseThreshold)
                {
                    Days.addSelToDay(intDayCount, SEL_List.pop());
                    intDayCount++;
                    if(Days.dayInRange(intDayCount))
                    {
                        intAverageVerses = SEL_List.getTotalVerses() / (Days.getSize() - intDayCount);
                        SELCurr    = SEL_List.peek();
                    }
                    break;
                }else if(longCurrVerses > nVerseThreshold)
                {
                    //intCurrVerses -= SELCurr.m_nEndVerse - SELCurr.m_nStartVerse;
                    intDayCount++;
                    
                    if(Days.getSize() - intDayCount    != 0)
                    {
                        intAverageVerses = (SEL_List.getTotalVerses() / (Days.getSize() -    intDayCount));
                    }
                    
                    break;
                    
                }
            }
            
        }
        
    }while((intDayCount != Days.getSize()) && (SEL_List.getTotalVerses() !=    0));
    
    if(Days.getSize() - intDayCount    != 0)
    {
        Days.resizeDays(intDayCount);
    }
    return true;
}

#ifdef __palmos__
static void AnimateProgress(UInt16 count)
{
    RPString mesg = "Calculating Plan ";
    RPString mesgMax = "Preparing ReadingPlan..."; // Dummy string for max length of msg box
    AnimatedStatusBox(mesg, mesgMax,count);
}
#endif


