#ifndef ISLANDS_TRIP_
#define ISLANDS_TRIP_

#include <iostream>
#include <sstream>

struct island {
    int cost;
    int score;
    double cost_benefit;
};

class IslandsTrip {
    private:
        island *list;
        int num_of_elements;
        int maxim_value;
        int better_score;
        int num_of_days;

        void mergeSort(island list[], int left, int right);
        void merge(island list[], int left, int middle, int right);

    
    public:
        IslandsTrip(int num_of_islands, int maxim_value);
        ~IslandsTrip();
        void addIsland(int cost, int score);
        void printList();
        void run_greedy();
        void run_dynamic();
        void orderByGreaterCostBenefit();
};





#endif