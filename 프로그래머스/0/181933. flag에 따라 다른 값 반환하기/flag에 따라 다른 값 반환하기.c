#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, bool flag) {
    // flag가 true면 a + b, false면 a - b 반환
    if (flag) {
        return a + b;
    } else {
        return a - b;
    }
}
