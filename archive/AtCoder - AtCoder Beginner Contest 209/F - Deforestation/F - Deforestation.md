---
fontfamily: sourcecodepro 
fontsize: 10pt
title: "F - Deforestation"
date: "2021-07-13"
keywords: [2300, dp]
lang: "en"
...

# [F - Deforestation](https://atcoder.jp/contests/abc209/tasks/abc209_f)

## Insertion DP for permutation

Suppose we have to find the number of permutations with size N that satisfy some properties.

$f[i][j]$ is the number of permutations if we only consider the first $i$ elements and 
the last elements is equal to $j$ ($j <= i$). The answer is 
$f[N][1] + f[N][2] + \dots + f[N][N]$

Transition: $F[i][j] = \sum f[i - 1][k]$ for some $k < i$. 

