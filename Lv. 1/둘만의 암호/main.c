#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* s, const char* skip, int index) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    const int len_s = strlen(s);
    const int len_skip = strlen(skip);
    char* answer = (char*)calloc((len_s+1),sizeof(char));
    for(int i = 0; i<len_s; i++){
        int alpha = s[i];
        for(int j = 0; j<index; j++){
            alpha = alpha + 1;
            if(alpha == 123) alpha = 'a';
            for(int k = 0; k<len_skip;k++){
                if(alpha == skip[k]){
                    alpha = alpha + 1;
                    k = -1;
                    if(alpha == 123) alpha = 'a';
                }
            }
        }
        answer[i] = alpha;
    }
    return answer;
}