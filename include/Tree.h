#ifndef TREE_H_
#define TREE_H_

#include <vector>

class Session;


class Tree{
public:
    Tree(int rootLabel); // constructor
    void addChild(const Tree& child);
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree() = 0;
    // added
    Tree(const Tree& other); // copy constructor
    Tree(Tree&& other); // move constructor
    Tree& operator=(const Tree& other); // copy assignment operator
    Tree& operator=(Tree&& other); // move assignment operator
    virtual ~Tree(); // destructor
    void clean(); // used by move assignment+destructor
    void addChild(Tree* child); // to make the BFS better organized
    bool hasChildren() const;
    Tree* getLeftChild() const; // for the cycleTree
    int getNodeInd() const;
    virtual Tree* clone() const = 0;
    //

protected:
    int node;
    std::vector<Tree*> children;
};


class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
    //added
    virtual Tree* clone() const;
    //

private:
    int currCycle;
};


class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    virtual int traceTree();
    //added
    virtual Tree* clone() const;
    //
};


class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    virtual int traceTree();
    //added
    virtual Tree* clone() const;
    //
};

#endif