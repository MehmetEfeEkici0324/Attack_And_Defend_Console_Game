#include <iostream>
#include <stdlib.h>
using namespace std;

void bar_Hesaplama(double can);

int main()
{
    setlocale(LC_ALL, "Turkish");

    srand(time(NULL));

    start:

    double user_live = 100.0;
    double computer_live = 100.0;
    int user_power = 10;
    int computer_power = 10;
    int user_counter = 0;
    int computer_counter = 0;
    string user_name;
    int choose_user;
    int computer_Power_count = 0;
    int user_Power_count = 0;
    int computer_DefAtt_count = 0;
    int user_DefAtt_count = 0;
    int choose_computer;
    int S = 0, F = 0;

    cout << "\n\n\t --------------- ATTACK AND DEFEND -------------- ";
    cout << "\n\t             made by Mehmet Efe Ekici ";
    cout << "\n\n\t > ENTER YOUR NICKNAME : ";
    cin >> user_name;

    S = rand() % 2;
    if (S == 0) {
        F = 20;
    }
    else if(S == 1){
        F = 21;
    }

        for (int i = S; i < F; i++) {

            if (i % 2 == 0) {

                if (i == 2) {
                    user_Power_count = 2;
                }

                cout << "\n\n\t !!! WARNING !!! "
                    "\n\t 1 -) Common Attack "
                    "\n\t 2 -) Powerful Attack "
                    "\n\t 3 -) Defend"
                    "\n\t 4 -) Against Attack "
                    "\n\t 5 -) Take Live "
                    "\n\t 6 -) USE MAGIC POWER ";

                cout << "\n\n\t ------------ STATE " << i+1 << " ----------- \n\n\t ATTACKER > " << user_name;
                cout << "\n\t DEFENDER > Computer ";

                choose_computer = 3 + (rand() % 3);

                if (computer_counter < 3 && computer_DefAtt_count == i - 2) {
                    choose_computer = 3;
                }
                
                if (choose_computer == 4 && computer_DefAtt_count == i - 2) {
                    do {
                        choose_computer = 3 + (rand() % 3);
                    } while (choose_computer == 4);
                }

                if (choose_computer == 5 && computer_counter < 3) {
                    choose_computer = 3 + (rand() % 2);
                }

                if (computer_counter >= 3 && computer_live >= 45) {
                    choose_computer = 5;
                }

            chooseUser:

                cout << "\n\n\t > CHOOSE YOUR MOVE : ";
                cin >> choose_user;

                if (choose_user == 6 && user_counter < 3) {
                    cout << "\n\n\t\a ! YOU HAVE NOT ENOUGH COUNT !";
                    goto chooseUser;
                }

                if (choose_user == 5 && user_counter < 3) {
                    cout << "\n\n\t\a ! YOU HAVE NOT ENOUGH COUNT !";
                    goto chooseUser;
                }

                if (choose_user == 2 && user_Power_count == i - 2) {
                    cout << "\n\n\t YOU CAN'T USE POWER ATTACK CONSECUTIVLY - CHOOSE ANOTHER ONE !!!";
                    goto chooseUser;
                }
                
                if (choose_user == 3 || choose_user == 4) {
                    cout << "\n\n\t YOU CAN NOT DEFEND - YOU ARE AN ATTACKER NOW !!! ";
                    goto chooseUser;
                }
                else if (choose_user == 1 && choose_computer == 3) {
                    cout << "\n\n\t --------> NORMAL ATTACK to : Computer ";
                    cout << "\n\t         -]   DEFEND to : " << user_name;
                    computer_live -= user_power / 2.0;
                    user_counter++;
                }
                else if (choose_user == 1 && choose_computer == 4 && computer_DefAtt_count != i - 2) {
                    cout << "\n\n\t --------> NORMAL ATTACK to : Computer ";
                    cout << "\n\t     -] ----> DEFEND AND ATTACK to : " << user_name;
                    computer_live -= user_power / 2.0;
                    user_live -= computer_power / 3.0;
                }
                else if (choose_user == 1 && choose_computer == 5) {
                    cout << "\n\n\t --------> NORMAL ATTACK to : Computer ";
                    cout << "\n\t      [^]  TAKE LIVE to : Computer ";
                    computer_live -= user_power;
                    computer_live += (computer_live * (3.0 / 10.0));
                    user_counter++;
                    computer_counter -= 3;
                }
                else if (choose_user == 2 && choose_computer == 3 && user_Power_count != i - 2 ) {
                    cout << "\n\n\t --------> POWERFUL ATTACK to : Computer ";
                    cout << "\n\t         -]   DEFEND to : " << user_name;
                    computer_live -= user_power;
                    user_counter++;
                }
                else if (choose_user == 2 && choose_computer == 4 && user_Power_count != i - 2 && computer_DefAtt_count != i - 2) {
                    cout << "\n\n\t --------> POWERFUL ATTACK to : Computer ";
                    cout << "\n\t     -] ----> DEFEND AND ATTACK to : " << user_name;
                    computer_live -= user_power;
                    user_live -= computer_power / 3.0;
                    user_counter++;
                }
                else if (choose_user == 2 && choose_computer == 5 && user_Power_count != i - 2) {
                    cout << "\n\n\t --------> POWERFUL ATTACK to : Computer ";
                    cout << "\n\t      [^]  TAKE LIVE to : Computer ";
                    computer_live -= user_power*2;
                    computer_live += (computer_live * (3.0 / 10.0));
                    user_counter++;
                    computer_counter -= 3;
                }
                else if (choose_user == 5 && choose_computer == 3) {
                    cout << "\n\t      [^]  TAKE LIVE to : " << user_name;
                    cout << "\n\t         -]   DEFEND to : " << user_name;
                    user_live += (user_live * (3.0 / 10.0));
                    user_counter -= 3;
                }
                else if (choose_user == 5 && choose_computer == 4 && computer_DefAtt_count != i - 2) {
                    cout << "\n\t      [^]  TAKE LIVE to : " << user_name;
                    cout << "\n\t     -] ----> DEFEND AND ATTACK to : " << user_name;
                    user_live += (user_live * (3.0 / 10.0));
                    user_live -= computer_power / 3.0;
                    user_counter -= 3;
                }
                else if (choose_user == 5 && choose_computer == 5) {
                    cout << "\n\t      [^]  TAKE LIVE to : " << user_name;
                    cout << "\n\t      [^]  TAKE LIVE to : Computer ";
                    user_live += (user_live * (3.0 / 10.0));
                    computer_live += (computer_live * (3.0 / 10.0));
                    user_counter -= 3;
                    computer_counter -= 3;
                }
                else if (choose_user == 6 && choose_computer == 3) {
                    cout << "\n\t <<------ XoX ------>> MAGIC POWER to : Computer";
                    cout << "\n\t         -]   DEFEND to : " << user_name;
                    computer_live -= user_power * 2.0;
                    user_counter -= 3;
                }
                else if (choose_user == 6 && choose_computer == 4 && computer_DefAtt_count != i - 2) {
                    cout << "\n\t <<------ XoX ------>> MAGIC POWER to : Computer";
                    cout << "\n\t     -] ----> DEFEND AND ATTACK to : " << user_name;
                    computer_live -= user_power * 2.0;
                    user_live -= computer_power / 4.0;
                    user_counter -= 3;
                }
                else if (choose_user == 6 && choose_computer == 5) {
                    cout << "\n\t <<------ XoX ------>> MAGIC POWER to : Computer";
                    cout << "\n\t      [^]  TAKE LIVE to : Computer ";
                    computer_live -= user_power * 3.0;
                    computer_live += (computer_live * (3.0 / 10.0));
                    user_counter -= 2;
                    computer_counter -= 3;
                }
                else {
                    cout << "\n\n\t\a YOU ENTERED INVALID CHOOSE FOR THIS STAGE !!!";
                    goto chooseUser;
                }

                if (choose_user == 2) {
                    user_Power_count = i;
                }
                else {
                    user_Power_count -= 1;
                }

                if (choose_computer == 4) {
                    computer_DefAtt_count = i;
                }
                else {
                    computer_DefAtt_count -= 1;
                }

                system("timeout /t 3 > nul");
                system("cls");

                cout << " \n\n\t  -------------- STAGE " << i+1 << " ---------------- "
                    "\n\n\t" << user_name << " : ";
                bar_Hesaplama(user_live);
                cout << "\t " << user_name << " Count = " << user_counter;
                cout << "\n\n\tCOMPUTER : ";
                bar_Hesaplama(computer_live);
                cout << "\t Computer Count = " << computer_counter; 
                cout << "\n\n\t ---------------------------------------------------- ";

                if (user_live <= 0) {
                    cout << "\n\n\t COMPUTER IS WINNER !!!";
                    break;
                } else if (computer_live <= 0){
                    cout << "\n\n\t " << user_name << " IS WINNER !!!";
                    break;
                }

            }
            else if ( i % 2 == 1 ){ 

                cout << "\n\n\t !!! WARNING !!! "
                    "\n\t 1 -) Common Attack "
                    "\n\t 2 -) Powerful Attack "
                    "\n\t 3 -) Defend"
                    "\n\t 4 -) Against Attack "
                    "\n\t 5 -) Take Live "
                    "\n\t 6 -) USE MAGIC POWER ";
                
                cout << "\n\n\t ------------ STATE " << i + 1 << " ----------- \n\n\t ATTACKER > Computer";
                cout << "\n\t DEFENDER > " << user_name;

                choose_computer = 1 + rand() % 6;

            chooseUser2:

                cout << "\n\n\t > CHOOSE YOUR MOVE ( only 3 / 4 / 5 ) : ";
                cin >> choose_user;

                if (choose_user == 5 && user_counter < 3) {
                    cout << "\n\n\t\a ! YOU HAVE NOT ENOUGH COUNT !";
                    goto chooseUser2;
                }

                if (choose_user == 4 && user_DefAtt_count == i - 2) {
                    cout << "\n\n\t\a ! YOU CAN NOT USE AGAINST ATTACK CONSECUTIVELY - ENTER ANOTHER ONE ! ";
                    goto chooseUser2;
                }

                while (choose_computer == 3 || choose_computer == 4 ||
                    (choose_computer == 5 && computer_counter < 3) ||
                    (choose_computer == 6 && computer_counter < 3) ||
                    (choose_computer == 2 && computer_Power_count == i - 2)) {

                    choose_computer = 1 + rand() % 6; 

                }

                if (computer_counter >= 3) {
                    choose_computer = 6;
                }

                if (choose_user == 1 || choose_user == 2 || choose_user == 6) {
                    cout << "\n\n\t\a YOU ENTERED INVALID CHOOSE - YOU A DEFENDER NOW !!!";
                    goto chooseUser2;
                }
                else if (choose_computer == 1  && choose_user == 3) {
                    cout << "\n\n\t --------> NORMAL ATTACK to : " << user_name;
                    cout << "\n\t         -]   DEFEND to : Computer ";
                    user_live -= computer_power / 2.0;
                    computer_counter++;
                }
                else if (choose_computer == 1 && choose_user == 4 && user_DefAtt_count != i - 2) {
                    cout << "\n\n\t --------> NORMAL ATTACK to : " << user_name;
                    cout << "\n\t     -] ----> DEFEND AND ATTACK to : Computer ";
                    user_live -= (computer_power / 2.0);
                    computer_live -= (user_power / 3.0);
                }
                else if (choose_computer == 1 && choose_user == 5) {
                    cout << "\n\n\t --------> NORMAL ATTACK to : " << user_name;
                    cout << "\n\t      [^]  TAKE LIVE to : " << user_name;
                    user_live -= computer_power;
                    user_live += (user_live * (3.0 / 10.0));
                    computer_counter++;
                    user_counter -= 3;
                }
                else if (choose_computer == 2 && choose_user == 3 && computer_Power_count != i - 2) {
                    cout << "\n\n\t --------> POWERFUL ATTACK to : " << user_name;
                    cout << "\n\t         -]   DEFEND to : Computer ";
                    user_live -= computer_power;
                    computer_counter++;
                }
                else if (choose_computer == 2 && choose_user == 4 && computer_Power_count != i - 2 && user_DefAtt_count != i - 2) {
                    cout << "\n\n\t --------> POWERFUL ATTACK to : " << user_name;
                    cout << "\n\t     -] ----> DEFEND AND ATTACK to : Computer ";
                    user_live -= computer_power;
                    computer_counter++;
                    computer_live -= (user_power / 3.0);
                }
                else if (choose_computer == 2 && choose_user == 5 && computer_Power_count != i - 2) {
                    cout << "\n\n\t --------> POWERFUL ATTACK to : " << user_name;
                    cout << "\n\t      [^]  TAKE LIVE to : " << user_name;
                    user_live -= computer_power;
                    user_live += (user_live * (3.0 / 10.0));
                    computer_counter++;
                    user_counter -= 3;
                }
                else if (choose_computer == 5 && choose_user == 3) {
                    cout << "\n\t      [^]  TAKE LIVE to : Computer ";
                    cout << "\n\t         -]   DEFEND to : Computer ";
                    computer_live += (computer_live * (3.0 / 10.0));
                    computer_counter -= 3;
                }
                else if (choose_computer == 5 && choose_user == 4 && user_DefAtt_count != i - 2) {
                    cout << "\n\t      [^]  TAKE LIVE to : Computer ";
                    cout << "\n\t     -] ----> DEFEND AND ATTACK to : Computer ";
                    computer_live += (computer_live * (3.0 / 10.0));
                    computer_live -= user_power / 3.0;
                    computer_counter -= 3;
                }
                else if (choose_computer == 5 && choose_user == 5) {
                    cout << "\n\t      [^]  TAKE LIVE to : Computer ";
                    cout << "\n\t      [^]  TAKE LIVE to : " << user_name;
                    computer_live += (computer_live * (3.0 / 10.0));
                    user_live += (user_live * (3.0 / 10.0));
                    computer_counter -= 3;
                    user_counter -= 3;
                }
                else if (choose_computer == 6 && choose_user == 3) {
                    cout << "\n\t <<------ XoX ------>> MAGIC POWER to : " << user_name;
                    cout << "\n\t         -]   DEFEND to : Computer ";
                    user_live -= computer_power * 2.0;
                    computer_counter -= 3;
                }
                else if (choose_computer == 6 && choose_user == 4 && user_DefAtt_count != i - 2) {
                    cout << "\n\t <<------ XoX ------>> MAGIC POWER to : " << user_name;
                    cout << "\n\t     -] ----> DEFEND AND ATTACK to : Computer ";
                    user_live -= computer_power * 2.0;
                    computer_live -= user_power / 4.0;
                    computer_counter -= 3;
                }
                else if (choose_computer == 6 && choose_user == 5) {
                    cout << "\n\t <<------ XoX ------>> MAGIC POWER to : " << user_name;
                    cout << "\n\t      [^]  TAKE LIVE to : " << user_name;
                    user_live -= computer_power * 3.0;
                    user_live += (user_live * (3.0 / 10.0));
                    computer_counter -= 2;
                    user_counter -= 3;
                }
                else {
                    cout << "\n\n\t\a YOU ENTERED INVALID CHOOSE FOR THIS STAGE !!!";
                    goto chooseUser2;
                }

                if (choose_computer == 2) {
                    computer_Power_count = i;
                }
                else {
                    computer_Power_count -= 1;
                }

                if (choose_user == 4) {
                    user_DefAtt_count = i;
                }
                else {
                    user_DefAtt_count -= 1;
                }

                system("timeout /t 3 > nul");
                system("cls");

                cout << " \n\n\t  -------------- STAGE " << i + 1 << " ---------------- "
                    "\n\n\t" << user_name << " : ";
                bar_Hesaplama(user_live);
                cout << "\t " << user_name << " Count = " << user_counter;
                cout << "\n\n\tCOMPUTER : ";
                bar_Hesaplama(computer_live);
                cout << "\t Computer Count = " << computer_counter;
                cout << "\n\n\t ---------------------------------------------------- ";

                if (user_live <= 0) {
                    cout << "\n\n\t COMPUTER IS WINNER !!!";
                    break;
                }
                else if (computer_live <= 0) {
                    cout << "\n\n\t " << user_name << " IS WINNER !!!";
                    break;
                }

            }
        }

        if (user_live > 0 && computer_live > 0) {
            cout << "\n\n\t\a < ---- DRAW ---- > ";
        }

        char yesOrNo = 'n';

        system("timeout /t  6 > nul");
        cout << "\n\n\n\t > DO YOU WANT TO PLAY AGAIN ? ( Y/n ) : ";
        cin >> yesOrNo;

        switch (yesOrNo) {
        case 'Y':
            system("cls");
            goto start;
            break;
        case 'y':
            system("cls");
            goto start;
            break;
        case 'N':
            system("exit");
            break;
        case 'n':
            system("exit");
            break;
        }

}

void bar_Hesaplama(double can) {

    int maxLenght = 20;
    int maxLive = 100;

    double dolulukOranı = (double)can / maxLive;
    int dolulukKarakterSayisi = (int)(dolulukOranı * maxLenght);

    if (can > 0 && dolulukKarakterSayisi == 0) {
        dolulukKarakterSayisi = 1;
    }

    if (can == 0) {
        dolulukKarakterSayisi = 0;
    }

    if (can < 0) {
        dolulukKarakterSayisi = 0;
    }

    int bosKarakterSayisi = maxLenght - dolulukKarakterSayisi;

    cout << " [";

    for (int i = 0; i < dolulukKarakterSayisi; i++) {
        cout << "#";
    }

    for (int j = 0; j < bosKarakterSayisi; j++) {
        cout << "-";
    }

    if (can < 0) {
        cout << "] 0 / " << maxLive << " ( 0% )" << endl;
    }
    else {
        cout << "] " << can << " / " << maxLive << " ( " << (dolulukOranı * 100) << "% )" << endl;
    }

}