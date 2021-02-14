#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;

int data = 1;
mutex mt1,mt2;

void a2() {
	data = data * data;
	mt1.lock();  //第二次申请对mt1上锁，但是上不上去
	cout<<data<<endl;
	mt1.unlock();
}
void a1() {
	mt1.lock();  //第一次对mt1上锁
	data = data+1;
	a2();
	cout<<data<<endl;
	mt1.unlock();
}

int main() {
	thread t1(a1);
	t1.join();
	cout<<"main here"<<endl;
	return 0;
}

