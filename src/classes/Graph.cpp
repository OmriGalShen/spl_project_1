#include "../../include/Graph.h"
#include <vector>

using namespace std;





//                           *** constructors ***


Graph::Graph(): edges(), nodesStatus() // empty constructor
{}


Graph::Graph(vector<vector<int>> matrix): // constructor
edges(matrix), nodesStatus(matrix.size(), Healthy)
{}


Graph::Graph(const Graph &other) = default; // copy constructor





//                           *** getters ***


vector<int> Graph::getInfectedNodes() const
{
    vector<int> infectedNodes;
    for(unsigned int i=0; i<nodesStatus.size(); i++)
    {
        if(nodesStatus[i] == Infected)
            infectedNodes.push_back(i);
    }
    return infectedNodes;
}


vector<int> Graph::getNeighbours(int nodeInd) const
{
    int row = nodeInd;
    int size = edges.size();
    vector<int> neighbours;
    if(row>=0 && row<size)
    {
        for(int col=0; col<size; col++)
        {
            if(edges[row][col] == 1)
                neighbours.push_back(col);
        }
    }
    return neighbours;
}


const vector<vector<int>>& Graph::getEdgesRef() const
{
    return edges;
}





//                           *** other functions ***


void Graph::infectNode(int nodeInd)
{
    nodesStatus[nodeInd] = Infected;
}


void Graph::addVirusOn(int nodeInd)
{
    if(nodesStatus[nodeInd] == Healthy)
        nodesStatus[nodeInd] = HasVirus;
}


bool Graph::isHealthy(int nodeInd) const
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