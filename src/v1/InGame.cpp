#include "InGame.h"
InGame::InGame()
{
    cout << "You are already in game" << endl;
    this->fileName = "../savingfile/saving.txt";
}

InGame::~InGame()
{
}

// Initialize the game (loading or create a new one)
void InGame::init_Game()
{
    ifstream savingFile;
    savingFile.open(this->fileName);

    if (savingFile.is_open())
    {
        cout << "Loading" << endl;
        this->loadGame();
    }
    else
    {
        createGame();
        this->saveGame();
    }
    savingFile.close();
}

void InGame::createGame()
{

    string name = "";
    cout << "Character name: ";
    getline(cin, name);

    //Create character
    character.initialize(name);
    cout << "Character: " << name << " is created!" << endl;
}

void InGame::saveGame()
{
    ofstream outFile(fileName);

    if (outFile.is_open())
    {
        outFile << this->character.AttributeToString() << "\n";
    }
    outFile.close();
}

void InGame::loadGame()
{

    ifstream savingFile(fileName);
    // this->character.clear();

    string name = "";
    int LV = 0;
    int HP = 0;
    int maxHP = 0;
    int MP = 0;
    int maxMP = 0;
    int vitality = 0;

    string line = "";
    stringstream strstr;

    if (savingFile.is_open())
    {
        while (getline(savingFile, line))
        {
            strstr.str(line);
            strstr >> name;
            strstr >> LV;
            strstr >> HP;
            strstr >> maxHP;
            strstr >> MP;
            strstr >> maxMP;
            strstr >> vitality;
            //Create character
            this->character.Character::CharacterLoading(name, LV, HP, maxHP, MP, maxMP, vitality);

            cout << "Character: " << name << " is loaded!" << std::endl;
            strstr.clear();
        }
    }

    savingFile.close();
}
void InGame::Menu()
{

    cout << "ENTER to continue..." << endl;
    cin.get();

    cout << "You have following options" << endl;
    cout << "0: Fight" << endl;
    cout << "1: Showstats" << endl;
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
        character.ShowStats();
        break;
    case 2:
        saveGame();
        break;
    case 3:
        Exit();
        break;
    }
}
void InGame::Fight()
{
    cout << " You are now encountering Enemy XXX" << endl;
    int damage = 3;
    cout << "You lost XX damge" << endl;
    character.takeDamage(damage);
}

void InGame::Exit()
{
    cout << "Exiting" << endl;
    exit(1);
}
bool InGame::game_status()
{
    return character.characterstate();
}