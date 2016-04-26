##Problem 4
```
while Q is not empty do
u ← vertex in Q with smallest dist[]
for all edges (u, v) ∈ E do
if dist(v)>dist(u)+l(u, v) then
dist(v)← dist(u)+l(u, v)
best(v)← best(u)+1
if dist(v)=dist(u)+l(u, v) then
if best(v)>best(u)+1 then
best(v)← best(u)+1
```
##Problem 5
```python
#Python 2!!!
from collections import defaultdict
from heapq import *
 
def prim(nodes, edges):
    conn = defaultdict( list )
    for n1,n2,c in edges:
        conn[n1].append( (c, n1, n2))
        conn[n2].append( (c, n2, n1))
 
    mst = []
    used = set( nodes[ 0 ] )
    usable_edges = conn[ nodes[0] ][:]
    heapify( usable_edges )
 
    while usable_edges:
        cost, n1, n2 = heappop(usable_edges)
        if n2 not in used:
            used.add(n2)
            mst.append((n1, n2, cost))
 
            for e in conn[n2]:
                if e[2] not in used:
                    heappush(usable_edges, e)
    return mst

    
string = "A,B,3|C,A,4|B,C,9|D,E,2|E,A,6"
lst = list(string.replace(',','').replace('|',''))

newlist = [lst[x:x+3] for x in range(0, len(lst),3)]

nodes = list("ABCDEFG")
edges = newlist


a = prim(nodes, edges)
listtostring = ','.join(str(r) for v in a for r in v)
bordered ='|'.join(listtostring[i:i+6] for i in range(0, len(listtostring), 6))
print(bordered)
```

