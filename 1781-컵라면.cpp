반례 생각하는게 좀 중요했던 것 같음
반례를 생각하고 거기에 끼워 맞추는 방법도 좋은 것 같음

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

vector<pair<int, int>> v;

// 데드라인이 널널한 거 먼저
// 데드라인이 같다면 그 중에서 많이 주는거 먼저

int N;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), [](auto a, auto b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first > b.first;
	});

	// 들어 갈 수있는 것중 가장 큰거

	queue <pair<int, int>> q;

	for (int i = 0; i < v.size(); i++)
	{
		q.push(v[i]);
	}

	int end = v[0].first;
	int answer = 0;
	int idx = 0;

	priority_queue<int> pq;

	for (int current = end; current >= 1; current--)
	{
		while (!q.empty() && q.front().first >= current)
		{
			pair<int, int> x = q.front();
			q.pop();
			pq.push(x.second);
		}

		if (pq.size() > 0)
		{
			answer += pq.top();
			pq.pop();
		}
	}

	cout << answer << '\n';

	return 0;
}
