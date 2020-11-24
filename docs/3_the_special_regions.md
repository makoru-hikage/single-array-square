# 3. The Special Regions
These special regions cannot be defined by mere **rows** and **columns** or any **borders**. However, they may be still be found using the **base** and the **square size**, or the **edges**. These regions are special because their traits vary depending on whether the **base** is odd or even.

## 3.1. The Center of a Line
Since we are dealing with discrete numbers, it is good to use the function to get the median with a slight tweak. We will be using the floor function for this.

### 3.1.1. Odd and Even Centers of a Line
The **center cell** can either be alone or a pair. It will be alone if the **base** is odd, and a pair if it's even. If the **base** is even, there will be a **first center** and a **second center**. In a **row**, the **first center** is in the right whilst the **second center** is in the left. In a **column**, the **first center** is on top of the **second center**.

### 3.1.2. Median of the Base
To find the **Median of the Base**, one must enumerate integers from 1 to **base**. For example:
```

If b = 5
then base_sets = {1, 2, 3, 4, 5}

If b = 8
then base_sets = {1, 2, 3, 4, 5, 6 ,7 ,8}
```

Then one must find the middle number amongst the set using a modified median function.

`mb = floor((b + 1) / 2)`

where `b` is the **base** and `mb` the **median of the base**. In an even **base**, the **median of the base** is always the **first center**

### 3.1.3. Center of a Row with Odd Base
To find the **center** of the **row**, one can simply use the function to find the **cell** indices of a particular **row**. (see 1.3.7). The you must supply the **median of the base**.
```
row_center(r) = row_cells(r,mb)
```
where `r` is the row index and `mb` the median of the base.

### 3.1.4. Center of a Column with Odd Base
To find the **center** of the **column**, one can simply use the function to find the **cell** indices of a particular **column**. (see 1.3.8). The you must supply the **median of the base**.
```
column_center(c) = column_cells(c,mb)
```
where `c` is the row index and `mb` the median of the base.

### 3.1.5. Center of a Row with Even Base
To find the **first center** of the **row**, use the function for finding the **center** of a **row** with odd **base**. Then add 1 to the **first center** to get the **second center**.
```
row_center_1(r) = row_center(r)
row_center_2(r) = row_center_1(r) + 1
```

### 3.1.6. Center of a Column with Even Base
To find the **first center** of the **row**, use the function for finding the **center** of a **row** with odd **base**. Then add the value of the **base** to the **first center** to get the **second center**.
```
column_center_1(c) = column_center(c)
column_center_2(c) = column_center_1(c) + b
```

## 3.2. The Center of a Square with an Odd Base
Like the center of a line, the **center of the square** is also affected on whether the **base** is odd or even since the **square** is made up of `b` number of **lines**.

### 3.2.1. Odd and Even Centers of a Square
The **square center** can either be alone or a quadrant. It will be alone if the **base** is odd, and a quadrant if it's even. If the **base** is even, there will be an **inner square** with a **base** of 2, which makes 4 four squares.

### 3.2.2. Odd Center
The **center** of a **square** with an odd **base** always has a lone **cell**. To find the lone **center** index, one must find the index of the row and the column equal to the **Median of the Base**. You can use the function for finding the center of a column or a row for this. (see 3.1.3 and 3.1.4)

`square_center(r) = row_cells(mb,mb) = column_cells(mb,mb)`

where `mb` is the **Median of the Base**.

### 3.2.3. Even Center
The **center** of a **square** with an even **base** always has quadrants of **cells**. To find the **center** indices, there are two ways using the **Median of the Base** as an argument in a function. 

Start with either the **row** or the **column** with an index equal to the **Median of the Base**. If you chose the **row** first, use the function for finding **cells** in a particular **column** (see 1.3.8). If you chose the **column** first, use the function for finding **cells** in a particular **row** (see 1.3.7). 
```
r = c = mb
csq_1 = column_cells(r,mb) = row_cells(c, mb)
```

where `mb` is the **Median of the Base**. `csq_1` is the **cell** index of the **first quadrant** of the **inner square**. `csq` means **center square quadrant**

To find the rest of the of the quadrants, the **base** is needed.
```
csq_2 = csq_1 + 1 
csq_3 = csq_1 + b
csq_4 = csq_1 + b + 1
```
where `csq` indicates a **quadrant** of the **inner square**. `csq_2` is a cell on the right of `csq_1`. `csq_3` goes directly below `csq_1`. `csq_4` goes directly below `csq_2` and on the right of `csq_3`

## 3.3. The Two Diagonal Lines
These **lines** are neither **horizontal lines** nor **vertical lines** yet they still contain **cells** counting to `b`. These two lines intersect each other in the **center** of the **square** if the **base** is odd. If the **base** is even, their **center** belongs to the **inner square**. Their **edges** are the **corners** of the **square**.

### 3.3.1. Cells of the First Diagonal Line
It always starts from 1 or the **Top-left Corner** and ends with `S` or the **Bottom-right Corner** or vice-versa. To enumerate the cell indices within the line:
```
d1_scell = corner_tl
cells_d1(n) = n + (b*n) - b
d1_scell <= n <= corner_br
```
where `n` is the nth **cell of the line** and `b` the **base**. `d1` simply means the **first diagonal**.

### 3.3.2. Cells of the First Diagonal Line
It always starts from 1 or the **Top-right Corner** and ends with the **Bottom-left Corner** or vice-versa. To enumerate the cell indices within the line:
```
d2_scell = corner_tr
cells_d2(n) = (b*n) - (n - 1)
d2_scell <= n <= corner_bl
```
where `n` is the **cell** index and `b` the **base**. `d2` simply means the **first diagonal**.

### 3.3.3. Intersection of Diagonal Lines of Odd Base
See 3.2.2

### 3.3.4. Centers of the Two Diagonal Lines of an Even Base
The **first center** of the **first diagonal** is the **first quadrant** of the **inner square**. The **second center** of the **first diagonal** is the **third quadrant** of the **inner square**. The **first center** of the **second diagonal** is the **second quadrant** of the **inner square**. The **second center** of the **second diagonal** is the **fourth quadrant** of the **inner square**.