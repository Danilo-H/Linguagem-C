//Validador de CPF, data de validade do cartão e cartão em linguagem C

//bibliotecas
#include <stdio.h>
#include <string.h>
#include <locale.h>

//indices funcoes
void validadeCartao();
void cpf();
void verificaCartao();

//funcao main
int main()
{

    //definindo a regiao
    setlocale(LC_ALL, "portuguese");

    //variaveis menu
    int opcao;

    //menu opcoes
    printf("O que deseja fazer?\n");
    printf("1 - Validar CPF\n");
    printf("2 - Data de validade do cartão\n");
    printf("3 - Validar cartao de crédito\n");
    printf("4 - Sair\n");
    printf("\n");
    scanf("%d", &opcao);
    printf("\n");

    while (opcao != 4)
    {

        switch (opcao)
        {
        case 1:
            //chamando a funcao cpf
            cpf();
            break;
        case 2:
            //chamando a funcao validadeCartao
            validadeCartao();
            break;
        case 3:
            //chamando a funcao verificaCartao
            verificaCartao();
            break;
        case 4:
            break;
        default:
            printf("\n opcao invalida \n");
            break;
        }
        printf("\nO que deseja fazer?\n");
        printf("1 - Validar CPF\n");
        printf("2 - Data de validade do cartão\n");
        printf("3 - Validar cartao de crédito\n");
        printf("4 - Sair\n");
        printf("\n");
        scanf("%d", &opcao);
        printf("\n");
    }
    return 0;
}
////////////////////////////////////////////////////////////
//FUNCOES
///////////////////////////////////////////////////////////
void validadeCartao()
{

    //variaveis
    int mesAtual, anoAtual, mesValidade, anoValidade;

    //lendo as datas
    printf("Informe o mês e ano atual:\n");
    printf("Mês:\n");
    scanf("%d", &mesAtual);
    printf("Ano:\n");
    scanf("%d", &anoAtual);
    printf("Informe o mês e ano da validade do cartão:\n");
    printf("Mês:\n");
    scanf("%d", &mesValidade);
    printf("Ano:\n");
    scanf("%d", &anoValidade);

    //verificando se o cartao esta vencido
    if (anoValidade < anoAtual)
    {
        printf("SEU CARTÃO ESTÁ VENCIDO!\n");
    }
    else if (anoValidade == anoAtual && mesValidade < mesAtual)
    {
        printf("SEU CARTÃO ESTÁ VENCIDO!\n");
    }
    else
    {
        printf("SEU CARTÃO ESTÁ DENTRO DA VALIDADE!\n");
    }
}
///////////////////////////////////////////////////////////
void cpf()
{

    //variaveis
    int vetCpf[12], resto1 = 0, resto2 = 0, verificado1, verificado2, i, j = 0, tam = 0, cont, resul = 0, estado;
    char numCpf[16];

    //lendo cpf
    printf("Digite seu CPF:\n");
    setbuf(stdin, 0);
    fgets(numCpf, sizeof(numCpf), stdin);
    numCpf[strlen(numCpf) - 1] = '\0';
    tam = strlen(numCpf);

    //transforma de char para inteiro(menos '.' e '-' caso haja)
    for (i = 0, j = 0; i < tam; i++)
    {
        if (numCpf[i] != '.' && numCpf[i] != '-')
        {
            vetCpf[j] = numCpf[i] - 48;
            j++;
        }
    }
    //validacao 1 dig
    for (i = 0, cont = 10; i < 9 && cont > 1; i++, cont--)
        resul += (vetCpf[i] * cont);

    //calculo1
    resto1 = resul % 11;

    if (resto1 == 0 || resto1 == 1)
        verificado1 = 0;
    else if (resto1 >= 2 && resto1 <= 10)
        verificado1 = 11 - resto1;

    resul = 0;
    //validacao 2 dig
    for (i = 0, cont = 11; i < 10 && cont > 1; i++, cont--)
        resul += (vetCpf[i] * cont);

    //calculo2
    resto2 = resul % 11;

    if (resto2 == 0 || resto2 == 1)
        verificado2 = 0;
    else if (resto2 >= 2 && resto2 <= 10)
        verificado2 = 11 - resto2;

    //verificando se os valores sao todos iguais no vetor(CPF invalido)
    for (i = 0; i < 10; i++)
        vetCpf[i++];

    if (vetCpf[0] == vetCpf[i++])
        printf("CPF inválido, números são todos iguais!\n\n");

    //verificando se o CPF eh valido ou nao
    else if (verificado1 == vetCpf[9] && verificado2 == vetCpf[10])
    {
        printf("CPF válido - ");

        //definindo o estado do cpf caso seja valido
        estado = vetCpf[8];
        switch (estado)
        {
        case 0:
            printf("Rio Grande do Sul\n\n");
            break;
        case 1:
            printf("Distrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul e Tocantins\n\n");
            break;
        case 2:
            printf("Amazonas, Pará, Rorâima, Amapá, Acre e Rondônia\n\n");
            break;
        case 3:
            printf("Ceará, Maranhão e Piauí\n\n");
            break;
        case 4:
            printf("Paraíba, Pernambuco, Alagoas e Rio Grande do Norte\n\n");
            break;
        case 5:
            printf("Bahia e Sergipe\n\n");
            break;
        case 6:
            printf("Minas Gerais\n\n");
            break;
        case 7:
            printf("Rio de Janeiro e Espírito Santo\n\n");
            break;
        case 8:
            printf("São Paulo\n\n");
            break;
        case 9:
            printf("Paraná e Santa Catarina\n\n");
            break;
        }
    }
    else
        printf("CPF inválido, digite um CPF válido!\n\n");
}
///////////////////////////////////////////////////////////////
void verificaCartao()
{

    //variaveis
    char cartao[21];
    int cartaoI[16], tam_cartao, i, j, d1, d2, total = 0;

    //lendo numeros do cartao
    printf("Digite o número do seu cartão:\n");
    setbuf(stdin, 0);
    fgets(cartao, sizeof(cartao), stdin);
    cartao[strlen(cartao) - 1] = '\0';
    tam_cartao = strlen(cartao);

    //tirando os espaços do meio e passando para inteiro
    for (i = 0, j = 0; i < tam_cartao; i++)
    {
        if (cartao[i] != ' ')
        {
            cartaoI[j] = cartao[i] - 48;
            j++;
        }
    }

    //calculo(multiplicando posit. pares e juntando os numeros com mais de 1 dig)
    for (i = 0; i < 16; i += 2)
    {
        cartaoI[i] = cartaoI[i] * 2;

        if (cartaoI[i] > 9)
        {
            d1 = (cartaoI[i] / 1) % 10;
            d2 = (cartaoI[i] / 10) % 10;
            cartaoI[i] = d2 + d1;
        }
    }

    //somando os numeros
    for (i = 0; i < 16; i++)
    {
        total = total + cartaoI[i];
    }

    //definindo se é valido ou nao, pelo resto
    if (total % 10 == 0)
        printf("Cartão válido!\n");
    else
        printf("Cartão inválido!\n");
}
/////////////////////////////////////////////////////////////