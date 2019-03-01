#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

typedef struct stack
{
    int *data;
    int top;
}Stack;

typedef struct Que
{
    int *data;
    int head;
    int tail;
}Que;

//��������
void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//ð������
void BubbleSoet(int* arr, int len)
{
    int i = 0;
    //int j = len - 1;
    int j = 0;
    int tmp = 0;

    for (j = 0; j < len - 1; j++)
    {
        for (i = 0; i < len - j - 1; i++)
        {
            //tmp = arr[i];
            if (arr[i] > arr[i + 1])
            {
                Swap(&arr[i],&arr[i+1]);
                //arr[i] = arr[i + 1];
                //arr[i + 1] = tmp;
            }
        }
    }
}

//ѡ������
void SelectSort(int* arr, int len)
{
    int i = 0,j = 0;
    int tmp = 0;
    for (i; i < len ; i++)
    {
        tmp = arr[i];
        for (j = i +1 ; j < len ; j++)
        {
            if (tmp > arr[j])
            {
                Swap(&tmp, &arr[j]);
            }
        }
        arr[i] = tmp;
    }
}

//��������
void InsertSort(int* arr, int len)
{
    for (int i = 1 ; i < len; i++)
    {
        int tmp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > tmp)
        {
                arr[j + 1] = arr[j];
                j--;
        }
            arr[j+1] = tmp;
    }
}

//ϣ������
void ShellSort(int* arr, int len)
{
    int gap;//��������(Ҳ�������)
    for (gap = len / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < len; i++)
        {
            int tmp = arr[i];
            int j = i - gap;
            while (j >= 0 && arr[j] > tmp)
            {
                arr[j+gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = tmp;
        }
    }
}

//��������

int OneProcess(int *arr,int head, int end)//�ڿӷ�һ������
{
    int L = head;
    int R = end;
    int tmp = arr[L];

    while (L < R)
    {
        while (L < R && arr[R] >= tmp)
        {
            R--;
        }
        if (L < R)//��ֹѭ��R--֮��С��L;
        {
            arr[L] = arr[R];
            L++;
        }
  
        while (L < R && arr[L] <= tmp)
        {
            L++;
        }
        if (L < R)//��ֹѭ��R--֮��С��L;
        {
            arr[R] = arr[L];
            R--;
        }
       
    }
    arr[L] = tmp;
    return L;
}

void QuickSort1(int *arr,int head,int end)//���η��ݹ�ʵ��
{
    if (head < end)
    {
        int val = OneProcess(arr, head, end);
        if (val - 1 - head > 1)
        {
            QuickSort1(arr, head, val - 1);//�ݹ�ʵ������
        }

        if (end - val - 1 > 1)
        {
            QuickSort1(arr, val + 1, end);//�ݹ�ʵ���Ұ��
        }
    }
}

void QuickSort2(int *arr, int head,int end)//�ǵݹ�ʵ��
{
    Stack st;
    int size = (int)(log10((double)(end-head+1))/log10((double)2)+1);
    //��ʼ��ջ
    st.data = (int *)malloc(sizeof(int)* 2 * size);
    assert(st.data != NULL);
    st.top = 0;

    st.data[st.top++] = head;
    st.data[st.top++] = end;

    while (st.top != 0)
    {
        end = st.data[-- st.top];
        head = st.data[--st.top];
        int val = OneProcess(arr,head,end);
        if (val - 1 - head > 1)//���
        {
            st.data[st.top++] = head;
            st.data[st.top++] = val - 1;
        }
        if (end - val - 1 > 1)//�ұ�
        {
            st.data[st.top++] = val + 1;
            st.data[st.top++] = end;
        }
    }

    free(st.data);
}

void FastSort(int* arr, int len)
{
    int head = 0;
    int end = len - 1;
    QuickSort2(arr, head, end);
}

//������

void Rootsort(int *arr,int root,int end)//��������
{
    int tmp = arr[root];
    int i = root * 2 + 1;//���ڵ������
    while (i <= end)
    {
        //�ȱȽ����Һ����Ǹ��Ƚϴ�
        if (i + 1 <= end && arr[i+1] > arr[i])
        {
            i += 1;//��ʱi��ʾ���ǽϴ�ĺ���
        }
        if (tmp > arr[i])
        {
            break;
        }
        arr[root] = arr[i];
        root = i;
        i = root * 2 + 1;

        /*if (tmp <= arr[i])//error
        {
            arr[root] = arr[i];
            root = i;
            i = root * 2 + 1;
        }
       */
    }
    arr[root] = tmp;
}

void MaxHeap(int *arr, int end)//����
{
    int val = (end - 1) / 2;//�������һ�������ĸ�
    for (; val >= 0; val--)
    {
        Rootsort(arr, val, end);
    }
}

void HeapSort(int* arr, int len)//�������ô����ʵ������
{
    int end = len - 1;
    while (end > 0)
    {
        MaxHeap(arr,end);
        Swap(&arr[end],&arr[0]);
        end -= 1;
    }
}

void Show(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
}

//�鲢����

void Merge(int *arr, int len, int width)//���������ݹ鲢Ϊһ��
{
    int L1 = 0;
    int R1 = L1 + width - 1;
    int L2 = R1 + 1;
    int R2 = (L2 + width - 1) < (len - 1) ? (L2 + width - 1) : (len - 1);//��ֹԽ��

    int *brr = (int*)malloc(sizeof(int)*len);
    assert(brr != NULL);

    int i = 0;//����brr���±�

    while (L1 < len)
    {
        //һ�ι鲢����
        
        while (L1 <= R1 && L2 <= R2)//���������ݶ��е���������طŽ�����brr��
        {
            if (arr[L1] < arr[L2])
            {
                brr[i++] = arr[L1++];
            }
            else
            {
                brr[i++] = arr[L2++];
            }
        }

        //�������ݶ��б���һ���е�����δ��ȫ��������brr��
        while (L1 <= R1)//����һ�����ݶ���ʣ��Ԫ�ش���brr
        {
            brr[i++] = arr[L1++];
        }

        while (L2 <= R2)//���ڶ������ݶ���ʣ��Ԫ�ش���brr
        {
            brr[i++] = arr[L2++];
        }

        L1 = R2 +1;
        R1 =( L1 + width - 1) < (len - 1) ? (L1 + width - 1) : (len - 1);
        L2 = R1 + 1;
        R2 = (L2 + width - 1) < (len - 1) ? (L2 + width - 1) : (len - 1); 
 
    }

    for (int j = 0; j <= len; j++)
    {
        arr[j] = brr[j];
    }
 
    free(brr);
}

void MergeSort(int *arr, int len)//����
{
    int width = 1;//��ࣨ�鲢��С������ݸ�����
    while (width <= len)
    {
        Merge(arr, len, width);
        width *= 2;
    }
}

//��������

int Get_width(int *arr, int len)//��ȡ�������������λ��
{
    int width = 0;
    int max = 0;//�����е������
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    while (max > 0)
    {
        max /= 10;
        width++;
    }

    return width;
}

int Get_val(int val, int n)//��ȡ�����ݵ�ǰ��λ����
{
    while (n > 0)
    {
        val /= 10;
        n--;
    }
    return val % 10;
}

void RadixSort(int *arr, int len)
{
    Que que[10];
    for (int i = 0; i < 10; ++i)//��ʼ������
    {
        que[i].data = (int *)malloc(sizeof(int)* len);
        assert(que[i].data != NULL);
        que[i].head = que[i].tail = 0;
    }

    int width = Get_width(arr, len);
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < len; j++)//���
        {
            int n = Get_val(arr[j], i);//��������ǰ��λ���֣�
            que[n].data[que[n].tail++] = arr[j];//��ǰ��λ�����Ǽ��ͽ������ݷŵ����Ŷ�����
        }
        
        /*int count = 0;
        for (int k = 0; k < 10; ++k)
        {
            while (que[k].head != que[k].tail)
            {
                arr[count++] = que[k].data[que[k].head++];
            }

            que[k].head = que[k].tail = 0;
        }*/

        int j = 0;
        for (int k = 0; k < 10; k++)//����
        {
           
            for (; j < len; j++)
            {
                if (que[k].head != que[k].tail)
                {
                    arr[j] = que[k].data[que[k].head++];//�����Ƚ��ȳ�
                }
                else
                {
                    break;
                }
            }
            que[k].head = que[k].tail = 0;
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        free(que[i].data);
    }
}

int main()
{
    int arr[] = { 12, 33, 31, 24, 16, 4, 41, 6, 11, 28, 1 };
    int len = sizeof(arr) / sizeof(arr[0]);

    //BubbleSoet(arr, len);
    //SelectSort(arr, len);
    //InsertSort(arr, len);
    //ShellSort(arr,len);
    //FastSort(arr,len);
    //HeapSort(arr, len);
    MergeSort(arr,len);
    //RadixSort(arr, len);
    Show(arr,len);
}