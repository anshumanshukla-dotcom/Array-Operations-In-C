#include <stdio.h>

// Function to populate the array, initially
int inputArr(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("Enter the value for element no. %d - ", i + 1);
        scanf("%d", &arr[i]);
    }
    return 1;
}

// Traversal
void displayArr(int arr[], int size){
    printf("\n\nThe elements of your array are listed below:\n");
    for (int i = 0; i < size; i++)
    printf("Element no. %d --> %d\n", i + 1, arr[i]);
}

// Insertion
int insertArr(int arr[], int size){
    int response;
    printf("How many elements do you want to insert?\nYour response: ");
    scanf("%d", &response);
    int indices[response], elements[response];
    for (int i = 0; i < response; i++){
        printf("\nEnter the index position (one at a time in case of more than one insertion): ");
        scanf("%d", &indices[i]);
        // Check whether the index entered is valid (i.e. non-negative) and whether the user is attempting to insert at an index greater than the value of size
        if (indices[i] >= 0 && indices[i] <= size){
            printf("Enter the element (one at a time in case of more than one insertion): ");
            scanf("%d", &elements[i]);
        }
        else{
            printf("ERROR - Invalid index!!!\n");
            return size;
        }
    }
    for (int i = 0; i < response; i++){
        if (size < 50){
            for (int j = size - 1; j >= indices[i]; j--){
                arr[j + 1] = arr[j];
            }
            arr[indices[i]] = elements[i];
            size+=1;
            printf("\nThe element %d has been inserted at index %d.", elements[i], indices[i]);
        }
        else{
            printf("\nThe element %d cannot be inserted at index %d because the aray is full.", elements[i], indices[i]);
        }
    }
    return size;
}

// Deletion
int deleteArr(int arr[], int size){
    int response;
    printf("How many elements do you want to delete?\nYour response: ");
    scanf("%d", &response);
    int indices[response];
    printf("\n");
    for (int i = 0; i < response; i++){
        printf("Enter the index position (one at a time in case of more than one deletion): ");
        scanf("%d", &indices[i]);
    }
    for (int i = 0; i < response; i++){
        if (indices[i] < size){
            for (int j = indices[i]; j < size - 1; j++){
                arr[j] = arr[j + 1];
            }
            size-=1;
            printf("\nThe element %d has been deleted from index %d.", arr[indices[i]], indices[i]);
        }
        else{
            printf("\nThe element %d cannot be deleted from index %d because of an error in the value of index provided.", arr[indices[i]], indices[i]);
        }
    }
    return size;
}

// Searching
void searchArr(int arr[], int size){
    int response, binSearch = 0, found = 0, low = 0, mid, high = size - 1;
    printf("How many elements do you want to search?\nYour response: ");
    scanf("%d", &response);
    int elements[response];
    printf("\n");
    for (int i = 0; i < response; i++){
        printf("Enter the element to be searched (one at a time in case of more than one element(s)): ");
        scanf("%d", &elements[i]);
    }
    // Whether the array is sorted in ascending order
    for (int i = 0; i < size; i++){
        if (arr[i] < arr[i + 1])
        binSearch = 1;
        else{
            binSearch = 0;
            break;
        }
    }
    // Whether the array is sorted in descending order
    if (binSearch == 0){
        for (int i = 0; i < size; i++){
            if (arr[i] > arr[i + 1])
            binSearch = 2;
            else{
                binSearch = 0;
                break;
            }
        }
    }
    // Binary Search (if the array is sorted in ascending order)
    if (binSearch == 1){
        for (int i = 0; i < response; i++){
            while (low <= high){
                mid = (low + high) / 2;
                if (arr[mid] == elements[i]){
                    found = 1;
                    printf("\nThe element %d has been found at index %d.", elements[i], mid);
                    break;
                }
                else if (arr[mid] < elements[i])
                low = mid + 1;
                else
                high = mid - 1;
            }
            if (found == 0)
            printf("\nThe element %d isn't present.", elements[i]);
            else
            found = 0;
        }
    }
    // Binary Search (if the array is sorted in descending order)
    else if (binSearch == 2){
        for (int i = 0; i < response; i++){
            while (low <= high){
                mid = (low + high) / 2;
                if (arr[mid] == elements[i]){
                    found = 1;
                    printf("\nThe element %d has been found at index %d.", elements[i], mid);
                    break;
                }
                else if (arr[mid] < elements[i])
                high = mid - 1;
                else
                low = mid + 1;
            }
            if (found == 0)
            printf("\nThe element %d isn't present.", elements[i]);
            else
            found = 0;
        }
    }
    // Linear Search for an unsorted array
    else{
        for (int i = 0; i < response; i++){
            for (int j = 0; j < size; j++){
                if (arr[j] == elements[i]){
                    found = 1;
                    printf("\nThe element %d has been found at index %d.", elements[i], j);
                    break;
                }
            }
            if (found == 0)
            printf("\nThe element %d isn't present.", elements[i]);
            else
            found = 0;
        }
    }
}

int main(){
    int arr[50], size;
    printf("---------- WELCOME FOLK!!! ----------\n\nThis program is meant to implement the below-mentioned operations in array:-\n1. Traversal\n2. Insertion\n3. Deletion\n4. Searching\n\nNote that an integer array of size '50' has just been created internally.\n\nNow the array has been created but it's empty. So let's fill it with numbers.\n");
    printf("Enter the number of elements to be used: ");
    scanf("%d", &size);
    // Check if the value of the size entered is not exceeding the capacity of the array
    if (size <= 50){
        printf("\n");
        int value = inputArr(arr, size);
        if (value == 1){
            printf("\n\n---------- TRAVERSAL ----------");
            displayArr(arr, size);
            printf("\n\n---------- INSERTION ----------\n\n");
            size = insertArr(arr, size);
            displayArr(arr, size);
            printf("\n\n---------- DELETION ----------\n\n");
            size = deleteArr(arr, size);
            displayArr(arr, size);
            printf("\n\n---------- SEARCHING ----------\n\n");
            searchArr(arr, size);
        }
    }
    else{
        printf("ERROR - You cannot exceed the capacity of the array!!!");
    }
    printf("\n\nThanks for using our program...");
    return 0;
}