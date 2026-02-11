#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다.
char* solution(const char* myString) {
    // 문자열 길이 계산
    size_t len = strlen(myString);

    // 널 문자 포함하여 메모리 할당
    char* answer = (char*)malloc(len + 1);

    // 한 글자씩 복사하면서 대문자로 변환
    for (size_t i = 0; i < len; i++) {
        // 소문자라면 대문자로 변환
        if (myString[i] >= 'a' && myString[i] <= 'z') {
            answer[i] = myString[i] - ('a' - 'A');
        } else {
            answer[i] = myString[i];
        }
    }

    // 문자열 끝 표시
    answer[len] = '\0';

    return answer;
}