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
};

struct Result {

    long long sum_cmp = 0;
    long long max_cmp = 0;

    long long sum_read = 0;
    long long max_read = 0;

    long long sum_assign = 0;
    long long max_assign = 0;

    long long sum_height = 0;
    long long max_height = 0;

    long long operations = 0;
};

struct TreeNode {

    TreeNode* left;
    TreeNode* right;

    int key;
    int high;

    TreeNode(int key)
        : left(nullptr),
          right(nullptr),
          key(key),
          high(1) {}
};

// HEIGHT

int height(TreeNode* root) {

    return root ? root->high : 0;
}

void updateHeight(TreeNode* root, Stats& s) {

    if (!root)
        return;

    // odczyty left/right
    s.pointer_reads += 2;

    root->high = max(height(root->left),height(root->right)) + 1;
}


// UPDATE RESULT


void updateResult(Result& r, Stats& s, int h) {

    r.sum_cmp += s.comparisons;
    r.max_cmp = max(r.max_cmp,s.comparisons);

    r.sum_read += s.pointer_reads;
    r.max_read = max(r.max_read,s.pointer_reads);

    r.sum_assign += s.pointer_assigns;
    r.max_assign = max(r.max_assign,s.pointer_assigns);

    r.sum_height += h;
    r.max_height = max(r.max_height,(long long)h);

    r.operations++;
}


// INSERT


TreeNode* insert(TreeNode* root, int value, Stats& s) {

    // odczyt root
    s.pointer_reads++;

    if (!root) {

        s.pointer_assigns++;

        return new TreeNode(value);
    }

    // porownanie value < key
    s.comparisons++;

    if (value < root->key) {

        // odczyt root->left
        s.pointer_reads++;

        root->left = insert(root->left, value, s);

        // przypisanie root->left
        s.pointer_assigns++;
    }

    else {

        // odczyt root->right
        s.pointer_reads++;

        root->right = insert(root->right,value,s);

        // przypisanie root->right
        s.pointer_assigns++;
    }

    updateHeight(root, s);

    return root;
}


// FIND NEXT


TreeNode* findNext(TreeNode* root, Stats& s) {

    // odczyt root
    s.pointer_reads++;

    while (root->left) {

        // sprawdzenie root->left
        s.pointer_reads++;

        // root = root->left
        s.pointer_reads++;
        s.pointer_assigns++;

        root = root->left;
    }

    return root;
}


// DELETE


TreeNode* deleteNode(TreeNode* root, int value, Stats& s) {

    // odczyt root
    s.pointer_reads++;

    if (!root) return nullptr;

    // value < root->key
    s.comparisons++;

    if (value < root->key) {

        // odczyt root->left
        s.pointer_reads++;

        root->left = deleteNode(root->left, value, s);

        // przypisanie root->left
        s.pointer_assigns++;
    }

    else {

        // value > root->key
        s.comparisons++;

        if (value > root->key) {

            // odczyt root->right
            s.pointer_reads++;

            root->right = deleteNode(root->right, value, s);

            // przypisanie root->right
            s.pointer_assigns++;
        }

        else {


            // LISC


            // odczyty left/right
            s.pointer_reads += 2;

            if (!root->left &&
                !root->right) {

                delete root;

                return nullptr;
            }

            // =================================
            // JEDNO DZIECKO
            // =================================

            // odczyt root->left
            s.pointer_reads++;

            if (!root->left) {

                // odczyt root->right
                s.pointer_reads++;

                TreeNode* temp = root->right;

                // temp = ...
                s.pointer_assigns++;

                delete root;

                return temp;
            }

            // odczyt root->right
            s.pointer_reads++;

            if (!root->right) {

                // odczyt root->left
                s.pointer_reads++;

                TreeNode* temp =
                    root->left;

                // temp = ...
                s.pointer_assigns++;

                delete root;

                return temp;
            }

            // =================================
            // DWOJE DZIECI
            // =================================

            // odczyt root->right
            s.pointer_reads++;

            TreeNode* succ = findNext(root->right,s);

            // succ = ...
            s.pointer_assigns++;

            root->key = succ->key;

            // odczyt root->right
            s.pointer_reads++;

            root->right = deleteNode(root->right,succ->key,s);

            // przypisanie root->right
            s.pointer_assigns++;
        }
    }

    updateHeight(root, s);

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
        "avg_height,max_height\n";

    for (int n = 10000; n <= 100000; n += 10000) {

        cout << "N = " << n << endl;

        Result sorted_insert;
        Result sorted_delete;

        Result random_insert;
        Result random_delete;

        for (int test = 0; test < 20; test++) {

            vector<int> arr(n);

            iota(arr.begin(), arr.end(), 1);


            // SORTED INSERT


            TreeNode* root = nullptr;

            for (int x : arr) {

                Stats s;

                root = insert(root, x, s);

                updateResult(sorted_insert,s,height(root));
            }


            // SORTED DELETE


            shuffle(arr.begin(),arr.end(),gen);

            for (int x : arr) {

                Stats s;

                root = deleteNode(root, x,s);

                updateResult(sorted_delete,s,height(root));
            }

            free_subtree(root);


            // RANDOM INSERT


            iota(arr.begin(),arr.end(),1);

            shuffle(arr.begin(),arr.end(),gen);

            root = nullptr;

            for (int x : arr) {

                Stats s;

                root = insert(root,x,s);

                updateResult(random_insert,s,height(root));
            }


            // RANDOM DELETE
        

            shuffle(arr.begin(),arr.end(),gen);

            for (int x : arr) {

                Stats s;

                root = deleteNode(root,x,s);

                updateResult(random_delete,s,height(root));
            }

            free_subtree(root);
        }

        auto saveResult =
            [&](string scenario,string operation,Result& r) {

            out
                << scenario << ","
                << operation << ","
                << n << ","

                << (double)r.sum_cmp / r.operations
                << ","
                << r.max_cmp << ","

                << (double)r.sum_read / r.operations
                << ","
                << r.max_read << ","

                << (double)r.sum_assign / r.operations
                << ","
                << r.max_assign << ","

                << (double)r.sum_height / r.operations
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
    }

    out.close();

    cout << "DONE\n";

    return 0;
}