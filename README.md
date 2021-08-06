# Reach_the_node

The project starts with taking input from the user (n) vertices and (n-1) edges between them which represent a tree.
After that it creates bidirectional graph. It allows the user to check whether the distance between a and b (two nodes in the tree) can be reached with exactly k moves (edges).
What special about this trees that you will create a temporary (x to y) edge with each query. 
to solve this problem BFS can be used to search all possible paths from a to b:
o	direct path from a to b
o	by using x y edge from a to b
o	by using y x edges from a to b 
then the program will check if there is a path that connects a to b with k edges distance
if the condition was satisfied 
then it prints YES.
otherwise prints NO.
