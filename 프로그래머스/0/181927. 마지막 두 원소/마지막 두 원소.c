#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len) {
    // 결과 배열은 기존 길이 + 1
    int* answer = (int*)malloc(sizeof(int) * (num_list_len + 1));

    // 기존 배열 값 복사
    for (size_t i = 0; i < num_list_len; i++) {
        answer[i] = num_list[i];
    }

    // 마지막 원소와 그 전 원소
    int last = num_list[num_list_len - 1];
    int prev = num_list[num_list_len - 2];

    // 조건에 따라 마지막 값 추가
    if (last > prev) {
        answer[num_list_len] = last - prev;
    } else {
        answer[num_list_len] = last * 2;
    }

    return answer;
}
