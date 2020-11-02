#pragma once
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

bool SchoolOnTime() {
	unsigned int Distance, Green, Yellow, Red;
	cin >> Distance >> Green >> Yellow >> Red;
	float Speed;
	float MinTime = Distance * 0.06;
	int period = Green + Yellow + Red;
	int time = Red + ((int)(MinTime - Red) / period) * period;
	if (time < MinTime) time += period;
	Speed = Distance * 3.6 / time;
	printf("%.2f", Speed);
	return true;
}

bool PowerGather() {
	int Case; cin >> Case;
	int** array;
	array = new int* [Case];
	int order, init1, init2, index1, index2;
	for (int i = 0; i < Case; i++) {
		array[i] = new int[5];
		for (int j = 0; j < 5; j++) cin >> array[i][j];
	}
	for (int i = 0; i < Case; i++) {
		int j = 3;
		order = array[i][0];
		init1 = array[i][1];
		init2 = array[i][2];
		index1 = array[i][3];
		index2 = array[i][4];

		while (j <= order) {
			if (j % 2) init1 = index1 + init1 * index2 * init2;
			else init1 = index1 * init1 + index2 * init2;
			j++;
		}
		if (j % 2) cout << init2 << endl;
		else cout << init1 << endl;
	}
	for (int i = 0; i < Case; i++) delete[] array[i];
	delete[] array;
	return true;
}

bool UmbRobber() {
	int N, LenRobA = 2, LenRobB = 1;
	int k = 1;
	cin >> N;
	if (N == 1) {
		cout << "1\t1" << endl;
		return true;
	}
	int* RobA = new int[N / 2];
	int* RobB = new int[N / 2];
	int* leaveA = new int[N / 3 * 2];
	memset(RobA, 0, N / 2);
	memset(RobB, 0, N / 2);
	RobA[0] = 1;
	RobA[1] = 2;
	leaveA[0] = 1;
	while(RobA[LenRobA - 1] + RobA[LenRobA-2] < N) {
		RobA[LenRobA] = RobA[LenRobA - 1] + RobA[LenRobA - 2];
		LenRobA++;
	}
	for (int i = 2; i < N; i++) {
		bool q = true;
		for (int j = 2; j < i / 2; j++) {
			if (i % j == 0) {
				q = false; break;
			}
		}
		if (q) {
			leaveA[k] = i;
			k++;
			cout << i << ' ';
		}
	}
	cout << k << endl;
	RobB[0] = 1;
	for (int i = 2; i <= N / 2; i++) if (N % i == 0) { 
		RobB[LenRobB] = i;
		LenRobB++;
	}
	cout << 2 << endl;
	delete[] RobA;
	delete[] RobB;
	return true;
}