#include "ClickTP.h"



ClickTP::ClickTP() : IModule(0x0, EXPLOITS)
{
}


ClickTP::~ClickTP()
{

}

const char* ClickTP::getModuleName()
{
	return ("ClickTP");
}

void ClickTP::onTick(C_GameMode* gm)
{
	C_GameSettingsInput* input = g_Data.getGameSettingsInput();
	if (input == nullptr)
		return;
	if (gm->player == nullptr)
		return;
	vec3_ti block = g_Data.getClientInstance()->getPointerStruct()->block;
	vec3_t pos = block.toFloatVector();
	pos.y += gm->player->height;
	pos.y += 1.f;

	if (GameData::isRightClickDown() && !hasClicked && GameData::canUseMoveKeys()) {
		std::string coords = "X: " + std::to_string(pos.x) + " Y: " + std::to_string(pos.y) + " Z: " + std::to_string(pos.z);
		gm->player->setPos(pos);
		g_Data.getGuiData()->displayClientMessageF("%sTeleported to %s%s%s.", GREEN, GRAY, coords.c_str(), GREEN);
		hasClicked = true;
	}
	else if (!GameData::isRightClickDown()) {
		hasClicked = false;
	}
}