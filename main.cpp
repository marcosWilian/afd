#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
	FILE *f;
	f = fopen("dados.txt","rt"); // ABRE O ARQUIVO PARA LEITURA EM MODO TEXTO!

	int i; // VARIAVEL INDICE!
	
	char recebePalavra; //VARIAVEL QUE ARMAZENA CARACTER DO ARQUIVO DE TEXTO! (UM POR VEZ);
	
	char a[500];
	int indiceLinhas = 0;		
	int quantidadeCaracteres=1;
	int Linha[100];
	
	while (!feof(f)){	//NÃO FIM DO ARQUIVO!
		fscanf(f,"%c",&recebePalavra);//Lê o arquivo de texto
		a[i] = recebePalavra;  // adiciona em um vetor a palavra 
        i++; // incrmenta i em +1 para aumentar a posição do indice e ler a proxima letra
			
		if (!feof(f) == 1){ //NÃO FIM DO ARQUIVO = 1 , FIM DO ARQUIVO 0	
		/*ESSA PARTE DO CODIGO IRA VERIFICAR O FINAL DA LINHA! FOI NECESSARIO ADICIONAR UM CARACTER PARA IDENTIFICAÇÂO;*/
			if (recebePalavra == ';'){	
		 		Linha[indiceLinhas]= quantidadeCaracteres; // DEFINE EM UM VETOR ONDE É O ULTIMO CARACTER EM UMA LINHA!
	     		indiceLinhas++; // AUMENTA UMA LINHA			  	
				quantidadeCaracteres++;	 // AUMENTA CARACTER
			}
		}		
	quantidadeCaracteres++;	
	} 
	fclose(f);	
		
	char salvaM[10][3];
	char salvaI; // VARIAVEL ARMAZENA O CARACTER INICIAL;
	int achei;
	// ARMAZENA EM UMA MATRIZ OS VALORES DE TRANSIÇÃO PARA FACIL MODIFICAÇÂO
	// armazena estado inicial
	for (int i = 0; i < quantidadeCaracteres; i++ ){
		if (a[i] == '>'){
			salvaI = a[i+1];	 				
			}
		}	
	// armazena a transição
	for (int i = 0; i < quantidadeCaracteres; i++ ){
		if (a[i] == '~'){	
			 salvaM[achei][1] = a[i+1] ;
			 salvaM[achei][2]= a[i+3];
			 salvaM[achei][3]= a[i+5] ;
			achei++;	 				
			}
		}
	// ARMAZENA O ESTADO FINAL;
	char estadoFinal[10];
	achei = 0;	
	for (int i = 0; i < quantidadeCaracteres; i++ ){
		if (a[i] == '*'){	
			 estadoFinal[achei] = a[i+1];
			 achei++;	 				
			}
		}	

    char w[100];   //VETOR DE CARACTERES O AUTOMOTO SERÁ ARMAZENAD AQUI! 
    cout << "\nAFD - RECONHECEDOR DE NUMEROS DE SERIE\n\n";    
    cout << "Informe a palavra de entrada: \n";
    gets(w);
    
    i=0;
    
    char estado=salvaI;
    cout << estado;    
    
    while( i < strlen(w) ){
        for (int x = 0; x < indiceLinhas; x++ ){
        	if( estado == salvaM[x][1] && w[i] == salvaM[x][2]) {
            	estado= salvaM[x][3] ;   // PROXIMO ESTADO
		    	i++; 
			    cout << estado; // Mostra na TELA O ESTADO APÒS O PROCESSAMENTO DO AUTOMATO		   			
			} // if
		}    // for   
    } // while...
  	cout << "\n";
    if( i == strlen(w) && (estado == estadoFinal[0] || estadoFinal[1]) || estadoFinal[2] ||  estadoFinal[3]){     
        cout << w << " NUMERO DE SERIE VALIDO !";
    }
    else{
        cout << w << " NAO e um numero de serie valido !";
        if( i < strlen(w) ) {
            cout << "\n\n===> Por que nao processou todos os simbolos!";
        }
        else{
            cout << "\n\n===> Por que nao parou em um dos estados finais!";
        }
    } // não aceitou a palavra
    
    cout << "\n\n\n\n\n";
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
