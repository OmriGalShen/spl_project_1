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
    g = Graph(inputJson["graph"]); // get graph from input
    string type(inputJson["tree"]); // get tree type from input
    if (type=="M") treeType=MaxRank;
    if (type=="C") treeType=Cycle;
    if (type=="R") treeType=Root;
    int size = inputJson["agents"].size();
    for (int i=0; i<size; i++) //loop on input agents list
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
    agents(),
    infectedQueue(other.infectedQueue),   //other.infectedQueue? - Eden
    cycleCount(other.cycleCount) //should it be other.cycleCount? - Eden
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
        infectedQueue(other.infectedQueue),   //other.infectedQueue? - Eden
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


Session& Session::operator=(const Session& other)// copy assignment
{
    if(this != &other)
    {
        this->clean();
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



void Session::removeNode(int node)
{
    int matSize = g.getEdges().size();
    if(node>=0 && node<matSize) // to verify that the input is valid
    {
        //std::cout << "IN THE LOOP" << std::endl;
        for(int row=0; row<matSize; row++)
        {
            g.setEdges(row, node, 0);
            //std::cout << "[row][node] num: " << g.getEdges()[row][node] << std::endl;
        }
        for(int col=0; col<matSize; col++)
        {
            g.setEdges(node, col, 0);
            //std::cout << "[node][col] num: " << g.getEdges()[node][col] << std::endl;
        }

    }
}



/*
This is the main simulation loop.
*/
void Session::simulate()
{
    bool terminateCycle = false;// true when terminate conditions are fulfilled
    while(! terminateCycle) //cycle loop
    {
        int tempAgentsSize = agents.size();
        cout << "number of agents: " << tempAgentsSize << endl;
        cycleCount++; // update counter for cycle
        cout << "cycle number: " << cycleCount << endl;
        for (int i = 0; i < tempAgentsSize; i++)
        {
            cout << "agent in action!" <<endl;
            agents[i]->act((*this));
        }
//        if (cycleCount == 4) {  //testing
//            terminateCycle = true;
//            cout << "agents list" <<endl;
//        }

        int newAgentsSize = agents.size();
        if (tempAgentsSize == newAgentsSize) // no virus was added in cycle
            terminateCycle = true;
    }
    cout<< "In simulate!" << endl;
    jsonOutput(); //output simulate results to json file
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

Graph& Session::getGraphRef()
{
    return g;
}



void Session::enqueueInfected(int nodeInd)
{
    infectedQueue.push_back(nodeInd);
}

int Session::dequeueInfected()
{
    if(! infectedQueue.empty())
    {
        int nodeTemp = infectedQueue.front();
        //cout  << "dequeue (nodeTemp): " << nodeTemp << endl;
        infectedQueue.pop_front();
        //cout  << "new front: " << infectedQueue.front() << endl;
        return nodeTemp;
    }
    return -1;
}


Tree* Session::BFS(int rootLabel)
{
    Tree* curr_tree = Tree::createTree((*this),rootLabel);
    int matSize = g.getEdges().size();
    //std::cout<<"matsize in BFS "<< matSize <<std::endl;
    vector<bool> visitedNode(matSize,false);
    visitedNode[rootLabel] =true;
    std::deque<Tree*> greyQueue;
    greyQueue.push_back(curr_tree);
    //cout << "BFS tree:" << endl;
    while(!greyQueue.empty())
    {
        Tree* treeNode = greyQueue.front();
        greyQueue.pop_front();
        vector<int> neighbours = g.getNeighbours(treeNode->getNodeInd());
        //cout <<" parent: "<< treeNode->getNodeInd() <<" children:";
        for(int neighbourInd:neighbours)
        {
            if(!visitedNode[neighbourInd])
            {
                Tree* newTree = Tree::createTree((*this),neighbourInd);
                treeNode->addChild(newTree);
                //cout <<" "<< newTree->getNodeInd() <<" ";
                greyQueue.push_back(newTree);
                visitedNode[neighbourInd] = true;
            }
        }
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
        output["infected"].push_back(g.getInfectedNodes()[i]);
    }

    ofstream out("./output.json");
    out<<output<<endl;
}