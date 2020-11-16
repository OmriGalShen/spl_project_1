#include "../../../include/Tree.h"

// constructor
RootTree::RootTree(int rootLabel): Tree(rootLabel)
{}

// copy constructor
RootTree::RootTree(const RootTree &other): Tree(other)
{}

// copy assignment operator
const RootTree &RootTree::operator=(const RootTree &other) {
    if(this != &other)
        Tree:: operator=(other);
    return (*this);
}
// move constructor
RootTree::RootTree(RootTree &&other)
        :Tree(std::move(other))
{

}
// move assignment
RootTree &RootTree::operator=(RootTree &&other)
{
    if(this != &other)
        Tree:: operator=(std::move(other)); //Steal resources
    return (*this);
}

int RootTree::traceTree()
{
    return node;
}

Tree * RootTree::clone() const
{
    return new RootTree((*this));
}