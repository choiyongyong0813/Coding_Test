#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int odd = 0;   // 홀수만 이어 붙인 값
    int even = 0;  // 짝수만 이어 붙인 값

    for (size_t i = 0; i < num_list_len; i++) {
        if (num_list[i] % 2 == 0) {
            // 짝수면 기존 값에 10 곱하고 현재 숫자 추가
            even = even * 10 + num_list[i];
        } else {
            // 홀수면 기존 값에 10 곱하고 현재 숫자 추가
            odd = odd * 10 + num_list[i];
        }
    }

    // 두 값을 더해서 반환
    return odd + even;
}
