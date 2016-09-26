/**
 * Search for a String in 2D array
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define R 3
#define C 14

//defining all 8 directions in a 2D array
int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 
bool search2D(char grid[R][C], int row, int col, char* word)
{
	//if the character does not match with word first character 
    if (grid[row][col] != word[0])
      return false;
 
    int len = strlen(word), dir;

	//checking for character in all 8 direction
    for (dir = 0; dir < 8; dir++)
    {
        int k, rd = row + x[dir], cd = col + y[dir];

        for (k = 1; k < len; k++)
        {
            // checking if rd, cd out of bound
            if (rd >= R || rd < 0 || cd >= C || cd < 0)
                break;
 
            // If not matched,  break
            if (grid[rd][cd] != word[k])
                break;
 
            //  Moving in particular direction
            rd += x[dir], cd += y[dir];
        }
 
        // If all character matched, then value of must be equal to length of word
        if (k == len)
            return true;
    }
    return false;
}

void patternSearch(char grid[R][C], char* word)
{
    // Consider every point as starting point and search given word
	int row,col;
    for (row = 0; row < R; row++)
       for (col = 0; col < C; col++)
          if (search2D(grid, row, col, word))
             printf(" %d, %d\n", row, col);
}
 
void main()
{
    char grid[R][C] = {"GEEKSFORGEEKS",
                       "GEEKSQUIZGEEK",
                       "IDEQAPRACTICE"
                      };
					  
	printf("\npattern of GEEKS found at\n");
    patternSearch(grid, "GEEKS");
	printf("\npattern of EEE found at\n");
    patternSearch(grid, "EEE");
}