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


