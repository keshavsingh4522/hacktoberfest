#include<stdio.h>


int main(){
	float pi;
	float volume;
	float altura;
	float raio;
	
	printf("Digite o raio: ");
	scanf("%f", &raio);
	
	printf("Digite a altura: ");
	scanf("%f", &altura);
	
	pi = 3.14;
	volume = pi * (raio * raio) * altura;
	
	printf("Volume e %f", volume);
	
	return 0;
}
