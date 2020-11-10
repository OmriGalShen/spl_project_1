#include "Tree.h"
#include "Session.h"
#include "Graph.h"

using namespace std;

Tree::Tree(int rootLabel)
:node(rootLabel),children(std::vector<Tree*>())
{

}

Tree::Tree(const Tree &other):node(other.node),children(other.children) {}

Tree::~Tree()
{
    for(auto* child:children)
        delete child;
    children.clear();
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

void Tree::addChild(Tree* child)
{
    children.push_back(child);
}

Tree* Tree::getRightChild()
{
    return children.back();
}

int Tree::getNodeInd()
{
    return node;
}

bool Tree::hasChildren() const
{
    return children.size()>0;
}

Tree* Tree::getLeftChild()
{
    if(hasChildren())
        return children[0];
    return nullptr;
}
