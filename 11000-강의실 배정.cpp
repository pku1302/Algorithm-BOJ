강의실이 여러개라고 해서 칸을 여러개 만들어서 생각할 필요가 없었다
그냥 무조건 그 중에서 빨리 끝나는 시간만 보면 됐음

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

vector <pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int N;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}
	int answer = 1;
	int count = 0;

	pq.push(-1);

	sort(v.begin(), v.end(), [](auto a, auto b) {
		return a.first < b.first;
	});

	for (int i = 0; i < N; i++)
	{
		int start = v[i].first;
		if (pq.top() <= start)
		{
			pq.pop();
			pq.push(v[i].second);
		}
		else
		{
			pq.push(v[i].second);
			answer++;
		}
	}

	cout << answer << '\n';

	return 0;
}
