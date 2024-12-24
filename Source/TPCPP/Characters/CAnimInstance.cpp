#include "CAnimInstance.h"
#include "TPCPP.h"

void UCAnimInstance::NativeUpdateAnimation(float DeltaSecondes)
{
	Super::NativeUpdateAnimation(DeltaSecondes);

	APawn* OwnerPawn = TryGetPawnOwner();
	if (!OwnerPawn) return;

	Speed = OwnerPawn->GetVelocity().Size2D();
	Direction = CalculateDirection(OwnerPawn->GetVelocity(), OwnerPawn->GetControlRotation());
}