#include "../../include/Graph.h"
#include "iostream"
#include "vector"


//            ***constructors***


Graph::Graph(): //empty constructor
edges(),
infectedQueue(),
infectedNodes()
{}

Graph::Graph(std::vector<std::vector<int>> matrix): //constructor
edges(matrix),
infectedQueue(),
infectedNodes()
{}

Graph::Graph(const Graph &other): // copy constructor
edges(other.edges),
infectedQueue(other.infectedQueue),
infectedNodes(other.infectedNodes)
{}


//            ***getters***

//void Graph::setInfectedNodes()
//{
//    infectedNodes=(0);
//}

std::vector<int> Graph::getInfectedNodes()
{
//    if (!infectedNodes.empty())
        return infectedNodes;
}

std::vector<std::vector<int>>* Graph::getEdgesCopy() {
    return new std::vector<std::vector<int>>(edges);
}

std::vector<int> Graph::getNeighbours(int nodeInd) const {
    size_t rowInd = nodeInd;
    auto neighbours = std::vector<int>();
    if(rowInd>=0&&rowInd<edges.size())
    {
        for(size_t colInd=0,len=edges.size();colInd<len;colInd++)
        {
            if(edges[nodeInd][colInd]==1)
                neighbours.push_back(colInd);
        }
    }
    return neighbours;
}




std::deque<int>* Graph::getInfectedCopy()
{
    return new std::deque<int>(infectedQueue);
}


//void Graph::infectNode(int nodeInd)
//{
//    if(!isInfected(nodeInd))
//    {
//        //std::cout << "infecting node" << nodeInd << std::endl;
//      infectedQueue.push_back(nodeInd);          // ***doesn't work
//    }
//}
//
//int Graph::dequeueInfected()
//{
//    if(!infectedQueue.empty())
//    {
//        int nodeTemp = infectedQueue.front();
//        infectedQueue.pop_front();
//        return nodeTemp;
//    }
//    return -1;
//}
//
//bool Graph::isInfected(int nodeInd)
//{
//    for(int currNode: infectedNodes)
//        if(currNode == nodeInd)
//            return true;
//    return false;
//}



//void Graph::removeNode(int node)
//{
////    std::cout << "IN removeNode:"<< node << std::endl;
////    std::cout << "row:"<< edges.size() << std::endl;
////    std::cout << "col:"<< edges[0].size() << std::endl;
//    //using size_t to compare with .size() without warnings
//    int matSize = edges.size();
//    if(node>=0 && node<matSize) // to verify that the input is valid
//    {
//        for(int row=0, len=matSize; row<len; row++)
//            edges[row][node]=0;
//        for(int col=0, len=matSize; col<len; col++)
//            edges[node][col]=0;
//    }
//}
