class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int tocount=0;
        for(auto i: nums)
            if(i)
            {
                tocount++;
                // cout<<nums[i]<<" "<<tocount<<endl;
            }

        int zinwin=0;

        for(int i=0; i<tocount; i++)
            if(!nums[i])
                zinwin++;

        nums.insert(nums.end(), nums.begin(), nums.end());


        int left=0, right=tocount, ans=zinwin;
        // cout<<tocount<<endl<<endl;
        // cout<<left<<" "<<right<<" "<<zinwin<<endl;
        while(right<nums.size())
        {
            if(!nums[left])
                zinwin--;
            if(!nums[right])
                zinwin++;
            right++;
            left++;
            // cout<<left<<" "<<right<<" "<<zinwin<<endl;
            ans=min(ans, zinwin);
        }
        return ans;
    }
};