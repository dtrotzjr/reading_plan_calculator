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

long CSVPlanBuilder::_buildSection(ofstream& ofile, int day, int totalDays, int& curBook, int& curChapter, long totalVersesPerDay, long& totalVersesAssignedInSection, double ratioToAssign, int upperBookBound, bool skipPsalmsAndProverbs) {
    long totalVersesToday = 0;
    bool newBook = false;
    int prevChapter = 0;
    
    ofile << bible.getName(curBook) << " " << curChapter << "-";
    
    while (!_dayIsComplete(day, totalDays, totalVersesPerDay, totalVersesAssignedInSection, ratioToAssign, curBook, upperBookBound)) {
        if (newBook) {
            ofile << bible.getName(curBook) << " " << curChapter << "-";
            newBook = false;
        }
        long thisAssignment = bible.getVerses(curBook, curChapter - 1);
        totalVersesToday += thisAssignment;
        totalVersesAssignedInSection += thisAssignment;
        prevChapter = curChapter;
        newBook = _nextChapter(curBook, curChapter, skipPsalmsAndProverbs);
        if(newBook) {
            ofile << prevChapter << " ";
            prevChapter = 0;
        }
    }
    if(prevChapter > 0) {
        ofile << prevChapter << " ";
    } /*else if (newBook && curBook > upperBookBound) {
        // We check whether this is a newBook or not because
        // at the end of a section we need to account for the
        // last chapter
        int chapter = bible.getChapters(curBook - 1);
        long thisAssignment = bible.getVerses(curBook - 1, chapter);
        totalVersesToday += thisAssignment;
        totalVersesAssignedInSection += thisAssignment;
        ofile << chapter << " ";
    }*/
    ofile << "," << totalVersesToday << ",";
    return totalVersesToday;
}

void CSVPlanBuilder::Build(int totalDays) {
    long totalVersesPerDay = _totalVersesInBible / totalDays;
    cout << "Total Verses Per Day: " << totalVersesPerDay << " verses at: " << ((double)totalVersesPerDay/(double)_totalVersesInBible) * 100.0f << "%%" << endl;
    
    ofstream ofile;
    long totalVersesAssignedOverall = 0;
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
    
    ofile.open ("/Users/dctrotz/tmp/plan.csv");
    if(ofile.is_open()) {
        for(int day = 1; day <= totalDays; day++) {
            totalVersesAssignedToday = 0;
            ofile << day << ",";
            int adjustment = 0;
            // Psalms
            totalVersesAssignedToday += _buildSection(ofile, day, totalDays, curPsalmBook, curPsalmChapter, totalVersesPerDay, totalVersesAssignedInPsalms, _ratioPsalms, PSALMS, false);
            
            // Proverbs
            long proVerses = bible.getVerses(PROVERBS, day - 1);
            totalVersesAssignedToday += proVerses;
            ofile << "Proverbs " << day << "," << proVerses << ",";
            
            // OT
            adjustment += totalVersesAssignedToday - (totalVersesPerDay * (_ratioPsalms + _ratioProverbs));
            double adjustedOTRatio = ((totalVersesPerDay * _ratioOTModified) - adjustment) / totalVersesPerDay;
            totalVersesAssignedToday += _buildSection(ofile, day, totalDays, curOTBook, curOTChapter, totalVersesPerDay, totalVersesAssignedInOT, adjustedOTRatio, MALACHI, true);
            
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
