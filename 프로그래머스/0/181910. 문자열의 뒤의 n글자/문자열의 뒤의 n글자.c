#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다.
char* solution(const char* my_string, int n) {
    size_t len = strlen(my_string);

    // 결과 문자열은 n글자 + 널문자
    char* answer = (char*)malloc(n + 1);

    // 시작 위치 = 전체 길이 - n
    size_t start = len - n;

    // n글자 복사
    for (int i = 0; i < n; i++) {
        answer[i] = my_string[start + i];
    }

    // 문자열 끝 표시
    answer[n] = '\0';

    return answer;
}