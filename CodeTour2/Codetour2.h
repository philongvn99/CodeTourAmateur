#pragma once
#include<iostream>
#include<stdio.h>
#define size 10
using namespace std;

typedef struct {
	int vertic;
	int hori;
} station;

bool jump() {
	int input;
	cin >> input;
	int redundant = input % 2;
	while (redundant == 0) {
		input = input / 2;
		redundant = input % 2;
	}
	cout << input << endl;
	return true;
}

bool jump_up() {
	int input;
	cin >> input;
	int sum = 0;
	for (int i = 1; i <= input; i++) {
		int step = i;
		int redundant = step % 2;
		while (redundant == 0) {
			step = step / 2;
			redundant = step % 2;
		}
		sum += step;
	}
	cout << sum << endl;
	return true;
}

bool interstellar() {
	int num, max = 0, idx = 0;
	cin >> num;
	int* a = new int[num];
	int* b = new int[num];
	for (int i = 0; i < num; i++) cin >> a[i];
	for (int i = 0; i < num; i++) cin >> b[i];
	for (int i = 0; i < num; i++) {
		int sum = 0;
		for (int j = 0; j < num; j++) {
			if (i == j) sum += a[j];
			else sum += b[j];
		}
		if (sum > max) { max = sum; idx = i; }
		cout << idx << endl;
	}
	cout << max << endl;
	delete[] a;
	delete[] b;
	return true;
}

bool IDcard() {
	int M, N, X, Y, count_list = 1, start = 0, end = 1, count_card = 1;
	cin >> M >> N >> X >> Y;
	int** tab;
	tab = new int*[M];
	int* list = new int[N];
	for (int i = 0; i < M; i++) {
		int amount;
		cin >> amount;
		tab[i] = new int[amount + 1];
		tab[i][0] = amount;
		for (int j = 1; j <= amount; j++) { cin >> tab[i][j]; }
		//for (int j = 0; j <= amount; j++) { cout << tab[i][j]; }
	}
	list[0] = X;
	while (count_list < N) { // duyet list
		while (start < end) { // duyet so the can thiet
			for (int i = 0; i < M; i++) { // duyet IDcard
				bool okie = 0;
				for (int j = 1; j <= tab[i][0]; j++) {
					if (tab[i][j] == list[start]) okie = 1;
				}
				if (okie) {
					for (int j = 1; j <= tab[i][0]; j++) {
						if (tab[i][j] == Y) {
							cout << count_card << endl;
							delete[] list;
							for (int k = 0; k < M; k++) { delete[] tab[k]; }
							delete[] tab; 
							return true;
						}
						bool ok = 1;
						for (int k = 0; k < count_list; k++) if (tab[i][j] == list[k]) ok = 0;
						if (ok) { list[count_list] = tab[i][j]; count_list++; }
					}  
				}
			}
			start++;
		}
		if (end == count_list) {
			cout << "impossible" << endl;
			delete[] list;
			for (int i = 0; i < M; i++) { delete[] tab[i]; }
			delete[] tab;
			return true;
		}
		count_card++;
		end = count_list;
	}
	cout << "impossible" << endl;
	delete[] list;
	for (int i = 0; i < M; i++) { delete[] tab[i]; }
	delete[] tab;
	return true;
}

int find(int* tab, int* daduyet, int soluongID, int& dem, int dau, int duoi, int ID, int soIDcan) {
	daduyet[dem] = ID;
	dem++;
	int times = tab[0];
	bool ok = false;
	for (int i = 1; i <= times; i++) {
		if (tab[i] == dau) ok = true;
	}
	for (int i = 0; i < times; i++) {
		if (ID == daduyet[i]) ok = false;
	}
	for (int i = 1; i <= times; i++) {
		if (tab[i] == duoi) return dem;
	}
	if (ok) {

	}
	else {}
	return 0;
}

bool build() {
	int Num_station, sum = 0, direction[4];
	cin >> Num_station;
	station* tunnel = new station[Num_station];
	station* pos = new station[size];
	for (int i = 0; i < Num_station; i++) {
		cin >> tunnel[i].vertic >> tunnel[i].hori;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			direction[0] = 1;
			direction[1] = 1;
			direction[2] = 1;
			direction[3] = 1;
			for (int k = 0; k < Num_station; k++) {
				if (i == tunnel[k].vertic) {
					if (j > tunnel[k].hori) direction[3] = 0;
					else if (j < tunnel[k].hori) direction[1] = 0;
				}
				if (j == tunnel[k].vertic) {
					if (i > tunnel[k].hori) direction[2] = 0;
					else if (i < tunnel[k].hori) direction[0] = 0;
				}
			}
			if (direction[0] + direction[1] + direction[2] + direction[3] == 0) {
				pos[sum].vertic = i;
				pos[sum].hori = j;
				sum++;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int ok = 1;
			for (int k = 0; k < Num_station; k++) {
				if ((i == tunnel[k].vertic) && (j == tunnel[k].hori)) {
					cout << 1;
					ok = 0;
					//break;
				}
			}
			if (ok) {
				for (int k = 0; k < sum; k++) {
					if ((i == pos[k].vertic) && (j == pos[k].hori)) {
						cout << 2;
						ok = 0;
						//break;
					}
				}
			}
			if(ok) cout << "-";
		}
		cout << endl;
	}
	cout << sum << endl;
	delete[] tunnel;
	delete[] pos;
	return true;
}
bool HLB() {
	int sphere, unit, max_length, sleep, service;
	cin >> sphere >> unit >> max_length >> sleep;
	service = sphere - sleep - unit;
	if (sleep % unit) cout << "impossible" << endl;
	else if (max_length * unit > sphere - unit) cout << "impossible" << endl;
	else if (max_length * sleep < sphere - unit ) cout << "impossible" << endl;
	else cout << "OK!" << endl;
	return true;
}