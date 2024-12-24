#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimInstance.generated.h"

UCLASS()
class TPCPP_API UCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeUpdateAnimation(float DeltaSecondes) override;
	
protected:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Pawn")
	float Speed;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Pawn")
	float Direction;

};
