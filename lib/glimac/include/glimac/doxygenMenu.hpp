#pragma once 

// Doxygen menu
/// \mainpage
/// \tableofcontents
/// \section instroduction_sec Qu'est-ce-que WorldImaker ?
/// WorldImaker est un éditeur de cube 3D.
/// \section install_bigsec Comment l'installer ?
/// \subsection dependencies_sec Librairies 
/// \li SDL2
/// \li CMAKE
/// \li OPENGL
/// \li EIGEN
/// \li GLEW
/// \li Doxygen (if you want the documentation)
/// \subsection install_sec Installation avec cmake
/// \li Créez un répertoire dans lequel importer le projet (lien vers le projet : https://github.com/margaux66/WorldIMaker.git)
/// \li mkdir build
/// \li cd build
/// \li cmake ../WordlImaker
/// \li make
/// \li make html
/// \li The documentation is located in [path to build]/doc/doc-doxygen/html/index.html
/// \section howuseit Comment ça marche ?
/// \subsection env_sec Environnement
/// \li Pour déplacer le curseur : utilisez les flêches de votre clavier
/// \li Pour déplacer la caméra : utilisez les touches q et d pour vous déplacer horizontalement et z et s pour vous déplacer verticalement
/// \li Pour dézoomer ou zoomer : utilisez la roulette de votre souris
/// \li Pour changer l'angle de la caméra : appuyez et bougez votre souris
/// \li Pour réinitialiser les paramètres de la caméra : appuyez sur g
/// \li Pour sauvegarder la scène : appuyez sur f et entrez dans le terminal le nom que vous voulez donner au fichier
/// \li Pour charger une scène : appuyez sur v et entrez dans le terminal le nom du fichier que vous voulez ouvrir
/// \li Pour supprimer la scène : appuyez sur c
/// \li Pour revenir à la scène de base : appuyez sur b
/// \li Pour passer du mode jour au mode nuit : appuyez sur n et inversement
/// \subsection edit_sec Éditer la scène
/// \li Pour ajouter un cube à la scène appuyer sur la touche r : le cube se placera à la position de votre curseur
/// \li Pour supprimer un cube de la scène appuyer sur la touche t : le cube à la position de votre curseur sera supprimer
/// \li Pour extruder appuyez sur u
/// \li Pour dig appuyez sur i
/// \li Pour changer la couleur du cube : appuyez sur l et entrez dans le terminal les valeurs de la couleur que vous voulez
/// \li Pour générer un cactus : appuyez sur p
/// \section info_sec Info
/// \version 1.0
/// \date Janvier 2020
/// \authors MAUREL Victorine & SEGUY Margaux

int main(){
	return 0;
}
