#include <iostream>
#include <math.h>
#include <locale.h>
#include <fstream>

using namespace std;

struct Calculadora{
	float valor1, valor2, ultimoResultadoSalvo, resultado;
	int i = 0;
	string operacao;
	
	void entradaNumeros(){
		cout<<"Primeiro número:"<<endl;
		cin>> valor1;
		cout<<"Segundo número:"<<endl;
		cin>>valor2;
	}

	void salvarResultado(){
		char opcao;
		cout<<"Deseja salvar resultado?"<<endl;
		cin>>opcao;
		if(opcao == 's'){
			ultimoResultadoSalvo = resultado;
		}
	}

	int soma(){
		return valor1 + valor2;
	}
	void calcularSoma(){
		cout<<"Soma:"<<endl;
		entradaNumeros();
		resultado = soma();
		cout<<valor1<<" + "<<valor2<<" = "<<resultado<<endl;
		salvarResultado();
		operacao = " + ";
	}

	int subtracao(){
	return valor1 - valor2; 
	}
	void calcularSubtracao(){
		cout<<"Subtração: "<<endl;
		entradaNumeros();
		resultado = subtracao();
		cout<<valor1<<" - "<<valor2<<" = "<<resultado<<endl;
		salvarResultado();
		operacao = " - ";
	}

	int multiplicacao(){
		return valor1 * valor2;
	}
	void calcularMultiplicacao(){
		cout<<"Multiplicação:"<<endl;
		entradaNumeros();
		resultado = multiplicacao();
		cout<<valor1<<" * "<<valor2<<" = "<<resultado<<endl;
		salvarResultado();
		operacao = " x ";
	}

	float divisao(){
		return valor1 / valor2;
	}
	void calcularDivisao(){
		cout<<"Divisão:"<<endl;
		entradaNumeros();
		if(valor2 == 0){
			cout<<"Erro, denominador igual a zero."<<endl;
			calcularDivisao();
			}else{
				resultado = divisao();
				cout<<valor1<<" / "<<valor2<<" = "<<resultado<<endl;
				}
		salvarResultado();
		operacao = " / ";
	}
	
	//Operações Avançadas

	void calcularPotencia(){
		cout<<"Potencia."<<endl;
		cout<<"Número base:"<<endl;
		cin>>valor1;
		cout<<"Número expoente:"<<endl;
		cin>>valor2;
		resultado = pow(valor1, valor2);
		cout<<valor1<<" elevado a "<<valor2<<" = "<<resultado<<endl;
		salvarResultado();
		operacao = " ^ ";
	}

	void calcularRaizQuadrada(){
		cout<<"Raiz quadrada."<<endl;
		cout<<"Radicando:"<<endl;
		cin>>valor2;
		resultado = sqrt(valor2);
		cout<<"Raiz: "<<resultado<<endl;
		salvarResultado();
		operacao = "Raiz ";
		valor1 = NULL;
	}

	int fatorial(){
		int fatorial = 1;
		for(int i = 1; i <= valor2; i++){
			fatorial *= i;
		}
		return fatorial;
	}
	void calcularFatorial(){
		cout<<"Fatorial."<<endl;
		cout<<"Digite um número:"<<endl;
		cin>>valor2;
		resultado = fatorial();
		cout<<"O fatorial de "<<valor2<<" é "<<resultado<<endl;
		salvarResultado();
		operacao = "Fatorial ";
		valor1 = NULL;
	}

	void calcularSeno(){
		cout<<"Seno"<<endl;
		cout<<"Digite um número em radiano:"<<endl;
		cin>>valor2;
		resultado = sin(valor2);
		cout<<"O seno de "<<valor2<<" é: "<<resultado<<endl;
		salvarResultado();
		operacao = "Seno ";
		valor1 = NULL;
	}

	void calcularCosseno(){
		cout<<"Cosseno."<<endl;
		cout<<"Digite um número em radiano:"<<endl;
		cin>>valor2;
		resultado = cos(valor2);
		cout<<"O cosseno de "<<valor2<<" é "<<resultado<<endl;
		salvarResultado();
		operacao = "Cosseno ";
		valor1 = NULL;
	}

	void calcularTangente(){
		cout<<"Tangente."<<endl;
		cout<<"Digite um número em radiano:"<<endl;
		cin>>valor2;
		resultado = tan(valor2);
		cout<<"A tangente de "<<valor2<<" é "<<resultado<<endl;
		salvarResultado();
		operacao = "Tangente ";
		valor1 = NULL;
	}
};

struct Historico {
	Calculadora historicoCalculadora[10];
	int i = 0;

	void resetarContador() {
		if (i >= 10)
		{
			i = 0;
		}
		
	}
	
	void registrar(Calculadora calculadora) {
		resetarContador();
		historicoCalculadora[i] = calculadora;
		i++;
	}

	void exibir() {
			for (int i = 0; i < 10; i++) {
				if (historicoCalculadora[i].valor1 == NULL){
					cout<<historicoCalculadora[i].operacao<<historicoCalculadora[i].valor2<<" = "<<historicoCalculadora[i].resultado<<endl;
				} else {
					cout<<historicoCalculadora[i].valor1<<historicoCalculadora[i].operacao<<historicoCalculadora[i].valor2<<" = "<< historicoCalculadora[i].resultado<<endl;
				}
				
			}
		}
	
};

void arquivarResultado(Calculadora *calculadora, ofstream &entrada);

int main(int argc, char** argv) {
	setlocale(LC_ALL, "pt-BR.UTF-8");
	
	int* operacao = new int;
	char* flag = new char;
	Calculadora* calculadora = new Calculadora;
	Historico* historico = new Historico;
	ofstream entrada;
	entrada.open("operacoes.txt");
	ifstream leitura;
	
	cout<<" \t <Calculadora cientifica>"<<endl;
	
	do{
		
		cout<<"Qual operação deseja utilizar?"<<endl;
		cout<<"(1-Soma, 2-Subtração, 3-Multiplicação, 4-Divisão, 6-Operações avançadas, 5 - Historico)"<<endl;
		
		cin>>*operacao;
				
		switch(*operacao){
			case 1:
				calculadora->calcularSoma();
				historico->registrar(*calculadora);
				arquivarResultado(calculadora, entrada);
				break;
			case 2:
				calculadora->calcularSubtracao();
				historico->registrar(*calculadora);
				arquivarResultado(calculadora, entrada);
				break;
			case 3:
				calculadora->calcularMultiplicacao();
				historico->registrar(*calculadora);
				arquivarResultado(calculadora, entrada);
				break;
			case 4:
				calculadora->calcularDivisao();
				historico->registrar(*calculadora);
				arquivarResultado(calculadora, entrada);
				break;
			case 5:
				historico->exibir();
				
				break;	
			//Operações Avançadas
			case 6:
				cout<<"Operações avançadas:"<<endl;
				cout<<"Qual operação avançada deseja utilizar?"<<endl;
				cout<<"(1-Potência, 2-Raiz quadrada, 3-Fatorial, 4-Seno, 5-Cosseno ou 6-Tangente.)"<<endl;
				cin>>*operacao;
								
				switch(*operacao){
					case 1:
						calculadora->calcularPotencia();
						historico->registrar(*calculadora);
						arquivarResultado(calculadora, entrada);
						break;
					case 2:
						calculadora->calcularRaizQuadrada();
						historico->registrar(*calculadora);
						arquivarResultado(calculadora, entrada);
						break;
					case 3:
						calculadora->calcularFatorial();
						historico->registrar(*calculadora);
						arquivarResultado(calculadora, entrada);
						break;
					case 4:
						calculadora->calcularSeno();
						historico->registrar(*calculadora);
						arquivarResultado(calculadora, entrada);
						break;	
					case 5:
						calculadora->calcularCosseno();
						historico->registrar(*calculadora);
						arquivarResultado(calculadora, entrada);
						break;
					case 6:
						calculadora->calcularTangente();
						historico->registrar(*calculadora);
						arquivarResultado(calculadora, entrada);
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
		if(*flag != 's'){
			cout<<"Programa encerrado!";
			historico->exibir();
		}
	}while(*flag == 's');
	
	entrada.close();
	delete calculadora;
	delete historico;
	delete flag;
	delete operacao;
	return 0;
}

void arquivarResultado(Calculadora *calculadora, ofstream &entrada){
	if (calculadora->valor1 == NULL)
	{
		entrada << calculadora->operacao << calculadora->valor2 << " = " << calculadora->resultado << "\n";

	} else {
		entrada << calculadora->valor1 << calculadora->operacao << calculadora->valor2 << " = " << calculadora->resultado << "\n";
	}
	
}