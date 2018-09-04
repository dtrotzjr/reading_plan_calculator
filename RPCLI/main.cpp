//
//  main.cpp
//  RPCLI
//
//  Created by David Trotz on 7/31/18.
//  Copyright © 2018 TrotzSoftware. All rights reserved.
//

#include "CSVPlanBuilder.hpp"
#include "CSVPlanToXMLPlanWriter.hpp"

int main(int argc, const char * argv[]) {
//    CSVPlanBuilder builder(20, 20);
//    builder.Build(90, "/Users/dctrotz/tmp/plan_90_.csv");
    
    CSVPlanToXMLPlanWriter csvToXML;
    csvToXML.Convert("/Users/dctrotz/tmp/plan_90_rev_d.csv", "/Users/dctrotz/tmp/plan_90_rev_d.xml");
    return 0;
}
