//
// Created by Nudzejma on 3/29/2018.
//
#include <iostream>
#include "headers/Graph.h"

using namespace std;

int main() {
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    node1->addAdjacentNode(node2);

    Graph graph;
    graph.addNode(node1);
    graph.addNode(node2);
    graph.addNode(node3);

    return 0;
}
