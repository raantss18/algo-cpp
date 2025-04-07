# C++ - Algorithmes classiques et avancés

Ce dépôt regroupe des implémentations en C++ d'algorithmes vus en cours avec les étudiants. Les solutions couvrent plusieurs paradigmes : **backtracking**, **programmation dynamique**, **diviser pour régner**, et d'autres approches classiques. Chaque dossier contient le code source et une explication en commentaires.

## Contenu du dépôt

### 🔁 ABRO
**Problème** : Simuler un automate ou résoudre un problème d'accès binaire répétitif optimisé.  
**Description** : L'algorithme lit une séquence d'actions binaires et applique une logique de validation ou de transformation selon un ensemble de règles données.

### 👑 Problème des N-Reines (Backtracking)
**Problème** : Placer N reines sur un échiquier de taille N×N sans qu'elles ne se menacent mutuellement.  
**Méthode** : Utilisation du backtracking pour tester récursivement toutes les positions valides.

### ♜ Problème des N-Tours (N-Rooks)
**Problème** : Placer N tours sur un échiquier de taille N×N de sorte qu’aucune ne se menace.  
**Méthode** : Similaire aux N-Reines mais avec des contraintes simplifiées (lignes et colonnes uniquement).

### 📍 Points les plus proches (Diviser pour régner)
**Problème** : Trouver la paire de points la plus proche dans un plan en 2D.  
**Méthode** : Utilisation d’un algorithme de type « divide and conquer » pour atteindre une complexité en O(n log n).

### 🔢 Résolution de Sudoku
**Problème** : Compléter une grille 9x9 avec des chiffres de 1 à 9 selon les règles du Sudoku.  
**Méthode** : Backtracking avec vérification de validité ligne/colonne/boîte.

### 🔃 Tri par fusion
**Problème** : Trier un tableau d’entiers.  
**Méthode** : Algorithme de tri par fusion, basé sur le paradigme diviser pour régner, avec une complexité O(n log n).

### 🎒 Problème du sac à dos (0-1 Knapsack)
**Problème** : Remplir un sac à dos avec un ensemble d’objets pour maximiser la valeur sans dépasser un poids limite.  
**Méthode** : Programmation dynamique pour explorer toutes les combinaisons possibles de manière optimisée.

### 💰 Problème du rendu de monnaie
**Problème** : Trouver le nombre minimum de pièces pour rendre une somme donnée.  
**Méthode** : Approche en programmation dynamique pour calculer les sous-problèmes de manière efficace.

---

## Organisation
Dans chaque fichiers `.cpp` on peut trouver :
- Des commentaires expliquant l’approche
- Parfois des exemples d’entrée/sortie dans le code

## Pré-requis
- Compilateur C++ (g++ recommandé)
- Environnement Linux/Windows/Mac
- Compilation : `g++ nom_du_fichier.cpp -o programme && ./programme`

---

## Contributions
Les contributions sont les bienvenues ! Si vous avez des suggestions d'amélioration ou d'autres algorithmes intéressants, n'hésitez pas à ouvrir une *issue* ou une *pull request*.

## Auteur
Travail réalisé avec les étudiants en algorithmique dans le cadre de l’enseignement en informatique/mathématiques.


