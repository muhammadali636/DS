# CIS2520-F24-A3

## Student Information 
Name : MUHAMMAD ALI

Student Number : 1115336

## Assignment Overview
What is the assignment about?  
This assignment has two parts: managing a max-heap and creating an expression tree. The first part focuses on maintaining a max-heap using the downheap process. The heap is stored in a 1D array, and the program adjusts elements to ensure each parent is larger than its children. The second part involves building and solving mathematical expressions using an expression tree. The program reads a mathematical expression, builds a tree to represent it and lets the user person assign values to variables, and calculates the result by evaluating the tree step by step. 

Explain the purpose of the program and what it accomplishes.
The goal is to practice working with heaps, trees, and basic algorithms. It accomplishes two main tasks: managing a max-heap by maintaining the heap property through the downheap process, and building an expression tree to parse and evaluate mathematical expressions step by step. 


## Resources 
Did you use any resources (for example book, notes etc) in this assignment?

I used mainly the lecture on stacks and assignment 2 polish notation, to help with Q1. I also used the tree and heap lectures. I also referenced geeks for geeks (which was such a great resource especially for ordering of tree): https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/#inorder-traversal

I also referenced a lot of previous code I wrote from previous classes like CIS2500 and CIS1300 for things like removing the null terminator from strings, file reading and loading etc etc. For the makefile I literally reused the same structuring from cis2500, since I havent used a makefile in a while. 

## Implementation
The assignment is complete. Unzip the file first. Open up terminal or powershell or whatever command line you got. Then Execute the makefile using the make command. 
once u do make, you can do ./a3q1 "expression" or ./a3q2 to run either question.
if u want to clean everything up do make clean. Make sure u put the expression is quotations for a3q1.
Use valgrind to check for memory leaks (shouldnt be any). For example valgrind ./a3q1 "expression"

For Q2 make sure the files read are exactly named f.dat otherwise the program will have trouble loading because the name is hardcoded. 

Use the following test cases to validate Q2:

Q1 (Tree traversal) test case:

Expression '(((x1+5.12)*(x2-7.68))/x3)'

Preorder Output: / * + x1 5.12 - x2 7.68 x3 

Inorder Output: ((((x1)+(5.12))*((x2)-(7.68)))/(x3))

Postorder Output: x1 5.12 + x2 7.68 - * x3 /

Q2 (max heap) test case:
f.dat file contents:
25 00 54 25 19 25 81 21 02 78
19 09 89 77 80 75 91 34 61 24
36 42 65 18 81 93 72 34 59 37
10 56 17 24 47 02 35 45 19 51
26 28 10 23 03 32 65 61 28 95
66 63 94 42 77 64 56 80 63 14
77 07 34 93 04 19 10 44 76 19
86 18 40 47 13 94 98 22 79 94
68 37 41 12 06 85 51 85 60 56
03 98 29 05 60 15 98 86 04 61
77 51 28 24 77 02 36 64 32 05
30 73 12 75 14 85 72 60 91 42
83 46 03 67 90 48 04 74 41 52
62 30 46 71 41 38 80 60 99 05
19 48 83 98 11 30 41 72 09 31
31 44 21 79 68 97 32 13 62 80
61 69 82 25 62 12 83 35 56 19
62 74 67 19 41 35 38 16 09 80
47 44 85 30 84 53 28 42 07 65
99 30 00 91 26 09 91 70 21 14

Sample output
66 63 94 42 77 64 56 80 63 14
61 69 82 25 62 12 83 35 56 19
19 48 83 98 11 30 41 72 09 31
62 74 67 19 41 35 38 16 09 80
77 51 28 24 77 02 36 64 32 05
36 42 65 18 81 93 72 34 59 37
62 30 46 71 41 38 80 60 99 05
86 18 40 47 13 94 98 22 79 94
47 44 85 30 84 53 28 42 07 65
03 98 29 05 60 15 98 86 04 61
26 28 10 23 03 32 65 61 28 95
30 73 12 75 14 85 72 60 91 42
83 46 03 67 90 48 04 74 41 52
25 00 54 25 19 25 81 21 02 78
77 07 34 93 04 19 10 44 76 19
31 44 21 79 68 97 32 13 62 80
10 56 17 24 47 02 35 45 19 51
68 37 41 12 06 85 51 85 60 56
19 09 89 77 80 75 91 34 61 24
99 30 00 91 26 09 91 70 21 14

Explanation:
In test case f.dat:
Node.sum_key: 79 (25+0+54)
Node.sum_key: 117 (19+9+89)
Node.sum_key: 143 (36+42+65)
Node.sum_key: 83 (10+56+17)
Node.sum_key: 64 (26+28+10)
Node.sum_key: 223 (66+63+94)
Node.sum_key: 118 (77+7+34)
Node.sum_key: 144 (86+18+40)
Node.sum_key: 146 (68+37+41)
Node.sum_key: 130 (3+98+29)
Node.sum_key: 156 (77+51+28)
Node.sum_key: 115 (30+73+12)
Node.sum_key: 132 (83+46+3)
Node.sum_key: 138 (62+30+46)
Node.sum_key: 150 (19+48+83)
Node.sum_key: 96 (31+44+21)
Node.sum_key: 212 (61+69+82)
Node.sum_key: 203 (62+74+67)
Node.sum_key: 176 (47+44+85)
Node.sum_key: 129 (99+30+0)

After applying the parental node downheap algorithm:
Node.sum_key: 223 (66+63+94)
Node.sum_key: 212 (61+69+82)
Node.sum_key: 150 (19+48+83)
Node.sum_key: 203 (62+74+67)
Node.sum_key: 156 (77+51+28)
Node.sum_key: 143 (36+42+65)
Node.sum_key: 138 (62+30+46)
Node.sum_key: 144 (86+18+40)
Node.sum_key: 176 (47+44+85)
Node.sum_key: 130 (03+98+29)
Node.sum_key: 64 (26+28+10)
Node.sum_key: 115 (30+73+12)
Node.sum_key: 132 (83+46+03)
Node.sum_key: 79 (25+00+54)
Node.sum_key: 118 (77+07+34)
Node.sum_key: 96 (31+44+21)
Node.sum_key: 83 (10+56+17)
Node.sum_key: 146 (68+37+41)
Node.sum_key: 117 (19+9+89)
Node.sum_key: 129 (99+30+0)

Heap keys in array
223, 212, 150, 203, 156, 143, 138, 144, 176, 130, 64,115, 132, 79, 118, 96,
83, 146, 117, 129





