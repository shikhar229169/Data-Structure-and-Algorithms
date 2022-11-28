for (int i=c+1; i<N && c; i++) {
            if (arr[i]%c==0 && arr[c]%i==0) {
                int temp=arr[i];
                arr[i]=arr[c];
                arr[c]=temp;
            }
        }