#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define INFINITY 9999
#define MAX 10

void Dijkstra(int Graph[MAX][MAX], int n, int start);
//void InitMatrix();
void Initialize(int* Graph[], int distance[], int visited[], int len);
//void Relax(int* Graph[], int i, int mindistance, int next, int distance[], int visited[]);
int main()
{
    int Graph[MAX][MAX], i, len;
    char input[100];    // ũ�Ⱑ 10�� char�� �迭�� ����
    char* alpha[100];
    scanf("%s", input);     // ǥ�� �Է��� �޾Ƽ� �迭 ������ ���ڿ��� ����
    char* p;
    p = strtok(input, ",");
    alpha[0] = p;
    i = 0;
    while (p != NULL) {
        i++;
        p = strtok(NULL, ",");
        alpha[i] = p;
    }//alpha�� A,B... ��ǲ�� ���� ���ڷ� ����
    int num = i;//vertex�� ����
    for (int j = 0; j < i; j++)
        for (int k = 0; k < i; k++)
            Graph[j][k] = INFINITY;
    //�׷��� ������ ����ġ ����Ʈ ���� inf�� �ʱ�ȭ
    int N;
    scanf("%d", &N); //�ι�° �� ������ ���� �Է�
    for (int j = 0; j < N; j++)
    {
        char edge[10];
        int weight;
        scanf("%s", edge);//scanf("%c,%c,%d")�� ���� �ϸ� �ȵȴ�. scanf�� ,�� ���͵� ���ڷ� �޴´�
        int u = edge[0] - 'A';
        int v = edge[2] - 'A';
        if (edge[5])
        {
            weight = (edge[4] - '0') * 10 + edge[5] - '0';
        }
        else
            weight = edge[4] - '0';

        Graph[u][v] = weight;
    }
    //�Է� ���� ������ ���� �־���
    //������ ������ matrix�� ���� �ְ� ������ inf����
    Dijkstra(Graph, num, 0);
    return 0;
}
void Dijkstra(int Graph[MAX][MAX], int n, int start)
{
    int distance[MAX];
    int visited[MAX];
    int cnt;

    //initialize ���ִ� �Լ�
    Initialize(Graph, distance, visited, n);
    /*for (i = 0; i < n; i++) {
        distance[i] = Graph[start][i];
        visited[i] = 0;
    }*/
    //cnt = 0;
    int mindistance, next;
    //while (cnt < n - 1)
    for (int cnt = 0; cnt < n - 1; cnt++)
    {
        mindistance = INFINITY;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                if (distance[i] < mindistance)
                {
                    mindistance = distance[i];
                    next = i;
                }
        }//ExtractMin
        visited[next] = 1;
        //relax�Լ�

        /*for (int i = 0; i < n; i++)
        {
            Relax(Graph, i, mindistance, next, distance, visited);
        }
        cnt++;*/
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                if (mindistance + Graph[next][i] < distance[i])
                {
                    distance[i] = mindistance + Graph[next][i];
                }
        }
        //cnt++;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", distance[i]);
    }
}

void Initialize(int* Graph[], int distance[], int visited[], int len)
{
    for (int i = 1; i < len; i++)
    {
        distance[i] = INFINITY;
        visited[i] = 0;
    }
    distance[0] = 0;
    visited[0] = 0;
}
