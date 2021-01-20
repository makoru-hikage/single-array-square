# 1. The Basic Parts

A square is a rectangle whose length and width are equal. We won't be talking much about what a rectangle is, as long as we are dealing with four 90 degree corners and a pair of parallel lines perpendicular to another pair of parallel lines. You get the gist. In this case the length and width is equal; we will call their value the **base**.

## 1.1. The Base
We call it the **base** because it is the **base** of a power, and our exponent is two. Base to the second power is also called as **base squared**. Since the length and width of a square are equal and the area of the square is equal to length multiplied by width, you might as well use **base squared** to quantify the area of the square. Since the word "area" and "size" are often interchanged, we'll use **square size** or just **size** for this topic. The **base** multiplied by itself is the **size** of the **square**.

### 1.1.1. The Square Size
The size of the square will always be determined by the base. 

`S = b * b`

or 

`S = b ^ 2`

where `S` is the square size and `b` is the base.

### 1.1.2. Square Sizes Must be Greater than One
While a square with a base of 1 can be considered a perfect square, in this topic, it is negligible. Zero and negative numbers as the value of the base is not in the scope of this topic.

`b > 1`

### 1.1.3. Square Visualisation
When printing a **square** to a screen or paper, a new **line** shall be made per multiple of the **base**. It shall result to all the rightmost **cells** being multiples of the **base**.


## 1.2. The Cells
The **cells** are the "building blocks" of the square. The count of all **cells** equate to the square **size**. The cells are labeled from 1 to the amount of the square size.

### 1.2.1. Cells in a Square as an Array
The total number of cells are equal to the size of the square. If the array starts with zero, it must be initialised with an extra index. 

`l_a = S + 1`

where `l_a` is array length. `S` is the size of the square.

### 1.2.2. Cell Indices
The cells are indexed from 1 to S, where S is the size of the square.

`1 <= n <= S`

where `n` is the index of the cell and `S` is the size of the square.

### 1.2.3. Index 0
The extra index or "index 0" can be used for anything but not for representing any part of the square. The indices 1 to `S` are the only indices used to represent the cells of the square.


## 1.3. The Lines
A **line** pertains to a collection of cells in one direction. It is limited by a **boundary**. The length of the line is always equal to the value of the **base**. It can have two basic orientations: **horizontal** and **vertical**. If it has a horizontal orientation, the line is called a **row**. If it has a vertical orientation, it is a **column**.

[Please take note that these "lines" are actually "line segments" if you feel pedantic with geometry or math.]

### 1.3.1. Cells in a Line
The **cells** in a **line** count only up to the value of **base**. (e.g. When the base is 5, there can only be 5 cells in a line.)

`l_line = b`

where `l_line` is length of the line and `b` is the base.

### 1.3.2. Equal Rows and Columns
The number of **rows** and **columns** are the same.

`l_rows = l_columns`

### 1.3.3. Rows, Columns, and the Base
In a **square**, the total count of both **rows** and **columns** each is equal to the value of **base**. See 1.3.1 and 1.3.2 (e.g. When the base is 5, there can only be 5 rows and 5 columns.)

`l_rows = l_columns = base`

### 1.3.4. Line Indices
Each row shall be indexed 1 up to the value of the base as well as each column shall be. (see 1.3.1).

`1 <= r <= b; 1 <= c <= b`

where `r` is the index of the row and `c` is the index of the column. `b` is the base

### 1.3.5. Cell in a Row
To determine which row a **cell** belongs to, we first get the cell index and the **base**.

`r(n) = ceil(n / b)`

where `n` is the cell index and `b` is the base. Since we are dealing with integers here, we need to find the ceiling.

### 1.3.6. Cell in a Column
To determine which column a **cell** belongs to, we first get the cell index and the **base**. 

`c(n) = b - ((b - n) mod b)`

where `n` is the cell index and `b` is the base. `mod` signifies modulo. (e.g `5 mod 2` would yield `1` because the remainder of `5/2` is `1`)

### 1.3.7. Cells of a Row
To enumerate all the **cells** of a certain **row**, we must choose a **row** index.
```
row_cells(r,n) = n - b + (b*r) 
1 <= n <= b
```
where `r` is the **row** index, `n` is the nth **cell** index of the **row**, and `b` is the **base**. To determine the starting **cell**, the value of `n` must be 1.

### 1.3.8. Cells of a Column
The **column's** starting **cell** is always equal to the **column** index. To enumerate all the **cells** of a certain **column**, we must choose a **column** index. 
```
column_cells(c,n) = c - b + (b*n)
1 <= n <= b
```
where `c` is the **row** index, `n` is the nth **cell** index of the **column**, and `b` is the **base**.

### 1.3.9. Cell of a Row and a Column: Intersection
There are two ways to determine a **cell** index using a **row** and **column**, it's some sort of pointing a point using x and y in a Cartesian plane. One way is to use the function to find **cells** in a **row** (see 1.3.7)

`n = row_cells(r,c)`

where `n` is the **cell** index being searched, `r` is the **row** index and `c` the **column** index.

Another way is to use the function to find **cells** in a **column** (see 1.3.8)

`n = column_cells(c,r)`

where `n` is the **cell** index being searched, `r` is the **row** index and `c` the **column** index.

To summarise, the equation is:

`p = c - b + (b*r)`

where `p` is the **cell index**, `c` and `r` are the **column** and **row** respectively, and the `b` is the **base**.

## 1.4. The Slopes
A **slope** is also called a diagonal line. A series of **cells** made by incrementing or decrementing either the **row** index, **column** index, or both. There are two kinds of slopes, **descending** and **ascending**. Slopes are neither horizontal nor vertical.

### 1.4.1. Slopes in a Square
The count of each kind of **slope** in a **square** are as follows:

`l_slopes = (b*2) - 1`

where `b` is the base and `l_slopes` is simply the number of slopes in a square. So there will be `l_scopes` number each of descending and ascending slopes.

### 1.4.2. Possible Number of Cells in a Slope
The number of **cells** in a **slope** can count to 1 up to the **base** depending in where the slope started.

`1 <= l_cells <= b`

where `b` is the base and `l_cells` is simply the number of **cells** in a given **slope**.

### 1.4.3. Intersection Sum and Difference
An equation to use to determine if two **cells** belong on the same **slope**. It is done by extracting the **row** and the **column** index of a **cell**. (See 1.3.5 and 1.3.6)
```
is = r + c
id = r - c
```
where `r` and `c` are the extracted **row** and **column** indices respectively. `is` is **intersection sum** and `id` is **intersection difference**.

### 1.4.4. Descending Slope
A **descending slope** is a series of **cells** that start from either **row** index 1 to **column** index b or from **column** index 1 to **row** index `b` as both the **row** and **column** indices increment.

#### 1.4.4.1. Descending Slope Indices
To determine the **descending slope** index of a **cell**, you first find its **intersection difference** and subtract it from the **base**. This can be used to determine if two **cells** belong in the same **descending slope**.

`d = b - id`

where `d` is the **descending slope** index, `b` the **base**, and `id` the **intersection difference**.

#### 1.4.4.2. Descending Slope Starting Cells
To get **descending slope** index 1, get the **cell** with **row** index `b` and **column** index 1. **Cell** index 1 shall always be the start of **descending slope** index `b`. The last **descending slope** index will always be equal to the total number of **descending slopes** in a **square** (See 1.4.1).

To enumerate all the starting **cells**, all **cells** of **column** index 1 shall be listed in descending order. The last **cell** from that **column** would be **cell** index 1. Then enumerate all the **cells** of **row** b in ascending order.

#### 1.4.4.3. Cells in a Certain Descending Slope
To get the maximum number of **cells** in a chosen **descending slope**, this equation must be used.

`l_dscells = |b - d|`

where `b` is the **base** and `d` is the **descending slope** index. The value is always absolute.

### 1.4.5.1 Ascending Slope
An **ascending slope** is a series of **cells** that start from either **column** index 1 to **row** index 1 or **row** index b to **column** index b as the **row** index decrements whilst the **column** index increments. 

#### 1.4.5.1. Ascending Slope Indices
To determine the **ascending slope** index of a **cell**, you first find its **intersection sum** and subtract 1. This can be used to determine if two **cells** belong in the same **ascending slope**.

`a = is - 1`

where `a` is the **ascending slope** index and `is` the **intersection sum**.

#### 1.4.5.2. Ascending Slope Starting Cells
To get **ascending slope** index 1, get the **cell** with **row** and **column** index 1. The **cell** with **row** index `b` and **column** index 1 shall always be the start of **ascending slope** index `b`. The last **ascending slope** index will always be equal to the total number of **ascending slopes** in a **square** (See 1.4.1).

To enumerate all the starting **cells**, all **cells** of **column** index 1 shall be listed in ascending order. The last **cell** from that **column** would be the first **cell** of **row** index b. Then enumerate all the **cells** of **row** b in ascending order.

#### 1.4.5.3. Cells in a Certain Ascending Slope
To get the maximum number of **cells** in a chosen **ascending slope**, this equation must be used.

`l_dscells = b - |b - d|`

where `b` is the **base** and `d` is the **ascending slope** index.

[end of page]

[//]: # (TODO: Two types of descending slope and two types of ascending slope, and how to enumerate the cells within them.)
