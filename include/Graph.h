#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <deque> //added

enum NodeCondition{
    Healthy,
    HasVirus,
    Infected
};

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    // added
    Graph();
    Graph(const Graph& other);
    std::vector<int> getNeighbours(int nodeInd) const;
    std::vector<int> getInfectedNodes(); // should that be const/ passed by ref? - Eden
    std::vector<std::vector<int>>& getEdgesRef();
    void addVirusOn(int nodeInd);
    bool isHealthy(int nodeInd);
    void removeNode(int nodeInd);
    //

private:
    std::vector<std::vector<int>> edges;
    // added
    std::vector<NodeCondition> nodesStatus;
};

#endif