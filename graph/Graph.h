//
// Created by Nudzejma on 4/2/2018.
//

#ifndef ADVANCED_ALGORTIHMS_GRAPH_H
#define ADVANCED_ALGORTIHMS_GRAPH_H


#include "../node/Node.h"

class Graph {
    vector<Node*> nodes;
    int size;
public:
    explicit Graph(unsigned int size) : nodes({}), size(size) {}
    Graph(const Graph& graph);
    ~Graph();
    void addNode(Node* node);
//  inline methods
    inline vector<Node*> getNodes() const { return nodes; }
    inline Node* getNodeAt(int position) const { return nodes[position]; }
    inline int getSize() const { return size; }
    inline void setSize(int size) { this->size = size; }
//  methods defined in Graph.cpp
    void addEdge(Node* nodeFrom, Node* nodeTo);
    void removeEdgesBetweenNodes(Node *node1, Node *node2);
//  operators
    Graph& operator=(const Graph& graph);
};


#endif //ADVANCED_ALGORTIHMS_GRAPH_H
