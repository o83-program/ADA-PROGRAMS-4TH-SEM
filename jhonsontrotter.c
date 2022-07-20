#include <stdio.h>
#include <stdlib.h>

int LEFT_TO_RIGHT = 1;
int RIGHT_TO_LEFT = 0;



// finding the position
// of largest mobile
// integer in a[].

int searchArr(int a[], int n, int mobile)
{
    for (int i = 0; i < n; i++)

        if (a[i] == mobile)
            return i + 1;

    return 0;
}




int getMobile(int a[], int dir[], int n)
{
    int mobile_prev = 0, mobile = 0;

    for (int i = 0; i < n; i++)
    {
        //dir == 0 => Right to left
        if (dir[a[i] - 1] == RIGHT_TO_LEFT && i != 0)
        {
            if (a[i] > a[i - 1] &&
                a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }

       //dir == 1 => Left to right
        if (dir[a[i] - 1] == LEFT_TO_RIGHT && i != n - 1)
        {
            if (a[i] > a[i + 1] &&
                a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }

    if (mobile == 0 && mobile_prev == 0)
        return 0;
    else
        return mobile;
}

// Prints a single
// permutation

int printOnePerm(int a[], int dir[], int n)
{
    int mobile = getMobile(a, dir, n);
    int pos = searchArr(a, n, mobile);

    // swapping the elements
    // according to the
    // direction
    if (dir[a[pos - 1] - 1] == RIGHT_TO_LEFT)
    {
        int temp = a[pos - 1];
        a[pos - 1] = a[pos - 2];
        a[pos - 2] = temp;
    }
    else if (dir[a[pos - 1] - 1] == LEFT_TO_RIGHT)
    {
        int temp = a[pos];
        a[pos] = a[pos - 1];
        a[pos - 1] = temp;
    }

    // changing the directions
    // for elements greater
    // than largest mobile integer.
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mobile)
        {
            if (dir[a[i] - 1] == LEFT_TO_RIGHT)
                dir[a[i] - 1] = RIGHT_TO_LEFT;

            else if (dir[a[i] - 1] == RIGHT_TO_LEFT)
                dir[a[i] - 1] = LEFT_TO_RIGHT;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d" , a[i]);

    printf(" ");

    return 0;
}



     int fact(int n)
    {
        int res = 1;

        for (int i = 1; i <= n; i++)
            res = res * i;
        return res;
    }


    void printPermutation(int n)
    {
        // To store current
        // permutation
       int a[n];

        // To store current
        // directions
       int dir[n];

        // storing the elements
        // from 1 to n and
        // printing first permutation.
        for (int i = 0; i < n; i++)
        {
            a[i] = i + 1;
            printf("%d", a[i]);
        }
         for (int i = 0; i < n; i++)
            dir[i] = RIGHT_TO_LEFT;

        // for generating permutations
        // in the order.
        for (int i = 1; i < fact(n); i++)
            printOnePerm(a, dir, n);
    }

 int main()
 {
     int n;
     printf("Enter the value of n\n");
     scanf("%d" , &n);
     printPermutation(n);
     return 0;
 }
