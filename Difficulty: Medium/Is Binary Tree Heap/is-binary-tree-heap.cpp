/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  int count(Node* root)
  {
      if(!root)
      {
          return 0;
      }else
      {
          return 1+count(root->left)+count(root->right);
      }
  }
      
      bool CBT(Node* root,int index,int total_nodes)
      {
          if(!root)
          {
              return 1;
          }
          if(index>=total_nodes)
          {
              return 0;
          }
          //left side
          return CBT(root->left,2*index+1,total_nodes)&& CBT(root->right,2*index+2,total_nodes);
          //right side
      }
          
      
  
      bool MaxHeap(Node* root)
      {
          //root null
          //left child exist only
          //right child exist only
          //both exist
          
          //one node existed question me diya hua hai
          if(root->left)
          {
              if(root->data<root->left->data)
              {
                  return 0;
              }
             if(!MaxHeap(root->left)) return 0;
          }
          //one node existed question me diya hua hai
          if(root->right)
          {
              if(root->data<root->right->data)
              {
                  return 0;
              }
             return MaxHeap(root->right);
          }
          return 1;
          
      }
      
  
    bool isHeap(Node* tree)
    {
        // code here
        
        //count the node
        int num=count(tree);
        //CBT
        bool ans=CBT(tree,0,num);
        if(ans==0)return 0;
        
        //every parent>=child
        return MaxHeap(tree);
        
    }
};