#Homework 3
山口 Mondo :jp:, Daniel Sjarif :neckbeard:, Alex Verdin :tada:
##Problem 1
```C
#include <stdio.h>
#include <stdlib.h>

// Global variables
int cols,
    currentDay,
    currentRow,
    currentColumn,
    numOfKids,
    numOfDays,
    rows;

void backTrack();
int checkSolution(int [][rows][cols], int [][numOfKids]);
void initialOptimizations(int [][rows][cols], int [][numOfKids], int [][numOfKids]);
int isValidInput(int, int);
int fillInEntry(int, int, int, int [][rows][cols], int [][numOfKids], int [][numOfKids]);
void goToNextEntry();
void printSolution(int [][rows][cols]);
void zeroOutAdj(int [][numOfKids]);
void zeroOutSolution(int [][rows][cols]);
void zeroOutUnavailable(int [][numOfKids]);


int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Invalid number of arguments. Please enter number of rows and number of columns.\n");
        return 1;
    }

    char * end;
    rows = (int)strtol(argv[1], &end, 10);
    cols = (int)strtol(argv[2], &end , 10);

    if(!isValidInput(rows, cols)) {
        printf("Impossible!\n");
        return 1;
    }

    numOfKids = rows * cols;
    /*
     * Each child needs to share a row with every other child
     * in the group. Each day that child can share a row with
     * at most cols - 1 students. The total number of
     * days required to share a row with all the other
     * numOfKids - 1 students is the ratio given below.
     */
    numOfDays = (numOfKids - 1)/(cols - 1);
    int solution[numOfDays][rows][cols];
    int adjacencyTable[numOfKids][numOfKids];

    zeroOutSolution(solution);
    zeroOutAdj(adjacencyTable);

    currentDay = 1;
    currentRow = 0;
    currentColumn = 1;

    // A checklist for each day that let's us know which
    // girls have already been taken.
    int unavailable[numOfDays][numOfKids];
    zeroOutUnavailable(unavailable);
    int success;

    // Fill in the first day and fill in part of the first columnn.
    initialOptimizations(solution, adjacencyTable, unavailable);
    int counter = 0;

    // Until we're done...
    while(1) {
       // ..Try to fill in the current solution...
        counter += 1;
        if (counter % 500 == 0) {
            counter = 0;
        }
        success = fillInEntry(currentDay, currentRow, currentColumn, solution, adjacencyTable, unavailable);
        if (success) {
            // ..if viable, go to next spot...
            goToNextEntry();
            // .. If we finished the last day, we're done...
            if (currentDay == numOfDays) {
                printf("Solution found\n");
                printSolution(solution);
                zeroOutAdj(adjacencyTable);
                success = checkSolution(solution, adjacencyTable);
                if(success) {
                    printf("Solution correct!\n");
                } else{
                    printf("Solution failed!\n");
                }

                return 0;
            }
        } else {
            // .. else back track...
            // When we back track, we have to skip over the
            // fixed days.
            backTrack();
            // ..if we couldn't find anything quit...
            if (currentDay == 1 && currentRow == 0 && currentColumn == 0){
                printf("No solutions exist\n");
                return 0;
            }
        }

     }

     // Print the solution
     printSolution(solution);

     return 0;
};

void goToNextEntry() {
    currentColumn = (currentColumn + 1) % cols;
    if (currentColumn == 0) {
        currentRow = (currentRow + 1) % rows;
        if(currentRow == 0) {
            currentDay += 1;
        }
    }
    // If we are in one of the fixed entries skip.
    if(currentColumn == 0 && currentRow < cols) goToNextEntry();
}

void backTrack(){
    currentColumn = (currentColumn + cols - 1) % cols;
    if( currentColumn == 0 && currentRow < cols) {
        currentColumn = (currentColumn + cols - 1) % cols;
    }
    if (currentColumn == cols - 1) {
        currentRow = (currentRow + rows - 1) % rows;
        if (currentRow == rows - 1) {
            currentDay -= 1;
        }
    }
    if(currentColumn == 0 && currentRow < cols) backTrack();
}

void zeroOutSolution(int sol[][rows][cols]) {
    int col,
        day,
        row;

    for(day = 0; day < numOfDays; day += 1) {
        for(row = 0; row < rows; row += 1) {
            for(col = 0; col < cols; col += 1) {
                sol[day][row][col] = 0;
            }
        }
    }
}

void zeroOutAdj(int adjTable[][numOfKids]) {
    int col,
        row;

    for(row = 0; row < numOfKids; row += 1) {
        for(col = 0; col < numOfKids; col += 1) {
            adjTable[row][col] = 0;
        }
    }
}

void zeroOutUnavailable(int unavailable[][numOfKids]) {
    int day,
        child;

    for(day = 0; day < numOfDays; day += 1) {
        for(child = 0; child < numOfKids; child += 1) {
            unavailable[day][child] = 0;
        }
    }

}

int fillInEntry(int day, int row, int col, int solution[][rows][cols], int adjTable[][numOfKids], int unavailable[][numOfKids]) {
    // If we are in a preoptimized place get out.
    if(row < cols && col == 0){
        return 1;
    }

    int currentChild,
        previousChild,
        previousCol,
        currentSolution;

    currentSolution = solution[day][row][col];
    // If we have nothing there right now.
    if(currentSolution == 0) {
        currentChild = (col == 0) ? solution[day][row - 1][col] + 1 : solution[day][row][col - 1] + 1;
    } else {
        // Else we have to clear it.
        for(previousCol = 0; previousCol < col; previousCol += 1) {
            previousChild = solution[day][row][previousCol];
            adjTable[previousChild][currentSolution] = 0;
            adjTable[currentSolution][previousChild] = 0;
        }
        unavailable[day][currentSolution] = 0;
        currentChild = currentSolution + 1;
    }

    for(; currentChild < numOfKids; currentChild += 1) {
        // If that child has already been placed continue.
        if (unavailable[day][currentChild]) continue;
        // Check if this child has already shared a row.
        for(previousCol = 0; previousCol < col; previousCol += 1) {
            previousChild =  solution[day][row][previousCol];
            // If it has shared a row with someone else break out early.
            if(adjTable[previousChild][currentChild]) break;
            // The numbers in the very last row of the first day
            // must be in the last column
            if(numOfKids - currentChild <= cols && col != cols - 1) {
                break;
            }
        }
        // If we checked all girls in the row and we're fine, place
        // current child in the partial solution.
        if(previousCol == col) {
            solution[day][row][col] = currentChild;
            for(previousCol = 0; previousCol < col; previousCol += 1) {
                previousChild = solution[day][row][previousCol];
                adjTable[previousChild][currentChild] = 1;
                adjTable[currentChild][previousChild] = 1;
                unavailable[day][currentChild] = 1;
            }
            return 1;
        }
    }
    // Else we failed.
    // If this was already a 0(empty) we don't need to change the adjacency table.
    if(currentSolution != 0) {
        solution[day][row][col] = 0;
        for(previousCol = 0; previousCol < col; previousCol += 1) {
            previousChild = solution[day][row][previousCol];
            adjTable[previousChild][currentSolution] = 0;
            adjTable[currentSolution][previousChild] = 0;
        }
    }
    return 0;

}

/*
 * This problem can't be solved if the number of days
 * required to share a row with every other child once
 * and only once is not an integer.
 */
int isValidInput(int numOfRows, int numOfCols ) {
    return (( numOfRows * numOfCols - 1 ) % ( numOfCols - 1 ) == 0);
}

void initialOptimizations(int solution[][rows][cols], int adjTable[][numOfKids], int unavailable[][numOfKids]) {

    int child, day, row;

    /*
     * The first day is simple. We list the children in ascending
     * order, left-to-right, top-to-bottom.
     */
    for(child = 0; child < numOfKids; child += 1) {
        solution[0][child / cols ][child % cols] = child;
    }

    /*
     * Since we know that kids 0, 1, ... cols - 1 have already
     * shared a row, we can designate them to be the first kids in
     * rows 0 through cols - 1.
     */
    for(day = 1; day < numOfDays; day += 1) {
        for(row = 0; row < cols; row += 1) {
            solution[day][row][0] = row;
            unavailable[day][row] = 1;
        }
    }

    /*
     * We fill the adjacency table.
     */
    int firstChild, currentChild, maxChild;
    for(firstChild = 0; firstChild < numOfKids; firstChild += cols) {
        for(currentChild = firstChild, maxChild = firstChild + cols; currentChild < maxChild; currentChild += 1) {
            for(child = firstChild; child < maxChild; child += 1){
                adjTable[currentChild][child] = 1;
            }
        }
    }
}

void printSolution(int solution[][rows][cols]) {
    int row, col, day;
    for(row = 0; row < rows; row += 1) {
        printf("| ");
        for(day = 0; day < numOfDays; day += 1) {
            for(col = 0; col < cols; col += 1) {
                 printf("%-3i", solution[day][row][col]);
            }
            printf("| ");
        }
        printf("\n");
    }
}

int checkSolution(int solution[][rows][cols], int adjTable[][numOfKids]) {
    int day, row, col, child, previousChild, previousCol;
    for(day = 0; day < numOfDays; day += 1) {
        for(row = 0; row < rows; row += 1) {
            for(col = 0; col < cols; col += 1) {
                child = solution[day][row][col];
                for(previousCol = 0; previousCol < col; previousCol += 1) {
                    previousChild = solution[day][row][previousCol];
                    if(adjTable[previousChild][child] == 0){
                        adjTable[previousChild][child] = 1;
                    } else {
                        printf("Invalid solution!!!\n");
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

```

##Problem 2
```python
##Python 2
##download python 2 and run the code in cmd this way: py -2 backtracker.py
##https://www.python.org/downloads/


def backtracker(choice_points, choices, assignable):
    N = len(choices)
    M = len(choice_points)
    
    # solutions is the dict that has for each choice point (key) a choice (value)
    solutions = {}
    
    cp=0
    c=0
    backtrack=False
    end=False
        
    while(not end):
        #forward
        while(not backtrack):
            if(assignable( cp, c, solutions)):
                solutions[cp] = c
                if(cp==M-1):
                    yield {choice_points[k]:choices[v] for k,v in solutions.iteritems()}
                    del solutions[cp]
                    if not c==N-1:
                        c+=1
                    else:
                        backtrack = True
                else:
                    cp+=1
                    c=0
            elif( c!=N-1):
                c+=1
            else:
                backtrack=True

        #backward
        end=(cp==0)
        while( backtrack and not end ):
            cp-=1
            c=solutions.pop(cp)
            if( not c==N-1 ):
                c+=1
                backtrack=False;
            elif(cp==0 ):
                end=True
```
```python
    ############# 8 Queens Problem ###############    
    rows = ['1', '2', '3', '4', '5', '6', '7', '8']
    columns = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
    
    def queens(row, column, solutions):
        for r, c in solutions.iteritems():
            if c == column:
                return False
            elif r-c == row-column:
                return False
            elif r+c == row+column:
                return False
        return True 
    
    for s in backtracker(rows, columns, queens):
        print(s)
```
```python
    ############## 4 Colors Problem #############
    # neighbors = [set(), set(),set(),set(),set()]
    # neighbors[0].add(1)
    # neighbors[0].add(2)
    # neighbors[1].add(2)
    # neighbors[1].add(3)
    # neighbors[1].add(0)
    # neighbors[2].add(0)
    # neighbors[2].add(1)
    # neighbors[2].add(4)
    # neighbors[3].add(1)
    # neighbors[3].add(4)
    # neighbors[4].add(2)
    # neighbors[4].add(3)


    # nations = ['Italy','Spain','France','Germany','England']
    # colors = ['Yellow','Red','Blue','Black']
    
    # def assignable4Colors(nation, color, solutions):
    #     """
    #     It's assignable a color to a nation if it's empty the intersection between neighbors of nation
    #     and the nations of the same color in solutions.
    #     """
    #     sameColor = set([n for n,c in solutions.iteritems() if c==color ])
    #     return neighbors[nation].isdisjoint(sameColor)
    
    
    # for s in backtracking(nations, colors, assignable4Colors):
    #     print(s)
```

credits: 
juansc - kirkman
Filippo Squillace - backtracker
