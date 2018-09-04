//
//  CSVPlanBuilder.hpp
//  RPCLI
//
//  Created by David Trotz on 7/31/18.
//  Copyright © 2018 TrotzSoftware. All rights reserved.
//

#ifndef CSVPlanBuilder_hpp
#define CSVPlanBuilder_hpp

#include <stdio.h>
#include <iostream>

#include "KJVBible.h"

class CSVPlanBuilder {
public:
    CSVPlanBuilder(long overalOverageMargin,
                   long dayOverageMargin);
    void Build(int totalDays, const char* outputFile);
protected:
    bool _nextChapter(int& curBook, int& curChapter, bool skipPsalmsAndProverbs);
    bool _dayIsComplete(int day, int totalDays, long totalVersesPerDay, long totalVersesAssignedInSectionToday, long totalVersesAssignedInSectionOverall, double targetRatio, int curBook, int upperBookBound, bool forceAtLeastOneAssignmentInSection);
    long _buildSectionForDay(std::ofstream& ofile, int day, int totalDays, int& curBook, int& curChapters, long totalVersesPerDay, long& totalVersesAssignedInSection, double ratioToAssign, int upperBookBound, bool skipPsalmsAndProverbs, bool forceAtLeastOneAssignmentInSection = false, int adjustment = 0);
    bool _dayOverflowed(int day, long totalVersesPerDayLimit, long totalVersesAssignedOverall, long totalVersesAssignedForDay);
    KJVBible bible;
    
    long _totalVersesInBible;
    long _totalVersesInPsalms;
    double _ratioPsalms;
    long _totalVersesInProverbs;
    double _ratioProverbs;
    long _totalVersesInPsalmsAndProverbs;
    double _ratioPsalmsAndProverbs;
    long _totalVersesInNewTestament;
    double _ratioNewTestament;
    long _totalVersesInOldTestament;
    double _ratioOldTestament;
    long _totalVersesInOTModified;
    double _ratioOTModified;
    long _overalOverageMargin;
    long _dayOverageMargin;
    
    int _curOTBook;
    int _curOTBookChapter;
    int _curPsalmChapter;
    int _curProverbsChapter;
    int _curNTBook;
    int _curNTBookChapter;
    
    long _totalOTVersesAssigned;
    long _totalOTVersesToday;
    long _totalPsalmsVersesToday;
    long _totalProverbsVersesToday;
    long _totalNTVersesToday;
};

#endif /* CSVPlanBuilder_hpp */
