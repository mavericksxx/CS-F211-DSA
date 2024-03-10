
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int leftPivot, rightPivot;

        if (arr[low] > arr[high]) {
            swap(&arr[low], &arr[high]);
        }

        leftPivot = arr[low];
        rightPivot = arr[high];

        int i = low + 1, k = low + 1, j = high - 1;

        while (k <= j) {
            if (arr[k] < leftPivot) {
                swap(&arr[i], &arr[k]);
                i++;
            } else if (arr[k] >= rightPivot) {
                while (arr[j] > rightPivot && k < j) {
                    j--;
                }

                swap(&arr[k], &arr[j]);
                j--;
                if (arr[k] < leftPivot) {
                    swap(&arr[i], &arr[k]);
                    i++;
                }
            }
            k++;
        }
        i--;
        j++;

        swap(&arr[low], &arr[i]);
        swap(&arr[high], &arr[j]);

        quickSort(arr, low, i - 1);
        quickSort(arr, i + 1, j - 1);
        quickSort(arr, j + 1, high);
    }
}


void merge(int *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    L[i] = arr[left + i];

    for (j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
        
    }
}


void selectionSort(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (arr[i] < arr[j])
            swap(&arr[i], &arr[j]);
        }
    }
}


void bubbleSort(int *arr, int len) {
    int swapped;

    for (int i = 0; i < len; i++) {
        swapped = 0;

        for (int j = 0; j < len - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (!(swapped))
        break;
    }
}