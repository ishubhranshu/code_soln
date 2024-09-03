class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.length();
        int sum=0;
        for(int i=0; i<n; i++)
        {
            int num=s[i]-'a'+1;
            
            while(num)
            {
                sum+=num%10;
                num/=10;
            }
        }

        while(--k && sum>9)
        {
            int temp=0;
            while(sum)
            {
                temp+=sum%10;
                sum/=10;
            }
            sum=temp;
        }
        return sum;
    }
};