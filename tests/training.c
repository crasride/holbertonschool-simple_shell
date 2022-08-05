#include "shell.h"

#define MAX_NUM 1024 // definie la taille maximale
/**
* main - function
* Return: ....
*/
int main(void)
{
        char *argc[8]; // pointeur sur charactere, tableau de valeur 8 arguments.
        char buffer[MAX_NUM + 1] = {0}; // definition de la taille du buffer 1024 + 1.
        int i, flag, argv; // declarations de 3 variables de type integer.

        while (1) // Tant que la condition est vrai.
        {
                if (fgets(buffer, MAX_NUM, stdin) == NULL) // Si valeur entrer au clavier vaut NULL. 
                        break; // arret programme
                buffer[strlen(buffer) - 1] = '\0'; // derniere valeur du buffer, renvoit fin de ligne. 

                i = 0,flag = 0, argv = 0; // initialisation de la variable.

                for (; buffer[i] != '\0' ; i++) // tant que l'index du buffer ne renvoit pas fin de ligne, incrementer.
                {
                        if (!isspace(buffer[i]) && flag == 0) //La fonction isspace() vérifie si un caractère n'est pas un espace blanc ou non.tokenise la variable.
                        {
                                flag = 1; //si vaut 1.
                                argc[argv++] = buffer + i;// trouve le pointer, incremente sa valeur.
                        }
                        else if (isspace(buffer[i]))  //La fonction isspace() vérifie si un caractère est un espace blanc ou non.Tokenise la variable.
                        {
                                flag = 0;// si vaut 0.
                                buffer[i] = '\0'; // trouve fin de ligne.
                        }
                }
                argc[argv] = NULL;
                if (argv) // contient la commande.
                {

                if (fork() == 0) // divise le child
                {
                        execvp(argc[0], argc); //recherche un nouveau processus image
                        exit(0); // quitte le programme.
                }
                else
                        wait(NULL); // attend
        }
        if (strcmp(argc[0], "exit") == 0) // compare la string.
                return (0); // quitte le programme 
        }
        return (0); // quitte le programme 
}

