"""
author: cunbidun
created: Tuesday, 2022-12-06 18:28:36 CST
tags: best-problem
"""

if __name__ == "__main__":
    MOD = 10**9 + 7
    T = int(input())
    for _ in range(T):
        N, A, B = map(int, input().split())
        # X4 is the number of ways to put A before B in a line that they do not overlap
        X4 = 0
        if N - A - B >= 0:
            X4 = (N - A - B + 1 + 1) * (N - A - B + 1) // 2

        # X4 is the number of ways to put A and B in a line that they do not overlap
        X3 = 2 * X4

        # X2 is the number of ways to put A and B in a line that they overlap
        X2 = (N - A + 1) * (N - B + 1) - X3

        # X1 is the number of ways to put square A and B overlap
        X1 = X2**2

        print(((N - A + 1) ** 2 * (N - B + 1) ** 2 - X1) % MOD)
