#include<iostream>
using namespace std;
class Exam
{
	public:
		int examID;
		string subject;
		int duration;
		virtual double gradeExam() const = 0;
        virtual void inputExamDetails()
		{
			cout<<"Enter Exam ID:";
			cin>>examID;
			cout<<"Subject:";
			cin>>subject;
			cout<<"Enter Duration(minutes):";
			cin>>duration;
		}
          virtual void displayExamInfo() const
		   {
        cout<<"Exam ID:"<<examID<<endl;
        cout<<"Subject:"<<subject<<endl;
        cout<<"Duration: "<< duration <<"minutes"<<endl;
    }
    virtual ~Exam() = default;
};
class MultipleChoiceExam:public Exam
{
	public:
       int numQuestions;
       int correctAnswers;
    void inputExamDetails() override
	 {
        inputExamDetails();
        cout <<"Enter number of questions: ";
        cin >>numQuestions;
        cout <<"Enter number of correct answers: ";
        cin >>correctAnswers;
    }

    double gradeExam() const override 
	{
        if (numQuestions == 0) 
        cout<<"There are no questions"<<endl;
        return (correctAnswers / numQuestions) * 100.0;
    }

    void displayExamInfo() const override
	 {
        displayExamInfo();
        cout <<" Questions:"<<numQuestions<<endl;
        cout<<"Correct:"<<correctAnswers<<endl;
     }
    ~MultipleChoiceExam() 
	{
        //destructor included for completeness
    }
};
class EssayExam:public Exam
{
	public:
		 string topic;
         double score;
       void inputExamDetails() override 
	   {
        inputExamDetails();
        cout << "Enter essay topic: ";
        cin>>topic;
        cout<< "Enter score (0-100): ";
        cin>>score;
       }
    double gradeExam() const override
	 {
        if (score < 0 || score > 100) 
        cout<<"Invalid"<<endl;
        return score;
    }
    void displayExamInfo() const override 
	{
        displayExamInfo();
        cout<<"Topic:"<<topic<<endl;
        cout<<"Score: "<<score<<endl;
    }
    ~EssayExam()
	 {
        //destructor included for completeness
     }		
};
int main()
{
	class MultipleChoiceExam student;
    student.gradeExam();
    class EssayExam student2;
    student2.gradeExam();
    return 0;
}