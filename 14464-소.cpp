왜 틀렸냐면.. 시간이라는 점을 생각안함 (한번 선택 시 되돌릴 수가 없음)
빨리 끝나는 소를 먼저 처리하면 항상 최적해다
multiset의 전용 lower bound 함수를 안쓰면 Log(N)의 비용이 들어버린다.


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

using namespace std;


multiset<int> chick;
vector<pair<int, int>> cow;

int C, N;

int main()
{
	cin >> C >> N;

	for (int i = 0; i < C; i++)
	{
		int x;
		cin >> x;
		chick.insert(x);
	}

	for (int i = 0; i < N; i++)
	{
		pair<int, int> c;
		cin >> c.first >> c.second;
		cow.push_back(c);
	}

	sort(cow.begin(), cow.end(), [](auto a, auto b) {
		return	a.second < b.second;
	});

	int answer = 0;
	for (auto c : cow)
	{
		auto it = chick.lower_bound(c.first);

		if (it != chick.end() && *it <= c.second)
		{
			chick.erase(it);
			answer++;
		}
	}

	cout << answer << '\n';

	return 0;
}
