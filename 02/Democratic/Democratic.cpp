#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


char masRepetido(vector<string>& matrizLetras, int columna){
	unordered_map<char, int> frecuencia;
	for(string fila : matrizLetras) {
		frecuencia[fila[columna]]++;
	}
	int maxFrecuencia = 0;
	char masFrecuente;
	for(auto& letra : frecuencia){
		if(letra.second > maxFrecuencia){
			maxFrecuencia = letra.second;
			masFrecuente = letra.first;
		}
		else if(letra.second == maxFrecuencia){
			if(masFrecuente > letra.first){
				masFrecuente = letra.first;
			}
		}
	}
	return masFrecuente;
}

int main(){
    int n, m;
    cin>>n;
    cin>>m;
    vector<string> matrizLetras;
    matrizLetras.resize(n);
    for(int i = 0; i < n; i++){
        cin>>matrizLetras[i];
    }
	for(int i = 0; i < m; i++){
		cout<<masRepetido(matrizLetras, i);
	}
	cout<<endl;
}
