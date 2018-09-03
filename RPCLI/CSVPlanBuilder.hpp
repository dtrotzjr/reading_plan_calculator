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
    CSVPlanBuilder();
    void Build(int totalDays, const char* outputFile);
protected:
    bool _nextChapter(int& curBook, int& curChapter, bool skipPsalmsAndProverbs);
    bool _dayIsComplete(int day, int totalDays, long totalVersesPerDay, long totalVersesAssignedInSection, double ratio, int curBook, int upperBookBound);
    long _buildSection(std::ofstream& ofile, int day, int totalDays, int& curBook, int& curChapters, long totalVersesPerDay, long& totalVersesAssignedInSection, double ratioToAssign, int upperBookBound, bool skipPsalmsAndProverbs, int adjustment = 0);
    bool _dayWasOverflow(long totalVersesPerDay, long totalVersesAssigned);
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
