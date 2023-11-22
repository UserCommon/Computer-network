#include <iostream>

class Message {
  public:
    Message(char arg[25], double weight, double height);
    Message();

    void setName(char setName[25]);
    void setHeight(double h);
    void setWeight(double w);

    std::string getName();
    double getWeight();
    double getHeight();
    double getBMI();
    char *getBMIResult();

  private:
    char name[25];
    double weight;
    double height;
};
