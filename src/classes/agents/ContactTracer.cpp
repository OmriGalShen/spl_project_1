#include "../../../include/Agent.h"
#include "iostream"

ContactTracer::ContactTracer(): Agent()
{

}

void ContactTracer::act(Session& session)
{
    //add getter
    int infectedNode = session.dequeueInfected();
    if(infectedNode>=0)
    {
        Tree *shortPathTree = session.BFS(infectedNode);
        int nodeToRemove = shortPathTree->traceTree();
        std::cout << "node to remove "<< nodeToRemove << std::endl;
        delete shortPathTree;
        //session.removeNode(nodeToRemove); //change to g.
    }
}

Agent * ContactTracer::clone()  const
{
    return new ContactTracer(*this);
}
