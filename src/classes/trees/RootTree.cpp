#include "../../../include/Tree.h"


RootTree::RootTree(int rootLabel): Tree(rootLabel) // constructor
{}


RootTree::RootTree(const RootTree &other): Tree(other) // copy constructor
{}


RootTree::RootTree(RootTree &&other): // move constructor
        Tree(std::move(other))
{}


RootTree &RootTree::operator=(const RootTree &other) // copy assignment operator
{
    if(this != &other)
        Tree:: operator=(other);
    return (*this);
}


RootTree &RootTree::operator=(RootTree &&other) // move assignment
{
    if(this != &other)
        Tree:: operator=(std::move(other)); //Steal resources
    return (*this);
}


int RootTree::traceTree()
{
    return node;
}


Tree* RootTree::clone() const
{
    return new RootTree((*this));
}