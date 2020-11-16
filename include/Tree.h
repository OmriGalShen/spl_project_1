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
    const Tree& operator=(const Tree& other); // copy assignment operator
    Tree(const Tree& other); // copy constructor
    Tree(Tree&& other); // move constructor
    Tree& operator=(Tree&& other); // move assignment
    void clean(); // used by move assignment+destructor
    virtual ~Tree(); // destructor
    void addChild(Tree* child);
    bool hasChildren() const;
    Tree* getLeftChild(); // const? - Eden
    int getNodeInd(); // const? - Eden
    virtual Tree * clone() const=0;
    std::vector<Tree*> getChildren();  // not used - Eden
    int getRootLabel(); // 1. not used 2. const? - Eden
    //


protected: // changed from private to protected
    int node;
    std::vector<Tree*> children;
};


class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
    //added
    const CycleTree& operator=(const CycleTree& other); // copy assignment operator
    CycleTree(const CycleTree& other); // copy constructor
    CycleTree(CycleTree&& other) ; // move constructor
    CycleTree& operator=(CycleTree&& other) ; // move assignment
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
    const MaxRankTree& operator=(const MaxRankTree& other); // copy assignment operator
    MaxRankTree(const MaxRankTree& other); // copy constructor
    MaxRankTree(MaxRankTree&& other) ; // move constructor
    MaxRankTree& operator=(MaxRankTree&& other) ; // move assignment
    Tree *clone() const;
    //
};


class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    virtual int traceTree();
    //added
    const RootTree& operator=(const RootTree& other); // copy assignment operator
    RootTree(const RootTree& other); // copy constructor
    RootTree(RootTree&& other) ; // move constructor
    RootTree& operator=(RootTree&& other) ; // move assignment
    Tree *clone() const;
    //
};

#endif