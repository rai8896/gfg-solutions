// class Solution {
//   public:
//     bool twoSum(vector<int>& arr, int target) {
//         // code here
        
//         unordered_map<int,int>mp;
//         for(int i=0;i<arr.size();i++)
//         {
//             int need=target-arr[i];
//             if(mp.find(need)!=mp.end())
//             {
//                 retrun true;
//             }
//             mp[a[[i]]]=i;
            
//         }
//         return false;
//     }


class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        
        unordered_map<int,int> mp;

        for(int i = 0; i < arr.size(); i++)
        {
            int need = target - arr[i];

            // agar need pehle se map me hai
            if(mp.find(need) != mp.end())
            {
                return true;
            }

            // current element store karo
            mp[arr[i]] = i;
        }

        return false;
    }
};