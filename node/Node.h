//
// Created by Nudzejma on 4/2/2018.
//

#ifndef ADVANCED_ALGORTIHMS_NODE_H
#define ADVANCED_ALGORTIHMS_NODE_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
    vector<Node*> adjacentNodes;
    bool visited;
    string label;
public:
    Node() : adjacentNodes({}), visited(false), label("") {}
    explicit Node(string label) : adjacentNodes({}), visited(false), label(label) {}
    explicit Node(vector<Node*> adjacentNodes, string label) : adjacentNodes(adjacentNodes), visited(false), label(label) {}
    Node(const Node& node);
    ~Node();
//  inline defined methods
    inline vector<Node*> getAdjacentNodes() const { return adjacentNodes; }
    inline Node* getAdjacentNodeAt(int position) const { return adjacentNodes[position]; }
    inline void setAdjacentNodes(vector<Node*> adj_nodes) { adjacentNodes = adj_nodes; }
    inline bool isVisited() const { return visited; }
    inline void setVisited(bool v) { visited = v; }
    inline string getLabel() const { return label; }
    inline void setLabel(string label) { this->label = label; }
//  methods defined in Node.cpp
    void addAdjacentNode(Node* node);
    void removeAdjacentNode(Node *node);
//  operators
    Node& operator=(const Node& node);
    bool operator==(const Node &node);
    bool operator!=(const Node &node);
};


#endif //ADVANCED_ALGORTIHMS_NODE_H
