/*
A company is planning to interview 2n people. You're given the array costs where costs[i]=[aCost(i),​bCost(i)].
The cost of flying the ith person to city A is aCost(i) , and the cost of flying the ith person to city B is bCost(i) .

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.

Constraints
 costs.length=2*n
 2<=costs.length<=100
 1<=acost[i],bcost[i]<=1000
*/

#include<vector>
#include<iostream>
#include <algorithm>
typedef std::pair<int,int> Pair;

int TwoCityScheduling(std::vector<Pair> &costs)
{
    // Array that we will use to divide the group in two equal parts
    std::vector<Pair> difference;
    // Initiliazing a loop, to calculate the difference to travel to City A or B
    for (int i = 0; i < costs.size(); i++)
    {
        difference.push_back(std::make_pair(costs[i].second - costs[i].first, i));
    }
    // We sort the array based on the differences we calculated above
    std::sort(difference.begin(), difference.end());
    // Initiliazing a new variable to calculate the minimum cost required to send exactly n people to both cities
    int answer = 0;
    // Initiliazing a loop, to add the relevent costs to our answer variable
    for (int i = 0; i < difference.size(); i++)
    {
        int index = difference[i].second;
        answer += (i < difference.size() / 2) ? costs[index].second : costs[index].first;
    }
    return answer;
}

int main()
{
    std::vector<std::vector<Pair>> A = {{std::make_pair(10, 20), std::make_pair(30, 200), std::make_pair(400, 50), std::make_pair(30, 20)},
                                        {std::make_pair(259, 770), std::make_pair(448, 54), std::make_pair(926, 667), std::make_pair(184, 139), std::make_pair(840, 118), std::make_pair(577, 469)},
                                        {std::make_pair(515, 563), std::make_pair(451, 713), std::make_pair(537, 709), std::make_pair(343, 819), std::make_pair(855, 779), std::make_pair(457, 60), std::make_pair(650, 359), std::make_pair(631, 42)},
                                        {std::make_pair(1, 2), std::make_pair(3, 4), std::make_pair(5, 6), std::make_pair(7, 8)},
                                        {std::make_pair(1, 2), std::make_pair(1, 2), std::make_pair(1, 2), std::make_pair(1, 2)}};
    for (int i = 0; i < A.size(); i++)
    {
        std::cout << i + 1 << ".\t The minimum cost to send people equally into City A and B when the costs are"
                  << "\n\t " << " is: "
                  << TwoCityScheduling(A[i]) << std::endl;
        std::cout << std::string(100, '-') << std::endl;
    }
}