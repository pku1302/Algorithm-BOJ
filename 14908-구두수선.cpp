한 가지에는 비례, 한 가지에는 반비례 관계일 경우 a/b 로 기준을 잡아
1일당 걸리는, 시간 1당 소요되는 비용을 구하는 방식 시간/비용를 기억해
sort를 쓰는 상황이라면 2개 중에 어느 거를 우선으로 둘건지만 생각해도 괜찮아

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


int N;
int days = 0;
vector<tuple<int, int, int>> v;


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		days += x;
		v.push_back(make_tuple(x, y, i + 1));
	}

	sort(v.begin(), v.end(), [](auto a, auto b) {
		if (get<0>(a) * get<1>(b) == get<0>(b) * get<1>(a))
			return get<2>(a) < get<2>(b);
		return get<0>(a) * get<1>(b) < get<0>(b) * get<1>(a);
	});

	for (int i = 0; i < N; i++)
	{
		cout << get<2>(v[i]) << ' ';
	}

	cout << '\n';

	return 0;
}
