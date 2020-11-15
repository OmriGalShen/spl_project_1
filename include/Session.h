#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <string>
#include "Graph.h"
#include "json.hpp"  //used for working with json files
#include "Tree.h" //added


// for convenience
using json = nlohmann::json; //used for working with json files

class Agent;

enum TreeType{
  Cycle,
  MaxRank,
  Root
};

class Session{
public:
    Session(const std::string& path);
    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);
    void enqueueInfected(int);
    int dequeueInfected();
    TreeType getTreeType() const;
    //added
    void jsonOutput();
    Session(const Session& other); // Copy constructor
    Session(Session&& other); //move constructor
    Session& operator=(const Session& other); // copy assignment
    Session& operator=(Session&& other); // move assignment
    void clean(); // used by move assignment+destructor
    virtual ~Session(); // destructor
    Tree* BFS(int rootLabel); // Create BFS tree based on given node the graph in session
    int getCycle() const; // getter for private member cycleCount
    Graph& getGraphRef();
    //
    
private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
    //added
    std::deque<int> infectedQueue;
    int cycleCount;
    //
};

#endif