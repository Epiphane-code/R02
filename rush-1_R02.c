#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
    int id;
    char nom[25];
    char prenom[25];
} p;

//fonction pour creer un fichier vide
void creer_fichier(const char* nom_fichier)
{
    FILE*f = fopen(nom_fichier, "a");
    if (f == NULL)
    {
        perror("Une erreur s'est produite lors de la creation du fichier");
        return;
    }
    fclose(f);
    printf("Le fichier %s existe ou a été creer avec succés", nom_fichier);
}


//fonction pour ajouter un etudiant à la liste des étudiants
void ajouter_etudiant(p etudiant, char* nom_fichier)
{
    FILE* f = fopen(nom_fichier, "a");
    if (f == NULL)
    {
        perror("Nous avons rencontré un problème lors de l'ouverture de ce fichier");
        return;
    }
    fprintf(f, "%d %s %s \n", etudiant.id, etudiant.nom, etudiant.prenom);
    printf("\nLes informations: ID:%d Nom:%s Prenom:%s ont été ajoutées avec succés", etudiant.id, etudiant.nom, etudiant.prenom);
    fclose(f);
}

//Trier et afficher
void trier_afficher(char *nom_fichier)
{
    FILE *f = fopen(nom_fichier, "r");
    if(f == NULL)
    {
        printf("Une erreur ou aucun étudiant n'est inscrit à la liste");
        return;
    }
    int i, j, id, taille=0; 
    char nom[25], prenom[25];
    while (fscanf(f, "%d %s %s", &id, nom, prenom) == 3) taille++;
    p etudiant[taille];
    p tempt[2];
    rewind(f);
    for (i = 0; i < taille; i++)
    {
        fscanf(f, "%d %s %s", &id, nom, prenom);
        etudiant[i].id = id;
        strcpy(etudiant[i].nom, nom);
        strcpy(etudiant[i].prenom, prenom);
    }
    fclose(f);

    //trier par id croissant
    for (i=0; i < taille; i++)
    {
        for (j = i+1; j < taille; j++)
        {
            if (etudiant[i].id > etudiant[j].id)
            {
                tempt[0].id = etudiant[i].id; etudiant[i].id = etudiant[j].id; etudiant[j].id = tempt[0].id;
                strcpy(tempt[0].nom, etudiant[i].nom); strcpy(etudiant[i].nom, etudiant[j].nom); strcpy(etudiant[j].nom, tempt[0].nom);
                strcpy(tempt[0].prenom, etudiant[i].prenom); strcpy(etudiant[i].prenom, etudiant[j].prenom); strcpy(etudiant[j].prenom, tempt[0].prenom);
            }
        }
    }
      printf("\n|||||||||||||||||||||||||||||| LISTE D'ETUDIANTS |||||||||||||||||||||||||||||||");
    for ( i = 0; i < taille; i++)
    {
        printf("\nMatricule: %d     Nom: %s    Prenom: %s", etudiant[i].id, etudiant[i].nom, etudiant[i].prenom);
        printf("\n--------------------------------------------------------------------------------");
    }

}

//fonction pour lister(rechercher)
void lister(int id, const char *nom_fichier)
{
    FILE *f = fopen(nom_fichier, "r");
    if (f == NULL)
    {
        perror("vide ou erreur d'ouverture");
        return;
    }
     char nom[25], prenom[25];
     int idr, k=0;
    printf("\n|||||||||||||||||||||||||||||| LISTE D'ETUDIANTS |||||||||||||||||||||||||||||||");
    while (fscanf(f, "%d %s %s",&idr, nom, prenom)==3)
    {
        if(idr == id)
        {
            printf("\nMatricule:%d     Nom:%s     Prenom:%s", idr, nom, prenom);
            printf("\n--------------------------------------------------------------------------------");

            k=1;
        }
        
    }
    if (k==0)
    printf("\nAucune information trouvée!");
    fclose(f);
}

//fonction pour supprimer un étudiant de la liste
void supprimer_etudiant(int id, const char *nom_fichier)
{
    FILE *f = fopen(nom_fichier, "r");
    if (f == NULL)
    {
        perror("vide ou erreur d'ouverture");
        return;
    }
    
    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        perror("Erreur lors de la création du fichier temporaire");
        fclose(f);
        return;
    }

    p etudiant;
    int idr, k = 0;
    while (fscanf(f, "%d %s %s", &idr, etudiant.nom, etudiant.prenom) == 3)
    {
        if (idr != id)
        {
            fprintf(temp, "%d %s %s\n", idr, etudiant.nom, etudiant.prenom);
        }
        else
        {
            k = 1; // Étudiant trouvé
        }
    }

    fclose(f);
    fclose(temp);

    if (k == 1)
    {
        remove(nom_fichier); // Supprimer l'ancien fichier
        rename("temp.txt", nom_fichier); // Renommer le fichier temporaire
        printf("L'étudiant avec ID %d a été supprimé avec succès.\n", id);
    }
    else
    {
        remove("temp.txt"); // Supprimer le fichier temporaire si l'étudiant n'est pas trouvé
        printf("Aucun étudiant trouvé avec l'ID %d.\n", id);
    }
}

int main()
{
int quiter=0;
while (quiter == 0)
{
    
   printf("////////////////////////////// CODELOCCOLE-RUSH-1_GESTION_DES_ETUDIANTS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
   printf("/////////////////////////////              PROJET-RO2                    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
   printf("----------------------------------------------------------------------------------------------------------\n");
   printf("                                  Manupilation des fichiers en C\n");
   printf("                                  ------------------------------\n");
   printf("                                  1. Creer un fichier\n");
   printf("                                  2. Ajout d'un étudiant\n");
   printf("                                  3. Afficher la liste des étudiants (trié par ID)\n");
   printf("                                  4. Afficher un étudiant (filtrer par ID)\n");
   printf("                                  5. Supprimer un étudiant de la liste\n");
   printf("                                  6. Quitter\n");
   printf("----------------------------------------------------------------------------------------------------------\n");

   int choix;
   printf("Entrez votre choix: ");
   printf("REPONSE:");
   // Utiliser scanf pour lire l'entrée de l'utilisateur
   scanf("%d", &choix);
   printf("----------------------------------------------------------------------------------------------------------\n");

   switch (choix)
   {
        case 1:
            {
                int sortie = 0;
                int k;
                // Créer un fichier
                printf("Créer un fichier\n");
                // Demander le nom du fichier à créer
                while(sortie == 0)
                {
                char nom_fichier[50];
                printf("Entrez le nom du fichier à créer: ");
                scanf("%s", nom_fichier);
                creer_fichier(nom_fichier);
                printf("\nVoulez-vous créer un autre fichier? (1 pour oui, 0 pour non): ");
                scanf("%d", &k);
                if (k == 0) 
                {
                    printf("Merci d'avoir utilisé le programme. Au revoir!\n");
                    sortie = 1;
                }
            
                } break;
            }
        case 2:
            {   int k;
                // Ajouter un étudiant à la liste
                printf("Ajouter un étudiant à la liste\n");
                // Demander le nom du fichier, l'ID, le nom et le prénom de l'étudiant
                int sortie = 0;
                while(sortie == 0)
                {
                    p etudiant;
                    char nom_fichier[50];

                    printf("Entrez le nom du fichier: ");
                    scanf("%s", nom_fichier);
                    printf("Entrez l'ID de l'étudiant: ");
                    scanf("%d", &etudiant.id);
                    printf("Entrez le nom de l'étudiant: ");
                    scanf("%s", etudiant.nom);
                    printf("Entrez le prénom de l'étudiant: ");
                    scanf("%s", etudiant.prenom);
                    ajouter_etudiant(etudiant, nom_fichier);
                    printf("\nVoulez-vous ajouter un autre étudiant? (1 pour oui, 0 pour non): ");
                    scanf("%d", &k);
                    if (k == 0) 
                    {
                        printf("Merci d'avoir utilisé le programme. Au revoir!\n");
                        sortie = 1;
                    }
    
                }break;
            }
        case 3:
            {   int k;
                // Afficher la liste des étudiants triée par ID
                printf("Afficher la liste des étudiants triée par ID\n");
                // Demander le nom du fichier à afficher
                int sortie = 0;
                while(sortie == 0)
                {
                    char nom_fichier[50];
                    printf("Entrez le nom du fichier: ");
                    scanf("%s", nom_fichier);
                    trier_afficher(nom_fichier);
                    printf("\nVoulez-vous afficher la liste d'un autre fichier? (1 pour oui, 0 pour non): ");
                    scanf("%d", &k);
                    if (k == 0) 
                    {
                        printf("Merci d'avoir utilisé le programme. Au revoir!\n");
                        sortie = 1;
                    }
                
                }break;
            }
        case 4:
            {   int k;
                // Rechercher un étudiant par ID
                printf("Rechercher un étudiant par ID\n");
                // Demander le nom du fichier et l'ID de l'étudiant à rechercher
                int sortie = 0;
                while(sortie == 0)
                {
                    int id;
                    char nom_fichier[50];
                    printf("Entrez le nom du fichier: ");
                    scanf("%s", nom_fichier);
                    printf("Entrez l'ID de l'étudiant à rechercher: ");
                    scanf("%d", &id);
                    lister(id, nom_fichier);
                    printf("\nVoulez-vous rechercher un autre étudiant? (1 pour oui, 0 pour non): ");
                    scanf("%d", &k);
                    if (k == 0) 
                    {
                        printf("Merci d'avoir utilisé le programme. Au revoir!\n");
                        sortie = 1;
                    }
                
                }break;
            }
        case 5:
            {   int k;
                // Supprimer un étudiant par ID
                // Demander le nom du fichier et l'ID de l'étudiant à supprimer
                printf("Supprimer un étudiant de la liste\n");
                int sortie = 0;
                while(sortie == 0)
                {
                    int id;
                    char nom_fichier[50];
                    printf("Entrez le nom du fichier: ");
                    scanf("%s", nom_fichier);
                    printf("Entrez l'ID de l'étudiant à supprimer: ");
                    scanf("%d", &id);
                    supprimer_etudiant(id, nom_fichier);
                    printf("\nVoulez-vous supprimer un autre étudiant? (1 pour oui, 0 pour non): ");
                    scanf("%d", &k);
                    if (k == 0) 
                    {
                        printf("Merci d'avoir utilisé le programme. Au revoir!\n");
                        sortie = 1;
                    }
                }break;
            
            }
        case 6:
            {   // Quitter le programme
                printf("Quitter le programme\n");
                printf("Merci d'avoir utilisé le programme. Au revoir!\n");
                quiter = 1;
                break;
            }

   }

}
return 0;
}
//fin du programme
