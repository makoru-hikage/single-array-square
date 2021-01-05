# INTRODUCTION

Can a magic square be represented using only one-dimensional array?

The answer is **yes**: labelling each grid from one to n^2 and math. In computer science, an array is a data type that holds a series of variables or data. Imagine a row of 5 empty boxes labelled "0" to "4". When one needs to represent a 4x4 grid in a program, one would intuit to create a two-dimensional array to represent rows and columns. That is the common way.

To determine navigation along the square, one might resort to using Cartesian coordinate system. Many video game developers use it; it seems to the standard. But we won't be using it here. However, a series of equations will be used to determine the borders, location of a cell, neighbors of a cell, the corners, and other parts of the square. We'll also be dealing with discrete values.

As for the practicality, I don't think this will be practical. This is an exploration to a counterintuitive way to view a perfect square. 

_Rule 0: all parts of the square will be represented with integers_
