#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

// 랜덤 함수를 이용하여 int 배열을 0~max-1의 값으로 무작위로 채우는 함수
static void initRandom( int list[], int n, int max=100 )
{
    for( int i=0 ; i<n ; i++ )
	list[i] = rand() % max;
}

// 배열을 화면에 보기 좋게 출력하는 함수. 디폴트 매개변수 사용
static void printArray( int arr[], int n, char *str="Array" )
{
    printf("%s = ", str);
    for( int i=0 ; i<n ; i++ )
       printf("%3d", arr[i]);
    printf("\n");
}

static void printStep( int arr[], int n, int c )
{
    //printf("Sorted Data = ");
    for( int i=0 ; i<n ; i++ )
       printf("%3d", arr[i]);
    printf("\n");
}

void bubble_sort (int list[], int n) 
{ 
	int i, j, bChanged, tmp;

	for( i=n-1 ; i>0 ; i-- ) { // 끝으로 이동한 레코드를 제외한 왼쪽 리스트에 
		bChanged = 0;                   //  대하여 스캔 과정을 반복함

		printf("-------------------------------------\n");
		printf("SCAN %d 완료\n", n-i);
		printf("-------------------------------------\n");

		for( j=0 ; j<i ; j++ ) {	   //항목을 교환할 범위
			if (list[j]>list[j + 1]) {    //인접한 2개의 레코드를 비교하여 순서대로 되어 있지 않으면 서로 교환
				SWAP(list[j],list[j+1],tmp);// 비교-교환 과정
				bChanged = 1;               // swap이 일어나지 않을 때까지 반복
			}
			//printf("step %d : %d %d\n", j+1, list[j], list[j+1]);
			printf("step %d : ", j+1);
			printStep(list,n,n-i);
		}

		printf("-------------------------------------\n");
		printf("SCAN %d 결과\n", n-i);
		
		if (!bChanged) break;
		printf("Sorted Data = ");
		printStep(list, n, n-i);
	}
}

void main()
{
	int list[9] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };
	printArray( list, 9, "Original Data" );	// 정렬 전 배열 출력 
	bubble_sort( list, 9 ); 		// 버블 정렬 실행
	printArray( list, 9, "Bubble Data" );	// 정렬 후 배열 출력 

	system("pause");
}