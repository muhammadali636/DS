# CIS2520-F24-A2

## Student Information 
Name : MUHAMMAD ALI

Student Number : 1115336

## Assignment Overview
What is the assignment about?  
this assignment is to strengthen my ability to work with data structures like singly linkedlists and stacks.
The first problem is about car rentals, and we have to use three linkedlists for that and manipulate them for different user operations.
The second assignment is about postfix operations and it uses the stack for that. 

Explain the purpose of the program and what it accomplishes.
This assignment has two main parts to help me practice using linked lists and stacks. Firstly, to create a system to manage cars for a rental company. There will have to be three lists for cars: available, rented, and in repair. It will let user add cars,  send cars to and from repair, and rent out cars and handle returns, It will also calc the fees for returned cars, checks to make sure inputs like plate numbers are correct, and save everything to files so the data is there for next time.

Second part is about a program to solve math expressions written in Reverse Polish Notation,  where the operators come after  numbers. A stack implemented linkedlist style will be used. the program will take an expression like "12+53-*" and calculate the result as a float/double. It will also check for errors in the input.



## Resources 
Did you use any resources (for example book, notes etc) in this assignment?

I used mainly the lecture on stack for stack linkedlist implementation and referenced a lot of previous code I wrote from previous classes like CIS2500 and CIS1300 for things like removing the null terminator from strings, file reading and loading etc etc. For the makefile I literally reused the same structuring from cis2500, since I havent used a makefile in a while. 

## Implementation
The assignment is complete. Unzip the file first. Open up terminal or powershell or whatever command line you got. Then Execute the makefile using the make command. 
once u do make, you can do ./a2q1 or ./a2q2 to run either question.
if u want to clean everything up do make clean.
Use valgrind to check for memory leaks (shouldnt be any)

For Q1 make sure the files read are exactly named repair.txt, rented.txt, and available.txt otherwise the program will have trouble loading these files because the names are hardcoded. 

Use the following test cases to validate Q2:
56+32*-2/ => 2.5
89-35*/ => -0.07
92-31*+73+-2/ => 0
<blank> => Incorrect input 
25+58*/ => 0.17
89*35*+79*+ => 150
93/62/-84/-51/- => -7
72*51*-39*+62/+ => 39


