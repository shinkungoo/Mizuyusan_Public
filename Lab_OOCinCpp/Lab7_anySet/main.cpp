//----------------------------------------------------------------------
//
//TestAnySet.cpp : Test program for Lab7.
//
//----------------------------------------------------------------------

#include <iostream>
using namespace std;

#include "anySet.h"  // your header file for class anySet

int main(int argc, char** argv)
try
{
    // ***** test for initialization *****

    anySet s1{5};   // a set with 5 maximum elements
    anySet s2{10};   // a  set with 10 maximum elements

    // ***** test for printing *****

    cout << "Set s1 after initialization: " << endl;
    s1.print();     // display set
    cout << endl;

    // ***** test for size *****

    cout << "The number of elements in Set s1: " << s1.size() << endl;
    cout << "The capacity of Set s1: " << s1.capacity() <<endl;

    cout << endl << "Set s2 after initialization: " << endl;
    s2.print();     // display set
    cout << endl;
    cout << "The number of elements in Set s2: " << s2.size() << endl;
    cout << "The capacity of Set s2: " << s2.capacity() << endl;
    cout << endl;

    //**************************************************************
    TelephoneNumber n1("aaa",53341234);
    TelephoneNumber n2("bbb",62231238);
    TelephoneNumber n3("ccc",53340333);
    TelephoneNumber n4("ddd",12345678);
    TelephoneNumber n5("police",110);
    TelephoneNumber n6("fire",119);
    TelephoneNumber n7("time",121);
    TelephoneNumber n[]={n1,n2,n3,n4,n5,n6,n7};
    //**************************************************************


    // ***** test for inserting *****

    for (int i=0;i<5;i++)
    {   s1.insert(n[i]);   // insert 5 elements from n1 to n5
    s2.insert(n[i+2]); // insert 5 elements from n3 to n7
    }

    cout << "Set s1 after inserting: " << endl;
    s1.print();   // display set
    cout << endl;
    cout << "The number of elements in Set s1: " << s1.size() << endl;
    cout << "The capacity of Set s1: " << s1.capacity() << endl;
    cout << endl << "Set s2 after inserting: " << endl;
    s2.print();     // display set
    cout << endl;
    cout << "The number of elements in Set s2: " << s2.size() << endl;
    cout << "The capacity of Set s2: " << s2.capacity() << endl;
    cout << endl;

    // ***** test for union *****

    cout << "Union of two sets s1 and s2: " << endl;
    s1.print();     // display set
    cout << " | ";
    s2.print();    // display set
    cout << " = ";
    anySet r1{s1.setUnion(s2)};   // compute union of twosets
    r1.print();     // display union result
    cout << endl;
    cout << endl;

    // ***** test for intersection *****

    cout << "Intersection of two sets s1 and s2: " << endl;
    s1.print();
    cout << " & ";
    s2.print();
    cout << " = ";
    anySet r2{s1.setIntersection(s2)};  // compute intersection of two sets
    r2.print();
    cout << endl;
    cout << endl;

    // ***** test for difference *****

    cout << "Difference of two sets s1 and s2: " << endl;
    s1.print();
    cout << " - ";
    s2.print();
    cout << " = ";
    anySet r3{s1.setDifference(s2)};     // compute difference of two sets
    r3.print();
    cout << endl;
    cout << endl;

    cout << "Difference of two integer sets s2 and s1: " << endl;
    s2.print();
    cout << " - ";
    s1.print();
    cout << " = ";
    anySet r4{s2.setDifference(s1)};     // compute difference of two sets
    r4.print();
    cout << endl;
    cout << endl;

    // ***** test for symmetric difference *****

    cout << "Symmetric difference of two sets s1 and s2: " << endl;
    s1.print();
    cout << " symmetric- ";
    s2.print();
    cout << " = ";
    anySet r5{s1.setSymmetricDifference(s2)};   // compute symmetric difference of two sets
    r5.print();
    cout << endl;
    cout << endl;

    // ***** test for assignment *****

    cout << "Set s1 after assignment s1=s2: " << endl;
    s1=s2;
    s1.print();
    cout << endl;
    cout << endl;

    // ***** test for "clear" *****

    cout << "Set s2 after erasing all elements: " << endl;
    s2.clear();
    s2.print();
    cout << endl;
    cout << endl;

    // ***** test for "isEmpty" *****

    if (s1.empty()) cout << "Set s1 is empty " << endl;
    else cout << "Set s1 is NOT empty " << endl;
    cout << endl;

    if (s2.empty()) cout << "Set s2 is empty " << endl;
    else cout << "Set s2 is NOT empty " << endl;
    cout << endl;

    // ***** test for "isFull" *****

    if (s1.full()) cout << "Set s1 is fully " << endl;
    else cout << "Set s1 is NOT full " << endl;
    cout << endl;

    if (s2.full()) cout << "Set s2 is full " << endl;
    else cout << "Set s2 is NOT full " << endl;
    cout << endl;

    // ***** test for "erase" *****

    cout << "Set s1 after erasing an element : " << endl;
    s1.erase(TelephoneNumber("qqq",1234));
    s1.print();
    cout << endl;
    cout << endl;
    cout << "Set s1 after erasing an element : " << endl;
    s1.erase(TelephoneNumber("qqq",1234));
    s1.print();
    cout << endl;
    cout << endl;

    // ***** test for "contains" *****

    if (s1.contains(n1)) cout << n1 << " is a member of s1" << endl;
    else cout << n1 << " is NOT a member of s1" << endl;
    cout << endl;
    TelephoneNumber x("aaqqq",123224);
    if (s1.contains(x)) cout << x << " is a member of s1" << endl;
    else cout << x << " is NOT a member of s1" << endl;
    cout << endl;


    // ***** test for "isSubset" *****

    if (s1.isSubset(s2)) cout << "Set s2 is a subset of s1" << endl;
    else cout << "Set s2 is NOT a subset of s1" << endl;
    cout << endl;

    cout << "Insert an element into set s2 : " << endl;
    s2.insert(TelephoneNumber("aaabbbccc",53341234));
    cout << "Set s2 : " << endl;
    s2.print();
    cout << endl;

    cout << endl;

    if (s1.isSubset(s2)) cout << "Set s2 is a subset of s1" << endl;
    else cout << "Set s2 is NOT a subset of s1" << endl;
    cout << endl;

    return 0;
}

// ***** exception handling *****

catch(anySet::bad_anySet bi)  // catch exceptions related to any set
    { switch (bi.errnum)          // # of exceptions
    { case 1: cerr << "bad anySet: constructor parameter<1 , exit " << endl;
        // error of constructor parameter
        break;
        case 2: cerr << "bad anySet: maximum elements reached(is Full), exit " << endl;
        // overflow of any set
        break;
    }
    return 0;
    }
