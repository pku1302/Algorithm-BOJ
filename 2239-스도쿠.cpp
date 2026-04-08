스도쿠 번호랑 index랑 매칭 시키는데 너무 많은 시간을 썼다.
백트래킹을 좀 더 공부해야 할 듯

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

char tile[81];
char res[81];
bool visited[81];
vector<int> v;
bool found = false;
int N = 0;

bool row[9][10];
bool col[9][10];
bool area[9][10];

#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

//0 1   2  3  4  5  6  7  8
//9 10 11 12 13 14 15 16 17
//18 19 20 21 22 23 24 25 26
//
//27 28 29 30 31 32 33 34 35
//36 37 38 39 40 41 42 43 44
//45 46 47 48 49 50 51 52 53
//
//54 55 56 57 58 59 60 61 62
//63 64 65 66 67 68 69 70 71
//72 73 74 75 76 77 78 79 80

int arr[9][9] = {
	{0, 1, 2, 9, 10, 11, 18, 19, 20},
	{3, 4, 5, 12, 13, 14, 21, 22, 23},
	{6, 7, 8, 15, 16, 17, 24, 25, 26},
	{27, 28, 29, 36, 37, 38, 45, 46, 47},
	{30, 31, 32, 39, 40, 41, 48, 49, 50},
	{33, 34, 35, 42, 43, 44, 51, 52, 53},
	{54, 55, 56, 63, 64, 65, 72, 73, 74},
	{57, 58, 59, 66, 67, 68, 75, 76, 77},
	{60, 61, 62, 69, 70, 71, 78, 79, 80}
};


void DFS(int level)
{
	if (found) return;
	if (level == N)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << tile[i * 9 + j];
			}
			cout << '\n';
		}

		found = true;
		return;
	}

	int index = v[level];
	int x = index / 9;
	int y = index % 9;

	for (int i = 1; i <= 9; i++)
	{
		tile[index] = i + '0';
		if (!row[index / 9][i] && !col[index % 9][i] && !area[(x /3) * 3 + (y / 3)][i])
		{
			row[index / 9][i] = true;
			col[index % 9][i] = true;
			area[(x / 3) * 3 + (y / 3)][i] = true;

			DFS(level + 1);

			row[index / 9][i] = false;
			col[index % 9][i] = false;
			area[(x / 3) * 3 + (y / 3)][i] = false;
		}
		if (found) return;
		tile[index] = '0';
	}
}


int main()
{
	for (int i = 0; i < 81; i++)
	{
		cin >> tile[i];
		if (tile[i] == '0')
		{
			v.push_back(i);
			N++;
		}
		else
		{
			int num = tile[i] - '0';
			int x = i / 9;
			int y = i % 9;

			row[x][num] = true;
			col[y][num] = true;
			area[(x / 3) * 3 + (y / 3)][num] = true;
		}
	}

	DFS(0);

	return 0;
}
