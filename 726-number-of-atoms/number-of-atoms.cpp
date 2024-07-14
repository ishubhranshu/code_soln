#include <string>
class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());

        int i = 0;
        while (i < n) {
            if (formula[i] == '(') {
                st.push(unordered_map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                auto top = st.top();
                st.pop();
                i++;
                string multiplierStr;
                while (i < n && isdigit(formula[i])) {
                    multiplierStr += formula[i++];
                }
                int multiplier = multiplierStr.empty() ? 1 : stoi(multiplierStr);
                for (auto &p : top) {
                    p.second *= multiplier;
                }
                for (auto &p : top) {
                    st.top()[p.first] += p.second;
                }
            } else {
                string element;
                element += formula[i++];
                while (i < n && islower(formula[i])) {
                    element += formula[i++];
                }
                string countStr;
                while (i < n && isdigit(formula[i])) {
                    countStr += formula[i++];
                }
                int count = countStr.empty() ? 1 : stoi(countStr);
                st.top()[element] += count;
            }
        }

        map<string, int> sortedMap(st.top().begin(), st.top().end());
        string result;
        for (const auto &p : sortedMap) {
            result += p.first;
            if (p.second > 1) {
                result += to_string(p.second);
            }
        }

        return result;
    }
};