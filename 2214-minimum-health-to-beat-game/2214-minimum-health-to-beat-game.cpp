class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int maxDamage=0;
        int totalDamage=0;
        for(auto dam: damage)
        {
            maxDamage=max(maxDamage, dam);
            totalDamage+=dam;
        }

        return totalDamage-min(maxDamage, armor)+1;

    }
};