#include "CAttributeComponent.h"

UCAttributeComponent::UCAttributeComponent()
{
	WalkSpeeds[(int32)EWalkSpeedType::Sneak] = 200.f;
	WalkSpeeds[(int32)EWalkSpeedType::Walk] = 400.f;
	WalkSpeeds[(int32)EWalkSpeedType::Sprint] = 600.f;

	RotationRate = FRotator(0, 720, 0);

	bCanMove = true;
}