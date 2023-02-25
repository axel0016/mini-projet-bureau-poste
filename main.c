#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct ELEMENT ELEMENT ;
struct ELEMENT{
    int NOMBRE;
    ELEMENT *SUIVANT;
};

ELEMENT *N = NULL;
ELEMENT *A = NULL;
ELEMENT *B = NULL;
ELEMENT *C = NULL;
int p=1,client=0;
int *i=&p;
int *t=&client;
void AFFMenu()
{
    printf("                                                                                  LE MENU:\n");
    printf("(°~°)_____:)------------------------------------------------------------------------------------------------------------------------------------------------(:_____(°~°)\n");
    printf("            |                                               |       N:  nouveau client                           |                                          |\n");
    printf("            |                                               |       A:  appel client au niveau employe A         |                                          |\n");
    printf("            |                                               |       B:  appel client au niveau employe B         |                                          |\n");
    printf("            |                                               |       C:  appel client au niveau employe C         |                                          |\n");
    printf("            |                                               |       X:  Fin de session                           |                                          |\n");
    printf("(°~°)_____:)------------------------------------------------------------------------------------------------------------------------------------------------(:_____(°~°)\n");
}

void AJOUTE(ELEMENT **tete, int nmb){
    ELEMENT *New;
    New= malloc(sizeof(ELEMENT));
    New->NOMBRE = nmb;
    ELEMENT *p = *tete;

    if(*tete == NULL){
    New->SUIVANT = NULL;
    *tete = New;
    }
    else{
        while(p->SUIVANT != NULL){
        p = p->SUIVANT;
        }
    New->SUIVANT = NULL;
    p->SUIVANT = New;
    }

}


ELEMENT* sup(ELEMENT *supell)
{
    if(supell != NULL)
    {
        ELEMENT* bye = supell->SUIVANT;
        free(supell);
        return bye;
    }
    else
    {
        return NULL;
    }
}
void afflist(ELEMENT *aff){
    ELEMENT *VER=aff;
    while(aff!=NULL){
        printf("%d => ",aff->NOMBRE);
        aff = aff->SUIVANT;
    }
    if(VER == NULL){printf("           ----- n'a traiter aucun client aujourd'hui----- \n");    }
}

void Traiter(char commande, int *client){
    if(commande == 'N' || commande == 'n'){
        AJOUTE(&N,*client);
        printf("BONJOUR MONSIEUR  VOTRE TICKET EST ** %d ** TU ES LE CLIENT NOMBRE  === %d === POUR L'INSTANT VEUILLEZ ATTENDRE VOTRE TOUR ET MERCI IL Y A =-= %d =-= CLIENT AVANT TOI \n",*client,(*t)+1,(*t));
        (*client)++;(*i)++;(*t)++;
    }
    else{
        if(N!=NULL){
            if(commande == 'A' || commande == 'a'){
                AJOUTE(&A,N->NOMBRE);if(*i>1){(*i)--;}if((*t)>0){(*t)--;}
                printf("LE CLIENT de ticket ** %d ** PASSE a L'EMPOLYE ~~ A ~~ S'IL VOUS PLAIT\n",N->NOMBRE);N = sup(N);
            }

            else if(commande == 'B' || commande == 'b'){
                AJOUTE(&B,N->NOMBRE);if(*i>1){(*i)--;}if((*t)>0){(*t)--;}
                printf("LE CLIENT de ticket ** %d ** PASSE a L'EMPOLYE ~~ B ~~ S'IL VOUS PLAIT \n",N->NOMBRE);N = sup(N);
            }

            else if(commande == 'C' || commande == 'c'){
                AJOUTE(&C,N->NOMBRE);if(*i>1){(*i)--;}if((*t)>0){(*t)--;}
                printf("LE CLIENT de ticket ** %d ** PASSE a L'EMPOLYE ~~ C ~~ S'IL VOUS PLAIT \n",N->NOMBRE);N = sup(N);
            }
             else printf("entrer votre commande :");
        }

    }

}




int main(){
    AFFMenu();
    char commande;
    printf("ENTRER VOTRE COMMANDE : \n");
    int TICKET = 1;
    scanf("%c%*c",&commande);

    while(commande!='X' && commande!='x'){
        AFFMenu();
        Traiter(commande,&TICKET);
        scanf("%c%*c",&commande);
        if(p==1){
                printf("AUCUN CLIENT DISPONIBLE POUR LE MOMENT \n");}

    }
    AFFMenu();
    if(TICKET!=1){printf("====================================================================| LES RESULTATS DU JOUR |==========================================================================\n");
   }          else printf("                       **AUCUN CLIENT DISPONIBLE POUR CE JOUR**                  \n");
    printf("          :LES CLIENT QU'IL a TRAITES PAR EMPOLYE A: \n");
    afflist(A);printf("NULL \n");
    printf("           :LES CLIENT QU'IL a TRAITES PAR EMPLOYE B: \n");
    afflist(B);printf("NULL \n");
    printf("           :LES CLIENT QU'IL a TRAITES PAR EMPOLYE C: \n");
    afflist(C);printf("NULL \n");
    //free(A);free(C);free(B);free(N);//
    printf("\n=========================================================|Thanks for using the project waiting for the full pointe|=====================================================");
return 0;
}
