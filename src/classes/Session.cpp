#include "../../include/Session.h"
#include <fstream>
#include "../../include/Agent.h"
#include "iostream"
#include <queue>

using namespace std;// for convenience



//            ***constructors and operators***

Session::Session(const string& path): // constructor
g(), treeType(), agents(), infectedQueue(), cycleCount(0)
{
    ifstream readFile(path);
    json inputJson;
    readFile>>inputJson;
    g = Graph(inputJson["graph"]); // get the graph from the input
    string type(inputJson["tree"]); // get the tree type from the input
    if (type == "M") treeType=MaxRank;
    if (type == "C") treeType=Cycle;
    if (type == "R") treeType=Root;
    int size = inputJson["agents"].size();
    for (int i=0; i<size; i++) // goes over the input's agents list
    {
        if (inputJson["agents"][i][0]=="V") // agent is a Virus
        {
            int virusNode = inputJson["agents"][i][1]; // the node that the virus is occupying
            agents.push_back(new Virus(virusNode)); // add the new agent
            g.addVirusOn(virusNode); // inform Graph that virusNode has a virus
        }
        else // agent is a ContactTracer
            agents.push_back(new ContactTracer()); // add the new agent
    }
}


Session::Session(const Session& other): // copy constructor
g(other.g), treeType(other.treeType), agents(), infectedQueue(), cycleCount(0)
{
    for(auto& agent : other.agents)
    {
        Agent* agentClone = agent->clone();
        agents.push_back(agentClone);
    }
}


Session::Session(Session&& other): // move constructor
g(other.g), treeType(other.treeType), agents(move(other.agents)), infectedQueue(),
cycleCount(0) {}


Session& Session::operator=(const Session& other) // copy assignment
{
    if(this != &other)
    {
        clean();
        g = other.g;
        treeType = other.treeType;
        for(auto& agent : other.agents)
        {
            Agent* agentClone = agent->clone();
            agents.push_back(agentClone);
        }
    }
    return (*this);
}


Session& Session::operator=(Session&& other) // move assignment
{
    if(this != &other)
    {
        clean();
        g = other.g;
        treeType = other.treeType;
        agents = move(other.agents);
    }
    return (*this);
}


void Session::clean() // used by move assignment+destructor
{
    for(auto * agent : agents)
        delete agent;
    agents.clear();
}


Session::~Session() // destructor
{
    clean();
}





//            ***getters and setters***


TreeType Session::getTreeType() const
{
    return treeType;
}


int Session::getCycle() const
{
    return cycleCount;
}


Graph& Session::getGraphRef()
{
    return g;
}


void Session::setGraph(const Graph &graph)
{
    g = graph;
}





//            ***other functions***



void Session::enqueueInfected(int nodeInd)
{
    infectedQueue.push(nodeInd);
}


int Session::dequeueInfected()
{
    if(! infectedQueue.empty())
    {
        int nodeTemp = infectedQueue.front();
        infectedQueue.pop();
        return nodeTemp;
    }
    return -1;
}

Tree* Session::BFS(int rootLabel)
{
    Tree* rootTree = Tree::createTree(*this, rootLabel);
    int size = g.getEdgesRef().size();
    vector<bool> visitedNodes(size, false);
    visitedNodes[rootLabel] = true;
    queue<Tree*> greyQueue;
    greyQueue.push(rootTree);
    while(! greyQueue.empty())
    {
        Tree* currTree = greyQueue.front();
        greyQueue.pop();
        vector<int> neighbours = g.getNeighbours(currTree->getNodeInd());
        for(int neighbour : neighbours)
        {
            if(! visitedNodes[neighbour])
            {
                Tree* newTree = Tree::createTree(*this, neighbour);
                currTree->addChild(newTree);
                greyQueue.push(newTree);
                visitedNodes[neighbour] = true;
            }
        }
    }
    return rootTree;
}


void Session::addAgent(const Agent& agent)
{
    Agent* clone = agent.clone();
    agents.push_back(clone);
}

/*
This is the main simulation loop.
*/
void Session::simulate()
{
    bool terminateCycle = false;// true when terminate conditions are fulfilled
    while(! terminateCycle) // cycle loop
    {
        int tempAgentsSize = agents.size();
        for (int i = 0; i < tempAgentsSize; i++)
            agents[i]->act((*this));
        int newAgentsSize = agents.size();
        if (tempAgentsSize == newAgentsSize) // no virus was added in cycle
            terminateCycle = true;
        cycleCount++; // update counter for cycle
    }
    jsonOutput(); // output simulate results to json file
}


void Session::jsonOutput() // output final results as json
{
    json outputJSON;
    outputJSON["graph"] = g.getEdgesRef();
    outputJSON["infected"] = g.getInfectedNodes();
    ofstream file("./output.json");
    file << outputJSON << endl;
    //file.close();
}