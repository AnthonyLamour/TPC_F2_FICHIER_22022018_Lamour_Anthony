#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 30

//types
    typedef struct ddn{

        int j;
        int m;
        int a;

    }ddn;

    typedef struct Cid{

        int NumCarte;
        char* nom;
        char* prenom;
        char sexe;
        ddn Naissance;
        char* ville;

    }Cid;

int main()
{
    //VAR
        int choix=0,i=0;
        int lSize;
        Cid *CarteIdentite=malloc(sizeof(Cid));
        Cid *CarteIdentitetest[TAILLE];
        int test=0;
        CarteIdentite->nom=malloc(sizeof(char)*30);
        CarteIdentite->prenom=malloc(sizeof(char)*30);
        CarteIdentite->ville=malloc(sizeof(char)*50);

    //descripteur de fichier
        FILE * pFCarteIdBin;

    do{

        //clearscreen
            system("@cls||clear");

        //menu
            printf("Que voulez-vous faire :\n 1:Lire le fichier\n 2:Saisir une carte\n 0:quitter\n\n");
            scanf("%d",&choix);

        switch (choix){
                case 1://lecture de fichier partie nom fonctionnel
                        //ouverture du fichier
                            pFCarteIdBin = fopen ("CarteIdentite.bin","rb");
                            rewind(pFCarteIdBin);

                        //si le fichier n'existe pas alors érreur
                            if (pFCarteIdBin==NULL) {
                                printf("Le fichier n'existe pas.\n");
                        //sinon affichage du fichier
                            }else{

                                //définition de la taille du fichier
                                    fseek (pFCarteIdBin , 0 , SEEK_END);
                                    lSize = ftell (pFCarteIdBin);
                                    rewind (pFCarteIdBin);

                                //allocation de mémoire
                                    for(i=0;i<TAILLE;i++){
                                        CarteIdentitetest[i]=malloc (sizeof(Cid));
                                        CarteIdentitetest[i]->nom=malloc(sizeof(char)*30);
                                        CarteIdentitetest[i]->prenom=malloc(sizeof(char)*30);
                                        CarteIdentitetest[i]->ville=malloc(sizeof(char)*50);
                                    }
                                //initialisation ou réinitialisation de test et i
                                    test=sizeof(Cid)*lSize;
                                    i=0;
                                /*temps que la fin du fichier n'est pas atteinte alors on stock les données dans le tableau
                                CarteIdentitetest eton les affiches*/
                                    do{
                                        fread(CarteIdentitetest[i],sizeof(Cid),1,pFCarteIdBin);
                                        test=test-sizeof(CarteIdentitetest[i]);
                                        i++;
                                        printf("%d\n",CarteIdentitetest[i]->NumCarte);
                                        printf("%s\n",CarteIdentitetest[i]->nom);
                                        printf("%s\n",CarteIdentitetest[i]->prenom);
                                        printf("%c\n",CarteIdentitetest[i]->sexe);
                                        printf("%d/%d/%d\n",CarteIdentitetest[i]->Naissance.j,CarteIdentitetest[i]->Naissance.m,CarteIdentitetest[i]->Naissance.a);
                                    }while (test!=0);

                                 //pause
                                    system("pause");

                                //fermeture du fichier
                                    fclose (pFCarteIdBin);

                                //libération de la mémoire
                                    for(i=0;i<TAILLE;i++){
                                        free(CarteIdentitetest[i]->ville);
                                        free(CarteIdentitetest[i]->nom);
                                        free(CarteIdentitetest[i]->prenom);
                                        free(CarteIdentitetest[i]);
                                    }
                            }
                        break;
                case 2: //écriture de fichier
                        //renseignement de la variable CarteIdentite
                            printf("Entrez le numero de votre carte d'identite :\n");
                            fflush(stdin);
                            scanf("%d",&CarteIdentite->NumCarte);
                            printf("Entrez votre nom :\n");
                            fflush(stdin);
                            scanf("%s",CarteIdentite->nom);
                            printf("Entrez votre prenom :\n");
                            fflush(stdin);
                            scanf("%s",CarteIdentite->prenom);
                            printf("Entrez votre sexe:\n");
                            fflush(stdin);
                            scanf("%c",&CarteIdentite->sexe);
                            printf("Entrez le jour de votre date de naissance :\n");
                            fflush(stdin);
                            scanf("%d",&CarteIdentite->Naissance.j);
                            printf("Entrez le mois de votre date de naissance :\n");
                            fflush(stdin);
                            scanf("%d",&CarteIdentite->Naissance.m);
                            printf("Entrez l'annee de votre date de naissance :\n");
                            fflush(stdin);
                            scanf("%d",&CarteIdentite->Naissance.a);
                            printf("Entrez le nom de votre ville :\n");
                            fflush(stdin);
                            scanf("%s",CarteIdentite->ville);

                        //écriture dans le fichier
                            pFCarteIdBin = fopen ("CarteIdentite.bin","ab");
                            fwrite(CarteIdentite,sizeof(Cid),1,pFCarteIdBin);
                            fclose(pFCarteIdBin);
                        break;
            }

    }while(choix!=0);

    //libération de mémoire
        free(CarteIdentite->nom);
        free(CarteIdentite->prenom);
        free(CarteIdentite->ville);
        free(CarteIdentite);

    //pause
        system("pause");

    return 0;
}
