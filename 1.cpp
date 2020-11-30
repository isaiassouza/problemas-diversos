#include <bits/stdc++.h>
#define MAX 5

using namespace std;
int lista[MAX];
int fim;

bool vazia()
{
	if(fim == 0)
		return true;

	return false;
}

void inserir(int valor){
	if(fim == MAX) 
		cout << "Nao inseriu " << valor << ", lista cheia" << endl;
	 else 
	 {
		lista[fim] = valor; 
		fim++; 
		cout << "Inserido " << valor << " OK" << endl;
	}
}

void remover(int pos){
	int i;
	if(!vazia())
	{ 
		if(pos > fim-1)
			cout << "Posicao nao e valida (" << pos <<")" << endl;
		else 
		{
			cout << "Removido elemento " << lista[pos] << " da posicao (" << pos << ")" << endl;
			for(i= pos; i < fim; i++)
				lista[i]=lista[i+1];
				
			fim--;
		}
	} 
	else 
		cout << "Lista vazia, nao ha o que remover" << endl;
	
}

void imprimir()
{
	if(not vazia())
	{ 
		for(int i = 0; i < fim; i++)
			cout << lista[i] << ' ';
		
		cout << endl;
	} 
	else 
		cout << "Lista Vazia, nao ha o que imprimir!" << endl;
}

void ordenar()
{
	if(not vazia())
	{	
		cout << "Lista antes de ordernar:" << endl;
		for(int i = 0; i < fim; i++)
			cout << lista[i] << ' ';
		cout << endl;
		
		int aux;
	    for (int i = 0; i < fim - 1; i++) 
		{
	        for (int j = 0; j < fim - i - 1; j++) 
			{
	            if (lista[j] > lista[j + 1]) 
				{
	                aux          = lista[j];
	                lista[j]     = lista[j + 1];
	                lista[j + 1] = aux;
	            }
	        }
	    }
		
		cout << "Lista depois da ordernação:" << endl;
		for(int i = 0; i < fim; i++)
			cout << lista[i] << ' ';
		cout << endl;	
	}
	else
		cout << "Lista Vazia, não há o que ordenar!" << endl;	
	
}

int main(){
	int op, x, pos; 
   	fim = 0;
   	do
	{
		cout << endl;
		cout << "Escolha a operacao desejada" << endl;
		cout << "1 - Inserir" << endl;
		cout << "2 - Remover" << endl;
		cout << "3 - Imprimir" << endl;
		cout << "4 - Ordenar" << endl;
		cout << "5 - Sair" << endl;
		cout << endl;
		
		cin >> op;
		
		switch(op)
		{
			case 1:
			cout << "Digite o numero a ser inserido na lista: ";
			cin >> x;
			inserir(x);		
			break;
			
			case 2:
			cout << "Digite a posicao a ser removida da lista: ";
			cin >> pos;
			remover(pos);
			break;
			
			case 3:
			cout << "Imprimindo a lista..." << endl;
			imprimir();
			break;
			
			case 4:
			ordenar();
			break;
			
			case 5:
			cout << "Saindo.. Volte Sempre" << endl;
			break;
			
			default:
			cout << "Opcao escolhida invalida!" << endl; 
			break;
		}
	}
	while(op != 5);

	imprimir(); //LISTA VAZIA
	remover(1); //POSICAO INVALIDA - LISTA VAZIA
	inserir(1);	//INSERIDO ELEMENTO 1
	inserir(6);	//INSERIDO ELEMENTO 6
	inserir(8);	//INSERIDO ELEMENTO 8
	inserir(7);	//A LISTA ESTÁ CHEIA
	imprimir(); //(1,6,8)
	remover(3);	//ERRO - POSICAO INVALIDA
	remover(1);	//REMOVIDO ELEMENTO 6
	imprimir();	//(1,8)
	inserir(12);//OK
	inserir(15);//CHEIA
	imprimir(); //(1,8,12)

	return 0;
}



