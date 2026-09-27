#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXVALUE 20 // valor máximo de números na lista recebida
#define MINVALUE 1 // valor ´mínimo de números na lista recebida

void selectionSrot(double *arr, int n);
float fmedia(float *value, int n); //recebe ponteiro para lista de float e contagem dos valores
float fmediana(float *value, int n);
float fdesvio(float *value, int n, int media);


int main() { 
	int cont_n = 0; //guarda contagem de números a incluir

	double min; //alocação de espaço para as estatísticas a mostrar
	double max;
	double media;
	double mediana;
	double d_padrao;
	
	bool is_valid = false;

	// perguntar quantos dados quer
	printf("Quantos números na sua série (N):");
	//checar se número recebido é válido
	do 
	{
		scanf("%d \n", &cont_n);
		if (cont_n > MAXVALUE || cont_n < MINVALUE) 
		{
			printf("Valor informado está fora do intervalo permitido");
		}
		else
		{
			is_valid = true
		}
	} while (!is_valid)
	

	//alocação dinâmica de números
	double *qntde_num = malloc(cont_n* sizeof(float)); // guarda (cont_n) vezes o tamanho de um float

	if(qtde_num == NULL){// validar se deu certo alocar o espaço
        printf("Erro de alocação de memória");
		return 1;
    }
	//receber Input dos valores
	printf("Entre com os números: \n");

	for (int i=0; i<cont_n; i++){
		scanf("%lf", qntde_num[i]); // guardando em "indices" do qntde_num
	}

	selectionSort(&qntde_num[0],cont_n); // reordenar a lista para facilitar estatística


	min = qntde_num[0];
	max = qntde_num[cont_n-1];
	media = fMedia(&qntde_num[0],cont_n);
	mediana = fMediana(&qntde_num[0],cont_n); 
	d_padrao = fDesvio(&qntde_num[0],cont_n,media); //distância de cada valor da média, eleva ao quadrado as distancias, soma, divide por cont_n - 1 e tira raiz quadrada 


	printf("Valor mínimo: %lf \n", min);
	printf("Valor máximo: %lf \n", max);
	printf("Média: %lf \n", media);
	printf("Mediana: %lf \n", mediana);
	printf("Desvio Padrão: %lf \n", d_padrao);

	free(qtde_num);

}

void selectionSort (double *arr, int n){ // função de ordenação para ordenar números recebidos
	for (int i = 0; i< n-1; i++) {
		int min_index = i; 

		for (int j = i + 1; j < n; j++){
			if (arr[j] < arr[min_index]){ //compara valor mínimo com os itens do array
				min_index = j;
			}
		}
	double temp = arr[i];
	arr[i] = arr[min_index];
	arr[min_index] = temp;
	}
}

float fmedia(float *value, int n) 
{
	double totalSum = 0;
	for (int i = 0; i < n ; i++){
		totalSum += value[i];
	}
	return totalSum/n;
}
float fmediana(float *value, int n)
{
	if (n % 2 == 1) //mediana se número for impar
	{
		return value[n/2]; // mediana = número central
	}
	else
	{
		double n1 = value[n/2];
		double n2 = value[(n/2)-1];
		return (n1+n2) /2; // se número for par, mediana = média dos 2 números centrais
	}
}
float fdesvio(float *value)
{
	double desvio = 0;
	for (int i=0; i<n; i++)
	{
		desvio += pow(value[i] - media, 2); // incrementando no desvio a soma das distâncias da média ao quadrado
	}
	desvio = desvio/(n-1);
	return sqrt(desvio);
}