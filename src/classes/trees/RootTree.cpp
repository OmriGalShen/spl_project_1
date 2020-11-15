#include "../../../include/Tree.h"

RootTree::RootTree(int rootLabel): Tree(rootLabel) // constructor
{}

RootTree::RootTree(const RootTree& other): Tree(other) // copy constructor
{}

int RootTree::traceTree()
{
    return node;
}

Tree * RootTree::clone() const
{
    return new RootTree((*this));
}