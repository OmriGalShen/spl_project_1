#include "../../../include/Tree.h"

RootTree::RootTree(int rootLabel)
        : Tree(rootLabel)
{

}
int RootTree::traceTree()
{
    return node;
}

Tree * RootTree::clone() const
{
    return new RootTree(node);
}