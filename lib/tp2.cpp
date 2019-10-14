#include <stdlib.h>
#include <iostream>

#include "Greedy.h"

using namespace std;

int main() {
    
    Greedy g = Greedy(3);
    g.addIsland(2000,32);
    g.addIsland(500,4);
    g.addIsland(1000,30);

    g.printList();
    cout << endl;

    g.orderByGreaterCostBenefit();

    g.printList();
    cout << endl;

    return 0;
}