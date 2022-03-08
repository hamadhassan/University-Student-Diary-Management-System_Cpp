#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;
#pragma region
// Version 04 is developed with the concept of Conditional statments, Functions, loops, Arrays and File Handling...
// ****************** FUNCTION PROTOTYPE ******************
void header();         // header function
void header_Welcome(); // welocme header function
char admin_HomeMenu(); // admin menu function
void hold_Option();    // hold the display
//****************** SECURITY FUNCTION ******************
int checkuser(string user_name, string pass_word);                   // check the user record is existing or not
bool check_Existing(string username_check);                          // to make username unique
int checkuser_agent(string agent_user_name, string agent_pass_word); // check the user record is existing or not
bool check_Existing_agent(string agent_username_check);              // to make username unique
//****************** RECOMMENDATIOM ******************
void admin_Recommendation(); // It will give recommendation to the user
//****************** ADMIN FUNCTION ******************
void admin_0Profile(int indexValue);             // admin option
void admin_1WalletStatus();                      // admin option
void admin_2ExpensesReport();                    // admin option
void admin_2ExpensesReportToday();               // admin option
void admin_2ExpensesReportMonthly();             // admin option
void admin_2ExpensesReportYearly();              // admin option
void admin_3AcademicFee();                       // admin option
void admin_4Hostel();                            // admin option
void admin_4Hostel_1Meal();                      // admin option
void admin_4Hostel_1Meal_1Breakfast();           // admin option
void admin_4Hostel_1Meal_2Lunch();               // admin option
void admin_4Hostel_1Meal_3Dinner();              // admin option
void admin_4Hostel_2MealChargesMonthly();        // admin option
void admin_4Hostel_3LivingChargesMonthly();      // admin option
void admin_4Hostel_4ServiceChargesMonthly();     // admin option
void admin_4Hostel_5RenovationChargesMonthly();  // admin option
void admin_4Hostel_6LaundryChargesMonthly();     // admin option
void admin_4Hostel_7BarberChargesMonthly();      // admin option
void admin_5HelpingMaterial();                   // admin option
void admin_5HelpingMaterial_1Notes();            // admin option
void admin_5HelpingMaterial_2Register();         // admin option
void admin_5HelpingMaterial_3Stationary();       // admin option
void admin_6RecreationalExpenses();              // admin option
void admin_6RecreationalExpenses_1Friends();     // admin option
void admin_6RecreationalExpenses_2Family();      // admin option
void admin_7CommunityFund();                     // admin option
void admin_7CommunityFund_1Class();              // admin option
void admin_7CommunityFund_2Societies();          // admin option
void admin_8Goals();                             // admin option
void admin_8Goals_1Daily();                      // admin option
void admin_8Goals_2Weekly();                     // admin option
void admin_8Goals_3Monthly();                    // admin option
void admin_8Goals_4Yearly();                     // admin option
void admin_9CellPhone();                         // admin option
void admin_9CellPhone_1Call();                   // admin option
void admin_9CellPhone_2Internet();               // admin option
void admin_9CellPhone_3Message();                // admin option
void admin_10Book();                             // admin option
void admin_10Book_1Borrow();                     // admin option
void admin_10Book_2Purchase();                   // admin option
void admin_11SelfMotivational();                 // admin option
void admin_11SelfMotivational_1FiveTimePrayer(); // admin option
void admin_11SelfMotivational_2Quran_e_Pak();    // admin option
void admin_11SelfMotivational_3Durood_e_Pak();   // admin option
void admin_12Transport();                        // admin option
void admin_12Transport_1Uber();                  // admin option
void admin_12Transport_2Bus();                   // admin option
void admin_13RecreationalActivities();           // admin option
void admin_13RecreationalActivities_1Sporties(); // admin option
void admin_13RecreationalActivities_2Socities(); // admin option
void admin_14Achievments();                      // admin option
void admin_14Achievments_1CoCurricular();        // admin option
void admin_14Achievments_2ExtraCurricular();     // admin option
void admin_15ResultGrades();                     // admin option
void admin_16GoldenLines();                      // admin option
void admin_17LifelongEvents();                   // admin option
void admin_18Notes();                            // admin option
void admin_19CreateAgentAccount();               // admin option
//****************** ADMIN FUNCTION EXPLANATION ******************
string admin_Menu();                   // admin, menu function
char admin_ExpensesReportMenu();       // admin, expenses report menu function
char admin_HostelMenu();               // admin, hostel menu function
char admin_Hostel_MealMenu();          // admin, hostel option of meal menu function
char admin_HelpingMaterialMenu();      // admin, helping material menu function
char admin_RecreationalExpesesMenu();  // admin, recreational expenses menu function
char admin_CommunityFundMenu();        // admin, community fund function
char admin_GoalsMenu();                // admin, goals menu function
char admin_CellPhoneMenu();            // admin, cell phone menu function
char admin_BookMenu();                 // admin, book menu function
char admin_SelfMotivationalMenu();     // admin, self motivational menu function
char admin_TransportMenu();            // admin, transport menu funtion
char admin_RecerationActivitiesMenu(); // admin, recreational activities menu function
char admin_Achievemnets();             // admin, achievments menu function
void display_profile_admin();
//****************** AGENT FUNCTION ******************
void agent_0Profile(int agentindex); // agent option
void agent_1Wallet();                // agent option
void agent_2AcademicReport();        // agent option
void agent_3ExpensesReport();        // agent option
void agent_4MealReport();            // agent option
void agent_5SpiritualTracker();      // agent option
void agent_6AachieventsReport();     // agent option
//****************** AGENT FUNCTION EXPLANATION ******************
string agent_Menu(); // agent, menu function
//****************** ADMIN & AGENT FUNCTION ******************
int personal_Expenses();        // sum of purchase book + academic fee
int hostel_Expenses();          // sum of breakfast + lunch + dinner + mealMonthly + livingMonthly + serviceMonthly + renovationMonthly + laundryMonthly + barbermonthly
int helpingmaterial_Expenses(); // sum of notes + register_ + stationary
int recreational_Expenses();    // sum of friends + family
int communityfund_Expenses();   // sum of classes + socities
int cellphone_Expenses();       // sum of call + internet + message
int transport_Expenses();       // sum of uber + bus
int total_Expenses();           // sum of  personalExpenses + hostelExpenses + helpingmaterialExpenses + recreationalExpenses + communityfundExpenses + cellphoneExpenses + transportExpenses
//********************* SORTING FUNCTION ************************
void sort_academicFee();    // sort academic fee data
void display_academicFee(); // display sorted academic  fee data
void sort_breakfast();      // sort breakfast data
void display_breakfast();   // diplay sorted breakfast data
void sort_lunch();          // sort lunch data
void display_lunch();       // diplay sorted lunch data
void sort_dinner();         // sort dinner data
void display_dinner();      // diplay sorted dinner data
// ****************** FILE HANDLING ******************
string seperateField(string record, int fieldNumber); // file handling, load data
void load_adminSecurityFile();                        // file handling, load data
void load_agentSecurityFile();                        // file handling, load data
void load_agentWalletMoney();                         // file handling, load data
void load_admin3AcadmicFee();                         // file handling, load data
void load_admin_4Hostel_1Meal_1Breakfast();           // file handling, load data
void load_admin_4Hostel_1Meal_2Lunch();               // file handling, load data
void load_admin_4Hostel_1Meal_3Dinner();              // file handling, load data
void load_admin_4Hostel_2MealChargesMonthly();        // file handling, load data
void load_admin_4Hostel_3LivingChargesMonthly();      // file handling, load data
void load_admin_4Hostel_4ServiceChargesMonthly();     // file handling, load data
void load_admin_4Hostel_5RenovationChargesMonthly();  // file handling, load data
void load_admin_4Hostel_6LaundryChargesMonthly();     // file handling, load data
void load_admin_4Hostel_7BarberChargesMonthly();      // file handling, load data
void load_admin_5HelpingMaterial_1Notes();            // file handling, load data
void load_admin_5HelpingMaterial_2Register();         // file handling, load data
void load_admin_5HelpingMaterial_3Stationary();       // file handling, load data
void load_admin_6RecreationalExpenses_1Friends();     // file handling, load data
void load_admin_6RecreationalExpenses_2Family();      // file handling, load data
void load_admin_7CommunityFund_1Class();              // file handling, load data
void load_admin_7CommunityFund_2Societies();          // file handling, load data
void load_admin_8Goals_1Daily();                      // file handling, load data
void load_admin_8Goals_2Weekly();                     // file handling, load data
void load_admin_8Goals_3Monthly();                    // file handling, load data
void load_admin_8Goals_4Yearly();                     // file handling, load data
void load_admin_9CellPhone_1Call();                   // file handling, load data
void load_admin_9CellPhone_2Internet();               // file handling, load data
void load_admin_9CellPhone_3Message();                // file handling, load data
void load_admin_10Book_1Borrow();                     // file handling, load data
void load_admin_10Book_2Purchase();                   // file handling, load data
void load_admin_11SelfMotivational_1FiveTimePrayer(); // file handling, load data
void load_admin_11SelfMotivational_2Quran_e_Pak();    // file handling, load data
void load_admin_11SelfMotivational_3Durood_e_Pak();   // file handling, load data
void load_admin_12Transport_1Uber();                  // file handling, load data
void load_admin_12Transport_2Bus();                   // file handling, load data
void load_admin_13RecreationalActivities_1Sporties(); // file handling, load data
void load_admin_13RecreationalActivities_2Socities(); // file handling, load data
void load_admin_14Achievments_1CoCurricular();        // file handling, load data
void load_admin_14Achievments_2ExtraCurricular();     // file handling, load data
void load_admin_15ResultGrades();                     // file handling, load data
void load_admin_16GoldenLines();                      // file handling, load data
void load_admin_17LifelongEvents();                   // file handling, load data
void load_admin_18Notes();                            // file handling, load data
//****************** VALIDATIONS ******************
float float_Validaion(string about, float variable);
//****************** GLOBAL DATA STRUCTURE *****************
const int length = 20; // lenght of arrays
//****************** SECURITY-ARRAYS ******************
string firstname[length];       // create an account store firstname
string lastname[length];        // create an account store lastname
string username[length];        // create an account store username
string password[length];        // create an account store password
string firstname_Agent[length]; // create an account store firstname
string lastname_Agent[length];  // create an account store lastname
string username_Agent[length];  // create an account store username
string password_Agent[length];  // create an account store password
//****************** ADMIN-ARRAYS ******************
string semesterType[length], challanNo[length], date[length], remarks[length];                                     // academic fee variables , opAdmin >> opAcademicFee
float amountacademic[length];                                                                                      // academic fee variables , opAdmin >> opAcademicFee
string menuBreakfast[length], remarksBreakfast[length];                                                            // meal breakfast charges , opHostel >> opMeal >> opMealBreakfast
float chargesBreakfast[length];                                                                                    // meal breakfast charges , opHostel >> opMeal >> opMealBreakfast
string menuLunch[length], remarksLunch[length];                                                                    // meal lunch charges , opHostel >> opMeal >> opMealLunch
float chargesLunch[length];                                                                                        // meal lunch charges , opHostel >> opMeal >> opMealLunch
string menuDinner[length], remarksDinner[length];                                                                  // meal dinner charges , opHostel >> opMeal >> opMealDinner
float chargesDinner[length];                                                                                       // meal dinner charges , opHostel >> opMeal >> opMealDinner
string monthlyMealExpenses[length], remarksMealExpenses[length];                                                   // monthly meal charges , opHostel >> opMealCharges
float chargesMealMonthly[length];                                                                                  // monthly meal charges , opHostel >> opMealCharges
string monthLivingExpenses[length], remarksLivingExpenses[length];                                                 // monthly living charges , opHostel >> opLivingCharges
float chargesLivingExpenses[length];                                                                               // monthly living charges , opHostel >> opLivingCharges
string monthServiceExpenses[length], remarksServiceExpenses[length];                                               // monthly service charges , opHostel >> opServiceCharges
float chargesServiceMonthly[length];                                                                               // monthly service charges , opHostel >> opServiceCharges
string remarksRenovationExpenses[length];                                                                          // renovation charges , opHostel >> opRenovationCharges
float chargesRenovationMonthly[length];                                                                            // renovation charges , opHostel >> opRenovationCharges
string remarksLaundryExpenses[length];                                                                             // laundry charges , opHostel >> opLaundryCharges
float chargesLaundryMonthly[length];                                                                               // laundry charges , opHostel >> opLaundryCharges
string remarksBarberExpenses[length];                                                                              // barber charges , opHostel >> opBarberCharges
float chargesBarberMonthly[length];                                                                                // barber charges , opHostel >> opBarberCharges
string remarksNotesExpenses[length];                                                                               // notes charges , opHelpingMaterial >> opNotesHelpingMaterial
float chargesNotesMonthly[length];                                                                                 // notes charges , opHelpingMaterial >> opNotesHelpingMaterial
string remarksRegisterExpenses[length];                                                                            // register charges , opHelpingMaterial >> opRegisterHelpingMaterial
float chargesRegisterMonthly[length];                                                                              // register charges , opHelpingMaterial >> opRegisterHelpingMaterial
string remarksStationaryExpenses[length];                                                                          // stationary charges , opHelpingMaterial >> opStationaryHelpingMaterial
float chargesStationaryMonthly[length];                                                                            // stationary charges , opHelpingMaterial >> opStationaryHelpingMaterial
string remarksFriendsRecreationalExpenses[length];                                                                 // friend recreational expenses , opRecreationalExpenses >> opFriendsRecreationalExpenses
float chargesFriendsRecreationalExpenses[length];                                                                  // friend recreational expenses , opRecreationalExpenses >> opFriendsRecreationalExpenses
string remarksFamilyRecreationalExpenses[length];                                                                  // family recreational expenses , opRecreationalExpenses >> opFamilyRecreationalExpenses
float chargesFamilyRecreationalExpenses[length];                                                                   // family recreational expenses , opRecreationalExpenses >> opFamilyRecreationalExpenses
string remarksClassCommunityFund[length];                                                                          // class community fund , opCommunityFund >> opClassCommunityFund
float chargesClassCommunityFund[length];                                                                           // class community fund , opCommunityFund >> opClassCommunityFund
string remarksSocietiesCommunityFund[length];                                                                      // class community fund , opCommunityFund >> opSocietiesCommunityFund
float chargesSocietiesCommunityFund[length];                                                                       // class community fund , opCommunityFund >> opSocietiesCommunityFund
string titleDailyGoals[length], descriptionDailyGoals[length];                                                     // daily goals , opGoals >> opDailyGoals
string titleWeeklyGoals[length], descriptionWeeklyGoals[length];                                                   // weekly goals , opGoals >> opWeeklyGoals
string titleMonthlyGoals[length], descriptionMonthlyGoals[length];                                                 // monthly goals , opGoals >> opMonthlyGoals
string titleYearlyGoals[length], descriptionYearlyGoals[length];                                                   // yearly goals , opGoals >> opYearlyGoals
string nameCallPakage[length], durationCallPakage[length];                                                         // call package , opCellPhone >> opCall_CellPhone
float amountCallPakage[length];                                                                                    // call pacage ,  opCellPhone >> opCall_CellPhone
string nameInternetPakage[length], durationInternetPakage[length];                                                 // internet package , opCellPhone >> opInternet_CellPhone
float amountInternetPakage[length];                                                                                // internet package , opCellPhone >> opInternet_CellPhone
string nameMessagePakage[length], durationMessagePakage[length];                                                   // message package , opCellPhone >> opMessage_CellPhone
float amountMessagePakage[length];                                                                                 // message package , opCellPhone >> opMessage_CellPhone
string titleBorrowBook[length], authorBorrowBook[length], friendnameBorrowBook[length], remarksBorrowBook[length]; // borrow book , opBook >> opBookBorrow
string titlePurchaseBook[length], authorPurchaseBook[length], remarksPurchaseBook[length];                         // purchase book , opBook >> opBookPurchase
float amountPurchaseBook[length];                                                                                  // purchase book , opBook >> opBookPurchase
string five_time_Prayer[length];                                                                                   // five time prayer , opSelfMotivational >> opFiveTimePrayer
string Quran_e_Pak[length];                                                                                        // quran e pak , opSelfMotivational >> opQuran_e_Pak
string Durood_e_Pak[length];                                                                                       // durood e pak , opSelfMotivational >> opDurood_e_Pak
string locationFromUber[length], locationToUber[length], purposeUber[length];                                      // transport uber/cream/bykea , opTransport >> opUberTransport
float amountUber[length];                                                                                          // transport uber/cream/bykea , opTransport >> opUberTransport
string locationFromBus[length], locationToBus[length], purposeBus[length];                                         // transport bus , opTransport >> opBusTransport
float amountBus[length];                                                                                           // transport bus , opTransport >> opBusTransport
float minutiesSporties[length];                                                                                    // sporties recreational activities , opRecreationalActivities >> opSportiesActivities
float minutiesSocieties[length];                                                                                   // societies recreational activities , opRecreationalActivities >> opSocietiesActivities
string purposeSocieties[length];                                                                                   // societies recreational activities , opRecreationalActivities >> opSocietiesActivities
string awardCo_Curricular[length], presentCo_Curricular[length], remarksCo_Curricular[length];                     // achievements co-curricular , opAchievements >> opCoCurricular
string awardExtra_Curricular[length], presentExtra_Curricular[length], remarksExtra_Curricular[length];            //  achievements extra-curricular , opAchievements >> opExtraCurricular
float gpa[length], cgpa[length];                                                                                   // result grades , opResultGrades
string remarksResult[length];                                                                                      // result grades , opResultGrades
string titleGoldenLines[length], descriptionGoldenLines[length];                                                   // golden lines , opGoldenLines
string titleLifelongEvents[length], descriptionLifelongEvents[length];                                             // life long events , opLifelongEvents
string titleNotes[length], descriptionNotes[length];                                                               // notes , opNotes
// ****************** INCREMENT-VARIABLES ******************
int inc_opAddUser = 0;                     // increment in the array index
int inc_opAgentAddUser = 0;                // increment in the array index
int increment_opAcademicFee = 0;           // increment in the array index
int increment_opMealBreakfast = 0;         // increment in the array index
int increment_opMealLunch = 0;             // increment in the array index
int increment_opMealDinner = 0;            // increment in the array index
int increment_opMealCharges = 0;           // increment in the array index
int inc_opLivingCharges = 0;               // increment in the array index
int inc_opServiceCharges = 0;              // increment in the array index
int inc_opRenovationCharges = 0;           // increment in the array index
int inc_opLaundryCharges = 0;              // increment in the array index
int inc_opBarberCharges = 0;               // increment in the array index
int inc_opNotesHelpingMaterial = 0;        // increment in the array index
int inc_opRegisterHelpingMaterial = 0;     // increment in the array index
int inc_opStationaryHelpingMaterial = 0;   // increment in the array index
int inc_opFriendsRecreationalExpenses = 0; // increment in the array index
int inc_opFamilyRecreationalExpenses = 0;  // increment in the array index
int inc_opClassCommunityFund = 0;          // increment in the array index
int inc_opSocietiesCommunityFund = 0;      // increment in the array index
int inc_opDailyGoals = 0;                  // increment in the array index
int inc_opWeeklyGoals = 0;                 // increment in the array index
int inc_opMonthlyGoals = 0;                // increment in the array index
int inc_opYearlyGoals = 0;                 // increment in the array index
int inc_opCall_CellPhone = 0;              // increment in the array index
int inc_opInternet_CellPhone = 0;          // increment in the array index
int inc_opMessage_CellPhone = 0;           // increment in the array index
int inc_opBookBorrow = 0;                  // increment in the array index
int inc_opBookPurchase = 0;                // increment in the array index
int inc_opFiveTimePrayer = 0;              // increment in the array index
int inc_opQuran_e_Pak = 0;                 // increment in the array index
int inc_opDurood_e_Pak = 0;                // increment in the array index
int inc_opUberTransport = 0;               // increment in the array index
int inc_opBusTransport = 0;                // increment in the array index
int inc_opSportiesActivities = 0;          // increment in the array index
int inc_opSocietiesActivities = 0;         // increment in the array index
int inc_opCoCurricular = 0;                // increment in the array index
int inc_opExtraCurricular = 0;             // increment in the array index
int inc_opResultGrades = 0;                // increment in the array index
int inc_opGoldenLines = 0;                 // increment in the array index
int inc_opLifelongEvents = 0;              // increment in the array index
int inc_opNotes = 0;                       // increment in the array index
//****************** ADMIN & AGENT-VARIABLES ******************
float addWalletMoney = 0;   // this used to add money from agent and show in balance
string walletRemarks = " "; // this used to add remarks from agent and show in balance
//****************** Load ******************

/*___________________________________________________
↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ MAIN FUNCTION ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
ـــــــــــــــــــــــــــــــــــــــــــــــــ*/
int main()
{
    load_adminSecurityFile();                        // file handling, load data from files into arrays and variables before running program
    load_agentSecurityFile();                        // file handling, load data from files into arrays and variables before running program
    load_agentWalletMoney();                         // file handling, load data from files into arrays and variables before running program
    load_admin3AcadmicFee();                         // file handling, load data from files into arrays and variables before running program
    load_admin_4Hostel_1Meal_1Breakfast();           // file handling, load data from files into arrays and variables before running program
    load_admin_4Hostel_1Meal_2Lunch();               // file handling, load data from files into arrays and variables before running program
    load_admin_4Hostel_1Meal_3Dinner();              // file handling, load data from files into arrays and variables before running program
    load_admin_4Hostel_2MealChargesMonthly();        // file handling, load data from files into arrays and variables before running program
    load_admin_4Hostel_3LivingChargesMonthly();      // file handling, load data from files into arrays and variables before running program
    load_admin_4Hostel_4ServiceChargesMonthly();     // file handling, load data from files into arrays and variables before running program
    load_admin_4Hostel_5RenovationChargesMonthly();  // file handling, load data from files into arrays and variables before running program
    load_admin_4Hostel_6LaundryChargesMonthly();     // file handling, load data from files into arrays and variables before running program
    load_admin_4Hostel_7BarberChargesMonthly();      // file handling, load data from files into arrays and variables before running program
    load_admin_5HelpingMaterial_1Notes();            // file handling, load data from files into arrays and variables before running program
    load_admin_5HelpingMaterial_2Register();         // file handling, load data from files into arrays and variables before running program
    load_admin_5HelpingMaterial_3Stationary();       // file handling, load data from files into arrays and variables before running program
    load_admin_6RecreationalExpenses_1Friends();     // file handling, load data from files into arrays and variables before running program
    load_admin_6RecreationalExpenses_2Family();      // file handling, load data from files into arrays and variables before running program
    load_admin_7CommunityFund_1Class();              // file handling, load data from files into arrays and variables before running program
    load_admin_7CommunityFund_2Societies();          // file handling, load data from files into arrays and variables before running program
    load_admin_8Goals_1Daily();                      // file handling, load data from files into arrays and variables before running program
    load_admin_8Goals_2Weekly();                     // file handling, load data from files into arrays and variables before running program
    load_admin_8Goals_3Monthly();                    // file handling, load data from files into arrays and variables before running program
    load_admin_8Goals_4Yearly();                     // file handling, load data from files into arrays and variables before running program
    load_admin_9CellPhone_1Call();                   // file handling, load data from files into arrays and variables before running program
    load_admin_9CellPhone_2Internet();               // file handling, load data from files into arrays and variables before running program
    load_admin_9CellPhone_3Message();                // file handling, load data from files into arrays and variables before running program
    load_admin_10Book_1Borrow();                     // file handling, load data from files into arrays and variables before running program
    load_admin_10Book_2Purchase();                   // file handling, load data from files into arrays and variables before running program
    load_admin_11SelfMotivational_1FiveTimePrayer(); // file handling, load data from files into arrays and variables before running program
    load_admin_11SelfMotivational_2Quran_e_Pak();    // file handling, load data from files into arrays and variables before running program
    load_admin_11SelfMotivational_3Durood_e_Pak();   // file handling, load data from files into arrays and variables before running program
    load_admin_12Transport_1Uber();                  // file handling, load data from files into arrays and variables before running program
    load_admin_12Transport_2Bus();                   // file handling, load data from files into arrays and variables before running program
    load_admin_13RecreationalActivities_1Sporties(); // file handling, load data from files into arrays and variables before running program
    load_admin_13RecreationalActivities_2Socities(); // file handling, load data from files into arrays and variables before running program
    load_admin_14Achievments_1CoCurricular();        // file handling, load data from files into arrays and variables before running program
    load_admin_14Achievments_2ExtraCurricular();     // file handling, load data from files into arrays and variables before running program
    load_admin_15ResultGrades();                     // file handling, load data from files into arrays and variables before running program
    load_admin_16GoldenLines();                      // file handling, load data from files into arrays and variables before running program
    load_admin_17LifelongEvents();                   // file handling, load data from files into arrays and variables before running program
    load_admin_18Notes();                            // file handling, load data from files into arrays and variables before running program

    char opMain = ' '; // Main menu options, store user input
    while (true)
    {
        header_Welcome(); // welcome header function  is called
        cout << "Main Menu > Home " << endl;
        cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
        opMain = admin_HomeMenu(); // admin home menu is called
        if (opMain == '1')
        {
            char opLogin; // login option, store user input
            opLogin = ' ';
            while (true)
            {
                header(); // header function is called
                cout << "Main Menu > Login " << endl;
                cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
                cout << "Login As" << endl;
                cout << "   1. Admin " << endl;
                cout << "   2. Agent " << endl;
                cout << "Press 0 to Go Back...";
                cin >> opLogin;
                if (opLogin == '0')
                {
                    break;
                }
                else if (opLogin == '1')
                {
                    string adminUsername, adminPassword; // admin sig-in variable to store username and password
                    header();                            // header function is called
                    cout << "Main Menu > Login > Admin " << endl;
                    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
                    cout << "Sign-In" << endl;
                    cout << "Username : ";
                    cin >> adminUsername;
                    cout << "Password : ";
                    cin >> adminPassword;
                    int index = checkuser(adminUsername, adminPassword); // check the username and password in the array and make descion upon it
                    if (username[index] == adminUsername && password[index] == adminPassword)
                    {
                        string opAdmin = " "; // admin option, store return value of function admin menu
                        while (true)
                        {
                            header(); // header function is called
                            cout << "Main Menu > Admin > Menu " << endl;
                            cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
                            opAdmin = admin_Menu(); // admin menu function is called
                            if (opAdmin == "0")
                            {
                                char opProfile = ' ';
                                while (opProfile != '1')
                                {
                                    admin_0Profile(index); // function called
                                    cout << "Press 0 to go back...";
                                    cin >> opProfile;
                                    if (opProfile == '0')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Incorrect option" << endl;
                                        hold_Option();
                                    }
                                }
                            }
                            else if (opAdmin == "1")
                            {
                                char opWalletStatus = ' '; //// wallet status option, store user input
                                while (opWalletStatus != '1')
                                {
                                    load_agentWalletMoney();
                                    admin_1WalletStatus(); // function called
                                    cout << "Press 0 to go back...";
                                    cin >> opWalletStatus;
                                    if (opWalletStatus == '0')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Incorrect option" << endl;
                                        hold_Option();
                                    }
                                } // end of opWalletStatus option

                            } // end of wallet status option of admin menu option
                            else if (opAdmin == "2")
                            {
                                char opExpensesReport = ' '; // expenses report option , store return value of function admin expenses report
                                while (opExpensesReport != '4')
                                {
                                    admin_2ExpensesReport();                       // function called
                                    opExpensesReport = admin_ExpensesReportMenu(); // admin expenses report function is called
                                    if (opExpensesReport == '0')
                                    {
                                        break;
                                    }
                                    else if (opExpensesReport == '1')
                                    {
                                        char opTodayExpenses = ' '; // today expenses option , store user input
                                        while (opTodayExpenses != '1')
                                        {
                                            admin_2ExpensesReportToday();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opTodayExpenses;
                                            if (opTodayExpenses == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        }
                                    } // end of today expenses report of admin menu option
                                    else if (opExpensesReport == '2')
                                    {
                                        char opExpensesReport = ' '; // monthly expenses option , store user input
                                        while (opExpensesReport != '1')
                                        {
                                            admin_2ExpensesReportMonthly();
                                            cout << "Press 0 to go back...";
                                            cin >> opExpensesReport;
                                            if (opExpensesReport == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop of opExpenses Report

                                    } // end of monthly expense report
                                    else if (opExpensesReport == '3')
                                    {
                                        char opYearExpenses = ' '; // yearly expenses option , store user input
                                        while (opYearExpenses != '1')
                                        {
                                            admin_2ExpensesReportYearly();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opYearExpenses;
                                            if (opYearExpenses == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of yealy expense report

                                    } // end of while loop of opYearExpenses

                                } // end of while loop of opExpensesReport

                            } // end of expenses report option of admin menu option
                            else if (opAdmin == "3")
                            {
                                char opAcademicFee = ' '; // academic fee option , store user input
                                while (opAcademicFee != '1')
                                {
                                    admin_3AcademicFee(); // fimction called
                                    cout << "Press 0 to Go Back...";
                                    cin >> opAcademicFee;
                                    if (opAcademicFee == '0')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Incorrect option" << endl;
                                        hold_Option();
                                    }
                                } // end of while loop of opAcademicFee

                            } // end of academic fee option of admin menu option
                            else if (opAdmin == "4")
                            {
                                char opHostel = ' '; // Hostel option, store return value of hostel menu function
                                while (opHostel != '8')
                                {
                                    admin_4Hostel();
                                    opHostel = admin_HostelMenu(); // hostel menu function is called
                                    if (opHostel == '0')
                                    {
                                        break;
                                    }
                                    else if (opHostel == '1')
                                    {
                                        char opMeal = ' '; // meal option, store return value of admin, hostel option of meal menu function
                                        while (true)
                                        {
                                            admin_4Hostel_1Meal();            // function called
                                            opMeal = admin_Hostel_MealMenu(); // admin, hostel option of meal menu function is called
                                            if (opMeal == '0')
                                            {
                                                break;
                                            }
                                            else if (opMeal == '1')
                                            {
                                                char opMealBreakfast = ' '; // meal breakfast option under meal option, store user input
                                                while (opMealBreakfast != '1')
                                                {
                                                    admin_4Hostel_1Meal_1Breakfast();
                                                    cout << "Press 0 to Go Back...";
                                                    cin >> opMealBreakfast;
                                                    if (opMealBreakfast == '0')
                                                    {
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout << "Incorrect option" << endl;
                                                        hold_Option();
                                                    }
                                                } // end of while loop opMealBreakfast

                                            } // end of breakfast option of meal option of hostel option in admin menu option
                                            else if (opMeal == '2')
                                            {
                                                char opMealLunch = ' '; // meal lunch option under meal option, store user input
                                                while (opMealLunch != '1')
                                                {
                                                    admin_4Hostel_1Meal_2Lunch();
                                                    cout << "Press 0 to Go Back...";
                                                    cin >> opMealLunch;
                                                    if (opMealLunch == '0')
                                                    {
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout << "Incorrect option" << endl;
                                                        hold_Option();
                                                    }
                                                } // end of while loop of opMealLunch

                                            } // end of lunch option of meal option of hostel option in admin menu option
                                            else if (opMeal == '3')
                                            {
                                                char opMealDinner = ' '; // meal dinner option under meal option, store user input
                                                while (opMealDinner != '1')
                                                {
                                                    admin_4Hostel_1Meal_3Dinner();
                                                    cout << "Press 0 to Go Back...";
                                                    cin >> opMealDinner;
                                                    if (opMealDinner == '0')
                                                    {
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout << "Incorrect option" << endl;
                                                        hold_Option();
                                                    }
                                                } // end of while loop of opMealDinner

                                            } // end of dinner option of meal option of hostel option in admin menu option

                                        } // end of while loop of opMeal

                                    } // end of meal option of hostel option in admin menu option
                                    else if (opHostel == '2')
                                    {
                                        admin_4Hostel_2MealChargesMonthly();
                                        char opMealCharges = ' '; // monthly meal fee charges  option, store user input
                                        while (opMealCharges != '1')
                                        {

                                            cout << "Press 0 to Go Back...";
                                            cin >> opMealCharges;
                                            if (opMealCharges == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop of opMealCharges

                                    } // end of monthly meal option
                                    else if (opHostel == '3')
                                    {
                                        admin_4Hostel_3LivingChargesMonthly();
                                        char opLivingCharges = ' '; // monthly living fee charges  option, store user input
                                        while (opLivingCharges != '1')
                                        {

                                            cout << "Press 0 to Go Back...";
                                            cin >> opLivingCharges;
                                            if (opLivingCharges == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop of opLivingCharges

                                    } // end of living charges
                                    else if (opHostel == '4')
                                    {
                                        admin_4Hostel_4ServiceChargesMonthly();
                                        char opServiceCharges = ' '; // monthly service charges option, store user
                                        while (opServiceCharges != '1')
                                        {

                                            cout << "Press 0 to Go Back...";
                                            cin >> opServiceCharges;
                                            if (opServiceCharges == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop of opServiceCharges

                                    } // end of service charges of hostel option
                                    else if (opHostel == '5')
                                    {
                                        admin_4Hostel_5RenovationChargesMonthly();
                                        char opRenovationCharges = ' '; /// monthly renovation charges option, store user input
                                        while (opRenovationCharges != '1')
                                        {

                                            cout << "Press 0 to Go Back...";
                                            cin >> opRenovationCharges;
                                            if (opRenovationCharges == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop of opRenovationCharges

                                    } // end of renovation charges of hostel option
                                    else if (opHostel == '6')
                                    {
                                        admin_4Hostel_6LaundryChargesMonthly();
                                        char opLaundryCharges = ' '; // monthly laundry charges option, store user input
                                        while (opLaundryCharges != '1')
                                        {
                                            cin >> opLaundryCharges;
                                            if (opLaundryCharges == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opLaundryCharges

                                    } // end of lundry charges of hostel option
                                    else if (opHostel == '7')
                                    {
                                        admin_4Hostel_7BarberChargesMonthly();
                                        char opBarberCharges = ' '; // barber charges, store user input
                                        while (opBarberCharges != '1')
                                        {

                                            cout << "Press 0 to Go Back...";
                                            cin >> opBarberCharges;
                                            if (opBarberCharges == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of barber charges

                                    } // end of while loop of opBarberCharges

                                } // end of while loop of opHostel

                            } // end of hostel option of admin menu option
                            else if (opAdmin == "5")
                            {
                                char opHelpingMaterial = '1'; // helping material, store return value of admin,helping material menu
                                while (opHelpingMaterial != '4')
                                {
                                    admin_5HelpingMaterial();
                                    opHelpingMaterial = admin_HelpingMaterialMenu(); // admin,helping material menu is called
                                    if (opHelpingMaterial == '0')
                                    {
                                        break;
                                    }
                                    else if (opHelpingMaterial == '1')
                                    {
                                        char opNotesHelpingMaterial = ' '; // notes option  of helping material option, store user input
                                        while (opNotesHelpingMaterial != '1')
                                        {
                                            admin_5HelpingMaterial_1Notes();

                                            cout << "Press 0 to Go Back...";
                                            cin >> opNotesHelpingMaterial;
                                            if (opNotesHelpingMaterial == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opNotesHelpingMaterial

                                    } // end of notes option
                                    else if (opHelpingMaterial == '2')
                                    {
                                        char opRegisterHelpingMaterial = ' '; // register option  of helping material option, store user input
                                        while (opRegisterHelpingMaterial != '1')
                                        {
                                            admin_5HelpingMaterial_2Register();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opRegisterHelpingMaterial;
                                            if (opRegisterHelpingMaterial == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opRegisterHelpingMaterial

                                    } // end of register option
                                    else if (opHelpingMaterial == '3')
                                    {
                                        char opStationaryHelpingMaterial = ' '; // stationary option  of helping material option, store user input
                                        while (opStationaryHelpingMaterial != '1')
                                        {
                                            admin_5HelpingMaterial_3Stationary();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opStationaryHelpingMaterial;
                                            if (opStationaryHelpingMaterial == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opStationaryHelpingMaterial

                                    } // end of stationary option

                                } // end of while loop of opHelpingMaterial

                            } // end of helping material
                            else if (opAdmin == "6")
                            {
                                char opRecreationalExpenses = ' '; // recreational expenses option, store return value of admin,recreational expenses menu
                                while (opRecreationalExpenses != '3')
                                {
                                    admin_6RecreationalExpenses();
                                    opRecreationalExpenses = admin_RecreationalExpesesMenu(); // admin,recreational expenses menu is called
                                    if (opRecreationalExpenses == '0')
                                    {
                                        break;
                                    }
                                    else if (opRecreationalExpenses == '1')
                                    {
                                        char opFriendsRecreationalExpenses = ' '; //  friends recreational expenses option,store user input
                                        while (opFriendsRecreationalExpenses != '1')
                                        {
                                            admin_6RecreationalExpenses_1Friends();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opFriendsRecreationalExpenses;
                                            if (opFriendsRecreationalExpenses == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opFriendsRecreationalExpenses

                                    } // end of  friends recreational expenses option
                                    else if (opRecreationalExpenses == '2')
                                    {
                                        char opFamilyRecreationalExpenses = ' '; //  family recreational expenses option,store user input
                                        while (opFamilyRecreationalExpenses != '1')
                                        {
                                            admin_6RecreationalExpenses_2Family();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opFamilyRecreationalExpenses;
                                            if (opFamilyRecreationalExpenses == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opFamilyRecreationalExpenses

                                    } // end of family recreational expenses option

                                } // end of while loop opRecreationalExpenses

                            } // end of recreatiobnal expenses
                            else if (opAdmin == "7")
                            {
                                char opCommunityFund = ' '; // community fund option, store return value of admin,community fund function
                                while (opCommunityFund != '3')
                                {
                                    admin_7CommunityFund();
                                    opCommunityFund = admin_CommunityFundMenu(); // admin,community fund function is called
                                    if (opCommunityFund == '0')
                                    {
                                        break;
                                    }
                                    else if (opCommunityFund == '1')
                                    {
                                        char opClassCommunityFund = ' '; // class community fund option, store user input
                                        while (opClassCommunityFund != '1')
                                        {
                                            admin_7CommunityFund_1Class();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opClassCommunityFund;
                                            if (opClassCommunityFund == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opClassCommunityFund

                                    } // end of class option of community fund
                                    else if (opCommunityFund == '2')
                                    {
                                        char opSocietiesCommunityFund = ' '; // Socirties fund option, store user input
                                        while (opSocietiesCommunityFund != '1')
                                        {
                                            admin_7CommunityFund_2Societies();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opSocietiesCommunityFund;
                                            if (opSocietiesCommunityFund == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opSocietiesCommunityFund

                                    } // end of societies of

                                } // end of while loop opCommunityFund

                            } // end of community fund
                            else if (opAdmin == "8")
                            {
                                char opGoals = ' '; // goals option,store return value of admin, goals menu function
                                while (opGoals != '5')
                                {
                                    admin_8Goals();
                                    opGoals = admin_GoalsMenu(); // admin, goals menu function is called
                                    if (opGoals == '0')
                                    {
                                        break;
                                    }
                                    else if (opGoals == '1')
                                    {
                                        char opDailyGoals = ' '; // daiy option of goals option, store user input
                                        while (opDailyGoals != '1')
                                        {
                                            admin_8Goals_1Daily();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opDailyGoals;
                                            if (opDailyGoals == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opDailyGoals

                                    } // end of daily option of goals option of admin login
                                    else if (opGoals == '2')
                                    {
                                        char opWeeklyGoals; // weekly option of goals option, store user input
                                        while (opWeeklyGoals != '1')
                                        {
                                            admin_8Goals_2Weekly();

                                            cout << "Press 0 to Go Back...";
                                            cin >> opWeeklyGoals;
                                            if (opWeeklyGoals == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opWeeklyGoals

                                    } // end of weekly option of goals option of admin login
                                    else if (opGoals == '3')
                                    {
                                        char opMonthlyGoals = ' '; // monthly option of goals option, store user input
                                        while (opMonthlyGoals != '1')
                                        {
                                            admin_8Goals_3Monthly();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opMonthlyGoals;
                                            if (opMonthlyGoals == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opMonthlyGoals

                                    } // end of monthly option of goals option of admin login
                                    else if (opGoals == '4')
                                    {
                                        char opYearlyGoals = ' '; // yearly option of goals option, store user input
                                        while (opYearlyGoals != '1')
                                        {
                                            admin_8Goals_4Yearly();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opYearlyGoals;
                                            if (opYearlyGoals == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opYearlyGoals

                                    } // end of yearly  option of goals option of admin login

                                } // end of while loop opGoals

                            } // end of goals option
                            else if (opAdmin == "9")
                            {
                                char opCellPhone = ' '; // cell phone option,store return value admin,cell phone menu function
                                while (opCellPhone != '4')
                                {
                                    admin_9CellPhone();
                                    opCellPhone = admin_CellPhoneMenu(); // admin,cell phone menu function  called
                                    if (opCellPhone == '0')
                                    {
                                        break;
                                    }
                                    else if (opCellPhone == '1')
                                    {
                                        char opCall_CellPhone = ' '; // call pakage option of cell option, store user input
                                        while (opCall_CellPhone != '1')
                                        {
                                            admin_9CellPhone_1Call();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opCall_CellPhone;
                                            if (opCall_CellPhone == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opCall_CellPhone

                                    } // end of call pakage option of cell phone option
                                    else if (opCellPhone == '2')
                                    {
                                        char opInternet_CellPhone = ' '; // internet option of cell phone, store user input
                                        while (opInternet_CellPhone != '1')
                                        {
                                            admin_9CellPhone_2Internet();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opInternet_CellPhone;
                                            if (opInternet_CellPhone == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opInternet_CellPhone

                                    } // end of  internet option of cell phone
                                    else if (opCellPhone == '3')
                                    {
                                        char opMessage_CellPhone = ' '; // message option of cell phone, store user input
                                        while (opMessage_CellPhone != '1')
                                        {
                                            admin_9CellPhone_3Message();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opMessage_CellPhone;
                                            if (opMessage_CellPhone == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opMessage_CellPhone

                                    } // end of message option of cell phone

                                } // end of while loop opCellPhone

                            } // end of cell phone option of admin option
                            else if (opAdmin == "10")
                            {
                                char opBook = ' '; // book option,store return vale of admin, book menu function
                                while (opBook != '3')
                                {
                                    admin_10Book();
                                    opBook = admin_BookMenu(); // admin, book menu function called
                                    if (opBook == '0')
                                    {
                                        break;
                                    }
                                    else if (opBook == '1')
                                    {
                                        char opBookBorrow = ' '; // book borrow option of book option,store user input
                                        while (opBookBorrow != '1')
                                        {
                                            admin_10Book_1Borrow();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opBookBorrow;
                                            if (opBookBorrow == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opBookBorrow

                                    } // book borrow option of book option,store user input
                                    else if (opBook == '2')
                                    {
                                        char opBookPurchase = ' '; //  book purchase option of book option,store user input
                                        while (opBookPurchase != '1')
                                        {
                                            admin_10Book_2Purchase();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opBookPurchase;
                                            if (opBookPurchase == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opBookPurchase

                                    } // book purchase option of book option,store user input

                                } // end of while loop opBook

                            } // end of book option of admin menu option
                            else if (opAdmin == "11")
                            {
                                char opSelfMotivational = ' '; // self motivational option, store return value of admin,self motivational menu function
                                while (opSelfMotivational != '4')
                                {
                                    admin_11SelfMotivational();
                                    opSelfMotivational = admin_SelfMotivationalMenu(); // admin,self motivational menu function called
                                    if (opSelfMotivational == '0')
                                    {
                                        break;
                                    }
                                    else if (opSelfMotivational == '1')
                                    {
                                        char opFiveTimePrayer = ' '; // five time prayer option of self motivstional ,store user input
                                        while (opFiveTimePrayer != '3')
                                        {
                                            admin_11SelfMotivational_1FiveTimePrayer();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opFiveTimePrayer;
                                            if (opFiveTimePrayer == '0')
                                            {
                                                break;
                                            }
                                            else if (opFiveTimePrayer == '1')
                                            {

                                                five_time_Prayer[inc_opFiveTimePrayer] = {"Yes I Prayer five times! Alhamdulillah."};
                                                // File Handling
                                                fstream append;
                                                append.open("admin_11SelfMotivational_1FiveTimePrayer.txt", ios::app);
                                                append << "\n"
                                                       << five_time_Prayer[inc_opFiveTimePrayer];
                                                append.close();
                                                cout << "Data sucessfully saved" << endl;
                                                inc_opFiveTimePrayer += 1;
                                                hold_Option();
                                                break;
                                            }
                                            else if (opFiveTimePrayer == '2')
                                            {
                                                five_time_Prayer[inc_opFiveTimePrayer] = "No I Prayer five times! InshaAllah.";
                                                // File Handling
                                                fstream append;
                                                append.open("admin_11SelfMotivational_1FiveTimePrayer.txt", ios::app);
                                                append << "\n"
                                                       << five_time_Prayer[inc_opFiveTimePrayer];
                                                append.close();
                                                cout << "Data sucessfully saved" << endl;
                                                inc_opFiveTimePrayer += 1;
                                                hold_Option();
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opFiveTimePrayer

                                    } // five time prayer option of self motivstional option
                                    else if (opSelfMotivational == '2')
                                    {
                                        char opQuran_e_Pak = ' '; // Quran-e-ePak option of self motivational option , store user input
                                        while (opQuran_e_Pak != '3')
                                        {
                                            admin_11SelfMotivational_2Quran_e_Pak();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opQuran_e_Pak;
                                            if (opQuran_e_Pak == '0')
                                            {
                                                break;
                                            }
                                            else if (opQuran_e_Pak == '1')
                                            {
                                                Quran_e_Pak[inc_opQuran_e_Pak] = {"Yes I recite Quran-e-Pak! Alhamdulillah. "};
                                                // File Handling
                                                fstream append;
                                                append.open("admin_11SelfMotivational_2Quran_e_Pak.txt", ios::app);
                                                append << "\n"
                                                       << Quran_e_Pak[inc_opQuran_e_Pak];
                                                append.close();
                                                cout << "Data sucessfully saved" << endl;
                                                inc_opQuran_e_Pak += 1;
                                                hold_Option();
                                                break;
                                            }
                                            else if (opQuran_e_Pak == '2')
                                            {
                                                Quran_e_Pak[inc_opQuran_e_Pak] = "No I will recite Quran-e-Pak! InshaAllah. ";
                                                // File Handling
                                                fstream append;
                                                append.open("admin_11SelfMotivational_2Quran_e_Pak.txt", ios::app);
                                                append << "\n"
                                                       << Quran_e_Pak[inc_opQuran_e_Pak];
                                                append.close();
                                                cout << "Data sucessfully saved" << endl;
                                                inc_opQuran_e_Pak += 1;
                                                hold_Option();
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opQuran_e_Pak

                                    } // end of Quran-e-ePak option of self motivational option
                                    else if (opSelfMotivational == '3')
                                    {
                                        char opDurood_e_Pak = ' '; // Durood e Pak option of self motivational option,store user input
                                        while (opDurood_e_Pak != '3')
                                        {
                                            admin_11SelfMotivational_3Durood_e_Pak();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opDurood_e_Pak;
                                            if (opDurood_e_Pak == '0')
                                            {
                                                break;
                                            }
                                            else if (opDurood_e_Pak == '1')
                                            {
                                                Durood_e_Pak[inc_opDurood_e_Pak] = {"Yes I sent Durood-e-Pak to Beloved Prophet peace be upon him! Alhamdulillah."};
                                                // File Handling
                                                fstream append;
                                                append.open("admin_11SelfMotivational_3Durood_e_Pak.txt", ios::app);
                                                append << "\n"
                                                       << Durood_e_Pak[inc_opDurood_e_Pak];
                                                append.close();
                                                cout << "Data sucessfully saved" << endl;
                                                inc_opDurood_e_Pak += 1;
                                                hold_Option();
                                                break;
                                            }
                                            else if (opDurood_e_Pak == '2')
                                            {
                                                Durood_e_Pak[inc_opDurood_e_Pak] = "No I will send Durood-e-Pak to Beloved Prophet peace be upon him! InshaAllah.";
                                                // File Handling
                                                fstream append;
                                                append.open("admin_11SelfMotivational_3Durood_e_Pak.txt", ios::app);
                                                append << "\n"
                                                       << Durood_e_Pak[inc_opDurood_e_Pak];
                                                append.close();
                                                cout << "Data sucessfully saved" << endl;
                                                inc_opDurood_e_Pak += 1;
                                                hold_Option();
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opDurood_e_Pak

                                    } // end of Durood e Pak option of self motivational option

                                } // end of while loop opSelfMotivational

                            } // end of  self motivational option of admin menu option
                            else if (opAdmin == "12")
                            {
                                char opTransport = ' '; // transport option, store return value of admin, transport menu funtion
                                while (opTransport != '3')
                                {
                                    admin_12Transport();
                                    opTransport = admin_TransportMenu(); // admin, transport menu funtion called
                                    if (opTransport == '0')
                                    {
                                        break;
                                    }
                                    else if (opTransport == '1')
                                    {
                                        char opUberTransport; // Uber/Cream/Bykea option of tansport option,store user input
                                        while (opUberTransport != '1')
                                        {
                                            admin_12Transport_1Uber();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opUberTransport;
                                            if (opUberTransport == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opUberTransport

                                    } // end of Uber/Cream/Bykea option of tansport option
                                    else if (opTransport == '2')
                                    {
                                        char opBusTransport = ' '; //  bus option of of transport option,store user input
                                        while (opBusTransport != '1')
                                        {
                                            admin_12Transport_2Bus();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opBusTransport;
                                            if (opBusTransport == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opBusTransport

                                    } // end of bus option of of transport option

                                } // end of while loop opTransport

                            } // end of transport option of admin menu option
                            else if (opAdmin == "13")
                            {
                                char opRecreationalActivities = ' '; // recreational activities option , store return value of admin, recreational activities menu function
                                while (opRecreationalActivities != '3')
                                {
                                    admin_13RecreationalActivities();
                                    opRecreationalActivities = admin_RecerationActivitiesMenu(); // admin, recreational activities menu function called
                                    if (opRecreationalActivities == '0')
                                    {
                                        break;
                                    }
                                    else if (opRecreationalActivities == '1')
                                    {
                                        char opSportiesActivities = ' '; // sporties activities option of recreational activities option,store user input
                                        while (opSportiesActivities != '1')
                                        {
                                            admin_13RecreationalActivities_1Sporties();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opSportiesActivities;
                                            if (opSportiesActivities == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opSportiesActivities

                                    } // end of Sporties activities option of recreational activities option
                                    else if (opRecreationalActivities == '2')
                                    {
                                        char opSocietiesActivities = ' '; // societies activities option of recreational activities option,store user input
                                        while (opSocietiesActivities != '1')
                                        {
                                            admin_13RecreationalActivities_2Socities();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opSocietiesActivities;
                                            if (opSocietiesActivities == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opSocietiesActivities

                                    } // end of societies activities option of recreational activities option

                                } // end of while loop opRecreationalActivities

                            } // end of recreational activities option of admin menu option
                            else if (opAdmin == "14")
                            {
                                char opAchievements = ' '; // achievments option , store return value of admin,achievments menu function
                                while (opAchievements != '2')
                                {
                                    admin_14Achievments();
                                    opAchievements = admin_Achievemnets(); // admin,achievments menu function called
                                    if (opAchievements == '0')
                                    {
                                        break;
                                    }
                                    else if (opAchievements == '1')
                                    {
                                        char opCoCurricular; // co-curricular option of achievments option, store user input
                                        while (opCoCurricular != '1')
                                        {
                                            admin_14Achievments_1CoCurricular();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opCoCurricular;
                                            if (opCoCurricular == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop opCoCurricular

                                    } // end of co-curricular option of achievments option
                                    else if (opAchievements == '2')
                                    {
                                        char opExtraCurricular = ' '; // extra-curricular option of achievments option, store user input
                                        while (opExtraCurricular != '1')
                                        {
                                            admin_14Achievments_2ExtraCurricular();
                                            cout << "Press 0 to Go Back...";
                                            cin >> opExtraCurricular;
                                            if (opExtraCurricular == '0')
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Incorrect option" << endl;
                                                hold_Option();
                                            }
                                        } // end of while loop of opExtraCurricular

                                    } // end of extra-curricular option of achievments option

                                } // end of while loop opAchievements

                            } // end of achievments option of admin menu option
                            else if (opAdmin == "15")
                            {
                                char opResultGrades = ' '; // result grades option of admin menu option, store user input
                                while (opResultGrades != '1')
                                {
                                    admin_15ResultGrades();
                                    cout << "Press 0 to Go Back...";
                                    cin >> opResultGrades;
                                    if (opResultGrades == '0')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Incorrect option" << endl;
                                        hold_Option();
                                    }
                                } // end of while loop opResultGrades

                            } // end of result grades option of admin menu option
                            else if (opAdmin == "16")
                            {
                                char opGoldenLines = ' '; // golden lines option of admin menu option, store user input
                                while (opGoldenLines != '1')
                                {
                                    admin_16GoldenLines();
                                    cout << "Press 0 to Go Back...";
                                    cin >> opGoldenLines;
                                    if (opGoldenLines == '0')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Incorrect option" << endl;
                                        hold_Option();
                                    }
                                } // end of while loop opGoldenLines

                            } // end of golden lines option of admin menu option
                            else if (opAdmin == "17")
                            {
                                char opLifelongEvents = ' '; // lifelong events  option of admin menu option, store user input
                                while (opLifelongEvents != '1')
                                {
                                    admin_17LifelongEvents();
                                    cout << "Press 0 to Go Back...";
                                    cin >> opLifelongEvents;
                                    if (opLifelongEvents == '0')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Incorrect option" << endl;
                                        hold_Option();
                                    }
                                } // end of while loop opLifelongEvents

                            } // end of lifelong events  option of admin menu option
                            else if (opAdmin == "18")
                            {

                                char opNotes = ' '; // notes option of admin menu option, store user input
                                while (opNotes != '1')
                                {
                                    admin_18Notes();
                                    cout << "Press 0 to Go Back...";
                                    cin >> opNotes;
                                    if (opNotes == '0')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Incorrect option" << endl;
                                        hold_Option();
                                    }
                                } // end of while loop opNotes

                            } // end of notes option of admin menu option
                            else if (opAdmin == "19")
                            {
                                char opAgentAddUser = ' '; // notes option of admin menu option, store user input
                                while (opAgentAddUser != '1')
                                {
                                    admin_19CreateAgentAccount();
                                    cout << "Press 0 to Go Back...";
                                    cin >> opAgentAddUser;
                                    if (opAgentAddUser == '0')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Incorrect option" << endl;
                                        hold_Option();
                                    }
                                } // end of while loop opNotes

                            } // end of notes option of admin menu option
                            else if (opAdmin == "20")
                            {

                                break;

                            } // end of logout option
                            else
                            {
                                cout << "Incorrect option" << endl;
                                hold_Option();
                            }
                        } // end of While loop of opAdmin menu

                    } //  end of option admin login true securty code
                    else
                    {
                        cout << "Incorrect Username and Password" << endl;
                        hold_Option();

                    } // end of option admin login false security code

                } // end of admin login option
                //******************************* END OF ADMIN MENU OPTION *******************************************
                else if (opLogin == '2')
                {
                    string agentUsername, agentPassword; // Agent sig-in variable
                    agentUsername = agentPassword = "";  // variable initiation
                    header();                            // header function is called
                    cout << "Main Menu > Login > Agent" << endl;
                    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
                    cout << "Sign-In" << endl;
                    cout << "Username : ";
                    cin >> agentUsername;
                    cout << "Password : ";
                    cin >> agentPassword;
                    int agentindex = checkuser_agent(agentUsername, agentPassword); // check the username and password in the array and make descion upon it
                    if (username_Agent[agentindex] == agentUsername && password_Agent[agentindex] == agentPassword)
                    {
                        string opAgent = " "; // Agent option , store return value of agent menu function
                        while (true)
                        {
                            header(); // header function is called
                            cout << "Main Menu > Menu " << endl;
                            cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
                            opAgent = agent_Menu(); // agent menu function called
                            if (opAgent == "0")
                            {
                                char opProfile = ' ';
                                while (opProfile != '1')
                                {
                                    agent_0Profile(agentindex);
                                    cout << "Press 0 to go back...";
                                    cin >> opProfile;
                                    if (opProfile == '0')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Incorrect option" << endl;
                                        hold_Option();
                                    }
                                }
                            }
                            else if (opAgent == "1")
                            {
                                char opWallet = ' '; // wallet option, store user input
                                while (opWallet != '1')
                                {
                                    agent_1Wallet();
                                    cout << "Press 0 to go back...";
                                    cin >> opWallet;
                                    if (opWallet == '0')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Incorrect option" << endl;
                                        hold_Option();
                                    }
                                } // end of while loop opWallet

                            } // enf of wallet option of agent option
                            else if (opAgent == "2")
                            {
                                char opAcademicReport = ' '; // acsdemic report, store user input
                                while (opAcademicReport != '1')
                                {
                                    agent_2AcademicReport();
                                    cout << "Press 0 to go back...";
                                    cin >> opAcademicReport;
                                    if (opAcademicReport == '0')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Incorrect option" << endl;
                                        hold_Option();
                                    }
                                } // end of while loop opAcademicReport

                            } // end of academic report option of agent option
                            else if (opAgent == "3")
                            {
                                char opExpensesReport; // monthly expenses option , store user input
                                while (opExpensesReport != '1')
                                {
                                    agent_3ExpensesReport();
                                    cout << "Press 0 to go back...";
                                    cin >> opExpensesReport;
                                    if (opExpensesReport == '0')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Incorrect option" << endl;
                                        hold_Option();
                                    }
                                } // end of while loop opExpensesReport

                            } // end of expenses report of agent option
                            else if (opAgent == "4")
                            {
                                char opMealReport; // meal option ,store user input
                                while (opMealReport != '1')
                                {
                                    agent_4MealReport();
                                    cout << "Press 0 to go back...";
                                    cin >> opMealReport;
                                    if (opMealReport == '0')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Incorrect option" << endl;
                                        hold_Option();
                                    }
                                } // end of while loop opMealReport

                            } // end of meal option of agent option
                            else if (opAgent == "5")
                            {
                                char opTracker; // salah tracker ,store user input
                                while (opTracker != '1')
                                {
                                    agent_5SpiritualTracker();
                                    cout << "Press 0 to go back...";
                                    cin >> opTracker;
                                    if (opTracker == '0')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Incorrect option" << endl;
                                        hold_Option();
                                    }
                                } // end of while loop opTracker

                            } // salah tracker option of agent option
                            else if (opAgent == "6")
                            {
                                char opAachievmentsReport = ' '; // achivements report,store user input
                                while (opAachievmentsReport != '1')
                                {
                                    agent_6AachieventsReport();
                                    cout << "Press 0 to go back...";
                                    cin >> opAachievmentsReport;
                                    if (opAachievmentsReport == '0')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Incorrect option" << endl;
                                        hold_Option();
                                    }
                                } // end of while loop opAachievmentsReport

                            } // end of achivements report option of agent option
                            else if (opAgent == "7")
                            {
                                break;
                            } // end of agent function
                            else
                            {
                                cout << "Incorrect option" << endl;
                                hold_Option();
                            }
                        } // end of while loop opAgent

                    } // end of agent login true securty code

                    else
                    {
                        cout << "Incorrect Username and Password" << endl;
                        hold_Option();

                    } // end of agent login False security code

                } // end of agent login option

                else
                {
                    cout << "Incorrect option" << endl;
                    hold_Option();
                }

                //******************************* END OF AGENT OPTION *******************************************c

            } // end of login option of main menu

        } // end of While loop of opLogin
        else if (opMain == '2')
        {
            char opAbout = ' '; // about options, store user input
            while (opAbout != '3')
            {
                header(); // header function is called
                cout << "Main Menu > About " << endl;
                cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
                cout << "1. Version " << endl;
                cout << "2. Developer " << endl;
                cout << "Press 0 to Go Back...";
                cin >> opAbout;
                if (opAbout == '0')
                {
                    break;

                } // end of Go Back of about option
                else if (opAbout == '1')
                {
                    char opVersion = ' '; // option version, store user input
                    while (opVersion != '1')
                    {
                        header(); // header function is called
                        cout << "Main Menu > About > Version" << endl;
                        cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
                        cout << "Version : 4.0" << endl;
                        cout << "Version 04 is developed with the concept of Conditional statments," << endl;
                        cout << "Functions, loops, Arrays and File Handling..." << endl;
                        cout << "Press 0 to Go Back...";
                        cin >> opVersion;
                        if (opVersion == '0')
                        {
                            break;
                        }
                        else
                        {
                            cout << "Incorrect option" << endl;
                            hold_Option();
                        }
                    } // end of while loop opVersion

                } // end of version of about option
                else if (opAbout == '2')
                {
                    char opDeveloper; // option developer, store user input
                    while (opDeveloper != '1')
                    {
                        header(); // header function is called
                        cout << "Main Menu > About > Developer" << endl;
                        cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
                        cout << "Instructor     : Dr Awais Hassan" << endl;
                        cout << "Special thanks : Laeeq Khan Niazi " << endl;
                        cout << "Developer      : Muhammad Hammad Hassan" << endl;
                        cout << "Contact        : +923030299365 " << endl;
                        cout << "Press 0 to Go Back...";
                        cin >> opDeveloper;
                        if (opDeveloper == '0')
                        {
                            break;
                        }
                        else
                        {
                            cout << "Incorrect option" << endl;
                            hold_Option();
                        }
                    } // end of while loop opDeveloper

                } // end of developer of about option

            } // end of while loop opAbout

        } // end of about option of menu menu
        else if (opMain == '3')
        {
            char opAccount = ' '; // create new account  option, store user input
            while (opAccount != '1')
            {
                header(); // header function is called
                cout << "Main Menu > Create an acount " << endl;
                cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
                cout << "Enter first name : ";
                cin >> firstname[inc_opAddUser];
                cout << "Enter last name : ";
                cin >> lastname[inc_opAddUser];
                cout << "Enter username : ";
                cin >> username[inc_opAddUser];
                bool check = check_Existing(username[inc_opAddUser]);
                while (check_Existing(username[inc_opAddUser]) == true)
                {
                    cout << "Username is already exist try another once" << endl;
                    cout << "Enter username : ";
                    cin >> username[inc_opAddUser];
                }
                cout << "Enter password :";
                cin >> password[inc_opAddUser];
                // File Handling
                fstream append_opAccount;
                append_opAccount.open("adminSecurityFile.txt", ios::app);
                append_opAccount<< "\n" << firstname[inc_opAddUser] << "," << lastname[inc_opAddUser] << "," << username[inc_opAddUser] << "," << password[inc_opAddUser] ;
                append_opAccount.close();
                cout << "Admin account sucessfully created" << endl;
                inc_opAddUser += 1;
                cout << "Press 0 to Go Back...";

                cin >> opAccount;
                if (opAccount == '0')
                {
                    break;
                }
                else
                {
                    cout << "Incorrect option" << endl;
                    hold_Option();
                    break;
                }
            }
        } // end of create new account option
        else if (opMain == '4')
        {
            char opExit = ' '; // Exit options, store user input
            header();          // header function is called
            cout << "Main Menu > Exit " << endl;
            cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
            cout << "Are you sure to want to Exit?" << endl;
            cout << "1. Yes " << endl;
            cout << "2. No " << endl;
            cout << "Press 0 to Go Back...";
            cin >> opExit;
            if (opExit == '0')
            {
                continue;
            }
            else if (opExit == '1')
            {
                header(); // header is called
                cout << "Thanks for using University Student Diary Managment System" << endl;
                cout << "Take Care...Allah Hafiz";
                break;
            } // end of exit Yes, Program will terminate
            else if (opExit == '2')
            {
                continue;
            }
            else
            {
                cout << "Incorrect option" << endl;
                hold_Option();
            }

        } // exit option of admin home menu
        else
        {
            cout << "Invalid option..." << endl;
            hold_Option();

        } // message show  invalid option of option main screen

    } // end while loop main menu

} // end of main function

//********************* Functions Definition ************************
void header()
{
    system("cls");
    cout << "*************************************************************************************" << endl;
    cout << "*************                                                           *************" << endl;
    cout << "********                                                                     ********" << endl;
    cout << "***                  University Student Diary Management System                   ***" << endl;
    cout << "********                                                                     ********" << endl;
    cout << "*************                                                           *************" << endl;
    cout << "*************************************************************************************" << endl;

} // header funtion end
void header_Welcome()
{
    system("cls");
    cout << "*************************************************************************************" << endl;
    cout << "*************                                                           *************" << endl;
    cout << "********                                                                     ********" << endl;
    cout << "***             Welcome to University Student Diary Management System             ***" << endl;
    cout << "********                                                                     ********" << endl;
    cout << "*************                                                           *************" << endl;
    cout << "*************************************************************************************" << endl;
} // end of header welcome funtion
char admin_HomeMenu()
{
    char opMain;
    cout << "1. Login" << endl;
    cout << "2. About" << endl;
    cout << "3. Create an acount" << endl;
    cout << "4. Exit" << endl;
    cout << "Press the number... ";
    cin >> opMain;
    return opMain;
} // end of admin home menu
void hold_Option()
{
    cout << "Press anykey to continue..." << endl;
    getch();
} // end of hold option function
//********************* SECURITY ************************
int checkuser(string user_name, string pass_word)
{
    int index = -1;
    for (int i = 0; i < length; i++)
    {
        if (user_name == username[i] && pass_word == password[i])
        {
            index = i;
        }
    }
    return index;
} // end of check username
bool check_Existing(string username_check)
{
    for (int i = 0; i < inc_opAddUser; i++)
    {
        if (username_check == username[i])
        {
            return true;
        }
    }
    return false;

} // end of check exiting username
int checkuser_agent(string agent_user_name, string agent_pass_word)
{
    int index_agent = -1;
    for (int i = 0; i < length; i++)
    {
        if (agent_user_name == username_Agent[i] && agent_pass_word == password_Agent[i])
        {
            index_agent = i;
        }
    }

    return index_agent;
}
bool check_Existing_agent(string agent_username_check)
{
    for (int i = 0; i < inc_opAgentAddUser; i++)
    {
        if (agent_username_check == username_Agent[i])
        {
            return true;
        }
    }
    return false;
}
//****************** ADMIN ******************
void admin_0Profile(int indexValue)
{

    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Profile" << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "                                   __WELCOME ON BOARD__                             " << endl;
    cout << "First name : " << firstname[indexValue] << "\t";
    cout << "Last name : " << lastname[indexValue] << endl;
    cout << "_____________________________________________________________________________________" << endl;
    cout << "Recommendations:-" << endl;
    admin_Recommendation();
    cout << "_____________________________________________________________________________________" << endl;
    display_profile_admin();
} // end of option 0 profle of admin
void admin_1WalletStatus()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Wallet Status " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Current Blance:" << addWalletMoney-total_Expenses() << endl;
    cout << "Remarks from Agent:" << walletRemarks << endl;
} // end of admin option 1
void admin_2ExpensesReport()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Expenses Report " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
} // end of admin option 1
void admin_2ExpensesReportToday()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Expenses Report > Today  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    display_breakfast();
    cout << "_____________________________________________________________________________________" << endl;
    display_lunch();
    cout << "_____________________________________________________________________________________" << endl;
    display_dinner();
} // end of admin option 2 of today report
void admin_2ExpensesReportMonthly()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > ExpensesReport > Monthly" << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Monthly Report :- " << endl;
    cout << "Personal................: " << personal_Expenses() << endl;
    cout << "Hostel..................: " << hostel_Expenses() << endl;
    cout << "Helping Material........: " << helpingmaterial_Expenses() << endl;
    cout << "Recreational Expenses...: " << recreational_Expenses() << endl;
    cout << "Fund....................: " << communityfund_Expenses() << endl;
    cout << "Cell Phone..............: " << cellphone_Expenses() << endl;
    cout << "Transport...............: " << transport_Expenses() << endl;
    cout << "                   Total: " << total_Expenses() << endl;
} // end of admin option 2 of monthly option
void admin_2ExpensesReportYearly()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > ExpensesReport > Year  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    display_academicFee(); // sorted academic fee function called
} // end of admin option 2 of yearly
void admin_3AcademicFee()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Academic Fee " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Semester type : ";
    cin >> semesterType[increment_opAcademicFee];
    cout << "Challan no : ";
    cin >> challanNo[increment_opAcademicFee];
    cout << "Amount : ";
    amountacademic[increment_opAcademicFee] = float_Validaion("Amount : ", amountacademic[increment_opAcademicFee]);
    cout << "Date : ";
    cin >> date[increment_opAcademicFee];
    cout << "Remarks  : ";
    cin >> remarks[increment_opAcademicFee];
    // File Handling
    fstream append;
    append.open("admin3AcadmicFee.txt", ios::app);
    append << endl
           << semesterType[increment_opAcademicFee] << "," << challanNo[increment_opAcademicFee] << "," << amountacademic[increment_opAcademicFee] << "," << date[increment_opAcademicFee] << "," << remarks[increment_opAcademicFee];
    append.close();
    cout << "Data sucessfully saved" << endl;
    increment_opAcademicFee += 1; // after storing data successfully,increase the index by 1
} // end of admin option 3
void admin_4Hostel()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Hostel" << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
} // end of admin 4 option
void admin_4Hostel_1Meal()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Hostel > Meal  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
} // end of admin 4 option of sub option 1 meal
void admin_4Hostel_1Meal_1Breakfast()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Hostel > Meal > Breakfast Charges " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Note: If you Hostilities, add 000 in charges." << endl;
    cout << "Menu : ";
    cin >> menuBreakfast[increment_opMealBreakfast];
    cout << "Charges : ";
    chargesBreakfast[increment_opMealBreakfast] = float_Validaion("Charges : ", chargesBreakfast[increment_opMealBreakfast]);
    cout << "Remarks : ";
    cin >> remarksBreakfast[increment_opMealBreakfast];
    // File Handling
    fstream append;
    append.open("admin_4Hostel_1Meal_1Breakfast.txt", ios::app);
    append << endl
           << menuBreakfast[increment_opMealBreakfast] << "," << chargesBreakfast[increment_opMealBreakfast] << "," << remarksBreakfast[increment_opMealBreakfast];
    append.close();
    cout << "Data sucessfully saved" << endl;
    increment_opMealBreakfast += 1;
} // end of function
void admin_4Hostel_1Meal_2Lunch()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Hostel > Meal > Lunch Charges " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Note: If you Hostilities, add 000 in charges." << endl;
    cout << "Menu : ";
    cin >> menuLunch[increment_opMealLunch];
    cout << "Charges : ";
    chargesLunch[increment_opMealLunch] = float_Validaion("Charges : ", chargesLunch[increment_opMealLunch]);
    cout << "Remarks : ";
    cin >> remarksLunch[increment_opMealLunch];
    // File Handling
    fstream append;
    append.open("admin_4Hostel_1Meal_2Lunch.txt", ios::app);
    append << endl
           << menuLunch[increment_opMealLunch] << "," << chargesLunch[increment_opMealLunch] << "," << remarksLunch[increment_opMealLunch];
    append.close();
    cout << "Data sucessfully saved" << endl;
    increment_opMealLunch += 1;
} // end of function
void admin_4Hostel_1Meal_3Dinner()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Hostel > Meal > Dinner Charges " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Note: If you Hostilities, add 000 in charges." << endl;
    cout << "Menu : ";
    cin >> menuDinner[increment_opMealDinner];
    cout << "Charges : ";
    chargesDinner[increment_opMealDinner] = float_Validaion("Charges : ", chargesDinner[increment_opMealDinner]);
    cout << "Remarks : ";
    cin >> remarksDinner[increment_opMealDinner];
    // File Handling
    fstream append;
    append.open("admin_4Hostel_1Meal_3Dinner.txt", ios::app);
    append << endl
           << menuDinner[increment_opMealDinner] << "," << chargesDinner[increment_opMealDinner] << "," << remarksDinner[increment_opMealDinner];
    append.close();
    cout << "Data sucessfully saved" << endl;
    increment_opMealDinner += 1;
} // end of function
void admin_4Hostel_2MealChargesMonthly()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Hostel > Monthly fee Charges  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Month : ";
    cin >> monthlyMealExpenses[increment_opMealCharges];
    cout << "Charges : ";
    chargesMealMonthly[increment_opMealCharges] = float_Validaion("Charges : ", chargesMealMonthly[increment_opMealCharges]);
    cout << "Remarks : ";
    cin >> remarksMealExpenses[increment_opMealCharges];
    // File Handling
    fstream append;
    append.open("admin_4Hostel_2MealChargesMonthly.txt", ios::app);
    append << endl
           << monthlyMealExpenses[increment_opMealCharges] << "," << chargesMealMonthly[increment_opMealCharges] << "," << remarksMealExpenses[increment_opMealCharges];
    append.close();
    cout << "Data sucessfully saved" << endl;
    increment_opMealCharges += 1;
} // end of function
void admin_4Hostel_3LivingChargesMonthly()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Hostel > Living Charges  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Month : ";
    cin >> monthLivingExpenses[inc_opLivingCharges];
    cout << "Charges : ";
    chargesLivingExpenses[inc_opLivingCharges] = float_Validaion("Charges : ", chargesLivingExpenses[inc_opLivingCharges]);
    cout << "Remarks : ";
    cin >> remarksLivingExpenses[inc_opLivingCharges];
    // File Handling
    fstream append;
    append.open("admin_4Hostel_3LivingChargesMonthly.txt", ios::app);
    append << endl
           << monthLivingExpenses[inc_opLivingCharges] << "," << chargesLivingExpenses[inc_opLivingCharges] << "," << remarksLivingExpenses[inc_opLivingCharges];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opLivingCharges += 1;
} // end of function
void admin_4Hostel_4ServiceChargesMonthly()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Hostel > Service Charges  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Month : ";
    cin >> monthServiceExpenses[inc_opServiceCharges];
    cout << "Charges : ";
    chargesServiceMonthly[inc_opServiceCharges] = float_Validaion("Charges : ", chargesServiceMonthly[inc_opServiceCharges]);
    cout << "Remarks : ";
    cin >> remarksServiceExpenses[inc_opServiceCharges];
    // File Handling
    fstream append;
    append.open("admin_4Hostel_4ServiceChargesMonthly.txt", ios::app);
    append << "\n"
           << monthServiceExpenses[inc_opServiceCharges] << "," << chargesServiceMonthly[inc_opServiceCharges] << "," << remarksServiceExpenses[inc_opServiceCharges];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opServiceCharges += 1;
} // end of function
void admin_4Hostel_5RenovationChargesMonthly()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Hostel > Renovation Charges  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Charges : ";
    chargesRenovationMonthly[inc_opRenovationCharges] = float_Validaion("Charges : ", chargesRenovationMonthly[inc_opRenovationCharges]);
    cout << "Remarks : ";
    cin >> remarksRenovationExpenses[inc_opRenovationCharges];
    // File Handling
    fstream append;
    append.open("admin_4Hostel_5RenovationChargesMonthly.txt", ios::app);
    append << "\n"
           << chargesRenovationMonthly[inc_opRenovationCharges] << "," << remarksRenovationExpenses[inc_opRenovationCharges];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opRenovationCharges += 1;
} // end of function
void admin_4Hostel_6LaundryChargesMonthly()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Hostel > Laundry Charges  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Charges : ";
    chargesLaundryMonthly[inc_opLaundryCharges] = float_Validaion("Charges : ", chargesLaundryMonthly[inc_opLaundryCharges]);
    cout << "Remarks : ";
    cin >> remarksLaundryExpenses[inc_opLaundryCharges];
    // File Handling
    fstream append;
    append.open("admin_4Hostel_6LaundryChargesMonthly.txt", ios::app);
    append << "\n"
           << chargesLaundryMonthly[inc_opLaundryCharges] << "," << remarksLaundryExpenses[inc_opLaundryCharges];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opLaundryCharges += 1;
    cout << "Press 0 to Go Back...";
} // end of function
void admin_4Hostel_7BarberChargesMonthly()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Hostel > Laundry Charges  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Charges : ";
    chargesBarberMonthly[inc_opBarberCharges] = float_Validaion("Charges : ", chargesBarberMonthly[inc_opBarberCharges]);
    cout << "Remarks : ";
    cin >> remarksBarberExpenses[inc_opBarberCharges];
    // File Handling
    fstream append;
    append.open("admin_4Hostel_7BarberChargesMonthly.txt", ios::app);
    append << "\n"
           << chargesBarberMonthly[inc_opBarberCharges] << "," << remarksBarberExpenses[inc_opBarberCharges];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opBarberCharges += 1;
} // end of function
void admin_5HelpingMaterial()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Helping Material  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
} // end of function
void admin_5HelpingMaterial_1Notes()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Helping Material > Notes " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Charges : ";
    chargesNotesMonthly[inc_opNotesHelpingMaterial] = float_Validaion("Charges : ", chargesNotesMonthly[inc_opNotesHelpingMaterial]);
    cout << "Remarks : ";
    cin >> remarksNotesExpenses[inc_opNotesHelpingMaterial];
    // File Handling
    fstream append;
    append.open("admin_5HelpingMaterial_1Notes.txt", ios::app);
    append << "\n"
           << chargesNotesMonthly[inc_opNotesHelpingMaterial] << "," << remarksNotesExpenses[inc_opNotesHelpingMaterial];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opNotesHelpingMaterial += 1;
} // end of function
void admin_5HelpingMaterial_2Register()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Helping Material > Register " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Charges : ";
    chargesRegisterMonthly[inc_opRegisterHelpingMaterial] = float_Validaion("Charges : ", chargesRegisterMonthly[inc_opRegisterHelpingMaterial]);
    cout << "Remarks : ";
    cin >> remarksRegisterExpenses[inc_opRegisterHelpingMaterial];
    // File Handling
    fstream append;
    append.open("admin_5HelpingMaterial_2Register.txt", ios::app);
    append << "\n"
           << chargesRegisterMonthly[inc_opRegisterHelpingMaterial] << "," << remarksRegisterExpenses[inc_opRegisterHelpingMaterial];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opRegisterHelpingMaterial += 1;
} // end of function
void admin_5HelpingMaterial_3Stationary()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Helping Material > Stationary " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Charges : ";
    chargesStationaryMonthly[inc_opStationaryHelpingMaterial] = float_Validaion("Charges : ", chargesStationaryMonthly[inc_opStationaryHelpingMaterial]);
    cout << "Remarks : ";
    cin >> remarksStationaryExpenses[inc_opStationaryHelpingMaterial];
    // File Handling
    fstream append;
    append.open("admin_5HelpingMaterial_3Stationary.txt", ios::app);
    append << "\n"
           << chargesStationaryMonthly[inc_opStationaryHelpingMaterial] << "," << remarksStationaryExpenses[inc_opStationaryHelpingMaterial];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opStationaryHelpingMaterial += 1;
} // end of function
void admin_6RecreationalExpenses()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Recreational Expenses  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
} // end of function
void admin_6RecreationalExpenses_1Friends()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Recreational Expenses > Friends  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Charges : ";
    chargesFriendsRecreationalExpenses[inc_opFriendsRecreationalExpenses] = float_Validaion("Charges : ", chargesFriendsRecreationalExpenses[inc_opFriendsRecreationalExpenses]);
    cout << "Remarks : ";
    cin >> remarksFriendsRecreationalExpenses[inc_opFriendsRecreationalExpenses];
    // File Handling
    fstream append;
    append.open("admin_6RecreationalExpenses_1Friends.txt", ios::app);
    append << "\n"
           << chargesFriendsRecreationalExpenses[inc_opFriendsRecreationalExpenses] << "," << remarksFriendsRecreationalExpenses[inc_opFriendsRecreationalExpenses];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opFriendsRecreationalExpenses += 1;
} // end of function
void admin_6RecreationalExpenses_2Family()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Recreational Expenses > Family  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Charges : ";
    chargesFamilyRecreationalExpenses[inc_opFamilyRecreationalExpenses] = float_Validaion("Charges : ", chargesFamilyRecreationalExpenses[inc_opFamilyRecreationalExpenses]);
    cout << "Remarks : ";
    cin >> remarksFamilyRecreationalExpenses[inc_opFamilyRecreationalExpenses];
    // File Handling
    fstream append;
    append.open("admin_6RecreationalExpenses_2Family.txt", ios::app);
    append << "\n"
           << chargesFamilyRecreationalExpenses[inc_opFamilyRecreationalExpenses] << "," << remarksFamilyRecreationalExpenses[inc_opFamilyRecreationalExpenses];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opFamilyRecreationalExpenses += 1;
} // end of function
void admin_7CommunityFund()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Community Fund  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
} // end of function
void admin_7CommunityFund_1Class()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Community Fund " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Objective : ";
    cin >> remarksClassCommunityFund[inc_opClassCommunityFund];
    cout << "Charges : ";
    chargesClassCommunityFund[inc_opClassCommunityFund] = float_Validaion("Charges : ", chargesClassCommunityFund[inc_opClassCommunityFund]);
    // File Handling
    fstream append;
    append.open("admin_7CommunityFund_1Class.txt", ios::app);
    append << "\n"
           << remarksClassCommunityFund[inc_opClassCommunityFund] << "," << chargesClassCommunityFund[inc_opClassCommunityFund];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opClassCommunityFund += 1;
} // end of function
void admin_7CommunityFund_2Societies()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Community Fund " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Objective : ";
    cin >> remarksSocietiesCommunityFund[inc_opSocietiesCommunityFund];
    cout << "Charges : ";
    chargesSocietiesCommunityFund[inc_opSocietiesCommunityFund] = float_Validaion("Charges : ", chargesSocietiesCommunityFund[inc_opSocietiesCommunityFund]);
    // File Handling
    fstream append;
    append.open("admin_7CommunityFund_2Societies.txt", ios::app);
    append << "\n"
           << remarksSocietiesCommunityFund[inc_opSocietiesCommunityFund] << "," << chargesSocietiesCommunityFund[inc_opSocietiesCommunityFund];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opSocietiesCommunityFund += 1;
} // end of function
void admin_8Goals()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Goals " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
} // end of function
void admin_8Goals_1Daily()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Goals > Daily " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Title : ";
    cin >> titleDailyGoals[inc_opDailyGoals];
    cout << "Description : ";
    cin >> descriptionDailyGoals[inc_opDailyGoals];
    // File Handling
    fstream append;
    append.open("admin_8Goals_1Daily.txt", ios::app);
    append << "\n"
           << titleDailyGoals[inc_opDailyGoals] << "," << descriptionDailyGoals[inc_opDailyGoals];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opDailyGoals += 1;
} // end of function
void admin_8Goals_2Weekly()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Goals > Weekly " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Title : ";
    cin >> titleWeeklyGoals[inc_opWeeklyGoals];
    cout << "Description : ";
    cin >> descriptionWeeklyGoals[inc_opWeeklyGoals];
    // File Handling
    fstream append;
    append.open("admin_8Goals_2Weekly.txt", ios::app);
    append << "\n"
           << titleWeeklyGoals[inc_opWeeklyGoals] << "," << descriptionWeeklyGoals[inc_opWeeklyGoals];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opWeeklyGoals += 1;
} // end of function
void admin_8Goals_3Monthly()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Goals > Monthly " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Title : ";
    cin >> titleMonthlyGoals[inc_opMonthlyGoals];
    cout << "Description : ";
    cin >> descriptionMonthlyGoals[inc_opMonthlyGoals];
    // File Handling
    fstream append;
    append.open("admin_8Goals_3Monthly.txt", ios::app);
    append << "\n"
           << titleMonthlyGoals[inc_opMonthlyGoals] << "," << descriptionMonthlyGoals[inc_opMonthlyGoals];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opMonthlyGoals += 1;
} // end of function
void admin_8Goals_4Yearly()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Goals > Monthly " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Title : ";
    cin >> titleYearlyGoals[inc_opYearlyGoals];
    cout << "Description : ";
    cin >> descriptionYearlyGoals[inc_opYearlyGoals];
    // File Handling
    fstream append;
    append.open("admin_8Goals_4Yearly.txt", ios::app);
    append << "\n"
           << titleYearlyGoals[inc_opYearlyGoals] << "," << descriptionYearlyGoals[inc_opYearlyGoals];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opYearlyGoals += 1;
} // end of function
void admin_9CellPhone()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Cell Phone " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
} // end of function
void admin_9CellPhone_1Call()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Cell Phone > Call Pakage " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Name : ";
    cin >> nameCallPakage[inc_opCall_CellPhone];
    cout << "Amount : ";
    amountCallPakage[inc_opCall_CellPhone] = float_Validaion("Amount : ", amountCallPakage[inc_opCall_CellPhone]);
    cout << "Duration : ";
    cin >> durationCallPakage[inc_opCall_CellPhone];
    // File Handling
    fstream append;
    append.open("admin_9CellPhone_1Call.txt", ios::app);
    append << "\n"
           << nameCallPakage[inc_opCall_CellPhone]
           << "," << amountCallPakage[inc_opCall_CellPhone]
           << "," << durationCallPakage[inc_opCall_CellPhone];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opCall_CellPhone += 1;
} // end of function
void admin_9CellPhone_2Internet()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Cell Phone > Internet Pakage " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Name : ";
    cin >> nameInternetPakage[inc_opInternet_CellPhone];
    cout << "Amount : ";
    amountInternetPakage[inc_opInternet_CellPhone] = float_Validaion("Amount : ", amountInternetPakage[inc_opInternet_CellPhone]);
    cout << "Duration : ";
    cin >> durationInternetPakage[inc_opInternet_CellPhone];
    // File Handling
    fstream append;
    append.open("admin_9CellPhone_2Internet.txt", ios::app);
    append << "\n"
           << nameInternetPakage[inc_opInternet_CellPhone]
           << "," << amountInternetPakage[inc_opInternet_CellPhone]
           << "," << durationInternetPakage[inc_opInternet_CellPhone];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opInternet_CellPhone += 1;
} // end of function
void admin_9CellPhone_3Message()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Cell Phone > Message Pakage " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Name : ";
    cin >> nameMessagePakage[inc_opMessage_CellPhone];
    cout << "Amount : ";
    amountMessagePakage[inc_opMessage_CellPhone] = float_Validaion("Amount : ", amountMessagePakage[inc_opMessage_CellPhone]);
    cout << "Duration : ";
    cin >> durationMessagePakage[inc_opMessage_CellPhone];
    // File Handling
    fstream append;
    append.open("admin_9CellPhone_3Message.txt", ios::app);
    append << "\n"
           << nameMessagePakage[inc_opMessage_CellPhone]
           << "," << amountMessagePakage[inc_opMessage_CellPhone]
           << "," << durationMessagePakage[inc_opMessage_CellPhone];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opMessage_CellPhone += 1;
} // end of function
void admin_10Book()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Book " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
} // end of function
void admin_10Book_1Borrow()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Book > Borrow " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Title : ";
    cin >> titleBorrowBook[inc_opBookBorrow];
    cout << "Author: : ";
    cin >> authorBorrowBook[inc_opBookBorrow];
    cout << "Friend Name : ";
    cin >> friendnameBorrowBook[inc_opBookBorrow];
    cout << "Remarks : ";
    cin >> remarksBorrowBook[inc_opBookBorrow];
    // File Handling
    fstream append;
    append.open("admin_10Book_1Borrow.txt", ios::app);
    append << "\n"
           << titleBorrowBook[inc_opBookBorrow]
           << "," << authorBorrowBook[inc_opBookBorrow]
           << "," << friendnameBorrowBook[inc_opBookBorrow]
           << "," << remarksBorrowBook[inc_opBookBorrow];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opBookBorrow += 1;
} // end of function
void admin_10Book_2Purchase()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Book > Purchase " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Title : ";
    cin >> titlePurchaseBook[inc_opBookPurchase];
    cout << "Author: : ";
    cin >> authorPurchaseBook[inc_opBookPurchase];
    cout << "Purchase : ";
    amountPurchaseBook[inc_opBookPurchase] = float_Validaion("Purchase : ", amountPurchaseBook[inc_opBookPurchase]);
    cout << "Remarks : ";
    cin >> remarksPurchaseBook[inc_opBookPurchase];
    // File Handling
    fstream append;
    append.open("admin_10Book_2Purchase.txt", ios::app);
    append << "\n"
           << titlePurchaseBook[inc_opBookPurchase]
           << "," << authorPurchaseBook[inc_opBookPurchase]
           << "," << amountPurchaseBook[inc_opBookPurchase]
           << "," << remarksPurchaseBook[inc_opBookPurchase];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opBookPurchase = +1;
} // end of function
void admin_11SelfMotivational()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Spiritual Food " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
} // end of function
void admin_11SelfMotivational_1FiveTimePrayer()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Spiritual Food > Five-time Prayer " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Is you prayer five times?" << endl;
    cout << "   1. Yes" << endl;
    cout << "   2. No" << endl;
} // end of function
void admin_11SelfMotivational_2Quran_e_Pak()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Spiritual Food > Quran-e-Pak " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Is you Recite Quran-e-Pak?" << endl;
    cout << "   1. Yes" << endl;
    cout << "   2. No" << endl;
} // header function is called
void admin_11SelfMotivational_3Durood_e_Pak()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Spiritual Food > Quran-e-Pak " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Is you send Durood-e-Pak to Beloved Prophet peace be upon him" << endl;
    cout << "   1. Yes" << endl;
    cout << "   2. No" << endl;
} // header function is called
void admin_12Transport()
{
    header(); // header function is called;
    cout << "Main Menu > Admin > Menu > Transport " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
} // end of function
void admin_12Transport_1Uber()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Transport > Uber/Cream/Bykea " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Location from : ";
    cin >> locationFromUber[inc_opUberTransport];
    cout << "Location to: ";
    cin >> locationToUber[inc_opUberTransport];
    cout << "Amount : ";
    amountUber[inc_opUberTransport] = float_Validaion("Amount : ", amountUber[inc_opUberTransport]);
    cout << "Purpose : ";
    cin >> purposeUber[inc_opUberTransport];
    // File Handling
    fstream append;
    append.open("admin_12Transport_1Uber.txt", ios::app);
    append << "\n"
           << locationFromUber[inc_opUberTransport]
           << "," << locationToUber[inc_opUberTransport]
           << "," << amountUber[inc_opUberTransport]
           << "," << purposeUber[inc_opUberTransport];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opUberTransport += 1;
} // end of function
void admin_12Transport_2Bus()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Transport > Bus " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Location from : ";
    cin >> locationFromBus[inc_opBusTransport];
    cout << "Location to: ";
    cin >> locationToBus[inc_opBusTransport];
    cout << "Ticket Price : ";
    amountBus[inc_opBusTransport] = float_Validaion("Ticket Price : ", amountBus[inc_opBusTransport]);
    cout << "Purpose : ";
    cin >> purposeBus[inc_opBusTransport];
    // File Handling
    fstream append;
    append.open("admin_12Transport_2Bus.txt", ios::app);
    append << "\n"
           << locationFromBus[inc_opBusTransport]
           << "," << locationToBus[inc_opBusTransport]
           << "," << amountBus[inc_opBusTransport]
           << "," << purposeBus[inc_opBusTransport];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opBusTransport += 1;
} // end of function
void admin_13RecreationalActivities()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Recreational Activities " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
} // end of function
void admin_13RecreationalActivities_1Sporties()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Recreational Activities > Sporties " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "How much time you service?" << endl;
    cout << "Minuties: ";
    minutiesSporties[inc_opSportiesActivities] = float_Validaion("Minuties: ", minutiesSporties[inc_opSportiesActivities]);
    // File Handling
    fstream append;
    append.open("admin_13RecreationalActivities_1Sporties.txt", ios::app);
    append << "\n"
           << minutiesSporties[inc_opSportiesActivities];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opSportiesActivities += 1;
} // end of function
void admin_13RecreationalActivities_2Socities()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Recreational Activities > Societies " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "How much time you service?" << endl;
    cout << "Minuties: ";
    minutiesSocieties[inc_opSocietiesActivities] = float_Validaion("Minuties: ", minutiesSocieties[inc_opSocietiesActivities]);
    cout << "Purpose: ";
    cin >> purposeSocieties[inc_opSocietiesActivities];
    // File Handling
    fstream append;
    append.open("admin_13RecreationalActivities_2Socities.txt", ios::app);
    append << minutiesSocieties[inc_opSocietiesActivities]
           << "," << purposeSocieties[inc_opSocietiesActivities]
           << "\n";
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opSocietiesActivities += 1;
} // end of function
void admin_14Achievments()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Achievements " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
} // end of function
void admin_14Achievments_1CoCurricular()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Achievements > Co-Curricular " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Award/Certificate: ";
    cin >> awardCo_Curricular[inc_opCoCurricular];
    cout << "Presented by: ";
    cin >> presentCo_Curricular[inc_opCoCurricular];
    cout << "Remarks: ";
    cin >> remarksCo_Curricular[inc_opCoCurricular];
    // File Handling
    fstream append;
    append.open("admin_14Achievments_1CoCurricular.txt", ios::app);
    append << "\n"
           << awardCo_Curricular[inc_opCoCurricular]
           << "," << presentCo_Curricular[inc_opCoCurricular]
           << "," << remarksCo_Curricular[inc_opCoCurricular];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opCoCurricular += 1;
} // end of function
void admin_14Achievments_2ExtraCurricular()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Achievements > Extra-Curricular " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Award/Certificate: ";
    cin >> awardExtra_Curricular[inc_opExtraCurricular];
    cout << "Presented by: ";
    cin >> presentExtra_Curricular[inc_opExtraCurricular];
    cout << "Remarks: ";
    cin >> remarksExtra_Curricular[inc_opExtraCurricular];
    // File Handling
    fstream append;
    append.open("admin_14Achievments_2ExtraCurricular.txt", ios::app);
    append << "\n"
           << awardExtra_Curricular[inc_opExtraCurricular]
           << "," << presentExtra_Curricular[inc_opExtraCurricular]
           << "," << remarksExtra_Curricular[inc_opExtraCurricular];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opExtraCurricular += 1;
} // end of function
void admin_15ResultGrades()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Result Grades " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "GPA : ";
    gpa[inc_opResultGrades] = float_Validaion("GPA : ", gpa[inc_opResultGrades]);
    cout << "CGPA : ";
    cgpa[inc_opResultGrades] = float_Validaion("CGPA : ", cgpa[inc_opResultGrades]);
    cout << "Remarks : ";
    cin >> remarksResult[inc_opResultGrades];
    // File Handling
    fstream append;
    append.open("admin_15ResultGrades.txt", ios::app);
    append << "\n"
           << gpa[inc_opResultGrades]
           << "," << cgpa[inc_opResultGrades]
           << "," << remarksResult[inc_opResultGrades];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opResultGrades += 1;
} // end of function
void admin_16GoldenLines()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Golden Lines " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Title : ";
    cin >> titleGoldenLines[inc_opGoldenLines];
    cout << "Description:";
    cin >> descriptionGoldenLines[inc_opGoldenLines];
    // File Handling
    fstream append;
    append.open("admin_16GoldenLines.txt", ios::app);
    append << "\n"
           << titleGoldenLines[inc_opGoldenLines]
           << "," << descriptionGoldenLines[inc_opGoldenLines];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opGoldenLines += 1;
} // end of function
void admin_17LifelongEvents()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Lifelong Events " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Title : ";
    cin >> titleLifelongEvents[inc_opLifelongEvents];
    cout << "Description:";
    cin >> descriptionLifelongEvents[inc_opLifelongEvents];
    // File Handling
    fstream append;
    append.open("admin_17LifelongEvents.txt", ios::app);
    append << "\n"
           << titleLifelongEvents[inc_opLifelongEvents]
           << "," << descriptionLifelongEvents[inc_opLifelongEvents];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opLifelongEvents += 1;
} // end of function
void admin_18Notes()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Notes " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Title : ";
    cin >> titleNotes[inc_opNotes];
    cout << "Description:";
    cin >> descriptionNotes[inc_opNotes];
    // File Handling
    fstream append;
    append.open("admin_18Notes.txt", ios::app);
    append << "\n"
           << titleNotes[inc_opNotes]
           << "," << descriptionNotes[inc_opNotes];
    append.close();
    cout << "Data sucessfully saved" << endl;
    inc_opNotes += 1;
} // end of function
void admin_19CreateAgentAccount()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > Create agent account" << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Enter first name : ";
    cin >> firstname_Agent[inc_opAgentAddUser];
    cout << "Enter last name : ";
    cin >> lastname_Agent[inc_opAgentAddUser];
    cout << "Enter username : ";
    cin >> username_Agent[inc_opAgentAddUser];
    // bool agent_check = check_Existing_agent(username_Agent[inc_opAgentAddUser]); // to make username unique
    while (check_Existing_agent(username_Agent[inc_opAgentAddUser]) == true)
    {
        cout << "Username is already exist try another once" << endl;
        cout << "Enter username : ";
        cin >> username_Agent[inc_opAgentAddUser];
    }
    cout << "Enter password :";
    cin >> password_Agent[inc_opAgentAddUser];
    // File Handling
    fstream append_opAgentAddAccount;
    append_opAgentAddAccount.open("agentSecurityFile.txt", ios::app);
    append_opAgentAddAccount << "\n"
                             << firstname_Agent[inc_opAgentAddUser] << "," << lastname_Agent[inc_opAgentAddUser] << "," << username_Agent[inc_opAgentAddUser] << "," << password_Agent[inc_opAgentAddUser];
    append_opAgentAddAccount.close();
    cout << "Account sucessfully created" << endl;
    inc_opAgentAddUser += 1;
} // end of function
//****************** ADMIN EXPLANATION ******************
string admin_Menu()
{
    string opAdmin; // admin option, store user input
    cout << "Choose Option" << endl;
    cout << "   0. Profile" << endl;
    cout << "   1. Wallet Status " << endl;
    cout << "   2. Expenses Report " << endl;
    cout << "   3. Academic Fee " << endl;
    cout << "   4. Hostel " << endl;
    cout << "   5. Helping Material" << endl;
    cout << "   6. Recreational Expenses" << endl;
    cout << "   7. Community Fund" << endl;
    cout << "   8. Goals" << endl;
    cout << "   9. Cell Phone" << endl;
    cout << "   10.Books" << endl;
    cout << "   11.Spiritual Food" << endl;
    cout << "   12.Transport" << endl;
    cout << "   13.Recreational Activities" << endl;
    cout << "   14.Achievements" << endl;
    cout << "   15.Result Grades" << endl;
    cout << "   16.Golden Lines" << endl;
    cout << "   17.Lifelong Events" << endl;
    cout << "   18.Notes" << endl;
    cout << "   19.Create agent account" << endl;
    cout << "   20.Logout" << endl;
    cout << "Choose option...";
    cin >> opAdmin;
    return opAdmin;
} // end of admin menu
char admin_ExpensesReportMenu()
{
    char opExpensesReport; // expenses report option , store user input
    cout << "Choose Option" << endl;
    cout << "   1. Today" << endl;
    cout << "   2. Month" << endl;
    cout << "   3. Year" << endl;
    cout << "Press 0 to Go Back...";
    cin >> opExpensesReport;
    return opExpensesReport;
} // end of admin expenses report menu function
char admin_HostelMenu()
{
    char opHostel; // Hostel option, store user input
    cout << "Choose Option" << endl;
    cout << "   1. Meal" << endl;
    cout << "   2. Monthly Meal Charges" << endl;
    cout << "   3. Living Charges" << endl;
    cout << "   4. Service  Charges" << endl;
    cout << "   5. Renovation Charges" << endl;
    cout << "   6. Laundry Charges" << endl;
    cout << "   7. Barber Charges" << endl;
    cout << "Press 0 to Go Back...";
    cin >> opHostel;
    return opHostel;
} // end of admin hostel menu function
char admin_Hostel_MealMenu()
{
    char opMeal; // meal option, store user input
    cout << "Choose Option" << endl;
    cout << "   1. Breakfast Charges" << endl;
    cout << "   2. Lunch Charges" << endl;
    cout << "   3. Dinner Charges" << endl;
    cout << "Press 0 to Go Back...";
    cin >> opMeal;
    return opMeal;
} // end of admin, hostel option of meal menu function
char admin_HelpingMaterialMenu()
{
    char opHelpingMaterial; // helping material, store user input
    cout << "Choose Option" << endl;
    cout << "   1. Notes" << endl;
    cout << "   2. Register" << endl;
    cout << "   3. Stationary" << endl;
    cout << "Press 0 to Go Back...";
    cin >> opHelpingMaterial;
    return opHelpingMaterial;
} // end of admin,helping material menu function
char admin_RecreationalExpesesMenu()
{
    char opRecreationalExpenses; // recreational expenses option, store user input
    cout << "Choose Option" << endl;
    cout << "   1. Friend" << endl;
    cout << "   2. Family" << endl;
    cout << "Press 0 to Go Back...";
    cin >> opRecreationalExpenses;
    return opRecreationalExpenses;
} // end of admin,recreational expenses menu function
char admin_CommunityFundMenu()
{
    char opCommunityFund; // community fund option, store user input
    cout << "Choose Option" << endl;
    cout << "   1. Class" << endl;
    cout << "   2. Societies" << endl;
    cout << "Press 0 to Go Back...";
    cin >> opCommunityFund;
    return opCommunityFund;
} // end of admin,community fund function
char admin_GoalsMenu()
{
    char opGoals; // goals, store user input
    cout << "Choose Option" << endl;
    cout << "   1. Daily" << endl;
    cout << "   2. Weekly" << endl;
    cout << "   3. Monthly" << endl;
    cout << "   4. Yearly" << endl;
    cout << "Press 0 to Go Back...";
    cin >> opGoals;
    return opGoals;
} // end of admin, goals menu function
char admin_CellPhoneMenu()
{
    char opCellPhone; // cell phone option,store user input
    cout << "Choose Option" << endl;
    cout << "   1. Call Package" << endl;
    cout << "   2. Internet Package" << endl;
    cout << "   3. Message Package" << endl;
    cout << "Press 0 to Go Back...";
    cin >> opCellPhone;
    return opCellPhone;
} // end of admin,cell phone menu function
char admin_BookMenu()
{
    char opBook; // book option of admin option
    cout << "Choose Option" << endl;
    cout << "   1. Borrow" << endl;
    cout << "   2. Purchase" << endl;
    cout << "Press 0 to Go Back...";
    cin >> opBook;
    return opBook;
} // end of admin, book menu function
char admin_SelfMotivationalMenu()
{
    char opSelfMotivational; // self motivational option of admin menu option,store user input
    cout << "Choose Option" << endl;
    cout << "   1. Five-time Prayer" << endl;
    cout << "   2. Quran-e-Pak Recitation" << endl;
    cout << "   3. Durood-e-Pak" << endl;
    cout << "Press 0 to Go Back...";
    cin >> opSelfMotivational;
    return opSelfMotivational;
} // end of admin,self motivational menu function
char admin_TransportMenu()
{
    char opTransport; // transport option of admin menu option
    cout << "Choose Option" << endl;
    cout << "   1. Uber/Cream/Bykea" << endl;
    cout << "   2. Bus" << endl;
    cout << "Press 0 to Go Back...";
    cin >> opTransport;
    return opTransport;
} // end of admin, transport menu funtion
char admin_RecerationActivitiesMenu()
{
    char opRecreationalActivities; // recreational activities option of admin menu option,store user input
    cout << "Choose Option" << endl;
    cout << "   1. Sporties" << endl;
    cout << "   2. Societies" << endl;
    cout << "Press 0 to Go Back...";
    cin >> opRecreationalActivities;
    return opRecreationalActivities;
} // end of admin, recreational activities menu function
char admin_Achievemnets()
{
    char opAchievements; // achievments option of admin menu option,store user input
    cout << "Choose Option" << endl;
    cout << "   1. Co-Curricular" << endl;
    cout << "   2. Extra- Curricular" << endl;
    cout << "Press 0 to Go Back...";
    cin >> opAchievements;
    return opAchievements;
} // end of admin,achievments menu function
void display_profile_admin()
{
    if (titleDailyGoals->empty() && descriptionDailyGoals->empty())
    { // totday goal
        cout << "Today goals data is not avilable" << endl;
    }
    else
    {
        if (descriptionDailyGoals->empty())
        {
            cout << "Today goals data is not avilable" << endl;
        }
        else
        {
            cout << "Today Goals..." << endl;
            for (int i = 0; i < inc_opDailyGoals; i++)
            {
                cout << "        Title:" << titleDailyGoals[i] << endl;
                cout << "Discription:" << descriptionDailyGoals[i] << endl;
            }
        }
    }
    cout << "_____________________________________________________________________________________" << endl;
    if (titleWeeklyGoals->empty() && descriptionWeeklyGoals->empty())
    { // weekly goal
        cout << "Weekly goals data is not avilable" << endl;
    }
    else
    {
        if (descriptionWeeklyGoals->empty())
        {
            cout << "Weekly goals data is not avilable" << endl;
        }
        else
        {
            cout << "Weekly Goals..." << endl;
            for (int i = 0; i < inc_opWeeklyGoals; i++)
            {
                cout << "        Title:" << titleWeeklyGoals[i] << endl;
                cout << "Discription:" << descriptionWeeklyGoals[i] << endl;
            }
        }
    }
    cout << "_____________________________________________________________________________________" << endl;
    if (titleMonthlyGoals->empty() && descriptionMonthlyGoals->empty())
    { // Monthly goal
        cout << "Monthly goals data is not avilable" << endl;
    }
    else
    {
        if (descriptionMonthlyGoals->empty())
        {
            cout << "Monthly goals data is not avilable" << endl;
        }
        else
        {
            cout << "Monthly Goals..." << endl;
            for (int i = 0; i < inc_opMonthlyGoals; i++)
            {
                cout << "        Title:" << titleMonthlyGoals[i] << endl;
                cout << "Discription:" << descriptionMonthlyGoals[i] << endl;
            }
        }
    }
    cout << "_____________________________________________________________________________________" << endl;
    if (titleYearlyGoals->empty() && descriptionYearlyGoals->empty())
    { // Yearly goal
        cout << "Yearly goals data is not avilable" << endl;
    }
    else
    {
        if (descriptionYearlyGoals->empty())
        {
            cout << "Yearly goals data is not avilable" << endl;
        }
        else
        {
            cout << "Yearly Goals..." << endl;
            for (int i = 0; i < inc_opYearlyGoals; i++)
            {
                cout << "        Title:" << titleYearlyGoals[i] << endl;
                cout << "Discription:" << descriptionYearlyGoals[i] << endl;
            }
        }
    }
    cout << "_____________________________________________________________________________________" << endl;
} // end of profile admin option
//****************** RECOMMENDATIOM ******************
void admin_Recommendation()
{
    if (addWalletMoney >= 0 && addWalletMoney <= 200)
    {
        cout << "You have low money...!" << endl;
    }
    for (int i = 0; i < inc_opResultGrades; i++)
    {
        if (gpa[i] < 2.0 || cgpa[i < 2.0])
        {
            cout << "Work hard...You can do it!!!" << endl;
        }
    }
}
//********************* AGENT FUNCTIONS ************************
void agent_0Profile(int agentindex)
{
    header(); // header function is called
    cout << "Main Menu > Agent > Menu > Profile" << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "                                 __WELCOME ON BOARD__                             " << endl;
    cout << "First name : " << firstname_Agent[agentindex] << "\t";
    cout << "Last name : " << lastname_Agent[agentindex] << endl;
} // end of functions
void agent_1Wallet()
{
    header(); // header function is called
    cout << "Main Menu > Agent > Menu > Wallet  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Current Balance:" << endl;
    cout << "Add Balance: ";
    addWalletMoney = float_Validaion("Add Balance: ", addWalletMoney); // wallet money will show in admin wallet status
    cout << "Remarks: ";
    cin >> walletRemarks; // remaks will show in admin wallet status
    // File Handling
    fstream write_opWallet;
    write_opWallet.open("agentWalletMoney.txt", ios::out);
    write_opWallet << addWalletMoney << "," << walletRemarks;
    write_opWallet.close();
    cout << "Data sucessfully saved" << endl;
} // end of functions
void agent_2AcademicReport()
{
    header(); // header function is called
    cout << "Main Menu > Agent > Menu > Academic Report  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    if (gpa[0] == 0 && cgpa[0] == 0)
    {
        cout << "Data is not avilable" << endl;
    }
    else
    {
        cout << "Sr.No \tGPA \tCGPA \tRemarks" << endl;
        for (int i = 0; i < inc_opResultGrades; i++)
        {
            cout << i + 1 << "\t" << gpa[i] << "\t" << cgpa[i] << "\t" << remarksResult[i] << endl;
        }
    }
} // end of functions
void agent_3ExpensesReport()
{
    header(); // header function is called
    cout << "Main Menu > Admin > Menu > ExpensesReport > Monthly" << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Monthly Report :- " << endl;
    cout << "Personal................: " << personal_Expenses() << endl;
    cout << "Hostel..................: " << hostel_Expenses() << endl;
    cout << "Helping Material........: " << helpingmaterial_Expenses() << endl;
    cout << "Recreational Expenses...: " << recreational_Expenses() << endl;
    cout << "Fund....................: " << communityfund_Expenses() << endl;
    cout << "Cell Phone..............: " << cellphone_Expenses() << endl;
    cout << "Transport...............: " << transport_Expenses() << endl;
    cout << "                   Total: " << total_Expenses() << endl;
} // end of functions
void agent_4MealReport()
{
    header(); // header function is called
    cout << "Main Menu > Agent > Menu >  Meal Report  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    if (menuBreakfast->empty() && menuLunch->empty() && menuDinner->empty())
    {
        cout << "Data is not avilable" << endl;
    }
    else
    {
        if (menuBreakfast->empty())
        {
            cout << "Breakfast data is not avilable" << endl;
        }
        else
        {
            cout << "Sr.No \tBreakfast Menu \tRemarks \tCharges" << endl;
            for (int i = 0; i < increment_opMealBreakfast; i++)
            {
                cout << i + 1 << "\t" << menuBreakfast[i] << "\t\t" << remarksBreakfast[i] << "\t\t" << chargesBreakfast[i] << endl;
            }
        }
        if (menuLunch->empty())
        {
            cout << "__________________________" << endl;
            cout << "Lunch data is not avilable" << endl;
        }
        else
        {
            cout << "________________________________________________" << endl;
            cout << "Sr.No \tLunch Menu \tRemarks \tCharges" << endl;

            for (int i = 0; i < increment_opMealLunch; i++)
            {
                cout << i + 1 << "\t" << menuLunch[i] << "\t\t" << remarksLunch[i] << "\t\t" << chargesLunch[i] << endl;
            }
        }
        if (menuDinner->empty())
        {
            cout << "____________________________" << endl;
            cout << "Dinner data is not avilable" << endl;
        }
        else
        {
            cout << "________________________________________________" << endl;
            cout << "Sr.No \tDinner Menu \tRemarks \tCharges" << endl;
            for (int i = 0; i < increment_opMealDinner; i++)
            {
                cout << i + 1 << "\t" << menuDinner[i] << "\t\t" << remarksDinner[i] << "\t\t" << chargesDinner[i] << endl;
            }
        }
    }
    cout << "________________________________________________" << endl;
} // end of functions
void agent_5SpiritualTracker()
{
    header(); // header function is called
    cout << "Main Menu > Agent > Menu > Spiritual Tracker  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    cout << "Summary..." << endl;
    if (five_time_Prayer->empty() && Quran_e_Pak->empty() && Durood_e_Pak->empty())
    {
        cout << "Data is not avilable" << endl;
    }
    else
    {
        if (five_time_Prayer->empty())
        {
            cout << "Salah tracker data is not avilable" << endl;
        }
        else
        {
            cout << "Sr.No \tSalah Tracker..." << endl;
            for (int i = 0; i < inc_opFiveTimePrayer; i++)
            {
                cout << i + 1 << "\t" << five_time_Prayer[i] << endl;
            }
        }
        if (Quran_e_Pak->empty())
        {
            cout << "Quran-e-Pak tracker data is not avilable" << endl;
        }
        else
        {
            cout << "__________________________________" << endl;
            cout << "Sr.No \tQuran-e-Pak Tracker..." << endl;
            for (int i = 0; i < inc_opQuran_e_Pak; i++)
            {
                cout << i + 1 << "\t" << Quran_e_Pak[i] << endl;
            }
        }
        if (Durood_e_Pak->empty())
        {
            cout << "Durood-e-Pak tracker data is not avilable" << endl;
        }
        else
        {
            cout << "__________________________________" << endl;
            cout << "Sr.No \tDurood-e-Pak Tracker..." << endl;
            for (int i = 0; i < inc_opDurood_e_Pak; i++)
            {
                cout << i + 1 << "\t" << Durood_e_Pak[i] << endl;
            }
        }
    }
    cout << "__________________________________" << endl;
} // end of functions
void agent_6AachieventsReport()
{
    header(); // header function is called
    cout << "Main Menu > Agent > Menu > Achievments Report  " << endl;
    cout << "__________ . __________ . __________ . _________ . __________ . _________ . _________" << endl;
    if (awardCo_Curricular->empty() && awardExtra_Curricular->empty() && remarksCo_Curricular->empty() && remarksExtra_Curricular->empty())
    {
        cout << "Data is not avilable" << endl;
    }
    else
    {
        if (awardCo_Curricular->empty())
        {
            cout << "Co-curricular achievements data is not avilable" << endl;
        }
        else
        {
            cout << "Co-Curricular Achievements..." << endl;
            cout << "Sr.No \tAward/Certificate \tPresented by \tRemarks " << endl;
            for (int i = 0; i < inc_opCoCurricular; i++)
            {
                cout << i + 1 << "\t" << awardCo_Curricular[i] << "\t\t\t" << presentCo_Curricular[i] << "\t\t" << remarksCo_Curricular[i] << endl;
            }
        }
        if (awardExtra_Curricular->empty())
        {
            cout << "Extra-curricular achievements data is not avilable" << endl;
        }
        else
        {
            cout << "________________________________________________" << endl;
            cout << "Sr.No \tAward/Certificate \tPresented by \tRemarks " << endl;
            for (int i = 0; i < inc_opExtraCurricular; i++)
            {
                cout << i + 1 << "\t" << awardExtra_Curricular[i] << "\t\t\t" << presentExtra_Curricular[i] << "\t\t" << remarksExtra_Curricular[i] << endl;
            }
        }
    }
    cout << "________________________________________________" << endl;
} // end of functions
//****************** AGENT FUNCTION EXPLANATION ******************
string agent_Menu()
{
    string opAgent; // option Agent
    cout << "Choose Option" << endl;
    cout << "   0. Profile" << endl;
    cout << "   1. Wallet" << endl;
    cout << "   2. Academic Report" << endl;
    cout << "   3. Expenese Report" << endl;
    cout << "   4. Meal Report" << endl;
    cout << "   5. Spiritual Tracker" << endl;
    cout << "   6. Aachievments Report" << endl;
    cout << "   7. Logout" << endl;
    cout << "Choose option...";
    cin >> opAgent;
    return opAgent;
} // end of agent menu function
//********************* ADMIN & AGENT FUNCTION ************************
int personal_Expenses()
{
    float personalExpenses = 0.0; // sum of purchase book + academic fee
    float purchasebook = 0.0, academicfee = 0.0;
    for (int i = 0; i < inc_opBookPurchase; i++)
    {
        purchasebook += amountPurchaseBook[i];
    }
    for (int i = 0; i < increment_opAcademicFee; i++)
    {
        academicfee += amountacademic[i];
    }
    personalExpenses = purchasebook + (academicfee / 6);
    return personalExpenses;
} // end of personal expenses function
int hostel_Expenses()
{
    float hostelExpenses = 0.0; // sum of breakfast + lunch + dinner + mealMonthly + livingMonthly + serviceMonthly + renovationMonthly + laundryMonthly + barbermonthly
    float breakfast = 0.0, lunch = 0.0, dinner = 0.0, mealMonthly = 0.0, livingMonthly = 0.0, serviceMonthly = 0.0, renovationMonthly = 0.0, laundryMonthly = 0.0, barbermonthly = 0.0;
    for (int i = 0; i < increment_opMealBreakfast; i++)
    {
        breakfast += chargesBreakfast[i];
    }
    for (int i = 0; i < increment_opMealLunch; i++)
    {
        lunch += chargesLunch[i];
    }
    for (int i = 0; i < increment_opMealDinner; i++)
    {
        dinner += chargesDinner[i];
    }
    for (int i = 0; i < increment_opMealCharges; i++)
    {
        mealMonthly += chargesMealMonthly[i];
    }
    for (int i = 0; i < inc_opLivingCharges; i++)
    {
        livingMonthly += chargesLivingExpenses[i];
    }
    for (int i = 0; i < inc_opServiceCharges; i++)
    {
        serviceMonthly += chargesServiceMonthly[i];
    }
    for (int i = 0; i < inc_opRenovationCharges; i++)
    {
        renovationMonthly += chargesRenovationMonthly[i];
    }
    for (int i = 0; i < inc_opLaundryCharges; i++)
    {
        laundryMonthly += chargesLaundryMonthly[i];
    }
    for (int i = 0; i < inc_opBarberCharges; i++)
    {
        barbermonthly += chargesBarberMonthly[i];
    }
    hostelExpenses = breakfast + lunch + dinner + mealMonthly + livingMonthly + serviceMonthly + renovationMonthly + laundryMonthly + barbermonthly;
    return hostelExpenses;
} // end of hostel expenses function
int helpingmaterial_Expenses()
{
    float helpingmaterialExpenses = 0.0; // sum of notes + register_ + stationary
    float notes = 0.0, register_ = 0.0, stationary = 0.0;
    for (int i = 0; i < inc_opNotesHelpingMaterial; i++)
    {
        notes = chargesNotesMonthly[i];
    }
    for (int i = 0; i < inc_opRegisterHelpingMaterial; i++)
    {
        register_ = chargesRegisterMonthly[i];
    }
    for (int i = 0; i < inc_opStationaryHelpingMaterial; i++)
    {
        stationary = chargesStationaryMonthly[i];
    }
    helpingmaterialExpenses = notes + register_ + stationary;
    return helpingmaterialExpenses;
} // end of helping material function
int recreational_Expenses()
{
    float recreationalExpenses = 0.0; // sum of friends + family
    float friends = 0.0, family = 0.0;
    for (int i = 0; i < inc_opFriendsRecreationalExpenses; i++)
    {
        friends = chargesFriendsRecreationalExpenses[i];
    }
    for (int i = 0; i < inc_opFamilyRecreationalExpenses; i++)
    {
        family = chargesFamilyRecreationalExpenses[i];
    }
    recreationalExpenses = friends + family;
    return recreationalExpenses;
} // end of recreational expenses function
int communityfund_Expenses()
{
    float communityfundExpenses = 0.0; // sum of classes + socities
    float classes = 0.0, socities = 0.0;
    for (int i = 0; i < inc_opClassCommunityFund; i++)
    {
        classes = chargesClassCommunityFund[i];
    }
    for (int i = 0; i < inc_opSocietiesCommunityFund; i++)
    {
        socities = chargesSocietiesCommunityFund[i];
    }
    communityfundExpenses = classes + socities;
    return communityfundExpenses;
} // end of community fund expenses function
int cellphone_Expenses()
{
    float cellphoneExpenses = 0.0; // sum of call + internet + message
    float call = 0.0, internet = 0.0, message = 0.0;
    for (int i = 0; i < inc_opCall_CellPhone; i++)
    {
        call = amountCallPakage[i];
    }
    for (int i = 0; i < inc_opInternet_CellPhone; i++)
    {
        internet = amountInternetPakage[i];
    }
    for (int i = 0; i < inc_opMessage_CellPhone; i++)
    {
        message = amountMessagePakage[i];
    }
    cellphoneExpenses = call + internet + message;
    return cellphoneExpenses;
} // end of cell phone expenses function
int transport_Expenses()
{
    float transportExpenses = 0.0; // sum of uber + bus
    float uber = 0.0, bus = 0.0;
    for (int i = 0; i < inc_opUberTransport; i++)
    {
        uber = amountUber[i];
    }
    for (int i = 0; i < inc_opBusTransport; i++)
    {
        bus = amountBus[i];
    }
    transportExpenses = uber + bus;
    return transportExpenses;
} // end of transport expenses function
int total_Expenses()

{
    int totalExpenses = 0.0; // sum of  personalExpenses + hostelExpenses + helpingmaterialExpenses + recreationalExpenses + communityfundExpenses + cellphoneExpenses + transportExpenses
    totalExpenses = personal_Expenses() + hostel_Expenses() + helpingmaterial_Expenses() + recreational_Expenses() + communityfund_Expenses() + cellphone_Expenses() + transport_Expenses();
    //totalExpenses = totalExpenses - addWalletMoney;
    return totalExpenses;
} // end of total expneses function
  //********************* SORTING FUNCTION ************************
void sort_academicFee()
{
    for (int i = 0; i < increment_opAcademicFee; i++)
    {
        for (int j = i + 1; j < increment_opAcademicFee; j++)
        {
            if (amountacademic[j] > amountacademic[i])
            {
                float temp = amountacademic[i];
                amountacademic[i] = amountacademic[j];
                amountacademic[j] = temp;
                // semester type sort
                string temp_type = semesterType[i];
                semesterType[i] = semesterType[j];
                semesterType[j] = temp_type;
                // challan no sort
                temp_type = challanNo[i];
                challanNo[i] = challanNo[j];
                challanNo[j] = temp_type;
                // date sort
                temp_type = date[i];
                date[i] = date[j];
                date[j] = temp_type;
                // remarks sort
                temp_type = remarks[i];
                remarks[i] = remarks[j];
                remarks[j] = temp_type;
            }
        }
    }
} // end of academic fee function
void display_academicFee()
{
    sort_academicFee();
    cout << "Sr.No \tSemester type \tChallan no \tDate \tAmount \tRemarks" << endl;
    for (int i = 0; i < increment_opAcademicFee; i++)
    {
        cout << i + 1 << "\t" << semesterType[i] << "\t\t" << challanNo[i] << "\t\t" << date[i] << "\t" << amountacademic[i] << "\t" << remarks[i] << endl;
    }
} // end of display academic fee function
void sort_breakfast()
{
    for (int i = 0; i < increment_opMealBreakfast; i++)
    {
        for (int j = i + 1; j < increment_opMealBreakfast; j++)
        {
            if (chargesBreakfast[j] > chargesBreakfast[i])
            {
                float temp = chargesBreakfast[i];
                chargesBreakfast[i] = chargesBreakfast[j];
                chargesBreakfast[j] = temp;
                //  menu sort
                string temp_st = menuBreakfast[i];
                menuBreakfast[i] = menuBreakfast[j];
                menuBreakfast[j] = temp_st;
                // remarks no sort
                temp_st = remarksBreakfast[i];
                remarksBreakfast[i] = remarksBreakfast[j];
                remarksBreakfast[j] = temp_st;
            }
        }
    }
} // end of sorting breakfast function
void display_breakfast()
{
    sort_breakfast();
    cout << "Sr.No \tBreakfast menu \tCharges\tRemarks" << endl;
    for (int i = 0; i < increment_opMealBreakfast; i++)
    {
        cout << i + 1 << "\t" << menuBreakfast[i] << "\t\t" << chargesBreakfast[i] << "\t" << remarksBreakfast[i] << endl;
    }
} // end of display breakfast function
void sort_lunch()
{
    for (int i = 0; i < increment_opMealLunch; i++)
    {
        for (int j = i + 1; j < increment_opMealLunch; j++)
        {
            if (chargesLunch[j] > chargesLunch[i])
            {
                float temp = chargesLunch[i];
                chargesLunch[i] = chargesLunch[j];
                chargesLunch[j] = temp;
                //  menu sort
                string temp_st = menuLunch[i];
                menuLunch[i] = menuLunch[j];
                menuLunch[j] = temp_st;
                // remarks no sort
                temp_st = remarksLunch[i];
                remarksLunch[i] = remarksLunch[j];
                remarksLunch[j] = temp_st;
            }
        }
    }
} // end of sort of lunch function
void display_lunch()
{
    sort_lunch();
    cout << "Sr.No \tLunch menu \tCharges\tRemarks" << endl;
    for (int i = 0; i < increment_opMealLunch; i++)
    {
        cout << i + 1 << "\t" << menuLunch[i] << "\t\t" << chargesLunch[i] << "\t" << remarksLunch[i] << endl;
    }
} // end of display function
void sort_dinner()
{
    for (int i = 0; i < increment_opMealDinner; i++)
    {
        for (int j = i + 1; j < increment_opMealDinner; j++)
        {
            if (chargesDinner[j] > chargesDinner[i])
            {
                float temp = chargesDinner[i];
                chargesDinner[i] = chargesDinner[j];
                chargesDinner[j] = temp;
                //  menu sort
                string temp_st = menuDinner[i];
                menuDinner[i] = menuDinner[j];
                menuDinner[j] = temp_st;
                // remarks no sort
                temp_st = remarksDinner[i];
                remarksDinner[i] = remarksDinner[j];
                remarksDinner[j] = temp_st;
            }
        }
    }
} // end of sort dinner function
void display_dinner()
{
    sort_dinner();
    cout << "Sr.No \tDinner menu \tCharges\tRemarks" << endl;
    for (int i = 0; i < increment_opMealDinner; i++)
    {
        cout << i + 1 << "\t" << menuDinner[i] << "\t\t" << chargesDinner[i] << "\t" << remarksDinner[i] << endl;
    }
} // display dinner function
  // ****************** FILE HANDLING ******************
string seperateField(string record, int fieldNumber)
{
    int count = 1;
    string value;
    for (int i = 0; i < record.length(); i++)
    {
        if (record[i] == ',')
        {
            count++;
        }
        else if (count == fieldNumber)
        {
            value = value + record[i];
        }
    }
    return value;
} // end of function
void load_adminSecurityFile()
{
    // File Handling
    string record;
    int i = 0;
    fstream read_opAccount;
    read_opAccount.open("adminSecurityFile.txt", ios::in);
    while (!read_opAccount.eof())
    {
        getline(read_opAccount, record);
        firstname[i] = seperateField(record, 1); // username field
        lastname[i] = seperateField(record, 2);  // password field
        username[i] = seperateField(record, 3);  // username field
        password[i] = seperateField(record, 4);  // password field
        i++;
    }
    read_opAccount.close();
} // end of function
void load_agentSecurityFile()
{
    string record;
    int i = 0;
    fstream read_opAgentAddUser;
    read_opAgentAddUser.open("agentSecurityFile.txt", ios::in);
    while (!read_opAgentAddUser.eof())
    {
        getline(read_opAgentAddUser, record);
        firstname_Agent[i] = seperateField(record, 1); // create an account store firstname
        lastname_Agent[i] = seperateField(record, 2);  // create an account store lastname
        username_Agent[i] = seperateField(record, 3);  // username field
        password_Agent[i] = seperateField(record, 4);  // password field
        i++;
    }
    read_opAgentAddUser.close();
} // end of function
void load_agentWalletMoney()
{
    string record;
    fstream read_opWallet;
    read_opWallet.open("agentWalletMoney.txt", ios::in);
    while (!read_opWallet.eof())
    {
        getline(read_opWallet, record);
        addWalletMoney = stof(seperateField(record, 1));
        walletRemarks = seperateField(record, 2);
    }
    read_opWallet.close();
} // end of function
void load_admin3AcadmicFee()
{
    string record;
    fstream read;
    read.open("admin3AcadmicFee.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        semesterType[increment_opAcademicFee] = seperateField(record, 1);
        challanNo[increment_opAcademicFee] = seperateField(record, 2);
        amountacademic[increment_opAcademicFee] = stof(seperateField(record, 3));
        date[increment_opAcademicFee] = seperateField(record, 4);
        remarks[increment_opAcademicFee] = seperateField(record, 5);
        increment_opAcademicFee++;
    }
    read.close();
} // end of function
void load_admin_4Hostel_1Meal_1Breakfast()
{
    string record;
    fstream read;
    read.open("admin_4Hostel_1Meal_1Breakfast.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        menuBreakfast[increment_opMealBreakfast] = seperateField(record, 1);
        chargesBreakfast[increment_opMealBreakfast] = stof(seperateField(record, 2));
        remarksBreakfast[increment_opMealBreakfast] = seperateField(record, 3);
        increment_opMealBreakfast++;
    }
    read.close();
} // end of function
void load_admin_4Hostel_1Meal_2Lunch()
{
    string record;
    fstream read;
    read.open("admin_4Hostel_1Meal_2Lunch.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        menuLunch[increment_opMealLunch] = seperateField(record, 1);
        chargesLunch[increment_opMealLunch] = stof(seperateField(record, 2));
        remarksLunch[increment_opMealLunch] = seperateField(record, 3);
        increment_opMealLunch++;
    }
    read.close();
} // end of function
void load_admin_4Hostel_1Meal_3Dinner()
{
    string record;
    fstream read;
    read.open("admin_4Hostel_1Meal_3Dinner.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        menuDinner[increment_opMealDinner] = seperateField(record, 1);
        chargesDinner[increment_opMealDinner] = stof(seperateField(record, 2));
        remarksDinner[increment_opMealDinner] = seperateField(record, 3);
        increment_opMealDinner++;
    }
    read.close();
} // end of function
void load_admin_4Hostel_2MealChargesMonthly()
{
    string record;
    fstream read;
    read.open("admin_4Hostel_2MealChargesMonthly.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        monthlyMealExpenses[increment_opMealCharges] = seperateField(record, 1);
        chargesMealMonthly[increment_opMealCharges] = stof(seperateField(record, 2));
        remarksMealExpenses[increment_opMealCharges] = seperateField(record, 3);
        increment_opMealCharges++;
    }
    read.close();
} // end of function
void load_admin_4Hostel_3LivingChargesMonthly()
{
    string record;
    fstream read;
    read.open("admin_4Hostel_3LivingChargesMonthly.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        monthLivingExpenses[inc_opLivingCharges] = seperateField(record, 1);
        chargesLivingExpenses[inc_opLivingCharges] = stof(seperateField(record, 2));
        remarksLivingExpenses[inc_opLivingCharges] = seperateField(record, 3);
        inc_opLivingCharges++;
    }
    read.close();
}
void load_admin_4Hostel_4ServiceChargesMonthly()
{
    string record;
    fstream read;
    read.open("admin_4Hostel_4ServiceChargesMonthly.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        monthServiceExpenses[inc_opServiceCharges] = seperateField(record, 1);
        chargesServiceMonthly[inc_opServiceCharges] = stof(seperateField(record, 2));
        remarksServiceExpenses[inc_opServiceCharges] = seperateField(record, 3);
        inc_opServiceCharges++;
    }
    read.close();
}
void load_admin_4Hostel_5RenovationChargesMonthly()
{
    string record;
    fstream read;
    read.open("admin_4Hostel_5RenovationChargesMonthly.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        chargesRenovationMonthly[inc_opRenovationCharges] = stof(seperateField(record, 1));
        remarksRenovationExpenses[inc_opRenovationCharges] = seperateField(record, 2);
        inc_opRenovationCharges++;
    }
    read.close();
}
void load_admin_4Hostel_6LaundryChargesMonthly()
{
    string record;
    fstream read;
    read.open("admin_4Hostel_6LaundryChargesMonthly.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        chargesLaundryMonthly[inc_opLaundryCharges] = stof(seperateField(record, 1));
        remarksLaundryExpenses[inc_opLaundryCharges] = seperateField(record, 2);
        inc_opLaundryCharges++;
    }
    read.close();
}
void load_admin_4Hostel_7BarberChargesMonthly()
{
    string record;
    fstream read;
    read.open("admin_4Hostel_7BarberChargesMonthly.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        chargesBarberMonthly[inc_opBarberCharges] = stof(seperateField(record, 1));
        remarksBarberExpenses[inc_opBarberCharges] = seperateField(record, 2);
        inc_opBarberCharges++;
    }
    read.close();
}
void load_admin_5HelpingMaterial_1Notes()
{
    string record;
    fstream read;
    read.open("admin_5HelpingMaterial_1Notes.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        chargesNotesMonthly[inc_opNotesHelpingMaterial] = stof(seperateField(record, 1));
        remarksNotesExpenses[inc_opNotesHelpingMaterial] = seperateField(record, 2);
        inc_opNotesHelpingMaterial++;
    }
    read.close();
}
void load_admin_5HelpingMaterial_2Register()
{
    string record;
    fstream read;
    read.open("admin_5HelpingMaterial_2Register.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        chargesRegisterMonthly[inc_opRegisterHelpingMaterial] = stof(seperateField(record, 1));
        remarksRegisterExpenses[inc_opRegisterHelpingMaterial] = seperateField(record, 2);
        inc_opRegisterHelpingMaterial++;
    }
    read.close();
}
void load_admin_5HelpingMaterial_3Stationary()
{
    string record;
    fstream read;
    read.open("admin_5HelpingMaterial_3Stationary.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        chargesStationaryMonthly[inc_opStationaryHelpingMaterial] = stof(seperateField(record, 1));
        remarksStationaryExpenses[inc_opStationaryHelpingMaterial] = seperateField(record, 2);
        inc_opStationaryHelpingMaterial++;
    }
    read.close();
}
void load_admin_6RecreationalExpenses_1Friends()
{
    string record;
    fstream read;
    read.open("admin_6RecreationalExpenses_1Friends.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        chargesFriendsRecreationalExpenses[inc_opFriendsRecreationalExpenses] = stof(seperateField(record, 1));
        remarksFriendsRecreationalExpenses[inc_opFriendsRecreationalExpenses] = seperateField(record, 2);
        inc_opFriendsRecreationalExpenses++;
    }
    read.close();
}
void load_admin_6RecreationalExpenses_2Family()
{
    string record;
    fstream read;
    read.open("admin_6RecreationalExpenses_2Family.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        chargesFamilyRecreationalExpenses[inc_opFamilyRecreationalExpenses] = stof(seperateField(record, 1));
        remarksFamilyRecreationalExpenses[inc_opFamilyRecreationalExpenses] = seperateField(record, 2);
        inc_opFamilyRecreationalExpenses++;
    }
    read.close();
}
void load_admin_7CommunityFund_1Class()
{
    string record;
    fstream read;
    read.open("admin_7CommunityFund_1Class.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        remarksClassCommunityFund[inc_opClassCommunityFund] = seperateField(record, 1);
        chargesClassCommunityFund[inc_opClassCommunityFund] = stof(seperateField(record, 2));
        inc_opClassCommunityFund++;
    }
    read.close();
}
void load_admin_7CommunityFund_2Societies()
{
    string record;
    fstream read;
    read.open("admin_7CommunityFund_2Societies.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        remarksSocietiesCommunityFund[inc_opSocietiesCommunityFund] = seperateField(record, 1);
        chargesSocietiesCommunityFund[inc_opSocietiesCommunityFund] = stof(seperateField(record, 2));
        inc_opSocietiesCommunityFund++;
    }
    read.close();
}
void load_admin_8Goals_1Daily()
{
    string record;
    fstream read;
    read.open("admin_8Goals_1Daily.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        titleDailyGoals[inc_opDailyGoals] = seperateField(record, 1);
        descriptionDailyGoals[inc_opDailyGoals] = seperateField(record, 2);
        inc_opDailyGoals++;
    }
    read.close();
}
void load_admin_8Goals_2Weekly()
{
    string record;
    fstream read;
    read.open("admin_8Goals_2Weekly.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        titleWeeklyGoals[inc_opWeeklyGoals] = seperateField(record, 1);
        descriptionWeeklyGoals[inc_opWeeklyGoals] = seperateField(record, 2);
        inc_opWeeklyGoals++;
    }
    read.close();
}
void load_admin_8Goals_3Monthly()
{
    string record;
    fstream read;
    read.open("admin_8Goals_3Monthly.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        titleMonthlyGoals[inc_opMonthlyGoals] = seperateField(record, 1);
        descriptionMonthlyGoals[inc_opMonthlyGoals] = seperateField(record, 2);
        inc_opMonthlyGoals++;
    }
    read.close();
}
void load_admin_8Goals_4Yearly()
{
    string record;
    fstream read;
    read.open("admin_8Goals_4Yearly.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        titleYearlyGoals[inc_opYearlyGoals] = seperateField(record, 1);
        descriptionYearlyGoals[inc_opYearlyGoals] = seperateField(record, 2);
        inc_opYearlyGoals++;
    }
    read.close();
}
void load_admin_9CellPhone_1Call()
{
    string record;
    fstream read;
    read.open("admin_9CellPhone_1Call.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        nameCallPakage[inc_opCall_CellPhone] = seperateField(record, 1);
        amountCallPakage[inc_opCall_CellPhone] = stof(seperateField(record, 2));
        durationCallPakage[inc_opCall_CellPhone] = seperateField(record, 3);
        inc_opCall_CellPhone++;
    }
    read.close();
}
void load_admin_9CellPhone_2Internet()
{
    string record;
    fstream read;
    read.open("admin_9CellPhone_2Internet.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        nameInternetPakage[inc_opInternet_CellPhone] = seperateField(record, 1);
        amountInternetPakage[inc_opInternet_CellPhone] = stof(seperateField(record, 2));
        durationInternetPakage[inc_opInternet_CellPhone] = seperateField(record, 3);
        inc_opInternet_CellPhone++;
    }
    read.close();
}
void load_admin_9CellPhone_3Message()
{
    string record;
    fstream read;
    read.open("admin_9CellPhone_3Message.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        nameMessagePakage[inc_opMessage_CellPhone] = seperateField(record, 1);
        amountMessagePakage[inc_opMessage_CellPhone] = stof(seperateField(record, 2));
        durationMessagePakage[inc_opMessage_CellPhone] = seperateField(record, 3);
        inc_opMessage_CellPhone++;
    }
    read.close();
}
void load_admin_10Book_1Borrow()
{
    string record;
    fstream read;
    read.open("admin_10Book_1Borrow.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        titleBorrowBook[inc_opBookBorrow] = seperateField(record, 1);
        authorBorrowBook[inc_opBookBorrow] = seperateField(record, 2);
        friendnameBorrowBook[inc_opBookBorrow] = seperateField(record, 3);
        remarksBorrowBook[inc_opBookBorrow] = seperateField(record, 4);
        inc_opBookBorrow++;
    }
    read.close();
}
void load_admin_10Book_2Purchase()
{
    string record;
    fstream read;
    read.open("admin_10Book_2Purchase.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        titlePurchaseBook[inc_opBookPurchase] = seperateField(record, 1);
        authorPurchaseBook[inc_opBookPurchase] = seperateField(record, 2);
        amountPurchaseBook[inc_opBookPurchase] = stof(seperateField(record, 3));
        remarksPurchaseBook[inc_opBookPurchase] = seperateField(record, 4);
        inc_opBookPurchase++;
    }
    read.close();
}
void load_admin_11SelfMotivational_1FiveTimePrayer()
{
    string record;
    fstream read;
    read.open("admin_11SelfMotivational_1FiveTimePrayer.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        five_time_Prayer[inc_opFiveTimePrayer] = seperateField(record, 1);
        inc_opFiveTimePrayer++;
    }
    read.close();
}
void load_admin_11SelfMotivational_2Quran_e_Pak()
{
    string record;
    fstream read;
    read.open("admin_11SelfMotivational_2Quran_e_Pak.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        Quran_e_Pak[inc_opQuran_e_Pak] = seperateField(record, 1);
        inc_opQuran_e_Pak++;
    }
    read.close();
}
void load_admin_11SelfMotivational_3Durood_e_Pak()
{
    string record;
    fstream read;
    read.open("admin_11SelfMotivational_3Durood_e_Pak.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        Durood_e_Pak[inc_opDurood_e_Pak] = seperateField(record, 1);
        inc_opDurood_e_Pak++;
    }
    read.close();
}
void load_admin_12Transport_1Uber()
{
    string record;
    fstream read;
    read.open("admin_12Transport_1Uber.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        locationFromUber[inc_opUberTransport] = seperateField(record, 1);
        locationToUber[inc_opUberTransport] = seperateField(record, 2);
        amountUber[inc_opUberTransport] = stof(seperateField(record, 3));
        purposeUber[inc_opUberTransport] = seperateField(record, 4);
        inc_opUberTransport++;
    }
    read.close();
}
void load_admin_12Transport_2Bus()
{
    string record;
    fstream read;
    read.open("admin_12Transport_2Bus.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        locationFromBus[inc_opBusTransport] = seperateField(record, 1);
        locationToBus[inc_opBusTransport] = seperateField(record, 2);
        amountBus[inc_opBusTransport] = stof(seperateField(record, 3));
        purposeBus[inc_opBusTransport] = seperateField(record, 4);
        inc_opBusTransport++;
    }
    read.close();
}
void load_admin_13RecreationalActivities_1Sporties()
{
    string record;
    fstream read;
    read.open("admin_13RecreationalActivities_1Sporties.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        minutiesSporties[inc_opSportiesActivities] = stof(seperateField(record, 1));
        inc_opSportiesActivities++;
    }
    read.close();
}
void load_admin_13RecreationalActivities_2Socities()
{
    string record;
    fstream read;
    read.open("admin_13RecreationalActivities_2Socities.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        minutiesSocieties[inc_opSocietiesActivities] = stof(seperateField(record, 1));
        purposeSocieties[inc_opSocietiesActivities] = seperateField(record, 2);
        inc_opSocietiesActivities++;
    }
    read.close();
}
void load_admin_14Achievments_1CoCurricular()
{
    string record;
    fstream read;
    read.open("admin_14Achievments_1CoCurricular.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        awardCo_Curricular[inc_opCoCurricular] = seperateField(record, 1);
        presentCo_Curricular[inc_opCoCurricular] = seperateField(record, 2);
        remarksCo_Curricular[inc_opCoCurricular] = seperateField(record, 3);
        inc_opCoCurricular++;
    }
    read.close();
}
void load_admin_14Achievments_2ExtraCurricular()
{
    string record;
    fstream read;
    read.open("admin_14Achievments_2ExtraCurricular.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        awardExtra_Curricular[inc_opExtraCurricular] = seperateField(record, 1);
        presentExtra_Curricular[inc_opExtraCurricular] = seperateField(record, 2);
        remarksExtra_Curricular[inc_opExtraCurricular] = seperateField(record, 3);
        inc_opExtraCurricular++;
    }
    read.close();
}
void load_admin_15ResultGrades()
{
    string record;
    fstream read;
    read.open("admin_15ResultGrades.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        gpa[inc_opResultGrades] = stof(seperateField(record, 1));
        cgpa[inc_opResultGrades] = stof(seperateField(record, 2));
        remarksResult[inc_opResultGrades] = seperateField(record, 3);
        inc_opResultGrades++;
    }
    read.close();
}
void load_admin_16GoldenLines()
{
    string record;
    fstream read;
    read.open("admin_16GoldenLines.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        titleGoldenLines[inc_opGoldenLines] = seperateField(record, 1);
        descriptionGoldenLines[inc_opGoldenLines] = seperateField(record, 2);
        inc_opGoldenLines++;
    }
    read.close();
}
void load_admin_17LifelongEvents()
{
    string record;
    fstream read;
    read.open("admin_17LifelongEvents.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        titleLifelongEvents[inc_opLifelongEvents] = seperateField(record, 1);
        descriptionLifelongEvents[inc_opLifelongEvents] = seperateField(record, 2);
        inc_opLifelongEvents++;
    }
    read.close();
}
void load_admin_18Notes()
{
    string record;
    fstream read;
    read.open("admin_18Notes.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        titleNotes[inc_opNotes] = seperateField(record, 1);
        descriptionNotes[inc_opNotes] = seperateField(record, 2);
        inc_opNotes++;
    }
    read.close();
}
//****************** VALIDATIONS ******************
float float_Validaion(string about, float variable)
{
    while (!(cin >> variable)) // check the validation of correct data type
    {
        cout << "Invalid entry.Please reenter." << endl;
        cout << about;
        cin.clear();
    }
    return variable;
}
//********************************************************************************** END OF PROGEAM CODE *********************************************************************