class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap;
    
    // Count the frequency of each number
    for (int num : nums) {
        freqMap[num]++;
    }

    // Custom comparator for sorting
    auto comparator = [&freqMap](int a, int b) {
        if (freqMap[a] == freqMap[b]) {
            return a > b; // Sort by value in decreasing order if frequencies are equal
        }
        return freqMap[a] < freqMap[b]; // Otherwise sort by frequency in increasing order
    };

    sort(nums.begin(), nums.end(), comparator);

    return nums;
    }
};