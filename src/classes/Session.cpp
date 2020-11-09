#include "../../include/Session.h"
#include <fstream>
#include "Agent.h"
#include "iostream"
#include <deque>
#include <algorithm>
// for convenience
using namespace std;


Session::Session(const std::string& path)
:g(),treeType(Root),agents(std::vector<Agent*>()),cycleCount(0)
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
:g(other.g),treeType(other.treeType),agents(std::vector<Agent*>()),cycleCount(0)
{
    for(auto agent : other.agents)
    {
        Agent* agentClone = agent->clone();
        agents.push_back(agentClone);
    }
}

void Session::simulate()
{
    bool terminateCycle = false;// true when terminate conditions are fulfilled
    while(!terminateCycle) //cycle loop
    {
        cycleCount++; // update counter for cycle
        for(Agent* agent : agents)
            agent->act((*this));
//        terminateCycle = g.isInfectedEmpty();
        if(cycleCount==2)
            terminateCycle=true;
    }
    // Print input info to console
//    cout << "Agents list:" << endl;
//    for(auto& agent: agents)
//    {
//        if(typeid(agent) == typeid(ContactTracer))
//            cout << "This is a Contact Tracer" <<endl;
//        else
//            cout << "This is a Virus" << endl;
//    }
//    enqueueInfected(0);
//    enqueueInfected(2);
//    enqueueInfected(5);
//    agents[1]->act((*this));
//    cycleCount = 2;
//    Tree* tree_ptr = BFS(0);
//    cout << "trace node: " << (*tree_ptr).traceTree() << endl;
    cout<< "In simulate!" << endl;
    create_json_output();
}

Session::~Session()
{
    for(auto* agent: agents)
        delete agent;
}

void Session:: addAgent(const Agent& agent)
{
    Agent* clone = agent.clone();
    agents.push_back(clone);
}
void Session::setGraph(const Graph& graph)
{
    g = graph;
}

void Session::enqueueInfected(int nodeInd)
{
    g.infectNode(nodeInd);
}
int Session::dequeueInfected()
{
    return g.dequeueInfected();
}
TreeType Session::getTreeType() const
{
    return treeType;
}

int Session::getCycle() const
{
    return cycleCount;
}

Graph Session::getGraph() const
{
    return g;
}

void Session::removeNode(int node) {g.removeNode(node);}

Tree* Session::BFS(int rootLabel)
{
    Tree* curr_tree = Tree::createTree((*this),rootLabel);
    vector<bool> visitedNode(g.getVerticesCount(),false);
    visitedNode[rootLabel] =true;
    std::deque<Tree*> greyQueue;
    greyQueue.push_back(curr_tree);
    cout << "BFS tree:" << endl;
    while(!greyQueue.empty())
    {
        Tree* treeNode = greyQueue.front();
        greyQueue.pop_front();
        vector<int> neighbours = g.getNeighbours(treeNode->getNodeInd());
        cout <<" parent: "<< treeNode->getNodeInd() <<" children:";
        for(int neighbourInd:neighbours)
        {
            if(!visitedNode[neighbourInd])
            {
                Tree* newTree = Tree::createTree((*this),neighbourInd);
                treeNode->addChild(newTree);
                cout <<" "<< newTree->getNodeInd() <<" ";
                greyQueue.push_back(newTree);
                visitedNode[neighbourInd] = true;
            }
        }
        cout << endl;
    }
    return curr_tree;
}

json Session::file_path_to_json(const std::string& path)
{
    ifstream MyReadFile(path);
    json inputJSON;
    MyReadFile >> inputJSON;
    MyReadFile.close();
    return inputJSON;
}

void Session::create_json_output()
{
    // output final results as json
    json outputJSON;
    string myText;
    outputJSON["graph"] = (*g.getEdgesCopy());
    outputJSON["infected"] = (*g.getInfectedCopy());
    ofstream file("output.json");
    file << outputJSON;
    file.close();
}

void Session::add_agents_from_json(const json& inputJson)
{
    for (auto& agent : inputJson.at("agents"))
    {
        auto agent_type = agent.at(0); //type of agent "C" or "V"
        auto agent_index = agent.at(1); // the node index of the agent
        if(agent_type == "C") // Agent is contact tracer
        {
            const Agent* contact_ptr = new ContactTracer();
            this->addAgent((*contact_ptr));
        }
        else if(agent_type == "V") // Agent is virus
        {
            const Agent* virus_ptr = new Virus(agent_index);
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