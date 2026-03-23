#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Factory.hpp"

void ticketSim() {
  Queue<int> *tQ = Factory<int>::GetQueue(10);

  int numEnqueue = 0;
  int turnedAway = 0;
  int served = 0;

  for (int i = 0; i < 100; ++i) {
    int s = (std::rand() % 3) - 1;

    if (s < 0) {
      if (!tQ->isEmpty()) {
	tQ->dequeue();
	++served;
      }
    }
    else {
      try {
	tQ->enqueue(1);
	++numEnqueue;
      } catch (std::string &e) {
	++turnedAway;
      }
    }
  }

  std::cout << "total arrival: " << (numEnqueue + turnedAway) << '\n';
  std::cout << "successful enqueues: " << numEnqueue << '\n';
  std::cout << "turned away: " << turnedAway << '\n';
  std::cout << "served: " << served << '\n';
  std::cout << "remaining: " << tQ->getLength() << "\n\n";

  delete tQ;
}

void bankSim() {
  Queue<int> *bQ = Factory<int>::GetQueue();

  int arrivals = 0;
  int served = 0;

  for (int i = 0; i < 100; ++i) {
    int s = (std::rand() % 4) - 1;

    if (s < 0) {
      if (!bQ->isEmpty()) {
	bQ->dequeue();
	++served;
      }
    }
    else {
      bQ->enqueue(1);
      ++arrivals;
    }
  }

  std::cout << "total arrival: " << arrivals << '\n';
  std::cout << "served: " << served << '\n';
  std::cout << "remaining: " << bQ->getLength() << "\n\n";

  delete bQ;
}

int main(int argc, char **argv) {
  std::srand(std::time(0));

  ticketSim();
  bankSim();

  return 0;
}
