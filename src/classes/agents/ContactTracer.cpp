#include "../../../include/Agent.h"
#include "iostream"

ContactTracer::ContactTracer()
{}

void ContactTracer::act(Session& session)
{
    int infectedNode = session.dequeueInfected();
    std::cout<<"infected node in CT is "<<infectedNode<<std::endl;
    if(infectedNode>=0)
    {
        Tree * shortPathTree = session.BFS(infectedNode);
        int nodeToRemove = shortPathTree->traceTree();
        std::cout << "node to remove "<< nodeToRemove << std::endl;
        delete shortPathTree;
        session.removeNode(nodeToRemove);
    }
}

Agent * ContactTracer::clone() const
{
    return new ContactTracer(* this);
}
