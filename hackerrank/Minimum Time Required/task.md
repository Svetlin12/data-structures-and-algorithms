You are planning production for an order. You have a number of machines that each have a fixed number of days to produce an item. Given that all the machines operate simultaneously, determine the minimum number of days to produce the required order.

For example, you have to produce ***goal=10*** items. You have three machines that take ***machines=[2,3,2]*** days to produce an item. The following is a schedule of items produced: 

|Day| Production | Count |
|---|------------|-------|
|2  | 2          |     2 |
|3  | 1          |     3 |
|4  | 2          |     5 |
|6  | 3          |     8 |
|8  | 2          |    10 |

It takes **8** days to produce **10** items using these machines. 

### Input Format

The first line consist of two integers ***n*** and ***goal***, the size of ***machines*** and the target production. The next line contains ***n*** space-separated integers, ***machines[i]***.

### Constraints

* 1 ≤ n ≤ 10<sub>5</sub>
* 1 ≤ goal ≤ 10<sub>9</sub>
* 1 ≤ machines[i] ≤ 10<sub>9</sub>

### Output Format

Return the minimum time required to produce ***goal*** items considering all machines work simultaneously. 

### Sample Input 0

2 5

2 3

### Sample Output 0

6

### Explanation 0

In 6 days machine<sub>0</sub> can produce 3 items and machine<sub>1</sub> can produce 2 items. This totals up to 5.

### Sample Input 1

3 10

1 3 4

### Sample Output 1

7

### Explanation 1

In 7 minutes, machines<sub>0</sub> can produce 7 items, machines<sub>1</sub> can produce 2 items and machines<sub>2</sub> can produce 1 item, which totals up to 10. 

### Sample Input 2

3 12

4 5 6

### Sample Output 2

20

### Explanation 2

In 20 days machine[0] can produce 5 items, machines[1] can produce 4, and machine[2] can produce 3.

[Link to problem](https://www.hackerrank.com/challenges/minimum-time-required/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search)
