#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    vector<int> primos = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    pair<int, int> primeCount[primos.size()];
    int number;

    for (long i = 0; i < primos.size(); ++i) primeCount[i].first = primos[i];

    while (cin >> number) {
        if (number == 0) break;

        for (long i = 0; i < primos.size(); ++i) primeCount[i].second = 0;

        for (int i = 2; i < number+1; ++i) {
            int k = i, indexPrimo = 0;
            while (k != 1) {
                if (k % primeCount[indexPrimo].first == 0) {
                    ++primeCount[indexPrimo].second;
                    k /= primeCount[indexPrimo].first;
                }
                else{
                    ++indexPrimo;
                }
            }
        }

        int indexMax = 0;
        for (long i = 0; i < primos.size(); i++) {
            if (primeCount[i].second != 0) indexMax = i;
        }

        cout << setw(3) << number;
        cout << "! =";

        for (long i = 0; i <= indexMax; ++i) {
            if (i % 15 == 0 and i > 0){
                cout << '\n' << "      ";
            }
            cout << setw(3) << primeCount[i].second;
        }
        cout << '\n';
    }
    return 0;
}