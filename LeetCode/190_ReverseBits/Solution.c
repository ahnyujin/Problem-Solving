uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    int count = 32;
    while (n!=0){
        ret*=2;
        ret+=(n%2);
        n/=2;
        count--;
    }
    if (count==32) return 0;
    return ret << count;
}
