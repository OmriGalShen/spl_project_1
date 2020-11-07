#include "Tree.h"
#include "Session.h"
#include "Graph.h"

using namespace std;

Tree::Tree(int rootLabel)
:node(rootLabel),children(std::vector<Tree*>())
{

}

Tree::~Tree()
{

}

Tree* Tree::createTree(const Session& session, int rootLabel)
{
    TreeType treeType = session.getTreeType();
    if(treeType==Root)
        return new RootTree(rootLabel);
    else if(treeType==MaxRank)
        return new MaxRankTree(rootLabel);
    return new CycleTree(rootLabel,session.getCycle());
}

void Tree::addChild(const Tree& child)
{
    Tree* clone = child.clone();
    children.push_back(clone);
}

int Tree::getNodeInd()
{
    return node;
}
