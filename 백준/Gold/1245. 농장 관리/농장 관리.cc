#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[100][70];
int visited[100][70];

// 8방향 탐색 (상하좌우 + 대각선)
int dx[] = { -1,-1,-1, 0,0, 1,1,1 };
int dy[] = { -1, 0, 1,-1,1,-1,0,1 };

struct pos {
    int y, x;
};

bool is_peak;

void bfs(int sy, int sx) {
    queue<pos> q;
    q.push({ sy, sx });
    visited[sy][sx] = 1;
    is_peak = true;
    int h = map[sy][sx];

    while (!q.empty()) {
        pos cur = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            if (map[ny][nx] > h) {
                is_peak = false; // 더 높은 곳 발견 → 산봉우리 아님
            }

            if (!visited[ny][nx] && map[ny][nx] == h) {
                visited[ny][nx] = 1;
                q.push({ ny, nx });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && map[i][j] > 0) {
                bfs(i, j);
                if (is_peak) ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
