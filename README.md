# LivreRecettes
#Cette application a été développée par Florian DESAMAIS et Jérémy IGONIN; 
 


Application permettant de gérer un livre de recettes.

Cette application permet à l'utilisateur de créer, modifier et supprimer des recettes.

L'application contient deux pages:

	- FirstPage : qui est une liste de recette, sur cette vue on retrouve un pullDown Menu avec l'ajout d'une recette et la sauvegarde en JSON (ne fonctionne pas pour le moment)
		-> Lorsqu'on reste appuyer sur une recette un contextMenu permettant la suppression apparait. 
  		-> Lorsqu'on clique sur une recette on se retrouve sur la SecondePage
	
	- SecondPage : qui est le detail d'une recette, on retrouve son nom, temps de préparation , nombre de personne, note, et description ( ce champ est difficilement accessible a cause du clavier virtuel). Ces champs sont modifiables. 
		-> Pour valider la modification il faut quitter le focus ou valider.
 
	- Execution du Main : Création du modele, chargement du JSON si il existe, sinon on charge un stub, puis on démarre l'application.

