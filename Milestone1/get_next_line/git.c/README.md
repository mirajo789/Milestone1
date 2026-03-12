*This project has been created as part of the 42 curriculum by mirajora.*

# get_next_line
## DESCRIPTIONS

get_next_line est un projet du cursus de l’ecole 42 dont l’objectif est d’implémenter une fonction capable de lire un fichier ligne par ligne.

La fonction get_next_line doit :

-Lire depuis un file descriptor

-Retourner une ligne à la fois, incluant le \n si présent

-Gérer les lectures successives sans perdre d’information

-Fonctionner avec différents types d’entrées (fichiers, entrée standard, etc.)

Ce projet permet de comprendre en profondeur :

-La gestion des file descriptors

-L’utilisation de read

-La gestion dynamique de la mémoire

-La manipulation de buffers

-La gestion des fuites mémoire

## INSTRUCTIONS
### Installation
Comment installer ceci :
```bash
git clone : git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-11087192-2aa7-4674-9388-7fa6cd0d789f-7255973-mirajora
```
### Compilation
Compilation standard : 
-> cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
vous pouvez modifier BUFFER_SIZE lors de la compilation : 
-D BUFFER_SIZE=1024

-Exemple main:

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    int i = 1;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return 1;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("[%d]%s",i++,line);
        free(line);
    }
    close(fd);
}
### Choix techniques

Utilisation d’un buffer statique pour conserver les données non lues

-Découpage en fonctions utilitaires :

.ft_strjoin

.ft_substr

.ft_strdup

.ft_strlen

.ft_strchr

## Resources

-Peer to peer

### Documentation

-Manuel read(man 2 read)

### Utilisation de l'IA

-> L’intelligence artificielle a été utilisée pour :

.Clarifier certains comportements spécifiques de read

.Vérifier la gestion des cas limites (EOF, fichiers vides, grands buffers)

.Améliorer la structure et la rédaction du README

.Relire et expliquer certaines erreurs mémoire potentielles

L’implémentation principale et la logique de gestion du buffer ont été conçues et codées manuellement.