class Solution {
  public:
    // Function to find the nodes that are common in both BST.
    vector<int> findCommon(Node *root1, Node *root2) {
        // Your code here
         vector<int>ans;
         stack<Node*>s1,s2;
         while(root1)// all the left side push into stacj
         {
             s1.push(root1);
             root1=root1->left;
         }
        
        
         while(root2)// all the right side push into stack
         {
             s2.push(root2);
             root2=root2->left;
         }
        
        while(!s1.empty() && !s2.empty())
        {
            //top element equal
            if(s1.top()->data==s2.top()->data)
            {
                ans.push_back(s1.top()->data);
                root1=s1.top()->right;
                s1.pop();
                
                 root2=s2.top()->right;
                s2.pop();
            }
            //s1>s2
            else if(s1.top()->data>s2.top()->data)
            {
                root2=s2.top()->right;
                s2.pop();
            }
            //s2>s1
            else 
            {
                root1=s1.top()->right;
                s1.pop();
            }
            
             while(root1)// all the left side push into stacj
         {
             s1.push(root1);
             root1=root1->left;
         }
        
        
         while(root2)// all the right side push into stack
         {
             s2.push(root2);
             root2=root2->left;
         }
            
            
            
        }
        
        return ans;
        
    }
};






























// Step-by-Step Logic (Ultra Short)
// 1️⃣ Initialize

// 2 stacks: s1, s2

// 2 pointers: root1, root2

// 2️⃣ Left push karo

// Dono trees ke leftmost nodes stack me push karo

// while(root1) push in s1
// while(root2) push in s2
// 3️⃣ Compare top elements
// if equal → answer me daal do
//             dono pop karo
//             dono ka right subtree process karo

// if s1.top < s2.top → s1 pop karo
//                      root1 = right

// if s2.top < s1.top → s2 pop karo
//                      root2 = right
// 4️⃣ Stop Condition
// Jab koi bhi stack empty ho jaye → break
// 🎯 Memory Trick

// Socho:

// "BST ka inorder sorted hota hai →
// do sorted arrays ko merge kar raha hoon"

// Bas itna yaad rakhna 🔥

// ⏱ Complexity

// Time: O(n1 + n2)

// Space: O(h1 + h2)