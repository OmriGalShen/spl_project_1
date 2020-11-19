#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Session.h" //added


class Agent{
public:
    Agent(); // empty constructor
    virtual void act(Session& session)=0;
    //added
    virtual Agent* clone() const = 0;
    virtual ~Agent();
    //
};


class ContactTracer: public Agent{
public:
    ContactTracer();
    virtual void act(Session& session);
    // added
    virtual Agent* clone() const;
    //
};


class Virus: public Agent{
public:
    Virus(int nodeInd);
    virtual void act(Session& session);
    //added
    virtual Agent* clone() const;
    //Virus(const Virus& other); // copy constructor
    //

private:
    const int nodeInd;
};

#endif