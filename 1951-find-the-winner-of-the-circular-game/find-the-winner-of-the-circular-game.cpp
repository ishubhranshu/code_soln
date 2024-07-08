class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i=0; i<n; i++)
            arr.push_back(i+1);

        int i=0;
        while(arr.size()>1)
        {
            int ind = (i+k-1)%arr.size();
            arr.erase(arr.begin()+ind);
            i=ind;
        }

        return arr[0];
    }
};