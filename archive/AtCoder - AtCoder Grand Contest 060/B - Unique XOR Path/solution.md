# B - Unique XOR Path

## Observations 

1. The problem asks to check wether the given $K$ is "enough" to satisfy the requirements, which also means we need to
the smallest possible number of bits
2. One strategy is to find the a number $A$ that we are certain that $A \leq K$, and construct a valid matrix that 
only uses that $x$ number of bits 
3. We will use the definition of $A$ and the matrix construction is described in the official solution: https://atcoder.jp/contests/agc048/editorial/234
4. Now, now we prove $A \leq K$ using contradictions:
	
	- Assume $K < A$
	- We know that the XOR along the path S is 0, and we can freely de-tour at $A$ corners 
	- Now if we find a subset of corners that the original XOR sum and the new XOR sum are equal, we successfully find
	  another the path that have the total XOR sum of 0
	- We can create a new array with $A$ elements, each equal to the original corner XOR with the opposite (potentially detour route) 
	- This array have $A$ elements while each have $K$ bit ($K < A$). We can prove that there is a subset of this array
      that has the XOR sum of 0, which also mean there is a subset of detour that produce the same XOR sum as the original corners.