//
// Created by Nudzejma on 4/2/2018.
//

#ifndef ADVANCED_ALGORTIHMS_MAXCYCLEDECOMPOSITION_H
#define ADVANCED_ALGORTIHMS_MAXCYCLEDECOMPOSITION_H

#include <stack>
#include "../node/Node.h"
#include "../graph/Graph.h"

vector< vector<Node*> > getMaxCycleDecomposition(const Graph &eulerianGraph) {
    vector< vector<Node*> > maxCycleDecomposition = {};
    Graph copiedEulerianGraph(eulerianGraph);
    stack<Node*> nodes;
    stack<Node*> dfsVisitedNodes;

    for (int i=0; i<copiedEulerianGraph.getNodes().size(); i++) {
        copiedEulerianGraph.getNodeAt(i)->setVisited(false);
    }

    Node *node = copiedEulerianGraph.getNodes()[0];
    dfsVisitedNodes.push(node);

    Node *toTop = node;

    while(!dfsVisitedNodes.empty()) {

        node = dfsVisitedNodes.top();
        if (!node->isVisited()) {
            node->setVisited(true);
            dfsVisitedNodes.pop();

            if (!nodes.empty()) {
                toTop = nodes.top();
            }
            nodes.push(node);

            for (int i = 0; i < node->getAdjacentNodes().size(); i++) {
                Node *adjacentNode = node->getAdjacentNodeAt(i);
                if (!adjacentNode->isVisited()) {

                    dfsVisitedNodes.push(adjacentNode);
                } else {
                    if (toTop != adjacentNode) {
                        vector<Node*> cycleDecomposition;
                        Node *n = nodes.top();
                        nodes.pop();
                        cycleDecomposition.push_back(n);
                        while (n != adjacentNode && !nodes.empty()) {
                            copiedEulerianGraph.removeEdgesBetweenNodes(n, nodes.top());
                            n = nodes.top();
                            nodes.pop();
                            cycleDecomposition.push_back(n);
                        }
                        copiedEulerianGraph.removeEdgesBetweenNodes(cycleDecomposition[0], cycleDecomposition[cycleDecomposition.size()-1]);
                        maxCycleDecomposition.push_back(cycleDecomposition);

                        for (int j=0; j<copiedEulerianGraph.getNodes().size(); j++) {
                            copiedEulerianGraph.getNodeAt(j)->setVisited(false);
                        }

                        toTop = nullptr;
                    }
                }

            }
        } else {
            dfsVisitedNodes.pop();
        }
    }

    return maxCycleDecomposition;
}

#endif //ADVANCED_ALGORTIHMS_MAXCYCLEDECOMPOSITION_H
