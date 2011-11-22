#ifndef MORPHY_Hxx
#define MORPHY_Hxx
 
using namespace std;

typedef unsigned char statearray;

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
