#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "COptionComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TPCPP_API UCOptionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCOptionComponent();

public:
	UFUNCTION(BlueprintPure)
		FORCEINLINE float GetMouseXSpeed() { return MouseXSpeed; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE float GetMouseYSpeed() { return MouseYSpeed; }
	

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Option")
		float MouseXSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Option")
		float MouseYSpeed;
};
