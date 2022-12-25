#include <iostream>
#include <vector>
#include <string>

struct Patient
{
    std::string name;
    int age;
    std::string illness;
};

class Hospital
{
private:
    std::vector<Patient> patients;

public:
    void addPatient(const Patient& patient)
    {
        patients.push_back(patient);
    }

    void removePatient(const std::string& name)
    {
        for (std::size_t i = 0; i < patients.size(); i++)
        {
            if (patients[i].name == name)
            {
                patients.erase(patients.begin() + i);
                break;
            }
        }
    }

    Patient getPatient(const std::string& name)
    {
        for (const Patient& patient : patients)
        {
            if (patient.name == name)
            {
                return patient;
            }
        }

        return Patient{};
    }

    std::vector<Patient> getAllPatients() const
    {
        return patients;
    }
};

int main()
{
    Hospital hospital;

    Patient patient1{ "Alice", 30, "Flu" };
    Patient patient2{ "Bob", 40, "Broken leg" };
    Patient patient3{ "Eve", 35, "Pneumonia" };

    hospital.addPatient(patient1);
    hospital.addPatient(patient2);
    hospital.addPatient(patient3);

    std::cout << "All patients: " << std::endl;
    for (const Patient& patient : hospital.getAllPatients())
    {
        std::cout << patient.name << " " << patient.age << " " << patient.illness << std::endl;
    }

    std::cout << std::endl;

    hospital.removePatient("Bob");

    std::cout << "All patients after removing Bob: " << std::endl;
    for (const Patient& patient : hospital.getAllPatients())
    {
        std::cout << patient.name << " " << patient.age << " " << patient.illness << std::endl;
    }

    std::cout << std::endl;

    Patient patient = hospital.getPatient("Alice");
    std::cout << "Patient Alice: " << patient.name << " " << patient.age << " " << patient.illness << std::endl;

    return 0;
}
