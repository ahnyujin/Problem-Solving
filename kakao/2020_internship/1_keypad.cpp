#include <string>
#include <vector>
#include <cmath>
using namespace std;
int distance(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
string solution(vector<int> numbers, string hand)
{
    string answer = "";
    pair<int, int> left_hand = make_pair(3, 0);
    pair<int, int> right_hand = make_pair(3, 2);
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 0)
            numbers[i] = 11;
        pair<int, int> number_location = make_pair((numbers[i] - 1) / 3, (numbers[i] - 1) % 3);
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer.append("L");
            left_hand = number_location;
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer.append("R");
            right_hand = number_location;
        }
        else
        {
            int left_length = distance(left_hand, number_location);
            int right_length = distance(right_hand, number_location);
            if (left_length < right_length || (left_length == right_length && hand.compare("left") == 0))
            {
                answer.append("L");
                left_hand = number_location;
            }
            else
            {
                answer.append("R");
                right_hand = number_location;
            }
        }
    }
    return answer;
}