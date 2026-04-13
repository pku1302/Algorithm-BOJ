#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <tuple>
#include <cstring>
#include <string>
#include <stack>
#include <list>
#include <unordered_set>
#include <set>
#include <deque>

typedef long long ll;
using namespace std;
int N;

//A, B, C, D, E, F
//0  1  2  3  4  5

// (n-2) * (n-2) * 5
// (n-1) * 4
// 4

// 반례
// A, F (0, 5)
// E, B (1, 4)
// D, C (2, 3)

// E, A, D (0, 3, 4)
// E, A, C (0, 2, 4)
// D, A, B (0, 1, 3)
// A, B, C (0, 1, 2)

// E, F, D (3, 4, 5)
// E, F, C (2, 4, 5)
// D, F, B (1, 3, 5)
// F, B, C (1, 2, 5)


vector<ll> two;
vector<ll> triple;

int main()
{
	cin >> N;

	vector<ll> v;

	for (int i = 0; i < 6; i++)
	{
		ll x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (i == 0 && j == 5) continue;
			if (i == 1 && j == 4) continue;
			if (i == 2 && j == 3) continue;
			two.push_back(v[i] + v[j]);
		}
	}

	triple.push_back(v[0] + v[3] + v[4]);
	triple.push_back(v[0] + v[2] + v[4]);
	triple.push_back(v[0] + v[1] + v[3]);
	triple.push_back(v[0] + v[1] + v[2]);
	triple.push_back(v[3] + v[4] + v[5]);
	triple.push_back(v[2] + v[4] + v[5]);
	triple.push_back(v[1] + v[3] + v[5]);
	triple.push_back(v[1] + v[2] + v[5]);

	sort(v.begin(), v.end());
	sort(two.begin(), two.end());
	sort(triple.begin(), triple.end());

	ll answer = 0;
	if (N == 2)
	{
		answer += triple[0] * 4;
		answer += two[0] * 4;
;	}
	else if (N == 1)
	{
		answer += v[0] + v[1] + v[2] + v[3] + v[4];
	}
	else
	{
		answer += v[0] * (N - 2) * (N - 2) * 5; //(5)
		answer += v[0] * (N - 2) * 4;
		answer += (two[0] * (N - 1) * 4) + (two[0] * (N - 2) * 4); // 24 + 12 = 36
		answer += triple[0] * 4; // 24
	}

	cout << answer << '\n';

	return 0;
}
