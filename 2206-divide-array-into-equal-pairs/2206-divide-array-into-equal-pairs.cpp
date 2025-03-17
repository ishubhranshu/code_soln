class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int odds=0;
        unordered_map<int, int> freq;
        for(auto num: nums)
        {
            freq[num]++;
            if(freq[num]%2)
                odds++;
            else
                odds--;
        }

        return odds==0;
    }
};