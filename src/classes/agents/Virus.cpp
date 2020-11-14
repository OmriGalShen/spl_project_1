#include "../../../include/Agent.h"
#include "iostream"

Virus::Virus(int nodeInd): nodeInd(nodeInd)
{}

Virus::Virus(const Virus& other): nodeInd(other.nodeInd)
{}

void Virus::act(Session& session)
{
    Graph g = session.getGraph();
    std::cout<<"virus act-nodeInd = "<<nodeInd<<std::endl;
    std::cout<<"virus-act "<<nodeInd<<std::endl;
    std::vector<int> neighbours = g.getNeighbours(nodeInd);
    //std::cout<<"num of nei "<<vecSize<<std::endl;
    bool found = false; // found neighbour node to infect
//    std::cout<<"infected nodes:"<<std::endl;
//    for (int i=0; i<nodesStatus.size(); i++)
//        if(nodesStatus[i]==Infected)
//            std::cout<< i;
//    std::cout << std::endl;
    for(unsigned i=0; !found && i<neighbours.size(); i++) // loop on neighbours of the virus node
    {
        int neighbourNode = neighbours[i]; // the neighbourNode index
        if(g.isHealthy(neighbourNode)) //neighbourNode doesn't have virus or already infected
        {
            std::cout<<"node to infect "<<neighbourNode<<std::endl;
            Agent * spread = new Virus(neighbourNode); // create virus on neighbourNode
            session.addAgent(* spread); // add the new virus as an agent to agents vector
            g.addVirusOn(neighbourNode); // Graph now marked neighbourNode as having a virus
            found = true; //found neighbour to infect, loop terminated
        }
   }
    g.infectNode(nodeInd); // Virus infect the node he is on
    session.enqueueInfected(nodeInd);
}

Agent * Virus::clone() const
{
    return new Virus(* this);
}

