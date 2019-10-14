#include "Greedy.h"
#include <iostream>
#include <sstream>

using namespace std;

Greedy::Greedy(int num_of_islands, int maxim_value) {
    this->maxim_value = maxim_value;
    this->list = new island[num_of_islands];
    this->better_score = 0;
    this->num_of_days = 0;
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
    
    int posLivre, inicio_vetor1, inicio_vetor2, i;
    island aux[this->num_of_elements];
    inicio_vetor1 = left;
    inicio_vetor2 = middle+1;
    posLivre = left;
    while (inicio_vetor1 <= middle && inicio_vetor2 <= right) {
        if (list[inicio_vetor1].cost_benefit >= list[inicio_vetor2].cost_benefit) {
            aux[posLivre] = list[inicio_vetor1];
            inicio_vetor1++;
        } else {
            aux[posLivre] = list[inicio_vetor2];
            inicio_vetor2++;
        }
        posLivre++;
    }
    for(int i=inicio_vetor1; i<= middle; i++){
        aux[posLivre] = list[i];
        posLivre++;
    }
    for(int i=inicio_vetor2; i<= right; i++){
        aux[posLivre] = list[i];
        posLivre++;
    }
    for(int i=left; i<= right; i++){
        list[i] = aux[i];
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

void Greedy::run() {
    int i = 0;
    while (this->maxim_value != 0) {
        if (this->maxim_value - this->list[i].cost >= 0) {
            this->num_of_days++;
            this->better_score = this->better_score + this->list[i].score;
            this->maxim_value = this->maxim_value - this->list[i].cost;
        } else {
            i++;
            if (i == this->num_of_elements)
                break;
        }
    }
    cout << this->better_score << " " << this->num_of_days << endl; 
}

void Greedy::printList() {
    for(int i=0; i<this->num_of_elements; i++) {
        cout << this->list[i].cost_benefit << ", ";
    }
}