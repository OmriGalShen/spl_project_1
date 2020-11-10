#include "../../../include/Agent.h"
#include "iostream"

Virus::Virus(int nodeInd): nodeInd(nodeInd)
{

}

Virus::Virus(const Virus& other):
nodeInd(other.nodeInd)
{

}

void Virus::act(Session& session)
{
    Graph g = session.getGraph();

    g.infectNode(nodeInd);
    std::cout<<"virus-act "<<nodeInd<<std::endl;

    std::vector<int> vec = g.getNeighbours(nodeInd);
    bool found = false;
    if(! vec.empty())
    {
        for(int i=0,len=vec.size(); !found && i<len; i++)
        {
            if(! g.isInfected(vec[i]))
            {
                Agent * spread = new Virus(vec[i]);
                session.addAgent(*spread); // add the new virus as an agent to agent queue
                found = true;
            }
        }
    }
    session.enqueueInfected(nodeInd);
}

Agent * Virus::clone() const
{
    return new Virus(*this);
}

