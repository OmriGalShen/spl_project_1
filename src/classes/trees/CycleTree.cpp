#include "../../../include/Tree.h"



CycleTree::CycleTree(int rootLabel, int currCycle): Tree(rootLabel), // constructor
currCycle(currCycle)
{}



Tree* CycleTree::clone() const
{
    return new CycleTree(*this);
}



int CycleTree::traceTree()
{
    Tree* currentTree = this;
    int cycleCount = currCycle;
    while (cycleCount>0 && currentTree->hasChildren())
    {
        currentTree = currentTree->getLeftChild();
        cycleCount--;
    }
    return currentTree->getNodeInd();
}