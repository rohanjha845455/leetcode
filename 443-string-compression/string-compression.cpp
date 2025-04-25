#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, index = 0;
        while (i < chars.size()) {
            char current = chars[i];
            int count = 0;
            while (i < chars.size() && chars[i] == current) {
                ++i;
                ++count;
            }
            chars[index++] = current;
            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[index++] = c;
                }
            }
        }
        return index;
    }
};
