//
// Created by Nudzejma on 3/29/2018.
//
#include <iostream>
#include "graph/Graph.h"
#include "maxCycleDecomposition/maxCycledecomposition.h"

using namespace std;

int main() {
    try {
        Node *node1 = new Node("1");
        Node *node2 = new Node("2");
        Node *node3 = new Node("3");
        Node *node4 = new Node("4");
        Node *node5 = new Node("5");
        Node *node6 = new Node("6");
        Node *node7 = new Node("7");
        Node *node8 = new Node("8");

        node1->addAdjacentNode(node2);
        node1->addAdjacentNode(node3);
        node2->addAdjacentNode(node3);

        node3->addAdjacentNode(node4);
        node3->addAdjacentNode(node5);
        node4->addAdjacentNode(node5);

        node4->addAdjacentNode(node6);
        node4->addAdjacentNode(node8);
        node6->addAdjacentNode(node7);
        node7->addAdjacentNode(node8);

        Graph graph(8);
        graph.addNode(node8);
        graph.addNode(node2);
        graph.addNode(node4);
        graph.addNode(node1);
        graph.addNode(node3);
        graph.addNode(node5);
        graph.addNode(node6);
        graph.addNode(node7);

        vector< vector<Node*> > cycleDecomposition = getMaxCycleDecomposition(graph);
        cout << "Max cycle decomposition has " << cycleDecomposition.size() << " cycles." << endl;
        for(int i=0; i<cycleDecomposition.size(); i++) {
            cout  << "Cycle " << (i+1) << " with " << cycleDecomposition[i].size() << " nodes: " << endl;
            for(int j=0; j<cycleDecomposition[i].size(); j++) {
                cout <<  cycleDecomposition[i][j]->getLabel() << " ";
            }
            cout << endl;
        }
    } catch (const out_of_range& oor) {
        cout << oor.what() << endl;
    }

    return 0;
}
