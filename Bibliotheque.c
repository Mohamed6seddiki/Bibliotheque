#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titre[100];
    char auteur[100];
    int ISBN;
} livre;

void ajouterLivre(livre livres[], int *nbLivres) {
    if (*nbLivres >= 100) {
        printf("La bibliotheque est pleine.\n");
    } else {
        printf("=== Ajouter un livre ===\n");
        printf("Titre : ");
       
        getchar();
        fgets(livres[*nbLivres].titre, sizeof(livres[*nbLivres].titre), stdin);
        livres[*nbLivres].titre[strcspn(livres[*nbLivres].titre, "\n")] = '\0';
        
        printf("Auteur : ");
        fgets(livres[*nbLivres].auteur, sizeof(livres[*nbLivres].auteur), stdin);
        livres[*nbLivres].auteur[strcspn(livres[*nbLivres].auteur, "\n")] = '\0';
        
        printf("ISBN : ");
        scanf("%d", &livres[*nbLivres].ISBN);
        (*nbLivres)++;
        printf("Livre ajoute avec succes!\n");
    }
}

void rechercherLivreParTitre(livre bibliotheque[], int nbLivres, char titre[]) {
    int trouve = 0;
    
    for (int i = 0; i < nbLivres; i++) {
        if (strcmp(bibliotheque[i].titre, titre) == 0) {
            printf("Livre trouve : %s de %s (ISBN: %d)\n", 
                   bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].ISBN);
            trouve = 1;
        }
    }
    if (trouve == 0) {
        printf("Livre non trouve\n");
    }
}

void afficherTousLesLivres(livre bibliotheque[], int nbLivres) {
    if (nbLivres == 0) {
        printf("Aucun livre dans la bibliotheque\n");
    } else {
        printf("\n=== Liste des Livres ===\n");
        for (int i = 0; i < nbLivres; i++) {
            printf("%d. %s de %s (ISBN: %d)\n", 
                   i + 1, bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].ISBN);
        }
    }
}

void supprimerLivre(livre livres[], int *nbLivres, char titre[]) {
    int trouve = 0;
    
    for (int i = 0; i < *nbLivres; i++) {
        if (strcmp(titre, livres[i].titre) == 0) {
            
            for (int j = i; j < *nbLivres - 1; j++) {
                livres[j] = livres[j + 1];
            }
            (*nbLivres)--;
            trouve = 1;
            break; 
        } 
    }
    
    if (trouve == 1) {
        printf("Livre supprime avec succes\n");
    } else {
        printf("Livre non trouve.\n");
    }
}

void pauseEcran() {
    printf("\nAppuyez sur Entree pour continuer...");
    getchar();
    getchar();
}

int main() {
    livre livres[100];
    int nbLivres = 0;
    char titre[100];
    int choix;
    
    do {
        
        system("cls"); 
        printf("\n=== Menu Bibliotheque ===\n");
        printf("1. Ajouter un livre\n");
        printf("2. Rechercher un livre par titre\n");
        printf("3. Afficher tous les livres\n");
        printf("4. Supprimer un livre\n");
        printf("0. Quitter\n");
        printf("========================\n");
        printf("Choix : ");
        
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                system("cls"); 
                ajouterLivre(livres, &nbLivres);
                pauseEcran();
                break;

            case 2:
                system("cls"); 
                printf("=== Rechercher un livre par titre ===\n");
                printf("Entrez le titre du livre à rechercher : ");
                getchar();
                fgets(titre, sizeof(titre), stdin);
                titre[strcspn(titre, "\n")] = '\0'; 
                printf("\n==============================\n");
                rechercherLivreParTitre(livres, nbLivres, titre);
                pauseEcran();
                break;
                
            case 3:
                system("cls"); 
                afficherTousLesLivres(livres, nbLivres);
                pauseEcran();
                break;

            case 4:
                system("cls"); 
                if (nbLivres == 0) {
                    printf("Aucun livre a supprimer.\n");
                } else {
                    afficherTousLesLivres(livres, nbLivres);
                    printf("\nEntrez le titre du livre à supprimer : ");
                    getchar();
                    fgets(titre, sizeof(titre), stdin);
                    titre[strcspn(titre, "\n")] = '\0';
                    supprimerLivre(livres, &nbLivres, titre);
                }
                pauseEcran();
                break;
                
            case 0:
                printf("Au revoir!\n");
                break;
                
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                pauseEcran();
                break;
        }
        
    } while (choix != 0);
    
    return 0;
}