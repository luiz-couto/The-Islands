#include <stdlib.h>
#include <iostream>

#include "Greedy.h"

using namespace std;

int main() {
    
    Greedy g = Greedy(5,6000);
    g.addIsland(1000,30);
    g.addIsland(2000,32);
    g.addIsland(500,4);
    g.addIsland(5000, 90);
    g.addIsland(2200,45);

    g.orderByGreaterCostBenefit();
    g.run();

    g.run_dynamic();
    
    return 0;
}