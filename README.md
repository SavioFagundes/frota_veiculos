# frota_veiculos

Projeto em linguagem C para controle de frota de veículos.

---

## 🧾 Descrição

Este sistema permite o cadastro, controle e monitoramento de uma frota de veículos conforme os requisitos de uma prova ou atividade acadêmica. Ele foi implementado em **C**, utilizando `struct`, vetores, funções, laços e decisões, sem uso de ponteiros avançados ou arquivos externos.

---

## ✅ Funcionalidades

- Cadastro de veículos (placa, modelo, estado inicial)  
- Listagem de todos os veículos cadastrados  
- Busca de veículo por placa  
- Registro de saída para viagem (mudança de estado para “Em uso”)  
- Registro de retorno da viagem (acumula km, incrementa número de viagens, estado volta para “Disponível”)  
- Envio de veículo para manutenção (mudança de estado para “Em manutenção”)  
- Retorno da manutenção (mudança de estado para “Disponível”)  
- Relatório final contendo:  
  - Quantidade de veículos por estado  
  - Veículo com mais viagens  
  - Veículo com maior quilometragem  
  - Média de km por viagem  

---

## 🛠 Tecnologias Utilizadas

- Linguagem: **C**  
- Compilador: GCC (ou equivalente compatível com C padrão)  
- Estrutura de dados: `struct`  
- Armazenamento em memória via vetores  
- Interface de console: `printf`, `scanf`

---

## 🚀 Como rodar o projeto

1. Faça o clone do repositório:  
   ```bash
   git clone https://github.com/SavioFagundes/frota_veiculos.git
   cd frota_veiculos
   ```
2. Compile o código:
```
gcc index.c -o frota_veiculos
```

Execute o programa:
```
./frota_veiculos
```
🤝 Contribuições

Contribuições são bem-vindas! Para sugerir melhorias ou reportar bugs, abra uma issue ou envie um pull request no repositório original.
