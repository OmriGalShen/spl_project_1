#include "../../include/Graph.h"
#include "iostream"
#include "vector"





//            ***constructors***


Graph::Graph(): // empty constructor
edges(), nodesStatus()
{}

Graph::Graph(std::vector<std::vector<int>> matrix): // constructor
edges(matrix), nodesStatus(matrix.size(),Healthy)
{}

Graph::Graph(const Graph &other): // copy constructor
edges(other.edges), nodesStatus(other.nodesStatus)
{}





//            ***getters***


std::vector<int> Graph::getInfectedNodes() const
{
    std::vector<int> infectedNodes;
    for(unsigned int i=0; i<nodesStatus.size(); i++)
    {
        if(nodesStatus[i] == Infected)
            infectedNodes.push_back(i);
    }
    return infectedNodes;
}

std::vector<int> Graph::getNeighbours(int nodeInd) const
{
    int row = nodeInd;
    int matSize = edges.size();
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

std::vector<std::vector<int>>& Graph::getEdgesRef()
{
    return edges;
}





//            ***other functions***


void Graph::infectNode(int nodeInd)
{
    nodesStatus[nodeInd] = Infected;
}

void Graph::addVirusOn(int nodeInd)
{
    if(nodesStatus[nodeInd] == Healthy)
        nodesStatus[nodeInd] = HasVirus;
}

bool Graph::isHealthy(int nodeInd)
{
    return nodesStatus[nodeInd] == Healthy;
}

bool Graph::isInfected(int nodeInd)
{
    return nodesStatus[nodeInd] == Infected;
}

void Graph::removeNode(int nodeInd)
{
    int verticesCount = edges.size();
    if(nodeInd>=0 && nodeInd<verticesCount) // to verify that the input is valid
    {
        for(int index=0; index<verticesCount; index++)
        {
            edges[index][nodeInd] = 0;
            edges[nodeInd][index] = 0;
        }
    }
}