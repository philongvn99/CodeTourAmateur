#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
using namespace std;

int Snap_kill(int* Q, int first, int last, int time) {
	int wide = last - first + 1;
	int max = 0;
	int idx[20000];
	memset(idx, -1, 20000);
	for (int j = 0; j < time; j++) {
		max = 0;
		for (int i = 0; i < wide; i++) {
			bool ok = true;
			for (int k = 0; k < time; k++) { if (i == idx[k]) ok = false; }
			if (ok) {
				if (Q[i + first - 1] > max) {
					max = Q[i + first - 1];
					idx[j] = i;
				}
			}
		}
	}
	return max;
}
int Avenger() {
	string input;
	stringstream hero_sub, input_sub, plan_sub[500];
	int hero_pow[20000], plan[500], hero_num, plan_num, first, last, snap_num;
	//input
	getline(cin, input);
	input_sub << input;
	input_sub >> hero_num >> plan_num;
	//hero
	getline(cin, input);
	hero_sub << input;
	for (int i = 0; i < hero_num; i++) {
		hero_sub >> hero_pow[i];
	}
	//snap
	for (int i = 0; i < plan_num; i++) {
		getline(cin, input);
		plan_sub[i] << input;
		plan_sub[i] >> first >> last >> snap_num;
		plan[i] = Snap_kill(hero_pow, first, last, snap_num);
	}
	for (int i = 0; i < plan_num; i++) {
		cout << plan[i] << endl;
	}

	return 0;
}

bool Compression() {
	int n, L, R;
	cin >> n >> L >> R;
	int* a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	return true;
}
