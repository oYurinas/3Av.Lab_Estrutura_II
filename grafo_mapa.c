#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Cidade para representar os vértices do grafo
struct Cidade {
    char nome[50]; 
};

typedef struct Cidade Cidade;

// Definição da estrutura Node para representar as arestas do grafo
struct Node {
    int cidade_id; // ID da cidade conectada
    struct Node* prox; // Próximo nó na lista de adjacência
};

typedef struct Node Node;

Cidade cidades[5]; 
Node* grafo[5];   // Grafo representando as conexões entre as cidades

// Função para imprimir o mapa
void imprimirMapa() {
    for (int i = 0; i < 5; i++) {
        printf("Cidade: %s -> Conectada a: ", cidades[i].nome); // Imprime o nome da cidade
        Node* atual = grafo[i];
        while (atual != NULL) {
            printf("%s ", cidades[atual->cidade_id].nome); // Imprime as cidades conectadas
            atual = atual->prox; // Move para o próximo nó na lista de adjacência
        }
        printf("\n");
    }
}

int main() {
    // Inicializar as cidades do Rio Grande do Norte
    strcpy(cidades[0].nome, "Natal");
    strcpy(cidades[1].nome, "Mossoro");
    strcpy(cidades[2].nome, "Parnamirim");
    strcpy(cidades[3].nome, "Caico");
    strcpy(cidades[4].nome, "Currais Novos");

    // Inicializar o grafo
    for (int i = 0; i < 5; i++) {
        grafo[i] = NULL; // Inicializa a lista de adjacência de cada cidade
    }

    // Definir as conexões entre as cidades diretamente no main
    // Grafo[0] é a cidade de Natal, que está conectada a Mossoró (cidade 1)
    grafo[0] = (Node*)malloc(sizeof(Node));
    grafo[0]->cidade_id = 1;
    grafo[0]->prox = NULL;

    // Grafo[1] é a cidade de Mossoró, que está conectada a Parnamirim (cidade 2)
    grafo[1] = (Node*)malloc(sizeof(Node));
    grafo[1]->cidade_id = 2;
    grafo[1]->prox = NULL;

    // Grafo[2] é a cidade de Parnamirim, que está conectada a Caicó (cidade 3)
    grafo[2] = (Node*)malloc(sizeof(Node));
    grafo[2]->cidade_id = 3;
    grafo[2]->prox = NULL;

    // Grafo[3] é a cidade de Caicó, que está conectada a Currais Novos (cidade 4)
    grafo[3] = (Node*)malloc(sizeof(Node));
    grafo[3]->cidade_id = 4;
    grafo[3]->prox = NULL;

    // Grafo[4] é a cidade de Currais Novos, que não possui conexões neste exemplo
    grafo[4] = NULL;

    // Imprimir o mapa
    imprimirMapa();

    return 0;
}
