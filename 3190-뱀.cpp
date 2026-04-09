구현 문제, 문제를 정확하게 읽어야 한다. 거의 말장난 수준.. 문제가 사기꾼도 아니고..
머리를 먼저 움직이고 충돌 검사 후 뱀 꼬리를 움직여야 됐다 (문제에선 '먼저' 라는 단어가 있긴 했다 꼬리를 먼저 움직여서 삽질) (..)
X초가 끝나고 방향을 전환해라 (X초가 시작될때 방향 전환해서 삽질)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <tuple>
#include <cstring>
#include <stack>
#include <list>

using namespace std;

int N;
int K;
int L;
queue<pair<int, char>> q;

int board[100 + 2][100 + 2];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
// Up, Down, Right, Left
// 0     1      2      3
// 1 -> 사과
// 2 -> 뱀

// -> 일때 L이면 UP, D면 Down // 2일때 L이면 0 D면 1
// V 일때 L이면 Right, D면 Left // 1일때 L이면 2, D면 3
// <- 일때 L이면 Down, D면 UP // 3일때 L이면 1, D면 0
// ^ 일때 L이면 Left, D면 Right // 0일때 L이면 3 D면 2

int dL[4] = { 3, 2, 0, 1 };
int dD[4] = { 2, 3, 1, 0 };

int main()
{
	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;

		board[x][y] = 1;
	}

	cin >> L;

	for (int i = 0; i < L; i++)
	{
		int X;
		char C;
		cin >> X >> C;

		q.push({ X, C });
	}

	int dir = 2;
	list<pair<int, int>> snake;
	board[1][1] = 2;
	snake.push_back({ 1, 1 });
	int answer = 1;
	bool gameover = false;

	pair<int, char> next = q.front();
	q.pop();

	while (!gameover)
	{
		auto head = snake.back();
		int hx = head.first;
		int hy = head.second;

		// 이동
		hx += dx[dir];
		hy += dy[dir];

		// 벽꿍
		if (hx == 0 || hx == N + 1 || hy == 0 || hy == N + 1)
		{
			gameover = true;
			break;
		}

		// 사과
		if (board[hx][hy] == 1)
		{
			board[hx][hy] = 2;
			snake.push_back({ hx, hy });
		}
		else
		{


			for (auto s : snake)
			{
				if (hx == s.first && hy == s.second)
				{
					gameover = true;
					break;
				}
			}

			auto tail = snake.front();
			board[tail.first][tail.second] = 0;
			snake.pop_front();

			snake.push_back({ hx, hy });
			board[hx][hy] = 2;
		}

		if (gameover)
			break;

		// 시간이 되면
		if (answer == next.first)
		{
			// 방향 전환
			if (next.second == 'L')
				dir = dL[dir];
			else
				dir = dD[dir];

			if (!q.empty())
			{
				auto p = q.front();
				next = p;
				q.pop();
			}
		}

		answer++;
	}

	cout << answer;

	return 0;
}
