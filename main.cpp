#include <iostream>
using namespace std;

string ordemAlfabetica(string palavra1, string palavra2){
	char alfabeto[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	
	string maiorPalavra;
	string menorPalavra;
	if(palavra1.length()>=palavra2.length()){
		maiorPalavra = palavra1;
		menorPalavra = palavra2;
	} else{
		maiorPalavra = palavra2;
		menorPalavra = palavra1;
	}
	
	int indiceLetraPalavra1[palavra1.length()];
	for(int j = 0; j<palavra1.length(); j++){
		for(int i = 0; i<26; i++){
			if(toupper(palavra1[j]) == alfabeto[i]){
				indiceLetraPalavra1[j] = i;
				break;
			}
		}
	}
	int indiceLetraPalavra2[palavra2.length()];
	for(int j = 0; j<palavra2.length(); j++){
		for(int i = 0; i<26; i++){
			if(toupper(palavra2[j]) == alfabeto[i]){
				indiceLetraPalavra2[j] = i;
				break;
			}
		}
	}
	
	for(int i = 0; i < menorPalavra.length(); i++){
		if(indiceLetraPalavra1[i] < indiceLetraPalavra2[i]){
			return palavra1;
		} else if(indiceLetraPalavra2[i] < indiceLetraPalavra1[i]){
			return palavra2;
		}
	}
	return menorPalavra;
}

void bubbleSort(string vetor[], int tamanhoVetor){
	for(int i = 0; i < tamanhoVetor; i++){
		for(int j = 0; j < tamanhoVetor - (i + 1); j++){
			if(ordemAlfabetica(vetor[j], vetor[j+1]) == vetor[j+1]){
				string aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}
	for(int i = 0; i < tamanhoVetor; i++){
		cout << vetor[i] << ", ";
	}
}

void insertionSort(string vetor[], int tamanhoVetor){
	for(int i = 1; i < tamanhoVetor; i++){
		string aux = vetor[i];
		int indexMenor = i-1;
		/*while(indexMenor >= 0 && ordemAlfabetica(aux, vetor[indexMenor]) == aux){
			vetor[indexMenor + 1] = vetor[indexMenor];
			indexMenor --;
		}
		vetor[indexMenor + 1] = aux;
		*/
		for(int j = i-1; j >= 0; j--){
			if(ordemAlfabetica(aux, vetor[j]) == aux){
				vetor[j+1] = vetor[j];
				if(j == 0){
					vetor[j] = aux;
				}
			} else{
				vetor[j+1] = aux;
				break;
			}
		}
	}
	for(int i = 0; i < tamanhoVetor; i++){
		cout << vetor[i] << ", ";
	}
}

void selectionSort(string vetor[], int tamanhoVetor){
	for(int i = 0; i < tamanhoVetor; i++){
		string menor = vetor[i];
		int indexMenor = i;
		for(int j = i + 1; j < tamanhoVetor; j++){
			if(ordemAlfabetica(vetor[j], menor) == vetor[j]){
				indexMenor = j;
				menor = vetor[j];
			} 
		}
		vetor[indexMenor] = vetor[i];
		vetor[i] = menor;
	}
	for(int i = 0; i < tamanhoVetor; i++){
		cout << vetor[i] << ", ";
	}
}

int main() {
	string vetor[5] = {"Leontiev", "Louise", "Tercia", "Enilda", "Alice"};
	selectionSort(vetor, 5);
	return 0;
}
