#最後のHomework４
山口 Mondo :jp:, Daniel Sjarif :neckbeard:, Alex Verdin :tada:
##Problem 1
```python
initial = [0, 7, 4]
temp = []
results = []
commands = ["10", "7", "4"]
steps = []
command = "T"
results.append(initial)

for i in initial:
	if initial[i] == 0:
		i+=1
	else:
		for j in initial and j != i:
			if j == 0 and initial[j] != 10:
				initial[j] += (initial[i] - (initial[j] + initial[i]) - 10)
				initial[i] = (initial[j] + initial[i]) - 10
				command.append("10")
				command.append(commands[i])
				steps.append(command)
				command = "T"
				break
			else if j == 1 and initial[j] != 7:
				initial[j] += (initial[i] - (initial[j] + initial[i]) - 7)
				initial[i] = (initial[j] + initial[i]) - 7
				command.append("7")
				command.append(commands[i])
				steps.append(command)
				command = "T"
				break
			else if j == 1 and initial[j] != 4:
				initial[j] += (initial[i] - (initial[j] + initial[i]) - 4)
				initial[i] = (initial[j] + initial[i]) - 4
				command.append("4")
				command.append(commands[i])
				steps.append(command)
				command = "T"
				break

			for item in results:
				temp = initial
				if initial == item:
					initial = results.length
			if(temp == intial):
				break
print(steps)

```

##Problem 2
a. 
![alt tag](http://i.imgur.com/27T0mTf.png)

b.
![alt tag](http://i.imgur.com/OQY7rdq.png)

##Problem 3
![alt tag](http://i.imgur.com/rlxhMXY.png)

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
##Problem 6
```java
public class SubsetOfSums{

	public static boolean subsetOfSums(int[] c, int d){
		boolean canSum = false; 
		int[][] sumArray = new int[c.length + 1][d];
		for(int i = 0; i <= c.length; i++){
			for(int j = 0; j < d; j++){
				if(i == 0){
					sumArray[i][j] = 0;
				}
				else if(c[i - 1] <= j + 1){
					if(c[i - 1] < j + 1){
						int add = c[i - 1] + sumArray[i - 1][(j + 1) - c[i - 1]];
						if(add >= sumArray[i - 1][j]){
							sumArray[i][j] = add;
						}
						else {
							sumArray[i][j] = sumArray[i - 1][j];	
						}
					}
					else if(c[i - 1] >= sumArray[i - 1][j]){
						sumArray[i][j] = c[i - 1];
					}
					else {
						sumArray[i][j] = sumArray[i - 1][j];
					}
				} else {
				    sumArray[i][j] = sumArray[i - 1][j];
				}
			}
		}

		if(sumArray[c.length + 1][d] == d){
			canSum = true;
		}
		else{
			canSum = false;
		}
		return canSum;
	}

	public static void main(String[] args) {
		int[] c = {2,3,4,10};
		boolean yay = subsetOfSums(c, 12);
		if(yay == true){
			System.out.println("yay");
		} else{
			System.out.println("shit");
		}
	}
}
```
##Problem 7
```java
package util;

import java.util.Arrays;

/**
 * Represents a Tuple of integers.
 * A tuple is a ordered list of elements.
 */
public class IntTuple {

    private int[] elements;

    /**
     * Constructs an IntTuple with the given length, initializing each
     * element to 0.
     */
    public IntTuple(int length) {
        if (length < 0) {
            throw new IllegalArgumentException(
                    "Whoopsie daisy, length cannot be negative.");
        }
        this.elements = new int[length];
    }

    /**
     * Constructs an IntTuple object with the given elements.
     */
    public IntTuple(int[] elements) {
        this.elements = new int[elements.length];
        for (int i = 0; i < elements.length; i++) {
            this.elements[i] = elements[i];
        }
    }

    /**
     * Returns a new IntTuple object with the same elements as this one.
     */
    public IntTuple copy() {
        return new IntTuple(elements);
    }

    /**
     * Returns the int at the given index.
     */
    public int intAt(int index) {
        if (index < 0 || index >= elements.length) {
            throw new IllegalArgumentException("Index out of Bounds: " + index);
        }
        return elements[index];
    }

    /**
     * Sets the element at the given index.
     */
    public void set(int index, int element) {
        if (index < 0 || index >= elements.length) {
            throw new IllegalArgumentException("Index out of Bounds: " + index);
        }
        elements[index]= element;
    }

    /**
     * Returns a new IntTuple that is the sum of this IntTuple and otherTuple.
     */
    public IntTuple plus(IntTuple otherTuple) {
        if (otherTuple == null) {
            return null;
        } else if (otherTuple.elements.length != this.elements.length) {
            throw new IllegalArgumentException(
                    "Cannot add tuples of differing lengths, chief.");
        }
        int[] sumElements = new int[this.elements.length];
        for (int i = 0; i < this.elements.length; i++) {
            sumElements[i] = this.elements[i] + otherTuple.elements[i];
        }
        return new IntTuple(sumElements);
    }

    /**
     * Returns the sum of all the elements of the IntTuple.
     */
    public int sumOfElements() {
        int sum = 0;
        for (int element : elements) {
            sum += element;
        }
        return sum;
    }

    /**
     * Returns the length of the tuple.
     */
    public int length() {
        return elements.length;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder("<" + elements[0]);
        for (int i = 1; i < elements.length; i++) {
            builder.append(", " + elements[i]);
        }
        return builder.append(">").toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }

        if (obj == null) {
            return false;
        }

        if (getClass() != obj.getClass()) {
            return false;
        }

        IntTuple other = (IntTuple)obj;

        if (other.length() != this.length()) {
            return false;
        }

        for (int i = 0; i < this.elements.length; i++) {
            if (this.elements[i] != other.elements[i]) {
                return false;
            }
        }
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + Arrays.hashCode(elements);
        return result;
    }
}
```
```java
package money;

import util.IntTuple;

/**
 * A utility class for making change given an amount of cents and an IntTuple
 * containing the denominations for the coins to use.
 */
public class DynamicChangeMaker {

    /**
     * Using the dynamic programming algorithm, returns an IntTuple containing
     * how many coins of each denomination are required to make the given cents.
     * The returned IntTuple should be the most efficient answer (least possible
     * amount of coins). Returns null if it's impossible to find a solution.
     */
    public static IntTuple makeChange(IntTuple denominations, int cents) {
        IntTuple[][] changeTable = new IntTuple[denominations.length()][cents + 1];
        for (int i = 0; i < denominations.length(); i++) {
            for (int j = 0; j <= cents; j++) {
                changeTable[i][j] = new IntTuple(denominations.length());

                if (j != 0) {
                    if (j >= denominations.intAt(i)) {
                        changeTable[i][j].set(i, 1);
                        changeTable[i][j] = changeTable[i][j].plus(changeTable[i][j - denominations.intAt(i)]);

                        if (i > 0 && changeTable[i - 1][j] != null &&
                            changeTable[i][j] != null && 
                            changeTable[i - 1][j].sumOfElements() < changeTable[i][j].sumOfElements()) {
                            changeTable[i][j] = changeTable[i - 1][j];
                    
                        } else if(i > 0 && changeTable[i][j] == null) {

                            changeTable[i][j] = changeTable[i - 1][j];

                        }

                    } else {

                        if (i > 0) {

                            changeTable[i][j] = changeTable[i - 1][j];

                        } else {

                            changeTable[i][j] = null;
                        }

                    }
                }
            }
        }

        return changeTable[denominations.length() - 1][cents];

    }

    private static void printCoins(IntTuple denominations) {
        System.out.print("coins: ");
        for (int i = 0; i < denominations.length(); i++) {
            System.out.print(denominations.intAt(i) + "c" +
                    (i < denominations.length() - 1 ? ", " : ""));
        }
        System.out.println();
    }

    private static void can_make_change(IntTuple denominations, IntTuple amounts) {
        if (amounts == null) {
            System.out.println("Impossible for these coins.");
        } else {
            for (int i = 0; i < amounts.length(); i++) {
                System.out.println(denominations.intAt(i) +
                        "c: " + amounts.intAt(i));
            }
            System.out.println("total used: " + amounts.sumOfElements());
        }
    }

    private static int[] stringArrayToIntArray(String[] args) {
        int[] coins = new int[args.length - 1];
        for (int i = 1; i < args.length; i++) {
            try {
                coins[i - 1] = Integer.parseInt(args[i]);
                if (coins[i - 1] < 1) {
                    printError("Coin values must be > 0. " +
                            "Value found: " + coins[i - 1]);
                    return null;
                }
                for (int j = 0; j < i - 1; j++) {
                    if (coins[j] == coins[i - 1]) {
                        printError("Duplicate coin value found: " + coins[j]);
                        return null;
                    }
                }
            } catch (NumberFormatException nfe) {
                printError("Not a valid integer: " + args[i]);
                return null;
            }
        }
        return coins;
    }

    private static void printError(String message) {
        System.out.println("ERROR: " + message);
        System.out.println(
                "Usage: java money.DynamicChangeMaker <cents> <demoniations...>");
    }
    
    private static void can_make_change_using_each_coin_once(IntTuple denominations, int amount){
        int sum = 0;
        for(int j = 0; j < denominations.length(); j++){
            sum += denominations.intAt(j);
        }
            if(sum != amount){
                System.out.println("Cannot make change using each coin once");
            }
            else {
                for(int i = 0; i < denominations.length(); i++){
                    System.out.println(denominations.intAt(i) + "c: " + "1");  
                }
                System.out.println("Total used: " + denominations.length());
            }
    }
    private static void can_make_change_with_limited_coins(IntTuple denominations, int amount, int max_coins){
        IntTuple totalCoins = makeChange(denominations, amount);
        if(max_coins < totalCoins.sumOfElements()){
            System.out.println("Cannot make change with limited coins");
        }
        else{
            can_make_change(denominations, totalCoins);
        }
    }

    public static void main(String[] args) {
        boolean validInput = true;
        int cents = 0;
        int[] coinArray = new int[0];
        if (args.length < 1) {
            validInput = false;
            printError("No amount of cents given.");
        } else if (args.length < 2) {
            validInput = false;
            printError("No denominations given.");
        } else {
            try {
                cents = Integer.parseInt(args[0]);
                if (cents < 0) {
                    validInput = false;
                    printError("Can't make change for negative cents: " + cents);
                } else {
                    coinArray = stringArrayToIntArray(args);
                    validInput = coinArray != null;
                }
            } catch (NumberFormatException nfe) {
                validInput = false;
                printError("Not a valid integer: " + args[0]);
            }
        }

        if (validInput) {
            IntTuple denominations = new IntTuple(coinArray);
            IntTuple amounts = makeChange(denominations, cents);
            printCoins(denominations);
            System.out.println("To make change for " + cents +
                    "c, use the following coins:");
            can_make_change(denominations, amounts);
            can_make_change_using_each_coin_once(denominations, cents);
            can_make_change_with_limited_coins(denominations, cents, 3);
        }
    }

    private DynamicChangeMaker() {
        // Constructor left private to prevent instantiating a utility class.
    }
}
```
