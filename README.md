# Set Relations Tester
A console-based relations checker for sets written in C++. 

## Functionality
Can be used to check for the basic properties of relations, including reflexivity, irreflexivity, transitivity, symmetry, & antisymmetry. Can also be used to check if a relation is an equivalence relation or partially-ordered set. 

## Usage
Usage is fairly straightforward. Sets and relations can be integer input in any regular format, including just numbers (ex. 1234 for set, 1112223344 for relations), or in a more typical set/relation style (ex. {1, 2, 3, 4} for set, {(1, 1), (1, 2), (2, 2), (3, 3), (4, 4)} for relations). Handling spaces, brackets, parentheses, and commas is built into the relation handling, but other values are not, so ensure the input only contains these characters.

## Runtime
The runtimes of each function are listed next to their corresponding input key. 
Reflexivity and irreflexivity both run in O(mn) time, with m representing the number of digits in the set and n representing the number of relational pairs. The "Check All" feature runs in O(n^2) in many cases, but can run in O(mn) worst case if the number of digits in the set exceeds the number of relational pairs. 
Symmetry runs in O(n) time, and transitivity, antisymmetry, equivalence relation, and partially-ordered set all run in O(n^2) time.
