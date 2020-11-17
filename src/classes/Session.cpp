#include "../../include/Session.h"
#include <fstream>
#include "Agent.h"
#include "iostream"
#include <deque>

// for convenience
using namespace std;





//            ***constructors and operators***


Session::Session(const string& path): // constructor
g(), treeType(), agents(), infectedQueue(), cycleCount(0)
{
    ifstream readFile(path);
    json inputJson;
    readFile>>inputJson;
    g = Graph(inputJson["graph"]); // get graph from input
    string type(inputJson["tree"]); // get tree type from input
    if (type=="M") treeType=MaxRank;
    if (type=="C") treeType=Cycle;
    if (type=="R") treeType=Root;
    int matSize = inputJson["agents"].size();
    for (int i=0; i<matSize; i++) // loop on input agents list
    {
        if (inputJson["agents"][i][0]=="V") // agent is Virus
        {
            int virusNode = inputJson["agents"][i][1];
            agents.push_back(new Virus(virusNode)); // add the new agent
            g.addVirusOn(virusNode); // inform Graph that virusNode has virus
        }
        else // agent is ContactTracer
            agents.push_back(new ContactTracer()); // add the new agent
    }
    readFile.close();
}


Session::Session(const Session& other): // copy constructor
treeType(other.treeType), agents(), infectedQueue(other.infectedQueue),
cycleCount(other.cycleCount)
{
    setGraph(other.g);
    for(auto& agent : other.agents)
    {
        Agent* agentClone = agent->clone();
        agents.push_back(agentClone);
    }
}


Session::Session(Session&& other): // move constructor
        g(other.g), treeType(other.treeType), agents(move(other.agents)),
        infectedQueue(other.infectedQueue), cycleCount(other.cycleCount)
{
    other.clean(); // should we add that? - Eden
}




Session& Session::operator=(const Session& other) // copy assignment
{
    if(this != &other)  // what about the infectedQueue? - Eden
    {
        clean();
        setGraph(other.g);
        treeType = other.treeType;

        infectedQueue = other.infectedQueue;
        cycleCount = other.cycleCount;
    }
    return (*this);
}

Session& Session::operator=(Session&& other) // move assignment
{
    if(this != &other)  //what about cycleCount and the infectedQueue? - Eden
    {
        this->clean();
        g = other.g;
        treeType = other.treeType;
        agents = std::move(other.agents);
    }
    return (*this);
}



void Session::clean() // used by move assignment+destructor
{
    for(auto * agent:agents)
    {
        delete agent;
        agent = nullptr;
    }
    //agents.clear();  // is this instead of agent=nullptr? - Eden
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
    infectedQueue.push_back(nodeInd);
}

int Session::dequeueInfected()
{
    if(! infectedQueue.empty())
    {
        int nodeTemp = infectedQueue.front();
        infectedQueue.pop_front();
        return nodeTemp;
    }
    return -1;
}

Tree* Session::BFS(int rootLabel)
{
    Tree* curr_tree = Tree::createTree((*this),rootLabel);
    int matSize = g.getEdgesRef().size();
    vector<bool> visitedNode(matSize,false);
    visitedNode[rootLabel] =true;
    std::deque<Tree*> greyQueue; // std needed? - Eden
    greyQueue.push_back(curr_tree);
    while(!greyQueue.empty())
    {
        Tree* treeNode = greyQueue.front();
        greyQueue.pop_front();
        vector<int> neighbours = g.getNeighbours(treeNode->getNodeInd());
        for(int neighbourInd:neighbours)
        {
            if(!visitedNode[neighbourInd])
            {
                Tree* newTree = Tree::createTree((*this),neighbourInd);
                treeNode->addChild(newTree);
                greyQueue.push_back(newTree);
                visitedNode[neighbourInd] = true;
            }
        }
    }
    return curr_tree;
}

void Session::addAgent(const Agent& agent)
{
    Agent * clone = agent.clone();
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
    file << outputJSON;
    file.close();
}