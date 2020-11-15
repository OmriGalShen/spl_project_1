#include "../../../include/Agent.h"
#include "iostream"



ContactTracer::ContactTracer()
{}



void ContactTracer::act(Session& session)
{
    Graph& g = session.getGraphRef();
    int infectedNode = session.dequeueInfected();
    if(infectedNode >= 0)
    {
        Tree * shortPathTree = session.BFS(infectedNode);
        int nodeToRemove = shortPathTree->traceTree();
        delete shortPathTree;
        g.removeNode(nodeToRemove);
    }
}



Agent * ContactTracer::clone() const
{
    return new ContactTracer(* this);
}