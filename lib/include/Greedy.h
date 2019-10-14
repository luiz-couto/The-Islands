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

        void mergeSort(island list[], int left, int right);
        void merge(island list[], int left, int middle, int right);

    
    public:
        Greedy(int num_of_islands);
        ~Greedy();
        void addIsland(int cost, int score);
        void printList();
        void orderByGreaterCostBenefit();
};





#endif