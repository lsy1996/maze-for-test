#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    char letter = 'A', grid[10][10] = {0};
    int i = 0, j = 0,
        up = 0, down = 0, left = 0, right =0, move = 0;
    grid[0][0] = letter++;

    srand((unsigned) time(NULL));

    while (letter <= 'Z')
    {
        up = 0, down = 0, left = 0, right =0, move = 0;
        if (j+1 < 10 && grid[i][j+1] == 0)  /*方向键为1说明可以往这个方向走*/
            down = 1;
        if (j-1 >= 0 && grid[i][j-1] == 0)
            up = 1;
        if (i+1 < 10 && grid[i+1][j] == 0)
            right = 1;
        if (i-1 >= 0 && grid[i-1][j] == 0)
            left = 1;
        
        if (up + down + left + right == 0)
            break;

        move = rand() % 4;

        switch (move)
        {
            case 0:
                if(up) 
                {
                    grid[i][--j] = letter++;
                    break;
                }
            case 1:
                if(down) 
                {
                    grid[i][++j] = letter++;
                    break;
                }
            case 2:
                if(left) 
                {
                    grid[--i][j] = letter++;
                    break;
                }
            case 3:
                if(right) 
                {
                    grid[++i][j] = letter++;
                    break;
                }
            default:
                break;
        }
    }
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (grid[i][j] == 0)
            {
                grid[i][j] = '.';
            }
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}