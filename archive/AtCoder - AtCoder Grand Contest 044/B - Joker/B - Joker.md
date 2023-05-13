# Solution

## From the [official solution](https://img.atcoder.jp/agc044/editorial.pdf)

For each $1 \leq i \leq N^2$, we compute the minimum number of viewers that
will hate viewer $i$ forever (the answer is the sum of these values).

This number coincides with the minimum cost of a path from the seat of viewer
$i$ to the sides of the square, considering that going through an empty seat has
cost 0 and going through an occupied seat has cost 1

Let $H_k(i)$ be the minimum cost (as defined above) of a path from the seat of
viewer $i$ to the outside after the first k viewers have left the cinema.

Our strategy is to keep all values $H_k(i)$ updated at all times. When the
viewer $P_k$ goes away, we perform a DFS starting from the seats of $P_k$ and
updating the values. During the $k^{th}$ DFS, we will visit only the seats i such
that $H_k(i) < H_{k - 1}(i)$, hence the total number of seats visited in the $N^2$
steps (for $1 \leq k \leq N^2$) is $O(N^3)$ (see key observation)

### **Key observation**

The values $H_k(i)$ are decreasing (for all a $k$).
At the beginning we have:

$$H_0(1) + H_0(2) + \dots + H_0(N^2) \approx \frac{N^3}{6}$$

Because we visit seats will strictly decreasing value of $H$, and since the
sum of all $H$ are $O(N^3)$, we visit at most $O(N^3)$ seats for updating
