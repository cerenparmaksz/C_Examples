// Sample code for matrix addition
// Header libraries

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Main function
int main(int argc, char* argv[])
{
    // argc used for the number of arguments passed
    // argv[] used for the values of the arguments
    struct timeval start, end; // for time measurements
    int row, col, i, j,col_b,k,col_a;       // array dimensions
    int **a, **b, **c;       // double pointers
    
    
    //--------------------------------------------
    row = atoi(argv[1]);     // ascii to integer conversion
    
    //--------------------------------------------
    col = row;
    col_a=row;
    col_b=row;
    
    // double pointer allocations for each row of the array
    a = (int **)malloc(sizeof(int*)*row);
    b = (int **)malloc(sizeof(int *)*row);
    c = (int **)malloc(sizeof(int *)*row);
    for (i = 0; i < row; i++)
    {
        // pointer allocations for each column of the array
        a[i] = (int *)malloc(sizeof(int)*col);
        b[i] = (int *)malloc(sizeof(int)*col);
        c[i] = (int *)malloc(sizeof(int)*col);
        for (j = 0; j < col; j++)
        {
            // Initializations
            a[i][j] = 0;
            b[i][j] = rand();
            // random numbers
            c[i][j] = rand();
        }
    }
    
      //--------------TRADITIONAL-------------------
    /*
    printf("Traditional\n");
    gettimeofday(&start, NULL);
   for(i = 0; i < row; ++i) {
   for(j = 0; j < col_a; ++j) {
   c[i][j] = 0;
   for(k = 0; k < col_b; ++k) {
   c[i][j] += a[i][k] * b[k][j];}}}
   */
    
    
      //------------ROW MAJOR-------------------------
    printf("Row major\n");
    gettimeofday(&start, NULL);
    for (i = 0; i < row; i++)
    {
        for ( k = 0; k < col_b; k++)
        {
            for ( j = 0; j < col_a; j++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    
    
  
  
    gettimeofday(&end, NULL);
    printf("Time to compute: %4.4f seconds\n", (((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec)) / 1000000.0);
    // Memory deallocation
    for (i = 0; i < row; i++)
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);
   return (0);
}

