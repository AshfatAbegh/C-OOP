#include<iostream>
using namespace std;

//Abstraction
class AbstractEmployee{
   virtual void AskForPromotion() = 0;//virtual function

};

class Employee:AbstractEmployee{
   //Encapsulation
   private:
          string Company;
          int Age;
   protected:
             string Name;
   public:
        void setName(string name){
           Name = name;
        }
        string getName(){
           return Name;
        }

        void setCompany(string company){
           Company = company;
        }
        string getCompany(){
           return Company;
        }

        void setAge(int age){
           if(age>=18){
             Age = age;
           }
        }
        int getAge(){
           return Age;
        }

    void Intro(){
      cout<<"Name: "<<Name<<endl;
      cout<<"Company: "<<Company<<endl;
      cout<<"Age: "<<Age<<endl;
    }
    //Constructor
    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }
    void AskForPromotion(){
      if(Age>30){
        cout<<Name<<" got promoted"<<endl;
     }
      else{
        cout<<Name<<" No Promotion!"<<endl;
    }
    }
    //virtual function
    virtual void Work(){
       cout<<Name<<" is checking email, task backlog, performing tasks..."<<endl;
    }
};

//Inheritance
class Developer: public Employee{
    public:
           string FavProgrammingLanguage;

    Developer(string name, string company, int age, string favprogramminglanguage)
      :Employee(name,company,age)

    {
        FavProgrammingLanguage = favprogramminglanguage;
    }
    void FixBug(){
      cout<<Name<<" fixed bug using "<<FavProgrammingLanguage<<endl;
    }
    void Work(){
       cout<<Name<<" is writing "<<FavProgrammingLanguage<<" code"<<endl;
    }
};

class Teacher: public Employee{
public:
      string Subject;

      void PrepareLesson(){
      cout<<Name<<" is preparing "<<Subject<<" lesson"<<endl;
      }
      Teacher(string name, string company, int age, string subject)
      :Employee(name, company, age)
      {
       Subject = subject;
      }
      void Work(){
       cout<<Name<<" is teaching "<<Subject<<endl;
    }
};

int main(){
   //Constructor
   //Employee employee1 = Employee("Ashfat","Brain Station23",24);
   //employee1.Intro();

   //Employee employee2 = Employee("Araf","Brain Station23",24);
   //employee2.Intro();

   //Encapsulation
   /*employee1.setName("Ashfat");
   cout<<"Name: "<<employee1.getName()<<endl;

   employee1.setCompany("Brain Station23");
   cout<<"Company: "<<employee1.getCompany()<<endl;

   employee1.setAge(16);
   cout<<"Age: "<<employee1.getAge();*/

   //Abstraction
   //employee1.AskForPromotion();
   //employee2.AskForPromotion();

   //Inheritance
   Developer d = Developer("Ashfat","Brain Station23",24,"C++");
   //d.FixBug();
   //d.AskForPromotion();
   //d.Work();//invoked

   Teacher t = Teacher("Hank","Cool",35,"Physics");
   //t.PrepareLesson();
   //t.AskForPromotion();
   //t.Work();//invoked

   //The most common use of polymorphism is when a
   //parent class reference is used to refer to a child class object;

   Employee *e1 = &d; //pointer is using base class to store derived class/child class
   Employee *e2 = &t;

   e1->Work();//(->) = means access member using a pointer
   e2->Work();
}

