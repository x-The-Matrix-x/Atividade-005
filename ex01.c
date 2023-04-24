/*Elabore um programa que receba AT� 25 medias e retorne
a quantidade de alunos reprovados, a quantidades de 
alunos aprovados e a menor media informada. 
Aprova��o media acima de 6.9
------------------
Relatorio da turma
------------------
Informe 1a nota:10 
Informe 2a nota:9
...
------------------
Media da turma: 8.7
Maior nota: 10
Menor nota: 1.5
Reprovados: 8
Aprovados: 10
------------------
    BSB - 2023
Alguns requisitos: 
- fun��o le_valida_media (dever� ser informada entre 0 e 10)    
- procedimento para cabe�alho
- procedimento para rodap�
- fun��o calcular_media (recebe como par�metro a 
quantidade de medias informadas e a soma das m�dias)
*/



#include <stdio.h>

float le_valida_media() {
    float media;
    do {
        printf("Ola! Por favor, informe a media do aluno (0 a 10): ");
        scanf("%f", &media);
    } while (media < 0 || media > 10);
    return media;
}

void cabecalho() {
    printf("------------------\n");
    printf("Relatorio da Turma\n");
    printf("------------------\n");
}

void rodape(float media_turma, float menor_media, int aprovados, int reprovados) {
    printf("------------------\n");
    printf("Media da turma: %.1f\n", media_turma);
    printf("Menor media: %.1f\n", menor_media);
    printf("Aprovados: %d\n", aprovados);
    printf("Reprovados: %d\n", reprovados);
    printf("------------------\n");
    printf("    BSB - 2023\n");
}

float calcular_media(int qtd_medias, float soma_medias) {
    return soma_medias / qtd_medias;
}

int main() {
    int qtd_medias = 0, aprovados = 0, reprovados = 0;
    float media, soma_medias = 0, menor_media = 10, media_turma, maior_media = 0;

    cabecalho();

    while (qtd_medias < 25) {
        media = le_valida_media();
        soma_medias += media;
        qtd_medias++;

        if (media < menor_media) {
            menor_media = media;
        }

        if (media > maior_media) {
            maior_media = media;
        }

        if (media >= 6.9) {
            aprovados++;
        } else {
            reprovados++;
        }

        printf("Agora informe a proxima media ou digite um valor negativo para encerrar: ");
        scanf("%f", &media);
        if (media < 0) {
            break;
        }
    }

    media_turma = calcular_media(qtd_medias, soma_medias);

    rodape(media_turma, menor_media, aprovados, reprovados);

    return 0;
}


/*
Esse programa funciona da seguinte forma: primeiramente, s�o declaradas as fun��es le_valida_media, 
cabecalho, rodape e calcular_media. Em seguida, � feita a declara��o das vari�veis utilizadas.

O procedimento cabecalho imprime na tela o cabe�alho do relat�rio. 
O procedimento rodape imprime na tela o rodap� do relat�rio, com as informa��es sobre a m�dia da turma, 
a menor m�dia, a quantidade de alunos aprovados e reprovados, e a identifica��o do ano e cidade.

A fun��o le_valida_media � respons�vel por receber a entrada do usu�rio e validar se a m�dia est� dentro do intervalo permitido (de 0 a 10).

A fun��o calcular_media recebe a quantidade de m�dias informadas e a soma das m�dias, e retorna a m�dia da turma.

No corpo do programa, � chamado o procedimento cabecalho, seguido de um la�o de repeti��o que 
solicita ao usu�rio a entrada das m�dias. A cada itera��o, a m�dia � lida atrav�s da fun��o le_valida_media, 
e � feita a valida��o das condi��es de aprova��o ou reprova��o.
*/
