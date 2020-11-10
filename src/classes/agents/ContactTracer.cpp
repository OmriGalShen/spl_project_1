#include "../../../include/Agent.h"
#include "iostream"

ContactTracer::ContactTracer(): Agent()
{

}

void ContactTracer::act(Session& session)
{
    int infectedNode = session.dequeueInfected();
    if(infectedNode>=0)
    {
        Tree *shortPathTree = session.BFS(infectedNode);
        int nodeToRemove = shortPathTree->traceTree();
        delete shortPathTree;
        session.removeNode(nodeToRemove);
    }
}

Agent * ContactTracer::clone()  const
{
    return new ContactTracer(*this);
}
