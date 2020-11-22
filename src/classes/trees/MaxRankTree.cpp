#include "../../../include/Tree.h"
#include <queue>

using namespace std; // added for convenience



MaxRankTree::MaxRankTree(int rootLabel): Tree(rootLabel) // constructor
{}


Tree* MaxRankTree::clone() const
{
    return new MaxRankTree((*this));
}


int MaxRankTree::traceTree()
{
    int maxChildrenCount = 0;
    MaxRankTree* maxChildrenPtr = this;
    queue<MaxRankTree*> nodesToCheck;
    nodesToCheck.push(this);
    while (! nodesToCheck.empty())
    {
        MaxRankTree* curr = nodesToCheck.front();
        nodesToCheck.pop();
        auto currChildren = (*curr).children;
        int currentChildrenCount = currChildren.size();
        if(currentChildrenCount>maxChildrenCount)
        {
            maxChildrenCount=currentChildrenCount;
            maxChildrenPtr = curr;
        }
        for(auto* child: currChildren)
            nodesToCheck.push((MaxRankTree*)child);
    }
    return (*maxChildrenPtr).node;
}