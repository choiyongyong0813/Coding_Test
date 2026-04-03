#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// included_len은 배열 included의 길이입니다.
int solution(int a, int d, bool included[], size_t included_len) {
    int answer = 0;

    // i = 0 → 1항, i = 1 → 2항 ...
    for (int i = 0; i < included_len; i++) {

        // 포함해야 하는 항만 더함
        if (included[i]) {

            // i번째 항 계산
            // a: 첫째항
            // d: 공차
            // i: 0-based index → (i+1)항이 아니라 (i번째 계산은 a + i*d)
            int term = a + (i * d);

            answer += term;
        }
    }

    return answer;
}