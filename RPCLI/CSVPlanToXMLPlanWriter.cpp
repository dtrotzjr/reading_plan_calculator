//
//  CSVPlanToXMLPlanWriter.cpp
//  RPCLI
//
//  Created by David Trotz on 9/2/18.
//  Copyright © 2018 TrotzSoftware. All rights reserved.
//

#include "CSVPlanToXMLPlanWriter.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include "KJVBible.h"

using namespace std;

CSVPlanToXMLPlanWriter::CSVPlanToXMLPlanWriter()
{
    
}


CSVPlanToXMLPlanWriter::~CSVPlanToXMLPlanWriter()
{
    
}


void CSVPlanToXMLPlanWriter::Convert(const char* inFile, const char* outFile)
{
    ofstream ofile;
    ifstream ifile;
    ofile.open(outFile);
    ifile.open(inFile);
    KJVBible bible;
    
    if(ofile.is_open() && ifile.is_open()) {
        string csvLine;
        
        while( getline(ifile, csvLine) )
        {
            std::regex rNewLine("[\\n\\r]+");
            csvLine = std::regex_replace(csvLine, rNewLine, "");
            
            istringstream csvStream(csvLine);
            string strCol;
            // read every element from the line that is seperated by commas
            // and put it into the vector or strings
            int colIndex = 0;
            while( getline(csvStream, strCol, ',') )
            {
                if (colIndex++ == 0) {
                    ofile << "\t\t<otPlanDay day=\""<< strCol << "\">" << endl;
                } else {
                    istringstream assignments(strCol);
                    string assignment;
                    while (getline(assignments, assignment, '#')) {
                        istringstream parts(assignment);
                        string part;
                        string bookName, fromChapter, toChapter;
                        int partNum = 0;
                        while (getline(parts, part, '_')) {
                            switch (partNum++) {
                                case 0:
                                    bookName = part;
                                    break;
                                case 1:
                                {
                                    istringstream chapters(part);
                                    string chapter;
                                    int chapPartNum = 0;
                                    while (getline(chapters, chapter, '-')) {
                                        switch (chapPartNum++) {
                                            case 0:
                                                fromChapter = chapter;
                                                break;
                                            case 1:
                                                toChapter = chapter;
                                                break;
                                            default:
                                                assert(false);
                                        }
                                    }
                                }
                                    break;
                                default:
                                    assert(false);
                            }
                        }
                        if(bookName.length() > 0 ) {
                            int otBookNumber = bible.getBookNumber(bookName) +  1;
                            if(otBookNumber > 0 && fromChapter.length() > 0 && toChapter.length() > 0) {
                                ofile << "\t\t\t<otDayAssignment" <<
                                " begin=\"" << otBookNumber << "." << fromChapter << ".1\""  <<
                                " end=\"" <<  otBookNumber << "." << toChapter << ".ff\" />" <<
                                endl;
                            }
                        }
                    }
                    
                }
            }
            ofile << "\t\t</otPlanDay>" << endl;
            
        }
    }
    ofile.close();
    ifile.close();
}

