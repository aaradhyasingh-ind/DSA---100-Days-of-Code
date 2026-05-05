#include <stdio.h>
int main() {
    int arr[100], n, i, pos, val, found = 0;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    // Traversal
    printf("Array: ");
    for(i=0;i<n;i++) printf("%d ", arr[i]);

    // Insertion
    printf("\nEnter position & value to insert: ");
    scanf("%d %d",&pos,&val);
    for(i=n;i>=pos;i--) arr[i]=arr[i-1];
    arr[pos]=val; n++;

    // Deletion
    printf("Enter position to delete: ");
    scanf("%d",&pos);
    for(i=pos;i<n-1;i++) arr[i]=arr[i+1];
    n--;

    // Searching
    printf("Enter element to search: ");
    scanf("%d",&val);
    for(i=0;i<n;i++)
        if(arr[i]==val){ found=1; break; }

    if(found) printf("Found at %d\n", i);
    else printf("Not Found\n");

    // Update
    printf("Enter position & new value: ");
    scanf("%d %d",&pos,&val);
    arr[pos]=val;

    printf("Final Array: ");
    for(i=0;i<n;i++) printf("%d ", arr[i]);
}