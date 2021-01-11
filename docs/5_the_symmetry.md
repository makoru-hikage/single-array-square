# 5. The Symmetry
The symmetry of a square comes from its all equal sides. It can be bisected, even quadrisected.

## 5.1. The Bisection of a Line
A **line** can be bisected into two by finding its **center**. Whether the **base** is odd or even, it can still be done.

### 5.1.1. Find the Median
To bisect a line, the Median of the Base is needed (See 3.1.2). The indices 1 to the Median of the Base will be the **first side**. The rest up to value of the **base** shall comprise the **second side** which will be the **opposite** of the **first side**.
```
first_side(n) = 1 <= n <= mb;
second_side(n) = mb < n <= b;
```
where `n` is the **cell** index, `mb` is the **median of the base**, and `b` is the **base**.

## 5.2. The Opposite Cells in a Line 
A **line** is always symmetrical and has a **center cell** or a pair. A **cell** in the **first side** has a counterpart or **opposite cell** in the **second side** or vice versa.

### 5.2.1. Finding the Opposite Index
To find the opposite, the **line** and the **base** shall be determined.

`o = (b + 1) - n`

where `n` is the chosen **index** index and `o` is the index of its **opposite index**. `b` is the **base**.

### 5.2.2. Center of an Odd-sized Line
The opposite of **center cell** of a line with an odd **base** will be itself, therefore, the **center cell** belongs to both first and second **side**

### 5.2.3. Horizontal Opposite
To know the **opposite cell** of a **cell** in a **row**, you must determine the index of its respective **row** and **column** (see 3.1.5 and 3.1.6). Then you must find the opposite index of the **column** index (see 5.2.1). Then use the formula for Intersection (see 1.3.9). 
```
c_n = c(n)
r_n = r(n)
o_h = o(c_n) + (b*r_n) - b
```
where `o(c_n)` is the **opposite index** of the **column** index of the **cell**, `r_n` is the **row** index of the **cell**, and `b` is the **base**.

### 5.2.4. Vertical Opposite
To know the **opposite cell** of a **cell** in a **column**, you must determine the index of its respective **row** and **column** (see 3.1.5 and 3.1.6). Then you must find the opposite index of the **row** index (see 5.2.1). Then use the formula for Intersection (see 1.3.9). 
```
c_n = c(n)
r_n = r(n)
o_h = c_n + (b*o(r_n)) - b
```
where `o(r_n)` is the **opposite index** of the **row** index of the **cell**, `c_n` is the **column** index of the **cell**, and `b` is the **base**.

[//]: # (TODO: 5.3)

