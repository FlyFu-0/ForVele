#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void read(vector <string>& fio, vector <string>& depart, vector <string>& job, vector <string>& zp)
{
	string temp;

	ifstream fout;
	fout.open("Worker.txt");

	while (fout) {
		getline(fout, temp);
		fio.push_back(temp);

		getline(fout, temp);
		depart.push_back(temp);

		getline(fout, temp);
		job.push_back(temp);

		fout >> temp;
		zp.push_back(temp);
	}
}

void write(vector <string> fio, vector <string> depart, vector <string> job, vector <string> zp)
{
	ofstream fin;
	fin.open("Worker.txt", ios::out | ios::trunc);

	for (size_t i = 0; i < fio.size(); i++) {
		fin << fio[i] << endl
			<< depart[i] << endl
			<< job[i] << endl
			<< zp[i] << endl;
	}

}

void show(vector <string> fio, vector <string> depart, vector <string> job, vector <string> zp)
{
	for (size_t i = 0; i < fio.size(); i++) {
		cout << "Запись №" << i + 1 << endl
			<< fio[i] << endl
			<< depart[i] << endl
			<< job[i] << endl
			<< zp[i] << endl;
	}
}

void deleting(vector <string>& fio, vector <string>& depart, vector <string>& job, vector <string>& zp)
{
	size_t NumOfRec;

	cout << "Введите номер записи которую хотите удалить: ";
	cin >> NumOfRec;

	fio.erase(fio.begin() + NumOfRec - 1);
	depart.erase(depart.begin() + NumOfRec - 1);
	job.erase(job.begin() + NumOfRec - 1);
	zp.erase(zp.begin() + NumOfRec - 1);
}

int main()
{
	setlocale(LC_ALL, "");

	vector <string> fio;
	vector <string> depart;
	vector <string> job;
	vector <string> zp;

	read(fio, depart, job, zp);

	show(fio, depart, job, zp);

	deleting(fio, depart, job, zp);

	show(fio, depart, job, zp);

	write(fio, depart, job, zp);
}
