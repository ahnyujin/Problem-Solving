class Solution {
    fun maxDifference(s: String): Int {
        val freqMap = IntArray(26)
        for (ch in s) {
            freqMap[ch - 'a']++
        }

        val oddFreqs = freqMap.filter { it % 2 == 1 }
        val evenFreqs = freqMap.filter { it != 0 && it % 2 == 0 }

        if (oddFreqs.isEmpty() || evenFreqs.isEmpty()) return 0

        val maxOdd = oddFreqs.maxOrNull()!!
        val minEven = evenFreqs.minOrNull()!!

        return maxOdd - minEven
    }
}
