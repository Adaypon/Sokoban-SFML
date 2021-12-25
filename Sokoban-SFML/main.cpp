#include "Game.hpp"
#include <vector>
#include <string>
#include <fstream>

int main() {
    Game game;

	std::string str;
	std::vector<std::string> fileCache;
	std::ifstream fin;
	fin.open("config.ini");
	if (fin.is_open()) {
		while (!fin.eof()) {
			if (getline(fin, str) && !(str.length() == 1 && isspace(str[0]))) {
				fileCache.push_back(str);
			}
		}
	}
	else {
		std::cerr << "Can't open configuration file " << std::endl;
		throw std::invalid_argument("Unable to load the file");
	}
	fin.close();
	/*
	for (auto elem : fileCache) {
		std::cout << elem << std::endl;
		std::getchar();
	}
	*/

	game.setResolution(std::stoi(fileCache[0]), std::stoi(fileCache[1]));

    game.run();
    return 0;
}