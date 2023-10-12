// Сервер - деканат
// Клиент передаёт серверу **фамилию** и четыре оцценки по экзаменам
// сессии. Сервер на основании этих данных выдаёт результат, есть ли у
// студента задолжности; если нет, то возможно ли получении стипендии и её
// размер
#include <array>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string.h>
#include <thread>
#include <vector>

namespace fs = std::filesystem;
using namespace std;

class Person {
public:
  Person(array<char, 15> faculty, const std::array<char, 40> &name,
         array<unsigned int, 4> marks)
      : m_faculty(faculty), m_name(name), m_marks(marks){};

  string getName() const { return string(m_name.data()); }
  string getFaculty() const { return string(m_faculty.data()); }
  std::array<char, 40> getNameArr() const { return m_name; }
  array<unsigned int, 4> getMarks() const { return m_marks; }

  static Person regular() {
    std::array<char, 15> faculty;
    std::array<char, 40> name;
    std::array<unsigned int, 4> marks;
    faculty.fill(0);
    name.fill(0);
    marks.fill(0);
    return Person(faculty, name, marks);
  }

private:
  std::array<char, 15> m_faculty;
  std::array<char, 40> m_name;
  array<unsigned int, 4> m_marks;
};

string dir_resp = "/home/usercommon/vuz/prj2/responses/";
string dir_req = "/home/usercommon/vuz/prj2/requests/req.bin";

vector<ifstream> getIfstreams() {
  vector<ifstream> res;
  for (const auto &entry : fs::directory_iterator(dir_req)) {
    res.push_back(ifstream(entry.path(), ios::binary));
    cout << entry.path() << endl;
  }
  return res;
}

vector<ofstream> getOfstreams() {
  vector<ofstream> res;
  for (const auto &entry : fs::directory_iterator(dir_resp)) {
    res.push_back(ofstream(entry.path(), ios::binary | ios::app));
    cout << entry.path() << endl;
  }
  return res;
}

double getAmount(const Person &p) {
  // for 5 5 5 5 = 10.000
  // for 4 4 4 4 = 7.000
  bool isAce = true;
  bool isThree = false;
  bool debt = false;
  for (const auto &elem : p.getMarks()) {
    if (elem < 3) {
      debt = true;
      break;
    } else if (elem == 3) {
      isThree = true;
      isAce = false;
    } else if (elem == 4) {
      isAce = false;
    }
  }

  if (debt)
    return -1;
  if (isThree)
    return 0;
  if (isAce)
    return 10000;
  if (!isAce && !isThree)
    return 7000;
  return 0;
}

void checkOrCreateFile(const string &path) {
  namespace fs = std::filesystem;
  if (!fs::exists(path)) {
    std::ofstream file;
    file.open(path, ios::binary | ios::app);
    file.close();
  }
}

int main() {
  cout << "Server on fly!" << endl;
  checkOrCreateFile(dir_req);
  ifstream requests(dir_req, ios::binary);
  long size_pred = requests.tellg();
  while (true) {
    requests.seekg(0, ios::end);
    Person p = Person::regular();
    while (size_pred >= requests.tellg()) {
      std::this_thread::sleep_for(chrono::milliseconds(100));
      requests.seekg(0, ios::end);
    }
    requests.seekg(size_pred, ios::beg);
    requests.read((char *)&p, sizeof(p));
    cout << "New client! " << p.getName() << endl;
    size_pred = requests.tellg();
    double resp = getAmount(p);
    ofstream f(dir_resp + p.getFaculty() + "_" + p.getName(),
               ios::binary | ios::app);
    f.write((char *)&resp, sizeof(resp));
  }
  return 0;
}
