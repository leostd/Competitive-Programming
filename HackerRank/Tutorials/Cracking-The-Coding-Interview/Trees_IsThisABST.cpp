/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
    
    vector<int> chk;
    void checkBSTUtil(Node* root)
    {
        if (root != NULL)
        {
            checkBSTUtil(root->left);
            chk.push_back(root->data);
            checkBSTUtil(root->right);
        }
    }
    bool checkBST(Node* root) {
        bool sorted = true;
        checkBSTUtil(root);
        for (int i = 1; i < chk.size(); i++)
        {
            if (chk[i-1] >= chk[i])
                sorted = false;
        }
        return sorted;
    }
