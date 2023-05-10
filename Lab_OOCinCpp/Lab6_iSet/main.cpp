//----------------------------------------------------------------------
//
// TestISet.cpp : Test program for Lab6.
//
//----------------------------------------------------------------------

#include <iostream>
using namespace std;

#include "iSet.h"  // your header file for class tSet


int main(int argc, char** argv)
{
    // ***** test for initialization *****

    iSet s1{100};  // an integer set with 100 maximum elements
    iSet s2{110};   // an integer set with 110 maximum elements



    // ***** test for printing *****

    cout << "Set s1 after initialization: " << endl;
    cout << s1 << endl;     // display set

    // ***** test for size *****

    cout << "The number of elements in Set s1: " << s1.size() << endl;
    cout << "The capacity of Set s1: " << s1.capacity() <<endl;

    cout << endl << "Set s2 after initialization: " << endl;
    cout << s2 << endl;
    cout << "The number of elements in Set s2: " << s2.size() << endl;
    cout << "The capacity of Set s2: " << s2.capacity() << endl;
    cout << endl;

    // ***** test for inserting *****

    for (int i{200};i<203;i++)   s1.insert(i);
    for (int i{190};i<225;i++)   s2.insert(i);

    cout << "Set s1 after inserting: " << endl;
    cout << s1 << endl;
    cout << "The number of elements in Set s1: " << s1.size() << endl;
    cout << "The capacity of Set s1: " << s1.capacity() << endl;
    cout << endl << "Set s2 after inserting: " << endl;
    cout << s2 << endl;
    cout << "The number of elements in Set s2: " << s2.size() << endl;
    cout << "The capacity of Set s2: " << s2.capacity() << endl;
    cout << endl;

    // ***** test for union *****

    cout << "Union of two integer sets s1 and s2: " << endl;
    cout << s1 << " & " << s2 << " = " << (s1 & s2) << endl;
    cout << endl;

    // ***** test for intersection *****

    cout << "Intersection of two integer sets s1 and s2: " << endl;
    s1.print();
    cout << " ^";
    s2.print();
    cout << " = ";
    iSet r2{s1.setIntersection(s2)};  // compute intersection of two integer sets
    r2.print();
    cout << endl;
    cout << endl;

    // ***** test for difference *****

    cout << "Difference of two integer sets s1 and s2: " << endl;
    s1.print();
    cout << " -";
    s2.print();
    cout << " = ";
    iSet r3{s1.setDifference(s2)};     // compute difference of two integer sets
    r3.print();
    cout << endl;
    cout << endl;

    cout << "Difference of two integer sets s2 and s1: " << endl;
    s2.print();
    cout << " -";
    s1.print();
    cout << " = ";
    iSet r4{s2.setDifference(s1)};     // compute difference of two integer sets
    r4.print();
    cout << endl;
    cout << endl;

    // ***** test for symmetric difference *****

    cout << "Symmetric difference of two integer sets s1 and s2: " << endl;
    s1.print();
    cout << " *";
    s2.print();
    cout << " = ";
    iSet r5{s1.setSymmetricDifference(s2)};   // compute symmetric difference of two integer sets
    r5.print();
    cout << endl;
    cout << endl;

    // ***** test for assignment *****

    cout << "Set s1 after assignment s1=s2: " << endl;
    s1=s2;
    s1.print();
    cout << endl;
    if(s1 == s2){
        cout << "equal" << endl;
    }else{
        cout << " no!!!" << endl;
    }

    cout << endl;

    // ***** test for "clear" *****

    cout << "Set s2 after erasing all elements: " << endl;
    s2.clear();
    s2.print();
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
    s1.print();
    cout << endl;
    cout << endl;
    cout << "Set s1 after erasing an element 288 : " << endl;
    s1.erase(288);
    s1.print();
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

    if (s1 < s2) cout << "Set s1 is a subset of s2" << endl;
    else cout << "Set s1 is NOT a subset of s2" << endl;
    cout << endl;

    if (s1 > s2) cout << "Set s1 is a superset of s2" << endl;
    else cout << "Set s1 is NOT a superset of s2" << endl;
    cout << endl;

    cout << "Insert an element 888 into set s2 : " << endl;
    s2.insert(888);
    cout << "Set s2 : " << endl;
    s2.print();
    cout << endl;

    cout << endl;

    if (s1 < s2) cout << "Set s2 is a subset of s1" << endl;
    else cout << "Set s2 is NOT a subset of s1" << endl;
    cout << endl;

    if (s1 > s2) cout << "Set s2 is a superset of s1" << endl;
    else cout << "Set s2 is NOT a superset of s1" << endl;
    cout << endl;

    cout << s1 << endl << s2 << endl;

    return 0;
}

