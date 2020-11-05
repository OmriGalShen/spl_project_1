#include "../../include/Graph.h"
#include "iostream"

Graph::Graph() {}

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

void Graph::infectNode(int nodeInd)
{

}
bool Graph::isInfected(int nodeInd)
{

}



