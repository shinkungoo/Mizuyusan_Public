//***************************************************************
// Test Program for Lab9.
//***************************************************************

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <typeinfo>
#include <ctime>

using namespace std;

#include "ExtremeLong.h" // specification of ExtremeLong class

int main(int,char**)

try
{
    cout << "*** Test all operations of ExtremeLong class ***\n" << endl;

    string s{"-123456789012345678902131312421244622333223"};
    ExtremeLong n1{76543210}, n2{781231},
    n3{12312345678901234567890123456789098999999999999999999999999999xl},
    n4{"1"}, n5,
    n6{"123123456789012345678901234567890000"},n7{s};

    cout << "type of "   << 1234442423223243233223432XL << " is "

    << typeid(1234442423223243233223432XL).name() << "\n\n";

    cout << "type of "   << n1 << " is " << typeid(n1).name() << "\n\n";


    cout << "n1 is "   << n1 << "\nn2 is " << n2
    << "\nn3 is " << n3 << "\nn4 is " << n4
    << "\nn5 is " << n5 << "\nn6 is " << n6
    << "\nn7 is " << n7 << "\n\n";

    ExtremeLong n11(-767854321), n12(-767891234),
    n13("-1234567890123456789670123456789098999999999999999999999999999"),
    n14("-1"), n15;

    cout << "n11 is "   << n11 << "\nn12 is " << n12
    << "\nn13 is " << n13 << "\nn14 is " << n14
    << "\nn15 is " << n15 << "\n\n";

    n5 = n1 * n2;
    cout << n1 << " * " << n2 << " = " << n5 << "\n\n";

    cout << n3   << " * " << n3   << " = " << n3*n3   << "\n\n";
    cout << n13  << " * " << n13  << " = " << n13*n13 << "\n\n";
    cout << n3   << " * " << n13  << " = " << n3*n13  << "\n\n";
    cout << n13  << " * " << n3   << " = " << n13*n3  << "\n\n";

    cout << n3 << " + " << n4 << " = " <<  n3+n4 << "\n\n";

    n5 = n1 + 9;
    cout << n1 << " + " << 9 << " = " << n5 << "\n\n";

    n5 = n2 + "10000";
    cout << n2 << " + " << "10000" << " = " << n5 << "\n";

    n5 = n2 * 1111;
    cout << n2 << " * " << "1111" << " = " << n5 << endl;
    cout << "1111" << " * "  << n2 << " = " << 1111*n2 << endl << endl;

    cout << "123456789012345687932432048203XL*389838430850348058409385098409845XL=" <<
    123456789012345687932432048203XL*389838430850348058409385098409845XL << endl << endl;

    cout << "Enter two huge integers to evaluate their product:" << endl;
    ExtremeLong x,y;    cin >> x >> y;
    cout << x << "*" << y << "=" << x*y << endl << endl;


    cout << "***Test operations of ExtremeLong by a factorial computing***\n" << endl;


    cout << "Compute factorial(n): " << endl;

    { ExtremeLong product{1};
        long n;  cout << "Enter n: " << endl;  cin >> n;

        long startTime=clock();

        for (long idx{1};idx<=n;idx++)
        {
            cout << setw(5) << setfill(' ') << idx << flush;
            product *= idx;
            cout << "\b\b\b\b\b";
        }

        cout << endl << n << "! : " << product << endl;

        cout << "with " << product.digits() << " digit(s)"<<endl;


        long endTime{clock()};
        cout << endl << "Time Elasped : "
        << 1000*(double)(endTime-startTime) / CLOCKS_PER_SEC
        << " milliseconds." << endl << endl;
    }

    cout << "***Test operations of ExtremeLong by an exponent computing***\n" << endl;

    // compute a**b :

    cout << "Compute a**b : "  << endl;

    { ExtremeLong a; UtilityNumber<long> b;  cout << "Enter a & b: " << endl; cin >> a >> b;
        long startTime{clock()};
        cout << endl << a << "**" <<  b << " : "<< (a=a**b) << endl;
        cout << "with " << a.digits() << " digit(s)"<<endl;
        long endTime{clock()};
        cout << endl << "Time Elasped : "
        << 1000*(double)(endTime-startTime) / CLOCKS_PER_SEC
        << " milliseconds." << endl;
    }

    return 0;
}
catch(...) { cerr << "ERROR!" << endl; return 0; }
