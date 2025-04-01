#include <iostream>
#include <math.h>
#include <locale.h>
#include <fstream>

using namespace std;

struct Calculadora{
	float n1, n2, ultimoResultadoSalvo, resultado;
	int i = 0;
	string operacao;
	
	void entradaNumeros(){
		cout<<"Primeiro número:"<<endl;
		cin>>n1;
		cout<<"Segundo número:"<<endl;
		cin>>n2;
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
		return n1 + n2;
	}
	void calcularSoma(){
		cout<<"Soma:"<<endl;
		entradaNumeros();
		resultado = soma();
		cout<<n1<<" + "<<n2<<" = "<<resultado<<endl;
		salvarResultado();
		operacao = " + ";
	}

	int subtracao(){
	return n1 - n2; 
	}
	void calcularSubtracao(){
		cout<<"Subtração: "<<endl;
		entradaNumeros();
		resultado = subtracao();
		cout<<n1<<" - "<<n2<<" = "<<resultado<<endl;
		salvarResultado();
		operacao = " - ";
	}

	int multiplicacao(){
		return n1 * n2;
	}
	void calcularMultiplicacao(){
		cout<<"Multiplicação:"<<endl;
		entradaNumeros();
		cout<<n1<<" * "<<n2<<" = "<<multiplicacao()<<endl;
		salvarResultado();
		operacao = " x ";
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
		salvarResultado();
		operacao = " / ";
	}
	
	//Operações Avançadas

	void calcularPotencia(){
		cout<<"Potencia."<<endl;
		cout<<"Número base:"<<endl;
		cin>>n1;
		cout<<"Número expoente:"<<endl;
		cin>>n2;
		cout<<n1<<" elevado a "<<n2<<" = "<<pow(n1,n2)<<endl;
		salvarResultado();
		operacao = " ^ ";
	}

	void calcularRaizQuadrada(){
		cout<<"Raiz quadrada."<<endl;
		cout<<"Radicando:"<<endl;
		cin>>n2;
		resultado = sqrt(n2);
		cout<<"Raiz: "<<resultado<<endl;
		salvarResultado();
		operacao = "Raiz ";
		n1 = NULL;
	}

	int fatorial(){
		int fatorial = 1;
		for(int i = 1; i <= n2; i++){
			fatorial *= i;
		}
		return fatorial;
	}
	void calcularFatorial(){
		cout<<"Fatorial."<<endl;
		cout<<"Digite um número:"<<endl;
		cin>>n2;
		resultado = fatorial();
		cout<<"O fatorial de "<<n2<<" é "<<resultado<<endl;
		salvarResultado();
		operacao = "Fatorial ";
		n1 = NULL;
	}

	void calcularSeno(){
		cout<<"Seno"<<endl;
		cout<<"Digite um número em radiano:"<<endl;
		cin>>n2;
		resultado = sin(n2);
		cout<<"O seno de "<<n2<<" é: "<<resultado<<endl;
		salvarResultado();
		operacao = "Seno ";
		n1 = NULL;
	}

	void calcularCosseno(){
		cout<<"Cosseno."<<endl;
		cout<<"Digite um número em radiano:"<<endl;
		cin>>n2;
		resultado = cos(n2);
		cout<<"O cosseno de "<<n2<<" é "<<resultado<<endl;
		salvarResultado();
		operacao = "Cosseno ";
		n1 = NULL;
	}

	void calcularTangente(){
		cout<<"Tangente."<<endl;
		cout<<"Digite um número em radiano:"<<endl;
		cin>>n2;
		resultado = tan(n2);
		cout<<"A tangente de "<<n2<<" é "<<resultado<<endl;
		salvarResultado();
		operacao = "Tangente ";
		n1 = NULL;
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
				if (historicoCalculadora[i].n1 == NULL){
					cout<<historicoCalculadora[i].operacao<<historicoCalculadora[i].n2<<" = "<<historicoCalculadora[i].resultado<<endl;
				} else {
					cout<<historicoCalculadora[i].n1<<historicoCalculadora[i].operacao<<historicoCalculadora[i].n2<<" = "<< historicoCalculadora[i].resultado<<endl;
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

	delete calculadora;
	delete historico;
	delete flag;
	delete operacao;
	entrada.close();
	return 0;
}

void arquivarResultado(Calculadora *calculadora, ofstream &entrada){
	entrada << calculadora->n1 << calculadora->operacao << calculadora->n2 << " = " << calculadora->resultado << "\n";
}