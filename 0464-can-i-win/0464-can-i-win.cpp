class Solution {
public:
    unordered_map<int, bool> memo;

    bool canIWinHelper(int maxChoosableInteger, int desiredTotal, int usedNumbers, int currentTotal) {
        if (memo.count(usedNumbers)) return memo[usedNumbers];
        
        for (int i = 1; i <= maxChoosableInteger; ++i) {
            int currentBit = (1 << i);
            if ((usedNumbers & currentBit) == 0) {
                if (currentTotal + i >= desiredTotal || 
                    !canIWinHelper(maxChoosableInteger, desiredTotal, usedNumbers | currentBit, currentTotal + i)) {
                    return memo[usedNumbers] = true;
                }
            }
        }
        return memo[usedNumbers] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (sum < desiredTotal) return false;

        return canIWinHelper(maxChoosableInteger, desiredTotal, 0, 0);
    }
};
