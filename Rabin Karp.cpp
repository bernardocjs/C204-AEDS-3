#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

void rabin_karp(char T[], char P[], int tamT, int tamP, int d, int q)
{

	int h; // valor utilizado para calculo de hash
	int p = 0; // padrao convertido para inteiro
	int t = 0; // texto convertido para inteiro
	int n;
	int cont = 0;

	for(int i = 0; i < tamP; i++)
	{
		p = (d * p + (P[i]-'0')) % q; // converte o padrao
		t = (d * t + (T[i]-'0')) % q; // converte o texto para o primeiro valor (t0)
	}
	
	h = (int)pow(d, tamP - 1) % q; // utilizado para calculo de hash
	
	for(int i = 0; i <= tamT - tamP; i++)
	{
		if(p == t) // Se encontrei um valor de hash valido
		{
			// Verifico se ha diferencas
			int j;
			for(j = 0; j < tamP; j++)
			{
				if(P[j] != T[i + j])
				{
					break;
				}
			}

			if(j == tamP){
			n = i;
			cont++;	
			} 
		}

		if(i < tamT - tamP) // se ainda nao cheguei no final
		{
			t = (d * ( t - (T[i]-'0') * h ) + (T[i + tamP]-'0')) % q; // atualizo o ti para ti+1
			if(t < 0) t += q;
		}
	}
cout << "Ultima ocorrencia: "<< n << endl;
cout << cont << " ocorrencia(s)" << endl;
}

int main()
{

	char texto[100];
	char padrao[100];
	int tamtxt;
	int tampad;

	// cardinalidade do alfabeto usado no texto, em outras palavras, qtd de caracteres diferentes utilizados
	int d = 20;
	// n�mero primo grande, para calcular os valores no hash
	int q = 13;
	
	cin >> tamtxt;
	cin >> tampad;
	
	cout << "Digite o texto: ";
	cin >> texto;
	
	cout << "Agora, digite o padrao a ser buscado: ";
	cin >> padrao;

	rabin_karp(texto, padrao, tamtxt, tampad, d, q);

	return 0;
}





