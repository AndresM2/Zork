#include "Globals.h"
#include "World.h"
#include <ctime>
#include <cstdlib>

int main() {

	cout << "WELCOME TO ZORK!" << endl;
	srand(static_cast<unsigned int>(time(NULL)));

	World world;
	string input;

	while (!world.IsGameOver()) {

		// Obtener el input
		getline(cin, input);

		// Convierte las strings en palabras
		vector<string> words = Globals::split(input);

		// Salir
		if (words.size() > 0 && (ACTION_EXIT == Globals::toLowercase(words.at(0)) || ACTION_QUIT == Globals::toLowercase(words.at(0))))
			break;

		// Comando Parse
		world.HandleInput(words);

	}

	cout << "Thanks for playing!" << endl;
	system("pause");
	return 0;
}