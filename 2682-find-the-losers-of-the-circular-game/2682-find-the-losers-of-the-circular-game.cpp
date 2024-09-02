class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> vis(n, 0);
        int mul=0;
        int indx=0;
        while(1)
        {
            indx=(indx + mul*k)%n;
            if(vis[indx])
                break;
            vis[indx]++;
            mul++;
            
            // for(auto i: vis)
            //     cout<<i<<" ";
            // cout<<endl;
        }

        vector<int> ans;
        for(int i=0; i<n; i++)
            if(vis[i]==0)
                ans.push_back(i+1);

        return ans;

    }
};