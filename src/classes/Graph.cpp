#include "../../include/Graph.h"
#include "iostream"

Graph::Graph():edges(std::vector<std::vector<int>> ()) {}

Graph::Graph(std::vector<std::vector<int>> matrix):
edges(matrix)
{
    // Print input info to console
    std::cout << "input graph:" << std::endl;
    for (int i = 0, r=(edges).size() ; i < r ; i++)
    {
        for (int j = 0, c=(edges)[i].size(); j<c; j++) {
            std::cout << (edges)[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

Graph::Graph(const Graph &other)
:edges(other.edges)
{
}

Graph::~Graph() {
    edges.clear();
}

void Graph::infectNode(int nodeInd)
{

}
bool Graph::isInfected(int nodeInd)
{
    return false;
}

std::vector<std::vector<int>>* Graph::getEdgesCopy() {
    return new std::vector<std::vector<int>>(edges);
}

std::vector<int> Graph::getNeighbours(int nodeInd) const {
    auto neighbours = std::vector<int>();
    if(nodeInd>=0&&nodeInd<edges.size())
    {
        for(int neighbourInd=0;neighbourInd<edges[nodeInd].size();neighbourInd++)
        {
            if(edges[nodeInd][neighbourInd]==1)
                neighbours.push_back(neighbourInd);
        }
    }
    return neighbours;
}




