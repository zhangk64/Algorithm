/* 堆排序 
   堆：一个完全二叉树中，任意父结点总是大于或等于（小于或等于）任何一个子节点，则为大顶堆（小顶堆）。 
   基本原理：
   1.将初始待排序关键字序列(R1,R2....Rn)构建成大顶堆，此堆为初始的无序区
   2.将堆顶元素R[1]与最后一个元素R[n]交换，此时得到新的无序区(R1,R2,......Rn-1)和新的有序区(Rn)
   3.由于交换后新的堆顶R[1]可能违反堆的性质，因此需要对当前无序区(R1,R2,......Rn-1)调整为新堆，然后再次将R[1]与无序区最后一个元素交换，得到新的无序区(R1,R2....Rn-2)和新的有序区(Rn-1,Rn)。不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成 
*/ 

#include <stdio.h>
#include <stdlib.h>

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void Heapify(int A[], int i, int size)  // 从A[i]向下进行堆调整
{
    int left_child = 2 * i + 1;         // 左孩子索引
    int right_child = 2 * i + 2;        // 右孩子索引
    int max = i;                        // 选出当前结点与其左右孩子三者之中的最大值
    if (left_child < size && A[left_child] > A[max])
        max = left_child;
    if (right_child < size && A[right_child] > A[max])
        max = right_child;
    if (max != i)
    {
        Swap(A, i, max);                // 把当前结点和它的最大(直接)子节点进行交换
        Heapify(A, max, size);          // 递归调用，继续从当前结点向下进行堆调整
    }
}

int BuildHeap(int A[], int n)           // 建堆，时间复杂度O(n)
{
    int heap_size = n;
    for (int i = heap_size / 2 - 1; i >= 0; i--) // 从每一个非叶结点开始向下进行堆调整
        Heapify(A, i, heap_size);
    return heap_size;
}

void HeapSort(int A[], int n)
{
    int heap_size = BuildHeap(A, n);    // 建立一个最大堆
    while(heap_size > 1)                // 堆（无序区）元素个数大于1，未完成排序
    {
        // 将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素
        // 此处交换操作很有可能把后面元素的稳定性打乱，所以堆排序是不稳定的排序算法
        Swap(A, 0, --heap_size);
        Heapify(A, 0, heap_size);     // 从新的堆顶元素开始向下进行堆调整，时间复杂度O(logn)
    }
}

int main()
{
    //int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };// 从小到大堆排序
    int A[100]={0};
	for(int i= 0;i<100;i++)
	{
		A[i]=rand()%200;
		printf("%d ",A[i]);
	}
    int n = sizeof(A) / sizeof(int);
    HeapSort(A, n);
    printf("堆排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}