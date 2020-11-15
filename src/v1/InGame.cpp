#include "InGame.h"

InGame::InGame()
{
    cout << "You are already in game" << endl;
    fileName = "saving.txt";
    bool gameStatus = true;
}

InGame::~InGame()
{
}

void InGame::initGame(){
    ifstream savingFile;
	savingFile.open(fileName);

    if (inFile.is_open())
		this -> loadGame();
	else
	{
		newGame();
		this-> saveGame();
	}
    savingFile.close();
}

void InGame::newGame(){

    string name = "";
	cout << "Character name: ";
	getline(cin, name);
        
    int LV = 1;
    int HP = 100;
    int maxHP = 100;
    int MP = 40;
    int maxMP = 40;

    //Create character
    Character temp_character = Character(name, LV, HP, maxHP, MP, maxMP);
    this -> character = temp_character;
    cout << "Character: " << temp_character.name << " created!\n";

}

void InGame::saveGame(){
	ofstream outFile(fileName);

	if (outFile.is_open())
	{
        outFile << this -> character.AttributeToString() <<"\n";
	}
	outFile.close();
}

void InGame::loadGame(){

    ifstream savingFile(fileName);
	this ->character.clear();

    string name = "";
    int LV = 0;
    int HP = 0;
    int maxHP = 0;
    int MP = 0;
    int maxMP = 0;

    string line = "";
	stringstream str;

    if (savingFile.is_open())	{
		while (getline(savingFile, line))
		{
			str.str(line);
			str >> name;	
			str >> LV;
			str >> HP;
			str >> maxHP;
			str >> MP;
			str >> maxMP;

			//Create character
			Character temp_character = Character(name, LV, HP, maxHP, MP, maxMP);

            this -> character = temp_character;

			cout << "Character: " << temp_character.name << " loaded!\n";
			str.clear();

		}
	}

	inFile.close();

	if (this->characters.size() <= 0)
	{
		throw "ERROR! NO CHARACTERS LOADED OR EMPTY FILE!";
	}
}
void InGame::Menu()
{

    cout << "ENTER to continue..." << endl;
    cin.get();

    cout << "You have following options" << endl;
    cout << "0: Fight" << endl;
    cout << "1: Showstates" << endl;
    cout << "2: Save" << endl;
    cout << "3: Exit" << endl;

    cout << "Give your option: " << endl;
    cin >> this->option;

    while (cin.fail() || this->option > 3)
    {
        cout << "False input" << endl;
        cout << "Give your option again" << endl;
        cin.clear();

        // Extracts characters from the input sequence and discards them, until either n characters have been extracted, or one compares equal to delim.
        cin.ignore(5, '\n');

        cout << "Option in range [0,3]" << endl;
        cin >> this->option;
    }

    switch (this->option)
    {
    case 0:
        Fight();
        break;
    case 1:
        ShowStates();
        break;
    case 2:
        saveGame();
        break;
    case 3:
        this -> gameStatus = false;
        Exit();
        break;
    }
}
void InGame::Fight()
{
    cout << " You are now encountering Enemy XXX" << endl;
}
void InGame::ShowStates()
{
    cout << "Your current state shows below" << endl;
    // TODO: ADD character info;
    cout << "Your current character is " << endl;
    cout << "Your current HP is " << endl;
}

void InGame::Exit()
{
    cout << "Exiting" << endl;
}
