class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> odd, even;
        int temp=num;
        while(temp)
        {
            int i=temp%10;
            temp/=10;
            if(i%2)
                odd.push(i);
            else
                even.push(i);
        }

        int ans=0;
        int ind=0;
        while(odd.size() && even.size())
        {
            if(to_string(num)[ind]=='1' || to_string(num)[ind]=='3' ||to_string(num)[ind]=='5' || to_string(num)[ind]=='7' || to_string(num)[ind]=='9')
            {
                ans=ans*10+odd.top();
                odd.pop();
            }
            else
            {
                ans=ans*10+even.top();
                even.pop();
            }
            ind++;
        }
        while(odd.size())
        {
            ans=ans*10+odd.top();
            odd.pop();
        }
        while(even.size())
        {
            ans=ans*10+even.top();
            even.pop();
        }

        return ans;
    }
};