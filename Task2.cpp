#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;
public:
    Person(){};
    Person(string name , int age)
    {
        this->name = name;
        this->age = age;
    }
    virtual void Display()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
    }

};

class Patient : public Person
{
private:
    string Patient_ID;
    string diagnosis;
public:
    Patient():Person(){};
    Patient(string name , int age , string Patient_ID , string diagnosis):Person(name , age)
    {
        this->Patient_ID = Patient_ID;
        this->diagnosis = diagnosis;
    }
    void Display()
    {
        Person::Display();
        cout<<"Patient ID : "<< Patient_ID << endl;
        cout<<"Diagnosis : "<<diagnosis << endl;
    }
    string get_patientID()
    {
        return Patient_ID;
    }
};

class Doctor : public Person
{
private:
    string Doctor_ID;
    string Specialization;
public:
    Doctor():Person(){};
    Doctor(string name , int age ,string Doctor_ID , string Specialization):Person(name , age)
    {
        this->Doctor_ID = Doctor_ID;
        this->Specialization = Specialization;
    }
    void Display()
    {
        Person::Display();
        cout<<"Doctor ID : "<<Doctor_ID << endl;
        cout<<"Specialization : "<< Specialization << endl;
    }
    string get_doctorID()
    {
        return Doctor_ID;
    }
};
class Appointment
{
private:
    Patient patient;
    Doctor doctor;
    string appointmentDate;
public:
    Appointment() {}
    Appointment(Patient patient, Doctor doctor, string appointmentDate)
    {
        this->patient = patient;
        this->doctor = doctor;
        this->appointmentDate = appointmentDate;
    }
    void Display()
    {
        cout << "Appointment Date: " << appointmentDate << endl;
        cout << "--- Patient Info ---" << endl;
        patient.Display();
        cout << "--- Doctor Info ---" << endl;
        doctor.Display();
    }
};

class Hospital
{
private:
    Patient patients[10];
    Doctor doctors[10];
    Appointment appointments[10];
    int patientCount;
    int doctorCount;
    int appointmentCount;
public:
    Hospital() : patientCount(0), doctorCount(0), appointmentCount(0) {}

    void addPatient(Patient p)
    {
        if (patientCount < 10)
        {
            patients[patientCount++] = p;
        }
        else
        {
            cout << "Patient list is full!" << endl;
        }
    }

    void addDoctor(Doctor d)
    {
        if (doctorCount < 10)
        {
            doctors[doctorCount++] = d;
        }
        else
        {
            cout << "Doctor list is full!" << endl;
        }
    }

    void scheduleAppointment(Patient p, Doctor d, string date)
    {
        if (appointmentCount < 10)
        {
            appointments[appointmentCount++] = Appointment(p, d, date);
        }
        else
        {
            cout << "Appointment list is full!" << endl;
        }
    }

    void displayAppointments()
    {
        if (appointmentCount == 0)
        {
            cout << "No appointments scheduled." << endl;
        }
        else
        {
            for (int i = 0; i < appointmentCount; i++)
            {
                cout << "Appointment " << (i + 1) << ":" << endl;
                appointments[i].Display();
                cout <<endl<< "----------------------------" << endl;
            }
        }
    }

    Patient* findPatient(string id)
    {
        for (int i = 0; i < patientCount; i++)
        {
            if (patients[i].get_patientID() == id)
            {
                return &patients[i];
            }
        }
        return nullptr;
    }

    Doctor* findDoctor(string id)
    {
        for (int i = 0; i < doctorCount; i++)
        {
            if (doctors[i].get_doctorID() == id)
            {
                return &doctors[i];
            }
        }
        return nullptr;
    }
};

int main()
{
    Hospital hospital;
    Patient patient1("Mariam", 25, "A12B345", "Heart disease");
    hospital.addPatient(patient1);
    Doctor doctor1("Dr. Ahmed Salem", 35, "T176G32", "Surgery");
    hospital.addDoctor(doctor1);
    hospital.scheduleAppointment(patient1, doctor1, "04-09-2024");
    cout << "  ------------" << endl;
    cout << " |Patient Info|" << endl;
    cout << "  ------------" << endl;
    patient1.Display();
    cout << endl << "---------------------------------------" << endl << endl;
    cout << "  -----------" << endl;
    cout << " |Doctor Info|" << endl;
    cout << "  -----------" << endl;
    doctor1.Display();
    cout << endl << "---------------------------------------" << endl << endl;
    cout << "  ------------------" << endl;
    cout << " |Appointments Info|" << endl;
    cout << "  ------------------" << endl;
    hospital.displayAppointments();

    return 0;
}

