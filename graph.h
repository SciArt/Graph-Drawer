#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "node.h"
#include "edge.h"

class Graph
{
public:
    Graph();

    Node* addNode();
    void addNode(Node* node);
    bool deleteNode(Node* node);
    Node* getNode(unsigned int index_of_node);

    Edge* addEdge();
    void addEdge(Edge* edge);
    bool deleteEdge(Edge* edge);
    Edge* getEdge(unsigned int index_of_edge);

private:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;
};

#endif // GRAPH_H
