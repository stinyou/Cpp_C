#include <stdio.h>
#include <assert.h>

// 3

void doit(int n){
    for (int i=n; i>=1; i--){
        printf("*");
    for (int j=1; j<=i; j++)
        printf("@");
        printf("*\n");
    }
}

// 5

int replacedigit_h(int num, int olddigit, int newdigit, int newnum, int mult);
int replacedigit(int num, int olddigit, int newdigit) {
    return replacedigit_h(num, olddigit, newdigit, 0, 1);
}

int replacedigit_h(int num, int olddigit, int newdigit, int newnum, int mult) {
    if (num == 0) {
        return newnum;
    }
    if (num % 10 == olddigit) {
        newnum  += newdigit * mult;
        replacedigit_h(num/10, olddigit, newdigit, newnum, mult*10);
    }
    else {
        newnum += (num % 10) * mult;
        replacedigit_h(num/10, olddigit, newdigit, newnum, mult*10);
    }
}

// 6

void fun(int n){
    if (n>0){
        printf("%d",n%10);
        fun(n/10);
    }
}

// 8
int tailrec(int n, int cnt) {
if (n == 0) return cnt;
return tailrec (n/10, cnt+1);
}
// The recursive function reccount takes a non negative integer and
// returns the number of digits.
int reccount(int n){
if (n==0) return 1;
return tailrec(n/10, 1);
}
// The function count takes a non negative integer and
// returns the number of digits.
int count(int n){
if (n==0) return 1;
int cnt = 0;
while (n>0){
n/=10;
cnt++;
}
return cnt;
}
// The function forcount takes a non negative integer and
// returns the number of digits.
int forcount(int n){
if (n==0) return 1;
int cnt;
for (cnt = 0; n > 0; n /= 10)
cnt++;
return cnt;
}

// 9
int cube(int n) {
    return n*n*n;
}

int main(void) {

    // 3
    doit(6);

    /*
    // 4
    int index = 0, min_value, min_frequency, max_value, max_frequency, n;
    while (scanf("%d", &n)) {
        index++;
        if (index == 1) {
            min_value = n; min_frequency = 1; max_value = n; max_frequency = 1;
        }
        else {
            if (n < min_value) {
                min_value = n; min_frequency = 1;
            }
            else if (n == min_value) min_frequency++;
            else if (n > max_value) {
                max_value = n; max_frequency = 1;
            }
            else if (n == max_value) max_frequency++;
        }
    }
    if (index == 0) printf("No integer given");
    else printf("(%d,%d)(%d,%d)\n", min_value, min_frequency, max_value, max_frequency);
    */
   
    // 5
    assert(replacedigit(1,9,8)==1);
    assert(replacedigit(1,1,7)==7);
    assert(replacedigit(13945,9,0)==13045);
    assert(replacedigit(444444,4,0)==0);
    assert(replacedigit(7137457,7,0)==130450);
    assert(replacedigit(110111001,0,1)==111111111);

    // 6
    fun(1230);

    // 8
    assert(1==count(0));
    assert(3==count(137));
    assert(8==count(18700087));
    assert(1==reccount(0));
    assert(3==reccount(137));
    assert(8==reccount(18700087));
    assert(1==forcount(0));
    assert(3==forcount(137));
    assert(8==forcount(18700087));

    // 9
    for (int i = 1; i < 10000; i++) {
        int possible = 0;
        for (int j = 1; cube(j) < i; j++) { if (possible) break; 
            for (int k = 1; k < j; k++) { if (possible) break;
                for (int l = 1; l < k; l++) {
                    if (i == cube(j) + cube(k) + cube(l)) possible++;
                    if (possible) break;
                }
            }
        }
        if (possible) printf("%d\n", i);
    }

    return 0;
}
