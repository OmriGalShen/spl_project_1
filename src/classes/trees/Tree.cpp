#include "Tree.h"
#include "Session.h"

Tree::Tree(int rootLabel)
:node(0),children(std::vector<Tree*>())
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

Tree* Tree::BFS(const Session& session, int rootLabel)
{
    Tree* curr_tree = Tree::createTree(session,rootLabel);
    return curr_tree;
}

void Tree::addChild(const Tree& child)
{
    return;
}

int Tree::traceTree()
{
    return 0;
}
