#include <iostream>
#include <string>
using namespace std;

class Skill{
    string skillID;
    string skillName;
    string skillDescription;

public:
    Skill() : skillID(""), skillName(""), skillDescription("") {}  // Default constructor
    Skill(string id, string name, string desc) : skillID(id), skillName(name), skillDescription(desc){}

    void showSkillDetails();
    void updateSkillDescription(string newDescription);
    string getSkillName() { return skillName; }
};

void Skill :: showSkillDetails(){
    cout << "Skill ID: " << skillID << " | Skill Name: " << skillName << " | Description: " << skillDescription << endl;
}

void Skill :: updateSkillDescription(string newDescription){
    skillDescription = newDescription;
}

class Sport{
    string sportID;
    string sportName;
    string sportDescription;
    Skill **requiredSkills;  // pointer to an array of Skills
    int numSkills;

public:
    Sport() : sportID(""), sportName(""), sportDescription(""), requiredSkills(nullptr), numSkills(0) {} // Default constructor
    Sport(string id, string name, string desc, Skill **skill_ptr, int n) : sportID(id), sportName(name), sportDescription(desc), numSkills(n) {
        requiredSkills = new Skill *[numSkills];
        for (int i = 0; i < numSkills; i++) {
            requiredSkills[i] = skill_ptr[i];
        }
    }

    void addSkill(Skill *);
    void removeSkill(Skill *);
    string getSportName() { return sportName; }
    void displaySportDetails(){
        cout << "Sport ID: " << sportID << " | Sport Name: " << sportName << " | Sport Description: " << sportDescription << endl;
        for(int i=0 ; i<numSkills ; i++){
            cout << "Skill " << (i+1) << ": ";
            requiredSkills[i]->showSkillDetails();
        }
    }

    ~Sport(){
        delete[] requiredSkills;
    }
};

void Sport :: addSkill(Skill *s){
    Skill **temp = new Skill *[numSkills + 1];
    for(int i=0 ; i < numSkills ; i++){
        temp[i] = requiredSkills[i];
    }
    temp[numSkills] = s;
    delete[] requiredSkills;
    requiredSkills = temp;
    numSkills++;
    cout << "Skill \"" << s->getSkillName() << "\" added successfully." << endl;
}

void Sport :: removeSkill(Skill *s){
    if(requiredSkills == nullptr || numSkills == 0){
        cout << "The sport \"" << getSportName() << "\" has not been initialized with any skills yet." << endl;
        return;
    }
    
    int i, flag = 0;
    for(i=0 ; i < numSkills ; i++){
        if(requiredSkills[i]->getSkillName() == s->getSkillName()){
            flag = 1;
            break;
        }
    }

    if(!flag){
        cout << "The entered skill was not found in sport \"" << sportName << "\" skill set." << endl;
        return;
    }

    Skill **temp = new Skill *[numSkills - 1];
    int counter = 0;
    for(int j=0 ; j<numSkills ; j++){
        if(j != i){ 
            temp[counter++] = requiredSkills[j];
        }
    }
    
    delete[] requiredSkills;
    requiredSkills = temp;
    numSkills--;
    cout << "Skill \"" << s->getSkillName() << "\" removed successfully." << endl;
}

class Mentor;

class Student{
    string studentID;
    string studentName;
    int studentAge;
    Sport **sportsInterests;  // pointer to an array of Skills
    int numSports;
    Mentor *mentorAssigned;

public:
    Student() : studentID(""), studentName(""), studentAge(0), sportsInterests(nullptr), numSports(0), mentorAssigned(nullptr) {} // Default constructor
    Student(string id, string name, int age, Sport **sports_ptr, int nS, Mentor *mentor_ptr) : studentID(id), studentName(name), studentAge(age), numSports(nS), mentorAssigned(mentor_ptr) {
        sportsInterests = new Sport *[numSports];
        for (int i = 0; i < numSports; i++) {
            sportsInterests[i] = sports_ptr[i];
        }
    }

    void registerForMentorship(Mentor *);
    void viewMentorDetails();
    void updateSportsInterest(Sport *);
    string getStudentName() { return studentName; }
    void displayStudentDetails();

    ~Student(){
        delete[] sportsInterests;
        mentorAssigned = nullptr;
    }
};

class Mentor{
    string mentorID;
    string mentorName;
    Sport **sportExpertise;  // pointer to an array of Skills
    int numSports;
    int maxLearners;
    Student **assignedLearners;  // pointer to an array of Skills
    int currentLearners;

public:
    Mentor(string id, string name, int nS, int mL, Sport **sports_ptr , Student **students_ptr, int cL) : mentorID(id), mentorName(name), numSports(nS), maxLearners(mL), currentLearners(cL) {
        sportExpertise = new Sport *[numSports];
        for (int i = 0; i < numSports; i++) {
            sportExpertise[i] = sports_ptr[i];
        }

        assignedLearners = new Student *[currentLearners];
        for (int i = 0; i < currentLearners; i++) {
            assignedLearners[i] = students_ptr[i];
        }
    }

    bool assignLearner(Student *);
    void removeLearner(Student *);
    void viewLearners();
    void provideGuidance();
    void displayMentorDetails(){
        cout << "Mentor ID: " << mentorID << " | Mentor Name: " << mentorName << endl;
        cout << "Sports Expertise: " << endl;
        for(int i=0; i<numSports ; i++){
            cout << "Sport " << (i+1) << ": ";
            sportExpertise[i]->displaySportDetails();
        }
    }
    string getMentorName(){ return mentorName; }

    ~Mentor(){
        delete[] sportExpertise;
        delete[] assignedLearners;
    }
};

bool Mentor :: assignLearner(Student *s){
    if(currentLearners >= maxLearners){
        cout << "Max students assigned has been reached for Mentor \"" << mentorName << "\"." << endl;
        return false;
    }
    
    Student **temp = new Student *[currentLearners + 1];
    for(int i=0 ; i<currentLearners ; i++){
        temp[i] = assignedLearners[i];
    }
    temp[currentLearners] = s;
    delete[] assignedLearners;
    assignedLearners = temp;
    currentLearners++;
    cout << "Student \"" << s->getStudentName() << "\" assigned to Mentor \"" << mentorName << "\" successfully." << endl;
    return true;
}

void Mentor :: removeLearner(Student *s){
    if(assignedLearners == nullptr || currentLearners == 0){
        cout << "No student has been assigned to Mentor \"" << mentorName << "\" yet." << endl;
        return;
    }

    int i, flag = 0;
    for(i=0 ; i<currentLearners ; i++){
        if(assignedLearners[i]->getStudentName() == s->getStudentName()){
            flag = 1;
            break;
        }
    }

    if(!flag){
        cout << "The entered student was not found in Mentor \"" << mentorName << "\" assigned students." << endl;
        return;
    }

    Student **temp = new Student *[currentLearners - 1];
    int counter = 0;
    for(int j=0 ; j<currentLearners ; j++){
        if(j != i){
            temp[counter++] = assignedLearners[j];
        }
    }

    delete[] assignedLearners;
    assignedLearners = temp;
    currentLearners--;
    cout << "Student \"" << s->getStudentName() << "\" removed from Mentor \"" << mentorName << "\" successfully";
}

void Student :: registerForMentorship(Mentor *m) {  
    if (m->assignLearner(this)) {
        mentorAssigned = m;
    }
}

void Student :: viewMentorDetails()
{
    cout << "Displaying details for Mentor: " << endl;
    if (mentorAssigned) {
        cout << "Mentor: " << endl;
        mentorAssigned->displayMentorDetails();
    } else {
        cout << "Mentor: None" << endl;
    }
}

void Student :: updateSportsInterest(Sport *s){
        Sport **temp = new Sport *[numSports + 1];
        for(int i=0 ; i<numSports ; i++){
            temp[i] = sportsInterests[i];
        }
        temp[numSports] = s;
        delete[] sportsInterests;
        sportsInterests = temp;
        numSports++;
        cout << "Sport \"" << s->getSportName() << "\" assigned to Student \"" << studentName << "\" successfully." << endl;
}

void Student :: displayStudentDetails() {
    cout << "Student ID: " << studentID << " | Student Name: " << studentName << " | Student Age: " << studentAge << endl;
}

void Mentor :: viewLearners(){
    cout << "Displaying the assigned students for Mentor \"" << mentorName << "\": " << endl;
    for(int i=0 ; i<currentLearners ; i++){
        assignedLearners[i]->displayStudentDetails();
    }
}

void Mentor :: provideGuidance(){
    // The question did not specify the purpose and functionality of this function
    cout << "Work harder to master your skills and reach your goal!" << endl;
}

int main() {
    Skill skill1("S001", "Running", "Ability to run fast");
    Skill skill2("S002", "Swimming", "Ability to swim efficiently");
    Skill skill3("S003", "Throwing", "Ability to throw accurately");

    Skill *sport1Skills[] = {&skill1, &skill2};
    Sport sport1("SP001", "Triathlon", "Combination of running, swimming, and cycling", sport1Skills, 2);

    Skill *sport2Skills[] = {&skill3};
    Sport sport2("SP002", "Javelin", "Sport involving throwing a spear", sport2Skills, 1);

    Sport *mentorSports[] = {&sport1};
    Mentor mentor1("M001", "Coach John", 1, 5, mentorSports, nullptr, 0);

    Sport *studentSports[] = {&sport2};
    Student student1("ST001", "Alice", 20, studentSports, 1, nullptr);

    student1.registerForMentorship(&mentor1);

    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Display Mentor Details\n";
        cout << "2. Display Student Details\n";
        cout << "3. View Learners of Mentor\n";
        cout << "4. Provide Guidance\n";
        cout << "5. Add Skill to Sport1\n";
        cout << "6. Remove Skill from Sport1\n";
        cout << "7. Display Sport1 Details\n";
        cout << "8. Display Sport2 Details\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                mentor1.displayMentorDetails();
                break;
            case 2:
                student1.displayStudentDetails();
                break;
            case 3:
                mentor1.viewLearners();
                break;
            case 4:
                mentor1.provideGuidance();
                break;
            case 5: {
                Skill *skill4 = new Skill("S004", "Cycling", "Ability to cycle long distances");
                sport1.addSkill(skill4);
                break;
            }
            case 6: {
                sport1.removeSkill(&skill1);
                break;
            }
            case 7:
                sport1.displaySportDetails();
                break;
            case 8:
                sport2.displaySportDetails();
                break;
            case 9:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}