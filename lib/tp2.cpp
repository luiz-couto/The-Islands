#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Greedy.h"

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
    
    Greedy g = Greedy(numberIslands,maxScoreSum);
    
    int islandScore;
    int islandCost;
    for (int i=0; i<numberIslands; i++){
        file >> islandCost >> islandScore;
        g.addIsland(islandCost, islandScore);
    }
    
    g.orderByGreaterCostBenefit();
    g.run();

    g.run_dynamic();
    
    return 0;
}