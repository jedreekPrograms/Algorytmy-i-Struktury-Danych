#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

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

int height(TreeNode* root) {
    return (root ? root->high : 0);
}

TreeNode* insert(TreeNode* root, int value) {

    // puste miejsce -> tworzymy node
    if (!root) {
        return new TreeNode(value);
    }

    // BST
    if (value < root->key) {

        root->left = insert(root->left, value);

    } else {

        root->right = insert(root->right, value);
    }

    // aktualizacja wysokości
    root->high =
        max(height(root->left), height(root->right)) + 1;

    return root;
}

TreeNode* findNext(TreeNode* root) {

    while (root->left) {
        root = root->left;
    }

    return root;
}

TreeNode* deleteNode(TreeNode* root, int value) {

    if (!root) {
        return nullptr;
    }

    // szukamy node'a
    if (value < root->key) {

        root->left = deleteNode(root->left, value);

    } else if (value > root->key) {

        root->right = deleteNode(root->right, value);

    } else {

        // CASE 1: liść
        if (!root->left && !root->right) {

            delete root;
            return nullptr;
        }

        // CASE 2: jedno dziecko
        if (!root->left) {

            TreeNode* temp = root->right;

            delete root;

            return temp;
        }

        if (!root->right) {

            TreeNode* temp = root->left;

            delete root;

            return temp;
        }

        // CASE 3: dwoje dzieci

        // bierzemy następnika inorder
        TreeNode* succ = findNext(root->right);

        // kopiujemy wartość
        root->key = succ->key;

        // usuwamy następnika
        root->right =
            deleteNode(root->right, succ->key);
    }

    // aktualizacja wysokości
    root->high =
        max(height(root->left), height(root->right)) + 1;

    return root;
}

void free_subtree(TreeNode* root) {

    if (!root) return;

    free_subtree(root->left);
    free_subtree(root->right);

    delete root;
}

char* left_trace;
char* right_trace;

void print_BST(TreeNode* root,
               int depth = 0,
               char prefix = '-') {

    if (root == nullptr)
        return;

    // lewe poddrzewo
    if (root->left != nullptr) {

        print_BST(root->left,
                  depth + 1,
                  '/');
    }

    // ustawianie trace
    if (prefix == '/')
        left_trace[depth - 1] = '|';

    if (prefix == '\\')
        right_trace[depth - 1] = ' ';

    // początek linii
    if (depth == 0)
        printf("-");

    if (depth > 0)
        printf(" ");

    // pionowe kreski
    for (int i = 0; i < depth - 1; i++) {

        if (left_trace[i] == '|' ||
            right_trace[i] == '|') {

            printf("| ");

        } else {

            printf("  ");
        }
    }

    // prefix node'a
    if (depth > 0)
        printf("%c-", prefix);

    // wartość
    printf("[%d]\n", root->key);

    // czyszczenie trace
    left_trace[depth] = ' ';

    // prawe poddrzewo
    if (root->right != nullptr) {

        right_trace[depth] = '|';

        print_BST(root->right,
                  depth + 1,
                  '\\');
    }
}

int main() {

    vector<int> arr;

    left_trace = new char[100];
    right_trace = new char[100];

    for (int i = 0; i < 100; i++) {

        left_trace[i] = ' ';
        right_trace[i] = ' ';
    }

    // =========================================
    // TEST 1
    // insert 1..30
    // delete losowa permutacja
    // =========================================

    for (int i = 1; i <= 30; i++) {
        arr.push_back(i);
    }

    TreeNode* root = nullptr;

    cout << "\n========== TEST 1 ==========\n";

    // insert rosnąco
    for (int i = 0; i < arr.size(); i++) {

        cout << "\nINSERT[" << arr[i] << "]\n";

        root = insert(root, arr[i]);

        print_BST(root);

        cout << "HEIGHT = "
             << height(root)
             << "\n";
    }

    // losowe delete
    random_device rd;
    mt19937 gen(rd());

    shuffle(arr.begin(), arr.end(), gen);

    for (int i = 0; i < arr.size(); i++) {

        cout << "\nDELETE[" << arr[i] << "]\n";

        root = deleteNode(root, arr[i]);

        print_BST(root);

        cout << "HEIGHT = "
             << height(root)
             << "\n";
    }

    // =========================================
    // TEST 2
    // insert losowa permutacja
    // delete losowa permutacja
    // =========================================

    shuffle(arr.begin(), arr.end(), gen);

    root = nullptr;

    cout << "\n========== TEST 2 ==========\n";

    // insert losowo
    for (int i = 0; i < arr.size(); i++) {

        cout << "\nINSERT[" << arr[i] << "]\n";

        root = insert(root, arr[i]);

        print_BST(root);

        cout << "HEIGHT = "
             << height(root)
             << "\n";
    }

    // delete losowo
    shuffle(arr.begin(), arr.end(), gen);

    for (int i = 0; i < arr.size(); i++) {

        cout << "\nDELETE[" << arr[i] << "]\n";

        root = deleteNode(root, arr[i]);

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