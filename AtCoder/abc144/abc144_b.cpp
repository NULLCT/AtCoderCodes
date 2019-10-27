#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
//#include<boost/multiprecision/cpp_int.hpp>
//#include<boost/multiprecision/cpp_dec_float.hpp>
//namespace mp = boost::multiprecision;
using namespace std;
int main()
{

	int n;
	cin >> n;
	for (int i = 0; i < 9; i++)
	{
		for (int w = 0; w < 9; w++)
		{
			if ((i + 1) * (w + 1) == n)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;

	return 0;
}
