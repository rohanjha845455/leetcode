#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minTimeToReach(std::vector<std::vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        std::vector<std::vector<int>> dist(n, std::vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        using T = std::tuple<int, int, int>; // (time, x, y)
        std::priority_queue<T, std::vector<T>, std::greater<>> pq;
        pq.emplace(0, 0, 0);

        const int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!pq.empty()) {
            auto [time, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == m - 1) return time;
            if (time > dist[x][y]) continue;

            for (const auto& [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int arriveTime = std::max(time, moveTime[nx][ny]) + 1;
                    if (arriveTime < dist[nx][ny]) {
                        dist[nx][ny] = arriveTime;
                        pq.emplace(arriveTime, nx, ny);
                    }
                }
            }
        }

        return -1;
    }
};
