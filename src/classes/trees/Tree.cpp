#include "Tree.h"
#include "Session.h"
#include "Graph.h"

using namespace std;

Tree::Tree(int rootLabel): // constructor
node(rootLabel),children(std::vector<Tree*>())
{}

Tree::Tree(const Tree &other): // copy constructor
node(other.node),children()
{
    for(auto child : other.children)
    {
        Tree* childClone = child->clone();
        children.push_back(childClone);
    }
}

void Tree::clean() // used by move assignment+destructor
{
    for(auto* child:children)
         delete child;
    children.clear();
    node = -1; // why? - Eden
}

Tree::~Tree() // destructor
{
    clean();
}

Tree::Tree(Tree&& other): //move constructor
node(other.node),children(std::move(other.children))
{}

Tree& Tree::operator=(Tree&& other) // move assignment
{
    if(this != &other)
    {
        this->clean();
        node = other.node;
        children = std::move(other.children); // need the std? - Eden
    }
    return (*this);
}

const Tree& Tree::operator=(const Tree& other) // copy assignment
{
    if(this != &other)
    {
        this->clean();
        node = other.node;
        children = other.children;
    }
    return (*this);
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

int Tree::getNodeInd()
{
    return node;
}

bool Tree::hasChildren() const
{
    return children.size()>0;
    // return !children.empty();
    // to solve a potential problem with int compered with unsigned int - Eden
}

Tree* Tree::getLeftChild()
{
    if(hasChildren())
        return children[0];
    return nullptr;
}

std::vector<Tree *> Tree::getChildren() {
    return children;
}

int Tree::getRootLabel() {
    return node;
}
