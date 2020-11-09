#include "../../../include/Agent.h"
#include "iostream"

ContactTracer::ContactTracer(): Agent()
{

}

void ContactTracer::act(Session& session)
{
    int infectedNode = session.dequeueInfected();
    Tree* shortPathTree = session.BFS(infectedNode);
    int nodeToRemove = shortPathTree->traceTree();
//    std::cout << "----------------------"<< std::endl;
//    std::cout << "IN CONTRACT TRACER" << std::endl;
//    std::cout<<"nodeToRemove:" << nodeToRemove << std::endl;
//    std::cout << "----------------------"<< std::endl;
    session.removeNode(nodeToRemove);
}

Agent * ContactTracer::clone()  const
{
    return new ContactTracer(*this);
}
