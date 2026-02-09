#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다.
int solution(const char* ineq, const char* eq, int n, int m) {
    // ">=" 또는 "<="
    if (eq[0] == '=') {
        if (ineq[0] == '>') {
            return n >= m ? 1 : 0;
        } else { // ineq == '<'
            return n <= m ? 1 : 0;
        }
    }
    // ">" 또는 "<"
    else { // eq == '!'
        if (ineq[0] == '>') {
            return n > m ? 1 : 0;
        } else { // ineq == '<'
            return n < m ? 1 : 0;
        }
    }
}
