#include <stdio.h>
#include <string.h>

#define MAX 50

#define DISPONIVEL 1
#define EM_USO 2
#define MANUTENCAO 3

typedef struct {
    char placa[8];        
    char modelo[50];      
    int estado;           
    int viagens;          
    float km_total;       
} Veiculo;

int buscarVeiculo(Veiculo f[], int total, char placa[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(f[i].placa, placa) == 0) {
            return i;
        }
    }
    return -1;
}

void exibirVeiculo(Veiculo v) {
    printf("\n==============================\n");
    printf("Placa: %s\n", v.placa);
    printf("Modelo: %s\n", v.modelo);

    printf("Estado: ");
    if (v.estado == DISPONIVEL) printf("Disponível\n");
    else if (v.estado == EM_USO) printf("Em uso\n");
    else printf("Em manutenção\n");

    printf("Viagens realizadas: %d\n", v.viagens);
    printf("Quilometragem total: %.2f km\n", v.km_total);
    printf("==============================\n");
}

void cadastrarVeiculo(Veiculo f[], int *total) {
    if (*total >= MAX) {
        printf("\nERRO: Limite máximo de veículos atingido.\n");
        return;
    }

    Veiculo n;

    printf("\nDigite a placa (ex: ABC1234): ");
    scanf("%s", n.placa);

    if (buscarVeiculo(f, *total, n.placa) != -1) {
        printf("\nERRO: Placa já cadastrada.\n");
        return;
    }

    printf("Digite o modelo: ");
    scanf(" %[^\n]s", n.modelo);

    n.estado = DISPONIVEL;
    n.viagens = 0;
    n.km_total = 0;

    f[*total] = n;
    (*total)++;

    printf("\nVeículo cadastrado com sucesso!\n");
}

void listarVeiculos(Veiculo f[], int total) {
    if (total == 0) {
        printf("\nNenhum veículo cadastrado.\n");
        return;
    }

    for (int i = 0; i < total; i++)
        exibirVeiculo(f[i]);
}

void buscarPorPlaca(Veiculo f[], int total) {
    char placa[8];
    printf("\nDigite a placa: ");
    scanf("%s", placa);

    int idx = buscarVeiculo(f, total, placa);

    if (idx == -1)
        printf("\nVeículo não encontrado.\n");
    else
        exibirVeiculo(f[idx]);
}

void registrarSaida(Veiculo f[], int total) {
    char placa[8];
    printf("\nPlaca para saída: ");
    scanf("%s", placa);

    int idx = buscarVeiculo(f, total, placa);
    if (idx == -1) {
        printf("\nVeículo não encontrado.\n");
        return;
    }

    if (f[idx].estado != DISPONIVEL) {
        printf("\nERRO: Veículo não está disponível.\n");
        return;
    }

    f[idx].estado = EM_USO;
    printf("\nSaída registrada com sucesso!\n");
}

void registrarRetorno(Veiculo f[], int total) {
    char placa[8];
    float km;

    printf("\nPlaca para retorno: ");
    scanf("%s", placa);

    int idx = buscarVeiculo(f, total, placa);
    if (idx == -1) {
        printf("\nVeículo não encontrado.\n");
        return;
    }

    if (f[idx].estado != EM_USO) {
        printf("\nERRO: Esse veículo não está em uso.\n");
        return;
    }

    printf("KM percorridos: ");
    scanf("%f", &km);

    f[idx].km_total += km;
    f[idx].viagens++;
    f[idx].estado = DISPONIVEL;

    printf("\nRetorno registrado!\n");
}

void enviarManutencao(Veiculo f[], int total) {
    char placa[8];
    printf("\nPlaca para enviar à manutenção: ");
    scanf("%s", placa);

    int idx = buscarVeiculo(f, total, placa);
    if (idx == -1) {
        printf("\nVeículo não encontrado.\n");
        return;
    }

    if (f[idx].estado == MANUTENCAO) {
        printf("\nERRO: Veículo já está em manutenção.\n");
        return;
    }

    f[idx].estado = MANUTENCAO;
    printf("\nVeículo agora está em manutenção.\n");
}

void retornarManutencao(Veiculo f[], int total) {
    char placa[8];
    printf("\nPlaca para retornar da manutenção: ");
    scanf("%s", placa);

    int idx = buscarVeiculo(f, total, placa);
    if (idx == -1) {
        printf("\nVeículo não encontrado.\n");
        return;
    }

    if (f[idx].estado != MANUTENCAO) {
        printf("\nERRO: Veículo não está em manutenção.\n");
        return;
    }

    f[idx].estado = DISPONIVEL;
    printf("\nVeículo agora está disponível!\n");
}

void relatorioFinal(Veiculo f[], int total) {
    int qtdDisp = 0, qtdUso = 0, qtdMan = 0;
    int maisViagens = -1, idxViagens = -1;
    float maiorKm = -1, somaKm = 0;
    int somaViagens = 0, idxKm = -1;

    for (int i = 0; i < total; i++) {

        if (f[i].estado == DISPONIVEL) qtdDisp++;
        else if (f[i].estado == EM_USO) qtdUso++;
        else qtdMan++;

        if (f[i].viagens > maisViagens) {
            maisViagens = f[i].viagens;
            idxViagens = i;
        }

        if (f[i].km_total > maiorKm) {
            maiorKm = f[i].km_total;
            idxKm = i;
        }

        somaKm += f[i].km_total;
        somaViagens += f[i].viagens;
    }

    printf("\n========== RELATÓRIO FINAL ==========\n");

    printf("\nVeículos disponíveis: %d", qtdDisp);
    printf("\nVeículos em uso: %d", qtdUso);
    printf("\nVeículos em manutenção: %d\n", qtdMan);

    if (idxViagens != -1) {
        printf("\nVeículo com mais viagens (%d): %s - %s",
               f[idxViagens].viagens, f[idxViagens].placa, f[idxViagens].modelo);
    }

    if (idxKm != -1) {
        printf("\nVeículo com maior KM (%.2f): %s - %s",
               f[idxKm].km_total, f[idxKm].placa, f[idxKm].modelo);
    }

    float media = (somaViagens == 0) ? 0 : somaKm / somaViagens;
    printf("\nMédia geral de KM por viagem: %.2f km", media);

    printf("\n=====================================\n");
}

int main() {
    Veiculo frota[MAX];
    int total = 0;
    int op;

    do {
        printf("\n===== MENU DE OPERAÇÕES =====\n");
        printf("1 - Cadastrar veículo\n");
        printf("2 - Listar veículos\n");
        printf("3 - Buscar por placa\n");
        printf("4 - Registrar saída\n");
        printf("5 - Registrar retorno\n");
        printf("6 - Enviar para manutenção\n");
        printf("7 - Retornar da manutenção\n");
        printf("8 - Encerrar e gerar relatório\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1: cadastrarVeiculo(frota, &total); break;
            case 2: listarVeiculos(frota, total); break;
            case 3: buscarPorPlaca(frota, total); break;
            case 4: registrarSaida(frota, total); break;
            case 5: registrarRetorno(frota, total); break;
            case 6: enviarManutencao(frota, total); break;
            case 7: retornarManutencao(frota, total); break;
            case 8: relatorioFinal(frota, total); break;
            default: printf("\nOpção inválida!\n");
        }

    } while (op != 8);

    return 0;
}