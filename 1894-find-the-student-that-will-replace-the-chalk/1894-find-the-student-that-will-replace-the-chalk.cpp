class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(auto i: chalk)
            sum+=i;

        k%=sum;
        // cout<<sum<<endl;
        for(int i=0; i<chalk.size(); i++)
        {
            
            // cout<<k<<endl;
            if(k<chalk[i])
                return i;
            k-=chalk[i];
        }

        return -1;
    }
};