/* ������ 
   �ѣ�һ����ȫ�������У����⸸������Ǵ��ڻ���ڣ�С�ڻ���ڣ��κ�һ���ӽڵ㣬��Ϊ�󶥶ѣ�С���ѣ��� 
   ����ԭ��
   1.����ʼ������ؼ�������(R1,R2....Rn)�����ɴ󶥶ѣ��˶�Ϊ��ʼ��������
   2.���Ѷ�Ԫ��R[1]�����һ��Ԫ��R[n]��������ʱ�õ��µ�������(R1,R2,......Rn-1)���µ�������(Rn)
   3.���ڽ������µĶѶ�R[1]����Υ���ѵ����ʣ������Ҫ�Ե�ǰ������(R1,R2,......Rn-1)����Ϊ�¶ѣ�Ȼ���ٴν�R[1]�����������һ��Ԫ�ؽ������õ��µ�������(R1,R2....Rn-2)���µ�������(Rn-1,Rn)�������ظ��˹���ֱ����������Ԫ�ظ���Ϊn-1������������������ 
*/ 

#include <stdio.h>
#include <stdlib.h>

// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(nlogn)
// ����ʱ�临�Ӷ� ---- O(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(nlogn)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ ���ȶ�

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void Heapify(int A[], int i, int size)  // ��A[i]���½��жѵ���
{
    int left_child = 2 * i + 1;         // ��������
    int right_child = 2 * i + 2;        // �Һ�������
    int max = i;                        // ѡ����ǰ����������Һ�������֮�е����ֵ
    if (left_child < size && A[left_child] > A[max])
        max = left_child;
    if (right_child < size && A[right_child] > A[max])
        max = right_child;
    if (max != i)
    {
        Swap(A, i, max);                // �ѵ�ǰ�����������(ֱ��)�ӽڵ���н���
        Heapify(A, max, size);          // �ݹ���ã������ӵ�ǰ������½��жѵ���
    }
}

int BuildHeap(int A[], int n)           // ���ѣ�ʱ�临�Ӷ�O(n)
{
    int heap_size = n;
    for (int i = heap_size / 2 - 1; i >= 0; i--) // ��ÿһ����Ҷ��㿪ʼ���½��жѵ���
        Heapify(A, i, heap_size);
    return heap_size;
}

void HeapSort(int A[], int n)
{
    int heap_size = BuildHeap(A, n);    // ����һ������
    while(heap_size > 1)                // �ѣ���������Ԫ�ظ�������1��δ�������
    {
        // ���Ѷ�Ԫ����ѵ����һ��Ԫ�ػ��������Ӷ���ȥ�����һ��Ԫ��
        // �˴������������п��ܰѺ���Ԫ�ص��ȶ��Դ��ң����Զ������ǲ��ȶ��������㷨
        Swap(A, 0, --heap_size);
        Heapify(A, 0, heap_size);     // ���µĶѶ�Ԫ�ؿ�ʼ���½��жѵ�����ʱ�临�Ӷ�O(logn)
    }
}

int main()
{
    //int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };// ��С���������
    int A[100]={0};
	for(int i= 0;i<100;i++)
	{
		A[i]=rand()%200;
		printf("%d ",A[i]);
	}
    int n = sizeof(A) / sizeof(int);
    HeapSort(A, n);
    printf("����������");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}