#ifndef TREE_H_
#define TREE_H_

#include <vector>



class Session;

class Tree{
public:
    Tree(int rootLabel); // constructor
    void addChild(const Tree& child);
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
    //added
    Tree(const Tree& other); // copy constructor
    Tree(Tree&& other); // move constructor
    Tree& operator=(const Tree& other); // copy assignment operator
    Tree& operator=(Tree&& other); // move assignment
    void clean(); // used by move assignment+destructor
    virtual ~Tree(); // destructor
    void addChild(Tree* child);
    bool hasChildren() const;
    Tree* getLeftChild(); // const? - Eden
    int getNodeInd() const;
    virtual Tree* clone() const=0;
    //


// for testing
//    std::vector<Tree*> getChildren();
//    int getRootLabel();


protected:
    int node;
    std::vector<Tree*> children;
};


class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
    //added
//    CycleTree(const CycleTree& other); // copy constructor
//    CycleTree(CycleTree&& other); // move constructor
//    CycleTree& operator=(const CycleTree& other); // copy assignment operator
//    CycleTree& operator=(CycleTree&& other); // move assignment
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
//    MaxRankTree(const MaxRankTree& other); // copy constructor
//    MaxRankTree(MaxRankTree&& other); // move constructor
//    MaxRankTree& operator=(const MaxRankTree& other); // copy assignment operator
//    MaxRankTree& operator=(MaxRankTree&& other); // move assignment
    virtual Tree* clone() const;
    //
};


class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    virtual int traceTree();
    //added
//    RootTree(const RootTree& other); // copy constructor
//    RootTree(RootTree&& other); // move constructor
//    RootTree& operator=(const RootTree& other); // copy assignment operator
//    RootTree& operator=(RootTree&& other); // move assignment
    virtual Tree* clone() const;
    //
};

#endif