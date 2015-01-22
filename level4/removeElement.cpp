int removeElement(int A[], int n, int elem) {
    int end = n-1;
    int i = 0;
    while ( i<=end ){
        if (A[i]==elem){
            A[i] = A[end--];
            continue;
        }
        i++;
    }
    return end+1;
}