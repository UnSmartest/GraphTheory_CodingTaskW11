# Coding Task Week 11
| Student ID | Name |
| ---------- | ---- |
| 5025241012 | Dewey Sutjiadi |
| 5025241086 | Isabel Hayaaulia Ismail |
| 5025241166 | Krisna Widhi Wijaya |
| 5999251114 | Gharbi Yassine |

### Hungarian Algorithm
As for input, simply declare the amount of rows and then the columns. In the code, we just said bulldozers and construction sites because we're using the Week 11 Powerpoint as our test case. After declaring the amount of rows and columns, declare the cost value of each bulldoze to each construction site.
You may use the following as example :
```
4 4
90 75 75 80
35 85 55 65
125 95 90 105
45 110 95 115
```

The output we got is
```
Bulldozer 1 goes to site 2
Bulldozer 2 goes to site 4
Bulldozer 3 goes to site 3
Bulldozer 4 goes to site 1
The total minimum cost will be 275
```

### Welsh-Powell Algorithm
Input format: first line is the number of nodes n and edges m.
Then list the n node names (one per line).
Then list m edges as u v cost. (Cost is ignored for coloring; it’s only kept for a consistent format with the assignment spec.)
The Input should look like this:
```
5 7
A
B
C
D
E
A B 1
A C 1
B C 1
B D 1
C D 1
C E 1
D E 1
```

The Output should look like
```
# Welsh-Powell Coloring Result
Total Colors Used: 3

Color 1: C E 
Color 2: B D 
Color 3: A
```
