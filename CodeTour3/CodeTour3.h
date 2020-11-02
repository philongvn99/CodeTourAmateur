#pragma once
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

bool bin(int num, int**  bin, int length) {
	int long_func = log2(num);
	if (long_func >= length) return false;
	for (int i = length; i >= 0; i--) {
		(*bin)[i] = num / pow(2, i);
		num = num - pow(2, i)*(*bin)[i];
	}
	return true;
}
bool Character() {
	string a;
	getline(cin, a); 
	int length = a.length();
	int length_char = length * (length + 1) / 2;
	string* b = new string[length_char];
	int count = 0;
	for(int size = 1; size <= length; size++) {
		int times = length - size + 1;
		string string_sub;
		for (int i = 0; i < times; i++) {
			string_sub = a.substr(i, size);
			bool ok = 1;
			for (int j = 0; j < count; j++) {if (string_sub == b[j]) ok = 0;}
			if (ok) { b[count] = string_sub; count++; }
		}
		cout << size << " " << count << endl;
	}
	for (int i = 0; i < count; i++) cout << b[i] << endl;
	cout << count << endl;
	return true;
}

bool Secret_room() {
	int Num_of_stone, Min, Max, count = 0;
	cin >> Num_of_stone >> Min >> Max; 
	int times = pow(2, Num_of_stone - 1);
	int* chars_on_stone = new int[Num_of_stone];
	int* choose = new int[Num_of_stone - 1];
	for (int i = 0; i < Num_of_stone; i++) { cin >> chars_on_stone[i]; }
	for (int i = 1; i < times; i++) {
		bool ok = true;
		int sum = 0;
		bin(i, &choose, Num_of_stone - 1);
		for (int j = 0; j < Num_of_stone - 1; j++) {
			sum += chars_on_stone[j];
			if (choose[j]) { 
				if ((sum < Min) || (sum > Max)) {
					ok = false;
					break;
				}
				sum = 0;
			}
		}
		sum += chars_on_stone[Num_of_stone - 1];
		if ((sum < Min) || (sum > Max)) ok = false;
		if (ok) {
			count++;
			for (int j = 0; j < Num_of_stone - 1; j++) cout << choose[j];
			cout << endl;
		}
	}
	cout << count << endl;
	return true;
}

typedef struct {
	int tower1;
	int tower2;
	int indestructibility;
}road;

typedef struct {
	int TargetTower;
	int Links;
}target;

typedef struct {
	int Tower;
	int *ListOfChild;
	int LengthOfList;
} node;

bool browse(road *Road, int *tower_browse, int *road_browse, int &browse_count, int road_idx, int tow_idx, int n) {
	if (browse_count < n) {
		if (Road[road_idx].tower1 == tower_browse[tow_idx]) {
			tower_browse[browse_count] = Road[tow_idx].tower2;
			road_browse[browse_count] = tow_idx;
			browse_count++;
		}
		else if (Road[road_idx].tower2 == tower_browse[tow_idx]) {
			tower_browse[browse_count] = Road[tow_idx].tower1;
			road_browse[browse_count] = tow_idx;
			browse_count++;
		}
	}
	return true;
}

/*bool GreatWall() {
	int NumOfTower, NumOfPlan;
	cin >> NumOfTower >> NumOfPlan;
	int NumOfRoad = NumOfTower - 1;
	int NumOfAlter = 0;
	int NumOfBrowsedRoad = 0;
	int NumOfBrowsedTower;
	road	*Road = new road[NumOfRoad];
	target	*Plan = new target[NumOfPlan];
	

	for (int PlanCount = 0; PlanCount < NumOfPlan; PlanCount++) {
		int* BrowsedTower = new int[NumOfRoad];
		int ThisTow = Plan[PlanCount].TargetTower;
		node* Node = new node[NumOfTower];
		
		BrowsedTower[0] = ThisTow;
		Node[0].Tower = ThisTow;		
		NumOfBrowsedTower = 1;
		for (int TowerCount = 0; TowerCount < NumOfTower; TowerCount++) {
			Node[TowerCount].LengthOfList = 0;
		}

		for (int TowerCount = 0; TowerCount < NumOfTower; TowerCount++) {
			for (int RoadCount = 0; RoadCount < NumOfRoad; RoadCount++) {
				if (Road[RoadCount].tower1 == ThisTow) {
					bool ok = true;
					int addTow = Road[RoadCount].tower2;
					for (int i = 0; i < NumOfBrowsedTower; i++) if (addTow == BrowsedTower[NumOfBrowsedTower]) ok = false;
					if(ok){
						BrowsedTower[NumOfBrowsedTower] = addTow;
						NumOfBrowsedTower++;
					}
				}
				else if (Road[RoadCount].tower2 == ThisTow) {
					bool ok = true;
					int addTow = Road[RoadCount].tower1;
					for (int i = 0; i < NumOfBrowsedTower; i++) if (addTow == BrowsedTower[NumOfBrowsedTower]) ok = false;
					if(ok){
						BrowsedTower[NumOfBrowsedTower] = addTow;
						NumOfBrowsedTower++;
					}
				}
			}
		}
		delete[] BrowsedTower;
		delete[] Node;
	}
	
	delete[] Road;
	delete[] Plan;
	//delete[] TowerBrowse;
	return true;
}*/

int dec(char x) { int n = int(x); return n - 48; }

bool x4x7(){
	string input;
	char x4 = '4';
	char x7 = '7';
	string output;
	getline(cin, input);
	//cin.ignore();
	while (input[0] == '0') input.erase(0, 1);
	int length = input.length();
	if(length % 2){
		length++;
		for (int i = 0; i < length / 2; i++) output += x4;
		for (int i = 0; i < length / 2; i++) output += x7;
	}
	else if (dec(input[0]) > 7) {
		length += 2;
		for (int i = 0; i < length / 2; i++) output += x4;
		for (int i = 0; i < length / 2; i++) output += x7;
	}
	else {
		for (int i = 0; i < length; i++) output += "0";
		int count4 = 0;
		int count7 = 0;
		bool alarm = false;
		bool constant = false;
		int insert = 0;
		while(insert < length) {
			if (constant) {output[insert] = x4;}
			else if (dec(input[insert]) <= 4) {
				output[insert] = x4;
				if (dec(input[insert]) < 4) constant = true;
			}
			else if(dec(input[insert]) <= 7) {
				output[insert] = x7;
				if (dec(input[insert]) < 7) constant = true;
			}
			else {
				output[insert] = x4;
				alarm = true;
				int back = insert - 1;
				while ((back >= 0) && alarm) {
					if (dec(output[back]) > dec(input[back])) alarm = false;
					else back--;
				}
				if (back == -1) back = insert - 1;;
				while ((back >= 0) && alarm) {
					if (dec(output[back]) > dec(input[back])) alarm = false;
					else if (output[back] == x4) { output[back] = x7; alarm = false; }
					else back--;
				}
				if (back == -1) {
					length += 2;
					output = "";
					for (int i = 0; i < length / 2; i++) output += x4;
					for (int i = 0; i < length / 2; i++) output += x7;
					break;
				}
				constant = true;
			}
			insert++;
		}
		int sum = 0;
		int max = pow(2, length);
		cout << output << endl;
		for (int i = 0; i < length; i++) if (output[i] == x7) { count7++; sum += pow(2, length - 1 - i); }
		count4 = length - count7;
		int* array = new int[length];
		while ((count4 != count7) && (sum < max)) {
			count4 = count7 = 0;
			sum++;
			int sub = sum;
			int bit;
			memset(array, 0, length);
			for (int i = 0; i < length; i++) {
				bit = sub / pow(2, length - 1 - i);
				sub -= bit * pow(2, length - 1 - i);
				array[i] = bit;
				if (bit) count7++;
				else count4++;
			}
			sum++;
		}
		if (count4 != count7) {
			length += 2;
			output = "";
			for (int i = 0; i < length / 2; i++) output += x4;
			for (int i = 0; i < length / 2; i++) output += x7;
		}
		else {
			for (int i = 0; i < length; i++) {
				if (array[i])output[i] = x7;
				else output[i] = x4;
			}
		}
		delete[] array;
	}
	cout << output << endl;
	/*string s1 = "095764";
	string s2 = "0";
	input = s1 + s2;
	s1.erase(1, 3);
	cout << s1 << endl;*/

	return true;
}

bool MachuPicchu() {
	int NumOfTowers, NumOfCommand;
	cin >> NumOfTowers >> NumOfCommand;
	int* Reliability = new int[NumOfTowers];
	int** Command =  new int* [NumOfCommand];
	for (int i = 0; i < NumOfTowers; i++) cin >> Reliability[i];
	for (int i = 0; i < NumOfCommand; i++) {
		Command[i] = new int[4];
		int idxCmd;
		cin >> idxCmd;;
		Command[i][0] = idxCmd;
		if (idxCmd == 1) { for (int j = 1; j < 3; j++) cin >> Command[i][j]; }
		if (idxCmd == 2) { for (int j = 1; j < 4; j++) cin >> Command[i][j]; }
	}
	for (int i = 0; i < NumOfCommand; i++) {
		if (*Command[i] == 1) {
			Reliability[Command[i][1]] += Command[i][2];
			for (int j = 0; j < NumOfTowers; j++) cout << Reliability[j]; cout << endl;
		}
		else {
			int max = Command[i][3];
			int first = Command[i][1];
			int last = Command[i][2];
			int count = 0;
			int k;
			int sum = 0;
			int* sumlist = new int[max + 1];
			memset(sumlist, 0, max + 1);
			for (int j = first; j <= last; j++) {
				sumlist[count] = Reliability[j];
				k = count;
				while ((k > 0) && (Reliability[k] < Reliability[k - 1])) {
					int swap = Reliability[k];
					Reliability[k] = Reliability[k- 1];
					Reliability[k - 1] = swap;
				}
				if (count <= max) count++;
			}
			for (int j = 0; j < max; j++) sum += sumlist[j];
			cout << sum << endl;
		}
	}
	for (int i = 0; i < NumOfCommand; i++) delete[] Command[i];
	delete[] Reliability;
	delete[] Command;
	return true;
	
}

