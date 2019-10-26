#include<iostream>
#include<string>
#include<vector>
using namespace std;
int input_int(void)
{
	int i;
	cin >> i;
	return i;
}
int main()
{
	
	string s;
	cin >> s;
	for (int i = 0; i < static_cast<int>(s.length()); i++)
	{
	

		if (i % 2 == 1)
		{
			if (s.substr(i, 1) == "L" || s.substr(i, 1) == "U" || s.substr(i, 1) == "D")
			{

			}
			else {
				cout << "No" << endl;
				return 0;
			}
		}
		else {
			if (s.substr(i, 1) == "R" || s.substr(i, 1) == "U" || s.substr(i, 1) == "D")
			{

			}
			else {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;

	return 0;
}
