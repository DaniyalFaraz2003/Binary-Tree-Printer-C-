#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class PrintTree {
    private:
        void placeNodes(TreeNode* root, vector<vector<string>>& tree, int r, int c, int height) {
            if (root == nullptr) return;

            tree[r][c] = to_string(root->val);
            placeNodes(root->left, tree, r + 1, c - int(pow(2, height - r - 1)), height);
            placeNodes(root->right, tree, r + 1, c + int(pow(2, height - r - 1)), height);
        }
        int getHeight(TreeNode* root) {
            if (root == nullptr)
                return 0;
            return max(getHeight(root->right) + 1, getHeight(root->left) + 1);
        }

    public:
        PrintTree() {}
        void printTree(TreeNode* root) {
            int height = getHeight(root);
            int cols = int(pow(2, height) - 1);
            vector<vector<string>> tree(height, vector<string>(cols, ""));

            placeNodes(root, tree, 0, (cols - 1) / 2, height - 1);
            for (auto i : tree) {
                for (string j : i) {
                    if (j == "") cout << ' ';
                    else cout << j;
                }
                cout << endl;
            }
        }
};


TreeNode* insertNode(TreeNode* root, int x) {
    if (root == nullptr) {
        root = new TreeNode(x);
    }
    else {
        if (x > root -> val) {
            root -> right = insertNode(root -> right, x);
        }
        else {
            root -> left = insertNode(root -> left, x);
        }
    }
    return root;
}


int main() {
    TreeNode* root = new TreeNode(45);
    root = insertNode(root, 3);
    root = insertNode(root, 67);
    root = insertNode(root, 5);
    root = insertNode(root, 2);
    root = insertNode(root, 8);
    root = insertNode(root, 4);
    
    PrintTree outHandle;
    outHandle.printTree(root);
    return 0;
}