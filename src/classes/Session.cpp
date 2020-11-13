#include "../../include/Session.h"
#include <fstream>
#include "Agent.h"
#include "iostream"
#include <deque>
#include <algorithm>
// for convenience
using namespace std;




//            ***constructors***




Session::Session(const std::string& path): // constructor
    g(),
    treeType(),
    agents(),
    infectedQueue(),
    cycleCount(0)
{
    ifstream readFile(path);
    json inputJson;
    readFile>>inputJson;
    g = Graph(inputJson["graph"]);
    string type(inputJson["tree"]);
    if (type=="M") treeType=MaxRank;
    if (type=="C") treeType=Cycle;
    if (type=="R") treeType=Root;
    int size = inputJson["agent"].size();
    for (int i=0; i<size; i++)
    {
        if (inputJson["agents"][i][0]=="V")
            agents.push_back(new Virus(inputJson["agents"][i][1]));
        else
            agents.push_back(new ContactTracer());
    }
    readFile.close();
}


void Session::setGraph(const Graph &graph)
{
    g = graph;
}

void Session::addAgent(const Agent& agent)
{
    Agent * clone = agent.clone();
    agents.push_back(clone);
}

Session::Session(const Session& other): //copy constructor
    g(other.g),
    treeType(other.treeType),
    agents(std::vector<Agent*>()),
    infectedQueue(),   //other.infectedQueue? - Eden
    cycleCount(0) //should it be other.cycleCount? - Eden
{
    for(auto agent : other.agents)
    {
        Agent* agentClone = agent->clone();
        agents.push_back(agentClone);
    }
}


Session::Session(Session&& other)://move constructor
        g(other.g),
        treeType(other.treeType),
        agents(std::move(other.agents)),
        infectedQueue(),   //other.infectedQueue? - Eden
        cycleCount(other.cycleCount)
{}


Session::~Session() //destructor
{
    clean();
}


void Session::clean() // used by move assignment+destructor
{
    for(auto * agent:agents)
        delete agent;
    agents.clear();
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



void Session::simulate()
{
    bool terminateCycle = false;// true when terminate conditions are fulfilled
    while(! terminateCycle) //cycle loop
    {
        int tempAgentsSize = agents.size();
        cycleCount++; // update counter for cycle
        for(int i=0; i<tempAgentsSize; i++)
            agents[i]->act((*this));
//        if(cycleCount==2)         //testing
//            terminateCycle=true;
        if(tempAgentsSize == int(agents.size()))
            terminateCycle=true;
//    // Print input info to console
//    cout << "Agents list:" << endl;
//    for(auto& agent: agents)
//        if(typeid(agent) == typeid(ContactTracer))
//            cout << "This is a Contact Tracer" <<endl;
//        else
//            cout << "This is a Virus" << endl;
    }
    cout<< "In simulate!" << endl;
    jsonOutput();
}




//            ***getters***






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





void Session::enqueueInfected(int nodeInd)
{
    infectedQueue.push_back(nodeInd);
    g.infectNode(nodeInd);
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
    int matSize = g.getEdges().size();
    vector<bool> visitedNode(matSize,false);
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


void Session::jsonOutput()
{
    json output;
    output["graph"]={};
    const vector<vector<int>> matrix=g.getEdges();
    int matSize = matrix.size();
    int infected = g.getInfectedNodes().size();
    for (int i=0; i<matSize; i++)
    {
        for (int j=0; j<matSize; j++)
            output["graph"][i][j]=matrix[i][j];
    }
    output["infected"]={};
    for (int i=0; i<infected; i++)
    {
        output["infected"][i].push_back(g.getInfectedNodes()[i]);
    }

    ofstream out("./output.json");
    out<<output<<endl;
}