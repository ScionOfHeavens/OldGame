#include "PlayerInterface.h"
#include "OuputPlayersInterface.h"

#include<iostream>

std::string PlayerInterface::GetPlayersName(int order_number)
{
    OutputPlayersInterface::AskPlayersName(order_number);
    std::string name;
    std::getline(std::cin, name);
    OutputPlayersInterface::EndOfWindow();
    return name;
}

int PlayerInterface::GetCommand(std::string players_name)
{
    OutputPlayersInterface::AskCommand(players_name);
    std::string command;
    getline(std::cin, command);
    OutputPlayersInterface::EndOfWindow();
    switch (command[0]) {
        case 'i':
            return 3;
        case 'w':
            return 2;
        case 'm':
            return 1;
        case 'f':
            return 0;
        default:
            OutputPlayersInterface::WrongEnter();
            return GetCommand(players_name);
    }
}

void PlayerInterface::GetPlayersInformation(std::string players_name, int lm,
    int dm, int am, int em, int fm, int wm, int ap, int tnoa)
{
    OutputPlayersInterface::OutputPlayersInformation(players_name, lm, dm, am, em, fm, wm, ap, tnoa);
    OutputPlayersInterface::ToReturnBack();
    bool b(ToReturnBack());
    OutputPlayersInterface::EndOfWindow();
    if (b == 1)
        return;
    else {
        OutputPlayersInterface::WrongEnter();
        return GetPlayersInformation(players_name, lm, dm, am, em, fm, wm, ap, tnoa);
    }
}
