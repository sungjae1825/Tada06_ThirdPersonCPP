#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CAttributeComponent.generated.h"

UENUM(BlueprintType)
enum class EWalkSpeedType : uint8
{
	Sneak, Walk, Sprint, Max
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TPCPP_API UCAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCAttributeComponent();

public:
 	FORCEINLINE float GetSneakSpeed() { return WalkSpeeds[(int32)EWalkSpeedType::Sneak]; }
 	FORCEINLINE float GetWalkSpeed() { return WalkSpeeds[(int32)EWalkSpeedType::Walk]; }
 	FORCEINLINE float GetSprintSpeed() { return WalkSpeeds[(int32)EWalkSpeedType::Sprint]; }

	FORCEINLINE FRotator GetRotationRate() { return RotationRate; }
	FORCEINLINE bool IsCanMove() { return bCanMove; }

private:
	UPROPERTY(EditDefaultsOnly, Category = "Attributes")
	float WalkSpeeds[(int32)EWalkSpeedType::Max];

	UPROPERTY(EditDefaultsOnly, Category = "Attributes")
	FRotator RotationRate;

	UPROPERTY(EditDefaultsOnly, Category = "Attributes")
	bool bCanMove;
};
