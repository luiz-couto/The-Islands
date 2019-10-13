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

void Greedy::printList() {
    for(int i=0; i<this->num_of_elements; i++) {
        cout << this->list[i].cost_benefit << ", ";
    }
}