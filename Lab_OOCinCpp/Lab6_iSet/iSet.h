/** This file is created by Shizumu.
 *  Here we declare AVLTree class and tSet, and the default type of tSet is int set.
 *
 *  The basic data structure of set is AVL tree, and to meet the requirement of print we define a simple and toy
 *  iteration class--just a packaged ordered-moving pointer(although I want to use <iterator> but it's a STL...)
 */
#ifndef ISET_ISET_H
#define ISET_ISET_H

#include <iostream>
#include <exception>

/**AVL tree class**/
namespace AVLTreeClass{
    template<typename T>
    class AVLTree {
    private:
        class AVLTreeNode {
        private:
            T _element;
            int _height;
            bool _isInitialized;
            AVLTreeNode *_left;
            AVLTreeNode *_right;
            AVLTreeNode *_parent;
        public:
            AVLTreeNode(T x, int h, bool isInit = false,
                        AVLTreeNode *left = nullptr, AVLTreeNode *right = nullptr, AVLTreeNode * parent = nullptr);
            ~AVLTreeNode();
            /// get function declaration
            T get_element() const;
            int get_height(const AVLTreeNode *node) const;
            bool get_isInitialized() const;
            AVLTreeNode *get_left_child() const;
            AVLTreeNode *get_right_child() const;
            AVLTreeNode *get_parent() const;
            /// set function declaration
            void set_element(T x);
            void set_height(int h);
            void set_isInitialized(bool init);
            void set_left_child(AVLTreeNode *left);
            void set_right_child(AVLTreeNode *right);
            void set_parent(AVLTreeNode *parent);
        };
    public:
        class AVLTreeIterator{
        private:
            static AVLTreeNode * _end;
            // use a global dump memory to represent end node;
            AVLTreeNode * _current;
        public:
            /// get funtion
            AVLTreeNode * get_current_ptr() const;
            AVLTreeNode * get_end_ptr() const;
            /// constructors and destructors
            explicit AVLTreeIterator(AVLTreeNode * node = nullptr);
            ~AVLTreeIterator();
            AVLTreeIterator(const AVLTreeIterator & i);
            ///operator overloading
            AVLTreeIterator & operator=(const AVLTreeIterator & i);
            AVLTreeIterator & operator=(AVLTreeNode* node);
            bool operator==(const AVLTreeIterator &i);
            bool operator==(const AVLTreeNode* node);
            bool operator!=(const AVLTreeIterator &i);
            bool operator!=(const AVLTreeNode* node);
            AVLTreeIterator & operator++();
        };
    private:
        /// private member
        AVLTreeNode *_root;
        AVLTreeIterator _iter_root;
        AVLTreeIterator _iter_begin;
        AVLTreeIterator _iter_last;
        AVLTreeIterator _iter_end;
        int _size;
        /// private method
        void _free(AVLTreeNode *root);
        int _get_height(AVLTreeNode *node);
        AVLTreeNode *_single_left_rotation(AVLTreeNode *node);
        AVLTreeNode *_single_right_rotation(AVLTreeNode *node);
        AVLTreeNode *_double_left_rotation(AVLTreeNode *node);
        AVLTreeNode *_double_right_rotation(AVLTreeNode *node);
        AVLTreeNode *_find(AVLTreeNode *root, T x) const;
        AVLTreeNode *_find_min(AVLTreeNode *root);
        AVLTreeNode *_find_max(AVLTreeNode *root);
        int _get_height_difference(AVLTreeNode * node);
        AVLTreeNode *_balance(AVLTreeNode * node);
        AVLTreeNode *_insert(AVLTreeNode *node, T x);
        AVLTreeNode *_delete(AVLTreeNode *node, T x);
        AVLTreeNode *_clone(const AVLTreeNode *root);
        void _maintain();
        void _in_order_travel(AVLTreeNode *root);
    public:
        AVLTree();
        ~AVLTree();
        AVLTree(const AVLTree<T> &t);
        /// iterator function
        AVLTreeIterator get_root() const;
        AVLTreeIterator get_begin() const;
        AVLTreeIterator get_last() const;
        AVLTreeIterator get_end() const;
        /// get size;
        int get_size()const;
        /// manipulation method
        AVLTreeNode * AVL_find(T x) const;
        void AVL_insert(T x);
        void AVL_delete(T x);
        void AVL_clear();
        /// operator overloading
        AVLTree<T> &operator=(const AVLTree<T> &t);
    };
};

/**set class**/
template<typename T = int>
class tSet {
public:
    /**exception class**/
    class bad_iSet : public std::exception {
    public:
        int errnum;
        explicit bad_iSet(int code) { errnum = code; }
    };
private:
    int _capacity;
    AVLTreeClass::AVLTree<T> _data;
public:
    /*basic manipulation of set*/
    AVLTreeClass::AVLTree<T> get_data() const;
    int size() const;
    int capacity() const;
    void rezise(int capacity);
    bool empty() const;
    bool full() const;
    bool find(T x) const;
    void insert(T x);
    void erase(T x);
    bool contains(T x);
    void print();
    void clear();

    /*constructors and destructors*/
    explicit tSet(int capacity = 1);        //constructor
    tSet(const tSet<T> &);                  //copy constructor
    ~tSet();                                //destructor
    /*algorithm of sets*/
    tSet<T> setUnion(const tSet<T> &s) const;
    tSet<T> setIntersection(const tSet<T> &s) const;
    tSet<T> setDifference(const tSet<T> &s) const;
    tSet<T> setSymmetricDifference(const tSet<T> &s) const;
    bool isSubset(const tSet<T> &s) const;
    bool isSuperset(const tSet<T> &s) const;
    /*operator overloading*/
    tSet<T> operator|(const tSet<T> &s) const;
    tSet<T> operator&(const tSet<T> &s) const;
    tSet<T> operator-(const tSet<T> &s) const;
    tSet<T> operator*(const tSet<T> &s) const;
    bool operator<(const tSet<T> &s) const;
    bool operator>(const tSet<T> &s) const;
    bool operator==(const tSet<T> &s) const;
    tSet<T> &operator=(const tSet<T> &s);

    template<typename t>
    friend std::ostream &operator<<(std::ostream &os, const tSet<t>  &s);
};

// to meet the requirement of test program
typedef tSet<int> iSet;

#endif //ISET_ISET_H
