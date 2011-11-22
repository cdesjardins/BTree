#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "treenode.h"
#include "morphy.h"
/*
** The << operator is part of the morphy class, but
** it cant be part of the class because of ostream.
** So it goes here, and is a friend of morphy.
*/
ostream &operator<<(ostream &os, const morphy& m)
{
    os<<m.m_nTip<<" ";
    return os;
}

int main()
{
    /* sample code with morphy, and int */
    CTreeNode<morphy> mtree;
    CTreeNode<int> itree;
    morphy mdata;
    int idata;
    int i;

    srand((unsigned int)time(NULL));
    for (i = 0; i < 10000; i++)
    {
        /* fill both trees with the same data */
        idata = rand();
        mdata.setTip(idata);
        mtree.insertNode(mdata);
        itree.insertNode(idata);
    }

    //tree.printNodes();
    cout<<"mHeight: "<<mtree.getHeight()<<endl;
    cout<<"iHeight: "<<itree.getHeight()<<endl;
    mtree.balanceRoot();
    itree.balanceRoot();
    //tree.printNodes();
    cout<<"mHeight: "<<mtree.getHeight()<<endl;
    cout<<"iHeight: "<<itree.getHeight()<<endl;
}


