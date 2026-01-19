/*
 * Group 4
 * Sam Millikan <smillikan@scu.edu>
 * Ameen Ahmed <aahmed5@scu.edu>
 * Samuel Reiter <sreiter@scu.edu>
 * Isaac Amedie <iamedie@scu.edu>
 * Test program
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdexcept>
#include "bag.h"

using namespace std;
using namespace csen79;
enum Command
{
  ENQ = 'E',
  DEQ = 'D',
  PRINT = 'P',
  QUIT = 'Q'
};

int main(void)
{
  Bag bag;
  string line;
  bool quit = false;
  cout << "Enqueue with E #, Dequeu with D, Print with P, and Quit with Q" << endl;
  while (!quit && std::getline(cin, line))
  {
    switch (line[0])
    {
    case ENQ:
    {
      int data;
      try
      {
        stringstream ss(line.substr(1));
        ss >> data;
        bag.push(data);
      }
      catch (const out_of_range &e)
      {
        cerr << "Data out of range" << endl;
        continue;
      }
      catch (const std::overflow_error &e)
      {
        cerr << e.what() << endl;
        continue;
      }
    }
    break;
    case DEQ:
      try
      {
        cout << "Dequeued: " << bag.pop() << endl;
      }
      catch (const std::underflow_error &e)
      {
        cerr << e.what() << endl;
      }
      break;
    case PRINT:
      bag.print();
      break;
    case QUIT:
      quit = true;
      break;
    default:
      cerr << "Unknown command: " << line << endl;
      break;
    }
  }

  return EXIT_SUCCESS;
}
