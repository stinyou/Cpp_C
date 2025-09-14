#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct {
    int check;
    float allowed;
    double types;
} syntax;

struct pos3d {
    int x;
    int y;
    int z;
};

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int cnt(char *str, char c) {
    int i = 0;
    int num = 0;
    while(str[i]) {
        if (str[i] == c) num++;
        i++;
    }
    return num;
}

char *cncat(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *newstr = malloc((len1+len2+1)*sizeof(char));
    *newstr = '\0';
    strcat(newstr, str1);
    strcat(newstr, str2);
    return newstr;
}

struct node {
    int value;
    struct node * link;
};

struct base {
    struct node * head;
};

int main(void) {
    struct pos3d p1 = {1,2,3};
    struct pos3d p2 = {4,5,6};
    struct pos3d poly[3] = {p1,p2};
    printf("%d\n", poly[2].x);
    printf("%d\n", (poly+1)->y);
    
    int *j = malloc(sizeof(int));
    *j = 42;
    int *k = j;
    *k = 43;
    free(j);

    char a[] = "T0\0 much fu\n";
    printf("%zu\n", sizeof(a));
    char s1[2] = {'h', 'i'};
    char s2[2] = {'h', 'i'};
    // if (strcmp(s1, s2) == 0) printf("equal\n");
    // else printf("not equal\n");
    if (s1 == s2) printf("ha\n");
    else printf("oh no\n");
    char s3[20] = "abcde";
    char s4[] = "ABCDE";
    strcat(s3, s4);
    printf("%s\n", s3);
    char s5[] = "abcde";
    // strcat(s4, s5);
    // printf("%s\n", s4);
    char *s6 = "hi";
    // string literal s6[0] = 'i';
    syntax discover = {1, -1.0, 2.9991};
    printf("%d %f %f\n", discover.check, discover.allowed, discover.types);

    int x = 0;
    int y = 10;
    printf("%d %d\n", x, y);
    swap(&x, &y);
    printf("%d %d\n", x, y);

    // int *p = 123;
    // printf("%d\n", p);
    // printf("%d\n", *p);
    
    int l[5];
    printf("%p\n", l);
    printf("%p\n", l+1);
    printf("%p\n", &l);
    printf("%p\n", &l+1);

    syntax * practice = malloc(sizeof(syntax));
    practice->allowed = 12.1;
    practice->types = -1.02;
    practice->check = 0;
    free(practice);

    char *word = "Hello World";
    int o = cnt(word, 'o');
    printf("%d\n", o);

    // char undefined[] = {'T','e','s','t'};
    // printf("%s\n", undefined);

    char str1[] = "A";
    char str2[] = "word";
    char *new1 = cncat(str1, " ");
    char *new2 = cncat(new1, str2);
    free(new1);
    printf("%s\n", new2);
    free(new2);

    return 0;
}