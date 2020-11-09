struct Cliente
{
    int cod;
    char nome[255];
    float entradas, saidas;
};

Cliente * CriaCliente(int Cod, char Nome[], float Ent, float Said);

void Libera(Cliente* cliente);

void AcessoDados(Cliente* cliente);

int DevolvePerfil(Cliente* cliente);
