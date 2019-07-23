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
    cout << "#-#-#-#-#-#-#-#-#-#-#-#-#-#     TESTE DE EXCE��ES     #-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n";
    cout << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n\n";
    do{
        cout << "############################ Escolha uma das opera��es: #############################\n";
        cout << "-------------------------------------------------------------------------------------\n";
        cout << "(1) - Divis�o por zero.\n";
        cout << "(2) - Ra�z de n�mero negativo.\n";
        cout << "(3) - Testar se cadeia de caracteres � num�rica.\n";
        cout << "(4) - Testar se cadeia de caracteres � alfab�tica.\n";
        cout << "(5) - Validar data.\n";
        cout << "(6) - Testar aloca��o de mem�ria.\n";
        cout << "(0) - Encerrar programa.\n";
        cout << "-------------------------------------------------------------------------------------\n";
        cout << "Op��o: ";
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
                    cout <<"Divis�o v�lida! Resultado: " << resultado <<"\n\n";
                }
                break;
            case '2':
                cout << "Digite o n�mero do qual deseja obter sua ra�z: ";
                cin >> operando;
                if(!exFloat.isNegativeSQR(operando)){
                    float resultado = sqrt(operando);
                    cout << "Opera��o v�lida! Resultado: " << resultado <<"\n\n";
                }
                break;
            case '3':
                cout << "Digite uma cadeia de caracteres num�ricos: ";
                cin >> palavraNumerica;
                if (!exStting.isNumber(palavraNumerica)){
                    cout << "Correto! Voc� digitou apenas n�meros.\n\n";
                }
                break;
            case '4':
                cout << "Digite uma cadeia de caracteres alfab�ticos: ";
                cin >> palavraAlfabetica;
                if (!exStting.isWord(palavraAlfabetica)){
                    cout << "Correto! Voc� digitou apenas caracteres alfab�ticos.\n\n";
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
                    cout << "Correto! Voc� digitou uma data v�lida.\n\n";
                }
                break;
            case '6':
                char *ptr, *p;
                long long int qtMemoria;
                cout << "Informe um valor (em bytes) de mem�ria a ser alocado: ";
                cin >> qtMemoria;
                if (qtMemoria > 1000000000000) qtMemoria = 1000000000000;
                ptr = (char *) malloc(qtMemoria*sizeof(char));
                p = exPtr.alocation(ptr);
                free(ptr);
                ptr = NULL;
                if (p != NULL){
                    cout << "Mem�ria alocada com sucesso!\n\n";
                }
                break;
            case '0':
                cout <<"Encerrando o programa...\n";
                free(p);
                p = NULL;
                break;
            default:
                cout <<"Op��o Inv�lida! Tente novamente.\n\n";
        }
    } while (op != '0');
	return 0;
}
