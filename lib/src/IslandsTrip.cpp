#include "IslandsTrip.h"
#include <iostream>
#include <sstream>

using namespace std;

IslandsTrip::IslandsTrip(int num_of_islands, int maxim_value) {
    this->maxim_value = maxim_value;
    this->list = new island[num_of_islands];
    this->better_score = 0;
    this->num_of_days = 0;
    this->num_of_elements = 0;
}

IslandsTrip::~IslandsTrip() {

}

void IslandsTrip::addIsland(int cost, int score) {
    this->list[this->num_of_elements].cost = cost;
    this->list[this->num_of_elements].score = score;
    this->list[this->num_of_elements].cost_benefit = ((float)score/(float)cost);
    this->num_of_elements++;
}

void IslandsTrip::orderByGreaterCostBenefit() {
    this->mergeSort(this->list,0,this->num_of_elements-1);
}

void IslandsTrip::merge(island list[], int left, int middle, int right) {
    
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

void IslandsTrip::mergeSort(island list[], int left, int right) {
    if (left < right) {
        int middle = left + (right-left)/2;
        this->mergeSort(list, left, middle);
        this->mergeSort(list, middle+1, right);

        this->merge(list, left, middle, right);
    }
}

void IslandsTrip::run_greedy() {
    int max_value = this->maxim_value;
    int i = 0;
    while (max_value != 0) {
        if (max_value - this->list[i].cost >= 0) {
            this->num_of_days++;
            this->better_score = this->better_score + this->list[i].score;
            max_value = max_value - this->list[i].cost;
        } else {
            i++;
            if (i == this->num_of_elements)
                break;
        }
    }
    cout << this->better_score << " " << this->num_of_days << endl; 
}

int max(int a, int b) { return (a > b)? a : b; }

void IslandsTrip::run_dynamic() {
    int i, w;
    int K[this->num_of_elements+1][this->maxim_value+1];

    for(i=0; i<=this->num_of_elements; i++) {
        for(w=0; w<=this->maxim_value;w++) {
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if(this->list[i-1].cost <= w) 
                K[i][w] = max(this->list[i-1].score + K[i-1][w - this->list[i-1].cost], K[i-1][w]);
            else 
                K[i][w] = K[i-1][w];
        }
    }

    int final_score = K[this->num_of_elements][this->maxim_value];

    int number_of_islands = 0;
    int n = this->num_of_elements;
    int max = this->maxim_value;

    while(n != 0) {
        if (K[n][max] != K[n-1][max]) {
            max = max - this->list[n-1].cost;
            number_of_islands++;
        }
        n--;
    }

    cout << final_score << " " << number_of_islands << endl;
}

void IslandsTrip::printList() {
    for(int i=0; i<this->num_of_elements; i++) {
        cout << this->list[i].cost_benefit << ", ";
    }
}