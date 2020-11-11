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
    Session& operator=(const Session& other); //Copy assignment operator
    Session(const Session& other); // Copy constructor
    Session(Session&& other); //move constructor
    Session& operator=(Session&& other); // move assignment
    Session& operator=(Session& other); // copy assignment
    void clean(); // used by move assignment+destructor
    virtual ~Session(); // destructor
    Tree* BFS(int rootLabel); // Create BFS tree based on given node the graph in session
    int getCycle() const; // getter for private member cycleCount
    Graph getGraph() const; // Eden
    //
    
private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
    //added
    int cycleCount;
    static json file_path_to_json(const std::string& path);
    void add_agents_from_json(const json& inputJson);
    static TreeType get_tree_type(const json& inputJson);
    void create_json_output();
    //
};

#endif