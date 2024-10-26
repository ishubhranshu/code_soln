class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n=people.size();
        int left=0,right=n-1;
        int boats=0;
        // while(left<=right && limit<=people[right])
        // {
        //     boats++;
        //     right--;
        // }
        // cout<<left<<" "<<right;
        while(left<right)
        {
            boats++;
            if(people[left]+people[right]<=limit)
            {
                left++;right--;
            }
            else
            {
                right--;
            }
        }
        boats+=right-left+1;

        return boats;
    }
};