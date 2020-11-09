#ifndef TREE_H_
#define TREE_H_

#include <vector>

class Session;

class Tree{
public:
    Tree(int rootLabel);
    void addChild(const Tree& child);
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
    //added
    Tree(const Tree& other);
    virtual ~Tree(); //added destructor
    Tree* getRightChild();
    int getNodeInd();
    virtual Tree * clone() const=0;
    bool hasChildren() const;
    Tree* getLeftChild();
    //



protected: //changed from private to protected
    int node;
    std::vector<Tree*> children;
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
    //added
    CycleTree(const CycleTree& other);
    Tree *clone() const;
    //
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    virtual int traceTree();
    //added
    MaxRankTree(const MaxRankTree& other);
    Tree *clone() const;
    //
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    virtual int traceTree();
    //added
    RootTree(const RootTree& other);
    Tree *clone() const;
    //
};

#endif