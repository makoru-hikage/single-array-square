# 4. The Directions of Traversal

The **square** can be a place to move in. Take note, the Cartesian coordinate system won't be used here. Video game developers and cartographers will likely use that, but not this. Usually, there are eight basic movement **directions** in a 2 dimensional plane: **up**, **down**, **left**, **right**, **up-left**, **up-right**, **down-right**, and **down-left**.

## 4.1. The Current Position
Before moving, one must know one's current **position**. All is discrete so "nothing in between" two **cells**.

### 4.1.1 Being in a Square
A **position** is within a confine of a **cell**. A **position** index is a non-zero positive integer and limited by the **square size**.

`1 <= p <= S`

where `p` is the position and `S` is the **square size**

## 4.2. The Horizontal and Vertical Directions
To move horizontally is move along a **row** just as vertical movements to a **column**.

### 4.2.1. Left
To move to the left.

`np_l(s) = p + s`

where `p` is the current **position** and `s` is the number is steps to the left. `np` means new position.

### 4.2.2. Right
To move to the right.

`np_r(s) = p - s`

where `p` is the current **position** and `s` is the number is steps to the right. `np` means new position.

### 4.2.3. Up

`np_u(s) = p + s*b`

where `p` is the current **position**, is the **base**, and `s` is the number is steps to the top. `np` means new position.

### 4.2.4. Down

`np_d(s) = p - s*b`

where `p` is the current **position**, is the **base**, and `s` is the number is steps to the bottom. `np` means new position.

## 4.3. The Diagonal Directions
These are special movements that do not go along neither rows or columns. 

### 4.3.1 Up-Left
To move up-left

`np_ul(s) = p - s*(b+1)`

where `p` is the current **position**, is the **base**, and `s` is the number is steps to the top-left. `np` means new position.

### 4.3.2 Up-Right
To move up-right

`np_ur(s) = p - s*(b-1)`

where `p` is the current **position**, is the **base**, and `s` is the number is steps to the top-right. `np` means new position.

### 4.3.3 Down-Left
To move down-left

`np_dl(s) = p + s*(b-1)`

where `p` is the current **position**, is the **base**, and `s` is the number is steps to the bottom-left. `np` means new position.

### 4.3.4 Down-Right
To move down-right

`np_dl(s) = p + s*(b+1)`

where `p` is the current **position**, is the **base**, and `s` is the number is steps to the bottom-right. `np` means new position.

[end of page]