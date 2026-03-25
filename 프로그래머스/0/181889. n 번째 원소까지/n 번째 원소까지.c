#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len, int n) {
    
    // 1. n개의 int를 담을 만큼 메모리 할당
    // sizeof(int) * n → int n개 공간 확보
    int* answer = (int*)malloc(sizeof(int) * n);
    
    // 2. 앞에서부터 n개 복사
    for (int i = 0; i < n; i++) {
        answer[i] = num_list[i];
    }
    
    // 3. 결과 배열 반환
    return answer;
}