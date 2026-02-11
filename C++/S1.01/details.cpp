 J'ai deja crée une page html qui affiche pour l'instant les listes qui sont
dans le menu principal , mais je ne sais pas comment combiner les deux codes 

 Bon je vais esssayer d'abord le truc du istream

 Mais trés cher ls fstream c'est pas pour lire des fichiers?????? Donc tu veux dire que html n'est pas un fichier?
Si mais les extensions ne sont pas ls memes. Pas faux et si on essayais de changer l'extension? 
Aucune idée essaye pour voire si ça va marcher d'abord 

Navré de te decevoir mais le truc de fstream c'est pour mire et ecrire dans le fichier pas
de les executer ouplaaa

le menu principal doit avoir des listes et chaque listes avec ces osus listes

1. On va commencer avec la premiére liste 

Consulter les références Cette option affiche la liste des livres de la bibliothèque de manière paginée.
Chaque page présente un résumé de plusieurs livres et comportera au moins l'ISBN, le titre et les auteurs. 
L'utilisateur peut naviguer entre les pages ("Page suivante" / "Page précédente"). 
Le nombre de références affichées par page doit être configurable "(




    Paramétrer l'affichage Permet de définir le nombre de références à afficher par page 
    dans les listes paginées (consultation et recherche). 
    Cette valeur numérique est sauvegardée dans le fichier de configuration.
)"

En selectionnant un livre dans la liste l'app doit afficher les information sur ce livre
(le titre, l'auteur, ISBN, langue, date de parution, genre et description compléte presentees de maniere structurées)

pour pointer sur une fonction 
std::function 