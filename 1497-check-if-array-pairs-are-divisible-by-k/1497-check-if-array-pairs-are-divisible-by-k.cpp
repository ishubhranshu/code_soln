class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> rem(k,0);

        for(auto i: arr)
            rem[(i%k+k)%k]++;
        // for(int i=0; i<k; i++)
        //     cout<<i<<" "<<rem[i]<<endl;
        if(rem[0]%2!=0)
            return 0;

        for(int i=1; i<=k/2; i++)
        {
            cout<<i<<" "<<rem[i]<<" "<<rem[k-i]<<endl;
            if(rem[i] != rem[k-i])
                return 0;
        }

        return 1;
    }
};