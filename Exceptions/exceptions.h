#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <cctype>
#include <ctime>
#include <clocale>

using namespace std;

template <class T> class excecoes{
 public:
    class erro{ }; //classe para referência na ocorrencia de erro. Utiliza-se construtor por ocultação
    void Mensagem (string msg); //Permite passar por parâmetro qualquer mensagem e exibi-la para o usuário
    bool isDivByZero (T numero); //retorna true se ocorreu uma tentativa de divisao por zero
    bool isNegativeSQR (T numero); //retorna true se houver tentativa de raiz negativa
    bool isNumber (T numero); //retorna true se o valor valor passado possui apenas números
    bool isWord (T palavra); //retorna true se o valor valor passado possui apenas char
    bool isDate (T dia, T mes, T ano); //returna true se for uma data válida
    T* alocation(T* ptr); //Caso não ocorra um erro de alocação de memmória devolve um ponteriro alocado

 private:
    T item; //Atributo privado que futuramente pode ser utilizado
};

template <class T> void excecoes<T>::Mensagem(string msg){
    cout << msg << " Erro gravado no arquivo arquivo de logs." << endl << endl;
}

template <class T> bool excecoes<T>::isDivByZero(T numero){
    try{
        if (numero==0){
            throw (erro());
        }
    }
    catch (excecoes::erro){
        Mensagem("Erro 01: Divisao por zero.");
        FILE *arq = fopen("../ErrorFiles/errorlogs.dat", "a");
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        char output[30];
        strftime(output, 30,"%d/%m/%Y as %H:%M:%S", timeinfo);
        fprintf(arq, "Erro 01: Divisao por zero. Horario de ocorrancia: %s\n", output);
        fclose(arq);
        free(arq);
        return true;
    }
    return false;
}

template <class T> bool excecoes<T>::isNegativeSQR(T numero){
    try {
        if (numero < 0){
            throw (erro());
        }
    }
    catch (excecoes::erro){
        Mensagem("Erro 02: Raiz de numero negativo.");
        FILE *arq = fopen("../ErrorFiles/errorlogs.dat", "a");
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        char output[30];
        strftime(output, 30,"%d/%m/%Y as %H:%M:%S", timeinfo);
        fprintf(arq, "Erro 02: Raiz de numero negativo. Horario de ocorrencia: %s\n", output);
        fclose(arq);
        free(arq);
        return true;
    }
    return false;
}

template <class T> bool excecoes<T>::isNumber(T numero){
    string s;
    std::stringstream numToChar;
    numToChar << numero;
    s = numToChar.str();
    unsigned int aux = 0;
    try {
        while (aux < s.size()){
            if (!isdigit(s[aux])){
                throw (erro());
            }
            aux++;
        }
    }
    catch (excecoes::erro){
        Mensagem("Erro 03: Nao e um numero.");
        FILE *arq = fopen("../ErrorFiles/errorlogs.dat", "a");
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        char output[30];
        strftime(output, 30,"%d/%m/%Y as %H:%M:%S", timeinfo);
        fprintf(arq, "Erro 03: Nao e um numero. Horario de ocorrencia: %s\n", output);
        fclose(arq);
        free(arq);
        return true;
    }
    return false;
}

template <class T> bool excecoes<T>::isWord(T palavra){
    string s;
    std::stringstream valueToChar;
    valueToChar << palavra;
    s = valueToChar.str();
    unsigned int aux = 0;
    try {
        while (aux < s.size()){
            if (!isalpha(s[aux])){
                throw (erro());
            }
            aux++;
        }
    }
    catch (excecoes::erro){
        Mensagem("Erro 04: Ha caracteres numericos na palavra.");
        FILE *arq = fopen("../ErrorFiles/errorlogs.dat", "a");
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        char output[30];
        strftime(output, 30,"%d/%m/%Y as %H:%M:%S", timeinfo);
        fprintf(arq, "Erro 04: Ha caracteres numericos na palavra. Horario de ocorrencia: %s\n", output);
        fclose(arq);
        free(arq);
        return true;
    }
    return false;
}

template <class T> bool excecoes<T>::isDate(T dia, T mes, T ano){
    std::stringstream strDia;
    std::stringstream strMes;
    std::stringstream strAno;
    string sDia, sMes, sAno;
    strDia << dia;
    strMes << mes;
    strAno << ano;
    sDia = strDia.str();
    sMes = strMes.str();
    sAno = strAno.str();
    unsigned int aux = 0;
    try{
        while (aux < sDia.size()){
            if (!isdigit(sDia[aux])){
                throw (erro());
            }
            aux++;
        }
        aux = 0;
        while (aux < sMes.size()){
            if (!isdigit(sMes[aux])){
                throw (erro());
            }
            aux++;
        }
        aux = 0;
        while (aux < sAno.size()){
            if (!isdigit(sAno[aux])){
                throw (erro());
            }
            aux++;
        }

        int iDia, iMes, iAno;
        strDia >> iDia;
        strMes >> iMes;
        strAno >> iAno;

        if ((iDia < 0 || iDia > 31) || (iMes < 0 || iMes > 12)){
            throw(erro());
        }
        if (iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11){
            if (iDia > 30){
                throw(erro());
            }
        }

        if (!(iAno % 4 == 0 && (iAno % 400 == 0 || iAno % 100 != 0))) {
            if (iMes == 2){
                if (iDia > 28){
                    throw (erro());
                }
            }
        }
        else{
            if (iMes == 2){
                if (iDia > 29){
                    throw (erro());
                }
            }
        }
    }
    catch(excecoes::erro){
        Mensagem("Erro 05: Data invalida.");
        FILE *arq = fopen("../ErrorFiles/errorlogs.dat", "a");
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        char output[30];
        strftime(output, 30,"%d/%m/%Y as %H:%M:%S", timeinfo);
        fprintf(arq, "Erro 05: Data invalida. Horario de ocorrencia: %s\n", output);
        fclose(arq);
        free(arq);
        return true;
    }
    return false;
}

template <class T> T* excecoes<T>::alocation(T* ptr){
	try{
		if (ptr == NULL){
			throw (erro());
		}
	}
	catch(excecoes::erro){
		Mensagem("Erro 06: Nao foi possivel alocar memoria.");
		FILE *arq = fopen("../ErrorFiles/errorlogs.dat", "a");
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        char output[30];
        strftime(output, 30,"%d/%m/%Y as %H:%M:%S", timeinfo);
        fprintf(arq, "Erro 06: Nao foi possivel alocar memoria. Horario de ocorrencia: %s\n", output);
        fclose(arq);
        free(arq);
        return NULL;
	}
	return ptr;
}
