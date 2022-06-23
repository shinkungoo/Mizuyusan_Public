/** This file is created by Shizumu.
 *  Here we declare AVLTree class and tSet, and the default type of tSet is int set.
 *
 *  The basic data structure of set is AVL tree, and to meet the requirement of print we define a simple and toy
 *  iteration class--just a packaged ordered-moving pointer(although I want to use <iterator> but it's a STL...)
 */
#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

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
        class AVLTreeIteration{
        private:
            static AVLTreeNode * _end;
            // use a global dump memory to represent end node;
            AVLTreeNode * _current;
        public:
            /// get funtion
            AVLTreeNode * get_current_ptr() const;
            AVLTreeNode * get_end_ptr() const;
            /// constructors and destructors
            explicit AVLTreeIteration(AVLTreeNode * node = nullptr);
            ~AVLTreeIteration();
            AVLTreeIteration(const AVLTreeIteration & i);
            ///operator overloading
            AVLTreeIteration & operator=(const AVLTreeIteration & i);
            AVLTreeIteration & operator=(AVLTreeNode* node);
            bool operator==(const AVLTreeIteration &i);
            bool operator==(const AVLTreeNode* node);
            bool operator!=(const AVLTreeIteration &i);
            bool operator!=(const AVLTreeNode* node);
            AVLTreeIteration & operator++();
        };
    private:
        /// private member
        AVLTreeNode *_root;
        AVLTreeIteration _iter_root;
        AVLTreeIteration _iter_begin;
        AVLTreeIteration _iter_last;
        AVLTreeIteration _iter_end;
        /// private method
        void _free(AVLTreeNode *root);
        int _get_height(AVLTreeNode *node);
        AVLTreeNode *_single_left_rotation(AVLTreeNode *node);
        AVLTreeNode *_single_right_rotation(AVLTreeNode *node);
        AVLTreeNode *_double_left_rotation(AVLTreeNode *node);
        AVLTreeNode *_double_right_rotation(AVLTreeNode *node);
        AVLTreeNode *_find(AVLTreeNode *root, T x);
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
        AVLTreeIteration get_root() const;
        AVLTreeIteration get_begin() const;
        AVLTreeIteration get_last() const;
        AVLTreeIteration get_end() const;
        /// manipulation method
        AVLTreeNode *AVL_find(T x);
        void AVL_insert(T x);
        void AVL_delete(T x);
        void AVL_clear();
        /// operator overloading
        AVLTree<T> &operator=(const AVLTree<T> &t);
    };
};



#endif //AVLTREE_AVLTREE_H
