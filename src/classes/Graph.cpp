#include "../../include/Graph.h"
#include "iostream"
#include "vector"


//            ***constructors***


Graph::Graph(): //empty constructor
    edges(),
    nodesStatus()
    {}

Graph::Graph(std::vector<std::vector<int>> matrix): //constructor
    edges(matrix),
    nodesStatus(std::vector<NodeCondition>(matrix.size(),Healthy))
{}

Graph::Graph(const Graph &other): // copy constructor
    edges(other.edges),
    nodesStatus(other.nodesStatus)
{}


//            ***getters***



std::vector<int> Graph::getInfectedNodes()
{
    std::vector<int> infectedNodes;
    for(unsigned int i=0;i<nodesStatus.size();i++)
        if(nodesStatus[i]==Infected)
            infectedNodes.push_back(i);
    return infectedNodes;
}




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
    nodesStatus[nodeInd] = Infected;
}

void Graph::addVirusOn(int nodeInd)
{
    if(nodesStatus[nodeInd]==Healthy)
        nodesStatus[nodeInd]=HasVirus;
}

bool Graph::isHealthy(int nodeInd){return nodesStatus[nodeInd]==Healthy;}



std::vector<std::vector<int>> Graph::getEdges()
{
    return edges;
}

void Graph::setEdges(int row, int col, int num)
{
    edges[row][col] = num;
}

//void Graph::setInfected(int node)
//{
//    infectedNodes.push_back(node);
//}

bool Graph::isInfected(int nodeInd)
{
    return nodesStatus[nodeInd] == Infected;
}

void Graph::printGraph()
{
    for ( const auto &row : edges )
    {
        for ( const auto &s : row ) std::cout << s << ' ';
        std::cout << std::endl;
    }
}

void Graph::removeNode(int nodeInd)
{
//    std:: cout << "Graph before removal" << std::endl;
//    printGraph();
    int verticesCount =  edges.size();
    if(nodeInd>=0 && nodeInd<verticesCount) // to verify that the input is valid
    {
        for(int index=0; index<verticesCount; index++)
        {
            edges[index][nodeInd] = 0;
            edges[nodeInd][index] = 0;
        }
    }
//    std:: cout << "Graph after removal" << std::endl;
//    printGraph();
}