#include <iostream>
#include <string>
#include <vector>

#include "GameManager.h"

using namespace std;

void main()
{
	GameManager cGameManager;

	cGameManager.init();

	while (cGameManager.GetStage() != GameManager::E_STAGE::EXIT)
	{
		cGameManager.Update();
	}

	cGameManager.Release();
}