#include<bits/stdc++.h>
#include<string.h>
#include"cliente_Quest2.h"

using namespace std;
Cliente * CriaCliente(int Cod, char Nome[], float Ent, float Said)
{
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
    if (cliente == NULL)
    {
        cout << "Memória insuficiente!" << endl;
        exit(1);
    }

    cliente->cod        = Cod;
    strcpy(cliente->nome, Nome);
    cliente->entradas   = Ent;
    cliente->saidas     = Said;

    cout << "Cliente Criado com Sucesso!" << endl;
    return cliente;
}

void Libera(Cliente* cliente)
{
    free(cliente);
    cout << "Cliente liberado da memoria com sucesso!" << endl;
}

void AcessoDados(Cliente* cliente)
{
    cout << "Cod.: " << cliente->cod << endl;
    cout << "Nome: " << cliente->nome << endl;
    cout << "Saldo: " << cliente->entradas - cliente->saidas << endl;
}

int DevolvePerfil(Cliente* cliente)
{
    int situacao = 0;
    float saldo = cliente->entradas - cliente->saidas;

    if(saldo > 2000)
        situacao = 1;
    else
    if((saldo >= -1000) and (saldo <= 1000))
        situacao = 2;
        situacao = 2;

    return situacao;
}
