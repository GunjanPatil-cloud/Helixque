class Solution {
public:
    int kthSmallest(Node* root, int k) {
        Node* curr = root;
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                if (k == 1) return curr->data;
                k--;
                curr = curr->right;
            } else {
                Node* prev = curr->left;
                while (prev->right != nullptr && prev->right != curr)
                    prev = prev->right;

                if (prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    if (k == 1) return curr->data;
                    k--;
                    curr = curr->right;
                }
            }
        }
        return -1;
    }
};

