#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <vector>

using namespace std;

class Engine
{
public:
	Engine();
	~Engine();
	void init();
	vector<int> process(string query);

private:
};

#endif