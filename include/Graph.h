#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <deque>

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    Graph();
    Graph(const Graph& other);
    ~Graph();
    std::vector<std::vector<int>> * getEdgesCopy();
    std::vector<int> getNeighbours(int nodeInd) const;
    unsigned int getVerticesCount() const;
    
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    int dequeueInfected();
    std::deque<int>* getInfectedCopy();

private:
    std::vector<std::vector<int>> edges;
    std::deque<int> infectedQueue;
};

#endif