#include <stdio.h>

void accept(int arr[10][10], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        printf("for p%d: \n", i + 1);
        for (int j = 0; j < n; j++)
        {
            printf("for r%d: ", j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
}

void safe(int max[10][10], int alloc[10][10], int need[10][10], int avail[10], int m, int n, int seq[10])
{
    int cnt = 0;
    int check[10];
    for (int i = 0; i < m; i++)
    {
        check[i] = 0;
        seq[i] = 0;
    }

    int flag = 0;
    for (int i = 0; i < m; i++)
    {
        flag = 0;
        for (int j = 0; j < m; j++)
        {
            int k = 0;
            if (check[j] == 0)
            {
                for (k = 0; k < n; k++)
                {
                    if (need[j][k] > avail[k])
                    {
                        break;
                    }
                }

                if (k == n)
                {
                    flag = 1;
                    check[j] = 1;
                    seq[cnt] = j;
                    cnt += 1;
                    for (int p = 0; p < n; p++)
                    {
                        avail[p] += alloc[j][p];
                    }
                }
            }
        }
        if (cnt == m)
        {
            break;
        }
        if (flag == 0)
        {
            break;
        }
    }

    if (cnt == m)
    {
        printf("\nSafe Sequence is: <");
        for (int i = 0; i < m - 1; i++)
        {
            printf("P%d, ", seq[i]);
        }
        printf("P%d>", seq[m - 1]);
    }
    else
    {
        printf("\nSystem is not in Safe State!!!");
    }
}

void calneed(int max[10][10], int alloc[10][10], int need[10][10], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

void space(int s)
{
    for (int i = 0; i < s; i++)
    {
        printf(" ");
    }
}

void display(int max[10][10], int alloc[10][10], int need[10][10], int avail[10], int m, int n)
{

    printf("\nProcess");
    space(2 + 2 * n);
    printf("Max");
    space(1 + 2 * n);
    printf("Alloc");
    space(2 * n);
    printf("Need");
    space(2 * n);
    printf("Avail\n\n");

    for (int i = 0; i < m; i++)
    {
        printf("P%d           ", i + 1);
        for (int j = 0; j < n; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("     ");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", alloc[i][j]);
        }
        printf("     ");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("     ");
        if (i == 0)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", avail[j]);
            }
        }
        printf("\n");
    }
}

void acceptavail(int avail[10], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("A%d: ", i + 1);
        scanf("%d", &avail[i]);
    }
}

int main()
{

    int max[10][10], alloc[10][10], need[10][10], avail[10], seq[10], m, n;
    printf("Enter the number of processes: ");
    scanf("%d", &m);
    printf("Enter the number of resources: ");
    scanf("%d", &n);
    printf("for max\n");
    accept(max, m, n);
    printf("for alloc\n");
    accept(alloc, m, n);
    printf("for avail\n");
    acceptavail(avail, n);
    calneed(max, alloc, need, m, n);
    display(max, alloc, need, avail, m, n);
    safe(max, alloc, need, avail, m, n, seq);
    return 0;
}