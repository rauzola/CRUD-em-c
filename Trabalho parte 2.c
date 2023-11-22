#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("|    3. Atualizar um registro existente    |\n");
        printf("|    4. Excluir um registro existente      |\n");
        printf("|    5. Sair do programa                   |\n");
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
                        printf("Endereco: %s\n", enderecos[i]);
                    }
                } else {
                    printf("Nenhum registro cadastrado ainda.\n");
                }
                break;

            case 3: // Atualizar um registro existente
                system("cls"); // Limpa a tela no Windows

                printf("\n==============================\n");
                printf("   Atualizar um registro\n");
                printf("==============================\n");

                int id_para_atualizar;
                printf("Digite o ID do registro a ser atualizado: ");
                scanf("%d", &id_para_atualizar);

                if (id_para_atualizar >= 1 && id_para_atualizar <= num_registros) {
                    printf("Digite o novo nome: ");
                    scanf(" %[^\n]", nomes[id_para_atualizar - 1]);
                    printf("Digite a nova idade: ");
                    while (scanf("%d", &idades[id_para_atualizar - 1]) != 1) {
                        printf("Idade inválida. Digite novamente: ");
                        scanf("%*s"); // Limpa o buffer de entrada
                    }
                    printf("Digite o novo telefone: ");
                    while (scanf("%14s", telefones[id_para_atualizar - 1]) != 1) {
                        printf("Telefone inválido. Digite novamente: ");
                        scanf("%*s"); // Limpa o buffer de entrada
                    }
                    printf("Digite o novo endereco: ");
                    scanf(" %[^\n]", enderecos[id_para_atualizar - 1]);
                    printf("Registro atualizado com sucesso!\n");
                } else {
                    printf("ID de registro inválido.\n");
                }

                break;

            case 4: // Excluir um registro existente
                system("cls"); // Limpa a tela no Windows

                printf("\n==============================\n");
                printf("   Excluir um registro\n");
                printf("==============================\n");

                int id_para_excluir;
                printf("Digite o ID do registro a ser excluído: ");
                scanf("%d", &id_para_excluir);

                if (id_para_excluir >= 1 && id_para_excluir <= num_registros) {
                    // Desloca os registros subsequentes para preencher o espaço vago
                    for (int i = id_para_excluir - 1; i < num_registros - 1; i++) {
                        strcpy(nomes[i], nomes[i + 1]);
                        idades[i] = idades[i + 1];
                        strcpy(telefones[i], telefones[i + 1]);
                        strcpy(enderecos[i], enderecos[i + 1]);
                    }
                    num_registros--;
                    printf("Registro excluído com sucesso!\n");
                } else {
                    printf("ID de registro inválido.\n");
                }

                break;

            case 5: // Sair do programa
                printf("\nEncerrando o programa. Obrigado!\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

        printf("\nPressione Enter para continuar...");
        while (getchar() != '\n'); // Aguarda o usuário pressionar Enter
        getchar(); // Limpa o Enter do buffer

    } while (opcao != 5);

    return 0;
}