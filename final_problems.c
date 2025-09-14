#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <assert.h>

int *rotateArray (int *arr, int size, int k) {
    if (k <= 0) return arr;
    int temp = arr[size-1];
    for (int i = size-1; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
    return rotateArray(arr, size, k-1);
}

char *repeat(char *str, int n) {
    int len = strlen(str);
    if (len == 0) return str;
    if (n <= 0) return str;
    char *repeatedstr = malloc((len*n+1)*sizeof(char));
    repeatedstr[0] = '\0';
    for (int i = 0; i < n; i++) strcat(repeatedstr, str);
    return repeatedstr;
}

int substring(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (int i = 0; i <= len2 - len1; i++) {
        for (int j = 0; j < len1 && str2[i+j] == str1[j]; j++) {
            if (j == len1-1) return 1;
        }
    }
    return 0;
}

int longestpalindrome_h(char *str, int start, int end, int lower, int upper, int value) {
    if (lower < start || upper > end) return value;
    if (lower == upper) return longestpalindrome_h(str, start, end, lower-1, upper+1, value+1);
    if (str[lower] == str[upper]) return longestpalindrome_h(str, start, end, lower-1, upper+1, value+2);
    return value;
}

int longestpalindrome(char *str, int start, int end) {
    int max_value = 0, value;
    for (int i = start; i <= end; i++) {
        value = longestpalindrome_h(str, start, end, i, i, 0);
        if (value > max_value) max_value = value;
    }
    for (int i = start; i < end; i++) {
        value = longestpalindrome_h(str, start, end, i, i+1, 0);
        if (value > max_value) max_value = value;
    }
    return max_value;
}

int main(void) {

    int rotate[5] = {1, 2, 3, 4, 5};
    rotateArray(rotate, 5, 2);
    for (int i = 0; i < 5; i++) printf("%d ", rotate[i]);
    printf("\n");
    
    char *str = "Testing123";
    char *hehehe = repeat(str, 3);
    printf("%s\n", hehehe);
    free(hehehe);
    char *str2 = malloc(6*sizeof(char));
    str2[0] = '\0';
    strcat(str2, "Hello");
    hehehe = repeat(str2, 5);
    printf("%s\n", hehehe);
    free(str2);
    free(hehehe);

    char *substr1 = "Justin";
    char *substr2 = "JustinYou";
    char *substr3 = "Justin";
    char *substr4 = "HelloJustinYou";
    if (substring(substr1, substr2)) printf("Yippee!\n");
    if (substring(substr2, substr1)) printf("Oh noooo :(\n");
    if (substring(substr1, substr3) && substring(substr3, substr1)) printf("Awesome!\n");
    if (substring(substr1, substr4) && substring(substr2, substr4) && !substring(substr4, substr2)) printf("Cooked!\n");

    assert(6 == longestpalindrome("111111", 0, 5));
    assert(7 == longestpalindrome("abbbcxyzazyxbba", 0, 14));
    assert(1 == longestpalindrome("a", 0, 0));
    assert(6 == longestpalindrome("aaa77777jbbbbbboh666aaa", 0, 23));
    assert(6 == longestpalindrome("abccbacba", 0, 8));
    assert(3 == longestpalindrome("aaa77777jbbbbbboh666aaa", 0, 4));
    assert(5 == longestpalindrome("aaa77777jbbbbbboh666aaa", 0, 7));
    assert(5 == longestpalindrome("aaa77777jbbbbbboh666aaa", 9, 13));

    return 0;
}