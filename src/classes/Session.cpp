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
    treeType(Root),
    agents(),
    edges(),
    infectedQueue(),
    cycleCount(0)
{




//    string myText;
//    ofstream file("output.json");
//    file << outputJSON;
//    file.close();
//}


    ifstream i(path);
    json inputJson;
    i>>inputJson;
    g = Graph(inputJson["graph"]);
    string type(inputJson["tree"]);
    if (type=="M") treeType=MaxRank;
    if (type=="C") treeType=Cycle;
    if (type=="R") treeType=Root;
    int size = inputJson["agent"].size();
    for (int x=0; x<size; x++)
    {
        if (inputJson["agents"][x][0]=="V")
            agents.push_back(new Virus(inputJson["agents"][x][1]));
        else
            agents.push_back(new ContactTracer());
    }

//    // add agents given by the json input to the agent vector
//    add_agents_from_json(inputJson);
    // get type of tree from the input
    treeType = tree_type_from_json(inputJson);
}

//Session::Session(const Session& other): //copy constructor
//    g(other.g),
//    treeType(other.treeType),
//    agents(std::vector<Agent*>()),
//    edges(other.edges),
//    infectedQueue(other.infectedQueue),  //should we copy it like agents? - Eden
//    cycleCount(0), //should it be other.cycleCount? - Eden
//{
//    for(auto agent : other.agents)           //why? - Eden
//    {
//        Agent* agentClone = agent->clone();
//        agents.push_back(agentClone);
//    }
//}
//
//
//Session::Session(Session&& other)://move constructor
//        g(other.g),
//        treeType(other.treeType),
//        agents(std::move(other.agents)),
//        edges(other.edges),
//        infectedQueue(other.infectedQueue),
//        cycleCount(other.cycleCount),
//{}
//
//
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
//
//
//Session& Session::operator=(Session& other)// copy assignment
//{
//    if(this != &other)
//    {
//        g = other.g;
//        treeType = other.treeType;
//        cycleCount = other.cycleCount;
//        for(auto agent : other.agents)
//        {
//            Agent* agentClone = agent->clone();
//            agents.push_back(agentClone);
//        }
//    }
//    return (*this);
//}
//
//
//Session& Session::operator=(Session&& other)// move assignment
//{
//    if(this != &other)
//    {
//        this->clean();
//        g = other.g;
//        treeType = other.treeType;
//        agents = std::move(other.agents);
//    }
//    return (*this);
//}
//
//
//void Session::simulate()
//{
//    bool terminateCycle = false;// true when terminate conditions are fulfilled
//    while(!terminateCycle) //cycle loop
//    {
//        int tempAgentsSize = agents.size();
//        cycleCount++; // update counter for cycle
//        for(int i=0; i<tempAgentsSize; i++) //need to fix?
//            agents[i]->act((*this));
//        if(cycleCount==2)         //testing
//            terminateCycle=true;
//        if(tempAgentsSize==int(agents.size()))
//            terminateCycle=true;
//    // Print input info to console
//    cout << "Agents list:" << endl;
//    for(auto& agent: agents)
//        if(typeid(agent) == typeid(ContactTracer))
//            cout << "This is a Contact Tracer" <<endl;
//        else
//            cout << "This is a Virus" << endl;
//    }
//    cout<< "In simulate!" << endl;
//    create_json_output();
//}




//            ***getters***




//std::vector<std::vector<int>> Session:: getMatrix()
//{
//    return edges;
//}

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

int Session::matSize() const
{
    return edges.size();
}





//            ***read json file***



TreeType Session::tree_type_from_json(const json& inputJson)
{
    string type = inputJson.at("tree").get<string>();
    if(type=="R") return Root;
    else if(type=="C") return Cycle;
    else return MaxRank;
}


//
//
//
//
//json Session::file_path_to_json(const std::string& path)
//{
//    ifstream MyReadFile(path);
//    json inputJSON;
//    MyReadFile >> inputJSON;
//    //MyReadFile.close();
//    return inputJSON;
//}
//
//void Session::add_agents_from_json(const json& inputJson)
//{
//    for (auto& agent : inputJson.at("agents"))
//    {
//        auto agent_type = agent.at(0); //type of agent "C" or "V"
//        auto agent_index = agent.at(1); // the node index of the agent
//        if(agent_type == "C") // Agent is contact tracer
//        {
//            const Agent* contact_ptr = new ContactTracer();
//            this->addAgent((*contact_ptr));
//        }
//        else if(agent_type == "V") // Agent is virus
//        {
//            const Agent* virus_ptr = new Virus(agent_index);
//            this->addAgent((*virus_ptr));
//        }
//    }
//}
//
//
//
//
//
//
//void Session:: addAgent(const Agent& agent)
//{
//    Agent* clone = agent.clone();
//    agents.push_back(clone);
//}





void Session::enqueueInfected(int nodeInd)
{

    //g.infectNode(nodeInd);
}

int Session::dequeueInfected()
{
    if(!infectedQueue.empty())
    {
        int nodeTemp = infectedQueue.front();
        infectedQueue.pop_front();
        return nodeTemp;
    }
    return -1;
}
//int Session::dequeueInfected()
//{
//    return g.dequeueInfected();
//}

Tree* Session::BFS(int rootLabel)
{
    Tree* curr_tree = Tree::createTree((*this),rootLabel);
    vector<bool> visitedNode(matSize(),false);
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
    const vector<vector<int>> gEdges=edges;
    for (int i=0; i<matSize(); i++)
    {
        for (int j=0; j<matSize(); j++)
            output["graph"][i][j]=gEdges[i][j];
    }
    output["infected"]={};

    ofstream out("./output.json");
    out<<output<<endl;
}