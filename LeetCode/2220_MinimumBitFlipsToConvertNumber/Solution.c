int minBitFlips(int start, int goal)
{
    int dif = start ^ goal;
    int ret = 0;
    while (dif)
    {
        if (dif % 2 == 1)
            ret++;
        dif /= 2;
    }
    return ret;
}
