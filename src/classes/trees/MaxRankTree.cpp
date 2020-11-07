#include "../../../include/Tree.h"
#include <deque>
#include "iostream"
using namespace std;

MaxRankTree::MaxRankTree(int rootLabel)
        : Tree(rootLabel)
{

}

Tree * MaxRankTree::clone() const
{
    return new MaxRankTree(node);
}

int MaxRankTree::traceTree()
{
//    int maxChildrenCount = 0;
//    MaxRankTree* maxChildrenPtr = this;
//    std::deque<MaxRankTree*> nodesToCheck;
//    nodesToCheck.push_back(this);
//    while (!nodesToCheck.empty())
//    {
//        MaxRankTree* curr = nodesToCheck.front();
//        nodesToCheck.pop_front();
//        cout << "Pop: " << (*curr).node <<endl;
//        auto currChildren = ((MaxRankTree)(*curr)).children;
//        auto currentChildrenCount = currChildren.size();
//        cout << "currentChildrenCount: " << (*curr).children.size() <<endl;
//        if(currentChildrenCount>maxChildrenCount)
//        {
//            maxChildrenCount=currentChildrenCount;
//            maxChildrenPtr = curr;
//        }
//        for(auto* child: currChildren)
//            nodesToCheck.push_back((MaxRankTree*)child);
//    }
//    std::cout << "Max Rank:" << (*maxChildrenPtr).node << endl;
}