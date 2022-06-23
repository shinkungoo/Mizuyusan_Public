/** This file is created by Shizumu on 2022/4/14.
 *  Here is the implementation of iSet.h
 */
#include <iostream>
#include "AVLtree.h"

inline int max(int a, int b) { return a > b ? a : b; } // simple inline function
namespace AVLTreeClass {
    /**the specific implementation of AVL tree node**/
    template<typename T>
    AVLTree<T>::AVLTreeNode::AVLTreeNode(T x, int h, bool isInit, AVLTreeNode *left, AVLTreeNode *right, AVLTreeNode *parent)
    {
        _element = x;
        _height = h;
        _isInitialized = isInit;
        _left = left;
        _right = right;
        _parent = parent;
    }

    template<typename T>
    AVLTree<T>::AVLTreeNode::~AVLTreeNode() = default;

    /// the definition of get function
    template<typename T>
    T  AVLTree<T>::AVLTreeNode::get_element() const
    {
        return _element;
    }

    template<typename T>
    int  AVLTree<T>::AVLTreeNode::get_height(const AVLTreeNode *node) const
    {
        if (node == nullptr) {
            return -1;
        } else {
            return _height;
        }
    }

    template<typename T>
    bool  AVLTree<T>::AVLTreeNode::get_isInitialized() const
    {
        return _isInitialized;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::AVLTreeNode::get_left_child() const
    {
        return _left;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::AVLTreeNode::get_right_child() const
    {
        return _right;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::AVLTreeNode::get_parent() const
    {
        return _parent;
    }

    /// the definition of set function
    template<typename T>
    void AVLTree<T>::AVLTreeNode::set_element(T x) {
        _element = x;
    }

    template<typename T>
    void AVLTree<T>::AVLTreeNode::set_height(int h) {
        _height = h;
    }

    template<typename T>
    void AVLTree<T>::AVLTreeNode::set_isInitialized(bool init) {
        _isInitialized = init;
    }

    template<typename T>
    void AVLTree<T>::AVLTreeNode::set_left_child(AVLTreeNode *left) {
        _left = left;
    }

    template<typename T>
    void AVLTree<T>::AVLTreeNode::set_right_child(AVLTreeNode *right) {
        _right = right;
    }

    template<typename T>
    void AVLTree<T>::AVLTreeNode::set_parent(AVLTreeNode *parent) {
        _parent = parent;
    }
    /******************************************************/
    /**the specific implementation of AVL tree iteration**/
    /// initialize static member
    template<typename T>
    typename AVLTree<T>::AVLTreeNode * AVLTree<T>::AVLTreeIteration::_end = new AVLTreeNode{0, 0};
    /// get function
    template<typename T>
    typename AVLTree<T>::AVLTreeNode * AVLTree<T>::AVLTreeIteration::get_current_ptr() const
    {
        return _current;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode * AVLTree<T>::AVLTreeIteration::get_end_ptr() const
    {
        return _end;
    }

    /// constructors and destructors
    template<typename T>
    AVLTree<T>::AVLTreeIteration::AVLTreeIteration(AVLTreeNode *node)
    {
        _current = node;
    }

    template<typename T>
    AVLTree<T>::AVLTreeIteration::~AVLTreeIteration() = default;

    template<typename T>
    AVLTree<T>::AVLTreeIteration::AVLTreeIteration(const AVLTreeIteration &i)
    {
        _current = i.get_current_ptr();
    }

    /// operator overloading
    template<typename T>
    typename AVLTree<T>::AVLTreeIteration & AVLTree<T>::AVLTreeIteration::operator=(const AVLTreeIteration &i)
    {
        if(this == &i){
            return *this;
        }
        _current = i.get_current_ptr();
        return *this;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeIteration &AVLTree<T>::AVLTreeIteration::operator=(AVLTreeNode* node) {
        _current = node;
        return *this;
    }

    template<typename T>
    bool AVLTree<T>::AVLTreeIteration::operator==(const AVLTreeIteration &i)
    {
        return _current == i.get_current_ptr();
    }

    template<typename T>
    bool AVLTree<T>::AVLTreeIteration::operator==(const AVLTreeNode* node)
    {
        return _current == node;
    }

    template<typename T>
    bool AVLTree<T>::AVLTreeIteration::operator!=(const AVLTreeIteration &i)
    {
        return _current != i.get_current_ptr();
    }

    template<typename T>
    bool AVLTree<T>::AVLTreeIteration::operator!=(const AVLTreeNode* node)
    {
        return _current != node;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeIteration & AVLTree<T>::AVLTreeIteration::operator++()
    {
        AVLTreeNode * temp = nullptr;
        if(_current->get_right_child() != nullptr){
            temp = _current->get_right_child();
            while(temp->get_left_child()){
                temp = temp->get_left_child();
            }
            _current = temp;
        }else{
            temp = _current->get_parent();
            while(temp && temp->get_right_child() == _current){
                _current = temp;
                temp = temp->get_parent();
            }
            if(temp == nullptr){
                _current = _end;
            }else{
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
            _free(root->get_left_child());
            _free(root->get_right_child());
            delete root;
            root = nullptr;
        }
    }

    template<typename T>
    int AVLTree<T>::_get_height(AVLTreeNode *node) {
        return node->get_height(node);
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_single_left_rotation(AVLTreeNode  *node2) {
        if (node2->get_left_child() == nullptr) {
            return node2;
        } else {
            AVLTreeNode  *node1;
            node1 = node2->get_left_child();

            if(node1->get_right_child() != nullptr){
                node1->get_right_child()->set_parent(node2);
            }
            node2->set_left_child(node1->get_right_child());

            node1->set_parent(node2);
            node2->set_parent(node1);
            node1->set_right_child(node2);

            node2->set_height(max(_get_height(node2->get_left_child()), _get_height(node2->get_right_child())) + 1);
            node1->set_height(max(_get_height(node1->get_left_child()), _get_height(node2)) + 1);

            return node1;
        }
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_single_right_rotation(AVLTreeNode *node1) {
        if (node1->get_right_child() == nullptr) {
            return node1;
        } else {
            AVLTreeNode *node2;
            node2 = node1->get_right_child();

            if(node2->get_left_child() != nullptr){
                node2->get_left_child()->set_parent(node1);
            }
            node1->set_right_child(node2->get_left_child());

            node2->set_parent(node1);
            node1->set_parent(node2);
            node2->set_left_child(node1);

            node1->set_height(max(_get_height(node1->get_left_child()), _get_height(node2->get_right_child())) + 1);
            node2->set_height(max(_get_height(node2->get_right_child()), _get_height(node1)) + 1);

            return node2;
        }
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_double_left_rotation(AVLTreeNode *node3) {
        if (node3->get_left_child() == nullptr) {
            return node3;
        } else {
            node3->set_left_child(_single_right_rotation(node3->get_left_child()));
            return _single_left_rotation(node3);
        }
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_double_right_rotation(AVLTreeNode *node1) {
        if (node1->get_right_child() == nullptr) {
            return node1;
        } else {
            node1->set_right_child(_single_left_rotation(node1->get_right_child()));
            return _single_right_rotation(node1);
        }
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_find(AVLTreeNode *root, T x) {
        if (root == nullptr) {
            return nullptr;
        } else if (x < root->get_element()) {
            return _find(root->get_left_child(), x);
        } else if (x > root->get_element()) {
            return _find(root->get_right_child(), x);
        } else {
            return root;
        }
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_find_min(AVLTreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        } else if (root->get_left_child() == nullptr) {
            return root;
        } else {
            return _find_min(root->get_left_child());
        }
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_find_max(AVLTreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        } else if (root->get_right_child() == nullptr) {
            return root;
        } else {
            return _find_max(root->get_right_child());
        }
    }

    template<typename T>
    int AVLTree<T>::_get_height_difference(AVLTreeNode *node) {
        return _get_height(node->get_left_child()) - _get_height(node->get_right_child());
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_balance(AVLTreeNode *node) {
        if (_get_height_difference(node) == 2) {
            if (_get_height_difference(node->get_left_child()) == 1) {
                node = _single_left_rotation(node);
            } else {
                node = _double_left_rotation(node);
            }
        } else if (_get_height_difference(node) == -2) {
            if (_get_height_difference(node->get_right_child()) == -1) {
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
        } else if (!node->get_isInitialized()) {
            node->set_element(x);
            node->set_isInitialized(true);
        } else if (x < node->get_element()) {
            node->set_left_child(_insert(node->get_left_child(), x));
            node->get_left_child()->set_parent(node);
            node = _balance(node);
        } else if (x > node->get_element()) {
            node->set_right_child(_insert(node->get_right_child(), x));
            node->get_right_child()->set_parent(node);
            node = _balance(node);
        }
        node->set_height(max(_get_height(node->get_left_child()), _get_height(node->get_right_child())) + 1);

        return node;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_delete(AVLTreeNode *node, T x) {
        AVLTreeNode *temp;

        if (node == nullptr) {
            return nullptr;
        } else if (!node->get_isInitialized()) {
            return node;
        } else if (x < node->get_element()) {
            node->set_left_child(_delete(node->get_left_child(), x));
            node = _balance(node);
        } else if (x > node->get_element()) {
            node->set_right_child(_delete(node->get_right_child(), x));
            node = _balance(node);
            //we find element to be deleted
        } else if (node->get_left_child() && node->get_right_child()/*two children*/) {

            temp = _find_min(node->get_right_child());
            node->set_element(temp->get_element());
            node->set_right_child(_delete(node->get_right_child(), node->get_element()));
        } else/*one or zero child*/{
            temp = node;
            if(node->get_left_child() == nullptr && node->get_right_child() == nullptr){
                delete temp;
                node = nullptr;
            }else if (node->get_left_child() == nullptr) {
                node->get_right_child()->set_parent(node->get_parent());
                node = node->get_right_child();
                delete temp;
            } else if (node->get_right_child() == nullptr) {
                node->get_left_child()->set_parent(node->get_parent());
                node = node->get_left_child();
                delete temp;
            }
        }

        return node;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::_clone(const AVLTreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        auto new_root = new AVLTreeNode {root->get_element(), root->get_height(root), root->get_isInitialized()};
        new_root->set_left_child(_clone(root->get_left_child()));
        new_root->set_right_child(_clone(root->get_right_child()));

        return new_root;
    }

    template<typename T>
    void AVLTree<T>::_in_order_travel(AVLTreeNode *root)
    {
        if (root != nullptr) {
            _in_order_travel(root->get_left_child());
            std::cout << root->get_element() << " ";
            _in_order_travel(root->get_right_child());
        }
    }

    template<typename T>
    void AVLTree<T>::_maintain()
    {
        _root->set_parent(nullptr);
        _iter_begin = _find_min(_root);
        _iter_root = _root;
        _iter_last = _find_max(_root);
    }

    /// the definitions of public methods
    template<typename T>
    typename AVLTree<T>::AVLTreeIteration AVLTree<T>::get_root() const
    {
        return _iter_root;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeIteration AVLTree<T>::get_begin() const
    {
        return _iter_begin;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeIteration AVLTree<T>::get_last() const
    {
        return _iter_last;
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeIteration AVLTree<T>::get_end() const
    {
        return _iter_end;
    }

    template<typename T>
    AVLTree<T>::AVLTree() {
        _root = new AVLTreeNode {0, 0};
        _iter_root = _root;
        _iter_begin = _iter_last = nullptr;
        _iter_end = _iter_root.get_end_ptr();
    }

    template<typename T>
    AVLTree<T>::~AVLTree<T>() {
        _free(_root);
    }

    template<typename T>
    AVLTree<T>::AVLTree(const AVLTree <T> &t) {
        _root = _clone(t.get_root().get_current_ptr());
        _iter_begin = t.get_begin();
        _iter_last = t.get_last();
        _iter_end = t.get_end();
    }

    template<typename T>
    typename AVLTree<T>::AVLTreeNode *AVLTree<T>::AVL_find(T x) {
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
        _root = new AVLTreeNode {0, 0};
        _iter_root = _root;
        _iter_begin = _iter_last = nullptr;
        _iter_end = _iter_root.get_end_ptr();
    }

    template<typename T>
    AVLTree <T> &AVLTree<T>::operator=(const AVLTree <T> &t) {
        if (this == &t) {
            return *this;
        }
        _free(_root);
        _root = _clone(t.get_root().get_current_ptr());
        return *this;
    }

    /// the instantiation of template( or will occur compile error)
    template class AVLTree<int>;
}




