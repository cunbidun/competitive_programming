# Naive solution

For each number `i`, we will count the number of possible array if `i` is the greatest.

We can do this by, for each element `j`, we count how many divisors of `i` is less than or equal to `j`. And then multiple those choices together This will be `O(mx * n * mx)` time complexity (`mx` is the maxinum number in the array)

# Efficient solution

1. For each value `i` from 1 to `mx`, we pre-calculate the numbers of element that greater or equal to `i`. This can be calculated efficiently by sorting the array.

2. For each number `i`, find all its divisors.

3. For each number in the array, we know how many options for that number if the maxinum number is `i`, also we know the number of element with the same number of otions.


```
// num[i] is the number of element that greater or equal to `i`
// i = 1 is handled seperately
for (int i = 2; i <= mx; i++) {
  vi l; 
  for (int j = 1; j * j <= i; j++) {
    if (i % j == 0) {
      l.push_back(j);
      if (j != i / j) {
        l.push_back(i / j);
      }
    }
  }
  sort(all(l)); // get all divisors of i and put them to a sorted the list
  int res = 1;
  // j is the number of options
  for (int j = 1; j < sz(l) - 1; j++) {
    res += (j + 1) ^ (num[l[j]] - num[l[j + 1]]);
    // j + 1 is the number of options
    // num[l[j]] - num[l[j + 1]] is the number of element with the same number of option
  }
  // Seperate case for the value i
  // We have to select at least 1 value i
  // sz(l)^num[i] is all the cases
  // (sz(l) - 1)^num[i] is all the cases without value i
  res += sz(l)^num[i] - (sz(l) - 1)^num[i];
  ans = Op.add(ans, res);
}
```