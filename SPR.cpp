#include <iostream>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32 
#define CLEAR_COMMAND "cls"
#define SHUT "shutdown -s"
#else
#define CLEAR_COMMAND "clear"
#define SHUT "halt"
#endif


void loser()
{
    system(SHUT);
}

void banner()
{
    system(CLEAR_COMMAND);
    std::cout << "____________________________________" << std::endl;
    std::cout << "           SPR                   " << std::endl;
    std::cout << "____________________________________" << std::endl;
}

int askUser()
{
    std::cout << "1. Scissors \n";
    std::cout << "2. Paper\n";
    std::cout << "3. Rock\n";
    std::cout << "Choose your option: ";
    int choice;
    std::cin >> choice;
    return choice;
}

int askComp()
{
    int choice;
    srand(static_cast<unsigned int>(time(NULL)));
    choice = rand() % 3;
    return choice;
}

void show(int user, int computer)
{
    switch (user)
    {
    case 1:
        std::cout << "Your choice : Scissors" << std::endl;
        break;
    case 2:
        std::cout << "Your choice : Paper" << std::endl;
        break;
    case 3:
        std::cout << "Your choice : Rock" << std::endl;
        break;
    default:
        break;
    }

    switch (computer)
    {
    case 0:
        std::cout << "Comp choice : Scissors" << std::endl;
        break;
    case 1:
        std::cout << "Comp choice : Paper" << std::endl;
        break;
    case 2:
        std::cout << "Comp choice : Rock" << std::endl;
        break;
    }
}

void check(int user, int computer)
{
    switch (user)
    {
    case 1:
        if (computer == 0)
        {
            std::cout << "\n Result : Draw!!" << std::endl;
        }
        else if (computer == 1)
        {
            std::cout << "\n Result : You win!!" << std::endl;
        }
        else if (computer == 2)
        {
            std::cout << "\n Result : You lose!!" << std::endl;
            loser();
        }
        break;
    case 2:
        if (computer == 0)
        {
            std::cout << "\n Result : you lose!!" << std::endl;
            loser();
        }
        else if (computer == 1)
        {
            std::cout << "\n Result : Draw!!" << std::endl;
        }
        else if (computer == 2)
        {
            std::cout << "\n Result : You win!!" << std::endl;
        }
        break;
    case 3:
        if (computer == 0)
        {
            std::cout << "\n Result : You win!!" << std::endl;
        }
        else if (computer == 1)
        {
            std::cout << "\n Result : You lose!!" << std::endl;
            loser();
        }
        else if (computer == 2)
        {
            std::cout << "\n Result :Draw!!" << std::endl;
        }
    }
}

char askReplay()
{
    std::cout << "\nReplay?(y/n):";
    char c;
    c = std::cin.get();
    return c;
}

int main()
{
    char replay;
    do
    {
        
        banner();
        int user = askUser();
        while (user > 3 || user < 1)
        {
            system("cls");
            banner();
            user = askUser();
        }
        int comp = askComp();
        show(user, comp);
        check(user, comp);
        replay = askReplay();
    } while (replay == 'y' || replay == 'Y');
    std::cout << "\nThank you for trying." << std::endl;
    return 0;
}

