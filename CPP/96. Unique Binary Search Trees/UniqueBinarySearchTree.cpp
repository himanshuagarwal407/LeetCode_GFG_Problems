// Source: https://leetcode.com/problems/unique-binary-search-trees/
// Autor: Himanshu Agarwal
// Date: 21/01/22

/*

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 
Example 1:
Input: n = 3
Output: 5


Example 2:
Input: n = 1
Output: 1

*/

#include <bits/stdc++.h>

class Solution {
public:
    unsigned long int binomialCoeff(unsigned int n, unsigned int k)
    {
        unsigned long int res = 1;
 
        if (k > n - k)
            k = n - k;
 
        for (int i = 0; i < k; ++i)
        {
            res *= (n - i);
            res /= (i + 1);
        }
 
        return res;
    }
    
    int numTrees(int n) {
        // calculate C(2*n,n)/(n+1)
        unsigned long long c = binomialCoeff(2*n, n);
        
        return c/(n+1);
    }
};
