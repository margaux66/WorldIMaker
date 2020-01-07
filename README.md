# WorldIMaker

WorldIMaker est un éditeur de cube en 3D, réalisé en C++, en utilisant OpenGL 3 et la SDL 2. 

## Pour lancer le programme

### Pré-requis 

Plusieurs librairies et programmes doivent être installées sur votre machine afin de pouvoir utiliser l'application. 

- CMAKE
- SDL2
- OPENGL 
- GLEW 

### Démarrage 

Télécharger le dossier du projet, dans le même répertoire faites les étapes suivantes : 

```bash
mkdir build
cd build
cmake ../WorldIMaker
make
./bin/worldIMaker
```
## Pour utiliser le programme

Voici les outils nécessaires à l'utilisation de l'éditeur.

### Environnement 

Pour déplacer le curseur : utilisez les flêches de votre clavier
Pour déplacer la caméra : utilisez les touches q et d pour vous déplacer horizontalement et z et s pour vous déplacer verticalement
Pour dézoomer ou zoomer : utilisez la roulette de votre souris
Pour changer l'angle de la caméra : appuyez et bougez votre souris
Pour réinitialiser les paramètres de la caméra : appuyez sur g
Pour sauvegarder la scène : appuyez sur f et entrez dans le terminal le nom que vous voulez donner au fichier
```bash
Entrez le nom du fichier où vous voulez sauvegarder votre scène
[tapez le nom du fichier souhaité]
```
Pour charger une scène : appuyez sur v et entrez dans le terminal le nom du fichier que vous voulez ouvrir
```bash
Entrez le nom du fichier où votre scène est sauvegardée
[tapez le nom souhaitez]
```
Pour supprimer la scène : appuyez sur c
Pour revenir à la scène de base : appuyez sur b
Pour passer du mode jour au mode nuit : appuyez sur n et inversement

### Éditer la scène

Pour ajouter un cube à la scène appuyer sur la touche r : le cube se placera à la position de votre curseur
Pour supprimer un cube de la scène appuyer sur la touche t : le cube à la position de votre curseur sera supprimer
Pour extruder appuyez sur u
Pour dig appuyez sur i
Pour changer la couleur du cube : appuyez sur l et entrez dans le terminal les valeurs de la couleur que vous voulez
```bash
Entrez la composante R de la couleur de votre choix
[tapez la valeur de R souhaitée]
Entrez la composante G de la couleur de votre choix
[tapez la valeur de G souhaitée]
Entrez la composante B de la couleur de votre choix
[tapez la valeur de B souhaitée]
Entrez la composante A de la couleur de votre choix
[tapez la valeur de A souhaitée]
```
Pour générer un cactus : appuyez sur p