

int minPartitions(char * n){
    char max_char = 0;
    int len = strlen(n);
    for(int i=0;i<len;i++) {
        if (max_char<n[i]) max_char = n[i];
    }
    return max_char-'0';
}
