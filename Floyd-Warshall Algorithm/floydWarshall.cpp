#include <stdio.h>

void floydWarshall();

int number = 4;
int INF = 1000000;

// 자료 배열 초기화
int arr[4][4] = {
    {0, 5, INF, 8},
    {7, 0, 9, INF},
    {2, INF, 0, 4},
    {INF, INF, 3, 0}
};

int main() {
    floydWarshall();

    return 0;
}

void floydWarshall() {
    // 결과 그래프를 초기화
    int d[number][number];

    for(int i = 0; i < number; i++) {
        for(int j = 0; j < number; j++) {
            d[i][j] = arr[i][j];
        }
    }

    // k = 거쳐가는 노드
    for(int k = 0; k < number; k++) {
        // i = 출발 노드
        for(int i = 0; i < number; i++) {
            // j = 도착 노드
            for(int j = 0; j < number; j++) {
                // i -> k -> j를 간 경우가 기존 i -> j보다 비용이 작을 경우
                if(d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
            
        }
    }

    // 결과 출력
    for(int i = 0; i < number; i++) {
        for(int j = 0; j < number; j++)
            printf("%d ", d[i][j]);
        printf("\n");
    }
}