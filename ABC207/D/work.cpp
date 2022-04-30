#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";

using ll = long long;

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> v1, v2;
	for (int i = 0; i < N; i++)
	{
		int A, B;
		cin >> A >> B;
		v1.push_back(make_pair(A, B));
	}
	for (int j = 0; j < N; j++)
	{
		int A, B;
		cin >> A >> B;
		v2.push_back(make_pair(A, B));
	}
	sort(v1.begin(), v1.end());
	static const double pi = 3.141592653589793;
	for (long double theta = 0; theta < 360; theta += 1)
	{
		vector<pair<long double, long double>> p;
		for (int i = 0; i < N; i++)
		{
			p.push_back(make_pair(cos(pi * theta / 180) * v2[i].first + -sin(pi * theta / 180) * v2[i].second, sin(pi * theta / 180) * v2[i].first + cos(pi * theta / 180) * v2[i].second));
		}
		sort(p.begin(), p.end());

		vector<long double> X_diff, Y_diff;
		for (int i = 0; i < N; i++)
		{
			X_diff.push_back(p[i].first - v1[i].first);
			Y_diff.push_back(p[i].second - v1[i].second);
		}
		if (*max_element(X_diff.begin(), X_diff.end()) - *min_element(X_diff.begin(), X_diff.end()) <= 0.01 && *max_element(Y_diff.begin(), Y_diff.end()) - *min_element(Y_diff.begin(), Y_diff.end()) <= 0.01)
		{
			cout << YES << endl;
			return 0;
		}
	}
	cout << NO << endl;
	return 0;
}
