#include <iostream>
#include <queue>

int main(){
	std::queue<std::string> q;
	q.push("one");
	q.push("two");
	q.push("three");
	
	while(!q.empty()){
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << "\n";
}
