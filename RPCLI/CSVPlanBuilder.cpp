//
//  CSVPlanBuilder.cpp
//  RPCLI
//
//  Created by David Trotz on 7/31/18.
//  Copyright © 2018 TrotzSoftware. All rights reserved.
//

#include "CSVPlanBuilder.hpp"

#include <iostream>
#include <fstream>
using namespace std;

#include "RPUtils.h"

CSVPlanBuilder::CSVPlanBuilder(long overalOverageMargin,
                               long dayOverageMargin):
    _overalOverageMargin(overalOverageMargin),
    _dayOverageMargin(dayOverageMargin) {
    _totalVersesInBible = 0;
    for( int book = GENESIS; book <= REVELATION; book++ ) {
        _totalVersesInBible += bible.getVerses(book);
    }
    cout << "Bible has " << _totalVersesInBible << " verses" << endl;
    
    _totalVersesInPsalms = bible.getVerses("Psalm");
    _ratioPsalms = (double)_totalVersesInPsalms / (double)_totalVersesInBible;
    cout << "Psalms has " << _totalVersesInPsalms << " verses at: " << _ratioPsalms * 100.0f << "%%" << endl;
    
    _totalVersesInProverbs = bible.getVerses("Proverbs");
    _ratioProverbs = (double)_totalVersesInProverbs / (double)_totalVersesInBible;
    cout << "Proverbs has " << _totalVersesInProverbs << " verses at: " << _ratioProverbs * 100.0f << "%%" << endl;
    
    _totalVersesInPsalmsAndProverbs = _totalVersesInPsalms + _totalVersesInProverbs;
    _ratioPsalmsAndProverbs = (double)_totalVersesInPsalmsAndProverbs / (double)_totalVersesInBible;
    cout << "Psalms and Proverbs has " << _totalVersesInPsalmsAndProverbs << " verses at: " << _ratioPsalmsAndProverbs * 100.0f << "%%" << endl;
    
    _totalVersesInNewTestament = 0;
    for( int book = MATTHEW; book <= REVELATION; book++ ) {
        _totalVersesInNewTestament += bible.getVerses(book);
    }
    _ratioNewTestament = (double)_totalVersesInNewTestament / (double)_totalVersesInBible;
    cout << "New Testament has " << _totalVersesInNewTestament << " verses at: " << _ratioNewTestament * 100.0f << "%%" << endl;
    
    _totalVersesInOldTestament = 0;
    for( int book = GENESIS; book <= MALACHI; book++ ) {
        _totalVersesInOldTestament += bible.getVerses(book);
    }
    _ratioOldTestament = (double)_totalVersesInOldTestament / (double)_totalVersesInBible;
    cout << "Old Testament has " << _totalVersesInOldTestament << " verses at: " << _ratioOldTestament * 100.0f << "%%" << endl;
    
    
    _totalVersesInOTModified = _totalVersesInOldTestament - _totalVersesInPsalms - _totalVersesInProverbs;
    _ratioOTModified = (double)_totalVersesInOTModified / (double)_totalVersesInBible;
    cout << "Old Testament without Psalms and Proverbs has " << _totalVersesInOTModified << " verses at: " << _ratioOTModified * 100.0f << "%%" << endl;
}

void CSVPlanBuilder::Build(int totalDays,
                           const char* outputFile) {
    long totalVersesPerDayLimit = _totalVersesInBible / totalDays;
    cout << "Total Verses Per Day: " << totalVersesPerDayLimit << " verses at: " << ((double)totalVersesPerDayLimit/(double)_totalVersesInBible) * 100.0f << "%%" << endl;
    
    ofstream ofile;
    long totalVersesAssignedToday = 0;
    long totalVersesAssignedInOT = 0;
    int curOTBook = GENESIS;
    int curOTChapter = 1;
    
    long totalVersesAssignedInPsalms = 0;
    int curPsalmBook = PSALMS;
    int curPsalmChapter = 1;
    
    long totalVersesAssignedInNT = 0;
    int curNTBook = MATTHEW;
    int curNTChapter = 1;
    
    ofile.open(outputFile);
    if(ofile.is_open()) {
        for(int day = 1; day <= totalDays; day++) {
            totalVersesAssignedToday = 0;
            ofile << day << ",";
            int adjustment = 0;
            // Psalms & Proverbs
            totalVersesAssignedToday += _buildSectionForDay(ofile, day, totalDays, curPsalmBook, curPsalmChapter, totalVersesPerDayLimit, totalVersesAssignedInPsalms, _ratioPsalmsAndProverbs, PROVERBS, false, true);
            
            // OT
            adjustment = totalVersesAssignedToday - (totalVersesPerDayLimit * (_ratioPsalms + _ratioProverbs));
            if(adjustment < 0)
                adjustment = 0; // We don't want other sections playing catchup on behalf of others, we only want sections taking into account that a previous section was over its daily quote.
            totalVersesAssignedToday += _buildSectionForDay(ofile, day, totalDays, curOTBook, curOTChapter, totalVersesPerDayLimit, totalVersesAssignedInOT, _ratioOTModified, MALACHI, true, false, adjustment);
            
            // NT
            totalVersesAssignedToday += _buildSectionForDay(ofile, day, totalDays, curNTBook, curNTChapter, totalVersesPerDayLimit, totalVersesAssignedInNT, _ratioNewTestament, REVELATION, false);
            
            ofile << totalVersesAssignedToday << endl;
        }
        ofile.close();
    }
}

long CSVPlanBuilder::_buildSectionForDay(ofstream& ofile,
                                         int day,
                                         int totalDays,
                                         int& curBook,
                                         int& curChapter,
                                         long totalVersesPerDayLimit,
                                         long& totalVersesAssignedInSection,
                                         double ratioToAssign,
                                         int upperBookBound,
                                         bool skipPsalmsAndProverbs,
                                         bool forceAtLeastOneAssignmentInSection,
                                         int adjustment) {
    long totalVersesAssignedInSectionToday = 0;
    bool newBook = false;
    int prevChapter = 0;
    int prevBook = 0;
    
    ofile << bible.getName(curBook) << "_" << curChapter << "-";
    
    while (!_dayIsComplete(day, totalDays, totalVersesPerDayLimit, totalVersesAssignedInSectionToday  + adjustment, totalVersesAssignedInSection, ratioToAssign, curBook, upperBookBound, forceAtLeastOneAssignmentInSection)) {
        if (newBook) {
            ofile << "#" << bible.getName(curBook) << "_" << curChapter << "-";
        }
        long thisAssignment = bible.getVerses(curBook, curChapter - 1);
        
        totalVersesAssignedInSectionToday += thisAssignment;
        totalVersesAssignedInSection += thisAssignment;
        prevBook = curBook;
        prevChapter = curChapter;
        newBook = _nextChapter(curBook, curChapter, skipPsalmsAndProverbs);
        if(newBook) {
            ofile << prevChapter;
            prevChapter = 0;
        }
    }
    if(prevChapter > 0) {
        if(day < totalDays &&
           totalVersesAssignedInSectionToday > bible.getVerses(prevBook, prevChapter - 1) &&
           _dayOverflowed(day, totalVersesPerDayLimit, totalVersesAssignedInSection, totalVersesAssignedInSectionToday)) {
            curChapter = prevChapter;
            prevChapter -= 1;
            
            long overflowedVerses = bible.getVerses(curBook, curChapter - 1);
            totalVersesAssignedInSectionToday -= overflowedVerses;
            totalVersesAssignedInSection -= overflowedVerses;
        }
        ofile << prevChapter;
    }
    
    ofile << "," << totalVersesAssignedInSectionToday << ",";
    return totalVersesAssignedInSectionToday;
}

bool CSVPlanBuilder::_nextChapter(int& curBook,
                                  int& curChapter,
                                  bool skipPsalmsAndProverbs) {
    bool bookIncremented = false;
    curChapter++;
    if(curChapter > bible.getChapters(curBook)) {
        curBook++;
        curChapter = 1;
        bookIncremented = true;
    }
    // Skip Psalms and Proverbs
    if(skipPsalmsAndProverbs && (curBook == PSALMS || curBook == PROVERBS)) {
        curBook = ECCLESIASTES;
    }
    return bookIncremented;
}

bool CSVPlanBuilder::_dayIsComplete(int day,
                                    int totalDays,
                                    long totalVersesPerDayLimit,
                                    long totalVersesAssignedInSectionToday,
                                    long totalVersesAssignedInSectionOverall,
                                    double targetRatio,
                                    int curBook,
                                    int upperBookBound,
                                    bool forceAtLeastOneAssignmentInSection) {
    bool complete = false;
    
    if(day < totalDays) {
        double currentEffectiveRatio =  ((double)totalVersesAssignedInSectionOverall / (double)(day * totalVersesPerDayLimit));
        bool sectionCompleteToday = totalVersesAssignedInSectionToday > (totalVersesPerDayLimit * targetRatio);
        bool sectionCompleteOverall = curBook > upperBookBound;
        bool sectionQuotaMet = currentEffectiveRatio > targetRatio;
        complete = sectionQuotaMet || sectionCompleteOverall || sectionCompleteToday;
    } else {
        complete = curBook > upperBookBound;
    }
    // One last chance to override the completion status
    if(complete && forceAtLeastOneAssignmentInSection && totalVersesAssignedInSectionToday == 0.0)
        complete = false;
    
    return complete;
}

bool CSVPlanBuilder::_dayOverflowed(int day,
                                    long totalVersesPerDayLimit,
                                    long totalVersesAssignedOverall,
                                    long totalVersesAssignedForDay) {
    bool overflowedOverall = totalVersesAssignedOverall > ((totalVersesPerDayLimit * day) + _overalOverageMargin);
    bool overflowedDay = totalVersesAssignedForDay > (totalVersesPerDayLimit + _dayOverageMargin);
    return overflowedOverall || overflowedDay;
}
