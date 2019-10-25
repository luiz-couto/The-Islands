#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "IslandsTrip.h"

using namespace std;

int main(int argc, char **argv) {
    
    if (argc < 2)
        return 0;
    
    int numberIslands;
    int maxScoreSum;

    string line;
    ifstream file(argv[1]);
    if (file.is_open()) {
        file >> maxScoreSum >> numberIslands; 
    }
    
    IslandsTrip islandsTrip = IslandsTrip(numberIslands,maxScoreSum);

    int islandScore;
    int islandCost;
    for (int i=0; i<numberIslands; i++){
        file >> islandCost >> islandScore;
        islandsTrip.addIsland(islandCost, islandScore);
    }
    
    islandsTrip.orderByGreaterCostBenefit();
    islandsTrip.run_greedy();

    islandsTrip.run_dynamic();
    
    return 0;
}