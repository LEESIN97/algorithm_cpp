#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

string map[12];
int visited[12][6];
int res;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

struct pos {
	int y;
	int x;
};

void del(vector<pos> v) {
	for (pos p : v) {
		map[p.y][p.x] = '.';
	}
}


bool bfs(int row, int col) {
	int cnt = 1;
	queue<pos> q;
	vector<pos> v;
	v.push_back({ row, col });
	q.push({ row, col });
	visited[row][col] = 1;
	char c = map[row][col];
	while (!q.empty()) {
		pos cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny < 12 && ny >= 0 && nx < 12 && nx >= 0 && visited[ny][nx] != 1) {
				if (map[ny][nx] == c) {
					cnt++;
					visited[ny][nx] = 1;
					q.push({ ny,nx });
					v.push_back({ ny, nx });
				}
			}
		}
	}

	if (cnt >= 4) {
		del(v);
		return true;
	}
	else return false;

}

bool chain() {
	bool istrue = false;

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] != '.') {
				if (bfs(i, j)) istrue = true;
			}
		}
	}

	return istrue;
}


void gravity() {
	string temp[6];
	for (int i = 0; i < 6; i++) {
		int cnt_empty = 0;
		for (int j = 0; j < 12; j++) {
			if (map[j][i] == '.') cnt_empty++;
			else temp[i] += map[j][i];
		}


		
		for (int l = 0; l < cnt_empty; l++) {
			map[l][i] = '.';
		}
		int idx = cnt_empty;
		for(char c : temp[i]) {
			map[idx][i] = c;
			idx++;
		}

	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 12; i++) {
		cin >> map[i];
	}


	while (chain()) {
		res++;
		gravity();
	}

	cout << res;

	return 0;
}