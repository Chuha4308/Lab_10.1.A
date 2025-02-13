#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

enum Speciality { ITIS, RE, KN, KI, PZ };
string speciality_str[] = { "�����������", "���������������", "����'������ �����", "����'������ ��������", "��������� ������������" };

struct Students
{
    string surname;
    int course;
    Speciality speciality;
    int grade_physics;
    int grade_math;
    int grade_informatics;
};

void Create(Students* S, const int N);
void Print(Students* S, const int N);
string FindBestStudent(Students* S, const int N);
double PercentageExcellents(Students* S, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "������ ������� ��������: "; cin >> N;

    Students* S = new Students[N];

    Create(S, N);
    Print(S, N);

    string best_student = FindBestStudent(S, N);
    cout << "������� � ��������� �������� �����: " << best_student << endl;

   
    cout << "������� ��������, �� ������� �� '������': " << fixed << setprecision(2) << PercentageExcellents(S, N) << "%" << endl;

    delete[] S;
    return 0;
}

void Create(Students* S, const int N)
{
    for (int i = 0; i < N; i++)
    {
        int speciality;
        cout << "����� ��������: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "�������: "; getline(cin, S[i].surname);
        cout << "����: "; cin >> S[i].course;
        cout << "������������� (0 - �����������, 1 - ���������������, 2 - ����'������ �����,";
        cout << "\n3 - ����'������ ��������, 4 - ��������� ������������): ";
        cin >> speciality;
        S[i].speciality = (Speciality)speciality;
        cout << "������ � ������: "; cin >> S[i].grade_physics;
        cout << "������ � ����������: "; cin >> S[i].grade_math;
        cout << "������ � �����������: "; cin >> S[i].grade_informatics;
        cout << endl;
    }
}

void Print(Students* S, const int N)
{
    cout << "=================================================================================================" << endl;
    cout << "|  �  |   �������   |  ����  |     �������������     |  Գ����  |  ����������  |  �����������  |" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(4) << left << i + 1 << " ";
        cout << "|" << setw(14) << left << S[i].surname;
        cout << "|" << setw(8) << left << S[i].course;
        cout << "|" << setw(23) << left << speciality_str[S[i].speciality];
        cout << "|" << setw(10) << left << S[i].grade_physics;
        cout << "|" << setw(14) << left << S[i].grade_math;
        cout << "|" << setw(15) << left << S[i].grade_informatics << "|" << endl;
    }
    cout << "=================================================================================================" << endl << endl;
}

string FindBestStudent(Students* S, const int N)
{
    int best_index = 0;
    double highest_avg = (S[0].grade_physics + S[0].grade_math + S[0].grade_informatics) / 3.0;

    for (int i = 1; i < N; i++) {
        double avg = (S[i].grade_physics + S[i].grade_math + S[i].grade_informatics) / 3.0;
        if (avg > highest_avg) {
            highest_avg = avg;
            best_index = i;
        }
    }
    return S[best_index].surname;
}

double PercentageExcellents(Students* S, const int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
       
        if (S[i].grade_physics == 5 && S[i].grade_math == 5 && S[i].grade_informatics == 5)
        {
            count++;
        }
    }
    return count * 100.0 / N;
}
