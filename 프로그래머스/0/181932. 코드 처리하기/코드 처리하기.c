#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// code 문자열을 조건에 따라 가공하여 결과 문자열 반환
char* solution(const char* code) {
    int len = strlen(code);   // 입력 문자열 길이

    // 결과 문자열은 최대 len까지 가능 (널 문자 포함)
    char* answer = (char*)malloc(len + 1);

    int idx_ans = 0;  // answer에 실제로 채워진 길이
    int mode = 0;     // 시작 mode = 0

    // 문자열 순회
    for (int i = 0; i < len; i++) {

        // '1'이면 mode 토글 (0 ↔ 1)
        if (code[i] == '1') {
            mode = 1 - mode;
            continue; // '1'은 결과에 포함되지 않음
        }

        // mode == 0
        // 짝수 index일 때만 문자 추가
        if (mode == 0) {
            if (i % 2 == 0) {
                answer[idx_ans++] = code[i];
            }
        }
        // mode == 1
        // 홀수 index일 때만 문자 추가
        else {
            if (i % 2 == 1) {
                answer[idx_ans++] = code[i];
            }
        }
    }

    // 결과가 비어있으면 "EMPTY" 반환
    if (idx_ans == 0) {
        free(answer);  // 기존 메모리 해제

        char* empty = (char*)malloc(6); // "EMPTY" + '\0'
        strcpy(empty, "EMPTY");
        return empty;
    }

    // 문자열 끝 처리
    answer[idx_ans] = '\0';

    return answer;
}