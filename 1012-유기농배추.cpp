테스트를 여러번 해야 할땐, visited, 원래 타일 memset하는거 잊지말것
memset하는 방법 자체도 숙지할 것

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <tuple>
#include <cstring>

using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int T;
int n, m, k;
int tile[50][50];
bool visited[50][50];
queue<pair<int, int>> q;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

const int INF = 1e9;

void bfs()
{
	while (!q.empty())
	{
		auto p = q.front();
		int x = p.first;
		int y = p.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];

			if (tx >= 0 && tx < n && ty >= 0 && ty < m)
			{
				if (tile[tx][ty] == 1 && !visited[tx][ty])
				{
					visited[tx][ty] = true;
					q.push({ tx, ty });
				}
			}
		}
	}
}

int solution()
{
	int res = 0;
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;

		tile[x][y] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tile[i][j] == 1 && !visited[i][j])
			{
				q.push({ i, j });
				visited[i][j] = true;
				bfs();
				res++;
			}
		}
	}

	return res;
}

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cout << solution() << '\n';
		memset(tile, 0, sizeof(tile));
		memset(visited, false, sizeof(visited));
	}

	return 0;
}
