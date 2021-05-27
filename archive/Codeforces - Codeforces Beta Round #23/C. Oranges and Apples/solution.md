# Problem CF23-D12-C

Problem link: https://codeforces.com/problemset/problem/23/C

### Solution:
#### Simpler problem
First let's solve this simple problems: Given an array with `2 * N - 1` elements. We have to find excactly `N` elements: the sum of the seclected elements are strictly greater than half of the total sum of array.

1. Realize that we always have to choose the greatest elements. 
2. So we have to choose `N - 1` other elements.
3. Relize that we have to find `N - 1` pair, and for each pair, take the greater one. So we will have `N - 1` number that has the sum greater than half of the total `2 * N - 1` elements (except the first one)
4. Realize that if we sort the array in non-increasing order we have:
5. The some of the first element and even indexed elements are greater than half
`(2 >= 3, 4 >= 5, ..., 2 * N - 2 > 2 * N - 1)`
6. The some of the first element and odd indexed elements are greater than half
`(1 >= 2, 3 >= 4, ..., 2 * N - 3 > 2 * N - 2)`

With this we can apply to sovle the main problem:

#### Main problem:

1. Sort the box in non-increasing order of apples.
2. Select box 1 and all the even order boxes in sorted array of boxes.
3. Check the sum for oranges in those box. If the sum is greater than half. This is the correct choice.
4. Repeat step 2 and 3 wth odd indexed boxes.
5. From the small problem above, we know that both choice in 2. and 4. will guarantee we have strictly more than half the number of apples.
6. If the number of oranges in the first choice is not greater than half, we number of oranges in second choices must be greater than half, and reverse.
7. So we can guarantee the answer always exists.