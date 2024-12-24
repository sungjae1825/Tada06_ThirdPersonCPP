#include "CGameMode.h"

ACGameMode::ACGameMode()
{
	ConstructorHelpers::FClassFinder<APawn> PlayerClass(TEXT("/Game/Player/BP_CPlayer"));

	if (PlayerClass.Succeeded())
	{
		DefaultPawnClass = PlayerClass.Class;
	}
}