#include "../../include/Graph.h"
#include "iostream"
#include "vector"


//            ***constructors***


Graph::Graph(): //empty constructor
    edges(),
    //infectedQueue(),
    infectedNodes()
{}

Graph::Graph(std::vector<std::vector<int>> matrix): //constructor
    edges(matrix),
    //infectedQueue(),
    infectedNodes()
{}

//Graph::Graph(const Graph &other): // copy constructor
//    edges(),
//    infectedQueue(),
//    infectedNodes()   // not other.infectedNodes
//{}


//            ***getters***



std::vector<int> Graph::getInfectedNodes()
{
    return infectedNodes;
}

std::vector<std::vector<int>>* Graph::getEdgesCopy()
{
    return new std::vector<std::vector<int>>(edges);
}



std::vector<int> Graph::getNeighbours(int nodeInd) const
{
    int row = nodeInd;
    auto neighbours = std::vector<int>();
    if(row>=0 && row<edges.size())
    {
        for(int col=0; col<edges.size(); col++)
        {
            if(edges[row][col] == 1)
                neighbours.push_back(col);
        }
    }
    return neighbours;
}


//std::deque<int> Graph::getInfectedQueue()
//{
//    return infectedQueue;
//}


void Graph::infectNode(int nodeInd)
{
    if(!isInfected(nodeInd))
        infectedNodes.push_back(nodeInd);
}


//int Graph::getEdgesSize()
//{
//    return edges.size();
//}



std::vector<std::vector<int>> Graph::getEdges()
{
    return edges;
}



bool Graph::isInfected(int nodeInd)
{
    for(int currNode: infectedNodes)
        if(currNode == nodeInd)
            return true;
    return false;
}



void Graph::removeNode(int node)
{
//   std::cout << "IN removeNode:"<< node << std::endl;
//   std::cout << "row:"<< edges.size() << std::endl;
//    std::cout << "col:"<< edges[0].size() << std::endl;
    int matSize = edges.size();
    if(node>=0 && node<matSize) // to verify that the input is valid
    {
        for(int row=0; row<matSize; row++)
            edges[row][node]=0;
        for(int col=0; col<matSize; col++)
            edges[node][col]=0;
    }
}
