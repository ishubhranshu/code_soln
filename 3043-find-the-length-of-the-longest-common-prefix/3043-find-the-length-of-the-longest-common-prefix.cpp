class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st1;
        for(auto num: arr1)
        {
            while(num)
            {
                st1.insert(num);
                num/=10;
            }
        }
        unordered_set<int> st2;
        for(auto num: arr2)
        {
            while(num)
            {
                st2.insert(num);
                num/=10;
            }
        }
        int ans=0;
        for(auto i: st1)
        {
            if(st2.find(i)!=st2.end())
            {
                int len=0;
                while(i)
                {
                    len++;
                    i=i/10;
                }
                ans=max(ans, len);
            }
        }
        return ans;
    }
};