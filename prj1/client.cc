#include <array>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string.h>
#include <thread>
#include <variant>

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

Person create() {
  cout << "Enter request: Your faculty, Your name, Marks(4 items)" << endl;
  std::string faculty_s;
  cin >> faculty_s;
  std::array<char, 15> faculty;
  faculty.fill(0);
  std::copy(faculty_s.begin(), faculty_s.end(), faculty.begin());

  std::string name_s;
  cin >> name_s;
  std::array<char, 40> name;
  name.fill(0);
  std::copy(name_s.begin(), name_s.end(), name.begin());

  array<unsigned int, 4> arr;
  for (int i = 0; i < 4; ++i) {
    cin >> arr[i];
  }
  return Person(faculty, name, arr);
}

void checkOrCreateFile(const string &path) {
  namespace fs = std::filesystem;
  if (!fs::exists(path)) {
    std::ofstream file;
    file.open(path, ios::binary | ios::app);
    file.close();
  }
}
void match_answer(double ans) {
  if (ans == -1) {
    cout << "You have academic debt! No scholarship!" << endl;
    return;
  }
  cout << "You've got scholarship: " << ans << endl;
}

int main() {

  while (true) {
    ofstream req;
    ifstream resp;
    long prev_size;
    double answer;

    Person p = create();

    req.open(dir_req, ios::app | ios::binary);
    req.write((char *)&p, sizeof(p));
    req.close();

    checkOrCreateFile(dir_resp + p.getFaculty() + "_" + p.getName());
    resp.open(dir_resp + p.getFaculty() + "_" + p.getName(), ios::binary);
    resp.seekg(0, ios::end);
    prev_size = resp.tellg();

    while (prev_size >= resp.tellg()) {
      this_thread::sleep_for(chrono::milliseconds(100));
      resp.seekg(0, ios::end);
    }

    resp.seekg(prev_size, ios::beg);
    resp.read((char *)&answer, sizeof(answer));
    match_answer(answer);
  }

  return 0;
}
