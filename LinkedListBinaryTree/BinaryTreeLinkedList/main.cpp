#include <iostream>
using namespace std;

template <class T>
class LinkBinaryTree;

template <class T>
class Node {
    friend LinkBinaryTree<T>;

    T info;
    Node<T>* left;
    Node<T>* right;

public:
    Node(T val) {
        info = val;
        left = right = nullptr;
    }
};

template <class T>
class LinkBinaryTree {
    Node<T>* root;

    void vlr(Node<T>* p) {
        if (p) {
            cout << p->info << ',';
            vlr(p->left);
            vlr(p->right);
        }
    }

    void lrv(Node<T>* p) {
        if (p) {
            lrv(p->left);
            lrv(p->right);
            cout << p->info << ',';
        }
    }

    void lvr(Node<T>* p) {
        if (p) {
            lvr(p->left);
            cout << p->info << ',';
            lvr(p->right);
        }
    }

    void removeNode(Node<T>* p) {
        if (!p)
            return;
        removeNode(p->left);
        removeNode(p->right);
        delete p;
    }

    Node<T>* searchParent(T key, Node<T>* p) {
        if (!p || (!p->left && !p->right))
            return nullptr;
        if ((p->left && p->left->info == key) || (p->right && p->right->info == key))
            return p;
        Node<T>* left = searchParent(key, p->left);
        if (left)
            return left;
        return searchParent(key, p->right);
    }

    int maxHeight(Node<T>* i) {
        if (!i)
            return 0;
        int sum1 = maxHeight(i->left);
        int sum2 = maxHeight(i->right);
        return 1 + (sum1 > sum2 ? sum1 : sum2);
    }

    T LowestCommonNode(Node<T>* p) {
        if (!p)
            return numeric_limits<T>::max();
        T val1 = p->info;
        T val2 = LowestCommonNode(p->left);
        T val3 = LowestCommonNode(p->right);
        if (val2 < val1)
            val1 = val2;
        if (val3 < val1)
            val1 = val3;
        return val1;
    }

public:
    LinkBinaryTree(T val) {
        root = new Node<T>(val);
    }

    ~LinkBinaryTree() {
        removeNode(root);
    }

    void setRoot(T val) {
        root = new Node<T>(val);
    }

    void setLeftChild(T parentKey, T value) {
        Node<T>* pr = search(parentKey, root);
        if (pr && !pr->left)
            pr->left = new Node<T>(value);
    }

    void setRightChild(T parentKey, T value) {
        Node<T>* pr = search(parentKey, root);
        if (pr && !pr->right)
            pr->right = new Node<T>(value);
    }

    void preOrder() {
        vlr(root);
    }

    void postOrder() {
        lrv(root);
    }

    void inOrder() {
        lvr(root);
    }

    T getParent(T value) {
        if (root->info == value)
            throw exception();
        Node<T>* p = searchParent(value, root);
        if (p)
            return p->info;
        else
            throw exception();
    }

    void remove(T node) {
        if (!root)
            return;
        if (root->info == node) {
            removeNode(root);
            root = nullptr;
            return;
        }
        Node<T>* p = searchParent(node, root);
        if (p->left && p->left->info == node) {
            removeNode(p->left);
            p->left = nullptr;
        }
        else {
            removeNode(p->right);
            p->right = nullptr;
        }
    }

    Node<T>* search(T x, Node<T>* p) {
        if (!p)
            return nullptr;
        if (p->info == x)
            return p;
        Node<T>* res = search(x, p->left);
        if (!res)
            res = search(x, p->right);
        return res;
    }

    int findBalanceFactor(T val) {
        Node<T>* p = search(val, root);
        if (!p)
            return 0;
        int count1 = maxHeight(p->left);
        int count2 = maxHeight(p->right);
        return count1 - count2;
    }

    T LowestCommonAncestor(T a, T b) {
        Node<T>* temp1 = search(a, root);
        Node<T>* temp2 = search(b, root);
        return LowestCommonNode(temp1) < LowestCommonNode(temp2) ? LowestCommonNode(temp1) : LowestCommonNode(temp2);
    }

    Node<T>* getRoot() {
        return root;
    }
};

int main() {
    LinkBinaryTree<int> t1(8);
    t1.setLeftChild(8, 5);
    t1.setRightChild(8, 6);
    t1.setRightChild(15, 9);
    t1.preOrder();
    return 0;
}
