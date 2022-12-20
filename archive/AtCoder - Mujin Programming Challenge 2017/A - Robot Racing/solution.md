<!-- markdownlint-configure-file { "MD013": { "line_length": 120 } } -->

# Solution

## Step by step solutions  

1. For each frog, compute the minimum number of frogs need to be remove before it can land on 0
Let's call this number min_frog
2. Now if put frogs with the same min_frog number to same bucket and compute the bucket size.
Let the name of the bucket be the min_frog number itself
3. The frog on bucket 1 and always jump 0 first. We can let one of them jump. After that, we know those
on bucket 2 will always be move to bucket 1, 3  will always move to 2, and so on... (see proof below)
4. Multiply the number of choice from each step together to get the answer:
$$
ans = bucket[1] \cdot (bucket[1] + bucket[2] - 1) \cdot (bucket[1] + bucket[3] + bucket[3] - 2) + \cdots
$$

## Proof of correctness

1. Why do step 3 is true?

    First, Let's limit the space between to frog to maximum 1 unit. Upper location of frog in similar
    bucket must ends will 2 consecutive frogs. If we remove any frog in that bucket, we effectively
    create an empty space between all frogs in the same bucket. Thus decrease all the next frog
    min_frog number
