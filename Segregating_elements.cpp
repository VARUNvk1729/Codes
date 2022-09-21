 void segregateElements(int arr[],int n)
    {
        int a[n];
        int k=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                a[k]=arr[i];
                k++;
            }
            
        }
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                a[k]=arr[i];
                k++;
            }
            
        }
        for(int i=0;i<n;i++){
            arr[i]=a[i];
        }
        
        // Your code goes here
    }
