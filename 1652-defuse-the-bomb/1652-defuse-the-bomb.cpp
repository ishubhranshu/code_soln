class Solution {
public:
    
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();

        if(k==0)
        {
            for(int i=0; i<n; i++)
                code[i]=0;
            return code;
        }

        vector<int> ans(n);
        if(k>0)
        {
            int left=1, right=1, sum=0;
            for(int i=0; i<k; i++)
            {
                sum+=code[right];
                right=(right+1)%n;
            }

            for(int i=0; i<n; i++)
            {
                ans[((left%n)-1+n)%n]=sum;

                sum-=code[left];
                left=(left+1)%n;

                sum+=code[right];
                right=(right+1)%n;
            }

            return ans;
        }

        int left=n-2, right=n-2, sum=0;
        k=abs(k);
        for(int i=0; i<k; i++)
        {
            sum+=code[left];
            left=((left-1)%n+n)%n;
            // cout<<left<<" "<<sum<<endl;
        }
        left=left+1;
        for(int i=0; i<n; i++)
        {
            // cout<<left<<" "<<right<<" "<<sum<<endl;
            ans[(right+1)%n]=sum;

            sum-=code[right];
            right=((right-1)%n+n)%n;
            // cout<<left<<" "<<right<<" "<<sum<<endl;
            
            left=((left-1)%n+n)%n;
            sum+=code[left];
            // cout<<left<<" "<<right<<" "<<sum<<endl;
            // cout<<endl;
            
        }
        return ans;
    }
};