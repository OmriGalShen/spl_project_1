#include "Tree.h"
#include "Session.h"
#include "Graph.h"

using namespace std;





//            ***constructors and operators***


Tree::Tree(int rootLabel): node(rootLabel), children(std::vector<Tree*>()) // constructor
{}


Tree::Tree(const Tree &other): node(other.node) // copy constructor
{
    for(auto& child : other.children)
    {
        Tree* childClone = child->clone();
        children.push_back(childClone);
    }
}

Tree::Tree(Tree&& other): // move constructor
node(other.node),children(std::move(other.children))
{}

Tree& Tree::operator=(const Tree& other) // copy assignment
{
    if(this != &other)
    {
    }
    return *this;
}

Tree& Tree::operator=(Tree&& other) // move assignment
{
    if(this != &other)
    {
        clean();
        node = other.node;
        children = other.children;
        other.clean();
    }
    return (*this);
}

void Tree::clean() // used by move assignment+destructor
{
    for(auto* child:children)
         delete child;
    children.clear();
    node = -1;
}

Tree::~Tree() // destructor
{
    clean();
}







Tree* Tree::createTree(const Session& session, int rootLabel)
{
    TreeType treeType = session.getTreeType();
    if(treeType == Root)
        return new RootTree(rootLabel);
    else if(treeType == MaxRank)
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

int Tree::getNodeInd() const
{
    return node;
}

bool Tree::hasChildren() const
{
    return !children.empty();
}

Tree* Tree::getLeftChild()
{
    if(hasChildren())
        return children[0];
    return nullptr;
}


// for testing
//std::vector<Tree *> Tree::getChildren() {
//    return children;
//}
//
//int Tree::getRootLabel() {
//    return node;
//}
