#include <stdio.h>

int trap_h(int m, int n, int arr[m][n], int x, int y) {
    if ((x==0)||(y==0)||(x==n-1)||(y==m-1)) return arr[x][y];
    if (!arr[x][y]) {
        int trap = arr[x][y];
        arr[x][y] = 1;
        if (!trap_h(m, n, arr, x+1, y+1)) return trap;
        if (!trap_h(m, n, arr, x-1, y+1)) return trap;
        if (!trap_h(m, n, arr, x-1, y-1)) return trap;
        if (!trap_h(m, n, arr, x+1, y-1)) return trap;
    }
    return 1;
}

int trap(int m, int n, int arr[m][n]) {
    if (!trap_h(m, n, arr, m/2, n/2)) return 1;
    else return 0;
}

void dspace(int space) {
    if (space == 0) return;
    printf(" ");
    dspace(space-1);
    }

void dstar(int star) {
    if (star == 0) return;
    printf("*");
    dstar(star-1);
}

void gem_helper(int n, int space, int star) {
    if (star <= 0) return;
    dspace(space);
    dstar(star);
    dspace(space);
    printf("\n");
    if (star == 2*n-1) n = 0;
    if (n) gem_helper(n, space-1, star+2);
    else gem_helper(n, space+1, star-2);
}

void gem_r(int n) {
    gem_helper(n, n-1, 1);
    return;
}

void gem(int n) {
    for (int space = n-1, star = 1; space >= 0; space--, star += 2) {
        for (int i = space; i > 0; i--) printf(" ");
        for (int j = star; j > 0; j--) printf("*");
        for (int k = space; k > 0; k--) printf(" ");
        printf("\n");
    }
    for (int space = 1, star = 2*n-3; space < n; space++, star -= 2) {
        for (int i = space; i > 0; i--) printf(" ");
        for (int j = star; j > 0; j--) printf("*");
        for (int k = space; k > 0; k--) printf(" ");
        printf("\n");
    }
}

int factorial_tr(int n, int m) {
    if (m <= 1) return n;
    else return factorial_tr(n*m, m-1);
}

int factorial(unsigned int n) {
    if (n == 0) return 1;
    else return factorial_tr(n, n-1);
}

int main(void) {
    printf("%d\n", factorial(2));

    // Lesson 6 Review
    int a[] = {0 ,1 ,2 ,3};
    int *b = a;
    printf("%d\n", a[0]);
    b[0] = 7;
    printf("%d\n", a[0]);
    
    gem(3);
    gem_r(3);

    int traps[5][7] = {
        {0, 1, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0}
    };
    printf("%d", trap(5, 7, traps));

    return 0;
}