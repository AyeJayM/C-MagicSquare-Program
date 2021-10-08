#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int MagicTest(int TestSquare[3][3]);

void main()
{
    int MagicSquare[3][3] =   { {4, 9, 2 },
                                {3, 5, 7 },
                                {8, 1, 6 } };

    int NotMagicSquare[3][3] = { {1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9} };

    int Result;
    int ResultTwo;

    //Test MagicSquare
    Result = ( MagicTest(MagicSquare) );
    if (Result == 1)
    {
        printf("\nThe array IS a Magic Square\n");
    }
    else if (Result == 0)
    {
        printf("\nThe array is NOT a Magic Square\n");
    }


    //Test NotMagicSquare
    ResultTwo = ( MagicTest(NotMagicSquare) );
    if (ResultTwo == 1)
    {
        printf("\nThe array IS a Magic Square\n");
    }
    else if (ResultTwo == 0)
    {
        printf("\nThe array is NOT a Magic Square\n");
    }

}

int MagicTest(int TestSquare[3][3])
{
    //Row Tests
    int RowOneSum = TestSquare[0][0] + TestSquare[0][1] + TestSquare[0][2];

    if (RowOneSum != 15)    
    {
        return 0;
    }

    int RowTwoSum = TestSquare[1][0] + TestSquare[1][1] + TestSquare[1][2];

    if (RowTwoSum != 15)
    {
        return 0;
    }

    int RowThreeSum = TestSquare[2][0] + TestSquare[2][1] + TestSquare[2][2];

    if (RowThreeSum != 15)
    {
        return 0;
    }


    //Column Tests
    int ColumnOneSum = TestSquare[0][0] + TestSquare[1][0] + TestSquare[2][0];
    
    if (ColumnOneSum != 15)
    {
        return 0;
    }

    int ColumnTwoSum = TestSquare[0][1] + TestSquare[1][1] + TestSquare[2][1];

    if (ColumnTwoSum != 15)
    {
        return 0;
    }

    int ColumnThreeSum = TestSquare[0][2] + TestSquare[1][2] + TestSquare[2][2];

    if (ColumnThreeSum != 15)
    {
        return 0;
    }

    //Diagnol Tests
    int DiagnolOneSum = TestSquare[0][0] + TestSquare[1][1] + TestSquare[2][2];
    if (DiagnolOneSum != 15)
    {
        return 0;
    }

    int DiagnolTwoSum = TestSquare[0][2] + TestSquare[1][1] + TestSquare[2][0];
    if (DiagnolTwoSum != 15)
    {
        return 0;
    }

//These will help keep track of the number of instances each integer occurs.
 int numOfOnes = 0;
 int numOfTwos = 0;
 int numOfThrees = 0;
 int numOfFours = 0;
 int numOfFives = 0;
 int numOfSixes = 0;
 int numOfSevens = 0;
 int numOfEights = 0;
 int numOfNines = 0;

    // Check for Duplicates
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            if(TestSquare[row][column] == 1)
            {
                numOfOnes++;
                if (numOfOnes > 1)
                {
                    return 0;
                }            
            }

            if(TestSquare[row][column] == 2)
            {
                numOfTwos++;
                if (numOfTwos > 1)
                {
                    return 0;
                }              
            }

            if(TestSquare[row][column] == 3)
            {
                numOfThrees++;
                if (numOfThrees > 1)
                {
                    return 0;
                }        
            }

            if(TestSquare[row][column] == 4)
            {
                numOfFours++;
                if (numOfFours > 1)
                {
                    return 0;
                }
            }

            if(TestSquare[row][column] == 5)
            {
                numOfFives++;
                if (numOfFives > 1)
                {
                    return 0;
                }               
            }

            if(TestSquare[row][column] == 6)
            {
                numOfSixes++;
                if (numOfSixes > 1)
                {
                    return 0;
                }               
            }

            if(TestSquare[row][column] == 7)
            {
                numOfSevens++;
                if (numOfSevens > 1)
                {
                    return 0;
                }              
            }

            if(TestSquare[row][column] == 8)
            {
                numOfEights++;
                if (numOfEights > 1)
                {
                    return 0;
                }               
            }

            if(TestSquare[row][column] == 9)
            {
                numOfNines++;
                if (numOfNines > 1)
                {
                    return 0;
                }               
            }

        }
    }

 return 1; //The square has passed the test!

}