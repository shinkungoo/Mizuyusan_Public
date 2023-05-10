/** This file is created by Shizumu on 2022-05-05.
 *  Here is the implementation of anySet.h
 *  update: use static_cast<T> to better its expansion.
 *  update: more overloading
 *  update: fixed: 1.some segmentation fault;
 *                 2.insert exception;
 *                 3.the copy constructor of AVL iterator
 */
#include <iostream>
#include "iSetEx.h"

inline int max(int a, int b) { return a > b ? a : b; } // simple inline function
namespace AVLTreeClass {
    /**the specific implementation of AVL tree node**/
    template<typename T>
    AVLTree<T>::AVLTreeNode::AVLTreeNode(T x, int h, bool isInit, AVLTreeNode *left, AVLTreeNode *right,
                                         AVLTreeNode *parent) {
        _element = x;
        _height = h;
        _isInitialized = isInit;
        _left = left;
        _right = right;
        _parent = parent;
    }

    template<typename T>
    AVLTree<T>::AVLTreeNode::~AVLTreeNode() = default;

    template<typename T>
    int AVLTree<T>::AVLTreeNode::get_height(const AVLTreeNode *node) const {
        if (node == nullptr) {
            return -1;
        } else {
            return _height;
        }
    }

    /******************************************************/
    /**the specific implementation of AVL tree iteration**/
    /// initialize static member
    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::AVLTreeIterator::_end = new AVLTreeNode{static_cast<T>(0), 0};

    /// get function
    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::AVLTreeIterator::get_current_ptr() const {
        return _current;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::AVLTreeIterator::get_end_ptr() const {
        return _end;
    }

    /// constructors and destructors
    template<typename T>
    AVLTree<T>::AVLTreeIterator::AVLTreeIterator(AVLTreeNode *node) {
        _current = node;
    }

    template<typename T>
    AVLTree<T>::AVLTreeIterator::~AVLTreeIterator() = default;

    template<typename T>
    AVLTree<T>::AVLTreeIterator::AVLTreeIterator(const AVLTreeIterator &i) {
        _current = i.get_current_ptr();
    }

    /// operator overloading
    template<typename T>
    typename AVLTree<T>::AVLTreeIterator &AVLTree<T>::AVLTreeIterator::operator=(const AVLTreeIterator &i) {
        if (this == &i) {
            return *this;
        }
        _current = i.get_current_ptr();
        return *this;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeIterator &AVLTree<T>::AVLTreeIterator::operator=(AVLTreeNode *node) {
        _current = node;
        return *this;
    }

    template<typename T>
    bool AVLTree<T>::AVLTreeIterator::operator==(const AVLTreeIterator &i) {
        return _current == i.get_current_ptr();
    }

    template<typename T>
    bool AVLTree<T>::AVLTreeIterator::operator==(const AVLTreeNode *node) {
        return _current == node;
    }

    template<typename T>
    bool AVLTree<T>::AVLTreeIterator::operator!=(const AVLTreeIterator &i) {
        return _current != i.get_current_ptr();
    }

    template<typename T>
    bool AVLTree<T>::AVLTreeIterator::operator!=(const AVLTreeNode *node) {
        return _current != node;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeIterator &AVLTree<T>::AVLTreeIterator::operator++() {
        AVLTreeNode *temp = nullptr;
        if (_current->_right != nullptr) {
            temp = _current->_right;
            while (temp->_left) {
                temp = temp->_left;
            }
            _current = temp;
        } else {
            temp = _current->_parent;
            while (temp && temp->_right == _current) {
                _current = temp;
                temp = temp->_parent;
            }
            if (temp == nullptr) {
                _current = _end;
            } else {
                _current = temp;
            }
        }

        return *this;
    }

    /******************************************************/
    /**the specific implementation of AVL tree**/
    /// the definitions of private methods
    template<typename T>
    void AVLTree<T>::_free(AVLTreeNode *root) {
        if (root != nullptr) {
            _free(root->_left);
            _free(root->_right);
            delete root;
            root = nullptr;
        }
    }

    template<typename T>
    int AVLTree<T>::_get_height(AVLTreeNode *node) {
        return node->get_height(node);
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_single_left_rotation(AVLTreeNode *node2) {
        if (node2->_left == nullptr) {
            return node2;
        } else {
            AVLTreeNode *node1;
            node1 = node2->_left;

            if (node1->_right != nullptr) {
                node1->_right->_parent = node2;
            }
            node2->_left = node1->_right;

            node1->_parent = node2;
            node2->_parent = node1;
            node1->_right = node2;

            node2->_height = max(_get_height(node2->_left), _get_height(node2->_right)) + 1;
            node1->_height = max(_get_height(node1->_left), _get_height(node2)) + 1;

            return node1;
        }
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_single_right_rotation(AVLTreeNode *node1) {
        if (node1->_right == nullptr) {
            return node1;
        } else {
            AVLTreeNode *node2;
            node2 = node1->_right;

            if (node2->_left != nullptr) {
                node2->_left->_parent = node1;
            }
            node1->_right = node2->_left;

            node2->_parent = node1;
            node1->_parent = node2;
            node2->_left = node1;

            node1->_height = max(_get_height(node1->_left), _get_height(node1->_right)) + 1;
            node2->_height = max(_get_height(node2->_right), _get_height(node1)) + 1;

            return node2;
        }
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_double_left_rotation(AVLTreeNode *node3) {
        if (node3->_left == nullptr) {
            return node3;
        } else {
            node3->_left = _single_right_rotation(node3->_left);
            return _single_left_rotation(node3);
        }
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_double_right_rotation(AVLTreeNode *node1) {
        if (node1->_right == nullptr) {
            return node1;
        } else {
            node1->_right = _single_left_rotation(node1->_right);
            return _single_right_rotation(node1);
        }
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_find(AVLTreeNode *root, T x) const {
        if (root == nullptr) {
            return nullptr;
        } else if (x < root->_element) {
            return _find(root->_left, x);
        } else if (x > root->_element) {
            return _find(root->_right, x);
        } else {
            return root;
        }
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_find_min(AVLTreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        } else if (root->_left == nullptr) {
            return root;
        } else {
            return _find_min(root->_left);
        }
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_find_max(AVLTreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        } else if (root->_right == nullptr) {
            return root;
        } else {
            return _find_max(root->_right);
        }
    }

    template<typename T>
    int AVLTree<T>::_get_height_difference(AVLTreeNode *node) {
        return _get_height(node->_left) - _get_height(node->_right);
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_balance(AVLTreeNode *node) {
        if (_get_height_difference(node) == 2) {
            if (_get_height_difference(node->_left) == 1) {
                node = _single_left_rotation(node);
            } else {
                node = _double_left_rotation(node);
            }
        } else if (_get_height_difference(node) == -2) {
            if (_get_height_difference(node->_right) == -1) {
                node = _single_right_rotation(node);
            } else {
                node = _double_right_rotation(node);
            }
        }

        return node;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_insert(AVLTreeNode *node, T x) {
        if (node == nullptr) {
            node = new AVLTreeNode{x, 0, true};
            _size++;
        } else if (!node->_isInitialized) {
            node->_element = x;
            node->_isInitialized = true;
            _size++;
        } else if (x < node->_element) {
            node->_left= _insert(node->_left, x);
            node->_left->_parent = node;
            node = _balance(node);
        } else if (x > node->_element) {
            node->_right = _insert(node->_right, x);
            node->_right->_parent = node;
            node = _balance(node);
        }
        node->_height = max(_get_height(node->_left), _get_height(node->_right)) + 1;

        return node;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_delete(AVLTreeNode *node, T x) {
        AVLTreeNode *temp;

        if (node == nullptr) {
            return nullptr;
        } else if (!node->_isInitialized) {
            return node;
        } else if (x < node->_element) {
            node->_left = _delete(node->_left, x);
            node = _balance(node);
        } else if (x > node->_element) {
            node->_right = _delete(node->_right, x);
            node = _balance(node);
            //we find element to be deleted
        } else if (node->_left && node->_right/*two children*/) {
            temp = _find_min(node->_right);
            node->_element = temp->_element;
            node->_right = _delete(node->_right, node->_element);
        } else/*one or zero child*/{
            temp = node;
            if (node->_left == nullptr && node->_right == nullptr) {
                delete temp;
                node = nullptr;
            } else if (node->_left == nullptr) {
                node->_right->_parent = node->_parent;
                node = node->_right;
                delete temp;
            } else if (node->_right == nullptr) {
                node->_left->_parent = node->_parent;
                node = node->_left;
                delete temp;
            }
            _size--;
        }

        return node;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_clone(const AVLTreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        auto new_root = new AVLTreeNode{root->_element, root->get_height(root), root->_isInitialized};
        new_root->_left = _clone(root->_left);
        if (new_root->_left) {
            new_root->_left->_parent = new_root;
        }
        new_root->_right = _clone(root->_right);
        if (new_root->_right) {
            new_root->_right->_parent = new_root;
        }

        return new_root;
    }

    template<typename T>
    void AVLTree<T>::_maintain() {
        _root->_parent = nullptr;
        _iter_root = _root;
        if(_root->_isInitialized){
            _iter_begin = _find_min(_root);
            _iter_last = _find_max(_root);
        }else{
            _iter_begin = _iter_last = _iter_end;
        }
    }

    /// the definitions of public methods
    template<typename T>
    typename AVLTree<T>::AVLTreeIterator AVLTree<T>::get_root() const {
        return _iter_root;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeIterator AVLTree<T>::get_begin() const {
        if (_iter_begin.get_current_ptr() == nullptr) {
            return _iter_end;
        } else {
            return _iter_begin;
        }
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeIterator AVLTree<T>::get_last() const {
        if (_iter_last.get_current_ptr() == nullptr) {
            return _iter_end;
        } else {
            return _iter_last;
        }
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeIterator AVLTree<T>::get_end() const {
        return _iter_end;
    }

    template<typename T>
    int AVLTree<T>::get_size() const {
        return _size;
    }

    template<typename T>
    AVLTree<T>::AVLTree() {
        _root = new AVLTreeNode{static_cast<T>(0), 0};
        _iter_root = _root;
        _iter_begin = _iter_last = nullptr;
        _iter_end = _iter_root.get_end_ptr();
        _size = 0;
    }

    template<typename T>
    AVLTree<T>::~AVLTree<T>() {
        _free(_root);
    }

    template<typename T>
    AVLTree<T>::AVLTree(const AVLTree<T> &t) {
        _root = _clone(t.get_root().get_current_ptr());
        _maintain();
        _iter_end = t.get_end();
        _size = t.get_size();
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::AVL_find(T x) const {
        return _find(_root, x);
    }

    template<typename T>
    void AVLTree<T>::AVL_insert(T x) {
        _root = _insert(_root, x);
        _maintain();
    }

    template<typename T>
    void AVLTree<T>::AVL_delete(T x) {
        _root = _delete(_root, x);
        _maintain();
    }

    template<typename T>
    void AVLTree<T>::AVL_clear() {
        _free(_root);
        _root = new AVLTreeNode{static_cast<T>(0), 0};
        _iter_root = _root;
        _iter_begin = _iter_last = nullptr;
        _iter_end = _iter_root.get_end_ptr();
        _size = 0;
    }

    template<typename T>
    AVLTree<T> &AVLTree<T>::operator=(const AVLTree<T> &t) {
        if (this == &t) {
            return *this;
        }
        _free(_root);
        _root = _clone(t.get_root().get_current_ptr());
        _maintain();
        _iter_end = t.get_end();
        _size = t.get_size();
        return *this;
    }

    /// the instantiation of template( or will occur compile error)
    template class AVLTree<int>;
}

/**the implementation of tSet**/
/// basic manipulation of set
template<typename T>
int tSet<T>::size() const {
    return _data.get_size();
}

template<typename T>
int tSet<T>::capacity() const {
    return _capacity;
}

template<typename T>
void tSet<T>::rezise(int capacity) {
    _capacity = capacity;
}

template<typename T>
bool tSet<T>::empty() const {
    return _data.get_size() == 0;
}

template<typename T>
bool tSet<T>::full() const {
    return _data.get_size() == _capacity;
}

template<typename T>
bool tSet<T>::find(T x) const {
    return _data.AVL_find(x) != nullptr;
}

template<typename T>
void tSet<T>::insert(T x) {
    if (!this->find(x) && _data.get_size() == _capacity) {
        throw bad_iSetEx(2);
    } else {
        _data.AVL_insert(x);
    }
}

template<typename T>
void tSet<T>::erase(T x) {
    _data.AVL_delete(x);
}

template<typename T>
bool tSet<T>::contains(T x) {
    return _data.AVL_find(x) != nullptr;
}

template<typename T>
void tSet<T>::clear() {
    _data.AVL_clear();
}

/// constructors and destructors

template<typename T>
tSet<T>::tSet(int capacity) {
    if (capacity < 1) {
        throw bad_iSetEx(1);
    } else {
        _capacity = capacity;
    }
}

template<typename T>
tSet<T>::tSet(const tSet<T> &s) {
    _data = s._data;
    _capacity = s._capacity;
}

template<typename T>
tSet<T>::~tSet(){
    _capacity = 1;
}

/// algorithm of sets
template<typename T>
tSet<T> tSet<T>::setUnion(const tSet<T> &s) const {
    tSet<T> ret = *this;
    ret.rezise(this->capacity() + s.capacity());
    for (auto i = s._data.get_begin(); i != s._data.get_end(); ++i) {
        ret.insert(i.get_current_ptr()->_element);
    }
    return ret;
}

template<typename T>
tSet<T> tSet<T>::setIntersection(const tSet<T> &s) const {
    tSet<T> ret{max(this->capacity(), s.capacity())};
    for (auto i = s._data.get_begin(); i != s._data.get_end(); ++i) {
        if (this->find(i.get_current_ptr()->_element)) {
            ret.insert(i.get_current_ptr()->_element);
        }
    }

    return ret;
}

template<typename T>
tSet<T> tSet<T>::setDifference(const tSet<T> &s) const {
    tSet<T> ret{max(this->capacity(), s.capacity())};
    for (auto i = this->_data.get_begin(); i != this->_data.get_end(); ++i) {
        if (!s.find(i.get_current_ptr()->_element)) {
            ret.insert(i.get_current_ptr()->_element);
        }
    }

    return ret;
}

template<typename T>
tSet<T> tSet<T>::setSymmetricDifference(const tSet<T> &s) const {
    return ((*this | s) - (*this & s));
}

template<typename T>
bool tSet<T>::isSubset(const tSet<T> &s) const {
    bool ret = true;
    if (s.empty()) {
        return true;
    } else {
        for (auto i = s._data.get_begin(); i != s._data.get_end(); ++i) {
            if (!this->find(i.get_current_ptr()->_element)) {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

template<typename T>
bool tSet<T>::isSuperset(const tSet<T> &s) const {
    bool ret = true;
    if (s.empty()) {
        ret = false;
    } else {
        for (auto i = this->_data.get_begin(); i != s._data.get_end(); ++i) {
            if (!s.find(i.get_current_ptr()->_element)) {
                ret = false;
                break;
            }
        }
    };

    return ret;
}


/// operator overloading
template<typename T>
tSet<T> tSet<T>::operator|(const tSet<T> &s) const {
    return this->setUnion(s);
}

template<typename T>
tSet<T> tSet<T>::operator&(const tSet<T> &s) const {
    return this->setIntersection(s);
}

template<typename T>
tSet<T> tSet<T>::operator-(const tSet<T> &s) const {
    return this->setDifference(s);
}

template<typename T>
tSet<T> tSet<T>::operator*(const tSet<T> &s) const {
    return this->setSymmetricDifference(s);
}

template<typename T>
tSet<T> tSet<T>::operator|=(const tSet<T> &s) {
    tSet<T> temp = *this | s;
    *this = temp;
    return temp;
}

template<typename T>
tSet<T> tSet<T>::operator&=(const tSet<T> &s) {
    tSet<T> temp = *this & s;
    *this = temp;
    return temp;
}

template<typename T>
tSet<T> tSet<T>::operator-=(const tSet<T> &s) {
    tSet<T> temp = *this - s;
    *this = temp;
    return temp;
}

template<typename T>
tSet<T> tSet<T>::operator*=(const tSet<T> &s) {
    tSet<T> temp = *this * s;
    *this = temp;
    return temp;
}

template<typename T>
bool tSet<T>::operator<(const tSet<T> &s) const {
    return this->isSuperset(s);
}

template<typename T>
bool tSet<T>::operator>(const tSet<T> &s) const {
    return this->isSubset(s);
}

template<typename T>
bool tSet<T>::operator==(const tSet<T> &s) const {
    bool ret = true;
    for (auto i = s._data.get_begin(); i != s._data.get_end(); ++i) {
        if (!this->find(i.get_current_ptr()->_element)) {
            ret = false;
            break;
        }
    }
    if (ret) {
        for (auto i = this->_data.get_begin(); i != s._data.get_end(); ++i) {
            if (!s.find(i.get_current_ptr()->_element)) {
                ret = false;
                break;
            }
        }
    }

    return ret;
}

template<typename T>
int tSet<T>::operator()() const {
    return this->size();
}


template<typename T>
tSet<T> &tSet<T>::operator=(const tSet<T> &s) {
    if (this == &s) {
        return *this;
    }
    _capacity = s._capacity;
    _data = s._data;

    return *this;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const tSet<T> &s) {
    os << "{";
    if (s._data.get_size() != 0) {
        for (auto i = s._data.get_begin(); i != s._data.get_end(); ++i) {
            os << i.get_current_ptr()->_element << ","[i == s._data.get_last()];
        }
    }
    os << "}";

    return os;
}

template<typename T>
std::istream &operator>>(std::istream &is, tSet<T> &s){
    tSet<T> temp{s.capacity()};
    char c;
    is >> c;
    T tx;
    if(c == '{'){
        is >> c;
        if(c != '}'){
            is.putback(c);
            while(is >> tx >> c && c == ','){
                temp.insert(tx);
                is >> c;
                if(c != '}'){
                    is.putback(c);
                }else{
                    break;
                }
            }
            temp.insert(tx);
        }
        if(c != '}'){
            is.clear(std::ios::badbit);
        }
    }else{
        is.clear(std::ios::badbit);
    }
    if(is){
        s = temp;
    }
    return is;
}

/// the instantiation of template( or will occur compile error)
template class tSet<int>;

template std::ostream &operator<<(std::ostream &os, const tSet<int> &s);
template std::istream &operator>>(std::istream &is, tSet<int> &s);
