#include <stdio.h>

int main()
{
    int i, j, k = 1, n, v, x, queue[20], adj[20][20], visit[20], bfs[20], front = 0, rear = -1;

    printf("Enter Number Of vertices ");
    scanf("%d", &n);
    printf("Enter adjaceny matrix :\n ");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter he source Vertix : ");
    scanf("%d", &v);
    for (i = 1; i <= n; i++)
    {
        visit[i] = 0;
    }
    rear = rear + 1;
    queue[rear] = v;
    visit[v] = 1;
    while (front <= rear)
    {
        x = queue[front];
        front = front + 1;
        bfs[k] = x;
        k = k + 1;
        for (j = 1; j <= n; j++)
        {
            if (adj[x][j] == 1 && visit[j] == 0)
            {
                visit[j] = 1;
                rear = rear + 1;
                queue[rear] = j;
            }
        }
    }
    printf(" The BFS Traversal is : \n");
    for (int i = 1; i < k; i++)
    {
        printf("%d ", bfs[i]);
    }
    for (i = 1; i <= n; i++)
    {
        if (visit[i] != 0)
            printf("\n Node %d is reachable", i);
        else
            printf("\n Node %d is not reachable", i);
    }
}