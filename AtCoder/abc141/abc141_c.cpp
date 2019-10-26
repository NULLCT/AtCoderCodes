#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define ll long long
int main()
{

	ll n, k, q,qpqp;
	vector<ll> a;
	cin >> n >> k >> q;
	for (ll i = 0; i < q; i++)
	{
		cin >> qpqp;
		a.push_back(qpqp);
	}
	vector<ll> points(n,k-q);

	for (ll i = 0; i < q; i++)
	{
		points[a[i] - 1]++; 
	}
	for (ll i = 0; i < n; i++)
	{
		if (points[i] > 0) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}
