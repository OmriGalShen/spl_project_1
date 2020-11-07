#include "../../../include/Tree.h"

CycleTree::CycleTree(int rootLabel, int currCycle)
: Tree(rootLabel),currCycle(currCycle)
{

}
CycleTree::CycleTree(const CycleTree &other):Tree(other),currCycle(other.currCycle) {}
int CycleTree::traceTree()
{
    return 0;
}

Tree * CycleTree::clone() const
{
    return new CycleTree((*this));
}