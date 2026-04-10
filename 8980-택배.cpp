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

int N, C, M;
int arr[2001];


// 1. 받는 마을 번호가 가까워야 한다
// 2. 박스 개수가 더 많아야 한다.
// 


int main()
{
	cin >> N >> C >> M;
	int in, out, box;
	vector<tuple<int, int, int>> v;

	for (int i = 0; i < M; i++)
	{
		cin >> in >> out >> box;

		v.push_back({in, out, box});
	}

	sort(v.begin(), v.end(), [](auto a, auto b) {
		return get<1>(a) < get<1>(b);
	});


	int answer = 0;

	for (auto t : v)
	{
		int start = get<0>(t);
		int end = get<1>(t);
		int b = get<2>(t);

		int max_load = 0;

		for (int i = start; i < end; i++)
		{
			max_load = max(max_load, arr[i]);
		}

		int boxNumber = min(b, C - max_load);
		
		for (int i = start; i < end; i++)
		{
			arr[i] += boxNumber;
		}

		answer += boxNumber;
	}

	cout << answer << '\n';

	return 0;
}
