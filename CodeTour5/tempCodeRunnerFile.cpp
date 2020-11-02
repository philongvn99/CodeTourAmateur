#include <iostream>
#include <stdio.h>
using namespace std;
int main()	{
<<<<<<< HEAD
	int b = 3;
=======
	int b = 20;
>>>>>>> 664bd6542c36ca0d1d0d8b8036a84b6f045ebf57
	int i = 0;
	int a = 5;
	while (i < 20) {
		if (a > b) { b += a; cout << b << endl; }
		else { a += b; cout << a << endl; }
		i++;
	}
	return 0;
}
