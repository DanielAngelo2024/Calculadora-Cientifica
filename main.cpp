#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Soma
int soma(int n1, int n2){
	return n1 + n2;
}

//Subtra��o
int subtracao(int n1, int n2){
	return n1 - n2; 
}

//Multiplica��o
int multiplicacao(int n1, int n2){
	return n1 * n2;
}

//Divis�o
float divisao(float n1, float n2){
	return n1 / n2;
}

//Fatorial
int fatorial(int n){
	int fatorial = 1;
	for(int i = 1; i <= n; i++){
		fatorial *= i;
	}
	return fatorial;
}


int main(int argc, char** argv) {
	setlocale(LC_ALL, "");
	
	int n1, n2, operacao, resultado, memoria, historico[10], i;
	char flag, salvarResultado, limpaHistorico, exibirHistorico;
	i = 0;
	
	for (int i = 0; i<10; i++){
		historico[i] = 0;
	}
	
	cout<<" \t <Calculadora cientifica>"<<endl;
	do{
		
		cout<<"Qual opera��o deseja utilizar?"<<endl;
		cout<<"(1-Soma, 2-Subtra��o, 3-Multiplica��o, 4-Divis�o, 5-Opera��es avan�adas)"<<endl;
		cin>>operacao;
		
		cout<<endl;
		
		switch(operacao){
			case 1:
				cout<<"Soma."<<endl;
				cout<<"Primeiro n�mero:"<<endl;
				cin>>n1;
				cout<<"Segundo n�mero:"<<endl;
				cin>>n2;
				resultado = soma(n1, n2);
				cout<<n1<<" + "<<n2<<" = "<<resultado<<endl;
				break;
			case 2:
				cout<<"Subtra��o."<<endl;
				cout<<"Primeiro n�mero:"<<endl;
				cin>>n1;
				cout<<"Segundo n�mero:"<<endl;
				cin>>n2;
				resultado = subtracao(n1, n2);
				cout<<n1<<" - "<<n2<<" = "<<resultado<<endl;
				break;
			case 3:
				cout<<"Multiplica��o."<<endl;
				cout<<"Primeiro n�mero:"<<endl;
				cin>>n1;
				cout<<"Segundo n�mero:"<<endl;
				cin>>n2;
				resultado = multiplicacao(n1, n2);
				cout<<n1<<" X "<<n2<<" = "<<resultado<<endl;
				break;
			case 4:
				cout<<"Divis�o."<<endl;
				cout<<"Primeiro n�mero:"<<endl;
				cin>>n1;
				cout<<"Segundo n�mero:"<<endl;
				cin>>n2;
				resultado = divisao(n1, n2);
				if(n2 == 0){
					cout<<"Erro, denominador igual a zero."<<endl;
				}else{
					cout<<n1<<" / "<<n2<<" = "<<divisao(n1, n2)<<endl;
				}
				break;				
			//Opera��es Avan�adas
			case 5:
				cout<<"Opera��es avan�adas:"<<endl;
				cout<<"Qual opera��o avan�ada deseja utilizar?"<<endl;
				cout<<"(1-Pot�ncia, 2-Raiz quadrada, 3-Fatorial, 4-Seno, 5-Cosseno ou 6-Tangente.)"<<endl;
				cin>>operacao;
				
				cout<<endl;
				
				switch(operacao){
					case 1:
						cout<<"Potencia."<<endl;
						cout<<"N�mero base:"<<endl;
						cin>>n1;
						cout<<"N�mero expoente:"<<endl;
						cin>>n2;
						resultado = pow(n1, n2);
						cout<<n1<<" elevado a "<<n2<<" = "<<resultado<<endl;
						break;
					case 2:
						cout<<"Raiz quadrada."<<endl;
						cout<<"Radicando:"<<endl;
						cin>>n1;
						resultado = sqrt(n1);
						cout<<"Raiz: "<<resultado<<endl;
						break;
					case 3:
						cout<<"Fatorial."<<endl;
						cout<<"Digite um n�mero:"<<endl;
						cin>>n1;
						resultado = fatorial(n1);
						cout<<"O fatorial de "<<n1<<" � "<<resultado<<endl;
						break;
					case 4:
						cout<<"Seno"<<endl;
						cout<<"Digite um n�mero em radiano:"<<endl;
						cin>>n1;
						resultado = sin(n1);
						cout<<"O seno �: "<<resultado<<endl;
						break;	
					case 5:
						cout<<"Cosseno."<<endl;
						cout<<"Digite um n�mero em radiano:"<<endl;
						cin>>n1;
						resultado = cos(n1);
						cout<<"O cosseno de "<<n1<<" � "<<resultado<<endl;
						break;
					case 6:
						cout<<"Tangente."<<endl;
						cout<<"Digite um n�mero em radiano:"<<endl;
						cin>>n1;
						resultado = tan(n1);
						cout<<"A tangente de "<<n1<<" � "<<resultado<<endl;
						break;
					default:
						cout<<"Opera��o avan�ada inv�lida!"<<endl;
				}
				break;
			default:
				cout<<"Opera��o inv�lida!"<<endl;
			
		}
	
		//Guarda ultimo resultado na memoria
		cout<<"Salvar ultimo resultado?(s/n)"<<endl;
		cin>>salvarResultado;
		if(salvarResultado == 's'){
			memoria = resultado;
		}
		
		//Salva as 10 ultimas opera��es
		historico[i] = resultado;
		i++;
		if(i >= 10){
			i=0;
		}
		//Exibir ultimas 10 opera��es
		cout<<"Exibir hist�rico?(s/n)"<<endl;
		cin>>exibirHistorico;
		if(exibirHistorico == 's'){
			for(int i = 0; i < 10; i++){
				cout<<historico[i]<<",";
			}
		}
		
		cout<<"Deseja continuar?(s/n)"<<endl;
		cin>>flag;
		if(flag != 's'){
			cout<<"Programa encerrado!";
		}
	}while(flag == 's');
	
	return 0;
}
