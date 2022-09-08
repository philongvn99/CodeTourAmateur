#pragma once
#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<string.h>
#include<array>
using namespace std;

int ROX(){
    int n, q, x, y, sum_xor = 0;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> y;
        sum_xor ^= y;
    }
    
    if(n % 2) {
        for (int i = 0; i < q; i++) {
        cin >> x;
        sum_xor ^= x;
        }
        cout << sum_xor << endl;
    }
    else cout << sum_xor << endl;
    return 0;
}

int JerryPasswords() {
    int t;
 	string s;
    cin >> t;
    bool appear[10];
    for(int i = 0; i < t; i++){
        for(int j = 0; j < 10; j++) appear[j] = false;
        cin >> s;
        int lenS = s.length()-1;
        while(lenS >= 0) {
            int idx = int(s[lenS]) - '0';
            if(appear[idx]) break;
            else {appear[idx] = true;}
            lenS--;
        }
        cout << lenS + 1 << endl;
    }
    return 0;
}

int SUM() {
    int M, N, K, Q;
    cin >> M >> N >> K;
    vector< vector<int> > agri( M , vector<int> (N, 0)); 
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> agri[i][j];
        }
        cin >> Q;
    }
    return 0;
}

int ARRAY() {
    unsigned short int n;
    cin >> n;
    unsigned int* arr = new unsigned int [n];
    int appearance[10000] = { 0 };
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        appearance[arr[i]]++;
    }
    for(int i = 0; i < n; i++) {
        cout <<  appearance[arr[i]] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}

// 11
// 1 5 3 5 7 1 6 2 8 9 1