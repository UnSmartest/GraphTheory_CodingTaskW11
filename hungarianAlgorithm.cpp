//this reminds me of lab PKT lol
//it's like, finding the most optimal path
//well, that's also tegraf in a way i guess
//yeah this is really reminiscent of PKT
#include <iostream>
using namespace std;
#include <vector>
#include <limits>
#include <algorithm>
const int INF = numeric_limits<int>::max();

void lineSeparator(){
    cout << "=================================================\n";
}

int hungarianAlgorithm(vector<vector<int>> matrixOfCosts){
    int n = matrixOfCosts.size();
    vector<int> u(n + 1), v(n + 1), p(n + 1), way(n + 1);

    for(int i = 1; i <= n; ++i){
        p[0] = i;
        int j0 = 0;
        vector<int> minv(n + 1, INF);
        vector<char> used(n + 1, false);
        do{
            used[j0] = true;
            int i0 = p[j0], diff = INF, j1 = 0;
            for(int j = 1; j <= n; ++j){
                if(!used[j]){
                    int cur = matrixOfCosts[i0 - 1][j - 1] - u[i0] - v[j];
                    if(cur < minv[j]){
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if(minv[j] < diff){
                        diff = minv[j];
                        j1 = j;
                    }
                }
            }
            for(int j = 0; j <= n; ++j){
                if(used[j]){
                    u[p[j]] += diff;
                    v[j] -= diff;
                } else {
                    minv[j] -= diff;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);

        do{
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while(j0);
    }

    vector<int> assignment(n + 1);
    for(int j = 1; j <= n; ++j) assignment[p[j]] = j;

    int smallestCost = -v[0];
    for(int i = 1; i <= n; ++i) cout << "Bulldozer " << i << " goes to site " << assignment[i] << "\n";
    lineSeparator();
    cout << "The total minimum cost will be " << smallestCost << "\n";

    return smallestCost;
}

int main() {
    int bulldozers, constructionSites;
    lineSeparator();
    cout << "How many bulldozers & construction sites? (use space to separate both values)\n";
    cin >> bulldozers >> constructionSites;
    lineSeparator();

    int n = max(bulldozers, constructionSites);
    vector<vector<int>> matrixOfCosts(n, vector<int>(n, 0));

    cout << "Enter the cost matrix below\n";
    for (int i = 0; i < bulldozers; ++i) {
        for (int j = 0; j < constructionSites; ++j) {
            cin >> matrixOfCosts[i][j];
        }
    }
    lineSeparator();
    hungarianAlgorithm(matrixOfCosts);
    lineSeparator();
    return 0;
}
