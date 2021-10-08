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






    /////////////////////////////////////////////////////

    //Magic Square Generator

    time_t t; //Volatile Variable allows for True Random

    srand((unsigned)time(&t)); //Set random generation based on time.

    int RandomResult = 9; //Holds result of Square Test on Generated Square
    int CreatedSquares = 0; //Counter that contains how many squares we have made.


    do 
    {
    //Now we assign each location in our square a random value form 1-9 with NO duplicates.

    int position1 = ( (rand() % 9) + 1); //This gives a range of possible values from 0 - 9

    int position2 = ( (rand() % 10) + 1);
    while (position2 == position1)
    {
        position2 = ( (rand() % 10) + 1); //Reroll for a new number. No duplicates!
    }

    int position3 = ( (rand() % 10) + 1);
    while (position3 == position2 || position3 == position1)
    {
        position3 = ( (rand() % 10) + 1); //Reroll for a new number. No duplicates!
    }

    int position4 = ( (rand() % 10) + 1);
    while (position4 == position3 || position4 == position2 || position4 == position1)
    {
        position4 = ( (rand() % 10) + 1); //Reroll for a new number. No duplicates!
    }

    int position5 = ( (rand() % 10) + 1);
    while (position5 == position4 || position5 == position3 || position5 == position2 ||
                        position5 == position1)
    {
        position5 = ( (rand() % 10) + 1); //Reroll for a new number. No duplicates!
    }

    int position6 = ( (rand() % 10) + 1);
    while (position6 == position5 || position6 == position4 || position6 == position3 ||
                        position6 == position2 || position6 == position1)
    {
        position6 = ( (rand() % 10) + 1); //Reroll for a new number. No duplicates!
    }

    int position7 = ( (rand() % 10) + 1);
    while (position7 == position6 || position7 == position5 || position7 == position4 ||
                        position7 == position3 || position7 == position2 || position7 == position1)
    {
        position7 = ( (rand() % 10) + 1); //Reroll for a new number. No duplicates!
    }

    int position8 = ( (rand() % 10) + 1);
    while (position8 == position7 || position8 == position6 || position8 == position5 || position8 == position4 ||
                        position8 == position3 || position8 == position2 || position8 == position1)
    {
        position8 = ( (rand() % 10) + 1); //Reroll for a new number. No duplicates!
    }

    int position9 = ( (rand() % 10) + 1);
    while (position9 == position8 || position9 == position7 || position9 == position6 ||
                        position9 == position5 || position9 == position4 || position9 == position3 ||
                        position9 == position2 || position9 == position1)
    {
        position9 = ( (rand() % 10) + 1); //Reroll for a new number. No duplicates!
    }

    //Assemble the Square with the previously Generated Values

    int RandomSquare[3][3] =   { {position1, position2, position3 },
                                 {position4, position5, position6 },
                                 {position7, position8, position9 } };

    CreatedSquares++;
    printf("\nSquares generated: %d\n", CreatedSquares);

    RandomResult = ( MagicTest(RandomSquare) );

    if(RandomResult == 1)
    {
        printf("\nSquares Generated: %d\n", CreatedSquares);
        printf("\nThe succesful square is shown below...\n");

        printf("\n[%d %d %d]\n"
                 "[%d %d %d]\n"
                 "[%d %d %d]",  position1, position2, position3,
                                position4, position5, position6,
                                position7, position8, position9);
    }

    }
    while(RandomResult == 0);
    
    
    printf("\nEnding Program...\n");

}






////////////////////////////////////////////////////

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