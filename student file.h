#include <vector>

using namespace std;

vector<int> Torneo(vector<int> habilidades, int N, int K) {
    int winner = 0;
    int loser = 1;
    int consecutiveWins = 0;

    while (K > 0) {
        if (habilidades[loser] > habilidades[winner]) {
            swap(winner, loser);
        }

        consecutiveWins++;

        if (consecutiveWins == N) {
            K--;
            consecutiveWins = 0;
        } else {
            loser++;
        }

        if (loser == habilidades.size()) {
            return {habilidades[loser - 1], habilidades[winner]};
        }
    }

    return {habilidades[loser], habilidades[winner]};
}
