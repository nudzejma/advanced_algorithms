//
// Created by Nudzejma on 4/2/2018.
//

#include "Graph.h"

Graph::Graph(const Graph &graph) : nodes({}), size(graph.size) {
    for(auto node : graph.nodes){
        auto *newGraphNode = new Node;
        *newGraphNode = *node;
        nodes.push_back(newGraphNode);
    }

    for (int i = 0; i < nodes.size(); ++i) {
        vector<Node*> newAdjacentNodes = {};
        for (int j = 0; j < nodes[i]->getAdjacentNodes().size(); ++j) {
            auto adjacentNode = nodes[i]->getAdjacentNodeAt(j);
            auto findingNode = find_if(nodes.begin(), nodes.end(), [adjacentNode](Node *adj) { return adjacentNode->getLabel() == adj->getLabel();});
            if (findingNode != nodes.end()) {
                newAdjacentNodes.push_back(*findingNode);
            }
        }
        nodes[i]->setAdjacentNodes(newAdjacentNodes);
    }
}

Graph::~Graph() {
    for (auto node : nodes)
        delete node;
    nodes.clear();
}

void Graph::addNode(Node *node) {
    if (this->size > this->nodes.size())
        nodes.push_back(node);
    else
        throw out_of_range("Graph cannot have more than his size. If you want graph to have more elements, resize it!" );
}

void Graph::addEdge(Node *nodeFrom, Node *nodeTo) {
    nodeFrom->addAdjacentNode(nodeTo);
    nodeTo->addAdjacentNode(nodeFrom);
}

void Graph::removeEdgesBetweenNodes(Node *node1, Node *node2) {
    node1->removeAdjacentNode(node2);
}

Graph& Graph::operator=(const Graph &graph) {
    if(this != &graph){
        nodes.clear();

        nodes = {};

        for(auto node : graph.nodes){
            auto *newGraphNode = new Node;
            *newGraphNode = *node;
            nodes.push_back(newGraphNode);
        }
        size = graph.size;
    }
    return *this;
}