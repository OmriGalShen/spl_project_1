#include "../../include/Session.h"
#include <fstream>
#include "Agent.h"
#include "iostream"
#include <deque>
#include <algorithm>
// for convenience
using namespace std;


Session::Session(const std::string& path) // constructor
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

Session::Session(const Session& other) //copy constructor
:g(other.g),treeType(other.treeType),agents(std::vector<Agent*>()),cycleCount(0)
{
    for(auto agent : other.agents)
    {
        Agent* agentClone = agent->clone();
        agents.push_back(agentClone);
    }
}

Session::~Session() //destructor
{
    clean();
}

void Session::clean() // used by move assignment+destructor
{
    for(auto* agent:agents)
        delete agent;
    agents.clear();
}

Session::Session(Session&& other)://move constructor
g(other.g),treeType(other.treeType),agents(std::move(other.agents)),cycleCount(other.cycleCount)
{}

Session& Session::operator=(Session&& other)// move assignment
{
    if(this != &other)
    {
        this->clean();
        g = other.g;
        treeType = other.treeType;
        agents = std::move(other.agents);
    }
    return (*this);
}

Session& Session::operator=(Session& other)// copy assignment
{
    if(this != &other)
    {
        g = other.g;
        treeType = other.treeType;
        cycleCount = other.cycleCount;
        for(auto agent : other.agents)
        {
            Agent* agentClone = agent->clone();
            agents.push_back(agentClone);
        }
    }
    return (*this);
}

void Session::simulate()
{
    bool terminateCycle = false;// true when terminate conditions are fulfilled
    while(!terminateCycle) //cycle loop
    {
        int tempAgentsSize = agents.size();
        cycleCount++; // update counter for cycle
        for(int i=0; i<tempAgentsSize; i++) //need to fix?
            agents[i]->act((*this));
        g.printGraph();
//        if(cycleCount==2)         //testing
//
//            terminateCycle=true;
        if(tempAgentsSize==int(agents.size()))
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
    cout<< "In simulate!" << endl;
    create_json_output();
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