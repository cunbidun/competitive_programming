tags:: #dp
rating:: #cf-2200
link:: https://codeforces.com/problemset/problem/1542/D

- ## Variables
  1. Let $a$ is the input array, $a[i]$ is either equal to '-' or a positive number
  2. Let $N$ is the size of $a$
## High-level idea
1. Because the number of subsets is enormous, 
instead of finding all the subsets, let's calculate the contribution of each element.
Elements will contribute to the sum when it remains in the priority queue after all operations are carried out.

2. Let $f[i][k]$ = the number of subsets such as, after carry out all the operations,
$a[i]$ is the $k^{th}$ smallest elements in the priority queue.

3. The number of times $a[i]$ remains in the queue is equal to $f[i][1] + \cdots + f[i][N]$, 
so the contribution of $a[i]$ to the total sum is $a[i] \cdot (f[i][1] + \cdots + f[i][N])$
## Low-level detail
Let's fix $i$ and calculate $f[k]$ for $k = 1 \rightarrow N$. To calculate $f[k]$, we will need
other dimension. Let's $f[j][k]$ is the number of subsets if we only
consider the first $j$ elements, such as after perform all operations, $a[i]$ is the $k^{th}$ smallest elements.

Denote $f[j][0]$ = number of subset if we only
consider the first $j$ elements, such as after perform all operations the priority queue is empty.

We have:

1. $f[0][0] = 1$ 
2. $f[j][k] += f[j - 1][k]$ if $i \neq j$. If we decide to skip $a[j]$ (we can't skip $a[i]$) 
2. $f[j][k] += f[j - 1][k]$ if $a[i] < a[j]$ or ($a[i] = a[j]$ and $i < j$. If we add something greater than $a[i]$, 
nothing will change.
4. $f[j][k] += f[j - 1][k - 1]$ if $a[j] < a[i]$ or ($a[j] = a[i]$ and $j \leq i)$. If we add
something that less than $a[i]$, the position of $a[i]$ will increase
5. $f[j][k] += f[j - 1][k + 1]$ if $a[j]$ = '-'. If we add a minus sign, the postion of $a[i]$ will decrease.
6. $f[j][0] = f[j - 1][1] + f[j - 1][0]$ if $a[j]$ = - and $j \leq i$. We can't make the 
queue empty after selecting $a[i]$.