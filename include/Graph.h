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
    std::vector<std::vector<int>> * getEdgesCopy(); //what for?
    std::vector<int> getNeighbours(int nodeInd) const;
    void setInfectedNodes(); //Eden
    std::vector<int> getInfectedNodes(); //Eden
    std::deque<int>* getInfectedCopy();
    void removeNode(int node);
//    int dequeueInfected();
    //

private:
    std::vector<std::vector<int>> edges;
    //added - Eden
    std::deque<int> infectedQueue;
    std::vector<int> infectedNodes;
};

#endif