#include<stdio.h>
typedef struct {
char code_A[10];
char lib_A[50];
float Prix;
}ARTICLE;
struct ligne_ticket {
    char code [10];
    int quant_t;
}ligne;
typedef struct {
int jj;
int mm;
int aa;
}date;
struct ticket{
char code[10];
date d;
};
date saisie_d()
{
    date d;
    printf("donner la date:");
    scanf("%d %d %d",d.jj,d.mm,d.aa);
}
void saisie_Article(ARTICLE *ART,int *nb_art)
{ARTICLE A;
printf("donnner code\n");
scanf("%s",A.code_A);
printf("donnner libellé\n");
scanf("%s",A.lib_A);
printf("donnner prix\n");
scanf("%f",A.Prix);
ART[*nb_art]=A;
(*nb_art)++;

}
void affiche(ARTICLE *A,int nb_art)
{
    for(int i=0;i<=nb_art;i++){
printf("code %s \n",A->code_A);
printf("libellé %s \n",A->lib_A);
printf("prix %f \n",A->Prix);
}
}
void Chercher_article_lib(ARTICLE *A, int nb_art, char *libelle) {
    int i, trouve = 0;

    for (i = 0; i < nb_art; i++) {
        if (strcmp(A[i].lib_A, libelle) == 0) {
            printf("Libellé : %s\n", A[i].lib_A);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun article trouvé pour le libellé \"%s\"\n", libelle);
    }
}
void Chercher_article_code(ARTICLE *A, int nb_art, char *code) {
    int i, trouve = 0;

    for (i = 0; i < nb_art; i++) {
        if (strcmp(A[i].code_A, code) == 0) {
            printf("Code : %s\n", A[i].code_A);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun article trouvé pour le code \"%s\"\n", code);
    }
}
void saisie_ticket(struct ticket *t, ARTICLE *A, int nb_art) {
    int i, trouve = 0;
    printf("Saisir le code du ticket : ");
    scanf("%s", t->code);
    t->d = saisie_d();
    do {
        printf("Saisir le code de l'article : ");
        scanf("%s", ligne.code);
        for (i = 0; i < nb_art; i++) {
            if (strcmp(A[i].code_A, ligne.code) == 0) {
                printf("Saisir la quantité : ");
                scanf("%d", &ligne.quant_t);
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            printf("Aucun article trouvé pour le code \"%s\"\n", ligne.code);
        }
    } while (!trouve);
    void ajouter_ticket(struct ticket *tickets, int *nb_tickets, ARTICLE *A, int nb_art) {
    struct ticket t;
    saisie_ticket(&t, A, nb_art);
    tickets[*nb_tickets] = t;
    (*nb_tickets)++;

void main()
{
    ARTICLE *A;
    int nb_art=0;
    int choix;
    char libelle[50],code[10];
    printf("1-Ajouter des articles:\n");
    printf("2-Afficher tous les articles:\n");
    printf("3-Afficher Articles par libellé:\n");
    printf("4-Ajouter des tickets:\n");
    printf("5-Afficher tickets par code:\n");
    printf("6-Calcler le chiffre d'affaires d'un mois donné:\n");
    printf("7-Afficher les articles tirés par code:\n");
    printf("8-Quitter le programme:\n");
    do{
    printf("donner votre choix:");
    scanf("%d",&choix);
    switch(choix)
    {
    case 1:
         {saisie_Article(&A,&nb_art);
          break;}
         case 2:
        {affiche(&A,&nb_art);
        break;}
        case 3:
            {printf("Saisir le libellé de l'article : ");
        scanf("%s", libelle);
        Chercher_article_lib(A, nb_art, libelle);
            printf("Saisir le code de l'article : ");
        scanf("%s", code);
        Chercher_article_code(A, nb_art, code);

        }
         break;
         case 4://{saisie_ticket
         break;
         case 5:
         break;
         case 6:
         break;
         case 7:
          break;
         case 8:
             break;
             default:
             printf("choix invalide");
         }

       }while(choix!=9);
}


