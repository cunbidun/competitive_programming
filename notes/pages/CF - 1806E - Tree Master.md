link:: https://codeforces.com/contest/1806/problem/E
rating:: #2200
tag::

	- ## Problem statement
		-
	- ## Observation
		- First observation is, there is no better way to compute the requested operation with better time complexity. So it's likely that the solution will be brute force + memorization
		- Note that time and space complexity is quite big for $N < 10^5$
	- ## Solution
		- For each query, we can just brute force compute the sum by jumping to the both parent. Let's also memorize the answer for each pair we visit so that we don't have to recompute next time.
		- The time complexity is the possible number of pair that we will have to visit.
		- Let's $s[i]$ be the list of node with depth $i$
		- When make a query for $u$ and $v$, let $z$ = $lca(u,v)$, we for each $i = lvl[u] \rightarrow lvl[z]$, we will get a pair of numbers. Because each query, we will visit at most 1 pair for each level, so the total time complexity for all level is $\sum{min(q, size(s[i])^2})$
		- Now let's see what is upper bound for this number. Let's $a_i = size(s_i)$, we have $\sum a_i = N$ we have to maximize $\sum{min(q, a_i^2})$. Assume that we have an array $A = a_0, a_1, \cdots, a_x$ and there is $a_i \leq a_j < \sqrt{q}$, we can see that $A'$ will all element of $A$ except $a_i$ replaced by $a_i - 1$ and $a_j$ replaced by $a_j + 1$ will have a better sum. So the best configuration is all $a_i$ except one will be equal to $\sqrt{q}$, and in that case, there will be $\sqrt{q}$ elements. The maximum sum will be $O(q\cdot \sqrt{q})$
		-
		-
	- ## Note
		-
-