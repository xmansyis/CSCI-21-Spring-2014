/*
 *PROJECT 2
 *This project will create a box and inside that box exist prizes.  The program allows the user to add
 *prizes, remove prizes, change the box number and box color, view the status of the box and its prizes.  The program
 *will allocate memory to create these prizes(using dynamic array) which the user will interact with.
 *
 *CHEE YEE XIONG
 *Date created: 3-15-14
 *Last date modified: 4-4-14

 *sources: cplusplus.com, programming challenges.
 */

#include "Prize.h"
#include "Box.h"
#include <iostream>
#include <cstdlib> 
#include <string>
using namespace std;
 
/*
 *This is MainMenuDisplay function.  This function display a main menu for the user to choose.
 */
void mainMenuDisplay();

/*
 *This is boxMenuDisplay function.  This function display a box menu for the user to choose.
 */
void boxMenuDisplay();

/*
 *This is prizeMenuDisplay function.  This function display a prize menu for the user to choose.
 */
void prizeMenuDisplay();

/*
 *This is the boxInteraction function.  This function will allow the user to interact with all
 *the options possible for box.  Inside this function, the user can add prizes, remove prizes, change
 *the box color, change the box number, view the prize capacity, and view the prize count.
 */
void boxInteraction();

/*
 *The is prizeInteraction function.  Inside this function, the user can change the prize names,
 *change the prize values, and compare two prizes.
 */
void prizeInteraction();

/*
 *This is clearScreen function.  It create blank lines.
 */
void clearScreen();

/*
 *This is userInput function.  This function takes in the user input(a string) and parse the string.  It 
 *will check for numbers, spaces, and characters from the user input and return a modified user string.
 *@param mode is type string and will be use for parsing in this function.
 *@return string for calculation and comparison in the driver.
 */
string userInput(string mode);

/*
 *This is prizeValue function.  This function will repeat itself if the user did not enter all digits only.
 *@return unsigned int is the new prize value.
 */
unsigned int prizeValue();


/*
 *This is systemPause function.  This function will fake a pause asking user to press enter to continue.
 */
void systemPause();

/*
 *This is runProject_2 function.  This function starts the simulation and control the Main menu options.
 */
void runProject_2();

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

/*
 * This is the program's main function/entry point.
 */
int main(){
    
    runProject_2();
    return 0;
}

void runProject_2(){
    bool endProject_2 = false;
    bool invalidChoiceMessage = false;

    while (endProject_2 == false){
        //clean the screen and display main menu.
        clearScreen();
        mainMenuDisplay();

        if(invalidChoiceMessage == true){
            cout << "Invalid Choice, ";
        }

        cout << "Enter Choice (0-3): ";
        string userChoice = userInput("numbers");

        //user choose to interact with Box.
        if(userChoice == "1"){
            invalidChoiceMessage = false;
            boxInteraction();
        }
        //user choose to interact with Prize
        else if (userChoice == "2"){
            invalidChoiceMessage = false;
            prizeInteraction();
        }
        //unittest option.
        else if (userChoice == "3"){
            invalidChoiceMessage = false;
            unittest();

            systemPause();
        }
        //user wanted to quit
        else if (userChoice == "0"){
            endProject_2 = true;
        }
        else{
            invalidChoiceMessage = true;
        }
    }
    cout << "Program Ended!" << endl;
}
void boxInteraction(){

    Box box_01; 

    bool endBoxInteraction = false;
    bool invalidBoxChoiceMessage = false;
    while(endBoxInteraction == false){
        //clear the screen and display main menu
        clearScreen();
        cout << "========== Box Information ===============\n";
        cout << " Box number = " << box_01.getBoxNumber() << ",  Box color = " << box_01.getBoxColor() << endl << endl;
        boxMenuDisplay();

        if(invalidBoxChoiceMessage == true){
            cout << "Invalid Choice, ";
        }

        cout << "Enter Choice (0-7): ";
        string userChoice = userInput("numbers");
        
        //the user choose option 1 which is to add a prize.
        if(userChoice == "1"){
            if(box_01.getPrizeCount() < 5){
                clearScreen();
                invalidBoxChoiceMessage = false;
                
                //display current prize name and prompt user for a prize name.
                cout << "Prize name (current =\"" << box_01.getPrize(box_01.getPrizeCount()).getPrizeName() << "\"): ";
                string prizeName = userInput("characters");

                bool prizeValueUpdate = false;
                while(prizeValueUpdate == false){
                    //display current value and prompt user for a prize value.
                    cout << "Prize value (current =\"" << box_01.getPrize(box_01.getPrizeCount()).getPrizeValue() << "\"): ";
                    unsigned int newPrizeValue = prizeValue();
                    box_01.addPrize(Prize(prizeName,newPrizeValue));
                    prizeValueUpdate = true;
                    cout << "\nNew prize added.\n\n" << endl;
                    systemPause();
                }
            }
            else{
                cout << "\nYour box is full! Cannot add anymore prizes.\n\n" << endl;
                systemPause();
            }
        }
 
        //the user choose option 2 to view the prizes.
        if(userChoice == "2"){
            invalidBoxChoiceMessage = false;
            clearScreen();

            for(unsigned int i = 0; i < box_01.getPrizeCount(); ++i){
                cout << (i+1) << ": " << box_01.getPrize(i).getPrizeName() << endl;
            }
            cout << endl << endl;
            systemPause();
        }
 
        //the user choose option 3 to remove cargo (prize).
        if(userChoice == "3"){
            invalidBoxChoiceMessage = false;

            //There are no prizes to be remove.
            if(box_01.getPrizeCount() == 0){
                cout << "\n\nNo cargo to be remove, ";
                systemPause();
            }
            //There is at least a prize in the box.
            else{
                bool RemoveItem = false;
                while(RemoveItem == false){
                    clearScreen();
                    for(unsigned int i = 0; i < box_01.getPrizeCount(); ++i){
                        cout << (i+1) << ": " << box_01.getPrize(i).getPrizeName() << endl;
                    }
 
                    //prompt for which cargo(prize) to remove.
                    cout << "\nRemove which prize (0 to cancel)?: ";
                    string removePrize = userInput("numbers");
                    if(removePrize == "1" || removePrize == "2" || removePrize =="3"
                        || removePrize == "4" || removePrize == "5"){

                        unsigned int index = strtoul(removePrize.c_str(),0,10);

                        //removing a prize and display prizes left.
                        if(index <= box_01.getPrizeCount()){
                            box_01.removePrize(index-1);
                            RemoveItem = true;

                            cout << endl;
                            for(unsigned int i = 0; i < box_01.getPrizeCount(); ++i){
                            cout << (i+1) << ": " << box_01.getPrize(i).getPrizeName() << endl;
                            }
                            
                            cout << "\n\nPrize removed, ";
                            systemPause();
                        }
                        else{
                            cout << "\n\nInvalid choice, ";
                            systemPause();
                        }
                    }
                    else if(removePrize == "0"){
                        RemoveItem = true;
                    }
                    else{
                        cout << "\n\nInvalid choice, ";
                        systemPause();
                    }
                }
            }
        }

        //the user choose option 4 to change box number.
        if(userChoice == "4"){
            clearScreen();
            cout << "Box number: " << box_01.getBoxNumber();
            cout << "\n\nUpdate(y/n)?: ";

            bool boxNumberUpdate = false;
            bool invalidChoiceMessage = false;
            while(boxNumberUpdate == false){

                if(invalidChoiceMessage == true){
                    cout << "\nEnter (y or n)?: ";
                }

                string boxNumberChange = userInput("characters");
                //the user enter either yes or no for his/her choice.
                if(boxNumberChange == "Y" || boxNumberChange == "y" || boxNumberChange == "n" || boxNumberChange == "N"){ 
                    
                    //the user choose yes to change box number.
                    if(boxNumberChange == "y" || boxNumberChange == "Y"){
                        
                        bool runBoxNumber = false;
                        while(runBoxNumber == false){
                            cout << "\nEnter new box number: ";
                            string boxNumber = userInput("numbers");
                            
                            if(boxNumber !="invalid"){
                                unsigned int newBoxNumber = strtoul(boxNumber.c_str(),0,10);
                                box_01.setBoxNumber(newBoxNumber);
                                
                                cout << "\n\nBox number updated, ";
                                systemPause();
                                boxNumberUpdate = true;
                                runBoxNumber = true;
                            }
                        }
                    }
                    //the user choose not to change the box number.
                    else{
                        cout << "\nNo update, ";
                        boxNumberUpdate = true;
                        systemPause();
                    }
                }
                invalidChoiceMessage = true;
            }
        }

        //the user choose option 5 to change box color.
        if(userChoice == "5"){
            clearScreen();
            cout << "Box color: " << box_01.getBoxColor();
            cout << "\n\nUpdate(y/n)? ";

            bool boxColorUpdate = false;
            bool invalidChoiceMessage = false;
            while(boxColorUpdate == false){
                if(invalidChoiceMessage == true){
                    cout << "\nEnter (y or n)?: ";
                }

                string boxColorChoice = userInput("characters");
                if(boxColorChoice == "Y" || boxColorChoice == "y" || boxColorChoice == "n" || boxColorChoice == "N"){
                    
                    //the user wanted to change the box color.
                    if(boxColorChoice == "Y" || boxColorChoice == "y"){
                        cout << "\nEnter box color: ";
                        string newColor = userInput("characters");

                        box_01.setBoxColor(newColor);
                        cout << "\n\nBox number updated, ";
                        boxColorUpdate = true;
                        systemPause();
                    }
                    //the user is not changing the box color.
                    else{
                        cout << "\n\nNo color update, ";
                        systemPause();
                        boxColorUpdate = true;
                    }
                }
                else{
                    invalidChoiceMessage = true;
                }
            }
        }

        //the user want to see the prize capacity.
        if(userChoice == "6"){
            clearScreen();
            cout << "Box prize capacity: " << box_01.getPrizeCapacity();
            cout << endl << endl << endl;
            systemPause();
        }

        //the user want to see the prize count.
        if(userChoice == "7"){
            clearScreen();
            cout << "Box prize count: " << box_01.getPrizeCount();
            cout << endl << endl << endl;
            systemPause();
        }
        
        if(userChoice == "0"){
             endBoxInteraction = true;
        }
    }
}
void prizeInteraction(){

    Prize prize_01;
    Prize prize_02;

    bool quitPrizeInteraction = false;
    while(quitPrizeInteraction == false){
        clearScreen();
        cout << "========== Prize Information ===========\n";
        cout << "Prize name = " << prize_01.getPrizeName() << ",   Prize value = "  << prize_01.getPrizeValue() << endl << endl;
        prizeMenuDisplay();

        cout << "Enter Choice (0-3): ";
        string userChoice = userInput("numbers");
        
        //the user choose option 1 to change prize name.
        if(userChoice == "1"){
            clearScreen();
            cout << "Prize name = " << prize_01.getPrizeName() << endl << endl;

            bool prizeNameUpdate = false;
            while(prizeNameUpdate == false){
                cout << "\nUpdate prize name? (y/n): ";
                string userPrizeNameChoice = userInput("characters");

                //the user enter either yes or no.
                if(userPrizeNameChoice == "Y" || userPrizeNameChoice == "y" ||userPrizeNameChoice == "N" || userPrizeNameChoice == "n"){

                    //the user choose yes to change prize name.
                    if(userPrizeNameChoice == "Y" || userPrizeNameChoice == "y"){
                        cout << "\nPlease enter new prize name: ";
                        userPrizeNameChoice = userInput("characters");
                        prize_01.setPrizeName(userPrizeNameChoice);
                        cout << "\n\nPrize name upated, ";
                        prizeNameUpdate = true;
                        systemPause();
                        
                    }
                    //the user choose not to change prize name;
                    else{
                        cout << "\n\nNo prize name update, ";
                        prizeNameUpdate = true;
                        systemPause();
                    }
                }
            } 
        }
        //the user choose option 2 to change prize value.
        else if(userChoice == "2"){
            clearScreen();
            cout << "Prize value = " << prize_01.getPrizeValue() << endl << endl;
 
            bool prizeValueUpdate = false;
            while(prizeValueUpdate == false){
                cout << "\nUpdate prize value? (y/n)?: ";
                string userPrizeValueUpdate = userInput("characters");

                if(userPrizeValueUpdate == "Y" || userPrizeValueUpdate == "y" || userPrizeValueUpdate == "n" || userPrizeValueUpdate == "N"){

                    //user choose to change prize value.
                    if(userPrizeValueUpdate == "Y" || userPrizeValueUpdate == "y"){
                        unsigned int newPrizeValue = prizeValue();
                        prize_01.setPrizeValue(newPrizeValue);
                                
                        cout << "\n\nPrize value updated, ";
                        prizeValueUpdate = true;
                        systemPause();
                    }
                    else{
                        cout << "\n\nPrize value not update, ";
                        prizeValueUpdate = true;
                        systemPause();
                    }
                }
            }
        }
        //user want to compare two prizes.
        else if(userChoice == "3"){
            clearScreen();
            cout << "First, set the values for the data members of the two prizes.\n\n";
            cout << "Prize 1 ->" << endl;
            cout << "Prize name (current=\"" << prize_01.getPrizeName() << "\"): ";
            
            //setting prize 1 name.
            string userPrizeName = userInput("characters");
            prize_01.setPrizeName(userPrizeName);
            
            bool prizeValueUpdate = false;
            while(prizeValueUpdate == false){
                cout << "Prize value (current=\"" << prize_01.getPrizeValue() << "\"): ";
                unsigned int newPrizeValue = prizeValue();
                prize_01.setPrizeValue(newPrizeValue);
                prizeValueUpdate = true;
            }

            cout << "\nPrize 2 ->" << endl;
            cout << "Prize name (current=\"" << prize_02.getPrizeName() << "\"): ";
            
            //setting prize 2 name.
            userPrizeName == userInput("characters");
            prize_02.setPrizeName(userPrizeName);
            
            prizeValueUpdate = false;
            while(prizeValueUpdate == false){
                cout << "Prize value (current=\"" << prize_02.getPrizeValue() << "\"): ";
                unsigned int newPrizeValue = prizeValue();
                prize_02.setPrizeValue(newPrizeValue);
                prizeValueUpdate = true;
            }
            
            if(prize_02 == prize_01)
                cout << "\n\nThe two prizes are the same.\n\n";
            else
                cout << "\n\nThe two prizes are not the same.\n\n";
            
                systemPause();

        }
        else if(userChoice == "0")
            quitPrizeInteraction = true;
        else
            cout << endl;
    }
}

string userInput(string mode){
    string userInput;
    getline(cin,userInput);

    if(mode == "characters"){
        return userInput;
    }

    for(unsigned int i = 0 ; i < userInput.size(); ++i){
        if(isspace(userInput[i])){
            userInput = userInput.erase(i,userInput.size());
        }
    }

    if(mode == "numbers"){
        for(unsigned int i = 0; i < userInput.size(); ++i){
            if(!isdigit(userInput[i])){
                userInput = "invalid";
            }
        }
    }

    if(userInput == "\n" || userInput ==""){
        userInput = "invalid";
    }

    return userInput;
}

unsigned int prizeValue(){
    bool prizeValueChange = false;
    while(prizeValueChange == false){
        cout << "Enter new prize value: ";
        string prizeValue = userInput("numbers");
                            
        if(prizeValue !="invalid"){ 
            unsigned int newPrizeValue = strtoul(prizeValue.c_str(),0,10);
            return newPrizeValue;
            prizeValueChange = true;
        }
    }
    return prizeValueChange;
}

void mainMenuDisplay(){
    cout << "========== MAIN MENU ===============\n\n";
    cout << " [1] Box -- interactive test" << endl;
    cout << " [2] Prize -- interactive test" << endl;
    cout << " [3] Run official unit test" << endl;
    cout << " [0] Quit" << endl << endl;
}

void boxMenuDisplay(){
    cout << " [1] Add prize" << endl;
    cout << " [2] View prizes" << endl;
    cout << " [3] Remove cargo" << endl;
    cout << " [4] Box number" << endl;  
    cout << " [5] Box color" << endl;
    cout << " [6] View prize capacity" << endl;
    cout << " [7] View prize count" << endl;
    cout << " [0] Back to main menu" << endl << endl;
} 

void prizeMenuDisplay(){
    cout << "[1] Prize name" << endl;
    cout << "[2] Prize value" << endl;
    cout << "[3] compare two prizes" << endl;
    cout << "[0] Back to main menu" << endl << endl;
}

void clearScreen(){
    cout << string(75,'\n');
}

void systemPause(){
    cout << "Press enter to continue.";
    string dummy;
    getline(cin,dummy);
}

/* 
 * Unit testing functionb1. Do not alter.
 */

void unittest ()
{
    cout << "\nSTARTING UNIT TEST\n\n";
	
    Box b1; 
    Box b2(42, "blue", 3);
	
    cout << b2.getPrizeCount();
    cout << "** TESTING DEFAULT BOX **\n\n";
	
    try {
        btassert<bool>(b1.getBoxNumber() == 0);
        cout << "Passed TEST 1: Box getBoxNumber()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 1 Box getBoxNumber() #\n";
    }
	
    try {
        btassert<bool>(b1.getBoxColor() == "NO COLOR");
        cout << "Passed TEST 2: Box getBoxColor()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 2 Box getBoxColor() #\n";
    }
    
    try {
        btassert<bool>(b1.getPrizeCapacity() == 5);
        cout << "Passed TEST 3: Box getPrizeCapacity()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 3 Box getPrizeCapacity() #\n";
    }
	
    try {
        btassert<bool>(b1.getPrizeCount() == 0);
        cout << "Passed TEST 4: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 4 Box getPrizeCount() #\n";
    }
	
    b1.setBoxNumber(99);
    try {
        btassert<bool>(b1.getBoxNumber() == 99);
        cout << "Passed TEST 5: Box setBoxNumber()/getBoxNumber()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 5 Box setBoxNumber()/getBoxNumber() #\n";
    }
	
    b1.setBoxColor("red");
    try {
        btassert<bool>(b1.getBoxColor() == "red");
        cout << "Passed TEST 6: Box setBoxColor()/getBoxColor()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 6 Box setBoxColor()/getBoxColor() #\n";
    }
    
    cout << "\n** TESTING CUSTOM BOX **\n\n";
	
    try {
        btassert<bool>(b2.getBoxNumber() == 42);
        cout << "Passed TEST 7: Box getBoxNumber()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 7 Box getBoxNumber() #\n";
    }
	
    try {
        btassert<bool>(b2.getBoxColor() == "blue");
        cout << "Passed TEST 8: Box getBoxColor()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 8 Box getBoxColor() #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCapacity() == 3);
        cout << "Passed TEST 9: Box getPrizeCapacity()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 9 Box getPrizeCapacity() #\n";
    }
	 
    try {
        btassert<bool>(b2.getPrizeCount() == 0);
        cout << "Passed TEST 10: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 10 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(0) == Prize());
        cout << "Passed TEST 11: Box getPrize(0)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 11 Box getPrize(0) #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(0) == Prize());
        cout << "Passed TEST 12: Box removePrize(0)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 12 Box removePrize(0) #\n";
    }
    
    b2.addPrize(Prize("BRONZE PRIZE", 1));
    try {
        btassert<bool>(b2.getPrizeCount() == 1);
        cout << "Passed TEST 13: Box addPrize()/getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 13 Box addPrize()/getPrizeCount() #\n";
    }
      
    b2.addPrize(Prize("SILVER PRIZE", 100));
    try {
        btassert<bool>(b2.getPrizeCount() == 2);
        cout << "Passed TEST 14: Box addPrize()/getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 14 Box addPrize()/getPrizeCount() #\n";
    }  
          
    b2.addPrize(Prize("GOLD PRIZE", 1000));
    try {
        btassert<bool>(b2.getPrizeCount() == 3);
        cout << "Passed TEST 15: Box addPrize()/getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 15 Box addPrize()/getPrizeCount() #\n";
    }
    
    try { 
        btassert<bool>(b2.addPrize(Prize("DIAMOND PRIZE", 999)) == false);
        cout << "Passed TEST 16: Box addPrize(ARRAY FULL)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 16 Box addPrize(ARRAY FULL) #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(1) == Prize("SILVER PRIZE", 100));
        cout << "Passed TEST 17: Box getPrize(1)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 17 Box getPrize(1) #\n";
    }
     
    try {
        btassert<bool>(b2.removePrize(2) == Prize("GOLD PRIZE", 1000));
        cout << "Passed TEST 18: Box removePrize(2)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 18 Box removePrize(2) #\n";
    }
        
    try {
        btassert<bool>(b2.getPrizeCount() == 2);
        cout << "Passed TEST 19: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 19 Box getPrizeCount() #\n";
    }  
	 
    try {
        btassert<bool>(b2.removePrize(2) == Prize());
        cout << "Passed TEST 20: Box removeCargo(2)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 20 Box removeCargo(2) #\n";
    }
	   
    try {
        btassert<bool>(b2.getPrize(2) == Prize());
        cout << "Passed TEST 21: Box getPrize(2)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 21 Box getPrize(2) #\n";
    }
	   
    try {
        btassert<bool>(b2.addPrize(Prize("RUBY PRIZE", 9999)) == true);
        cout << "Passed TEST 22: Box addPrize(\"RUBY PRIZE\", 9999)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 22 Box addPrize(\"RUBY PRIZE\", 9999) #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCount() == 3);
        cout << "Passed TEST 23: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 23 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrizeCapacity() == 3);
        cout << "Passed TEST 24: Box getPrizeCapacity()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 24 Box getPrizeCapacity() #\n";
    } 
	
    cout << "\n** TESTING PRIZE **\n\n";
	  
    Prize p1;
	
    try {
        btassert<bool>(p1.getPrizeName() == "NO NAME");
        cout << "Passed TEST 25: Prize getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 25 Prize getPrizeName() #\n";
    }
	
    try {
        btassert<bool>(p1.getPrizeValue() == 0);
        cout << "Passed TEST 26: Prize getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 26 Prize getPrizeValue() #\n";
    }
	
    p1.setPrizeName("FOOD PRIZE");
    try {
        btassert<bool>(p1.getPrizeName() == "FOOD PRIZE");
        cout << "Passed TEST 27: Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 27 Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName() #\n";
    }
	
    p1.setPrizeValue(17);
    try {
        btassert<bool>(p1.getPrizeValue() == 17);
        cout << "Passed TEST 28: Prize setPrizeValue(17)/getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 28 Prize setPrizeValue(17)/getPrizeValue() #\n";
    }
	
    Prize p2("HAT PRIZE", 50);
	
    try {
        btassert<bool>(p2.getPrizeName() == "HAT PRIZE");
        cout << "Passed TEST 29: Prize getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 29 Prize getPrizeName() #\n";
    }
	
    try {
        btassert<bool>(p2.getPrizeValue() == 50);
        cout << "Passed TEST 30: Prize getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 30 Prize getPrizeValue() #\n";
    }
    
    try {
        btassert<bool>(!(p1 == p2));
        cout << "Passed TEST 31: !(Prize == Prize)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 31 !(Prize == Prize) #\n";
    }
    
    p2.setPrizeName("FOOD PRIZE");
    try {
        btassert<bool>(p2.getPrizeName() == "FOOD PRIZE");
        cout << "Passed TEST 32: Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 32 Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName() #\n";
    }
	
    p2.setPrizeValue(17);
    try {
        btassert<bool>(p2.getPrizeValue() == 17);
        cout << "Passed TEST 33: Prize setPrizeValue(17)/getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 33 Prize setPrizeValue(17)/getPrizeValue() #\n";
    }
    
    try {
        btassert<bool>(p1 == p2);
        cout << "Passed TEST 34: (Prize == Prize)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 34 (Prize == Prize) #\n";
    }
    
    p2.setPrizeValue(1);
    try {
        btassert<bool>(!(p1 == p2));
        cout << "Passed TEST 35: !(Prize == Prize)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 35 !(Prize == Prize) #\n";
    }
	
    cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
        throw X();
}