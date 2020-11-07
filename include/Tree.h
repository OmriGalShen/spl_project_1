#ifndef TREE_H_
#define TREE_H_

#include <vector>

class Session;

class Tree{
public:
    Tree(int rootLabel);
    Tree(const Tree& other);
    virtual ~Tree(); //added destructor
    void addChild(const Tree& child);
    Tree* getNewChild();
    int getNodeInd();
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
    virtual Tree * clone() const=0;

protected:
    int node;
    std::vector<Tree*> children;
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    CycleTree(const CycleTree& other);
    virtual int traceTree();
    Tree *clone() const;
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    MaxRankTree(const MaxRankTree& other);
    virtual int traceTree();
    Tree *clone() const;
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    RootTree(const RootTree& other);
    virtual int traceTree();
    Tree *clone() const;
};

#endif