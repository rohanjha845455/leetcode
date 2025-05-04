class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> count;
        int result = 0;

        for (auto& d : dominoes) {
            int a = d[0], b = d[1];
            if (a > b) swap(a, b);  
            int key = a * 10 + b;
            result += count[key];  
            count[key]++;
        }

        return result;
    }
};
