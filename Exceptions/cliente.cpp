#include "exceptions.h"
#include <clocale>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

excecoes<float> exFloat;
excecoes<string> exStting;
excecoes<char> exPtr;

int main(){
    setlocale(LC_ALL, "");
    char op = '0';
    float numerador, denominador, operando;
    string dia, mes, ano;
    string palavraNumerica, palavraAlfabetica;
    cout << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n";
    cout << "#-#-#-#-#-#-#-#-#-#-#-#-#-#     TESTE DE EXCEÇÕES     #-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n";
    cout << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n\n";
    do{
        cout << "############################ Escolha uma das operações: #############################\n";
        cout << "-------------------------------------------------------------------------------------\n";
        cout << "(1) - Divisão por zero.\n";
        cout << "(2) - Raíz de número negativo.\n";
        cout << "(3) - Testar se cadeia de caracteres é numérica.\n";
        cout << "(4) - Testar se cadeia de caracteres é alfabética.\n";
        cout << "(5) - Validar data.\n";
        cout << "(6) - Testar alocação de memória.\n";
        cout << "(0) - Encerrar programa.\n";
        cout << "-------------------------------------------------------------------------------------\n";
        cout << "Opção: ";
        cin >>op;
        fflush(stdin);

        switch (op){
            case '1':
                cout << "Digite o numerador: ";
                cin >> numerador;
                cout << "Digite o denominador: ";
                cin >> denominador;
                if(!exFloat.isDivByZero(denominador)){
                    float resultado = numerador/denominador;
                    cout <<"Divisão válida! Resultado: " << resultado <<"\n\n";
                }
                break;
            case '2':
                cout << "Digite o número do qual deseja obter sua raíz: ";
                cin >> operando;
                if(!exFloat.isNegativeSQR(operando)){
                    float resultado = sqrt(operando);
                    cout << "Operação válida! Resultado: " << resultado <<"\n\n";
                }
                break;
            case '3':
                cout << "Digite uma cadeia de caracteres numéricos: ";
                cin >> palavraNumerica;
                if (!exStting.isNumber(palavraNumerica)){
                    cout << "Correto! Você digitou apenas números.\n\n";
                }
                break;
            case '4':
                cout << "Digite uma cadeia de caracteres alfabéticos: ";
                cin >> palavraAlfabetica;
                if (!exStting.isWord(palavraAlfabetica)){
                    cout << "Correto! Você digitou apenas caracteres alfabéticos.\n\n";
                }
                break;
            case '5':
                cout << "Informe a data. Formato: (dd/mm/aaaa)\n";
                cout << "Digite o dia: ";
                cin >> dia;
                fflush(stdin);
                cout << "Digite o mes: ";
                cin >> mes;
                fflush(stdin);
                cout << "Digite o ano: ";
                cin >> ano;
                fflush(stdin);
                if (!exStting.isDate(dia,mes,ano)){
                    cout << "Correto! Você digitou uma data válida.\n\n";
                }
                break;
            case '6':
                char *ptr, *p;
                long long int qtMemoria;
                cout << "Informe um valor (em bytes) de memória a ser alocado: ";
                cin >> qtMemoria;
                if (qtMemoria > 1000000000000) qtMemoria = 1000000000000;
                ptr = (char *) malloc(qtMemoria*sizeof(char));
                p = exPtr.alocation(ptr);
                free(ptr);
                ptr = NULL;
                if (p != NULL){
                    cout << "Memória alocada com sucesso!\n\n";
                }
                break;
            case '0':
                cout <<"Encerrando o programa...\n";
                free(p);
                p = NULL;
                break;
            default:
                cout <<"Opção Inválida! Tente novamente.\n\n";
        }
    } while (op != '0');
	return 0;
}
