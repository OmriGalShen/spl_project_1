#include "../../../include/Tree.h"
#include <deque>

MaxRankTree::MaxRankTree(int rootLabel)
        : Tree(rootLabel)
{

}

MaxRankTree::MaxRankTree(const MaxRankTree &other):Tree(other) {}

Tree * MaxRankTree::clone() const
{
    return new MaxRankTree((*this));
}

int MaxRankTree::traceTree()
{
    size_t maxChildrenCount = 0;
    MaxRankTree* maxChildrenPtr = this;
    std::deque<MaxRankTree*> nodesToCheck;
    nodesToCheck.push_back(this);
    while (!nodesToCheck.empty())
    {
        MaxRankTree* curr = nodesToCheck.front();
        nodesToCheck.pop_front();
        auto currChildren = ((MaxRankTree)(*curr)).children;
        auto currentChildrenCount = currChildren.size();
        if(currentChildrenCount>maxChildrenCount)
        {
            maxChildrenCount=currentChildrenCount;
            maxChildrenPtr = curr;
        }
        for(auto* child: currChildren)
            nodesToCheck.push_back((MaxRankTree*)child);
    }
    return (*maxChildrenPtr).node;
}