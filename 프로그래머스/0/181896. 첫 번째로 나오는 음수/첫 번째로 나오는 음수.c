#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    
    // 1. 배열을 앞에서부터 순회
    for (size_t i = 0; i < num_list_len; i++) {
        
        // 2. 현재 값이 음수인지 체크
        if (num_list[i] < 0) {
            // 3. 첫 번째 음수 발견 → 즉시 해당 인덱스 반환
            return i;
        }
    }
    
    // 4. 끝까지 음수가 없으면 -1 반환
    return -1;
}