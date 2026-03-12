*Ce projet a été créé dans le cadre du cursus 42 par mirajora.*

# ft_printf

## Description

**ft_printf** est une réimplémentation de la fonction standard `printf` de la bibliothèque C.  
Ce projet, réalisé dans le cadre du cursus 42, a pour objectif de reproduire le comportement de `printf` en gérant les conversions de format et les arguments variadiques.

Il permet de renforcer les compétences fondamentales en :

- Fonctions variadiques (`stdarg.h`)
- Analyse de chaînes de format
- Conversion de types de données
- Gestion de la mémoire
- Écriture bas niveau avec `write`
- Conception modulaire en C

L’objectif est de reproduire fidèlement le comportement de `printf` pour les conversions demandées, sans utiliser la fonction originale.

---

## Conversions supportées

Le projet gère les spécificateurs suivants :

| Spécificateur | Description |
|--------------|------------|
| `%c` | Caractère |
| `%s` | Chaîne de caractères |
| `%p` | Adresse mémoire (pointeur) |
| `%d` | Entier décimal signé |
| `%i` | Entier |
| `%u` | Entier décimal non signé |
| `%x` | Hexadécimal en minuscules |
| `%X` | Hexadécimal en majuscules |
| `%%` | Symbole pourcentage |

---

## Instructions

### Installation
Comment installer ceci :
```bash
git clone : git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-160b7df1-57a6-4f0b-a74a-871ba87360ac-7237136-mirajora
```
Prérequis : un système compatible POSIX avec un compilateur C (gcc/clang) et make.

Compilation de base :
- Exécutez `make` à la racine du dépôt. Cela compile les sources et produit la bibliothèque statique `libft.a` (et éventuellement des fichiers objets selon le Makefile).

Nettoyage des fichiers générés :
- `make clean` - supprime les fichiers objets
- `make fclean` - supprime les fichiers objets et la bibliothèque compilée
- `make re` - effectue `fclean` puis `make`

Utilisation de la bibliothèque dans un programme :
- Compilez votre programme et liez-le avec la bibliothèque et l'en-tête, par exemple :
  `cc -Wextra -Wall -Werror -o program file.c -L. -lft`
  ou incluez simplement les fichiers sources directement dans votre projet pour l'apprentissage.

## Exemple
#include "ft_printf.h"

int main(void)
{
    ft_printf("Bonjour %s\n", "42");
    ft_printf("Valeur : %d\n", 42);
    return (0);
}
## Gestion des arguments variadiques

	-Le projet utilise les macros de stdarg.h :
		.va_list
		.va_start
		.va_arg
		.va_end
Chaque spécificateur extrait le type approprié depuis la liste d’arguments.

## Choix techniques

Utilisation exclusive de write pour l’affichage.

Interdiction d’utiliser la fonction printf originale.

Fonctions séparées pour chaque conversion.

Code structuré et modulaire.

## RESOURCES
	- Documentation

		-> man 3 printf

		-> man 3 stdarg

	- Articles et tutoriels

		-> Fonctions variadiques en C

		-> Conversion d’entiers en chaînes

		-> Représentation des nombres en différentes bases

	- Utilisation de l’IA

	. Des outils d’intelligence artificielle ont été utilisés uniquement pour :

		-> Clarifier certains concepts théoriques (fonctions variadiques, conversions).

		-> Aider à la rédaction et à la structuration du README.

		-> Vérifier la cohérence des explications techniques.

L’IA n’a pas été utilisée pour générer ou remplacer la logique principale du code.