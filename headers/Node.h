//
// Created by Nudzejma on 3/29/2018.
//

#ifndef ADVANCED_ALGORTHMS_NODE_H
#define ADVANCED_ALGORTHMS_NODE_H

#include <iostream>
#include <vector>

using namespace std;

class Node {

    vector<Node*> adjacent_nodes;
    bool visited;

public:

    Node() { adjacent_nodes = {}; visited = false; }
    Node(vector<Node*> adjacent_nodes) {
        adjacent_nodes = adjacent_nodes;
        visited = false;
    }
    vector<Node*> getAdjacentNodes() const { return adjacent_nodes; }
    void setAdjacentNodes(vector<Node*> adj_nodes) { adjacent_nodes = adj_nodes; }
    void addAdjacentNode(Node* node) {
        adjacent_nodes.push_back(node);
        node->adjacent_nodes.push_back(this);
    }
    bool isVisited() const { return visited; }
    void setVisited(bool v) { visited = v; }
};

#endif //ADVANCED_ALGORTHMS_NODE_H
