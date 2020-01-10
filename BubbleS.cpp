#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

// ���� �Լ��� �̿��Ͽ� int �迭�� 0~max-1�� ������ �������� ä��� �Լ�
static void initRandom( int list[], int n, int max=100 )
{
    for( int i=0 ; i<n ; i++ )
	list[i] = rand() % max;
}

// �迭�� ȭ�鿡 ���� ���� ����ϴ� �Լ�. ����Ʈ �Ű����� ���
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

	for( i=n-1 ; i>0 ; i-- ) { // ������ �̵��� ���ڵ带 ������ ���� ����Ʈ�� 
		bChanged = 0;                   //  ���Ͽ� ��ĵ ������ �ݺ���

		printf("-------------------------------------\n");
		printf("SCAN %d �Ϸ�\n", n-i);
		printf("-------------------------------------\n");

		for( j=0 ; j<i ; j++ ) {	   //�׸��� ��ȯ�� ����
			if (list[j]>list[j + 1]) {    //������ 2���� ���ڵ带 ���Ͽ� ������� �Ǿ� ���� ������ ���� ��ȯ
				SWAP(list[j],list[j+1],tmp);// ��-��ȯ ����
				bChanged = 1;               // swap�� �Ͼ�� ���� ������ �ݺ�
			}
			//printf("step %d : %d %d\n", j+1, list[j], list[j+1]);
			printf("step %d : ", j+1);
			printStep(list,n,n-i);
		}

		printf("-------------------------------------\n");
		printf("SCAN %d ���\n", n-i);
		
		if (!bChanged) break;
		printf("Sorted Data = ");
		printStep(list, n, n-i);
	}
}

void main()
{
	int list[9] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };
	printArray( list, 9, "Original Data" );	// ���� �� �迭 ��� 
	bubble_sort( list, 9 ); 		// ���� ���� ����
	printArray( list, 9, "Bubble Data" );	// ���� �� �迭 ��� 

	system("pause");
}