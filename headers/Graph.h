//
// Created by Nudzejma on 3/30/2018.
//

#ifndef ADVANCED_ALGORTIHMS_GRAPH_H
#define ADVANCED_ALGORTIHMS_GRAPH_H

#include "Node.h"

class Graph {

    vector<Node*> nodes;

public:
    Graph() = default;

    explicit Graph(unsigned int size) {
        nodes.resize(size);
    }
    void addNode(Node* node) {
        nodes.push_back(node);
    }
    vector<Node*> getNodes() const { return nodes; }
    void addEdge(Node* nodeFrom, Node* nodeTo) {
        nodeFrom->addAdjacentNode(nodeTo);
        nodeTo->addAdjacentNode(nodeFrom);
    }
};

#endif //ADVANCED_ALGORTIHMS_GRAPH_H
