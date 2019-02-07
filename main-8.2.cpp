#include <iostream>

using namespace std;

// Date
struct Date {
    int month;
    int day;
    int year;
};

// Transcript
struct Transcript {
    string classes[100];
    double grades[100];
    int class_count;
    double gpa;
};

// student
struct Student {
    string name;
    int id;
    string major;
    Transcript tran;
    int age;
    Date dob;
};

// function declarations
Student mergeStudent(Student s1, Student s2);
void printStudent(Student s);
void initializeStudent(Student& st);

// for testing
int main() {

    const int n = 100; //You may wish to make this smaller for testing.
    Student freshmen[n];

    for(int i = 0; i < n; i++) {
        initializeStudent(freshmen[i]);
    }
    cout << freshmen[0].name << endl;
    for(int i = 0; i < n; i++){
        printStudent(freshmen[i]);
    }
    cout << endl;
    return 0;
}

// printing student information
void printStudent(Student s) {
    cout << "Name is: " << s.name << endl;
    cout << "ID is: " << s.id << endl;
    cout << "major is: " << s.major << endl;
    cout << "Birthday is: " << s.dob.month << "/" << s.dob.day << "/" << s.dob.year << endl;
    cout << "Age is: " << s.age<<endl;
    //Prints classes with grades
    cout<< "Classes and Grades:"<<endl;
    for (int i=0; i<s.tran.class_count; i++){
        cout<<s.tran.classes[i]<<" : "<<s.tran.grades[i]<<endl;
    }
    //Prints gpa
    cout<< "Gpa: "<<s.tran.gpa<<endl<<endl;
}


// initializing student
void initializeStudent(Student& st) {
    string dummy;
    cout << "Enter a name" << endl;
    getline(cin, st.name); // getline reads a line
    cout << "Enter an id" << endl;
    cin >> st.id;
    getline(cin, dummy);
    cout << "enter a major" << endl;
    getline(cin, st.major);
    cout << "Enter age: " << endl;
    cin >> st.age;
    cout << "Enter birthday month, day, year as numbers: " << endl;
    cin >> st.dob.month >> st.dob.day >> st.dob.year;
    //Initializes classes
    cout<< "Enter number of classes: ";
    cin>>st.tran.class_count;
    cout<< "Enter Classes"<<endl;
    for (int i=0;i<st.tran.class_count;i++){
        cin>>st.tran.classes[i];
    }
    //Initializes grades
    cout<< "Enter Grades"<<endl;
    for (int i=0;i<st.tran.class_count;i++){
        cin>>st.tran.grades[i];
    }
    //Calculates gpa
    for (int i=0; i<st.tran.class_count; i++){
        st.tran.gpa+=st.tran.grades[i];
    }
    st.tran.gpa=4*st.tran.gpa/(100*st.tran.class_count);
}
// Merging
Student mergeStudent(Student s1, Student s2) {
    Student ret = {"No name", 0, ""};
    if(s1.id == s2.id){
        ret.id = s1.id;
        if(s1.age > s2.age) {
            ret.major = s1.major;
        }
        else {
            ret.major = s2.major;
        }
        if(s1.name.length() > s2.name.length())
            ret.name = s1.name;
        else
            ret.name = s2.name;

    //Combines non-duplicate classes
    ret.tran.class_count=s1.tran.class_count;

      for(int i=0; i<s1.tran.class_count; i++){
        ret.tran.classes[i]=s1.tran.classes[i];
        ret.tran.grades[i]=s1.tran.grades[i];
      }
        bool isDupe=false;
      for(int j=0;j<s2.tran.class_count;j++){
            string current=s2.tran.classes[j];
            for(int k=0; k<s1.tran.class_count; k++){
                if(current==s1.tran.classes[k]) isDupe=true;
            }
                if(!isDupe){
                ret.tran.classes[ret.tran.class_count]=current;
                ret.tran.grades[ret.tran.class_count]=s2.tran.grades[j];
                ret.tran.class_count++;
                }
                isDupe=false;
      }
        //Calculates for new gpa
        for(int l=0; l<ret.tran.class_count;l++){
            ret.tran.gpa+=ret.tran.grades[l];
        }
        ret.tran.gpa=4*ret.tran.gpa/(100*ret.tran.class_count);
    }
    return ret;
}
