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
    char input[100];    // 크기가 10인 char형 배열을 선언
    char* alpha[100];
    scanf("%s", input);     // 표준 입력을 받아서 배열 형태의 문자열에 저장
    char* p;
    p = strtok(input, ",");
    alpha[0] = p;
    i = 0;
    while (p != NULL) {
        i++;
        p = strtok(NULL, ",");
        alpha[i] = p;
    }//alpha에 A,B... 인풋을 각각 문자로 저장
    int num = i;//vertex의 개수
    for (int j = 0; j < i; j++)
        for (int k = 0; k < i; k++)
            Graph[j][k] = INFINITY;
    //그래프 간선의 가중치 디폴트 값을 inf로 초기화
    int N;
    scanf("%d", &N); //두번째 줄 간선의 개수 입력
    for (int j = 0; j < N; j++)
    {
        char edge[10];
        int weight;
        scanf("%s", edge);//scanf("%c,%c,%d")와 같이 하면 안된다. scanf가 ,와 엔터도 문자로 받는다
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
    //입력 받은 간선은 값을 넣어줌
    //간선이 있으면 matrix에 값이 있고 없으면 inf값임
    Dijkstra(Graph, num, 0);
    return 0;
}
void Dijkstra(int Graph[MAX][MAX], int n, int start)
{
    int distance[MAX];
    int visited[MAX];
    int cnt;

    //initialize 해주는 함수
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
        //relax함수

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
