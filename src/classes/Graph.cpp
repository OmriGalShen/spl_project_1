#include "../../include/Graph.h"
#include "iostream"
#include "vector"


//            ***constructors***


Graph::Graph(): //empty constructor
    edges(),
    infectedNodes()
{}

Graph::Graph(std::vector<std::vector<int>> matrix): //constructor
    edges(matrix),
    infectedNodes()
{}

Graph::Graph(const Graph &other): // copy constructor
    edges(other.edges),
    infectedNodes()   // not other.infectedNodes
{}


//            ***getters***



std::vector<int> Graph::getInfectedNodes()
{
    return infectedNodes;
}

//std::vector<std::vector<int>>* Graph::getEdgesCopy()
//{
//    return new std::vector<std::vector<int>>(edges);
//}



std::vector<int> Graph::getNeighbours(int nodeInd) const
{
    int row = nodeInd;
    int matSize = edges.size();
    //std::cout << "get nei-edges.size: " << edges.size() << std::endl;
    auto neighbours = std::vector<int>();
    if(row>=0 && row<matSize)
    {
        for(int col=0; col<matSize; col++)
        {
            if(edges[row][col] == 1)
                neighbours.push_back(col);
        }
    }
    return neighbours;
}



void Graph::infectNode(int nodeInd)
{
    if(! isInfected(nodeInd))
        infectedNodes.push_back(nodeInd);
}



std::vector<std::vector<int>> Graph::getEdges()
{
    return edges;
}

void Graph::setEdges(int row, int col, int num)
{
    edges[row][col] = num;
}



bool Graph::isInfected(int nodeInd)
{
    for(int currNode: infectedNodes)
    {
        if(currNode == nodeInd)
            return true;
    }
    return false;
}

