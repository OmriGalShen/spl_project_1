#include "../../../include/Tree.h"
std::vector<Tree*> c;

Tree::Tree(int rootLabel)
:node(0),children(c)
{

}

void Tree::addChild(const Tree& child)
{
    return;
}

Tree* Tree::createTree(const Session& session, int rootLabel)
{
    return nullptr;
}

int Tree::traceTree()
{
    return 0;
}

Tree::~Tree() {

}
