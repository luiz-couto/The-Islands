#ifndef GREEDY_
#define GREEDY_

#include <iostream>
#include <sstream>

struct island {
    int cost;
    int score;
    double cost_benefit;
};

class Greedy {
    private:
        island *list;
        int num_of_elements;
    
    public:
        Greedy(int num_of_islands);
        ~Greedy();
        void addIsland(int cost, int score);
        void printList(); 
};





#endif