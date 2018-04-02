//
// Created by Nudzejma on 4/2/2018.
//

#include "Node.h"

Node::Node(const Node &node) {
    adjacentNodes = {};
    adjacentNodes = node.adjacentNodes;
    visited = node.visited;
    label = node.label;
}

Node::~Node() {
    while(!this->adjacentNodes.empty()) {
        removeAdjacentNode(this->adjacentNodes[this->adjacentNodes.size()-1]);
    }
}

void Node::addAdjacentNode(Node *node) {
    adjacentNodes.push_back(node);
    node->adjacentNodes.push_back(this);
}

void Node::removeAdjacentNode(Node *node) {
    auto removeIt = remove(adjacentNodes.begin(), adjacentNodes.end(), node);
    if (removeIt != adjacentNodes.end()) {
        adjacentNodes.erase(removeIt);
        node->adjacentNodes.erase(remove(node->adjacentNodes.begin(), node->adjacentNodes.end(), this));
    }
}

Node& Node::operator=(const Node &node) {
    if (this != &node) {
        for(auto adjacentNode : adjacentNodes)
            delete adjacentNode;
        adjacentNodes = {};
        adjacentNodes = node.adjacentNodes;
        visited = node.visited;
        label = node.label;
    }

    return *this;
}

bool Node::operator==(const Node &node) {
    return this->adjacentNodes == node.adjacentNodes && this->visited == node.visited && this->label == node.label;
}

bool Node::operator!=(const Node &node) {
    return !(this == &node);
}