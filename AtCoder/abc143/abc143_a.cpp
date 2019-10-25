#include<iostream>
#include<string>
#include<vector>
#include<boost/multiprecision/cpp_int.hpp>
typedef boost::multiprecision::cpp_int infinit;
using namespace std;
#define END return 0
int main()
{

	int a, b;
	cin >> a >> b;
	if (a < b * 2)
	{
		cout << 0 << endl;
		END;
	}

	cout << a - b * 2 << endl;

	END;
}
