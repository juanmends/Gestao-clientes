//ALUNO: JUAN SILVA MENDES
//BCC - ESTRUTURA DE DADOS
#include <iostream>
using namespace std;

struct no_s {
    int cod;
    struct no_s* pr;
};

struct no_d {
    struct no_d* ant;
    int info;
    struct no_s* p;
    struct no_d* prox;
};

struct no_d* topo = NULL;
struct no_d* fim = NULL;

int clientes = 0;

void chegada_cliente() {
    struct no_d* novo = new no_d;
    clientes += 100;
    novo->info = clientes;
    novo->prox = NULL;
    novo->p = NULL;
    if (topo == NULL) {
        topo = novo;
        fim = novo;
        novo->ant = NULL;
    } else {
        fim->prox = novo;
        novo->ant = fim;
        fim = novo;
    }
}

void consumo_cliente() {
    struct no_d* aux = topo;
    struct no_s* novo = new no_s;
    int cod_cliente, cod_produto;
    cout << "DIGITE O CODIGO DO CLIENTE: ";
    cin >> cod_cliente;
    cout << "DIGITE O CODIGO DO PRODUTO: ";
    cin >> cod_produto;
    novo->cod = cod_produto;
    while (aux != NULL) {
        if(aux->info == cod_cliente) {
            if(aux->p == NULL) {
                novo->pr = NULL;
                aux->p = novo;
            } else {
                novo->pr = aux->p;
                aux->p = novo;
            }
            cout << "PEDIDO REALIZADO COM SUCESSO!\n";
        }
        aux = aux->prox;
    }
}

void saida_cliente() {
    struct no_d* aux = topo;
    struct no_s* libera;
    int cod_cliente;
    cout << "DIGITE O CODIGO DO CLIENTE: ";
    cin >> cod_cliente;
    while (aux != NULL) {
        if(aux->info == cod_cliente) {
            while(aux->p != NULL) {
                cout << aux->p->cod <<"\n";
                libera = aux->p;
                aux->p = aux->p->pr;
                delete libera;
            }
            if (aux==topo) {
                if(topo==fim) {
                    topo = NULL;
                    fim = NULL;
                }else {
                    aux->prox->ant = NULL;
                    topo = aux->prox;
                }
            } else if (aux==fim) {
                aux->ant->prox = NULL;
                fim = aux->ant;
            } else {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
            }
            cout << "CLIENTE NUMERO " << aux->info << " LIBERADO" << "\n";
            delete aux;
            aux = NULL;
        }else
            aux = aux->prox;
    }

}

int main() {

    int escolha;

    do {
        cout << "1 - CHEGADA DE CLIENTE / 2 - CONSUMO DE CLIENTE / 3 - SAIDA DE CLIENTE / 0 - FIM : ";
        cin >> escolha;

        if (escolha == 1)
            chegada_cliente();
        if (escolha == 2)
            consumo_cliente();
        if (escolha == 3)
            saida_cliente();

    } while(escolha != 0);

    return 0;
}