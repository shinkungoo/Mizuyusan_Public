//----------------------------------------------------------------------
//
// TestISetEx.cpp : Test program for Lab8.
//
//----------------------------------------------------------------------

#include <iostream>
using namespace std;

#include "iSetEx.h"  // your header file for class iSetEx

int main(int argc, char** argv)
try
{
    // ***** test for initialization *****

    iSetEx s1{100000};  // an integer set with 100 maximum elements
    iSetEx s2{100000};   // an integer set with 110 maximum elements

    // ***** test for printing *****

    cout << "Set s1 after initialization: " << endl;
    cout << s1;     // display set
    cout << endl;

    // ***** test for size *****

    cout << "The number of elements in Set s1: " << s1() << endl;
    cout << "The capacity of Set s1: " << s1.capacity() <<endl;

    cout << endl << "Set s2 after initialization: " << endl;
    cout << s2;       // display set
    cout << endl;
    cout << "The number of elements in Set s2: " << s2() << endl;
    cout << "The capacity of Set s2: " << s2.capacity() << endl;
    cout << endl;

    // ***** test for inserting *****

    for (int i{200};i<22000;i++)   s1.insert(i);        // insert 20 elements from 200 to 219
    for (int i{190};i<21500;i++)   s2.insert(i);        // insert 25 elements from 190 to 214

    cout << "Set s1 after inserting: " << endl;
    cout << s1;   // display set
    cout << endl;
    cout << "The number of elements in Set s1: " << s1() << endl;
    cout << "The capacity of Set s1: " << s1.capacity() << endl;
    cout << endl << "Set s2 after inserting: " << endl;
    cout << s2;     // display set
    cout << endl;
    cout << "The number of elements in Set s2: " << s2() << endl;
    cout << "The capacity of Set s2: " << s2.capacity() << endl;
    cout << endl;

    // ***** test for union *****

    cout << "Union of two integer sets s1 and s2: " << endl;
    cout << s1;     // display set
    cout << " | ";
    cout << s2;
    cout << " = ";
    cout << (s1|s2);     // display union result
    cout << endl;
    cout << endl;

    // ***** test for intersection *****

    cout << "Intersection of two integer sets s1 and s2: " << endl;
    cout << s1;
    cout << " & ";
    cout << s2;
    cout << " = ";
    cout << (s1&s2);
    cout << endl;
    cout << endl;

    // ***** test for difference *****

    cout << "Difference of two integer sets s1 and s2: " << endl;
    cout << s1;
    cout << " - ";
    cout << s2;
    cout << " = ";
    cout << s1-s2;
    cout << endl;
    cout << endl;

    cout << "Difference of two integer sets s2 and s1: " << endl;
    cout << s2;
    cout << " - ";
    cout << s1;
    cout << " = ";
    cout << s2-s1;
    cout << endl;
    cout << endl;

    // ***** test for symmetric difference *****

    cout << "Symmetric difference of two integer sets s1 and s2: " << endl;
    cout << s1;
    cout << " symmetric- ";
    cout << s2;
    cout << " = ";
    cout << s1.setSymmetricDifference(s2);
    cout << endl;
    cout << endl;

    // ***** test for assignment *****

    cout << "Set s1 after assignment s1=s2: " << endl;
    s1=s2;
    cout << s1;
    cout << endl;
    cout << endl;

    // ***** test for "clear" *****

    cout << "Set s2 after erasing all elements: " << endl;
    s2.clear();
    cout << s2;
    cout << endl;
    cout << endl;

    // ***** test   "empty" *****

    if (s1.empty()) cout << "Set s1 is empty " << endl;
    else cout << "Set s1 is NOT empty " << endl;
    cout << endl;

    if (s2.empty()) cout << "Set s2 is empty " << endl;
    else cout << "Set s2 is NOT empty " << endl;
    cout << endl;

    // ***** test  "full" *****

    if (s1.full()) cout << "Set s1 is fully " << endl;
    else cout << "Set s1 is NOT full " << endl;
    cout << endl;

    if (s2.full()) cout << "Set s2 is full " << endl;
    else cout << "Set s2 is NOT full " << endl;
    cout << endl;

    // ***** test for "erase" *****

    cout << "Set s1 after erasing an element 211 : " << endl;
    s1.erase(211);
    cout << s1;
    cout << endl;
    cout << endl;
    cout << "Set s1 after erasing an element 288 : " << endl;
    s1.erase(288);
    cout << s1;
    cout << endl;
    cout << endl;

    // ***** test for "contains" *****
    int e{222};
    if (s1.contains(e)) cout << e << " is a member of s1" << endl;
    else cout << e << " is NOT a member of s1" << endl;
    cout << endl;
    e+=888;
    if (s1.contains(e)) cout << e << " is a member of s1" << endl;
    else cout << e << " is NOT a member of s1" << endl;
    cout << endl;


    // ***** test for "isSubset" *****

    if (s1.isSubset(s2)) cout << "Set s2 is a subset of s1" << endl;
    else cout << "Set s2 is NOT a subset of s1" << endl;
    cout << endl;

    cout << "Insert an element 888 into set s2 : " << endl;
    s2.insert(888);
    cout << "Set s2 : " << endl;
    cout << s2;
    cout << endl;

    cout << endl;

    if (s1.isSubset(s2)) cout << "Set s2 is a subset of s1" << endl;
    else cout << "Set s2 is NOT a subset of s1" << endl;
    cout << endl;

    // ***** test for input *****
    cout << "Input s1 and s2 (format: {...,...}) : " << endl;
    cin >> s1 >> s2;
    cout << "Set s1 after input : " << endl << s1 << endl;
    cout << "Set s2 after input : " << endl << s2 << endl;
    cout << endl;

    // ***** test for assignments *****

    iSetEx t{s1};
    cout << "Set s1 after s1|=s2 : " << endl << (s1|=s2) << endl;
    cout << endl;
    s1=t;
    cout << "Set s1 after s1&=s2 : " << endl << (s1&=s2) << endl;
    cout << endl;
    s1=t;
    cout << "Set s1 after s1-=s2 : " << endl << (s1-=s2) << endl;
    cout << endl;


    // ***** test for exception throwing *****

    cout << "insert 1000 elements from 1 to 999 into set s1 : " << endl;
    for (int i{1};i<1000;i++)
        s1.insert(i);        // insert 1000 elements from 1 to 999

        return 0;
}

// ***** exception handling *****

catch(iSetEx::bad_iSetEx bi)  // catch exceptions related to integer set
    { switch (bi.errnum)          // # of exceptions
    { case 1: cerr << "bad iSetEx: constructor parameter<1 , exit " << endl;
        // error of constructor parameter
        break;
        case 2: cerr << "bad iSetEx: maximum elements reached(is Full), exit " << endl;
        // overflow of integer set
        break;
    }
    return 1;
    }
catch(...)
{  cerr << "Unknown Exception, Exit " << endl;
    return 2;
}



