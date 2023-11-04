#include <vector>

class Solution {
public:
    std::vector<int> Torneo(std::vector<int> habilidades, int N, int K) {
        std::vector<int> queue;
        std::vector<int> winners;
        std::vector<int> losers;

        for (int i = 2; i <= habilidades.size(); i++) {
            queue.push_back(i);
        }

        int winner = 1;
        int loser = 2;
        int consecutiveWins = 1;

        while (consecutiveWins < N) {
            if (habilidades[winner - 1] > habilidades[loser - 1]) {
                winners.push_back(habilidades[winner - 1]);
                losers.push_back(habilidades[loser - 1]);
                consecutiveWins++;
                loser = queue[0];
                queue.erase(queue.begin());
            } else {
                winners.push_back(habilidades[loser - 1]);
                losers.push_back(habilidades[winner - 1]);
                consecutiveWins = 1;
                queue.push_back(winner);
                winner = queue[0];
                queue.erase(queue.begin());
            }
        }

        return {losers[K - 1], winners[K - 1]};
    }
};
