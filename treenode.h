/*
    Copyright 2011 Chris Desjardins

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef TREENODE_Hxx
#define TREENODE_Hxx
 
#include <vector>
using namespace std;

/*=====================================================
==
==  Node
==
==
==
==
======================================================*/

template <class T>
class CNode 
{
public:
    /******************************************************
    **
    **  Copy constructor
    **
    *******************************************************/
    CNode(T data)
    {
        m_pData = new T(data);
        if (!m_pData)
        {
            cout<<"Error: Unable to allocate m_left"<<endl;
        }
        m_left = NULL;
        m_right = NULL;
    }

    /******************************************************
    **
    **  Destructor
    **
    *******************************************************/
    ~CNode()
    {
        if (m_pData)
        {
            delete (m_pData);
        }
        m_pData = NULL;
    }

    /******************************************************
    **
    **  
    **
    *******************************************************/
    T getData()
    {
        return *m_pData;
    }

    /******************************************************
    **
    **  Set the left node by invoking the copy constructor
    **
    *******************************************************/
    void setLeft(T data) 
    {
        m_left = new CNode<T>(data);
        if (!m_left)
        {
            cout<<"Error: Unable to allocate m_left"<<endl;
        }
    }

    /******************************************************
    **
    **  Set the right node by invoking the copy constructor
    **
    *******************************************************/
    void setRight(T data) 
    { 
        m_right = new CNode<T>(data); 
        if (!m_right)
        {
            cout<<"Error: Unable to allocate m_right"<<endl;
        }
    }

    /******************************************************
    **
    **  
    **
    *******************************************************/
    CNode* getLeft()
    {
        return m_left;
    }

    /******************************************************
    **
    **  
    **
    *******************************************************/
    CNode* getRight()
    {
        return m_right;
    }

private:
    CNode* m_left;
    CNode* m_right;
	T *m_pData;
};

/*=====================================================
==
==  CTreeNode
==
==
==
==
======================================================*/

template <class T>
class CTreeNode 
{
public:
    /******************************************************
    **
    **  
    **
    *******************************************************/
    CTreeNode() 
    {
        m_root = NULL;
    }

    /******************************************************
    **
    **  
    **
    *******************************************************/
    ~CTreeNode() 
    {
        deleteNodes();
    }
    
    /******************************************************
    **
    **  Deletes all allocated data in the tree
    **
    *******************************************************/
    void deleteNodes()
    {
        deleteNode(getRoot());
        m_root = NULL;
    }

    /******************************************************
    **
    **  Insert a new node, if the root is null then
    **  allocate a new root with the node copy constructor.
    **  otherwise recursively insert the new node into the
    **  correct location.
    **
    *******************************************************/
    void insertNode(T data)
    {
        if (m_root == NULL) 
        {
            m_root = new CNode<T>(data);
            if (!m_root)
            {
                cout<<"Error: Unable to allocate m_root"<<endl;
            }
        }
        else
        {
            insertNodeHelper(m_root, data);
        }
    }

    /******************************************************
    **
    **  
    **
    *******************************************************/
    CNode<T>* getRoot() 
    {
        return m_root; 
    }

    /******************************************************
    **
    **  Balance the tree by:
    **  1) populating a vector with all data in current tree in order
    **  2) delete all nodes in the current tree
    **  3) create a new balanced tree from the ordered vector.
    **
    *******************************************************/
    void balanceRoot()
    {
        vector <T> tmpVec;
        fillVec(getRoot(), &tmpVec);
        deleteNodes();
        insertFromVec(&tmpVec, 0, tmpVec.size() - 1);
    }

    /******************************************************
    **
    **  
    **
    *******************************************************/
    void printNodes()
    {
        printNodesHelper(getRoot());
        cout<<endl;
    }
    /******************************************************
    **
    **  
    **
    *******************************************************/
    int getHeight()
    {
        return getHeightHelper(getRoot());
    }

private:
    /******************************************************
    **
    **  Recursive function to insert a new node in the correct
    **  location in the tree.
    **
    *******************************************************/
    void insertNodeHelper(CNode <T>*node, T data)
    {
        if (data == node->getData())
        {
            return;
        }
        else if (data < node->getData())
        {
            if (node->getLeft() == NULL)
            {
                node->setLeft(data);
            }
            else
            {
                insertNodeHelper(node->getLeft(), data);
            }
        }
        else
        {
            if (node->getRight() == NULL)
            {
                node->setRight(data);
            }
            else
            {
                insertNodeHelper(node->getRight(), data);
            }
        }
    }

    /******************************************************
    **
    **  
    **
    *******************************************************/
    int getHeightHelper(CNode <T>*node)
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            return max(getHeightHelper(node->getLeft()), getHeightHelper(node->getRight())) + 1;
        }
    }

    /******************************************************
    **
    **  Recursive function used to populate a vector (aka array)
    **  with all of the data from the current tree. The data
    **  will be stored in the vector in order.
    **
    *******************************************************/
    void fillVec(CNode <T>*node, vector <T> *tmpVec)
    {
        if (node == NULL)
        {
            return;
        }

        fillVec(node->getLeft(), tmpVec);
        tmpVec->push_back(node->getData());
        fillVec(node->getRight(), tmpVec);
    }

    /******************************************************
    **
    **  Recursive function used to populate the tree from 
    **  an ordered vector such that the resultant tree is 
    **  balanced.
    **
    *******************************************************/
    void insertFromVec(vector <T> *tmpVec, int low, int high)
    {
        int middlePos;
        T data;

        if (high < low)
        {
            return;
        }
        middlePos = low + (high - low) / 2;

        data = tmpVec->at(middlePos);
        insertNode(data);

        insertFromVec(tmpVec, low, middlePos - 1);
        insertFromVec(tmpVec, middlePos + 1, high);
    }

    /******************************************************
    **
    **  Print out the tree
    **
    *******************************************************/
    void printNodesHelper(CNode <T>*node)
    {
        if (node == NULL)
        {
            return;
        }

        printNodesHelper(node->getLeft());
        cout<<*node->getData();
        printNodesHelper(node->getRight());
    }

    /******************************************************
    **
    **  Deletes a single node, but recusively calls itself
    **  to make sure all other nodes are deleted as well.
    **
    *******************************************************/
    void deleteNode(CNode <T>*node)
    {
        CNode <T>*l;
        CNode <T>*r;
        if (node == NULL)
        {
            return;
        }
        l = node->getLeft();
        r = node->getRight();
        deleteNode(l);
        delete(node);
        deleteNode(r);
    }

    /* data */
    CNode <T>*m_root;
};

#endif
