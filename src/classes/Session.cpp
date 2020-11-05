#include "../../include/Session.h"
#include <fstream>
#include "Tree.h"
#include "Agent.h"
#include "iostream"
// for convenience
using namespace std;


Session::Session(const std::string& path)
:g(),treeType(Root),agents(std::vector<Agent*>())
{
    //get json file by location given as argument
    json inputJson = file_path_to_json(path);
    // add agents given by the json input to the agent vector
    add_agents_from_json(inputJson);
    // get the graph matrix and point graphMatrix to it
    g = Graph(inputJson["graph"]);
    // get type of tree to use in Session
    treeType = get_tree_type(inputJson);
}

Session::Session(const Session& other)
:g(other.g),treeType(other.treeType),agents(std::vector<Agent*>())
{
    for(auto agent : other.agents)
    {
        Agent* agentClone = agent->clone();
        agents.push_back(agentClone);
    }
}

void Session::simulate()
{
    // Print input info to console
    cout << "Agents list:" << endl;
    for(auto& agent: agents)
    {
        if(typeid(agent) == typeid(ContactTracer))
            cout << "This is a Contact Tracer" <<endl;
        else
            cout << "This is a Virus" << endl;
    }
//    cout << "input graph:" << endl;
//    for (int i = 0, r=(*graphMatrix).size() ; i < r ; i++)
//    {
//        for (int j = 0, c=(*graphMatrix)[i].size(); j<c; j++) {
//            cout << (*graphMatrix)[i][j] << ' ';
//        }
//        cout << endl;
//    }
    cout<< "In simulate!" << endl;
}

Session::~Session()
{
    // -- Free heap memory allocation ----------------
    // -- Please update with every heap allocation  --
    agents.clear();
    // ----------------------------------
}

void Session:: addAgent(const Agent& agent)
{
    Agent* clone = agent.clone();
    agents.push_back(clone);
}
void Session::setGraph(const Graph& graph)
{

}

void Session::enqueueInfected(int)
{

}
int Session::dequeueInfected()
{

}
TreeType Session::getTreeType() const
{
    return treeType;
}


json Session::file_path_to_json(const std::string& path)
{
    ifstream i(path);
    json j;
    j << i;
    return j;
}

void Session::add_agents_from_json(const json& inputJson)
{
    for (auto& agent : inputJson.at("agents"))
    {
        auto agent_type = agent.at(0); //type of agent "C" or "V"
        auto agent_index = agent.at(1); // the node index of the agent
        if(agent_type == "C") // Agent is contact tracer
        {
            const Agent* contact_ptr = new ContactTracer((*this));
            this->addAgent((*contact_ptr));
        }
        else if(agent_type == "V") // Agent is virus
        {
            const Agent* virus_ptr = new Virus(agent_index,(*this));
            this->addAgent((*virus_ptr));
        }
    }
}



TreeType Session::get_tree_type(const json& inputJson)
{
    string type = inputJson.at("tree").get<string>();
    if(type=="R")
        return Root;
    else if(type=="C")
        return Cycle;
    else
        return MaxRank;
}