class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n=arr.size();
        for(int i=0; i<n; i++)
        {
            int flag=1;
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    continue;
                if(arr[i]==arr[j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                k--;
            if(!k)
                return arr[i];
        }
        
        return "";
    }
};