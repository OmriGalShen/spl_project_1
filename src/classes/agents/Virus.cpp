#include "../../../include/Agent.h"
#include "iostream"

using namespace std; // for convenience


Virus::Virus(int nodeInd): nodeInd(nodeInd)  // constructor
{}


void Virus::act(Session& session)
{
    Graph& g = session.getGraphRef();
    vector<int> neighbours = g.getNeighbours(nodeInd);
    bool found = false; // found neighbour node to infect
    for(unsigned i=0; !found && i<neighbours.size(); i++) // loop on neighbours of the virus node
    {
        int neighbourNode = neighbours[i]; // the neighbourNode index
        if(g.isHealthy(neighbourNode)) // neighbourNode doesn't have virus or already infected
        {
            Agent* spread = new Virus(neighbourNode); // create virus on neighbourNode
            session.addAgent(*spread); // add the new virus as an agent to agents vector
            delete spread;
            g.addVirusOn(neighbourNode); // Graph now marked neighbourNode as having a virus
            found = true; //found neighbour to infect, loop terminated
        }
   }
    if(! g.isInfected(nodeInd)) // if virus is on node but it isn't infected yet
    {
        g.infectNode(nodeInd); // Virus infect the node he is on
        session.enqueueInfected(nodeInd); // new infected node is added to session's queue
    }
}


Agent* Virus::clone() const
{
    return new Virus(nodeInd);
}