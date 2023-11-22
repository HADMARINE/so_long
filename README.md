* Minilibx Docs : https://harm-smits.github.io/42docs/libs/minilibx
* https://github.com/S-LucasSerrano/miniLibX_sample

Solution pour réaliser L'Algorithm A*

1. Initialiser les valeurs
2. Evaluer les voisins et obtenir le monis coûteux (i)
3. Mettre dans le heap, mettre à jour les coûts des voisins (ii)
4. Prendre le moins coûteux élément dans heap (i)
5. Evaluation
	1. Evaluer s'il y a une solution (iii)
	2. Evaluer s'il n'y a aucune solution (iiii)
6. Continuer - 2

i. S'il y a les mêmes valeurs (au niveau de coût intégral), prendre celui qui a le moins dist_e
ii. Mettre à jour les coûts voisins
	1. Regarder les dist_e des voisins de chaque voisins
	2. Mettre valuer + 1 à dist_e, valeur est qui est le moins parmi les voisins
iii. Si la coordintion du moins coûteux (celui qui a le moins de dist_s) est égale à la destination. Il y a une solution, donc TRUE
iv. S'il n'y a aucun voisin(v) que je peux prendre, il n'y a aucune solution, donc FALSE
v. La sélection des nouveaux voisins se font parmi ceux qui ne sont pas encore pris.