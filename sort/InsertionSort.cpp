/* 插入排序 
   原理：通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
*/ 

#include <stdio.h>

// 简单插入排序 
// 分类 ------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- 最坏情况为输入序列是降序排列的,此时时间复杂度O(n^2)
// 最优时间复杂度 ---- 最好情况为输入序列是升序排列的,此时时间复杂度O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)         // 类似抓扑克牌排序
    {
        int get = A[i];                 // 右手抓到一张扑克牌
        int j = i - 1;                  // 拿在左手上的牌总是排序好的
        while (j >= 0 && A[j] > get)    // 将抓到的牌与手牌从右向左进行比较
        {
            A[j + 1] = A[j];            // 如果该手牌比抓到的牌大，就将其右移
            j--;
        }
        A[j + 1] = get; // 直到该手牌比抓到的牌小(或二者相等)，将抓到的牌插入到该手牌右边(相等元素的相对次序未变，所以插入排序是稳定的)
    }
}

// 二分插入排序 
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
void InsertionSortDichotomy(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int get = A[i];                    // 右手抓到一张扑克牌
        int left = 0;                    // 拿在左手上的牌总是排序好的，所以可以用二分法
        int right = i - 1;                // 手牌左右边界进行初始化
        while (left <= right)            // 采用二分法定位新牌的位置
        {
            int mid = (left + right) / 2;
            if (A[mid] > get)
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (int j = i - 1; j >= left; j--)    // 将欲插入新牌位置右边的牌整体向右移动一个单位
        {
            A[j + 1] = A[j];
        }
        A[left] = get;                    // 将抓到的牌插入手牌
    }
}

// 希尔排序 
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- 根据步长序列的不同而不同。已知最好的为O(n(logn)^2)
// 最优时间复杂度 ---- O(n)
// 平均时间复杂度 ---- 根据步长序列的不同而不同。
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定
void ShellSort(int A[], int n)
{
    int h = 0;
    while (h <= n)                          // 生成初始增量
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (int i = h; i < n; i++)
        {
            int j = i - h;
            int get = A[i];
            while (j >= 0 && A[j] > get)
            {
                A[j + h] = A[j];
                j = j - h;
            }
            A[j + h] = get;
        }
        h = (h - 1) / 3;                    // 递减增量
    }
}

int main()
{
    int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };// 从小到大插入排序
    int n = sizeof(A) / sizeof(int);
    InsertionSort(A, n);
    printf("插入排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    int B[] = { 6, 5, 3, 1, 8, 7, 2, 4 };// 从小到大插入排序
    n = sizeof(B) / sizeof(int);
    InsertionSortDichotomy(B, n);
    printf("二分插入排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    int C[] = { 6, 5, 3, 1, 8, 7, 2, 4 };// 从小到大插入排序
    n = sizeof(C) / sizeof(int);
    InsertionSortDichotomy(C, n);
    printf("希尔排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;
}