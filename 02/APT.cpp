#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    int n, m, k, *weights;
	uint64_t total = 0, downloaded = 0;
    cin>>n;
    cin>>m;
    cin>>k;
    weights = new int[n];
    for (int i = 0; i < n; i++) {
        cin>>weights[i];
        total += weights[i];
    }
    sort(weights, weights+n);
    int mayor = n - 1;
    int menorDescargable = n > m + k ? n - (m + k) : 0;
    for(int i = mayor; i >= menorDescargable; i--){
    	downloaded += weights[i];
	}
    cout<<setprecision(12)<<(double(downloaded) / double(total)) * double(100)<<endl;	
}
