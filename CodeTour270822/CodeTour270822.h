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
    int M, N, K, Q, centerR, centerC, runRow, runLeftCol, runRightCol;
    cin >> M >> N >> K;
    vector< vector<unsigned short int> > agri( M + 1, vector<unsigned short int> (N + 1, 0)); 
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cin >> agri[i][j];
            agri[i][j] += agri[i][j-1];
        }
    }

    cin >> Q;
    vector<unsigned short int> value(Q, 0);
    
    for(int i = 0; i < Q; i++){

        cin >> centerR >> centerC;

        runRow = max(centerR - K, 1);


        while((runRow <= M) && (runRow <= centerR + K)) {
            runRightCol = min(centerC + K - abs(centerR - runRow), N);
            runLeftCol = max(centerC - K + abs(centerR - runRow), 1);
            value[i] += agri[runRow][runRightCol] - agri[runRow][runLeftCol - 1];
            runRow++;
        }
    }

    for(int i = 0; i < Q; i++) cout <<  value[i] << endl;

    return 0;
}
/*
4 3 2
1 3 2
2 4 1
3 3 1
5 2 4
2
1 1
4 2
*/

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

/*
11
1 5 3 5 7 1 6 2 8 9 1
*/