A permutation is any possible ordering of the distinct items of a set S. If |S| = n, there are n! permutations. This means that for large sets, it is
computationally infeasible to generate all possible permutations. One well-known
algorithm for generating set permutations (at least for small sets) is presented below:
ALGORITHM Johnson-Trotter(n)
// Input: a positive integer n
// Output: A list of all permutations of {1, 2, ..., n}
initialize the first permutation as 1 2 ... n with directions pointing left
while the last permutation has a mobile element
find its largest mobile element k
swap k and the element to which k is directed
reverse the direction of all elements that are larger than k
add the new permutation to the list
Note: an element is mobile if its direction points to a smaller adjacent element.

                                           
REQUIREMENTS:
Design and implement a program to generate all permutations of the set of least n
positive integers.
