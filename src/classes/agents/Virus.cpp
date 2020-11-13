#include "../../../include/Agent.h"
#include "iostream"

Virus::Virus(int nodeInd): nodeInd(nodeInd)
{}

Virus::Virus(const Virus& other): nodeInd(other.nodeInd)
{}

void Virus::act(Session& session)
{
    Graph g = session.getGraph();
    //std::cout<<"problem with g? "<<g.getEdges().size()<<std::endl;
    session.enqueueInfected(nodeInd);
    std::cout<<"virus-act "<<nodeInd<<std::endl;
    std::vector<int> vec = g.getNeighbours(nodeInd);
    int vecSize = vec.size();
    std::cout<<"num of nei "<<vecSize<<std::endl;
    bool found = false;
    if(! vec.empty())
    {
        for(int i=0; !found && i<vecSize; i++)
        {
            if(! g.isInfected(vec[i]))
            {
                std::cout<<"node to infect "<<vec[i]<<std::endl;
                Agent * spread = new Virus(vec[i]);
                session.addAgent(* spread); // add the new virus as an agent to agent's vector
                found = true;
            }
        }
    }
}

Agent * Virus::clone() const
{
    return new Virus(* this);
}

