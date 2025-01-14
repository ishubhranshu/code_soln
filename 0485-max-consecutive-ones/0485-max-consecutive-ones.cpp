class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left=0, right=0;
        int ans=0;
        while(right<nums.size())
        {
            while(right<nums.size() && nums[right])
                right++;

            // cout<<left<<" "<<right<<endl;
            ans=max(ans, right-left);
            right++;
            left=right;
        }

        return ans;
    }
};