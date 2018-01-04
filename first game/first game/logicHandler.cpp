#include "logicHandler.h"

void LogicHandler::PossibleCollision(std::vector<RenderTarget*> targets, Camera& camera)
{
	for (int i = 0; i < targets.size(); i++)
	{
		//Wenn CameraZ + CameraZSchritt > TargetZ || Geh nur TargetZ - (CameraZ + CameraZSchritt)  
		//Wenn CameraX + CameraXSchritt > TargetX || Geh nur TargetX - (CameraX + CameraXSchritt)  
		//Wenn CameraY + CameraYSchritt > TargetY || Geh nur TargetY - (CameraY + CameraYSchritt)  

		//Und umgekehrt auch
		//Wenn CameraZ - CameraZSchritt...
	}
}