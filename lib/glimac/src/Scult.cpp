#include <glimac/Scult.hpp>

namespace glimac {
	void Scult::add(Cursor cursor, std::vector<Cube> &allCubes){
		for (int i = 0; i < allCubes.size(); ++i){
            if(cursor.getPosition() == allCubes[i].getPosition()){
                if(allCubes[i].getIsVisible()==false){
                    allCubes[i].setIsVisible(true);
                }
            }
       }
	}

	void Scult::remove(Cursor cursor, std::vector<Cube> &allCubes){
		for (int i = 0; i < allCubes.size(); ++i){
            if(cursor.getPosition() == allCubes[i].getPosition()){
                if(allCubes[i].getIsVisible()==true){
                    allCubes[i].setIsVisible(false);
                }
            }
       }
	}

	void Scult::extrud(Cursor cursor, std::vector<Cube> &allCubes){
		Scene scene;
		for (int i = 0; i < allCubes.size(); ++i){
            if(cursor.getPosition() == allCubes[i].getPosition()){
            	for (int j = 2; j < scene.getHeight(); ++j)
            	{
            		glm::vec3 pos = allCubes[i].getPosition();
            		if(allCubes[scene.getCubeAtThisPos(glm::vec3(pos.x,j,pos.z))].getIsVisible()==false){
            			allCubes[scene.getCubeAtThisPos(glm::vec3(pos.x,j,pos.z))].setIsVisible(true);
            			allCubes[scene.getCubeAtThisPos(glm::vec3(pos.x,j,pos.z))].setColor(allCubes[i].getColor());
            			return;
            		}
            	}
            }
        }    	
	}

	void Scult::dig(Cursor cursor, std::vector<Cube> &allCubes){
		Scene scene;
		for (int i = 0; i < allCubes.size(); ++i){
            if(cursor.getPosition() == allCubes[i].getPosition()){
            	for (int j = scene.getHeight(); j > 0 ; --j)
            	{
            		glm::vec3 pos = allCubes[i].getPosition();
            		if(allCubes[scene.getCubeAtThisPos(glm::vec3(pos.x,j,pos.z))].getIsVisible()==true){
            			allCubes[scene.getCubeAtThisPos(glm::vec3(pos.x,j,pos.z))].setIsVisible(false);
            			return;
            		}
            	}
            }
        } 

	}
	void Scult::changeColor(Cursor cursor,std::vector<Cube> &allCubes){
        glm::vec4 color;
        std::cout << "Entrez la composante R de la couleur de votre choix" << std::endl;
        int colorInput;
        std::cin>>colorInput;
        color.x = colorInput;
        std::cout << "Entrez la composante G de la couleur de votre choix" << std::endl;
        std::cin>>colorInput;
        color.y = colorInput;
        std::cout << "Entrez la composante B de la couleur de votre choix" << std::endl;
        std::cin>>colorInput;
        color.z = colorInput;
        std::cout << "Entrez la composante A de la couleur de votre choix" << std::endl;
        std::cin>>colorInput;
        color.w = colorInput;

		for (int i = 0; i < allCubes.size(); ++i){
            if(cursor.getPosition() == allCubes[i].getPosition()){
            	if(allCubes[i].getIsVisible()==true){
            			allCubes[i].setColor(color);
            	}
            }
        }
	}
	const void Scult::getColor(Cursor cursor,std::vector<Cube> &allCubes){
		for (int i = 0; i < allCubes.size(); ++i){
            if(cursor.getPosition() == allCubes[i].getPosition()){
            	if(allCubes[i].getIsVisible()==true){
            			std::cout << "Couleur du cube :  " << allCubes[i].getColor()<<std::endl;
            	}
            }
        }
	}

}