#include <glimac/Save.hpp>

namespace glimac {
	void Save::saveScene(std::string filepath, std::vector<Cube> allCube){
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

	void Save::loadScene(std::string filepath, std::vector<Cube> allCube){
		std::ifstream file(filepath);

		if (!file.is_open())
		   std::cout << "Save scene : Can't read the file" << std::endl;
		else{
			while(file){
				for (uint i = 0; i < allCube.size(); ++i)
				{
					glm::vec3 pos;
					glm::vec4 color;
					bool visible;
					file >> pos.x;
					file >> pos.y;
					file >> pos.z;
					allCube[i].setPosition(pos);
					file >> color.x;
					file >> color.y;
					file >> color.z;
					file >> color.w;
					allCube[i].setColor(color);
					file >> visible;
					allCube[i].setIsVisible(visible);

					std::cout << pos << " " << color << " " << visible<< std::endl;
				}
			}
		}
		file.close();
	}
}