double pow(double x, int n){
    if( n == 0) return 1;
    if (n == 1) return x;
    if(n<0){
        n=-n;
        x = 1/x;
    }
    return (n%2 == 0) ? pow(x*x, n/2): x*pow(x*x, n/2);
}