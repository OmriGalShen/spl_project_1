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
    Session(const Session& other);
    virtual ~Session();
    Tree* BFS(int rootLabel);
    int getCycle() const;
    void removeNode(int node);
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