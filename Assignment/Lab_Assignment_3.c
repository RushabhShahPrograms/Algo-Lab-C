/*
Name: Shah Rushabh Rupambhai
Roll Number: 202363006
*/

#include <stdio.h>
#include <string.h>

/*
  Function checks if a given string is a palindrome
 
  s The input string
  l The starting index of the string
  r The ending index of the string
  return 1 if the string is a palindrome, 0 otherwise
 */
int partA(char s[], int l, int r) {
    int i, m = (r + l + 1) / 2; // Calculate the midpoint of the string

    while (m <= r) { // Check each pair of characters from the middle to the ends of the string
        if (s[l] != s[m]) { // If any pair of characters is not equal, it's not a palindrome
            return 0;
        }

        l++;
        m++;
    }

    return 1; // If all pairs of characters are equal, it's a palindrome
}

/*
  Function checks if a given string belongs to the language L* (the set of all strings that can be formed by concatenating any number of strings from the language L)
 
  s The input string
  l The starting index of the string
  r The ending index of the string
  n The length of the input string
  dp A dynamic programming array to store intermediate results
  return 1 if the string belongs to L*, 0 otherwise
 */
int partB(char s[], int l, int r, int n, int *dp) {
    int index = l * n + r; // Calculate the index in the dynamic programming array

    if (dp[index] != -1) { // Check if the result for this substring has already been calculated
        return dp[index];
    }

    if (n - r == 1) { // Base case: If the substring is of length 1, it belongs to L*.
        dp[index] = partA(s, l, r);
        return dp[index];
    }

    if (partA(s, l, r) == 0) { // If the substring is not a palindrome, it does not belong to L*.
        dp[index] = partB(s, l, r + 2, n, dp);
        return dp[index];
    } else { // If the substring is a palindrome, it could belong to L* in two ways:
        dp[index] = partB(s, l, r + 2, n, dp) || partB(s, r + 1, r + 2, n, dp); // Either by splitting it into two palindromes
        return dp[index];                                                 // or by adding the next character to the palindrome
    }
}

int main(void) {
    char s[5000]; // Declare a character array to store the string
    printf("Enter the string: ");
    scanf("%s", s); // Read the input string

    int n = strlen(s); // Calculate the length of the string

    if (n % 2 == 1) { // Check if the length of the string is odd
        printf("NO"); // If odd, the string cannot belong to L*
        return 0;
    }

    int dp[n * n]; // Declare a dynamic programming array to store intermediate results
    for (int i = 0; i < n * n; i++) {
        dp[i] = -1; // Initialize all values in the dp array to -1 (indicating no result calculated yet)
    }

    if (partB(s, 0, 1, n, dp)) {
        printf("YES"); // If the recursive function returns 1, the string belongs to L*.
    } else {
        printf("NO"); // If the recursive function returns 0, the string does not belong to L*.
    }
    return 0;
}

/*
1. Enter string: bbbbababbaabbaababaaabaa
Yes
2. Enter string: bbaabbaaaaba
No
3. Enter string: aaabbb
No
4. Enter string: aabb
Yes
5. Enter string: abcdabcdjjkk
Yes
6. Enter string: lklkjh
No
7. Enter string: tyujkltyu
No
*/
