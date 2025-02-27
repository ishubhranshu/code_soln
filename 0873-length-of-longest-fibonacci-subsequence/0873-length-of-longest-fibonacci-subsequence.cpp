class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        unordered_set<int> st(arr.begin(), arr.end());
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int first=arr[i];
                int second=arr[j];
                int third=first+second;
                int len=0;
                while(st.find(third) != st.end())
                {
                    len++;
                    first=second;
                    second=third;
                    third=first+second;
                }
                ans=max(ans, len);
            }
        }
        return ans==0 ? 0: ans+2;
    }
};