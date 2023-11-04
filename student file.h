#include <vector>

using namespace std;

vector<int> Torneo(vector<int> habilidades, int N, int K) {
    while (K > 0) {
        int p1 = 0;
        int p2 = 1;

        if (habilidades[p1] < habilidades[p2]) {
            swap(p1, p2);
        }

        if (N == 1) {
            return {habilidades[p2], habilidades[p1]};
        }

        int consecutiveWins = 1;

        while (consecutiveWins < N) {
            if (p2 >= habilidades.size() - 1) {
                return {habilidades[p1], habilidades[p2]};
            }

            p2++;
            consecutiveWins++;
        }

        if (p2 >= habilidades.size() - 1) {
            return {habilidades[p1], habilidades[p2]};
        }

        K--;
        if (habilidades[p1] > habilidades[p2]) {
            swap(p1, p2);
        }
    }

    return {habilidades[1], habilidades[0]};
}
