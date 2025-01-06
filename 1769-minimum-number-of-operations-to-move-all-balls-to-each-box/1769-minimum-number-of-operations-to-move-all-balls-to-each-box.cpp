class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        int prefix=0, prefixS=0;
        vector<int> ans(n, 0);

        for(int i=0; i<n; i++)
        {
            ans[i]+=prefixS;
            if(boxes[i]=='1')
                prefix++;
            prefixS+=prefix;
        }
        prefix=0; prefixS=0;
        for(int i=n-1; i>=0; i--)
        {
            ans[i]+=prefixS;
            if(boxes[i]=='1')
                prefix++;
            prefixS+=prefix;
        }

        return ans;
        
    }
};