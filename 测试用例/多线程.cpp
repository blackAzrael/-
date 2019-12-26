#include "pch.h"
#include <iostream>
#include <functional>
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
using namespace std;

void pause_thread(int n,int m)
{
	int i = 0;
	while (n--)
	{
		std::this_thread::sleep_for(std::chrono::seconds(i++));
		std::cout << "pause of " << n << " seconds ended" << m << endl;
	}
	
}
TEST(多线程,1)
{
	std::cout << "Spawning 3 threads...\n";
	std::thread t1(pause_thread, 1,1);
	std::thread t2(pause_thread, 2,2);
	std::thread t3(pause_thread, 3,3);
	std::cout << "Done spawning threads. Now waiting for them to join:\n";
	t1.join();
	t2.join();
	t3.join();
	std::cout << "All threads joined!\n";
	
}
TEST(多线程, 2)
{
	std::cout << "Spawning 3 threads...\n";
	std::thread (pause_thread, 1, 1).detach();
	std::thread (pause_thread, 2, 2).detach();
	std::thread (pause_thread, 3, 3).detach();
	std::cout << "Done spawning threads. Now waiting for them to join:\n";
	pause_thread(5,5);
	std::cout << "All threads joined!\n";

}