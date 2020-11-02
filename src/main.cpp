#include <iostream>
#include "Session.h"
#include "Graph.h"
#include "Agent.h"
#include "Tree.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include "vector"

// for convenience
using json = nlohmann::json;
using namespace std;

json file_location_to_json(const string& location); //function to read json file
void add_agents_from_json(vector<Agent>& agentList, const json& inputJson);

int main(int argc, char** argv)
{
    auto* agentList = new vector<Agent>();// list of agents with ContactTracer and Virus objects
    vector<vector<int>> graphMatrix;// A 2d vector representing the graph matrix

     if(argc != 2) // json file for testing was not given as argument in terminal
     {
         cout << "usage cTrace <config_path>" << endl;
         return 0;
     }
     else // json file for testing was given as argument in terminal
     {
         json inputJson = file_location_to_json(argv[1]); //get json
         add_agents_from_json(*agentList,inputJson);
         graphMatrix = inputJson.at("graph").get<vector<vector<int>>>();
         // Print graph to console
         cout << "input graph:" << endl;
         for (int i = 0, r=graphMatrix.size() ; i < r ; i++)
         {
             for (int j = 0, c=graphMatrix[i].size(); j<c; j++) {
                 cout << graphMatrix[i][j] << ' ';
             }
             cout << endl;
         }
         // Session sess(argv[1]);
         // sess.simulate();
     }
     // -- Free heap memory allocation ----------------
     // -- Please update with every heap allocation  --
     agentList->clear();
     delete agentList;
     agentList = nullptr;
     // ----------------------------------
    cout<< "Hello World!" << endl;
    return 0;
}

json file_location_to_json(const string& location)
{
    string myText;
    ifstream MyReadFile(location);
    json j;
    MyReadFile >> j;
    MyReadFile.close();
    return j;
}

void add_agents_from_json(vector<Agent>& agentList, const json& inputJson)
{
    for (auto const& agentsJson : inputJson.at("agents"))
    {
        auto agent_type = agentsJson.at(0);
        auto agent_index = agentsJson.at(1); // the node index of the agent
        if(agent_type == "C")
        {
            cout << "This is a contact Tracer" << endl;
            cout << "his node is: " << agent_index << endl;
        }
        else if(agent_type == "V")
        {
            cout << "This is a Virus" << endl;
            cout << "his node is: " << agent_index << endl;
        }
    }
}