#pragma once
#include "Module.h"
#include "../../DrawUtils.h"
class Scaffold :
	public IModule
{
private:
	bool autoselect = false;
	bool tryScaffold(vec3_t blockBelow);
	bool findBlock();
public:
	Scaffold();
	~Scaffold();

	// Inherited via IModule
	virtual const char* getModuleName() override;
	virtual void onPostRender() override;
};
