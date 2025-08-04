class Solution {
    fun totalFruit(fruits: IntArray): Int {
        var ret=0
        val table=IntArray(fruits.size)
        var left=0
        var basket=0

        for(right in fruits.indices) {
            if(table[fruits[right]]==0)basket++
            table[fruits[right]]++
            while(basket>2){
                table[fruits[left]]--
                if (table[fruits[left]]==0)basket--
                left++
            }
            ret=maxOf(ret,right-left+1)
        }
        return ret
    }
}
