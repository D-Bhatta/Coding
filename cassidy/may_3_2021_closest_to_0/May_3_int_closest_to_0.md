# Integer closest to 0

## Problem definition

From [@cassidoo](https://twitter.com/cassidoo)'s [newsletter](https://buttondown.email/cassidoo/archive/in-a-time-of-destruction-create-something-maxine).

```text
Given a positive or negative real number, round it to the next whole integer closer to zero. This means if it’s positive, round down, and if it’s negative, round up. Try to do this in as few characters possible!

Test cases:

 1.7    =>  1
-2.1    => -2
 500.4  =>  500
-369.5  => -369
 150    =>  150
-350    => -350
```

## Ruminations

What the input is: postive and negative floating point numbers, that can be displaced on the number line towards 0.

What the output should be: integers on the number line that are closer to 0 than the input.

We can think of this as a problem where we have to **"move"** the integer towards 0, from it's place on the number line.

For input numbers greater than 0, if there is a decimal fraction with the number, to move it closer to 0 we can remove the decimal fraction.

For numbers less than o, if there is a decimal fraction with the number, to move it closer to 0 we can add the decimal fraction, since anything less than 0 represents **"loss"**. To **"repair"** this loss we can fill the decimal fraction lost with an equivalent amount. Thus, addition will move it closer to 0.

The `%` operator returns the `mod` of the operands. In other words, the remainder after the division.

```python
>>> 2%1
0
>>> 0.5%1
0.5
>>> -1%1
0
>>> -0.1%1
0.9
>>> -2%1
0
```

For positive inputs, we simply subtract the modulus of the input and 1 from the input.
For negative inputs, we subtract the modulus of the input and 1 from 1. This gives us the decimal fraction of the input. Next, we simply add it to the input.
If there is no decimal fraction in input, then there is no need for modification.

## Python implementation

```python
def round(num: float):
    if num%1 == 0:
        return num
    if num > 0:
        return int(num - (num%1))
    else:
        return int(num + (1-(num%1)))
```

- 164 characters

## Optimization for code length

### First iteration

```python
def round(num: float):
    return (int(((num + (1-(num%1))), (num - (num%1)))[num > 0]), num)[num%1 == 0]
```

- 106 characters (35% reduction)
- We use the [tuple ternary operator](https://book.pythontips.com/en/latest/ternary_operators.html) to reduce the number of characters required. `(if_test_is_false, if_test_is_true)[test]`