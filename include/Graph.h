#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <deque> //added

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    //added
    Graph();
    bool isInfectedEmpty();
    Graph(const Graph& other);
    std::vector<std::vector<int>> * getEdgesCopy();
    std::vector<int> getNeighbours(int nodeInd) const;
    unsigned int getVerticesCount() const;
    void removeEdge(int firstNode, int secondNode);
    int dequeueInfected();
    std::deque<int>* getInfectedCopy();
    void removeNode(int node);
    void printGraph();

    //

private:
    std::vector<std::vector<int>> edges;
    std::deque<int> infectedQueue; //added
};

#endif