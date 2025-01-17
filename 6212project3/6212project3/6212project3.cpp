﻿#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
#include <iostream>
#include <algorithm>




using namespace std;
#define MAX_NUM 100
#define M1 5
#define M2 5
void lcs(char* s1, char* s2, int m, int n)
{
    int L[MAX_NUM][MAX_NUM] = {};
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    int index = L[m][n];
    char lcs[MAX_NUM];
    lcs[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs[index - 1] = s1[i - 1];
            i--; j--; index--;    
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    cout << "LCS Length: "<< L[m][n] << endl;
    cout << "LCS string: "<<lcs<<endl;
}

int main()
{
    char s1[M1] = {'A','b','C','d'};
    char s2[M2] = {'A','d'};
    srand(time(NULL));

    cout <<"string 1: "<< s1 << endl;
    cout <<"string 2: "<< s2 << endl;


    int m = strlen(s1);
    int n = strlen(s2);
    lcs(s1, s2, m, n);
    return 0;
}




