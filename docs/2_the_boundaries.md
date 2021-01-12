# 2. The Boundaries

Now that we have indexed our **cells** and **lines**, we can now index the **borders**, the **edges**, and the **corners**. A **border** is simply a side of a square. An **edge** pertains to an end of a **line**. A **corner** is the common **cell** of two adjacent **lines**. In essence, boundaries set limits to lines and cells with regards to the **base**.

## 2.1. The Borders
The **borders** represent the four sides of the square. A **border** is a kind of a **line** that defines the outermost **cells** of the square. In a square, there are two **horizontal borders** and two **vertical borders**. The **horizontal borders** are **top border** and the **bottom border**. The **vertical borders** are **left border** and the **right border**.

```
l_hborders = 2
l_vborders = 2
l_borders = l_corners = l_hborders + l_vborders = 4
```

### 2.1.1 A Border is a Line
A **border** is always a **line**.

### 2.1.2 Top Border
The **top border** is always the first **horizontal border**.

`B_top = r_1`

where `B_top` is **top border** and `r_1` is **row** index 1.

### 2.1.3 Bottom Border
The **bottom border** is always the last **horizontal border**.

`B_bottom = r_b`

where `B_bottom` is **bottom border** and `r_b` is a **row** with its index equal to the **base**.

### 2.1.4 Left Border
The **left border** is always the first **vertical border**.

`B_left = c_1`

where `B_left` is **left border** and `c_1` is **column** index 1.

### 2.1.5 Right Border
The **right border** is always the last **vertical border**. (See 1.1.3)

`B_right = c_b`

where `B_right` is **right border** and `c_b` is a **column** with its index equal to the **base**.

### 2.1.6 Cells in a Horizontal Border
To see which **cell** belongs in which **border**, see if it belongs to either **row** index 1, **column** index 1, **row** index b, or **column** index b. (see 1.3.5 and 1.3.6.)

```
r(1) = B_top
c(1) = B_left
r(b) = B_bottom
c(b) = B_right
```

## 2.2. The Edges
The **edges** are the ends of a **line**. It can also pertain to **cells** found in a **border**. There are two kinds of **edges**: **horizontal edges** and **vertical edges**. **Horizontal edges** are **cells** from **horizontal borders** whilst **vertical edges** are **cells** from **vertical borders**.

## 2.2.1. All Edges of the Square
To count all of the **edges** of a square, one must mind that squares have four sides(**borders**) and four **corners**.

`l_edges = (b*l_borders) - l_corners `

where `l_edges` are the number of the edges; `l_borders`, number of all **borders**; `l_corners` number of all **corners**; and `b` the **base**.

## 2.2.2. Top Edges
Cells of the **top border**. All integers from 1 to `b` constitute the indices of **edges**.

`1 <= n <= b`

where `n` is the **cell** index and `b` is the **base**

## 2.2.3. Bottom Edges
Cells of the **bottom border**. It always contains the **cell** with index `S`

`S-(b-1) <= n <= S`

where `n` is the **cell** index, `S` is the **square size**, and `b` is the **base**

## 2.2.4. Left Edges
Cells of the **left border**. The topmost left edge is always 1. To determine the left edges:

```
edges_left(r) = 1 + (b*r) - b
1 <= r <= b
1 <= n <= S-(b-1)
```
where `S-(b-1)` is the limit. `S` is the **square size**, `b` the **base**, `r` the **row** index, and `n` the **cell** index.

## 2.2.5. Right Edges
Cells of the **right border**. The topmost right edge is always `b`. To determine the right edges:
```
edges_right(r) = b*r
1 <= r <= b
1 <= n <= S
```
where `S` is the limit and the **square size**, `b` the **base**, `r` the **row** index, and `n` the **cell** index.


## 2.3. The Corners
The **corners** are special kinds of **edges** that belongs to two **borders**. There are four **corners** because there are four possible combinations of two adjacent **borders** out of four.

### 2.3.1. Top-left Corner
The **top-left corner** always has a value of 1. This **edge** belongs to both **top border** and **left border**.

`corner_tl = 1`

### 2.3.2. Top-right Corner
The **top-right corner** always has a value of `b`. This **edge** belongs to both **top border** and **right border**.

`corner_tr = b`

### 2.3.3. Bottom-left Corner
The **bottom-left corner** is somewhat related to the **square size** and the **base**. This **edge** belongs to both **bottom border** and **left border**.

`corner_bl = S - (b - 1)`

### 2.3.4. Bottom-right Corner
The **bottom-right corner** is always the **edge** of the last **row** and the last **column**. This **edge** belongs to both **bottom border** and **right border**.

`corner_br = S`

[end of page]