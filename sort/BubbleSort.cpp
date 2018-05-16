// 冒泡排序 
// 基本思想：比较相邻的两个数，如果前者比后者大，则进行交换。每一轮排序结束，选出一个未排序中最大的数放到数组后面。

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- 如果能在内部循环第一次运行时,使用一个旗标来表示有无需要交换的可能,可以把最优时间复杂度降低到O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定


#include <stdio.h>

//冒泡排序 
void BubbleSort(int A[], int n)
{
    for (int j = 0; j < n - 1; j++)         // 每次最大元素就像气泡一样"浮"到数组的最后
    {
        for (int i = 0; i < n - 1 - j; i++) // 依次比较相邻的两个元素,使较大的那个向后移
        {
            if (A[i] > A[i + 1])            // 如果条件改成A[i] >= A[i + 1],则变为不稳定的排序算法
            {
            	int temp = A[i];
				A[i] = A[i+1];
    			A[i+1] = temp;
            }
        }
    }
}

//冒泡排序的改进：鸡尾酒排序，也叫定向冒泡排序 
//此算法与冒泡排序的不同处在于从低到高然后从高到低，而冒泡排序则仅从低到高去比较序列里的每个元素。他可以得到比冒泡排序稍微好一点的效能。 
 void CocktailSort(int A[], int n)
{
    int left = 0;                            // 初始化边界
    int right = n - 1;
    while (left < right)
    {
        for (int i = left; i < right; i++)   // 前半轮,将最大元素放到后面
        {
            if (A[i] > A[i + 1])
            {
                int temp = A[i];
				A[i] = A[i+1];
    			A[i+1] = temp;
            }
        }
        right--;
        for (int i = right; i > left; i--)   // 后半轮,将最小元素放到前面
        {
            if (A[i - 1] > A[i])
            {
                int temp = A[i-1];
				A[i-1] = A[i];
    			A[i] = temp;
            }
        }
        left++;
    }
}

int main()
{
    int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };    // 从小到大冒泡排序
    int n = sizeof(A) / sizeof(int);
    BubbleSort(A, n);
    printf("冒泡排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    int B[] = { 6, 5, 3, 1, 8, 7, 2, 4 };    // 从小到大冒泡排序
    n = sizeof(B) / sizeof(int);
    CocktailSort(A, n);
    printf("鸡尾酒排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;
}