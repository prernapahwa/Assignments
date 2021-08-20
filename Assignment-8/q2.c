/**
 * Program to print mth smallest element from unsorted array
 * 
 * @Prerna(1910990964)
 * 
 * Assignment-8-Algorithm
 * Question2
 */

#include<stdio.h>

int partition(int *arr, int start , int end)
{
    int count = 0;
    int temp = arr[start];
    
    for(int i = start ; i <= end ; i++)
    {
        if(arr[i] < temp)
        {
            count++;
        }
    }
    
    //swapping
    int extra = arr[start];
    arr[start] = arr[start + count];
    arr[start + count] = extra;
    
    int p = start;
    int q = end;
    
    while(p < (count + start) && q > (count + start))
    {
        if(arr[p] >= temp && arr[q] < temp)
        {
            extra = arr[p];
            arr[p] = arr[q];
            arr[q] = extra;
            p++;
            q--;
        }
        
        else if(arr[p] < temp)
        {
            p++;
        }
        
        else if(arr[q] >= temp)
        {
            q--;
        }
    }
    return start + count;
}


int mth_smallest(int *arr, int start, int end, int m) {
    if(start == end) {
        if(start == m) {
            return arr[start];
        }
        return 0;
    }
    else {
        int pivot = partition(arr, start, end);
        if(pivot == m) {
            return arr[m];
        }
        else if (pivot < m) {
            return mth_smallest(arr, pivot + 1, end, m);
        }
        return mth_smallest(arr, start, pivot - 1, m);
        
    }
}

int main() {
    int n;// size of array
    scanf("%d",&n);
    
    // declaring a n sized array
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    //scanning m 
    int m;
    scanf("%d",&m);
    printf("output %d", mth_smallest(arr, 0, n, m));
}
