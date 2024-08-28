#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, m, k, *weights, total = 0, downloaded = 0;
    cin>>n;
    cin>>m;
    cin>>k;
    weights = new int[n];
    for (int i = 0; i < n; i++) {
        cin>>weights[i];
        total += weights[i];
    }
    sort(weights, weights+n);
    for (int i = n - 1 ; i >=  n - (m + k); i--) {
        downloaded += weights[i];
    }
    cout<<(double(downloaded) / double(total)) * double(100);
}