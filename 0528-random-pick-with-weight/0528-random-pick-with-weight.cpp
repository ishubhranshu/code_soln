class Solution {
public:
    vector<int> arr;

    Solution(vector<int>& w) {
        int n=w.size();
        arr.resize(n);

        int minEle=*min_element(w.begin(), w.end());

        for(int i=0; i<n; i++)
        {
            arr[i]=minEle*w[i];
            if(i!=0)
                arr[i]+=arr[i-1];
        }

        for(int i=0; i<n; i++)
            cout<<arr[i]<<" ";
    }
    
    int pickIndex() {
        
        return lower_bound(arr.begin(), arr.end(), 1+rand()%(arr.back()))-arr.begin();

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */