#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void print_puzzle(int input[])
{
    printf("\n");
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if (input[9*i + j] != 0)
                printf("%d ", input[9*i + j]);
            else
                printf("  ");
            if((j == 2) || (j == 5))
                printf("| ");
        }
        printf("\n");
        if((i == 2) || (i == 5))
        {
            printf("---------------------\n");
        }  
    }
}

bool is_valid(int input[], int index, int val)
{
    int row = index / 9;
    int col = index % 9;
    int row_0 = row - row % 3;
    int col_0 = col - col % 3;
    // check cell
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if((row_0 + i != row) && (col_0 + j != col))
            {
                if(input[9 * (row_0 + i) + col_0 + j] == val)
                {
                    return false;
                }
            }
        }
    }
    // check colume
    for(int i = 0; i < 9; i++)
    {
        if(i != col)
        {
            if(input[9 * row + i] == val)
            {
                return false;
            }
        }
    }
    // check row
    for(int i = 0; i < 9; i++)
    {
        if(i != row)
        {
            if(input[9 * i + col] == val)
            {
                return false;
            }
        }
    }

    return true;
}

//How many solutions user needed if possiable.
unsigned long long int solution_need = 1;

bool solver(int input[], int index)
{
    int l_puzze[81];
    memcpy(l_puzze, input, 81 * sizeof(int));

    if(index == 81)
    {
        print_puzzle(input);
        solution_need = (solution_need > 0) ? solution_need - 1 : solution_need;
        if((solution_need < 0) || (0 < solution_need))
        {
           return false; //continue solve
        }
        return true; //stop solve
    }
    // not empty, next start
    if(l_puzze[index] != 0)
    {
        return solver(l_puzze, index + 1);
    }

    // empty, try from 1 to 9
    for(int i = 1; i <= 9; i++)
    {
        if(is_valid(l_puzze, index, i))
        {
            l_puzze[index] = i;
            if(solver(l_puzze, index + 1))
            {
                return true;
            }
        }
    }

    // not find a fit in 1 to 9, just return
    return false;
}

int main(int argc, char* argv[])
{
    int puzzle[81];

    // check parameter count
    if(argc != 3)
    {
        return -1;
    }
    // config the solver
    if(argv[1][0] == 'n' || argv[1][0] == 'N')
    {
        solution_need = -1;
    }
    else if(strtoull(argv[1], NULL, 10) >= 1)
    {
        solution_need = strtoull(argv[1], NULL, 10);
    }
    else
    {
        solution_need = 1;
    }

    // get input puzzle 
    if(strlen(argv[2]) != 81)
    {
        return -1;
    }
    for(int i = 0; i < 81; i++)
    {
        if(('1' <= argv[2][i]) && (argv[2][i] <= '9'))
            puzzle[i] = argv[2][i] - '0';
        else
            puzzle[i] = 0;
    }

    print_puzzle(puzzle);

    // solve puzzle
    solver(puzzle, 0);

    return 0;
}
