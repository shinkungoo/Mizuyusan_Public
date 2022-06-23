#include <iostream>
#include "AVLtree.h"

using std::cout;
using std::endl;

int main() {
    AVLTreeClass::AVLTree<int> t1;
    for(int i = 0 ; i < 6; i += 2){
        t1.AVL_insert(i);
    }
    for(int i = 7 ; i > 0; i -= 1){
        t1.AVL_insert(i);
    }
    for(auto i = t1.get_begin(); i != t1.get_end(); ++i ){
        cout<< i.get_current_ptr()->get_element() << " ";
    }
    cout << endl;
    t1.AVL_delete(12);
    t1.AVL_delete(4);
    for(auto i = t1.get_begin(); i != t1.get_end(); ++i ){
        cout<< i.get_current_ptr()->get_element() << "\n"[i != t1.get_last()];
    }

    return 0;
}
