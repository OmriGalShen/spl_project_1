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
    Graph(const Graph& other);
    std::vector<std::vector<int>> * getEdgesCopy(); //what for? - Eden
    std::vector<int> getNeighbours(int nodeInd) const;
    std::vector<int> getInfectedNodes();
    std::deque<int> getInfectedQueue();
    void removeNode(int node);
    //int getEdgesSize();
    std::vector<std::vector<int>> getEdges();
    //

private:
    std::vector<std::vector<int>> edges;
    //added - Eden
    std::deque<int> infectedQueue;
    std::vector<int> infectedNodes;
};

#endif