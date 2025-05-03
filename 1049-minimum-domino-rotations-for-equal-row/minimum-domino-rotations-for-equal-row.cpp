class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int cand1 = tops[0], cand2 = bottoms[0];

        int res1 = check(tops, bottoms, cand1);
        int res2 = check(tops, bottoms, cand2);

        if (res1 == -1 && res2 == -1) return -1;
        if (res1 == -1) return res2;
        if (res2 == -1) return res1;

        return min(res1, res2);
    }

    int check(vector<int>& tops, vector<int>& bottoms, int target) {
        int n = tops.size();
        int topRot = 0, botRot = 0;

        for (int i = 0; i < n; ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return -1;  // Not possible
            }
            else if (tops[i] != target) {
                topRot++;
            }
            else if (bottoms[i] != target) {
                botRot++;
            }
        }

        return min(topRot, botRot);
    }
};
