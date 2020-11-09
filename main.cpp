#include<bits/stdc++.h>
#include"cliente_Quest2.h"

using namespace std;

int main()
{
    int x, perfil, codcli;
    char nomecli[255];
    float entcli, saicli;
    Cliente* clienteatual;
    clienteatual = NULL;

    cout << setprecision(2) << fixed;
    do
    {
        cout << endl << "Escolha uma opcao abaixo: " << endl;
        cout << " 1 - Criar Cliente. " << endl;
        cout << " 2 - Libera Cliente. " << endl;
        cout << " 3 - Acesso Dados. " << endl;
        cout << " 4 - Devolve Perfil. " << endl;
        cout << " 5 - Sair. " << endl;
        cin >> x;
        cout << endl;
        switch(x)
        {
            case 1:
            if(clienteatual != NULL)
                cout << "Ja existe um cliente sendo trabalhado, libere este da memoria para trabalhar com outro." << endl;
            else
            {
                cout << "Opcao 1 Escolhida(1 - Criar Cliente)." << endl;
                cout << "Insira o codigo do cliente: " << endl;
                cin >> codcli;
                cout << "Insira o nome do cliente: " << endl;
                scanf(" %[^\n]", nomecli);
                cout << "Insira a entrada mensal do cliente: " << endl;
                cin >> entcli;
                cout << "Insira a saida mensal do cliente: " << endl;
                cin >> saicli;

                clienteatual = CriaCliente(codcli, nomecli, entcli, saicli);
            }
            break;

            case 2:
            cout << "Opcao 2 Escolhida(2 - Libera Cliente)" << endl;
            Libera(clienteatual);
            clienteatual = NULL;
            break;

            case 3:
            cout << "Opcao 3 Escolhida(3 - Acesso Dados)" << endl;

            if(clienteatual != NULL)
                AcessoDados(clienteatual);
            else
                cout << "Cliente nao foi criado." << endl;
            break;

            case 4:
            cout << "Opcao 4 Escolhida(4 - Devolve Perfil)" << endl;
            if(clienteatual != NULL)
            {
                perfil = DevolvePerfil(clienteatual);
                switch(perfil)
                {
                    case 1:
                    cout << "Perfil - Investimentos disponiveis = saldo acima de 2000.00 ." << endl;
                    break;

                    case 2:
                    cout << "Perfil - Emprestimos disponiveis = saldo entre -1000.00 e 1000.00 ." << endl;
                    break;

                    default:
                    cout << "Perfil desconhecido." << endl;
                    break;
                }
            }
            else
                cout << "Cliente nao foi criado." << endl;

            break;

            case 5:
            cout << "Opcao 5 Escolhida(5 - Sair)" << endl;
            cout << "Obrigado por nos visitar, volte quando quiser!" << endl;
            return 0;
            break;

            default:
            cout << "Opcao Invalida!" << endl;
            break;
        }
    }
    while(x != 5);

}

