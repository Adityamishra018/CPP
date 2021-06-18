#include <bits/stdc++.h>

using namespace std;

struct node {
    int key, priority, size;
    node *childL, *childR;

    node() {
        size = 0;
        childL = childR = this;
    }

    node(int k, node* l, node* r) {
        key = k;
        childL = l;
        childR = r;
        size = 1;
        priority = rand();
    }

    void update() {
        size = childL->size + childR->size + 1;
    }
};

class treap {
    node *nil, *root;

public:
    treap() {
        srand(time(0));
        root = nil = new node();
    }

    ~treap() {
        destroy(root);
        delete nil;
    }

    void clear() {
        destroy(root);
        root = nil;
    }

    int size() {
        return root->size;
    }

    int count(int key) {
        int res = 0;
        node* cur = root;

        while (cur != nil) {
            if (key <= cur->key) {
                res += (key == cur->key);
                cur = cur->childL;
            } else {
                cur = cur->childR;
            }
        }

        return res;
    }

    void insert(int key) {
        insert(root, new node(key, nil, nil));
    }

    bool erase(int key) {
        return erase(root, key);
    }
    int operator[](int idx) {
        node* cur = root;

        while (cur != nil && idx != cur->childL->size) {
            if (idx < cur->childL->size) {
                cur = cur->childL;
            } else {
                idx -= cur->childL->size + 1;
                cur = cur->childR;
            }
        }

        return cur->key;
    }

    int lower_bound(int val) {
        int ret = 0;

        node* cur = root;

        while (cur != nil) {
            if (val <= cur->key) {
                cur = cur->childL;
            } else {
                ret += cur->childL->size + 1;
                cur = cur->childR;
            }
        }

        return ret;
    }
    int upper_bound(int key) {
        return lower_bound(key + 1);
    }

private:

    void insert(node*& root, node* newNode) {
        if (root == nil) {
            root = newNode;
            return;
        }

        if (newNode->priority > root->priority) {
            split(root, newNode->childL, newNode->childR, newNode->key);
            root = newNode;
        } else {
            insert((newNode->key <= root->key) ? root->childL : root->childR, newNode);
        }

        root->update();
    }

    bool erase(node*& root, int key) {
        if (root == nil) {
            return 0;
        }

        bool ret = 1;

        if (key == root->key) {
            node* temp = root;
            merge(root->childL, root->childR, root);
            delete temp;
        } else {
            ret = erase((key <= root->key) ? root->childL : root->childR, key);
            root->update();
        }   

        return ret;
    }

    void split(node* root, node*& rootL, node*& rootR, int key) {
        if (root == nil) {
            rootL = rootR = nil;
            return;
        }

        if (key >= root->key) {
            rootL = root;
            split(root->childR, rootL->childR, rootR, key);
        } else {
            rootR = root;
            split(root->childL, rootL, rootR->childL, key);
        }

        root->update();
    }
    void merge(node* rootL, node* rootR, node*& root) {
        if (rootL == nil) {
            root = rootR;
            return;
        }

        if (rootR == nil) {
            root = rootL;
            return;
        }

        if (rootL->priority > rootR->priority) {
            root = rootL;
            merge(rootL->childR, rootR, root->childR);
        } else {
            root = rootR;
            merge(rootL, rootR->childL, root->childL);
        }

        root->update();
    }

    void destroy(node* root) {
        if (root == nil) {
            return;
        }

        destroy(root->childL);
        destroy(root->childR);
        delete root;
    }
};

int main(){
    //
}