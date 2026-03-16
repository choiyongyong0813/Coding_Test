#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// bandage_len은 배열 길이
// attacks_rows는 2차원 배열 행 길이
// attacks_cols는 열 길이
int solution(int bandage[], size_t bandage_len, int health,
             int** attacks, size_t attacks_rows, size_t attacks_cols) {

    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];

    int maxHealth = health;
    int curHealth = health;

    int attackIdx = 0;
    int lastTime = attacks[attacks_rows-1][0];

    int success = 0;

    for(int time = 1; time <= lastTime; time++) {

        // 공격 발생
        if(attackIdx < attacks_rows && attacks[attackIdx][0] == time) {

            curHealth -= attacks[attackIdx][1];
            if(curHealth <= 0)
                return -1;

            success = 0;
            attackIdx++;
        }
        else {

            success++;
            curHealth += x;

            if(success == t) {
                curHealth += y;
                success = 0;
            }

            if(curHealth > maxHealth)
                curHealth = maxHealth;
        }
    }

    return curHealth;
}