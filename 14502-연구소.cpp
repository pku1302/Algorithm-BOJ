2차원 배열을 1차원으로 눌러서 생각하기
서로 다른 K개의 조합 구하는데에 익숙해질 것

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <tuple>
#include <cstring>

using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int INF = 1e9;

int n, m;
int board[10][10];
int maxCount = 0;
bool visited[10][10];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector<pair<int, int>> v;
queue<pair<int, int>> q;

queue<pair<int, int>> start;

int bfs()
{
	int res = 0;

	while (!q.empty())
	{
		auto p = q.front();
		int cx = p.first;
		int cy = p.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (visited[nx][ny] || board[nx][ny] != 0) continue;

			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == false && board[i][j] == 0)
			{
				res++;
			}
		}
	}

	return res;
}


int main()
{
	cin >> n >> m;
	int total = n * m;
	vector<int> pos;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 2)
				start.push({i, j});

			if (board[i][j] == 0)
				pos.push_back(i * m + j);
		}
	}

	int sz = pos.size();

	for (int a = 0; a < sz; a++)
	{
		for (int b = a + 1; b < sz; b++)
		{
			for (int c = b + 1; c < sz; c++)
			{
				int x1 = pos[a] / m, y1 = pos[a] % m;
				int x2 = pos[b] / m, y2 = pos[b] % m;
				int x3 = pos[c] / m, y3 = pos[c] % m;

				board[x1][y1] = 1;
				board[x2][y2] = 1;
				board[x3][y3] = 1;

				q = start;
				memset(visited, false, sizeof(visited)); // visited 초기화
				int res = bfs();

				if (maxCount < res)
					maxCount = res;


				board[x1][y1] = 0;
				board[x2][y2] = 0;
				board[x3][y3] = 0;
			}
		}
	}
	
	q = start;

	cout << maxCount;

	return 0;
}
