#include "Tree.h"
#include "Session.h"

using namespace std;





//                           *****rule of 5*****


Tree::Tree(int rootLabel): node(rootLabel), children(vector<Tree*>()) // constructor
{}


Tree::Tree(const Tree &other): node(other.node), children() // copy constructor
{
    for(auto& child : other.children)
    {
        Tree* childClone = child->clone();
        children.push_back(childClone);
    }
}


Tree::Tree(Tree&& other): node(other.node),children(move(other.children)) // move constructor
{}


Tree& Tree::operator=(const Tree& other) // copy assignment
{
    if(this != &other)
    {
        clean();
        node = other.node;
        children = other.children;
    }
    return (*this);
}


Tree& Tree::operator=(Tree&& other) // move assignment
{
    if(this != &other)
    {
        clean();
        node = other.node;
        children = move(other.children);
    }
    return (*this);
}


Tree::~Tree() // destructor
{
    clean();
}





//                           *****getters*****


Tree* Tree::getLeftChild() const
{
    if(hasChildren())
        return children[0];
    return nullptr;
}


int Tree::getNodeInd() const
{
    return node;
}





//            ***other functions***


void Tree::clean() // used by move assignment + destructor
{
    for(auto* child : children)
        delete child;
    children.clear();
    node = -1;
}


void Tree::addChild(const Tree& child)
{
    Tree* clone = child.clone();
    children.push_back(clone);
}


Tree* Tree::createTree(const Session& session, int rootLabel)
{
    TreeType treeType = session.getTreeType();
    if(treeType == Root) return new RootTree(rootLabel);
    else if(treeType == MaxRank) return new MaxRankTree(rootLabel);
    return new CycleTree(rootLabel, session.getCycle());
}


void Tree::addChild(Tree* child)
{
    children.push_back(child);
}


bool Tree::hasChildren() const
{
    return !children.empty();
}