#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len, int n) {
    // 1) 결과 배열에 들어갈 원소 개수 계산
    //    0, n, 2n, 3n ... 이므로
    //    (num_list_len - 1) / n + 1
    size_t count = (num_list_len - 1) / n + 1;

    // 2) 필요한 크기만큼 동적 할당
    int* answer = (int*)malloc(sizeof(int) * count);

    // 3) n개 간격으로 값 저장
    size_t idx = 0;
    for (size_t i = 0; i < num_list_len; i += n) {
        answer[idx++] = num_list[i];
    }

    return answer;
}
