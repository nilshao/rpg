# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <vector>

struct PlayerClass{
    public:
        std::string character_name;
        int HealthPoints;
        int MagicPoints;
        int process;
        PlayerClass();
};

PlayerClass::PlayerClass(void){
    HealthPoints = 100;
    MagicPoints = 40;
    process = 0;
}

PlayerClass NewGame(){

    PlayerClass new_player;
    std::string str;
    std::cout<<"give me a new name"<<std::endl;
    std::cin >> new_player.character_name;
    std::cout << "---------------------------------------------------------"<<std::endl;
    std::cout << "| hello "<< new_player.character_name << "!" << std::endl;
    std::cout << "| you have "<<new_player.HealthPoints<< " HP!"<<std::endl;
    std::cout << "| you have "<<new_player.MagicPoints << " MP!"<<std::endl;
    std::cout << "| you are new here! So u will start from level: "<<new_player.process<<std::endl;
    std::cout << "| Good Luck!" <<std::endl;
    std::cout << "----------------------------------------------------------"<<std::endl;

    return new_player;
}



int Start_Menu_Initialize(){
    std::cout << "---------------------------------------------------------"<<std::endl;
    std::cout << "|                     Hello Welcome!                    |"<< std::endl;
    
    std::string str;
    while(1){
        std::cout << "---------------------------------------------------------"<<std::endl;
        std::cout << "| Hello, Welcome! You have following choices!"<<std::endl;
        std::cout << "| 1. New Game "<<std::endl;
        std::cout << "| 2. Load Game" <<std::endl;
        std::cout << "| 3. Exit" <<std::endl;
        std::cout << "| Input the Number to make your choice" << std::endl;
        std::cout << "---------------------------------------------------------"<<std::endl;
        
        getline(std::cin, str);
        if(str == "1" || str == "2" )
            break;
        else if(str == "3")
            break;
        else
            std::cout << "---------------------------------------------------------"<<std::endl;
            std::cout<< "|   stupido, choose again!"<<std::endl;
    }
    int res = str[0]-'0';
    return res;
}
std::vector <std::string> WritePlayerAttribution(int loc, PlayerClass player){
    std::vector<std::string> res;

    res.push_back(std::to_string(loc));
    res.push_back(player.character_name);
    res.push_back(std::to_string(player.HealthPoints));
    res.push_back(std::to_string(player.MagicPoints));
    res.push_back(std::to_string(player.process));

    return res;
    
}
std::vector<std::vector<std::string>> ReadSavingFile(){
    std::ofstream outfile;   
    std::ifstream inFile("PlayerSavings.csv", std::ios::in);
    std::vector<std::vector<std::string>> saving_file;
    std::string single_saving;

    while(getline(inFile, single_saving)){
        std::stringstream ss(single_saving);
        std::string saving_item;
        std::vector<std::string> saving_line;
        
        while(getline(ss, saving_item, ',')){

            saving_line.push_back(saving_item);           
        }
        saving_file.push_back(saving_line);
        
    }
    for(std::vector<std::string> vec: saving_file){
        for(std::string str: vec){
            std::cout << str <<" ";
        }
        std::cout <<std::endl;
    }
    return saving_file;
}

void SaveGame(PlayerClass player){
    std::vector<std::vector<std::string>> saving_file = ReadSavingFile();
    std::cout <<" Where do u want to save at?"<<std::endl;
    int loc;
    std::cin >> loc;

    std::cout << "save at location:" << loc <<std::endl;

    std::vector <std::string> player_vec; 
    player_vec = WritePlayerAttribution(loc,player);
    saving_file[loc] = player_vec;
    for(std::string str: saving_file[loc]){
        std::cout <<str <<" ";
    }
    std::cout << std::endl;
    std::cout << "================================"<<std::endl;
    for(std::vector<std::string> vec: saving_file){
        for(std::string str: vec){
            std::cout << str <<" ";
        }
        std::cout <<std::endl;
    }
}


PlayerClass LoadGame(){
    std::cout <<"These are the files we have, which do u want to load?"<<std::endl;
    std::vector<std::vector<std::string>> saving_file = ReadSavingFile();
    std::cout << "your choice: ";
    int loc;
    std::cin >> loc;

    PlayerClass player_load;
    player_load.character_name  =   saving_file[loc][1];
    player_load.HealthPoints    =   std::stoi(saving_file[loc][2]);
    player_load.MagicPoints     =   std::stoi(saving_file[loc][3]);
    player_load.process         =   std::stoi(saving_file[loc][4]);
    
    return player_load;
}

int main(){
    int start_command = Start_Menu_Initialize();
    
    PlayerClass player;
    if(start_command == 1 ){
        player = NewGame();
        std::cout <<"Game Start!"<<std::endl;
    }
    else if(start_command == 2){
        player = LoadGame();
        
        std::cout << "Back to Game!" << std::endl;
    }
    else{
        std::cout <<"ai wan bu wan"<<std::endl;
        return 0;
    }
    std::cout <<"----------------------------"<<std::endl;
    std::cout <<"Your attribution now: ";
    std::cout << player.character_name << " ";
    std::cout << player.HealthPoints << " ";
    std::cout << player.MagicPoints << " ";
    std::cout << player.process << " ";


 //   SaveGame(player);
 //   Fight();
    return 0;
}