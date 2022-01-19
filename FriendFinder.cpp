#include "FriendFinder.h"
// Default constructor for application for finding friends
FriendFinder::FriendFinder() {
    cout << "*****************************\n"
    << "Welcome to UMBC Friend Finder\n"
    << "*****************************\n"<<endl;

    Start();

}
//Asks user for their first name, last name, age, and ID to populate m_me
void FriendFinder::GetDetails() {
    string fName;
    string lName;
    int age;
    int ID;

    cout << "What is your first name?" << endl;
    getline(cin,fName);
    cout << "What is your last name?" << endl;
    getline(cin, lName);
    cout << "What is your age?" << endl;
    cin >> age;
    cout << "What is your ID?" << endl;
    cin >> ID;

    if (cin.peek() == '\n'){
        cin.ignore();
    }

    m_organization.SetName();
    m_me.SetDetails(fName, lName, age, ID);

}

//Displays main menu for application
void FriendFinder::DisplayMenu(int &choice) {
    cout << "What would you like to do?" << endl;
    cout << "1. Display Entire Organization" << endl;
    cout << "2. Display Friend List" << endl;
    cout << "3. Search for a Friend" << endl;
    cout << "4. Remove Friend" << endl;
    cout << "5. Exit" << endl;

    cin >> choice;

    // Displays menu results for user choices
    switch (choice) {
        case 1:
            cout << "You are: ";
            m_me.DisplayDetails();
            cout << endl;
            m_organization.DisplayRoster();
            break;

		case 2:
			m_me.DisplayFriends();
			break;

		case 3:
			m_me.AddFriend(m_organization.GetPerson());
			break;

		case 4:
			m_me.RemoveFriend();
			break;

		case 5:
			cout << "Thank you for using UMBC Friend Finder!" << endl;
			break;

		default:
			break;

    }


}

// Main function running FriendFinder
// Calls GetDetails
// Populates data for organization
// Continually calls DisplayMenu until someone enters 4 (exit)
void FriendFinder::Start() {
    int option = 0;
    GetDetails();
    m_organization.LoadRoster();
    while (option != 5) {
        DisplayMenu(option);
    }

}
