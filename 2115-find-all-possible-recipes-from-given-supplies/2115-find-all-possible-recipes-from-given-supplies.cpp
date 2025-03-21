class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> dependency;
        unordered_map<string, int> inDeg;
        unordered_set<string> isRecipe(recipes.begin(), recipes.end());

        // Build dependency graph
        for (int i = 0; i < recipes.size(); i++) {
            for (string& ing : ingredients[i]) {
                dependency[ing].push_back(recipes[i]);
                inDeg[recipes[i]]++;
            }
        }

        queue<string> q;
        // unordered_set<string> available(supplies.begin(), supplies.end());

        // Push initial supplies to queue
        for (const string& item : supplies) {
            q.push(item);
        }

        vector<string> ans;

        while (!q.empty()) {
            string curr = q.front(); q.pop();

            for (auto& recipe : dependency[curr]) {
                inDeg[recipe]--;
                if (inDeg[recipe] == 0) {
                    q.push(recipe);
                    if (isRecipe.count(recipe)) ans.push_back(recipe);
                }
            }
        }

        return ans;
    }
};
