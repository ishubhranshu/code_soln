//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        
        if(s>9*d)
        {
            return "-1";
        }
        
        string ans(d, '0');
        
        if(s < 1)
        {
            ans[0]='1';
            return ans;
        }
        
        int ind=d-1;
        while(ind>=0)
        {
            if(s>9)
            {
                ans[ind]='9';
                ind--;
                s-=9;
            }
            else
            {
                if(ind==0)
                    ans[0]=char('0'+s);
                else
                {
                    s=s-1;
                    ans[0]='1';
                    ans[ind--]='0'+s;;
                }
                break;
            }
        }
        
            
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends