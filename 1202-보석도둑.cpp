한번에 pq안에 다 넣으려다가 실패한 케이스
각 가방을 기준으로 pq에 넣는게 키 포인트였다.

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

struct cmp {
	bool operator()(pair<ll, ll> a , pair<ll ,ll> b)
	{
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
	}
};

int N, K;
vector<pair<ll, ll>> jw;
vector<ll> bag;
priority_queue<ll> pq;

bool used[300001];

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		// x 무게 , y 가격
		jw.push_back({ x, y });
	}

	for (int i = 0; i < K; i++)
	{
		int x;
		cin >> x;
		bag.push_back(x);
	}

	sort(jw.begin(), jw.end());
	sort(bag.begin(), bag.end());
	auto it = jw.begin();
	ll answer = 0;

	for (int i = 0; i < K; i++)
	{
		int currentBag = bag[i];

		while (it != jw.end() && currentBag >= (*it).first)
		{
			pq.push((*it).second);
			it++;
		}

		if (!pq.empty())
		{
			answer += pq.top();
			pq.pop();
		}
	}

	cout << answer << '\n';


	return 0;
}
