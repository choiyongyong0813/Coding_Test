#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20001
#define MAX_WORD 10000

int solution(const char* message, int** spoiler_ranges,
             size_t spoiler_ranges_rows, size_t spoiler_ranges_cols) {

    int len = strlen(message);

    bool spoilerMask[MAX_LEN] = {0};

    // 1️⃣ 스포 구간 표시
    for(int i=0;i<spoiler_ranges_rows;i++){
        for(int j=spoiler_ranges[i][0]; j<=spoiler_ranges[i][1]; j++)
            spoilerMask[j] = true;
    }

    char words[MAX_WORD][50];
    int wordStart[MAX_WORD];
    int wordEnd[MAX_WORD];
    int wordSpoilerCount[MAX_WORD];

    int wordCount = 0;
    int i=0;

    // 2️⃣ 단어 파싱
    while(i<len){

        int start=i;
        int k=0;
        int spoilerCnt=0;

        while(i<len && message[i]!=' '){

            words[wordCount][k++] = message[i];

            if(spoilerMask[i])
                spoilerCnt++;

            i++;
        }

        words[wordCount][k]='\0';

        wordStart[wordCount]=start;
        wordEnd[wordCount]=i-1;
        wordSpoilerCount[wordCount]=spoilerCnt;

        wordCount++;
        i++;
    }

    // 3️⃣ normal 위치 등장 여부
    bool appearNormal[MAX_WORD]={0};

    for(int w=0; w<wordCount; w++){

        bool allNormal=true;

        for(int p=wordStart[w]; p<=wordEnd[w]; p++){
            if(spoilerMask[p]){
                allNormal=false;
                break;
            }
        }

        if(allNormal){
            for(int k=0;k<wordCount;k++){
                if(strcmp(words[w],words[k])==0)
                    appearNormal[k]=true;
            }
        }
    }

    // 4️⃣ 공개 상태 추적
    int revealed[MAX_WORD]={0};
    bool counted[MAX_WORD]={0};

    int answer=0;

    // 스포 구간 순서대로 클릭
    for(int r=0;r<spoiler_ranges_rows;r++){

        int s=spoiler_ranges[r][0];
        int e=spoiler_ranges[r][1];

        for(int w=0; w<wordCount; w++){

            int overlapStart = s > wordStart[w] ? s : wordStart[w];
            int overlapEnd   = e < wordEnd[w] ? e : wordEnd[w];

            if(overlapStart <= overlapEnd){

                // 공개된 문자 증가
                revealed[w] += overlapEnd-overlapStart+1;

                // 단어가 완전히 공개된 순간
                if(revealed[w] >= wordSpoilerCount[w] && !counted[w]){

                    if(wordSpoilerCount[w] > 0 && !appearNormal[w]){

                        bool dup=false;

                        for(int k=0;k<w;k++){
                            if(counted[k] && strcmp(words[k],words[w])==0){
                                dup=true;
                                break;
                            }
                        }

                        if(!dup){
                            answer++;
                        }
                    }

                    counted[w]=true;
                }
            }
        }
    }

    return answer;
}