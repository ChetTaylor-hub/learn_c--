/*评委打分案例，使用到vector和deque*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int main()
{
    std::vector<std::deque<int>> person;
    std::deque<int> fractions;

    int fraction = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << "The " << i + 1 << " judge began to score the " << j + 1 << " contestant: ";
            std::cin >> fraction;
            fractions.push_back(fraction);
        }

        std::sort(fractions.begin(), fractions.end());

        // 去除最大值最小值
        fractions.pop_back();
        fractions.pop_front();

        person.push_back(fractions);
        fractions.clear();
    }

    int i = 0;
    int mean = 0;
    for (std::vector<std::deque<int>>::iterator it = person.begin(); it != person.end(); it++)
    {

        std::cout << "the average score of the " << i + 1 << " player: ";
        for (std::deque<int>::iterator jt = (*it).begin(); jt != (*it).end(); jt++)
        {
            mean += (*jt);
        }
        mean /= (*it).size();
        std::cout << mean << std::endl;
        i++;
    }

    return 0;
}