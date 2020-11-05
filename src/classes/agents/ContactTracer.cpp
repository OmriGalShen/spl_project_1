#include "../../../include/Agent.h"

ContactTracer::ContactTracer(Session& session): Agent(session)
{

}

void ContactTracer::act()
{

}

Agent * ContactTracer::clone()  const
{
    return new ContactTracer(*this);
}
