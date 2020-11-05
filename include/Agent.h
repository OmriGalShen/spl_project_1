#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Session.h"

class Agent{
public:
    Agent(Session& session);
    virtual Agent * clone() const = 0;
    virtual void act()=0;

protected:
    Session& session;
};

class ContactTracer: public Agent{
public:
    ContactTracer(Session& session);
    virtual void act();

    Agent *clone() const;
};


class Virus: public Agent{
public:
    Virus(int nodeInd, Session& session);
    Virus(const Virus& other);
    virtual void act();
private:
    const int nodeInd;

    Agent *clone() const;
};

#endif