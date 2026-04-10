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
vector<pair<long long, long long>> v;

int main()
{
	cin >> N;
	long long s, e;
	
	for (int i = 0; i < N; i++)
	{
		cin >> s >> e;
		v.push_back({s, e});
	}

	sort(v.begin(), v.end(), [](pair<long long, long long> a, pair<long long, long long> b) {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
	});
	
	long long current = 0;
	int res = 0;

	for (auto a : v)
	{
		if (a.first >= current)
		{
			current = a.second;
			res++;
		}
	}

	cout << res << '\n';

	return 0;
}
