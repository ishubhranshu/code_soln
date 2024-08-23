class Solution {
public:
    int hcf(int a, int b)
    {
        if(b==0)    return a;
        return hcf(b, a%b);
    }
    int lcm(int a, int b)
    {
        return a*b/hcf(a, b);
    }
    string fractionAddition(string exp) {
        int n=exp.size();
        int den=1, num=0;
        for(int i=1; i<n; i++)
        {
            if(exp[i]=='/')
                den=lcm(den, exp[i+1]-'0');
        }
        
        for(int i=1; i<n; i++)
        {
            if(exp[i]=='/')
            {
                int cnum=exp[i-1]-'0';
                int sign=1;
                int fact=den/(exp[i+1]-'0');
                if(i-2>=0 && exp[i-2]=='-')
                    sign=-1;
                num+=cnum*sign*fact;
            }    
        }
        int fhcf=hcf(den, abs(num));
        cout<<num<<" "<<den<<" "<<fhcf<<endl;
        den/=fhcf;
        num/=fhcf;
        string ans="";
        ans+=to_string(num)+"/"+to_string(den);
        return ans;
    }
};