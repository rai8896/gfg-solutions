class Solution {
  public:
  
    bool check(Node* root, long long minVal, long long maxVal) {
        
        if(root == NULL)
            return true;
            
        // violation condition
        if(root->data <= minVal || root->data >= maxVal)
            return false;
            
        return check(root->left, minVal, root->data) &&
               check(root->right, root->data, maxVal);
    }
  
    bool isBST(Node* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};