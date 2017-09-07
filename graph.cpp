#include "graph.h"

Graph::Graph()
{

}

Node *Graph::addNode()
{
    nodes.push_back(new Node);
    return nodes.back();
}

void Graph::addNode(Node *node)
{
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
