#include <iostream>
#include "Heaph.h"
using namespace std;

int main() {
	Heap<int, char> hello;
	hello.push(1, 'd');
	hello.push(1, 'f');
	hello.push(1, 'g');
	hello.pop();
	hello.is_empty();
	hello.pop();
	hello.is_empty();
	hello.pop();
	hello.is_empty();
	hello.pop();
	return 0;
}