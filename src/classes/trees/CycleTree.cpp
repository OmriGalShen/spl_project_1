#include "../../../include/Tree.h"





//            ***constructors and operators***


CycleTree::CycleTree(int rootLabel, int currCycle): // constructor
Tree(rootLabel), currCycle(currCycle)
{}

//
//CycleTree::CycleTree(const CycleTree &other): // copy constructor
//Tree(other), currCycle(other.currCycle)
//{}
//
//
//CycleTree::CycleTree(CycleTree &&other): // move constructor
//Tree(std::move(other)),currCycle(other.currCycle)
//{}
//
//
//CycleTree &CycleTree::operator=(const CycleTree &other) // copy assignment operator
//{
//    if(this != &other)
//    {
//        Tree:: operator=(other);
//        currCycle = other.currCycle;
//    }
//    return (*this);
//}
//
//
//CycleTree &CycleTree::operator=(CycleTree &&other) // move assignment
//{
//    if(this != &other)
//    {
//        currCycle = other.currCycle;
//        other.currCycle = -1;
//        Tree:: operator=(std::move(other)); // steal resources
//    }
//    return (*this);
//}





//            ***other functions***


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