#include "../../../include/Tree.h"
#include <deque>


MaxRankTree::MaxRankTree(int rootLabel): Tree(rootLabel) // constructor
{}


MaxRankTree::MaxRankTree(const MaxRankTree &other): Tree(other) // copy constructor
{}


MaxRankTree::MaxRankTree(MaxRankTree &&other): Tree(std::move(other)) // move constructor
{}


MaxRankTree& MaxRankTree::operator=(const MaxRankTree &other) // copy assignment operator
{
    if(this != &other)
        Tree:: operator=(other);
    return (*this);
}


MaxRankTree& MaxRankTree::operator=(MaxRankTree &&other) // move assignment
{
    if(this != &other)
        Tree:: operator=(std::move(other)); // steal resources
    return (*this);
}


Tree* MaxRankTree::clone() const
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
        auto currChildren = (*curr).children;
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




