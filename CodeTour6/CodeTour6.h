#pragma once
#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<string.h>
using namespace std;

template <typename T, std::size_t N>
void print_array(const T(&a)[N])
{
  cout << "{";
  for (std::size_t i = 0; i < N-1; ++i)
  {
    cout << a[i] << ", ";
  }
  cout << a[N-1] << "}\n";
}

// =========================== COUNT ARRAYS PROBLEM =================================================

//  As I has awared, for each line of test:
//  With value N as 1st input:
//      Length of A is 2N and B's is 2N+1
//      Number of Permutation is calculated easily as:
//          (2N)! / (N! * N!) --> NoP
//  With value K as 2nd input:
//  If K is odd, no permutation satisfies conditions
//  If K is even, number of permatations satisfying conditions is NoP / (N + 1)
//  Any one have

// Display vector elements
void displayVector(vector<int> a, int * b, int n, int s){
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << "   ";
    for(int i=0;i<=n;i++) cout << b[i] << " ";
    cout << "  " << s <<  endl;
}

void showArrayManipulation() {
    int halfLen;
    cin >> halfLen;

    vector<int> arrayA(halfLen * 2);            // Array A
    int* arrayB = new int [2 * halfLen + 1];    // Array B
    int cnt = 0;                                // Counting number of permutations
    arrayB[0] = 0;

    // Generate Base Array A 
    for(int i=0; i < 2 * halfLen; i++){
        if (i < halfLen) arrayA[i] = -1;
        else arrayA[i] = 1;
    }

    do{
        //Display the current permutation
        int sum_ = 0;
        for (int i = 1; i <= 2 * halfLen; i++) {
            arrayB[i] = arrayB[i - 1] + arrayA[i - 1];
            if (arrayB[i] < 0 || arrayB[i-1] < 0) sum_ += 1;
        }
        cnt++;
        displayVector(arrayA, arrayB, halfLen * 2, sum_);

    }while(next_permutation(arrayA.begin(), arrayA.end()));
    cout << cnt << endl;

    delete[] arrayB;
}

void CountArrays() {
    int numOfTests, halfLen, val;
    cin >> numOfTests;
    for(int i = 0; i < numOfTests; i++) {
        cin >> halfLen >> val;
        if (val % 2) cout << 0 << endl;
        else {
            if (val <= 2 * halfLen) {
                int mult = 1;
                for(int j = 2*halfLen; j > 1; j--) {
                    if(j > halfLen) mult *= j;
                    else mult /= j;
                }
                cout << mult << " " << halfLen << " " << mult/(halfLen + 1) << endl;;
            }
            else cout << 0 << endl;
        }
    }
}


// =========================== GAMES OF STONES =================================================

// With each N value as number of bubbles for each test:
//  -   for all value i for i^2 < N:
//  -   -   if any winner of case N - i^2 is B
//  -   -   else A
// So, with T testcases, we will find the biggest N value as N_max
// Then generate array (vector) VT with length N_max
// Each value in vector VT is initialized as 0
// We will iterate through VT by index <idx>, and number of bubbles is N:
//  -   if idx is square perfect, VT[idx] = 1
//  -   if VT[idx] = 0 when we reach it, 
//  -   -   with every i that idx + i^2 <= N,
//  -   -   VT[idx + i^2] = 1

int GameOfStones() {
    int numOfTests, maxTest = 0, sqroot = 2;
    cin >> numOfTests;
    vector<int> test(numOfTests);
    for (int i = 0; i < numOfTests; i++){
        cin >> test[i];
        if (test[i] > maxTest) maxTest = test[i];
    }
    vector<int> win(maxTest + 1);
    win[0] = 1;
    win[1] = 1;
    for(int i = 2; i <= maxTest; i++){
        if(i == sqroot * sqroot) {
            win[i] = 1;
            sqroot++;
            continue;
        }
        if(win[i] == 0){
            int j = 1;
            while(maxTest >= i + j * j){
                win[i + j * j] = 1;
                j++;
            }
        }
    }
    
    for(int i=0; i < numOfTests; i++) {
        cout << test[i] << " " << win[test[i]] << endl;
    }
    return 0;
}

// =========================== LOVE MATRIX =================================================
int LoveMatrix() {
    int numOfTests, nRows, nCols, cell;
    cin >> numOfTests;
    for(int i = 0; i < numOfTests; i++) {
        cin >> nRows >> nCols;

        // Love-Matrix 2D Vector
        vector< vector<int> > s2matrix(nRows, vector<int>(nCols + 1));

        // First of all,
        // We get input of Love Matrix cell by cell
        // For each cell, 
        // Mapping value to 2D Array is summary from its head of row to it,
        // By adding new value to a summary called current-summary
        // If value is odd, current-summary is reset to 0
        // Complexity: O(N)
        for(int rs = 0; rs <  nRows; rs++) {
            for(int cs = 1; cs <= nCols; cs++) {
                cin >> cell;
                if (cell % 2) {s2matrix[rs][cs] = INT_MIN;}
                else if (s2matrix[rs][cs-1] == INT_MIN) s2matrix[rs][cs] = cell;
                else { s2matrix[rs][cs] = s2matrix[rs][cs-1] + cell; }
            }
        }


        // Now we iterate through every cell in 2D Vector;
        // Firstly, we generate a total  maximum summary variable
        // We select horitzontal direction as base one, then we loop through segment of a row
        // To generate a segment, we select a beginning (called cs) then go though end-point (called ls-cs) by ls_cs <= cs
        // Then for each segment, 
        //  +   We will traverse every sub-2D-vector with the corresponding basis horizontal line
        //  +   Each segment has a segment-summary-run (SSR) initialized by 0
        //  +   For each row in sub-2d-vector,
        //  +   +   sum-of-row is added to SSR, sum-of-row is calculated by subtract  immedieately-befored cell from last cell
        //  +   +   if SSR < 0, reset to 0
        //  +   +   else if SSR > totally maximum summary, assign new greater value!
        //  If we reach a marked odd cell, mark its row index as a reset-line for corresponding beginning point cs 
        //  Complexity: O(N^3)
        int maxSum = INT_MIN;
        int prv_sum = 0;
        for (int cs=1; cs <= nCols; cs++) {
            vector<bool> rstRows(nRows);
            for (int ls_cs=cs; ls_cs <= nCols; ls_cs++) {
                int currMax = 0;
                for (int rs = 0; rs < nRows; rs++) {
                    if (!rstRows[rs]){
                        if (s2matrix[rs][ls_cs] == INT_MIN) {currMax = 0; rstRows[rs] = true; continue;}

                        if(s2matrix[rs][cs-1] != INT_MIN) prv_sum = s2matrix[rs][cs - 1];
                        else prv_sum = 0;
                        currMax += s2matrix[rs][ls_cs] - prv_sum;

                        if (currMax < 0) {currMax = 0; continue;}
                        if (currMax > maxSum) maxSum = currMax;
                    }
                    else currMax =0;
                }
            }
        }
        cout << " " <<  maxSum << endl;
    }
    return 0;
}

/*
1
4 5
2 3 3 4 7
1 -2 2 3 8
6 9 6 4 6
1 -12 3 3 1
*/


// =========================== MELODY =================================================
int Melody() {
    unsigned short int numOfChords, numOfNotes, notePitch, currAppIdx = 0, prevAppIdx = 1, sml, rqSML;
    cin >> numOfChords;
    vector< vector<bool>> chordsAppearance(2, vector<bool> (7, false));
    for (unsigned short int i = 0; i < numOfChords; i++){
        cin >> numOfNotes;
        sml = 0; // similar notes
        rqSML = (int) numOfNotes / 2; // required number of similars

        for (unsigned short int j = 0; j < numOfNotes; j++) {
            cin >> notePitch;
            chordsAppearance[currAppIdx][notePitch % 7] = true; 
            if(chordsAppearance[prevAppIdx][notePitch % 7]) {
                chordsAppearance[prevAppIdx][notePitch % 7] = false;
                sml++; 
            }
        }

        if(sml < rqSML && i > 0){
            cout << i << " " << sml << " " << rqSML << endl;
            cout << "unTRENDING !!!" << endl;
            return 0;
        }

        currAppIdx = prevAppIdx;
        prevAppIdx = 1 - prevAppIdx;
        for (unsigned short int j = 0; j < 7; j++) chordsAppearance[currAppIdx][j] = false;
    }
    cout << "TRENDING!!!" << endl;
    return 0;
}

/* TRENDing
5
2 1 10
3 2 5 8
6 12 1 6 1 2 5
3 11 20 31
4 87 6 4 2
*/

/* unTRENDing
5
2 1 10
3 2 5 8
6 12 1 6 1 2 5
4 11 20 31 6
4 87 6 4 2
*/