#include<stdio.h>

struct files
{
    int id, r;
};

void quicksort_files(files number[], int first, int last) {
    int i, j, pivot;
    files temp;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (number[i].r <= number[pivot].r && i < last)
                i++;
            while (number[j].r > number[pivot].r)
                j--;
            if (i < j) {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }

        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort_files(number, first, j - 1);
        quicksort_files(number, j + 1, last);

    }
}
int copy_to_pendrives(files number[], int memory1[], int memory2[], int n_f, int size_p, int* k, int* m)
{
    int sum = 0, j=0, l=0;
       while (j < n_f)
        {
            sum += number[j].r;
            if (sum <= size_p)
            {
                memory1[l] = number[j].id;
                l++;
                j++;
            }
            else
            {
                sum = 0;
                *k = l;
                l = 0;
                break;
            }
        }  
       while(j < n_f)
       {
           sum += number[j].r;
           if (sum <= size_p)
           {
               memory2[l] = number[j].id;
               l++;
               j++;
           }
           else
           {
               sum = 0;
               *m = l;
               l = 0;
               break;
           }

       }  
       return j;
}
void quicksort_pendrives(int number[], int first, int last) {
    int i, j, pivot, temp;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j) {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }

        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort_pendrives(number, first, j - 1);
        quicksort_pendrives(number, j + 1, last);
    }
}

int main()
{
    int i, p, n, max1=0, max2=0;
    scanf("%d %d", &n, &p);
    files* file = new files[n];
    for (i = 0; i < n; i++)
        scanf("%d %d", &file[i].id, &file[i].r);
    printf("\n");

    quicksort_files(file, 0, n - 1);

    int* pendrive_1 = new int[n];
    int* pendrive_2 = new int[n];
    
    printf("%d\n", copy_to_pendrives(file, pendrive_1, pendrive_2, n+1, p, &max1, &max2));

    quicksort_pendrives(pendrive_1, 0, max1 - 1);
    quicksort_pendrives(pendrive_2, 0, max2 - 1);

    printf("1: ");
    for (i = max1-1; i>=0; i--)
        printf("%d ", pendrive_1[i]);
    printf("\n2: ");
    for (i = max2-1; i >=0; i--)
        printf("%d ", pendrive_2[i]);
   
    delete[] file;
    delete[] pendrive_1;
    delete[] pendrive_2;
    return 0;
}
