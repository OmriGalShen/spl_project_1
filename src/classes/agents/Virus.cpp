#include "../../../include/Agent.h"

Virus::Virus(int nodeInd): Agent(),nodeInd(nodeInd)
{

}

Virus::Virus(const Virus& other):
Agent(),nodeInd(other.nodeInd)
{

}

void Virus::act(Session& session)
{

}

Agent * Virus::clone() const
{
    return new Virus(*this);
}

