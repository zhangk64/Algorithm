/* �鲢���� 
   ԭ���鲢��Merge�������ǽ����������������ϣ������ϲ���һ���µ���������Ѵ��������з�Ϊ���ɸ������У�ÿ��������������ġ�Ȼ���ٰ����������кϲ�Ϊ�����������С�
*/ 

#include <stdio.h> 
#include <string.h>

// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(nlogn)
// ����ʱ�临�Ӷ� ---- O(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(nlogn)
// ���踨���ռ� ------ O(n)
// �ȶ��� ------------ �ȶ�

//���ж�����������a[first...mid]��a[mid...last]�ϲ���  
void mergearray(int a[], int first, int mid, int last, int temp[])  
{  
    int i = first, j = mid + 1;  
    int m = mid,   n = last;  
    int k = 0;  
      
    while (i <= m && j <= n)  
    {  
        if (a[i] <= a[j])  
            temp[k++] = a[i++];  
        else  
            temp[k++] = a[j++];  
    }  
      
    while (i <= m)  
        temp[k++] = a[i++];  
      
    while (j <= n)  
        temp[k++] = a[j++];  
      
    for (i = 0; i < k; i++)  
        a[first + i] = temp[i];  
}  

// �ݹ�ʵ��
void MergeSortRecursion(int a[], int first, int last, int temp[])  
{  
    if (first < last)  
    {  
        int mid = (first + last) / 2;  
        MergeSortRecursion(a, first, mid, temp);    //�������  
        MergeSortRecursion(a, mid + 1, last, temp); //�ұ�����  
        mergearray(a, first, mid, last, temp); //�ٽ������������кϲ�  
    }  
}  

int main()
{
	int A1[] = { 6, 5, 3, 1, 8, 7, 2, 4 };      // ��С����鲢����
    int A2[] = { 6, 5, 3, 1, 8, 7, 2, 4 };
    int n1 = sizeof(A1) / sizeof(int);
    int n2 = sizeof(A2) / sizeof(int);
    int temp[1000] ={0};
    MergeSortRecursion(A1, 0, n1 - 1,temp);          // �ݹ�ʵ��
    printf("�ݹ�ʵ�ֵĹ鲢��������");
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", A1[i]);
    }
    printf("\n");
	return 0;
}