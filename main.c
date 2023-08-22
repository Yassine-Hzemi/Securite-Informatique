//  Grille de Vigenere
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main()

{
     int i,j,k,l;               // Variables
     char G[37][37];            // Grille de Vigenere
	 char texte[88];            // Texte a crypter
	 char cle[200];              // Cle de codage : Dans ce programme, uniquement entrer 'toto'
	 char textecrypte[88];
	 char textedecrypte[88];

// Boucles et conditions générant la grille automatiquement
     for(i=0;i<37;i++)
     {
	     for(j=0;j<26;j++)

		     G[i][j]= 97 + j;

			     if (G[0][25]==122)
			     {
				     G[i][26]=32;
				     for (j=27;j<37;j++) G[i][j]= 48 + (j-27)  ;
			  }
     }

for(i=1;i<37;i++)

{

	for(j=0;j<36;j++) G[i][j]=G[i-1][j+1];
           if (j==36)  G[i][j]=G[i-1][0];

     }
// Fin de l'algorithme
     printf("Affichage de la table:\n");
// Affichage de la grille de Vigenere
     for (i=0;i<37;i++)
     {
	     for (j=0;j<37;j++)
	     	     printf("%c",G[i][j]);

	     printf("\n");
	     }

     printf("\nFin\n");
// Condition d'entrée du texte
	 printf("Entrer le texte a crypter: \n");

	  gets(texte);

	 printf("Texte entre:\n");
	 puts(texte);

	 printf("Entrer la cle:\n");
	 gets(cle);

	 printf("Cle entrée:\n");
	 puts(cle);

	for (i=0;strlen(cle)<strlen(texte);i++)
{
	cle[i+4]=cle[i];

}

printf("Cle sur toute la ligne:\n");
puts(cle);

		printf("\nCryptage en cours:\n");
// Cryptage //


	  j=0;
	 l=0;
	 k=0;

	 for (i=0;l<strlen(texte);j++)
{

	if(G[0][j]==texte[l])
	{
		for(i=0;l<strlen(texte);i++)
		{
			if(G[i][0]==cle[l])
			{
				textecrypte[k]=G[i][j];
				k++;
				l++;
				j=0;
				break;
			}

		}

	}

}
// Affichage du texte crypté
printf("Texte crypte:\n");
puts(textecrypte);
// Décryptage
l=0;
k=0;
for (j=0;l<strlen(texte);i++)
{

		if (G[i][0] == cle[l])
		{
                    for (j=0;l<strlen(texte);j++)
			    if (G[i][j]==textecrypte[k])
			    {
				    textedecrypte[k]=G[0][j];
				    k++;
				    l++;
				    i=0;
				    break;
			    }

		}
}
// Affichage du texte décrypté
printf("Texte decrypte:\n");
puts(textedecrypte);

}
