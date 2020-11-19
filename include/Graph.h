#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <deque> //added

// for convenience
using namespace std;



enum NodeCondition{
    Healthy,
    HasVirus,
    Infected
};


class Graph{
public:
    Graph(vector<vector<int>> matrix); // constructor
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    // added
    Graph(); // empty constructor
    Graph(const Graph& other); // copy constructor
    vector<int> getNeighbours(int nodeInd) const;
    vector<int> getInfectedNodes() const;
    const vector<vector<int>>& getEdgesRef() const;
    void addVirusOn(int nodeInd);
    bool isHealthy(int nodeInd) const;
    void removeNode(int nodeInd);
    //


private:
    vector<vector<int>> edges;
    // added
    vector<NodeCondition> nodesStatus;
    //
};

#endif