#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int gcd(int a, int b){
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int lcm(int a, int b){
    return a / gcd(a,b) * b;
}

// signals_rows는 2차원 배열 signals의 행 길이, signals_cols는 2차원 배열 signals의 열 길이입니다.
int solution(int** signals, size_t signals_rows, size_t signals_cols) {

    int cycles[5];
    int limit = 1;

    // 각 신호등 주기 계산 + 전체 LCM
    for(int i=0;i<signals_rows;i++){
        int G = signals[i][0];
        int Y = signals[i][1];
        int R = signals[i][2];

        cycles[i] = G + Y + R;
        limit = lcm(limit, cycles[i]);
    }

    // 시간 탐색
    for(int t=1; t<=limit; t++){

        bool allYellow = true;

        for(int i=0;i<signals_rows;i++){

            int G = signals[i][0];
            int Y = signals[i][1];
            int cycle = cycles[i];

            int pos = (t-1) % cycle + 1;

            if(!(pos > G && pos <= G + Y)){
                allYellow = false;
                break;
            }
        }

        if(allYellow)
            return t;
    }

    return -1;
}