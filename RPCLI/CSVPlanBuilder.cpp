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

CSVPlanBuilder::CSVPlanBuilder() {
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

long CSVPlanBuilder::_buildSection(ofstream& ofile, int day, int totalDays, int& curBook, int& curChapter, long totalVersesPerDay, long& totalVersesAssignedInSection, double ratioToAssign, int upperBookBound, bool skipPsalmsAndProverbs, int adjustment) {
    long totalVersesToday = 0;
    bool newBook = false;
    int prevChapter = 0;
    int prevBook = 0;
    
    ofile << bible.getName(curBook) << "_" << curChapter << "-";
    
    while (!_dayIsComplete(day, totalDays, totalVersesPerDay, totalVersesAssignedInSection + adjustment, ratioToAssign, curBook, upperBookBound)) {
        if (newBook) {
            ofile << "#" << bible.getName(curBook) << "_" << curChapter << "-";
            newBook = false;
        }
        long thisAssignment = bible.getVerses(curBook, curChapter - 1);
        
        totalVersesToday += thisAssignment;
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
        if(day < totalDays && totalVersesToday > bible.getVerses(prevBook, prevChapter - 1) && _dayWasOverflow(totalVersesPerDay * ratioToAssign, totalVersesToday)) {
            curChapter = prevChapter;
            prevChapter -= 1;
            
            long overflowedVerses = bible.getVerses(curBook, curChapter - 1);
            totalVersesToday -= overflowedVerses;
            totalVersesAssignedInSection -= overflowedVerses;
        }
        ofile << prevChapter;
    }
    
    ofile << "," << totalVersesToday << ",";
    return totalVersesToday;
}

void CSVPlanBuilder::Build(int totalDays, const char* outputFile) {
    long totalVersesPerDay = _totalVersesInBible / totalDays;
    cout << "Total Verses Per Day: " << totalVersesPerDay << " verses at: " << ((double)totalVersesPerDay/(double)_totalVersesInBible) * 100.0f << "%%" << endl;
    
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
            totalVersesAssignedToday += _buildSection(ofile, day, totalDays, curPsalmBook, curPsalmChapter, totalVersesPerDay, totalVersesAssignedInPsalms, _ratioPsalmsAndProverbs, PROVERBS, false);
            
            // OT
            adjustment = totalVersesAssignedToday - (totalVersesPerDay * (_ratioPsalms + _ratioProverbs));
            totalVersesAssignedToday += _buildSection(ofile, day, totalDays, curOTBook, curOTChapter, totalVersesPerDay, totalVersesAssignedInOT, _ratioOTModified, MALACHI, true, adjustment);
            
            // NT
            totalVersesAssignedToday += _buildSection(ofile, day, totalDays, curNTBook, curNTChapter, totalVersesPerDay, totalVersesAssignedInNT, _ratioNewTestament, REVELATION, false);
            
            ofile << totalVersesAssignedToday << endl;
        }
        ofile.close();
    }
}

bool CSVPlanBuilder::_nextChapter(int& curBook, int& curChapter, bool skipPsalmsAndProverbs) {
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

bool CSVPlanBuilder::_dayIsComplete(int day, int totalDays, long totalVersesPerDay, long totalVersesAssignedInSection, double ratio, int curBook, int upperBookBound) {
    bool complete = false;
    double currentRatio =  ((double)totalVersesAssignedInSection / (double)(day * totalVersesPerDay));
    if(day < totalDays) {
        complete = (currentRatio > ratio) || curBook > upperBookBound;
    } else {
        complete = curBook > upperBookBound;
    }

    return complete;
}

bool CSVPlanBuilder::_dayWasOverflow(long totalVersesPerDay, long totalVersesAssigned) {
    return (totalVersesAssigned / totalVersesPerDay) > 1.25;
}
