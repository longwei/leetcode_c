void removeSpace(char *str) {
    char* runner = str;
    while(*runner){
        if(*runner = ' '){
            runner++;
        } else {
            *str++ = *runner++;
        }
    }
    *runner='\0';
}

int main()
{
    char x[] = "longwei su  123";
//    removeSpace(x);
    cout << x << endl;
    return 0;
}

//the difference between char x[] and char* is that char* is going to in read-only data section