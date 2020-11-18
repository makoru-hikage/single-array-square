# 1 The Basic Parts

A square is a rectangle whose length and width are equal. We won't be talking much about what a rectangle is, as long as we are dealing with four 90 degree corners and a pair of parallel lines perpendicular to another pair of parallel lines. You get the gist. In this case the length and width is equal; we will call their value the **base**.

## 1.1 The Base
We call it the **base** because it is the **base** of a power, and our exponent is two. Base to the second power is also called as **base squared**. Since the length and width of a square are equal and the area of the square is equal to length multiplied by width, you might as well use **base squared** to quantify the area of the square. Since the word "area" and "size" are often interchanged, we'll use **square size** or just **size** for this topic. **base** multiplied by itself if the **size** of the **square**.

### 1.1.1 The Square Size
The size of the square will always be determined by the base. 

`S = b * b`

or 

`S = b ^ 2`

where `S` is the square size and `b` is the base.

### 1.1.2 Square Sizes Must be Greater than One
While a square with a base of 1 can be considered a perfect square, in this topic, it is negligible. Zero and negative numbers as the value of the base is not in the scope of this topic.

`b > 1`


## 1.2 The Cells
The **cells** are the "building blocks" of the square. The count of all **cells** equate to the square **size**. The cells are labeled from 1 to the amount of the square size.

### 1.2.1 Cells in a Square as an Array
The total number of cells are equal to the size of the square. If the array starts with zero, it must be initialised with an extra index. 

`l_a = S + 1`

where `l_a` is array length. `S` is the size of the square.

### 1.2.2 Cell Indices
The cells are indexed from 1 to S, where S is the size of the square.

`1 <= n <= S`

where `n` is the index of the cell and `S` is the size of the square.

### 1.2.3 Index 0
The extra index or "index 0" can be used for anything but not for representing any part of the square. The indices 1 to `S` are the only indices used to represent the cells of the square.


## 1.3 The Lines
A **line** pertains to a collection of cells in one direction. It is limited by a **boundary**. The length of the line is always equal to the value of the **base**. It can have two basic orientations: **horizontal** and **vertical**. If it has a horizontal orientation, the line is called a **row**. If it has a vertical orientation, it is a **column**.

### 1.3.1 Cells in a Line
The **cells** in a **line** count only up to the value of **base**. (e.g. When the base is 5, there can only be 5 cells in a line.)

`l_line = b`

where `l_line` is length of the line and `b` is the base.

### 1.3.2 Equal Rows and Columns
The number of **rows** and **columns** are the same.

`rows = columns`

### 1.3.3 Rows, Columns, and the Base
In a **square**, the total count of both **rows** and **columns** each is equal to the value of **base**. See 1.3.1 and 1.3.2 (e.g. When the base is 5, there can only be 5 rows and 5 columns.)

`rows = columns = base`

### 1.3.4 Line Indices
Each row shall be indexed 1 up to the value of the base as well as each column shall be. (see 1.3.1).

`1 <= r <= b; 1 <= c <= b`

where `r` is the index of the row and `c` is the index of the column. `b` is the base

### 1.3.5 Cell in a Row
To determine which row a **cell** belongs to, we first get the cell index and the **base**.

`ceil(n / b)`

where `n` is the cell index and `b` is the base. Since we are dealing with integers here, we need to find the ceiling.

### 1.3.6 Cell in a Column
To determine which column a **cell** belongs to, we first get the cell index and the **base**. 

`b - ((b - n) mod b)`

where `n` is the cell index and `b` is the base. `mod` signifies modulo. (e.g `5 mod 2` would yield `1` because the remainder of `5/2` is `1`)

[end of page]