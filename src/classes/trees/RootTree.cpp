#include "../../../include/Tree.h"



RootTree::RootTree(int rootLabel): Tree(rootLabel) // constructor
{}

int RootTree::traceTree()
{
    return node;
}

Tree* RootTree::clone() const
{
    return new RootTree(*this);
}