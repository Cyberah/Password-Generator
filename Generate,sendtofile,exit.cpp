#include "pch.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>

char Random_char[32];
unsigned short Passlength;
int main();

bool Checkinput(char answer){
	if (answer == 'Y' || answer == 'y')
		return 1;
	else if (answer == 'N' || answer == 'n')
		return 0;
}

bool Checkchars(char answer){
	return (answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N');
}

void Exit(){
	std::cout << "\nGoodbye.\n";
	exit(0);
}

void Generate_password(){
	std::cout << "How long you want to your password be?[4-32] ";
	do
	{
		std::cin >> Passlength;
		while (std::cin.fail()) {
			std::cout << "Enter a number. \n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> Passlength;
		}
		if (Passlength > 32){
			std::cout << "Maximum length of password is 32.\n";
			continue;
		}
		else if (Passlength < 4){
			std::cout << "Minimum length of password is 4.\n";
			continue;
		}
		srand((unsigned)time(0));
		for (int i = 0; i < Passlength; i++)
			Random_char[i] = (std::rand() % 93) + 32;
		std::cout << "Your new password is: \n";
		for (int i = 0; i < Passlength; i++)
			std::cout << Random_char[i];
		break;
	} while (true);
}

void Send_to_file(){
	do{
		std::cout << "Enter the name of file: ";
		std::string defaultname;
		std::cin.get();
		std::getline(std::cin, defaultname);
		std::string filename = defaultname + ".txt";
		std::ofstream file(filename);
		char answer;
		if (file.good() == false){
			std::cout << "Something went wrong, file couldn't be created.\nContinue?[Y]/[N] ";
			do{
				std::cin >> answer;
				if (answer == 'Y' || answer == 'y')
					Send_to_file();
				else if (answer == 'N' || answer == 'n')
					Exit();
			} while (!Checkchars(answer));
		}

		for (int i = 0; i < Passlength; i++)
			file << Random_char[i];
		file.close();

		std::cout << "Done.";
		std::cout << "\nGenerate again?[Y]/[N] ";
		do{
			std::cin >> answer;
			if (answer == 'Y' || answer == 'y')
				main();
			else if (answer == 'N' || answer == 'n')
				Exit();
		}while (!Checkchars(answer));
	} while (1);
}
