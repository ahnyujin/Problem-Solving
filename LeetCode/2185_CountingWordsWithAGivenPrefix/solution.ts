function prefixCount(words: string[], pref: string): number {
    let ret = 0;
    for(const word of words){
        if(word.startsWith(pref)){
            ret++;
        }
    }
    return ret;
};
