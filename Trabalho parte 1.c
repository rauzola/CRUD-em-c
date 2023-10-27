#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcao;
    int num_registros = 0;
    char nomes[100][50];
    int idades[100];
    char telefones[100][15];
    char enderecos[100][100];

    do {
        system("cls"); // Limpa a tela no Windows

        printf("\n============================================\n");
        printf("|      Menu Principal                      |\n");
        printf("|==========================================|\n");
        printf("|    1. Adicionar um novo registro         |\n");
        printf("|    2. Listar todos os registros          |\n");
        printf("|    3. Sair do programa                   |\n");
        printf("|==========================================|\n");
        printf("|   Escolha uma opcao:                     |\n");
        printf("============================================\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // Adicionar um novo registro
                system("cls"); // Limpa a tela no Windows

                printf("\n==============================\n");
                printf("    Adicionar um novo registro\n");
                printf("==============================\n");
                printf("Digite o nome: ");
                scanf(" %[^\n]", nomes[num_registros]);
                printf("Digite a idade: ");
                while (scanf("%d", &idades[num_registros]) != 1) {
                    printf("Idade invalida. Digite novamente: ");
                    scanf("%*s"); // Limpa o buffer de entrada
                }
                printf("Digite o telefone: ");
                while (scanf("%14s", telefones[num_registros]) != 1) {
                    printf("Telefone invalido. Digite novamente: ");
                    scanf("%*s"); // Limpa o buffer de entrada
                }
                printf("Digite o endereco: ");
                scanf(" %[^\n]", enderecos[num_registros]);
                num_registros++;
                printf("Registro adicionado com sucesso!\n");
                break;

            case 2: // Listar todos os registros
                system("cls"); // Limpa a tela no Windows

                printf("\n==============================\n");
                printf("      Lista de Registros\n");
                printf("==============================\n");

                if (num_registros > 0) {
                    for (int i = 0; i < num_registros; i++) {
                        printf("\nRegistro %d:\n", i + 1);
                        printf("Nome: %s\n", nomes[i]);
                        printf("Idade: %d\n", idades[i]);
                        printf("Telefone: %s\n", telefones[i]);
                        printf("Endereco: %s\n");
                    }
                } else {
                    printf("Nenhum registro cadastrado ainda.\n");
                }
                break;

            case 3: // Sair do programa
                printf("\nEncerrando o programa. Obrigado!\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

        printf("\nPressione Enter para continuar...");
        while (getchar() != '\n'); // Aguarda o usuário pressionar Enter
        getchar(); // Limpa o Enter do buffer

    } while (opcao != 3);

    return 0;
}
