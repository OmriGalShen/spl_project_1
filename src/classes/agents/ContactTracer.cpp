#include "../../../include/Agent.h"
#include "iostream"

ContactTracer::ContactTracer(): Agent() //what does Agent() mean? does virus need it too? - Eden
{}

void ContactTracer::act(Session& session)
{
    Graph g = session.getGraph();
    int infectedNode = session.dequeueInfected();
    if(infectedNode>=0)
    {
        Tree * shortPathTree = session.BFS(infectedNode);
        int nodeToRemove = shortPathTree->traceTree();
        std::cout << "node to remove "<< nodeToRemove << std::endl;
        delete shortPathTree;
        g.removeNode(nodeToRemove);
    }
}

Agent * ContactTracer::clone() const
{
    return new ContactTracer(* this);
}
