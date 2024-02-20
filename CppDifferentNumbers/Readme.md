# Different numbers

Given a list of positive integers, find the longest fragment (some consecutive elements), where all the numbers are different.
For example, in the sequence "1, 3, 6, 3, 1, 4, 5, 3, 1", 
the longest fragment where all numbers are different is of length 5
and starts with the third element: "6, 3, 1, 4, 5".

Write a computer program that, for a given string of numbers, 
finds the longest fragment where all the numbers are
different, output its length and all the locations where these fragments start. 

## Input data

In the first line of the input data there is a positive integer - 
the number of elements in the sequence $N$ ($N \leq 2 \cdot 10^{5}$).
In the next line of input data precisely $N$ positive integers are given - 
these are the elements of the input list. It is known that no number
exceeds $10^9$.

There is a space between every two adjacent numbers in the input data.


## Output data

In the first line of the output data there is a positive integer $G$ - 
the length of the longest fragment containing different numbers (if all the 
numbers in the input list are equal, then $G=1$). 
In the second line of the output data, a positive integer $H$ shows in 
how many places the fragments containing different numbers can be found.
In the third line of the output data precisely $H$ positive integers
should be output in ascending order - these are the 
indices within the input sequence which show the starting points for 
each segment. The indices start from $1$.

There must be a space between every two adjacent numbers.

## Examples

**input01.txt**

```
9
1 3 6 3 1 4 5 3 1
```

**output01.txt**

```
5
1
3
```

**input02.txt**

```
7
3 3 3 15 15 7 15
```

**output02.txt**

```
2
3
3 5 6
```

**input03.txt**

```
14
1 3 5 3 2 3 7 9 3 8 6 4 9 3
```

**output03.txt**

```
6
1
7
```



-DEVAL -std=gnu++17 -O2 -pipe -static -s



## Outline of the solution 

* Sliding window technique (the fragment we are searching fits between two pointers) - expand or shrink the window to satisfy the criteria (try to maximize its length).
* The analysis of this algorithm counts the changes of the window size - it equals $O(n)$, where $n$ is the length of the input list. 










# CppDifferentNumbers build instructions 

Used to test cpp-related code -- both for reuse in Android NDK 
projects and also to protect with zShield separately.

Build instructions:

```
cd CppKeyDerivation
mkdir build
cd build
cmake -G "Xcode" .. -DCMAKE_OSX_DEPLOYMENT_TARGET=11 -DSKB_TARGET_LIB_DIR="$SKB_ROOT/lib/apple/macosx"
cmake --build . --config Release
./src/Release/cppkeyderivation_project_run
ctest
```

If "make" command is supported from the command-line, another set of commands can be tried out: 

```
cd build
cmake .. -DSKB_TARGET_LIB_DIR="$SKB_ROOT/lib/apple/macosx"
make
./src/cppkeyderivation_project_run
ctest
```
