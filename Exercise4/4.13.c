#include <stdio.h>

void swap(int* a, int* b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

void heap(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heap(arr, n, largest);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    char type;
    for(int i = 0; i < n; i++){
        arr[i] = 2147483647;
    }

    for ( ; ; ){
        scanf("%c", &type);
        if (type == 'I'){
            int input;
            scanf("%d", &input);
            if(input < arr[0]){
                arr[0] = input;
                heap(arr, n, 0);
            }
        }
        else if (type == 'O'){
            //print 
            printf("%d\n", arr[0]);

        }
        else if (type == 'S')
            break;
    }
    return 0;
}