#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

struct TreeNode {

    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    int val;
    int height;

    TreeNode(int val)
        : left(nullptr),
          right(nullptr),
          parent(nullptr),
          val(val),
          height(1) {}
};

// ==========================================
// HEIGHT
// ==========================================

int height(TreeNode* root) {

    return root ? root->height : 0;
}

void updateHeight(TreeNode* root) {

    if (!root) return;

    root->height = max(height(root->left),height(root->right)) + 1;
}

// pelna naprawa wysokosci po splay
void fixHeight(TreeNode* root) {

    if (!root) return;

    fixHeight(root->left);
    fixHeight(root->right);

    updateHeight(root);
}

// RIGHT ROTATE

TreeNode* rightRotate(TreeNode* y) {

    TreeNode* x = y->left;
    TreeNode* B = x->right;

    // rotacja
    x->right = y;
    y->left = B;

    // parent B
    if (B) {
        B->parent = y;
    }

    // parent x
    x->parent = y->parent;

    // przepiecie parenta y
    if (y->parent) {

        if (y == y->parent->left) {

            y->parent->left = x;

        } else {

            y->parent->right = x;
        }
    }

    y->parent = x;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// LEFT ROTATE

TreeNode* leftRotate(TreeNode* x) {

    TreeNode* y = x->right;
    TreeNode* B = y->left;

    // rotacja
    y->left = x;
    x->right = B;

    // parent B
    if (B) {
        B->parent = x;
    }

    // parent y
    y->parent = x->parent;

    // przepiecie parenta x
    if (x->parent) {

        if (x == x->parent->left) {

            x->parent->left = y;

        } else {

            x->parent->right = y;
        }
    }

    x->parent = y;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// SPLAY

TreeNode* splay(TreeNode* x) {

    if (!x) return nullptr;

    while (x->parent) {

        TreeNode* y = x->parent;
        TreeNode* z = y->parent;

        // ZIG

        if (!z) {

            if (x == y->left) {

                rightRotate(y);

            } else {

                leftRotate(y);
            }
        }

        // ZIG-ZIG LL

        else if (x == y->left && y == z->left) {

            rightRotate(z);
            rightRotate(y);
        }

        // ZIG-ZIG RR

        else if (x == y->right && y == z->right) {

            leftRotate(z);
            leftRotate(y);
        }

        // ZIG-ZAG LR

        else if (x == y->right && y == z->left) {

            leftRotate(y);
            rightRotate(z);
        }

        // ZIG-ZAG RL

        else {

            rightRotate(y);
            leftRotate(z);
        }
    }

    return x;
}

// INSERT BST

TreeNode* insertBST(TreeNode* root, int key, TreeNode*& inserted) {

    if (!root) {

        inserted = new TreeNode(key);

        return inserted;
    }

    if (key < root->val) {

        root->left = insertBST(root->left, key,inserted);

        root->left->parent = root;

    } else {

        root->right = insertBST(root->right, key,inserted);

        root->right->parent = root;
    }

    updateHeight(root);

    return root;
}

// INSERT


TreeNode* insert(TreeNode* root, int key) {

    TreeNode* inserted = nullptr;

    root = insertBST(root, key, inserted);

    root = splay(inserted);

    fixHeight(root);

    return root;
}

// SEARCH BST

TreeNode* searchBST(TreeNode* root, int key, TreeNode*& last) {

    if (!root) return nullptr;

    last = root;

    if (key < root->val) {

        return searchBST(root->left, key,last);

    } else if (key > root->val) {

        return searchBST(root->right, key, last);
    }

    return root;
}


// SEARCH


TreeNode* search(TreeNode* root, int key) {

    if (!root) return nullptr;

    TreeNode* last = nullptr;

    TreeNode* found = searchBST(root,key,last);

    if (found) {

        root = splay(found);

    } else {

        root = splay(last);
    }

    fixHeight(root);

    return root;
}


// FIND NEXT


TreeNode* findNext(TreeNode* root) {

    while (root && root->left) {

        root = root->left;
    }

    return root;
}


// DELETE BST


TreeNode* removeBST(TreeNode* root, int key, TreeNode*& parentRemoved) {

    if (!root) return nullptr;

    if (key < root->val) {

        root->left = removeBST(root->left, key, parentRemoved);

        if (root->left) {
            root->left->parent = root;
        }
    }

    else if (key > root->val) {

        root->right = removeBST(root->right, key,parentRemoved);

        if (root->right) {
            root->right->parent = root;
        }
    }

    else {

        // LEAF

        if (!root->left && !root->right) {

            parentRemoved = root->parent;

            delete root;

            return nullptr;
        }

        // ONE CHILD

        if (!root->left) {

            parentRemoved = root->parent;

            TreeNode* tmp = root->right;

            tmp->parent = root->parent;

            delete root;

            return tmp;
        }

        if (!root->right) {

            parentRemoved = root->parent;

            TreeNode* tmp = root->left;

            tmp->parent = root->parent;

            delete root;

            return tmp;
        }

        // TWO CHILDREN

        TreeNode* succ = findNext(root->right);

        root->val = succ->val;

        root->right = removeBST(root->right, succ->val,parentRemoved);

        if (root->right) {
            root->right->parent = root;
        }
    }

    updateHeight(root);

    return root;
}


// DELETE

TreeNode* remove(TreeNode* root, int key) {

    TreeNode* parentRemoved = nullptr;

    root = removeBST(root, key, parentRemoved);

    if (parentRemoved) {

        root = splay(parentRemoved);
    }

    fixHeight(root);

    return root;
}


// FREE


void free_subtree(TreeNode* root) {

    if (!root) return;

    free_subtree(root->left);
    free_subtree(root->right);

    delete root;
}


// PRINT TREE


char* left_trace;
char* right_trace;

void print_BST(TreeNode* root,
               int depth = 0,
               char prefix = '-') {

    if (!root)
        return;

    // lewe poddrzewo
    if (root->left) {

        print_BST(root->left,
                  depth + 1,
                  '/');
    }

    // trace
    if (prefix == '/')
        left_trace[depth - 1] = '|';

    if (prefix == '\\')
        right_trace[depth - 1] = ' ';

    // początek
    if (depth == 0)
        printf("-");

    if (depth > 0)
        printf(" ");

    // pionowe kreski
    for (int i = 0;
         i < depth - 1;
         i++) {

        if (left_trace[i] == '|' ||
            right_trace[i] == '|') {

            printf("| ");

        } else {

            printf("  ");
        }
    }

    // prefix
    if (depth > 0)
        printf("%c-", prefix);

    // node
    printf("[%d]\n",
           root->val);

    left_trace[depth] = ' ';

    // prawe poddrzewo
    if (root->right) {

        right_trace[depth] = '|';

        print_BST(root->right,
                  depth + 1,
                  '\\');
    }
}


// MAIN


int main() {

    vector<int> arr(30);

    iota(arr.begin(),arr.end(),1);

    left_trace = new char[100];
    right_trace = new char[100];

    for (int i = 0; i < 100; i++) {

        left_trace[i] = ' ';
        right_trace[i] = ' ';
    }


    // TEST 1


    cout << "\n========== TEST 1 ==========\n";

    TreeNode* root = nullptr;

    // insert rosnaco
    for (int i = 0; i < 30; i++) {

        cout << "\nINSERT["
             << arr[i]
             << "]\n";

        root = insert(root, arr[i]);

        print_BST(root);

        cout << "HEIGHT = "
             << height(root)
             << "\n";
    }

    random_device rd;
    mt19937 gen(rd());

    // delete losowo
    shuffle(arr.begin(), arr.end(), gen);

    for (int i = 0; i < 30; i++) {

        cout << "\nDELETE["
             << arr[i]
             << "]\n";

        root = remove(root, arr[i]);

        print_BST(root);

        cout << "HEIGHT = "
             << height(root)
             << "\n";
    }

    free_subtree(root);

    root = nullptr;

    // TEST 2

    cout << "\n========== TEST 2 ==========\n";

    iota(arr.begin(),arr.end(),1);

    shuffle(arr.begin(),arr.end(),gen);

    // insert losowo
    for (int i = 0; i < 30; i++) {

        cout << "\nINSERT["
             << arr[i]
             << "]\n";

        root = insert(root, arr[i]);

        print_BST(root);

        cout << "HEIGHT = "
             << height(root)
             << "\n";
    }

    // delete losowo
    shuffle(arr.begin(), arr.end(), gen);

    for (int i = 0; i < 30; i++) {

        cout << "\nDELETE["
             << arr[i]
             << "]\n";

        root = remove(root, arr[i]);

        print_BST(root);

        cout << "HEIGHT = "
             << height(root)
             << "\n";
    }

    free_subtree(root);

    delete[] left_trace;
    delete[] right_trace;

    return 0;
}