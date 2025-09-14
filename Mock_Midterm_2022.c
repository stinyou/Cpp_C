#include <stdio.h>
#include <assert.h>

// 3

void pyramid (int n) {
    for (int space = n-1, at = 0; space >= 0; space--, at += 2) {
        for (int i = space; i > 0; i--) printf(" ");
        printf("*");
        for (int j = at; j > 0; j--) printf("@");
        printf("*\n");
    }
    return;
}

// 5

int filterdigit_h(int num, int digit, int filtered, int ten_power);
int filterdigit(int num, int digit) {
    return filterdigit_h(num, digit, 0, 1);
}
int filterdigit_h(int num, int digit, int filtered, int ten_power) {
    if (num == 0) return filtered;
    if (num % 10 != digit) {
        filtered += num % 10 * ten_power;
        filterdigit_h(num / 10, digit, filtered, ten_power * 10);
    }
    else filterdigit_h(num / 10, digit, filtered, ten_power);
}

// 6

void fun(int n){
    if (n>99){
        printf("%d\n", n/10);
        fun(n/10);
        printf("%d\n", n/10);
    }
    else if (n>0) printf("%d\n", n/10);
}

void mystery(int n){
    printf("%d\n", n);
    fun(n);
    printf("%d\n", n);
}

// 8
void flatten(int arr[], int n, int m, int darr[n][m]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i * m + j] = darr[i][j];
}

int main(void) {

    // 3
    pyramid(6);

    /*
    // 4
    int index = 0, min, max, min_index, max_index, n;
    while (scanf("%d", &n)) {
        index++;
        if (index == 1) {
            max = n;
            min = n;
            max_index = index;
            min_index = index;
        }
        else {
            if (n >= max) {
                max = n;
                max_index = index;
            }
            if (n <= min) {
                min = n;
                min_index = index;
            }
        }
    }
    if (index == 0) printf("No integer given\n");
    else printf("(%d, %d)(%d, %d)\n", min, min_index, max, max_index);
    */

    // 5
    assert(filterdigit(1,9)==1);
    assert(filterdigit(1,1)==0);
    assert(filterdigit(13945,9)==1345);
    assert(filterdigit(444444,4)==0);
    assert(filterdigit(7137457,7)==1345);
    assert(filterdigit(110111001,0)==111111);

    // 6
    mystery(123456);

    /*
    // 7
    int array[10] = {0};
    int x;
    while (scanf("%d", &x) && (x > 0)) {
        int unique = 0;
        for (int i = x; i > 0; i /= 10) {
            if (!array[i % 10]) {
                unique++;
                array[i % 10]++;
            }
        }
        if (unique) printf("%d\n", x);
    }
    */

    // 8
    int darr[4][5] = {{1,2,3,4,5},{6,7,8,9,10},
                      {11,12,13,14,15},{16,17,18,19,20}};
    int arr[20] = {0};
    flatten(arr, 4 , 5, darr);
    for (int i=0; i<20; i++) printf("%d ", arr[i]);

    return 0;
}