#pragma once
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

bool bin(int num, int** bin, int length) {
	int long_func = log2(num);
	if (long_func >= length) return false;
	for (int i = length; i >= 0; i--) {
		(*bin)[i] = num / pow(2, i);
		num = num - pow(2, i) * (*bin)[i];
	}
	return true;
}

bool Child_array() {
	int num;
	cin >> num;
	int sum = 0;
	int* array = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> array[i];
	}
	long long times = pow(2, num); // So mang con
	int* choose = new int[num]; // bit chon
	int* child_array = new int[num]; //mang con
	// Xet 2^n mang con
	for (int i = 1; i < times; i++) {
		memset(choose, 0, num);
		memset(child_array, 0, num);
		int num_x = i;
		int count = 0;
		int sum_loop = 0;
		// Tao bit chon va tong cua mang con
		for (int j = num - 1; j >= 0; j--) {
			choose[j] = num_x / pow(2, j);
			num_x = num_x - pow(2, j) * choose[j];
			if (choose[j] == 1) { child_array[count] = array[j]; count++; sum_loop += array[j]; }
		}
		bool ok = true;
		int times_loop = pow(2, count); // Xet cac tong cua mang con
		int child_sum;
		for (int q = 1; q <= sum_loop; q++) { // Xet cac gia tri be hon tong cua mang con
			int count_loop = 0;
			for (int j = 1; j < times_loop; j++) {
				child_sum = 0;
				int num_y = j;
				for (int k = count - 1; k >= 0; k--) {
					choose[k] = num_y / pow(2, k);
					if (choose[k]) child_sum += child_array[k];
					num_y = num_y - pow(2, k) * choose[k];
				}
				if (child_sum == q) {
					count_loop++;
				}
			}
			if (count_loop == 0) { ok = false; }
		}
		if (ok) sum++;
	}
	cout << sum << endl;
	delete[] array;
	delete[] choose;
	delete[] child_array;
	return false;
}

bool xor_() {
	int b, n, k, m;
	cin >> b >> n >> k >> m;
	int** array;
	int sum = 0;
	
	array = new int* [n];
	for (int i = 0; i < n; i++) array[i] = new int[2];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) cin >> array[i][j];
	}
	int times = pow(2, b);

	int* term = new int[times];
	for (int i = 0; i < times; i++)  term[i] = 0;
	int* choose = new int[k + 2];
	for (int i = 1; i < k + 2; i++)  choose[i] = 0;
	choose[0] = n;
	
	int xor_of_k, sub_xor;
	int multi;
	int sub;

	while (true) {
		xor_of_k = 0;
		multi = 1;
		for (int i = 1; i <= k; i++) {
			sub = choose[i];
			sub_xor = xor_of_k ^ array[sub][0];
			xor_of_k = sub_xor;
			multi *= array[sub][1];
		}
		term[xor_of_k] += multi;
		for (int i = 1; i <= k + 1; i++) if (choose[i - 1] == n) choose[i]++;
		for (int i = 1; i <= k + 1; i++) if (choose[i] == n) choose[i] = 0;
		if (choose[k+1] == 1) break;
	}

	for (int i = 0; i < times; i++) { sum += pow(term[i], 2); }
	cout << sum << endl;

	for (int i = 0; i < n; i++) delete[] array[i];
	delete[] array;
	delete[] term;
	/*int a = 1;
	int b = 2;
	int c = b ^ a;
	cout <<  c << endl;*/
	return false;
}


bool Buffet() {
	int N, Min = 0, add;
	int Dish, NumOfSlot, Portion;
	cin >> Dish >> NumOfSlot >> Portion;
	int Times = Dish * Portion;
	int* Slot = new int[Dish];
	int* SlotIndex = new int[NumOfSlot];
	int* DishInSlot = new int[NumOfSlot];
	for (int i = 0; i < NumOfSlot; i++) {
		Slot[i] = Portion - 1;
		SlotIndex[i] = i;
		DishInSlot[i] = i;
	}
	for (int i = NumOfSlot; i < Dish; i++) Slot[i] = Portion;
	for (int j = 0; j < NumOfSlot; j++) cout << DishInSlot[j] << " ";
	cout << endl;

	for (int i = NumOfSlot; i < Times; i++) {
		add = i % Dish;
		int j = 0;
		while(j < NumOfSlot) {
			if (SlotIndex[j] == Min) {
				if (Slot[add] > 0) {
					Slot[add]--;
					DishInSlot[j] = add;
					SlotIndex[j] = i;
				}
				break;
			}
			j++;
		}
		Min++;
		for (int j = 0; j < NumOfSlot; j++) cout << DishInSlot[j] << " ";
		cout << endl;
	}

	delete[] Slot;
	delete[] SlotIndex;
	delete[] DishInSlot;
	return true;
}

bool Wanderer() {
	//Add data into NumOfCity x NumOfCity matrix
	int City, Money;
	int** CostOfRoad;
	CostOfRoad = new int* [City];
	for (int i = 0; i < City; i++) CostOfRoad[i] = new int[City];
	for (int i = 0; i < City; i++) {
		for (int j = 0; j < City; j++) cin >> CostOfRoad[i][j];
	}



	//Delete pointer
	for (int i = 0; i < City; i++) delete[] CostOfRoad[i];
	delete[] CostOfRoad;
	return true;
}