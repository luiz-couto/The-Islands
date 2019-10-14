#include "Greedy.h"
#include <iostream>
#include <sstream>

using namespace std;

Greedy::Greedy(int num_of_islands) {
    this->list = new island[num_of_islands];
    this->num_of_elements = 0;
}

Greedy::~Greedy() {

}

void Greedy::addIsland(int cost, int score) {
    this->list[this->num_of_elements].cost = cost;
    this->list[this->num_of_elements].score = score;
    this->list[this->num_of_elements].cost_benefit = ((float)score/(float)cost);
    this->num_of_elements++;
}

void Greedy::orderByGreaterCostBenefit() {
    this->mergeSort(this->list,0,this->num_of_elements-1);
}

void Greedy::merge(island list[], int left, int middle, int right) {
    
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    island L[n1], R[n2];

    for (i=0; i<n1; i++)
        L[i] = list[left + i];
    for (j=0; j<n2; j++)
        R[j] = list[middle + 1 + j];

    i=0;
    j=0;
    k=left;

    while (i < n1 && j < n2){
        if(L[i].cost_benefit >= R[i].cost_benefit){
            list[k] = L[i];
            i++;
        } else {
            list[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        list[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        list[k] = R[j];
        j++;
        k++;
    }

}

void Greedy::mergeSort(island list[], int left, int right) {
    if (left < right) {
        int middle = left + (right-left)/2;
        this->mergeSort(list, left, middle);
        this->mergeSort(list, middle+1, right);

        this->merge(list, left, middle, right);
    }
}

void Greedy::printList() {
    for(int i=0; i<this->num_of_elements; i++) {
        cout << this->list[i].cost_benefit << ", ";
    }
}