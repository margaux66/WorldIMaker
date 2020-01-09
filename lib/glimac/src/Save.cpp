#include <glimac/Save.hpp>

namespace glimac {
	void Save::saveScene(std::string filepath, std::vector<Cube> allCube){
		std::cout << "Entrez le nom du fichier où vous voulez sauvegarder votre scène" << std::endl;
        std::string name;
        std::cin>>name;

        name = "/" +name;
		filepath +=name;

		std::ofstream file (filepath);

		if (!file.is_open())
		   std::cout << "Save scene : Can't read the file" << std::endl;
		else
		   {
		   	for (uint i = 0; i < allCube.size(); ++i)
		   	{
		   		file << allCube[i].getPosition().x;
		   		file << " ";
		   		file << allCube[i].getPosition().y;
		   		file << " ";
		   		file << allCube[i].getPosition().z;
		   		file << " ";
		   		file << allCube[i].getColor().x;
		   		file << " ";
		   		file << allCube[i].getColor().y;
		   		file << " ";
		   		file << allCube[i].getColor().z;
		   		file << " ";
		   		file << allCube[i].getColor().w;
		   		file << " ";
		   		file << allCube[i].getIsVisible();
		   		file << " ";
		   	}
		    
		   }
		file.close();
	}

	void Save::loadScene(std::string filepath, std::vector<Cube> &allCube){
		std::cout << "Entrez le nom du fichier où votre scène est sauvegarder" << std::endl;
        std::string name;
        std::cin>>name;
        name = "/" +name;
        filepath +=name;
		std::ifstream file(filepath);
		if (!file.is_open())
		   std::cout << "Save scene : Can't read the file" << std::endl;
		else{
			int i = 0;

			while(file){
				glm::vec3 pos;
				glm::vec4 color;
				bool visible;

				file >> pos.x;
				file >> pos.y;
				file >> pos.z;

				Cube cube(pos);

				file >> color.x;
				file >> color.y;
				file >> color.z;
				file >> color.w;

				cube.setColor(color);

				file >> visible;
				
				allCube[i] = cube;
				if (visible == 1){
					allCube[i].setIsVisible(visible);
				}
				else{
					allCube[i].setIsVisible(visible);
				}
				i++;
			}
		}
		file.close();
	}
}