#include <stdio.h>
#include <string.h>

// Function to find the length of the Longest Common Subsequence and store the solution in table b
int lcs_length(char *X, char *Y, int *b) {
    int m = strlen(X);
    int n = strlen(Y);

    int c[(m + 1)][(n + 1)];

    // Build the LCS matrix and the direction table in a bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
                b[i * (n + 1) + j] = 0; // Assuming b is a 1D array representing a 2D table
            } else if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i * (n + 1) + j] = 1; // "↖"
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i * (n + 1) + j] = 2; // "↑"
            } else {
                c[i][j] = c[i][j - 1];
                b[i * (n + 1) + j] = 3; // "←"
            }
        }
    }

    return c[m][n];
}

// Function to print the LCS based on the direction table b
void print_lcs(char *X, int *b, int i, int j, int n) {
    if (i == 0 || j == 0)
        return;
    
    if (b[i * (n + 1) + j] == 1) {
        print_lcs(X, b, i - 1, j - 1, n);
        printf("%c ", X[i - 1]);
    } else if (b[i * (n + 1) + j] == 2) {
        print_lcs(X, b, i - 1, j, n);
    } else {
        print_lcs(X, b, i, j - 1, n);
    }
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    int b[(m + 1) * (n + 1)]; // Direction table
    int length = lcs_length(X, Y, b);
    printf("Length of LCS is %d\n", length);

    printf("LCS is: ");
    print_lcs(X, b, m, n, n);
    return 0;
}

/*
Output:
Length of LCS is 4
LCS is: G T A B
*/
