#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

struct Calculadora{
	int n1, n2;

	void entradaNumeros(){
		cout<<"Primeiro número:"<<endl;
		cin>>n1;
		cout<<"Segundo número:"<<endl;
		cin>>n2;
	}

	int soma(){
		return n1 + n2;
	}
	void calcularSoma(){
		cout<<"Soma:"<<endl;
		entradaNumeros();
		cout<<n1<<" + "<<n2<<" = "<<soma()<<endl;
	}

	int subtracao(){
	return n1 - n2; 
	}
	void calcularSubtracao(){
		cout<<"Subtração: "<<endl;
		entradaNumeros();
		cout<<n1<<" - "<<n2<<" = "<<subtracao()<<endl;
	}

	int multiplicacao(){
		return n1 * n2;
	}
	void calcularMultiplicacao(){
		cout<<"Multiplicação:"<<endl;
		entradaNumeros();
		cout<<n1<<" * "<<n2<<" = "<<multiplicacao()<<endl;
	}

	float divisao(){
		return n1 / n2;
	}
	void calcularDivisao(){
		cout<<"Divisão:"<<endl;
		entradaNumeros();
		if(n2 == 0){
			cout<<"Erro, denominador igual a zero."<<endl;
			calcularDivisao();
			}else{
				cout<<n1<<" / "<<n2<<" = "<<divisao()<<endl;
		}
	}
	
	//Operações Avançadas

	void calcularPotencia(){
		cout<<"Potencia."<<endl;
		cout<<"Número base:"<<endl;
		cin>>n1;
		cout<<"Número expoente:"<<endl;
		cin>>n2;
		cout<<n1<<" elevado a "<<n2<<" = "<<pow(n1,n2)<<endl;
	}

	void calcularRaizQuadrada(){
		cout<<"Raiz quadrada."<<endl;
		cout<<"Radicando:"<<endl;
		cin>>n1;
		
		cout<<"Raiz: "<<sqrt(n1)<<endl;
	}

	int fatorial(){
		int fatorial = 1;
		for(int i = 1; i <= n1; i++){
			fatorial *= i;
		}
		return fatorial;
	}
	void calcularFatorial(){
		cout<<"Fatorial."<<endl;
		cout<<"Digite um número:"<<endl;
		cin>>n1;
		cout<<"O fatorial de "<<n1<<" é "<<fatorial()<<endl;
	}

	void calcularSeno(){
		cout<<"Seno"<<endl;
		cout<<"Digite um número em radiano:"<<endl;
		cin>>n1;
		cout<<"O seno é: "<<sin(n1)<<endl;
	}

	void calcularCosseno(){
		cout<<"Cosseno."<<endl;
		cout<<"Digite um número em radiano:"<<endl;
		cin>>n1;
		cout<<"O cosseno de "<<n1<<" é "<<cos(n1)<<endl;
	}

	void calcularTangente(){
		cout<<"Tangente."<<endl;
		cout<<"Digite um número em radiano:"<<endl;
		cin>>n1;
		cout<<"A tangente de "<<n1<<" é "<<tan(n1)<<endl;
	}
};

int main(int argc, char** argv) {
	setlocale(LC_ALL, "pt-BR.UTF-8");
	
	int operacao, i;
	char flag, salvarResultado, limpaHistorico, exibirHistorico;
	Calculadora calculadora;
	i = 0;
	
	cout<<" \t <Calculadora cientifica>"<<endl;
	do{
		
		cout<<"Qual operação deseja utilizar?"<<endl;
		cout<<"(1-Soma, 2-Subtração, 3-Multiplicação, 4-Divisão, 5-Operações avançadas)"<<endl;
		cin>>operacao;
				
		switch(operacao){
			case 1:
				calculadora.calcularSoma();
				break;
			case 2:
				calculadora.calcularSubtracao();
				break;
			case 3:
				calculadora.calcularMultiplicacao();
				break;
			case 4:
				calculadora.calcularDivisao();
				break;				
			//Operações Avançadas
			case 5:
				cout<<"Operações avançadas:"<<endl;
				cout<<"Qual operação avançada deseja utilizar?"<<endl;
				cout<<"(1-Potência, 2-Raiz quadrada, 3-Fatorial, 4-Seno, 5-Cosseno ou 6-Tangente.)"<<endl;
				cin>>operacao;
								
				switch(operacao){
					case 1:
						calculadora.calcularPotencia();
						break;
					case 2:
						calculadora.calcularRaizQuadrada();
						break;
					case 3:
						calculadora.calcularFatorial();
						break;
					case 4:
						calculadora.calcularSeno();
						break;	
					case 5:
						calculadora.calcularCosseno();
						break;
					case 6:
						calculadora.calcularTangente();
						break;
					default:
						cout<<"Operação avançada inválida!"<<endl;
				}
				break;
			default:
				cout<<"Operação inválida!"<<endl;
			
		}

		cout<<"Deseja continuar?(s/n)"<<endl;
		cin>>flag;
		if(flag != 's'){
			cout<<"Programa encerrado!";
		}
	}while(flag == 's');
	
	return 0;
}