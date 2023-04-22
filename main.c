#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define PASSWORD "abc102030no"
//Polynomial is the solution for problem 1
void polynomial();
void polynomial()
{
    //This first part is what will take the longest - setting up the variables for the calculation
    int poly_degree;
    int x_val;
    int sum = 0;
    printf("Enter polynomial degree: ");
    scanf("%d", &poly_degree);
    if(poly_degree < 0 || poly_degree > 10)
    {
        printf("The integer needs to be between 0 and 10, try again\n");
        polynomial();
    }
    int coefficients[poly_degree + 1];
    for(int i = 0; i < poly_degree + 1; i++)
    {
        printf("(Left to Right) Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &coefficients[i]);
    }
    printf("Enter the value of X: ");
    scanf("%d", &x_val);
    //Now we do the math and display part
    int coefficient_track = 0;
   for(int degree = poly_degree; degree >= 0; degree--)
   {
       sum += coefficients[coefficient_track] * pow(x_val, degree);
       coefficient_track++;
   }
   printf("******************************\nDegree of Polynomial = %d\nCoefficients = ", poly_degree);
   for(int i = 0; i < poly_degree + 1; i++)
       printf("%d ", coefficients[i]);
   printf("\nValue of X = %d\nValue of Polynomial = %d\n******************************", x_val, sum);
}
//Parkingcheck and Parkinglot work together to solve problem 2
void parkingcheck(int lot[3][4]);
void parkingcheck(int lot[3][4])
{
    int row, col;
    printf("Enter the spot you'd like to check in the form of row, column: ");
    scanf("%d, %d", &row, &col);
    if(lot[row-1][col-1] == 1)
        printf("Available!\n");
    else if(lot[row-1][col-1] == 0)
        printf("Unavailable.\n");
    else
        printf("That spot does not exist.\n");
    int ans;
    printf("Would you like to try another spot? Input 1 for yes and 0 to cancel: ");
    scanf("%d", &ans);
    if(ans == 1)
        parkingcheck(lot);
    else
        exit;
}
void parkinglot();
void parkinglot()
{
    //First part of this problem, in which I initialize the parking lot and display it all available
    int visual_lot[3][4] = {
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 1}
    };
    printf("Original Lot: \n");
    for(int rows = 0; rows < 3; rows++)
    {
        for(int cols = 0; cols < 4; cols++)
        {
            printf("%d ", visual_lot[rows][cols]);
        }
        printf("\n");
    }
    //Second Part: Updating the parking lot (This part was very unspecific. Does (3,3) and (1,3) refer to indexes
    //or to row 3 column 3 and row 1 column 3? I went with the former considering index 3 would be out of bounds for rows)
    printf("Current Lot: \n");
    visual_lot[2][2] = 0;
    visual_lot[0][2] = 0;
    for(int cols = 0; cols < 4; cols++)
        visual_lot[0][cols] = 0;
    for(int rows = 0; rows < 3; rows++)
        visual_lot[rows][1] = 0;
    for(int rows = 0; rows < 3; rows++)
    {
        for(int cols = 0; cols < 4; cols++)
        {
            printf("%d ", visual_lot[rows][cols]);
        }
        printf("\n");
    }
    parkingcheck(visual_lot);
}
//Fizzbuzz is the solution for problem 3
//PS, the given for input 18 in the exam does not include 0 like the directions say to
//But 0 is divisible by everything, so it'll always be fizzbuzz anyway
int fizzbuzz();
int fizzbuzz()
{
    int input;
    printf("Please input an integer below 100: ");
    scanf("%d", &input);
    if(input >= 100)
    {
        printf("Input too large. Try again\n");
        fizzbuzz();
    }
    for(int i = 0; i <= input; i++)
    {
        if(i % 3 == 0 && i % 5 == 0)
            printf("fizzbuzz ");
        else if(i % 3 == 0)
            printf("fizz ");
        else if(i % 5 == 0)
            printf("buzz ");
        else
            printf("%d ", i);
    }
    int next_fb;
    int i = input + 1;
    while(next_fb == NULL)
    {
        if(i % 3 == 0 && i % 5 == 0)
            next_fb = i;
        i++;
    }
    printf("\nThe next fizzbuzz is: %d", next_fb);
    return(next_fb);
}
//passwordval is the solution for problem 4
void passwordval();
void passwordval()
{
    printf("Please input password (case sensitive): ");
    char input[50];
    scanf("%s", &input);
    if(strcmp(input, PASSWORD) == 0)
        printf("access granted");
    else
        printf("access denied");
}
//animalstruct is the solution for problem 5
void animalstruct();
void animalstruct()
{
    //Creating and filling the structure and array
    struct animal
    {
        char name[50];
        int length, weight, height, tspeed;
    };
    struct animal animals[8];
    for(int i = 0; i < 8; i++)
    {
        printf("Please enter the animal's name, length, height, weight, and top speed separated by spaces. ");
        scanf("%s %d %d %d %d", animals[i].name, &animals[i].length, &animals[i].height, &animals[i].weight, &animals[i].tspeed);
    }
    for(int i = 0; i < 8; i++)
    {
        printf("Animal %d's information: %s, %d cm, %d cm, %d kg, %d km/h\n", i+1, animals[i].name, animals[i].length,
               animals[i].height, animals[i].weight, animals[i].tspeed);
    }
    //Sorting algorithm using a swap with temp
    struct animal temp;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8 - i; j++)
        {
            if(animals[j].weight < animals[j + 1].weight)
            {
                temp = animals[j];
                animals[j] = animals[j + 1];
                animals[j + 1] = temp;
            }
        }
    }
    printf("Animals sorted by weight:\n");
    for(int i = 0; i < 8; i++)
    {
        printf("%s ", animals[i].name);
    }
    //Final part, finding the horse's index using the name
    for(int i = 0; i < 8; i++)
    {
        if(strcmp("Horse", animals[i].name) == 0)
        {
            printf("\nNow that array is sorted, Horse's index is %d", i);
        }
    }
}

int main() {
//polynomial();
//parkinglot();
//fizzbuzz();
//passwordval();
//animalstruct();
}
