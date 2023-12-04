#include <iostream>
using namespace std;

int replace5sWith8s(int n)
{
	if (n % 10 == 5) n += 3;
	
	if (n / 10 == 0)
		return n;
	
	return replace5sWith8s(n / 10) * 10 + n%10;
}	

//int main()
//{
//	int n = 549587;
//	
//	cout << replace5sWith8s(n);
//	return 0;
//}