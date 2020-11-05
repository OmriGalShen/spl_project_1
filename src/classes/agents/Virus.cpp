#include "../../../include/Agent.h"

Virus::Virus(int nodeInd, Session& session): Agent(session),nodeInd(nodeInd)
{

}

Virus::Virus(const Virus& other):
Agent(other.session),nodeInd(other.nodeInd)
{

}

void Virus::act()
{

}

Agent * Virus::clone() const
{
    return new Virus(*this);
}

