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
        int maxim_value;
        int better_score;
        int num_of_days;

        void mergeSort(island list[], int left, int right);
        void merge(island list[], int left, int middle, int right);

    
    public:
        Greedy(int num_of_islands, int maxim_value);
        ~Greedy();
        void addIsland(int cost, int score);
        void printList();
        void run();
        void run_dynamic();
        void orderByGreaterCostBenefit();
};





#endif