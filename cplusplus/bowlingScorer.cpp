#include <iostream>
#include <vector>

using namespace std;

int BowlingScorer()
{
    const int STRIKE = 10;
    const int MAX_ROUND = 10;

    int score = 0;
    int round = 1;
    int firstHit = 0;
    int secondHit = 0;

    std::vector<std::pair<int, int>> scoreVec;
    std::vector<int> roundTotalScoreVec(10, 0);
    scoreVec.clear();

    std::cout << "bowling Scorer" << std::endl;

    while (true)
    {
        if (MAX_ROUND < round - 1)
        {
            int totalScore = 0;
            int round = 1;

            // print total score.
            for (const auto& data : scoreVec)
            {
                totalScore += (data.first + data.second);
                std::cout << totalScore << " Total Score " << std::endl;
                round++;
            }

            std::cout << "totalSore : " << totalScore << std::endl;
            return 0;
        }

        if (round == MAX_ROUND)
        {
            auto prev = scoreVec.at(round - 2);
            if (prev.first != STRIKE)
            {
                round++;
                continue;
            }
        }

        std::cout << round << " Round input your score ( 0 ~ 10 )" << std::endl;
        std::cin >> firstHit;

        if (firstHit < 0 || 10 < firstHit)
        {
            std::cout << "input correct score ( 0 ~ 10 )" << std::endl;
            continue;
        }

        if (firstHit == STRIKE)
        {
            std::cout << "STRIKE!!!" << std::endl;

            scoreVec.push_back(std::make_pair(STRIKE, 0));
            round++;
        }
        else
        {
            std::cout << "hit " << firstHit << " pins!!" << std::endl;

            if (round == MAX_ROUND + 1)
            {
                scoreVec.push_back(std::make_pair(firstHit, 0));
                round++;
                continue;
            }

            std::cout << "input your score ( 0 ~ " << (STRIKE - firstHit) << " )" << std::endl;
            std::cin >> secondHit;

            if (STRIKE - firstHit < secondHit)
            {
                std::cout << "input correct score ( 0 ~ 10 )" << std::endl;
                continue;
            }

            scoreVec.push_back(std::make_pair(firstHit, secondHit));
            round++;
        }

        if (round < 3) continue;

        auto& cur = scoreVec.at(round - 2);
        auto& prev = scoreVec.at(round - 3);

        // strike
        if (prev.first == STRIKE)
        {
            prev.first += cur.first;

            if (round < 4) continue;

            auto& pprev = scoreVec.at(round - 4);

            // stkire
            if (pprev.first == STRIKE + STRIKE)
            {
                pprev.first += (cur.first + cur.second);
            }
        }

        // spare
        if ((prev.first + prev.second) == STRIKE)
        {
            prev.first += cur.first;
        }
    }
}