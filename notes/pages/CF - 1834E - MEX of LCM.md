link:: https://codeforces.com/contest/1834/problem/E
rating::
tag::

	- ## Trackers
		- ### Initial
			- TODO Thinking
			- TODO Coding
	- ## Problem statement
		-
	- ## Observation
		- The answer is < 2e7 (the millionth prime number is around 1.5e7)
			- If a prime number is not in the array, no sub array lcm will be equal to that prime number
		- Consider 2 range $[l, r]$ and $[l + 1, r]$, it's always true that $lcm([l, r]) \geq lcm([l + 1, r])$.
	- ## Solution
		- For every right end $r$, compute all possible distinct lcm and store it into a set
			- possible mean that the lcm is less than 2e7
			- because the lcms are distinct, for every $r$ there are at most $log_2(10^7)$ possible lcm
		- Then iterate from 1 -> 1e7, and check if the current number is in the set or not
	- ## Note
		-