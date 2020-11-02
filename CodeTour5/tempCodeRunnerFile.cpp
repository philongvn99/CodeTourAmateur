#include <iostream>
#include <stdio.h>
using namespace std;
int main()	{
	int b = 14;
	int i = 0;
	int a = 5;
	while (i < 20) {
		if (a > b) { b += a; cout << b << endl; }
		else { a += b; cout << a << endl; }
		i++;
	}
	return 0;
}
