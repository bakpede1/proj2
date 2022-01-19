#include "Person.h"
//Default constructor
Person::Person(){
    m_fName = "";
    m_lName = "";
    m_age = 0;
    m_ID = 0;
}

//Overloaded constructor
Person::Person(string fName, string lName, int age, int ID){
    SetDetails(fName, lName, age, ID);
}

//A person pointer is stored from the roster of people in an organization
void Person::AddFriend(Person* newPerson){
    if (m_friendCount == MAX_FRIENDS) {
        cout << "You have maximum friends - please remove a friend first" << endl;
    } else if (!CheckID(newPerson->m_ID)) {
        m_friends[m_friendCount] = newPerson;
        m_friendCount++;

        cout << "You are now friends with "
        << newPerson->m_fName << "!" << endl;
    } else {
        cout << "You are already friends with "
        << newPerson->m_fName << "!" << endl;
    }
}

//Removes a person pointer from this person's m_friend array
void Person::RemoveFriend(){
    int remove;
    if (m_friendCount) {
        DisplayFriends();

        //Validates that number is within correct bounds
        //then reprompts if it is not
        do {
            cout << "Who would you like to remove? " << endl;
            cin >> remove;
        } while (1 > remove || remove > m_friendCount);

        //Removes friend user chooses
        //and shifts remaining friends to front of array
        for (int i = remove - 1; i < m_friendCount - 1; i++){
            m_friends[i] = m_friends[i + 1];
        }
        m_friendCount--;

    } else {
        cout << "You don't have any friends to remove" << endl;
    }
}

//Checks to see if a specific person ID exists in m_friends
bool Person::CheckID(int ID){
    for (int i = 0; i < m_friendCount; i++) {
        if( ID == m_friends[i]->m_ID){
            return true;
        }
    }
    return false;
}

//Displays information about each friend in the m_friend array
void Person::DisplayFriends(){
    if (m_friendCount > 0) {
        cout << "\nFriend List for " << m_fName << endl;

        for (int i = 0; i < m_friendCount; i++) {
            cout << (i + 1) << ". ";
            m_friends[i]->DisplayDetails();
            cout << endl;
        }
    } else {
        cout << "You don't have any friends yet" << endl;
    }
}

//Displays information about the Person
void Person::DisplayDetails(){
    cout << m_fName << " " << m_lName
    << " (" << m_age << " yrs) " << m_ID;
}

//Used as a setter for first name, last name, age, and id
void Person::SetDetails(string fName, string lName, int age, int ID){
    m_fName = fName;
    m_lName = lName;
    m_age = age;
    m_ID = ID;
}
