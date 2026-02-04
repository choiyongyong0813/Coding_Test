#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int sum = 0;      // 모든 원소의 합
    int product = 1; // 모든 원소의 곱

    // 배열 순회
    for (size_t i = 0; i < num_list_len; i++) {
        sum += num_list[i];        // 합 누적
        product *= num_list[i];    // 곱 누적
    }

    // 합의 제곱 계산
    int sumSquare = sum * sum;

    // 조건 비교
    if (product < sumSquare) {
        return 1;
    } else {
        return 0;
    }
}