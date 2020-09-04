Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string. Given a string, find the number of pairs of substrings of the string that are anagrams of each other.

For example ***s=mom***, the list of all anagrammatic pairs is [***m***, ***m***], [***mo***, ***mo***] at positions respectively [[***0***, ***2***]], [[***0***, ***1***], [***1***, ***2***]].

### Input Format

The first line contains an integer *q*, the number of queries.

Each of the next *q* lines contains a string *s* to analyze. 

### Constraints

* 1 ≤ q ≤ 10
* 2 ≤ |s| ≤ 100

String *s* contains only lowercase letters ∈ ascii[a-z].

### Output Format

For each query, return the number of unordered anagrammatic pairs. 

### Sample Input 0

2

abba

abcd

### Sample Output 0

4

0

### Explanation 0

The list of all anagrammatic pairs is [***a***, ***a***], [***ab***, ***ba***], [***b***, ***b***] and [***abb***, ***bba***] at positions [[***0***], [***3***]], [[***0***, ***1***], [***2***, ***3***]], [[***1***], [***2***] and [[***0***, ***1***, ***2***], [***1***, ***2***, ***3***]] respectively.

No anagrammatic pairs exist in the second query as no character repeats.

### Sample Input 1

2

ifailuhkqq

kkkk

### Sample Output 1

3

10

### Explanation 1

For the first query, we have anagram pairs [***i***, ***i***], [***q***, ***q***] and [***ifa***, ***fai***] at positions [[***0***], [***3***]], [[***8***], [***9***]] and [[***0***, ***1***, ***2***], [***1***, ***2***, ***3***]] respectively.

For the second query:

There are 6 anagrams of the form [***k***, ***k***].

There are 3 anagrams of the form [***kk***, ***kk***].

There is 1 anagram of the form [***kkk***, ***kkk***].

[Link to problem](https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem)
