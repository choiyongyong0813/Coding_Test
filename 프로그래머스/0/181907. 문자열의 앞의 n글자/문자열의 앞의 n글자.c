#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int n) {
    char* answer = (char*)malloc(sizeof(char) * (n + 1));

    // 앞에서 n글자 복사
    strncpy(answer, my_string, n);

    // 문자열 끝 처리
    answer[n] = '\0';
    return answer;
}