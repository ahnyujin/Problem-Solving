bool isOneBitCharacter(int *bits, int bitsSize)
{
    int count = 1;
    for (int i = 0; i < bitsSize; i++)
    {
        count--;
        if (i == bitsSize - 1 && (count != 0 || bits[i] != 0)){
            return false;
        }
        if (count != 0){
            continue;
        }
        if (bits[i] == 1)
        {
            count = 2;
        }
        else
        {
            count = 1;
        }
    }
    return true;
}
