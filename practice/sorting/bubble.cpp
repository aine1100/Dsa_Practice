#include<iostream>
using namespace std;

void BubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void insertionSort(int arr[],int n){
    int i,key,j;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;

        while (j>=0 && arr[j]>key)
        {
           arr[j+1]=arr[j];
           j=j-1;
        }
        arr[j+1]=key;
        
    }
}

void selectionSort(int a[],int n){
   for(int i=0;i<n;i++){
    int targetIndex=i;
    for(int j=i+1;j<n;j++){
        if(a[j]<a[targetIndex]){
            targetIndex=j;
        }
    }
    swap(a[i],a[targetIndex]);
   }
}

void merge(int x[],int y[],int a[],int s,int e){
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;

    while(i<=mid && j<=e){
        if(x[i]<y[j]){
            a[k]=x[i];
            i++;
            k++;
        }else{
            a[k]=y[j];
            j++;
            k++;
        }
    }

    while(i<=mid){
        a[k]=x[i];
        k++;
        i++;
    }
    while(j<=e){
        a[k]=y[j];
        k++;
        j++;

    }
}

void mergeSort(int a[],int s,int e){
    if(s>=e){
        return;
    }

    int mid=(s+e)/2;
    int x[100],y[100];
    for(int i=s;i<=mid;i++){
        x[i]=a[i];
    }
    for(int i=mid+1;i<=e;i++){
        y[i]=a[i];
    }
    mergeSort(x,s,mid);
    mergeSort(y,mid+1,e);
    merge(x,y,a,s,e);
}

int partition(int a[],int low,int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }

    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(int a[],int low,int high){
    if(low<high){
        
        int pi=partition(a,low,high);
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
       
    }
}

int main() {
    int arr[] = {1, 3, 2, 9, 7, 6, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);


    cout<<"unsorted array";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    // BubbleSort(arr,n);
    // insertionSort(arr,n);
    // selectionSort(arr,n);
    // mergeSort(arr,0,n-1);
    quickSort(arr,0,n-1);
    cout<<"sorted array";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    char c='b';
    char *d=&c;
    cout<< d<<endl;
   
   
    return 0;
}
