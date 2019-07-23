#include <iostream>
#include <fstream>
#include <jagpdf/api.h>
#include <cstdlib>
#include <clocale>

using namespace std;
using namespace jag;

int main(){
    setlocale(LC_ALL, "");
    char op = '0';
    cout << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n";
    cout << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#     GERENCIAMENTO DE ERROS      #-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n";
    cout << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n\n";
	do{
        cout << "################################ Escolha uma das opções: #################################\n";
        cout << "------------------------------------------------------------------------------------------\n";
        cout << "(1) - Ler log de erros.\n";
        cout << "(2) - Gerar relatório de erros, em formato PDF.\n";
        cout << "(0) - Encerrar programa.\n";
        cout << "------------------------------------------------------------------------------------------\n";
        cout << "Opção: ";
        cin >> op;
        fflush(stdin);
        if (op == '1'){
            cout << "\nO arquivo de logs de erro será exibido abaixo: \n\n";
            cout << "-------------------------------------- errorlogs.dat -------------------------------------\n";
            cout << "------------------------------------------------------------------------------------------\n";
            FILE *arq1 = fopen("../ErrorFiles/errorlogs.dat", "r");
            char c1;
            while((c1=getc(arq1)) != EOF){
                cout << c1;
            }
            fclose(arq1);
            free(arq1);
            cout << "------------------------------------------------------------------------------------------\n";
            cout << "\nArquivo de logs exibido com sucesso!\n\n";
        }
        else{
            if (op == '2'){
                cout << "\nGerando relatório de erros...\n";
                FILE *arq = fopen("../ErrorFiles/errorlogs.dat", "r");
                char c, linha[100];
                int i=0, t=850, j=0, k=0;
                while (k < 100){
                    linha[k] = '\0';
                    k++;
                }
                pdf::Document doc(pdf::create_file("../ErrorFiles/ErrorLogs.pdf"));
                doc.page_start(597.6, 848.68);
                t-=40;
                doc.page().canvas().text_start(50,t);
                doc.page().canvas().text("RELATORIO DE ERROS");
                doc.page().canvas().text_translate_line(0,-15);
                doc.page().canvas().text_end();
                t-=20;
                while((c=getc(arq)) != EOF){
                    linha[i]=c;
                    if(linha[i]=='\n'){
                        linha[i]=' ';
                        if(t!=0){
                            t-=20;
                            doc.page().canvas().text_start(50,t);
                            doc.page().canvas().text(linha);
                            doc.page().canvas().text_translate_line(0,-15);
                            doc.page().canvas().text_end();
                            while(j!=i){
                                linha[j]=' ';
                                j++;
                            }
                            i=-1;j=0;
                        }
                    }
                    i++;
                }
                doc.page_end();
                doc.finalize();
                fclose(arq);
                cout << "Relatório de erros gerado com sucesso!\n\n";
            }
            else {
                if (op == '0'){
                    cout << "Encerrando o programa...\n";
                }
                else  cout << "Opção Inválida! Tente novamente.\n\n";
            }
        }
    } while (op != '0');
	return 0;
}
