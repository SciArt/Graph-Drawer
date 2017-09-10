#include "graph.h"

Graph::Graph()
{

}

Node *Graph::addNode()
{
    nodes.push_back(new Node);
    nodes.back()->graphicsView = graphicsView;
    return nodes.back();
}

void Graph::addNode(Node *node)
{
    node->graphicsView = graphicsView;
    nodes.push_back(node);
}

bool Graph::deleteNode(Node *node)
{
    for( unsigned int i = 0; i < nodes.size(); ++i )
    {
        if(nodes[i] == node)
        {
            nodes.erase(nodes.begin()+i);
            return true;
        }
    }
    return false;
}

Node *Graph::getNode(unsigned int index_of_node)
{
    return nodes[index_of_node];
}

Edge* Graph::addEdge(Node *n1, Node *n2)
{
    Edge* edge = new Edge;
    edge->node1 = n1;
    edge->node2 = n2;
    edges.push_back(edge);
    return edges.back();
}
