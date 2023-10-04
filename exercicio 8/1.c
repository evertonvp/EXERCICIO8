#include <stdio.h>

int main()
{
    char notas;
    int anos, repete, totalAvaliacoes = 0, totalOtimo = 0, totalBom = 0, totalRegular = 0, totalRuim = 0, totalPessimo = 0;
    float porcentagemOtimo, porcentagemBom, porcentagemRegular, porcentagemRuim, porcentagemPessimo, mediaIdadeRuim;
    int somaIdadesRuim = 0;
    int contadorRuim = 0;
    int maiorIdadePessimo = 0, maiorIdadeOtimo = 0, diferencaIdades;

    do
    {
        totalAvaliacoes++;

        do
        {
            fflush(stdin);
            printf("Digite sua idade: ");
            scanf("%d", &anos);

            if (anos < 0)
            {
                printf("\nOpcao invalidada, digite certo\n");
            }

        } while (anos < 0);

        do
        {
            fflush(stdin);
            printf("\nAgora, digite a nota dos cursos:\nA - para otimo.\nB - para bom\nC - para regular\nD - para ruim\nE - para pessimo\n");
            scanf(" %c", &notas); 

            if (notas != 'a' && notas != 'b' && notas != 'c' && notas != 'd' && notas != 'e')
            {
                printf("\nOpcao invalidada, digite certo\n");
            }

            if (notas == 'a')
            {
                totalOtimo++;
                if (anos > maiorIdadeOtimo)
                {
                    maiorIdadeOtimo = anos;
                }
            }
            else if (notas == 'b')
            {
                totalBom++;
            }
            else if (notas == 'c')
            {
                totalRegular++;
            }
            else if (notas == 'd')
            {
                totalRuim++;
                somaIdadesRuim += anos;
                contadorRuim++;
            }
            else if (notas == 'e')
            {
                totalPessimo++;
                if (anos > maiorIdadePessimo)
                {
                    maiorIdadePessimo = anos;
                }
            }

        } while (notas != 'a' && notas != 'b' && notas != 'c' && notas != 'd' && notas != 'e');

        printf("Deseja registrar uma nova avaliacao? 1 - Sim, -1 - nao\n");
        scanf("%d", &repete);
    } while (repete != -1);

    porcentagemOtimo = (float)totalOtimo / totalAvaliacoes * 100;
    porcentagemBom = (float)totalBom / totalAvaliacoes * 100;
    porcentagemRegular = (float)totalRegular / totalAvaliacoes * 100;
    porcentagemRuim = (float)totalRuim / totalAvaliacoes * 100;
    porcentagemPessimo = (float)totalPessimo / totalAvaliacoes * 100;

    mediaIdadeRuim = (float)somaIdadesRuim / contadorRuim;
    diferencaIdades = maiorIdadeOtimo - maiorIdadePessimo;

    printf("\nO total de notas otimas foi: %d\n", totalOtimo);
    printf("A porcentagem de notas otimas foi: %.2f%%\n", porcentagemOtimo);
    printf("A porcentagem de notas boas foi: %.2f%%\n", porcentagemBom);
    printf("A porcentagem de notas regulares foi: %.2f%%\n", porcentagemRegular);
    printf("A porcentagem de notas ruins foi: %.2f%%\n", porcentagemRuim);
    printf("A porcentagem de notas pessimas foi: %.2f%%\n", porcentagemPessimo);

    printf("A media de idade das respostas ruim foi: %.2f\n", mediaIdadeRuim);
    printf("A maior idade entre as respostas pessimo foi: %d\n", maiorIdadePessimo);
    printf("A diferenca de idades entre otimos e pessimos foi: %d\n", diferencaIdades);

    return 0;
}
