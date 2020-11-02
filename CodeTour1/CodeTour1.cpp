#include<cstdio>
#include<iostream>
#include<time.h>
using namespace std;
enum { x1, x2, x3 } State;
int main() {
	//Avenger();
	//Compression();
	srand(time(NULL));
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 20 - 10; cout << a[i] << " ";
	}
	int s_min = 0;
	int	s_max = 0;
	int t_min = 0;
	cout << endl;
	int k = 1;
	int t = a[0];
	int s = a[0];
	while (k < 10) {
		if (t + a[k] <= a[k]) {
			t = a[k]; t_min = k;
			}
			else t = t + a[k];
		if (s < t) {
			s = t; s_min = t_min; s_max = k;
		}
		k++;
		cout << t << ' ' << s << endl;
	}
	cout << s_min << ' ' << s_max << endl;
	cin.ignore();
	return 0;
}
