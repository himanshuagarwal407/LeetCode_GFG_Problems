// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    bool UsedInRow(int grid[N][N], int row, int num)
    {
        for (int col = 0; col < N; col++)
            if (grid[row][col] == num)
                return true;
        return false;
    }
     
    bool UsedInCol(int grid[N][N], int col, int num)
    {
        for (int row = 0; row < N; row++)
            if (grid[row][col] == num)
                return true;
        return false;
    }
     
    bool UsedInBox(int grid[N][N], int boxStartRow,
                   int boxStartCol, int num)
    {
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
                if (grid[row + boxStartRow]
                        [col + boxStartCol] ==
                                           num)
                    return true;
        return false;
    }
    bool canFill(int grid[N][N], int row, int col, int num)
    {
        return !UsedInRow(grid, row, num)
           && !UsedInCol(grid, col, num)
           && !UsedInBox(grid, row - row % 3,
                         col - col % 3, num)
           && grid[row][col] == 0;
        
        // for(int i=0; i<9; i++)
        // {
        //     if(grid[i][col]==k)
        //         return false;
                
        //     if(grid[row][i]==k)
        //         return false;
                
        //     if(grid[3*(row/3) + i%3][3*(col/3) + i%3]==k)
        //         return false;
                
        // }
        
        // return true;
    }
    
    bool empty(int grid[N][N], int &row, int &col)
    {
        for(row=0; row<9; row++)
            for(col=0; col<9; col++)
                if(grid[row][col]==0)
                    return true;
        
        return false;
    }
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        int i, j;
        
        if(!empty(grid, i, j))
            return true;
        
        for(int k=1; k<=9; k++)
        {
            if(canFill(grid, i, j, k))
            {
                grid[i][j]=k;
                if(SolveSudoku(grid))
                    return true;
                grid[i][j]=0;
            }
        }
        return false;
        // Your code here
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
                cout << grid[i][j] << " ";
        }
        // Your code here 
    }
};

// {
// public:
//     bool FindUnassignedLocation(int grid[N][N], int &row, int &col)
// {
//     for (row = 0; row < N; row++)
//         for (col = 0; col < N; col++)
//             if (grid[row][col] == 0)
//                 return true;
//     return false;
// }

// bool UsedInRow(int grid[N][N], int row, int num)
// {
//     for (int col = 0; col < N; col++)
//         if (grid[row][col] == num)
//             return true;
//     return false;
// }
 
// bool UsedInCol(int grid[N][N], int col, int num)
// {
//     for (int row = 0; row < N; row++)
//         if (grid[row][col] == num)
//             return true;
//     return false;
// }
 
// bool UsedInBox(int grid[N][N], int boxStartRow,
//               int boxStartCol, int num)
// {
//     for (int row = 0; row < 3; row++)
//         for (int col = 0; col < 3; col++)
//             if (grid[row + boxStartRow]
//                     [col + boxStartCol] ==
//                                       num)
//                 return true;
//     return false;
// }
 
// bool isSafe(int grid[N][N], int row, int col, int num)
// {
//     return !UsedInRow(grid, row, num)
//           && !UsedInCol(grid, col, num)
//           && !UsedInBox(grid, row - row % 3,
//                          col - col % 3, num)
//           && grid[row][col] == 0;
// }

 

// bool SolveSudoku(int grid[N][N])
// {
//     int row;
//     int col;
 
//     if (!FindUnassignedLocation(grid, row, col))
//         // success!
//         return true;
 
//     // Consider digits 1 to 9
//     for (int num = 1; num <= 9; num++)
//     {
         
//         // Check if looks promising
//         if (isSafe(grid, row, col, num))
//         {
             
//             // Make tentative assignment
//             grid[row][col] = num;
 
//             // Return, if success
//             if (SolveSudoku(grid))
//                 return true;
 
//             // Failure, unmake & try again
//             grid[row][col] = 0;
//         }
//     }
    
//     // This triggers backtracking
//     return false;
// }
 

 
 
// /* A utility function to print grid */
// void printGrid(int grid[N][N])
// {
//     for (int row = 0; row < N; row++)
//     {
//         for (int col = 0; col < N; col++)
//             cout << grid[row][col] << " ";
//     }
// }
// };

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends