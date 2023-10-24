/*

Nom: DZEUGUET DGNIDJEJI
Prenom: HUBERT CYRILLE
Matricule: 21S56127

*/





#include <stdlib.h>
#include <stdio.h>

//définition du type étudiant
typedef struct Etudiant Etudiant, *E;
struct Etudiant{
    int age;
    double poids;
    double taille;
    char *nom;
};
//prototypes
void supprimVieuxEtudiant(int* n, Etudiant* salle);
void afficheListeEtudiant(int* n,Etudiant* salle);


int main(void){
    int nbre = 0;
    int response = 0;
    char c[255][255];
    printf("\t By Ar10n: the Laplace's Demon :)\n");
    printf("__________________ Quel est le nombre d'étudiants de la salle !? ____________________ \n");
    scanf("%d", &nbre);
    Etudiant *salle;
    salle = malloc (nbre * sizeof(Etudiant));
    if (salle == NULL){
        printf( "Echec de l'allocation de la mémoire pour la salle !! \n");
        return EXIT_FAILURE;
    };
    printf("Entrer les informations des étudiants dans l'ordre AGE, POIDS, TAILLE, NOM \n");
    for (int i=0; i < nbre; i++){
        printf("\n \t++++++++++++++++++++ informations de l'étudiant %d +++++++++++++++++++++\n", i+1);
        scanf("%d %le %le %255s",&salle[i].age,&salle[i].poids,&salle[i].taille, c[i]);
        salle[i].nom = c[i];
    }
    afficheListeEtudiant(&nbre, salle);
    printf("voulez-vous ajouter un étudiant à la salle !?:\n \" entrer 1 pour OUI et 0  pour non \"\n");
    scanf("%d", &response);
    if(response){
        printf("***************** ajout d'étudiant ***************************\n");
        salle = realloc(salle, (nbre) * sizeof(Etudiant));
        if (salle == NULL){
            printf( "Echec de l'allocation de la mémoire pour la salle !! \n");
            return EXIT_FAILURE;
        };
        printf("\n \t =================================Informations Nouvel étudiant ===============================\n ");
        scanf("%d %le %le %255s",&salle[nbre].age,&salle[nbre].poids,&salle[nbre].taille, c[nbre]);
        salle[nbre].nom = c[nbre];
        afficheListeEtudiant(&nbre, salle);
    }

    printf("=======================================suppresssion vieux étudiants ===============================================\n");
    supprimVieuxEtudiant(&nbre, salle);
    free(salle);printf("\t It was Ar10n: the Laplace's Demon :), see you soon !!!!\n");

}


void afficheListeEtudiant(int *n, Etudiant *salle){
    printf("\n \t °°°°°°°°°°°°°°°°°° voici les étudiants actuel de la salle °°°°°°°°°°°°°°°°°° \n");
    for (int i = 0; i <= *n; i++){
        if (salle[i].nom != NULL){
			printf("^^^^^^^^^^^ Etudiant %d ^^^^^^^^^^^^^^^ \n", i+1);
            printf("Nom : %s\n", salle[i].nom);
			printf("Age : %d\n", salle[i].age);
			printf("Poids : %lf\n", salle[i].poids);
			printf("Taille : %lf\n", salle[i].taille);
			printf("\n");
		}
    }
}

void supprimVieuxEtudiant(int *n, Etudiant *salle){
    for (int i=0; i < *n; i++){
        if (salle[i].age >= 25){
            for (int j=0; j< *n; j++){
                salle[j] = salle [j+1];
            }
        *n=*n-1;
        }
    }
    if (*n==0)
        printf("\t''''''''''''''''''''''''' Oups, il ne reste plus personne ! (:\n ");
    else{
        printf("\n \t après suppression des étudiants de plus de 25ans\n");
    afficheListeEtudiant(n, salle);
    }
}

