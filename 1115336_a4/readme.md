# CIS2520-F24-A4

## Student Information 
Name : MUHAMMAD ALI

Student Number : 1115336

## Assignment Overview
What is the assignment about?  

This assignment is about processesing a graph from its adjacency matrix stored in a .txt file. The program reads the adjacency matrix and can display the adjacency list, perform Breadth First Search, Depth First Search, and finding the shortest paths using Dijkstra's Algorithm.

Explain the purpose of the program and what it accomplishes.
The purpose of the program is get experience working with graph data structures and implement djikstras algorithm. 

## Resources 
Did you use any resources (for example book, notes etc) in this assignment?
I used mainly the lecture on graphs, to help with Q4. I also used old assignments to help me out with stacks/queues and for reading files, especially from CIS2500. I also referenced geeks for geeks (which was such a great resource): https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/#inorder-traversal
https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

For the makefile I literally reused the same structuring from cis2500 which i have used for the last 2 assignments too. 


## Implementation
Is the assignment complete? If not, mention what part of the assignment is missing or incomplete.
The assignment is complete. 
The code should be complete for THIS assignment, but it only works for vertex 1 as a **starting point** (hardcoded) for the assignment, which is fine here but if i want to expand it later it wont be so great. 

to run the program type:  make.

test case:
make a text file named example-graph.txt for testing which will include:
0 4 5 0 0
4 0 1 9 2
5 1 0 0 3
0 9 0 0 0
0 2 3 0 0

now do ./a2graph example-graph.txt.

Test output:
Menu:
1. Display Adjacency List
2. Perform Breadth-First Search (BFS)
3. Perform Depth-First Search (DFS)
4. Find Shortest Path using Dijkstra's Algorithm
5. Exit
Enter your choice: 1
Adjacency List:
Vertex 1: -> 2 (4) -> 3 (5) NULL
Vertex 2: -> 1 (4) -> 3 (1) -> 4 (9) -> 5 (2) NULL
Vertex 3: -> 1 (5) -> 2 (1) -> 5 (3) NULL
Vertex 4: -> 2 (9) NULL
Vertex 5: -> 2 (2) -> 3 (3) NULL

Menu:
1. Display Adjacency List
2. Perform Breadth-First Search (BFS)
3. Perform Depth-First Search (DFS)
4. Find Shortest Path using Dijkstra's Algorithm
5. Exit
Enter your choice: 2
Final BFS Order:
1 2 3 4 5 

Menu:
1. Display Adjacency List
2. Perform Breadth-First Search (BFS)
3. Perform Depth-First Search (DFS)
4. Find Shortest Path using Dijkstra's Algorithm
5. Exit
Enter your choice: 3
1 2 3 5 4 

Menu:
1. Display Adjacency List
2. Perform Breadth-First Search (BFS)
3. Perform Depth-First Search (DFS)
4. Find Shortest Path using Dijkstra's Algorithm
5. Exit
Enter your choice: 4

Shortest distance from vertex 1 to vertex 1: 0
Shortest distance from vertex 1 to vertex 2: 4
Shortest distance from vertex 1 to vertex 3: 5
Shortest distance from vertex 1 to vertex 4: 13
Shortest distance from vertex 1 to vertex 5: 6

Menu:
1. Display Adjacency List
2. Perform Breadth-First Search (BFS)
3. Perform Depth-First Search (DFS)
4. Find Shortest Path using Dijkstra's Algorithm
5. Exit
Enter your choice: 5
Exiting...


