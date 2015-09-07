//****************** main.cpp ***********************************
//
// CS 3113 Data Structures
//
// Spring 2013
//
// Assignment: 8 Queens
//
// Due Date: 2-27-2013
//
// Instructor: Qualls
//
// Programmer: Will Johnson
//
// Description: Given the starting position for the first queen on
//              a chess board by the user, attempt to solve the 8
//              queens problem by recursion. 
//
// Input: User from console, starting point of first queen
//
// Output: Text to console, solution to 8 queens problem, chess board,
//         time taken to solve problem. 
//
//********************************************************************

#include<iostream>
    using std::cin;
    using std::cout;
    using std::endl;
#include<cstdlib>
#include<ctime>
    using std::time;
#include<sys/time.h>

// Function to print board
void printSolution(int board[]);

// Function to solve board
void solve(int board[], int startRow, int startColumn, int nextRow);

int main(){
    
    // the board will be an array of integers. The index of the array represents the row of the queen
    // and the actual value of that index represents the column
    int* board = new int[8];
    int x, y;
    cout << "Enter a column to place the first queen on (0 - 7): ";
    cin >> x;
    cout  << "Enter the row to place the first queen on (0 - 7): ";
    cin >> y;
    cout << endl;
    board[y] = x;
    
    // Declare variables to determine time
    struct timeval detail_time_start;
    struct timeval detail_time_stop;
    
    // get current time of day for start time
    gettimeofday(&detail_time_start, NULL);
    
    solve(board, y, x, 0); // solve the board
    
    //get current time of day for stop time
    gettimeofday(&detail_time_stop, NULL);
    
    // total time taken is stop time - start time
    double total_time = (detail_time_stop.tv_usec - detail_time_start.tv_usec);
    
    cout << "Time taken to solve the 8 Queens Problem: " << total_time << " microseconds." << endl;
    cout << endl;
    
    return 0;
}

/* Function to print the solution
 * @param board - array of locations of queens
 */
void printSolution(int board[]){
    cout << endl << "Success. Solution found." << endl;
    cout << endl << "Solution: " << endl;
    cout << "---------------------------------" << endl;
    for(int i = 0; i < 8; i++){ // for all 8 rows
        cout << "|";
        for(int j = 0; j < 8; j++){ // all 8 spots in each row
            if(board[i] == j){ // if a queen is in this spot
                cout << " Q ";
            }
            else{ // queen not in this spot
                cout << "   ";
            }
            cout << "|";
        }
        cout << endl << "---------------------------------" << endl;
    }
    cout << endl;
} // end print


/* Function to solve the board
 * @param board - array of queen locations
 * @param startRow - row first queen was placed on
 * @param startColumn - column first queen was placed on
 * @param nextRow -empty row to start on
 */
void solve(int board[], int startRow, int startColumn, int nextRow){
    // board[startRow] = startColumn is our given start point
    // if we find a solution with this position, print it
    if(nextRow == 8 && board[startRow] == startColumn){ // end of board and solution found with given starting point
        printSolution(board);
    }
    else{
        for(int j = 0; j < 8; j++){ // loop through all possible spots on current row
            bool legal = true;
            for(int i = 0; i < nextRow; i++){ // check conflicts with all prior queens
                if(board[i] == j || board[i] == (j + nextRow - i) || board[i] == (j - nextRow + i)){
                    legal = false;
                }
            }
            if(legal){ // legal to place a queen
                board[nextRow] = j; // place queen
                solve(board, startRow, startColumn, nextRow + 1); // call recursively with next row
            }
        }
    }
} // end solve

