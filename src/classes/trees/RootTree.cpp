#include "../../../include/Tree.h"

RootTree::RootTree(int rootLabel)
        : Tree(rootLabel)
{}

RootTree::RootTree(const RootTree& other):Tree(other) {}

int RootTree::traceTree()
{
    return node;
}

Tree * RootTree::clone() const
{
    return new RootTree((*this));
}