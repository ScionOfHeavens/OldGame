#include "ElementalInterface.h"
#include"ElementalOutputInterface.h"

int ElementalInterface::GetCommand(std::string players_name,std::string elemental_name,int elemental_type,int level,int hp,int ap)
{
    ElementalOutputInterface::OutputPlayersName(players_name);
    ElementalOutputInterface::OutputElementalInformation(elemental_name, elemental_type, level, hp, ap);
    ElementalOutputInterface::AskCommand();
    std::string command;
    std::getline(std::cin, command);
    ElementalOutputInterface::EndOfWindow();
    switch (command[0])
    {
        case 'b':
            return 0;
        case 'l':
            return 1;
        case 'u':
            return 2;
        case 's':
            return 3;
        default:
            ElementalOutputInterface::WrongEnter();
            return GetCommand(players_name,elemental_name,elemental_type,level,hp,ap);
    }
}

void ElementalInterface::VoidPlace()
{
    ElementalOutputInterface::OutputVoidPlace();
    ElementalOutputInterface::ToReturnBack();
    bool b = ToReturnBack();
    ElementalOutputInterface::EndOfWindow();
    if (b == 1)
        return;
    else {
        ElementalOutputInterface::WrongEnter();
        VoidPlace();
    }
}

int ElementalInterface::GetSkillType()
{
    ElementalOutputInterface::AskSkill();
    std::string s;
    std::getline(std::cin, s);
    ElementalOutputInterface::EndOfWindow();
    switch (s[0])
    {
    case '0':
        return 0;
    case '1':
        return 1;
    default:
        ElementalOutputInterface::WrongEnter();
        return GetSkillType();
    }
    return 0;
}

void ElementalInterface::ImpossibleLvlUp()
{
    std::cout << "It is impossible because elemantal already has third lvl or it has not enough mana" << std::endl;
}
