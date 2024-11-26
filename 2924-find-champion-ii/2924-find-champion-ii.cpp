class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        if(n==1)
            if(edges.size()==0)
                return 0;
            else
                return -1;
        vector<int> in(n);
        vector<int> out(n);

        for(auto &e: edges)
        {
            out[e[0]]++;
            in[e[1]]++;
        }
        int ans=-1;

        for(int i=0; i<n; i++)
        {
            if(in[i]==0)
            {
                if(ans==-1)
                    ans=i;
                else
                    return -1;
            }
        }

        // for(int i=0; i<n; i++)
            // cout<<inout[i]<<" ";
        return ans; 
    }
};