
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

struct Stats {

    long long comparisons = 0;

    long long pointer_reads = 0;

    long long pointer_assigns = 0;

    long long rotations = 0;
};

struct Result {

    long long sum_cmp = 0;
    long long max_cmp = 0;

    long long sum_read = 0;
    long long max_read = 0;

    long long sum_assign = 0;
    long long max_assign = 0;

    long long sum_rot = 0;
    long long max_rot = 0;

    long long sum_height = 0;
    long long max_height = 0;

    long long operations = 0;
};

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


// HEIGHT


int height(TreeNode* root) {

    return root ? root->height : 0;
}

void updateHeight(TreeNode* root) {

    if (!root) return;

    root->height = max(height(root->left), height(root->right)) + 1;
}

void fixHeight(TreeNode* root) {

    if (!root) return;

    fixHeight(root->left);
    fixHeight(root->right);

    updateHeight(root);
}

// UPDATE RESULT


void updateResult(Result& r, Stats& s, int h) {

    r.sum_cmp += s.comparisons;
    r.max_cmp = max(r.max_cmp, s.comparisons);

    r.sum_read += s.pointer_reads;
    r.max_read = max(r.max_read, s.pointer_reads);

    r.sum_assign += s.pointer_assigns;
    r.max_assign = max(r.max_assign, s.pointer_assigns);

    r.sum_rot += s.rotations;
    r.max_rot = max(r.max_rot, s.rotations);

    r.sum_height += h;
    r.max_height = max(r.max_height, (long long)h);

    r.operations++;
}


// RIGHT ROTATE


TreeNode* rightRotate(TreeNode* y, Stats& s) {

    s.rotations++;

    s.pointer_reads++;
    TreeNode* x = y->left;

    s.pointer_reads++;
    TreeNode* B = x->right;

    x->right = y;
    s.pointer_assigns++;

    y->left = B;
    s.pointer_assigns++;

    if (B) {

        B->parent = y;
        s.pointer_assigns++;
    }

    s.pointer_reads++;
    x->parent = y->parent;

    s.pointer_reads++;

    if (y->parent) {

        s.pointer_reads++;

        if (y == y->parent->left) {

            y->parent->left = x;
            s.pointer_assigns++;

        } else {

            y->parent->right = x;
            s.pointer_assigns++;
        }
    }

    y->parent = x;
    s.pointer_assigns++;

    updateHeight(y);
    updateHeight(x);

    return x;
}


// LEFT ROTATE


TreeNode* leftRotate(TreeNode* x, Stats& s) {

    s.rotations++;

    s.pointer_reads++;
    TreeNode* y = x->right;

    s.pointer_reads++;
    TreeNode* B = y->left;

    y->left = x;
    s.pointer_assigns++;

    x->right = B;
    s.pointer_assigns++;

    if (B) {

        B->parent = x;
        s.pointer_assigns++;
    }

    s.pointer_reads++;
    y->parent = x->parent;

    s.pointer_reads++;

    if (x->parent) {

        s.pointer_reads++;

        if (x == x->parent->left) {

            x->parent->left = y;
            s.pointer_assigns++;

        } else {

            x->parent->right = y;
            s.pointer_assigns++;
        }
    }

    x->parent = y;
    s.pointer_assigns++;

    updateHeight(x);
    updateHeight(y);

    return y;
}


// SPLAY


TreeNode* splay(TreeNode* x, Stats& s) {

    if (!x) return nullptr;

    while (x->parent) {

        TreeNode* y = x->parent;
        TreeNode* z = y->parent;

        // ZIG
        if (!z) {

            if (x == y->left)
                rightRotate(y, s);
            else
                leftRotate(y, s);
        }

        // ZIG-ZIG LL
        else if (
            x == y->left &&
            y == z->left) {

            rightRotate(z, s);
            rightRotate(y, s);
        }

        // ZIG-ZIG RR
        else if (
            x == y->right &&
            y == z->right) {

            leftRotate(z, s);
            leftRotate(y, s);
        }

        // ZIG-ZAG LR
        else if (
            x == y->right &&
            y == z->left) {

            leftRotate(y, s);
            rightRotate(z, s);
        }

        // ZIG-ZAG RL
        else {

            rightRotate(y, s);
            leftRotate(z, s);
        }
    }

    return x;
}

// INSERT BST

TreeNode* insertBST(TreeNode* root, int key, TreeNode*& inserted, Stats& s) {

    if (!root) {

        inserted = new TreeNode(key);

        return inserted;
    }

    s.comparisons++;

    if (key < root->val) {

        root->left = insertBST(root->left, key,inserted,s);

        root->left->parent = root;
        s.pointer_assigns++;

    } else {

        root->right = insertBST(root->right, key,inserted,s);

        root->right->parent = root;
        s.pointer_assigns++;
    }

    updateHeight(root);

    return root;
}


// INSERT


TreeNode* insert(TreeNode* root, int key, Stats& s) {

    TreeNode* inserted = nullptr;

    root = insertBST(root,key,inserted,s);

    root = splay(inserted, s);

    fixHeight(root);

    return root;
}


// FIND NEXT


TreeNode* findNext(TreeNode* root, Stats& s) {

    while (root && root->left) {

        root = root->left;

        s.pointer_reads++;
    }

    return root;
}


// REMOVE BST


TreeNode* removeBST(TreeNode* root, int key, TreeNode*& parentRemoved, Stats& s) {

    if (!root) return nullptr;

    s.comparisons++;

    if (key < root->val) {

        root->left = removeBST(root->left, key,parentRemoved,s);

        if (root->left) {

            root->left->parent = root;
            s.pointer_assigns++;
        }
    }

    else if (key > root->val) {

        root->right = removeBST(root->right, key, parentRemoved, s);

        if (root->right) {

            root->right->parent = root;
            s.pointer_assigns++;
        }
    }

    else {

        // LISC
        if (!root->left &&
            !root->right) {

            parentRemoved = root->parent;

            delete root;

            return nullptr;
        }

        // JEDNO DZIECKO
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

        // DWOJE DZIECI
        TreeNode* succ = findNext(root->right, s);

        root->val = succ->val;

        root->right = removeBST(root->right, succ->val,parentRemoved,s);

        if (root->right) {

            root->right->parent = root;
        }
    }

    updateHeight(root);

    return root;
}


// REMOVE


TreeNode* remove(TreeNode* root,int key,Stats& s) {

    TreeNode* parentRemoved =nullptr;

    root = removeBST(root,key,parentRemoved,s);

    if (parentRemoved) {

        root = splay(parentRemoved,s);
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


// MAIN


int main() {

    random_device rd;
    mt19937 gen(rd());

    ofstream out("results.csv");

    out <<
        "scenario,operation,n,"
        "avg_cmp,max_cmp,"
        "avg_read,max_read,"
        "avg_assign,max_assign,"
        "avg_rot,max_rot,"
        "avg_height,max_height\n";

    for (int n = 10000;
         n <= 100000;
         n += 10000) {

        cout << "N = "
             << n
             << endl;

        Result sorted_insert;
        Result sorted_delete;

        Result random_insert;
        Result random_delete;

        for (int test = 0;
             test < 20;
             test++) {

            vector<int> arr(n);

            iota(arr.begin(),arr.end(),1);


            // SORTED INSERT


            TreeNode* root = nullptr;

            for (int x : arr) {

                Stats s;

                root = insert(root, x, s);

                updateResult(
                    sorted_insert,
                    s,
                    height(root));
            }

            // ==================================
            // SORTED DELETE
            // ==================================

            shuffle(arr.begin(),
                    arr.end(),
                    gen);

            for (int x : arr) {

                Stats s;

                root =
                    remove(root,
                           x,
                           s);

                updateResult(
                    sorted_delete,
                    s,
                    height(root));
            }

            free_subtree(root);

            // ==================================
            // RANDOM INSERT
            // ==================================

            iota(arr.begin(),
                  arr.end(),
                  1);

            shuffle(arr.begin(),
                    arr.end(),
                    gen);

            root = nullptr;

            for (int x : arr) {

                Stats s;

                root =
                    insert(root,
                           x,
                           s);

                updateResult(
                    random_insert,
                    s,
                    height(root));
            }


            // RANDOM DELETE


            shuffle(arr.begin(),arr.end(),gen);

            for (int x : arr) {

                Stats s;

                root = remove(root, x, s);

                updateResult(random_delete,s,height(root));
            }

            free_subtree(root);
        }

        auto saveResult =
            [&](string scenario,
                string operation,
                Result& r) {

            out
                << scenario << ","
                << operation << ","
                << n << ","

                << (double)r.sum_cmp /
                       r.operations
                << ","

                << r.max_cmp
                << ","

                << (double)r.sum_read /
                       r.operations
                << ","

                << r.max_read
                << ","

                << (double)r.sum_assign /
                       r.operations
                << ","

                << r.max_assign
                << ","

                << (double)r.sum_rot /
                       r.operations
                << ","

                << r.max_rot
                << ","

                << (double)r.sum_height /
                       r.operations
                << ","

                << r.max_height

                << "\n";
        };

        saveResult(
            "sorted",
            "insert",
            sorted_insert);

        saveResult(
            "sorted",
            "delete",
            sorted_delete);

        saveResult(
            "random",
            "insert",
            random_insert);

        saveResult(
            "random",
            "delete",
            random_delete);

        out.flush();
    }

    out.close();

    cout << "DONE\n";

    return 0;
}
