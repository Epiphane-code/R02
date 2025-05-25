📚 GESTION_DES_ETUDIANTS  — Projet R03 de la Piscine Codeloccol
   ===========================================================
                    🎯 Objectif du projet
   ===============\\====================//=================
                  \\====================//
Ce projet a été réalisé dans le cadre de la semaine 3 de la piscine Codeloccol. 
L'objectif est de construire une application en ligne de commande permettant 
de gérer une liste d'étudiants. Les étudiants peuvent être ajoutés, affichés, 
triés ou recherchés, avec une sauvegarde des données dans un fichier texte.

\\\\\\=============🛠️ Fonctionnalités implémentées============//////
            Fonction \\==============//	Description

creer_fichier()	          ===         Crée un fichier texte vide pour stocker 
                                      les étudiants.
ajouter_etudiant()        ===	      Ajoute un nouvel étudiant (ID, nom, prénom)
                                      dans le fichier.
trier_afficher()          ===	      Trie les étudiants par identifiant et 
                                      affiche la liste.
lister()                  ===	      Recherche un étudiant à partir de son 
                                      identifiant.
(À venir)                 ===	      Suppression d’un étudiant, chargement
                                      et sauvegarde complète.


                      📄 Fichier principal gest.c
                     \\=========================//
Le programme propose une interface en ligne de commande avec le menu suivant :

1.     Creer un fichier
2.     Ajouter un étudiant
3.     Afficher la liste des étudiants (triée par ID)
4.     Afficher un étudiant (filtrer par ID)
5.     Supprimer un étudiant de la liste
6.     Quitter
 
                    🔧 Compilation
                    \\===========//
Utiliser gcc pour compiler :

gcc -o gestion_etudiants gest.c
Puis exécuter avec :

./gestion_etudiants

                    ✅ Technologies
                   \\=============//
Langage : C

Système de fichiers : manipulation avec fopen, fscanf, fprintf, rewind, etc.

Terminal uniquement (interface texte)

                      👨‍💻 Auteurs
                     \\========//
Ce projet a été réalisé par les membres de l’équipe Rush01 :

Mahamadou Habibou chargé de 

Epiphane Nicoue chargé de

Mamoudou Souley chargé de

Boureima Souley chargé de

Mariam              :absente


                      NOTER BIEN ::
            
====



                       🚀 Remarques
                      \\===========//
Ce projet nous a permis de mettre en pratique les bases du C : manipulation 
de structures, tableaux, gestion de fichiers, et modularité du code.
Il a renforcé notre collaboration, notre logique algorithmique et notre 
rigueur dans le développement en équipe.---------------------------------.