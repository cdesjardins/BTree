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
#ifndef MORPHY_Hxx
#define MORPHY_Hxx
 
using namespace std;

class morphy
{
public:
    /******************************************************
    **
    **  Constructor
    **
    *******************************************************/

    morphy()
    {
    }

    /******************************************************
    **
    **  Copy Constructor
    **  if any other data is added to morphy, then it should
    **  be copied from p to the local storage here.
    **
    *******************************************************/
    morphy(morphy *p) 
    {
        m_nTip = p->getTip();
    }

    /******************************************************
    **
    **  
    **
    *******************************************************/
    void setTip(int tip)
    {
        m_nTip = tip;
    }

    /******************************************************
    **
    **  
    **
    *******************************************************/
    const int getTip()
    {
        return m_nTip;
    }

    /******************************************************
    **
    **  Overloaded operator == used to compare current 
    **  morphy with another morphy. Required to be used with 
    **  CTreeNode.
    **
    *******************************************************/
    bool operator==(const morphy &other) const
    {
        return m_nTip == other.m_nTip;
    }

    /******************************************************
    **
    **  Overloaded operator < used to compare current 
    **  morphy with another morphy. Required to be used with 
    **  CTreeNode.
    **
    *******************************************************/
    bool operator<(const morphy &other) const
    {
        return m_nTip < other.m_nTip;
    }

    /******************************************************
    **
    **  Overloaded operator << used to easily cout<< a morphy
    **  data struct, also used in CTreeNode.
    **
    *******************************************************/
    friend ostream &operator<<(ostream &os, const morphy& m);
private:
    int m_nTip;
};

#endif
