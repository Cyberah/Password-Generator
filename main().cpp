#include "pch.h"
#include <iostream>
void Generate_password();
void Exit();
void Send_to_file();
bool Checkinput(char);
bool Checkchars(char);

int main()
{
	char answer;
	do{
		Generate_password();
		std::cout << "\nDo you want to save it to file?[Y]/[N] ";
		do{
			std::cin >> answer;
			if (answer == 'Y' || answer == 'y')
				Send_to_file();
			else if (answer == 'N' || answer == 'n'){
				std::cout << "\nContinue?[Y]/[N] ";
				do{
					std::cin >> answer;
					if (answer == 'Y' || answer == 'y')
						main();
					else if (answer == 'N' || answer == 'n')
						Exit();
				} while (!Checkchars(answer));
			}
		}while (!Checkchars(answer));
	} while (1);
	
	return 0;
}
