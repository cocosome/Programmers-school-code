#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* s, const char* skip, int index) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    const int len_s = strlen(s);
    const int len_skip = strlen(skip);
    //char array[50];
    /*for(int i = 0; i<50;i++)
    {
        printf("array[%d] = %c\n",i,array[i]);
    }*/
    char* answer = (char*)calloc((len_s+1),sizeof(char));
    printf("answer = %s\n",answer);
    for(int i = 0; i<len_s; i++){
        char alpha = s[i];
        printf("alpha[%d] = %c ",i,s[i]);
        for(int j = 0; j<index; j++){
            alpha = alpha + 1;
            if(alpha > 'z') alpha = 'a';
            for(int k = 0; k<len_skip;k++){
                if(alpha == skip[k]){
                    alpha = alpha + 1;
                    if(alpha > 'z') alpha = 'a';
                }
            }
        }
        answer[i] = alpha;
        //strcat(answer,&alpha);
        printf("-> %s\n",answer);
    }
    //strcat(answer,array);
    printf("answer = %s\n",answer);
    return answer;
}

int main()
{   
    char* result = (char*)calloc(50,sizeof(char));
    char* s1 = (char*)malloc(50*sizeof(char));
    char* s2 = (char*)malloc(50*sizeof(char));
    int input;
    scanf("%s %s %d",s1,s2,&input);
    result = solution(s1,s2,input);
    printf("%s\n",result);
    return 0;
}