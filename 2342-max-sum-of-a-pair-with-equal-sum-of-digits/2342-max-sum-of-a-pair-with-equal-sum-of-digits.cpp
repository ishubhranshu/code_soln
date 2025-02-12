// brute
class Solution {
public:
    int dSum(int num)
    {
        int sum=0;
        while(num)
        {
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        unordered_map<int, priority_queue<int>> ump;

        for(int i=0; i<n; i++)
        {
            // cout<<nums[i]<<" "<<dSum(nums[i])<<endl;
            ump[dSum(nums[i])].push(nums[i]);
        }


        for(auto i: ump)
        {
            if(i.second.size()<2)
                continue;
            
            int num1=i.second.top();
            i.second.pop();
            int num2=i.second.top();
            i.second.pop();
            
            ans=max(ans, num1+num2);
        }

        return ans;
    }
};