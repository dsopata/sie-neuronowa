#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Perceptron
{    
    int in;
    int out;
    double weight;
    double bias;
    
    int Result(double value)
    {
  double sigm =  1.0 / (1.0 + exp(-1 * value));

  if(sigm > 0.5)
  {
   return 1;
  }
  else
  {
   return 0;
  }
 }
    
    public:
    
    Perceptron()
    {
        in = 0;
        out = 0;
        weight = 0;
        bias = 1.0;
    }
 
 void Calc()
 {
  double tmp = ((double)in * weight) + bias;
  out = Result(tmp);
 }
};

int main() 
{
 srand(time(NULL));
 int sumResult = 0;
 int sumResult2 = 0;
 char name[6] = "pawel";
 
        Perceptron* p = new Perceptron[5]();
 Perceptron* p2 = new Perceptron[3]();
 Perceptron* p3 = new Perceptron();

 for(int i = 0; i < 5; i++)
 {
  p[i].in = (int)name[i];
  p[i].weight = rand() % 10 - 4;
  p[i].Calc();

  sumResult += p[i].out;

  cout << "p.weight: " << p[i].weight << endl;
 }

 for(int i = 0; i < 3; i++)
 {
  p2[i].in = sumResult;
  p2[i].weight = rand() % 10 - 4;
  p2[i].Calc();

  sumResult2 += p2[i].out;

  cout << "p2.weight: " << p2[i].weight << endl;
 }

 p3->in = sumResult2;
 p3->weight = rand() % 10 - 4;
 p3->Calc();

 cout << "p3.weight: " << p3->weight << endl;

 cout << "RESULT: " << p3->out << endl;

 char learn = 'y';

 while(learn == 'y')
 {
  int tmpSumResult = 0;
  int tmpSumResult2 = 0;

  for(int i = 0; i < 5; i++)
  {
   p[i].in = (int)name[i];
   p[i].weight += 0.1 * ((double)sumResult - p[i].out);
   p[i].bias += 0.1 * ((double)sumResult - p[i].out);
   p[i].Calc();

   tmpSumResult += p[i].out;

   cout << "p.weight " << i << ": " << p[i].weight << endl;
   cout << "p.out " << i << ": " << p[i].out << endl;
  }

  for(int i = 0; i < 3; i++)
  {
   p2[i].in = sumResult;
   p2[i].weight += 0.1 * ((double)sumResult2 - p2[i].out);
   p2[i].bias += 0.1 * ((double)sumResult2 - p2[i].out);
   p2[i].Calc();

   tmpSumResult2 += p2[i].out;

   cout << "p2.weight: " << i << ": " << p[i].weight << endl;
   cout << "p2.out: " << i << ": " << p[i].out << endl;
  }

  p3->in = sumResult2;
  p3->weight += 0.1; //???
  p3->bias += 0.1;
  p3->Calc();

  sumResult = tmpSumResult;
  sumResult2 = tmpSumResult2;

  cout << "p3.weight: 1 :" << p3->weight << endl;
  cout << "p3.out: 1 :" << p3->out << endl;

  cout << "RESULT: " << p3->out << endl;

  cout << "learn?" << endl;

  cin >> learn;

  if(learn == 'y')
  {
   cout << "input name" << endl;
   cin >> name;
  }
 }

 getchar();
 
 return 0;
}
