//Batalha entre chefes e heroi

#include <stdio.h>
#include <string.h>

//criando uma estrutura para as inf dos personagens(item 1)
typedef struct
{
    char nome[30];
    int hp;
    int forca;
    int defesa;
} personagem;

//funcao "imprime" (item 2)
void imprime(personagem chefes[], personagem heroi);
//funcao "fim" (item 4)
int fim(personagem chefes[], personagem heroi);

//funcao "main"
int main()
{
    //definindo variaveis
    personagem chefes[3];                     //vetor de chefes com 3 posicoes (item 3)
    personagem heroi = {"Goku", 100, 50, 20}; //var heroi com os seus devidos atributos (item 3)
    int i, acao_heroi, acao_chefe, ataca_chefe, escolhe_chefe_ataca, aux = 0, final = 0;

    //definindo valores iniciais do vetor de chefes como 0 (item 3)
    for (i = 0; i < 3; i++)
    {
        strcpy(chefes[i].nome, "NULL");
        chefes[i].hp = 0;
        chefes[i].forca = 0;
        chefes[i].defesa = 0;
    }

    //Instanciando os 3 chefes (item 3)
    strcpy(chefes[0].nome, "Majin Boo");
    chefes[0].hp = 50;
    chefes[0].forca = 30;
    chefes[0].defesa = 20;

    strcpy(chefes[1].nome, "Vejeta");
    chefes[1].hp = 60;
    chefes[1].forca = 35;
    chefes[1].defesa = 25;

    strcpy(chefes[2].nome, "Freeza");
    chefes[2].hp = 70;
    chefes[2].forca = 40;
    chefes[2].defesa = 30;
    ///////////////////////////////////////////////////////

    //troca de turnos(item 5)
    while (fim(chefes, heroi) != 1)
    {
        do
        {
            //heroi ataca
            printf("***HEROI VAI ATACAR***\n");
            printf("Defina a acao do heroi:\n");
            printf("1- usar item de cura;\n");
            printf("2- Escolher um chefe para atacar;\n");
            printf("3- Atacar todos os chefes;\n\n");
            scanf("%d", &acao_heroi);

            switch (acao_heroi)
            {
            case 1:
                aux += 1;
                if (aux < 3)
                {
                    heroi.hp = 100;
                    printf("Voce usou %d vez(es) a cura!\n", aux);
                    imprime(chefes, heroi);
                }
                else
                {
                    printf("\nVoce nao tem mais itens de cura!\n");
                    imprime(chefes, heroi);
                }
                break;
            case 2:
                printf("\nQuem voce quer atacar?\n");
                printf("1.Majin Boo\n");
                printf("2.Vejeta\n");
                printf("3.Freeza\n\n");
                scanf("%d", &ataca_chefe);

                switch (ataca_chefe)
                {
                case 1: //Magin Boo
                    chefes[0].hp = chefes[0].hp - (heroi.forca - chefes[0].defesa);
                    imprime(chefes, heroi);
                    fim(chefes, heroi);
                    break;
                case 2: //Vegeta
                    chefes[1].hp = chefes[1].hp - (heroi.forca - chefes[1].defesa);
                    imprime(chefes, heroi);
                    break;
                case 3: //Freeza
                    chefes[2].hp = chefes[2].hp - (heroi.forca - chefes[2].defesa);
                    imprime(chefes, heroi);
                    break;
                default:
                    printf("\nopcao invalida!\n\n");
                    break;
                }
                break;
            case 3:
                for (i = 0; i < 3; i++)
                {
                    if (chefes[i].hp != 0)
                    {
                        chefes[i].hp = chefes[i].hp - (heroi.forca - 15 - chefes[i].defesa);
                    }
                }
                imprime(chefes, heroi);
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
            }
        } while (acao_heroi > 3);
        do
        {
            //chefe ataca
            printf("\n***CHEFE VAI ATACAR***\n");
            printf("Defina o chefe que ira atacar:\n");
            printf("\n1.Majin Boo\n");
            printf("2.Vejeta\n");
            printf("3.Freeza\n\n");
            scanf("%d", &escolhe_chefe_ataca);

            switch (escolhe_chefe_ataca)
            {
            case 1: //Magin Boo
                printf("\nDefina a acao do Chefe:\n");
                printf("1- Ataque normal;\n");
                printf("2- Ataque enfurecido;\n\n");
                scanf("%d", &acao_chefe);

                switch (acao_chefe)
                {
                case 1:
                    heroi.hp = heroi.hp - (chefes[0].forca - heroi.defesa);
                    imprime(chefes, heroi);
                    break;
                case 2:
                    heroi.hp = heroi.hp - ((2 * chefes[0].forca) - heroi.defesa);
                    chefes[i].hp = chefes[0].hp / 2;
                    imprime(chefes, heroi);
                    break;
                default:
                    printf("Opcao invalida!\n");
                    break;
                }
                break;
            case 2: //Vegeta
                printf("\nDefina a acao do Chefe:\n");
                printf("1- Ataque normal;\n");
                printf("2- Ataque enfurecido;\n\n");
                scanf("%d", &acao_chefe);

                switch (acao_chefe)
                {
                case 1:
                    heroi.hp = heroi.hp - (chefes[1].forca - heroi.defesa);
                    imprime(chefes, heroi);
                    break;
                case 2:
                    heroi.hp = heroi.hp - ((2 * chefes[1].forca) - heroi.defesa);
                    chefes[i].hp = chefes[1].hp / 2;
                    imprime(chefes, heroi);
                    break;
                default:
                    printf("Opcao invalida!\n");
                    break;
                }
                break;
            case 3: //Freeza
                printf("\nDefina a acao do Chefe:\n");
                printf("1- Ataque normal;\n");
                printf("2- Ataque enfurecido;\n\n");
                scanf("%d", &acao_chefe);

                switch (acao_chefe)
                {
                case 1:
                    heroi.hp = heroi.hp - (chefes[2].forca - heroi.defesa);
                    imprime(chefes, heroi);
                    break;
                case 2:
                    heroi.hp = heroi.hp - ((2 * chefes[2].forca) - heroi.defesa);
                    chefes[i].hp = chefes[2].hp / 2;
                    imprime(chefes, heroi);
                    break;
                default:
                    printf("Opcao invalida!\n");
                    break;
                }
                break;
            default:
                printf("Opcao invalida!\n");
                break;
            }
        } while (escolhe_chefe_ataca > 3);
    }

    return 0;
}
//////////////////////////////////////////////////
//FUNCOES

//funcao "imprime" (item 2)
void imprime(personagem chefes[], personagem heroi)
{
    printf("\n");

    int i;
    for (i = 0; i < 3; i++)
    {
        printf("Chefe %d: %s - %d\n", i + 1, chefes[i].nome, chefes[i].hp);
    }
    printf("\n");
    printf("Heroi: %s - %d\n\n", heroi.nome, heroi.hp);
}

//funcao "fim" (item 4)
int fim(personagem chefes[], personagem heroi)
{
    if (heroi.hp <= 0)
    {
        printf("Os chefes (Majin Boo, Vejeta e Freeza) venceram!\n");
        return 1;
    }
    else if (chefes[0].hp <= 0 && chefes[1].hp <= 0 && chefes[2].hp <= 0)
    {
        printf("O heroi (Goku) venceu!\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
