//
//  AVLTreeIndex.h
//  AVLTreeIndex
//
//  Class Owner: Hailey Phelps
//
//  This class defines the AVL Tree used to store objects of type WordRef.
//  It also defines the nodes used in the AVL tree as a class that is a private member.
//  Code used for reference: AVL Tree in class handout (based on AVL implementation of Mark Allen Weiss:
//  http://users.cis.fiu.edu/~weiss/dsaa_c++3/code/ )
//  and RosettaCode AVL Tree C++ http://rosettacode.org/wiki/AVL_tree#C.2B.2B and http://codereview.stackexchange.com/questions/70842/avl-tree-for-inserting-and-searching
//
#ifndef AVLTreeIndex_h
#define AVLTreeIndex_h

#include <iostream>
#include "WordRef.h"
#include <fstream>
#include "IndexInterface.h"
using namespace std;


class AVLTreeIndex: public IndexInterface
{
    friend ostream& operator<<(ostream& os, const AVLTreeIndex& wr);

private:
    //AVL tree node class
    class AVLNode
    {
    public:
        WordRef ref;
        AVLNode* left;
        AVLNode* right;
        int height;
        
        AVLNode(const WordRef &theRef, AVLNode* lt, AVLNode* rt, int h = 0) : ref(theRef), left(lt), right(rt), height(h){}
    };
    AVLNode* root;
    
private:
    inline const WordRef& elementAt(AVLNode* t) const
    {
        if(t == NULL)
        {
            cout << "Item not found." << endl;
            return root->ref;
        }
        else
            return t -> ref;
    }
    inline void insert(string& word, string& pageNum, AVLNode*& t)
    {
        if(t == NULL)
        {
            WordRef x(word, pageNum);
            t = new AVLNode(x, NULL, NULL);
        } else if(word < t -> ref.getWord())
        {
            insert(word, pageNum, t -> left);
            if(height(t -> left) - height(t->right) == 2)
            {
                if(word < t -> left -> ref.getWord())
                    rotateWithLeftChild(t);
                else
                    doubleWithLeftChild(t);
            }
        } else if(t -> ref.getWord() < word)
        {
            insert(word, pageNum, t -> right);
            if (height(t -> right) - height(t -> left) == 2)
            {
                if(t -> right -> ref.getWord() < word)
                    rotateWithRightChild(t);
                else
                    doubleWithRightChild(t);
            }
        }else
        {
            t->ref.add(pageNum);
        }
        
        t -> height = max(height(t -> left), height(t -> right)) + 1;
    }
    inline void insert(string& word, string& pageNum, int& frequency, AVLNode*& t)
    {
        if(t == NULL)
        {
            WordRef x(word, pageNum, frequency);
            t = new AVLNode(x, NULL, NULL);
        } else if(word < t -> ref.getWord())
        {
            insert(word, pageNum, frequency, t -> left);
            if(height(t -> left) - height(t->right) == 2)
            {
                if(word < t -> left -> ref.getWord())
                    rotateWithLeftChild(t);
                else
                    doubleWithLeftChild(t);
            }
        } else if(t -> ref.getWord() < word)
        {
            insert(word, pageNum, frequency, t -> right);
            if (height(t -> right) - height(t -> left) == 2)
            {
                if(t -> right -> ref.getWord() < word)
                    rotateWithRightChild(t);
                else
                    doubleWithRightChild(t);
            }
        }else
        {
            t->ref.add(pageNum, frequency);
        }
        
        t -> height = max(height(t -> left), height(t -> right)) + 1;
    }

    inline AVLNode* findMin(AVLNode* t) const
    {
        if(t == NULL)
            return t;
        while(t -> left != NULL)
            t = t -> right;
        return t;
    }
    inline AVLNode* findMax(AVLNode* t) const
    {
        if(t == NULL)
            return t;
        while(t -> right != NULL)
            t = t -> right;
        return t;
    }
    
    inline bool contains(string& word, AVLNode* t)
    {
        if(t == nullptr)
        {
            return false;
        } else if (word == t->ref.getWord())
        {
            return true;
        } else if(word < t->ref.getWord())
        {
            return contains(word, t->left);
        } else if(t->ref.getWord() < word)
        {
            return contains(word, t->right);
        } else
        {
            return false;
        }
    }
    
    WordRef& get(string& word, AVLNode* t)
    {
        if(t == nullptr)
        {
            cout << "Word not found." << endl;
            WordRef temp;
            return temp;
        } else if (word == t->ref.getWord())
        {
            return t->ref;
        } else if(word < t->ref.getWord())
        {
            return get(word, t->left);
        } else if(t->ref.getWord() < word)
        {
            return get(word, t->right);
        } else
        {
            cout << "Word not found." << endl;
            WordRef temp;
            return temp;
        }
    }

    inline void makeEmpty(AVLNode*& t) const
    {
        if(t != NULL)
        {
            makeEmpty(t -> left);
            makeEmpty(t -> right);
            delete t;
        }
        t = NULL;
    }
    inline int height(AVLNode* t) const
    {
        return t == NULL ? -1 : t -> height;
    }
    inline int max(int lhs, int rhs) const
    {
        return lhs > rhs ? lhs : rhs;
    }
    inline void rotateWithLeftChild(AVLNode*& k2) const
    {
        AVLNode* k1 = k2 -> left;
        k2 -> left = k1 -> right;
        k1 -> right = k2;
        k2 -> height = max(height(k2 -> left), height(k2 -> right)) + 1;
        k1 -> height = max (height(k1 -> left), k1 -> height) + 1;
        k2 = k1;
    }
    inline void rotateWithRightChild(AVLNode*& k1) const
    {
        AVLNode* k2 = k1 -> right;
        k1 -> right = k2 -> left;
        k2 -> left = k1;
        k1 -> height = max(height(k1 -> left), height(k1 -> right)) + 1;
        k2 -> height = max(height(k2 -> right), k1 -> height) + 1;
        k1 = k2;
    }
    inline void doubleWithLeftChild(AVLNode*& k3) const
    {
        rotateWithRightChild(k3 -> left);
        rotateWithLeftChild(k3);
    }
    inline void doubleWithRightChild(AVLNode*& k1) const
    {
        rotateWithLeftChild(k1 -> right);
        rotateWithRightChild(k1);
    }
    
    inline void inOrder(AVLNode*& t)
    {
        if(t != nullptr)
        {
            inOrder(t->left);
            cout << t->ref << endl;
            inOrder(t->right);
        }
    }
    
    inline void preOrder(AVLNode*& t, ofstream& x)
    {
        if(t != nullptr)
        {
            
            x << t->ref << endl;
            preOrder(t->left, x);
            preOrder(t->right, x);
        }
    }
    
    inline int getSize(AVLNode*& t) const
    {
        if(t == nullptr)
            return 0;
        else
            return getSize(t->left) + 1 + getSize(t->right);
    }
    

public:
    AVLTreeIndex() : root(NULL){}
    AVLTreeIndex(const AVLTreeIndex& rhs) : root(NULL)
    {
        *this = rhs;
    }
    
    
    const WordRef& findMin() const
    {
        return elementAt(findMin(root));
    }
    
    const WordRef& findMax() const
    {
        return elementAt(findMax(root));
    }
    
    
    bool isEmpty()
    {
        if(root==NULL)
            return true;
        else
            return false;
    }
    
    void clear()
    {
        makeEmpty(root);
        
    }
    
    bool contains(string& word)
    {
        if(contains(word, root))
        {
            return true;
        } else
        {
            return false;
        }
    }
    
    WordRef& get(string& word)
    {
        return get(word, root);
    }
    
    inline void insert(string& word, string& pageNum)
    {
        insert(word, pageNum, root);
    }
    inline void insert(string& word, string& pageNum, int& frequency)
    {
        insert(word, pageNum, frequency, root);
    }
    
    void inOrder()
    {
        inOrder(root);
    }
    
    void print(ofstream& x)
    {
        preOrder(root, x);
    }
    
    int getSize()
    {
        return getSize(root);
    }
    
    void check()
    {
        cout << root->ref.getWord() << endl;
        cout << root->left->ref.getWord() << endl;
        cout << root->left->left->ref.getWord() << endl;
        cout << root->left->left->left->ref.getWord() << endl;
        cout << root->left->left->right->ref.getWord() << endl;
        cout << root->left->right->ref.getWord() << endl;
        cout << root->left->right->right->ref.getWord() << endl;
        cout << root->right << endl;
        cout << root->right->left->ref.getWord() << endl;
    }
    
    ~AVLTreeIndex()
    {
        
    }
    
    //void remove(const WordRef& x) const;
    //const AVLTreeIndex& operator= (const AVLTreeIndex& rhs); // overloaded assignment operator?
    
};

#endif /* AVLTreeIndex_h */
