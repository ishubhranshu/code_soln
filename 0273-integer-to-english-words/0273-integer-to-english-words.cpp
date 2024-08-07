class Solution {
public:
    string teen(int num)
    {
        switch(num)
        {
            case 10: return "Ten"; break;
            case 11: return "Eleven"; break;
            case 12: return "Twelve"; break;
            case 13: return "Thirteen"; break;
            case 14: return "Fourteen"; break;
            case 15: return "Fifteen"; break;
            case 16: return "Sixteen"; break;
            case 17: return "Seventeen"; break;
            case 18: return "Eighteen"; break;
            case 19: return "Nineteen"; break;
        }

        return "";
    }
    string tenns(int num)
    {
        switch(num)
        {
            case 1: return "Ten"; break;
            case 2: return "Twenty"; break;
            case 3: return "Thirty"; break;
            case 4: return "Forty"; break;
            case 5: return "Fifty"; break;
            case 6: return "Sixty"; break;
            case 7: return "Seventy"; break;
            case 8: return "Eighty"; break;
            case 9: return "Ninety"; break;
        }

        return "";
    }
    string one(int num)
    {
        switch(num)
        {
            case 1: return "One"; break;
            case 2: return "Two"; break;
            case 3: return "Three"; break;
            case 4: return "Four"; break;
            case 5: return "Five"; break;
            case 6: return "Six" ; break;
            case 7: return "Seven"; break;
            case 8: return "Eight"; break;
            case 9: return "Nine"; break;
        }

        return "";
    }
    string two(int num)
    {

        if(num==0) return "";
        if(num<10) return one(num);
        if(num<20) return teen(num);

        int tens=num/10;
        int rem=num%10;
        if(tens && rem)
            return tenns(tens)+ " " +one(rem);
        if(tens)
            return tenns(tens);
        return one(rem);
    }
    string three(int num)
    {
        if(num==0)  return "";

        int hundred = num/100;
        int rest = num%100;

        cout<<rest<<endl;
        if(hundred && rest)
            return one(hundred) + " " + "Hundred " + two(rest);
        else if(rest)
            return two(rest);
        
        return one(hundred) + " " + "Hundred";
    }   
    string numberToWords(int num) {
        if(num==0)
            return "Zero";

        int billion=num/1000000000;
        num=num%1000000000;
        int million=num/1000000;
        num=num%1000000;
        int thousand=num/1000;
        num=num%1000;
        
        string ans="";

        if(billion)
        {
            ans+=three(billion) + " ";
            ans+= (million|thousand|num)?"Billion ":"Billion";
        }
        if(million)
        {
            ans+=three(million) + " ";
            ans+= (thousand|num)?"Million ":"Million";
        }
        if(thousand)
        {
            ans+=three(thousand) + " ";
            ans+= (num)?"Thousand ":"Thousand";
        }
        // cout<<num<<endl;
        if(num) ans+=three(num);
    
        return ans;
    }
};