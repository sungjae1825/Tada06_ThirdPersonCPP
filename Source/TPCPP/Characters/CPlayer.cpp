#include "CPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CAttributeComponent.h"

ACPlayer::ACPlayer()
{
	//Create Components
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(GetMesh());

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	//Component Settings
	//-> MeshComp
	ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("/Game/Character/Mesh/SK_Mannequin"));
	if (MeshAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MeshAsset.Object);
	}

	ConstructorHelpers::FClassFinder<UAnimInstance> AnimClass(TEXT("/Game/Player/ABP_CPlayer"));
	if (AnimClass.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(AnimClass.Class);
	}

	GetMesh()->SetRelativeLocation(FVector(0, 0, -88));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	//-> SpringArmComp
	SpringArmComp->SetRelativeLocation(FVector(0, 0, 140));
	SpringArmComp->SetRelativeRotation(FRotator(0, 90, 0));
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->bEnableCameraLag = true;

	//-> My Comp
	AttributeComp = CreateDefaultSubobject<UCAttributeComponent>("AttributeComp");

	//-> Component Settings
	GetCharacterMovement()->MaxWalkSpeed = AttributeComp->GetSprintSpeed();
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = AttributeComp->GetRotationRate();
	bUseControllerRotationYaw = false;
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();

}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Axis Event
	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayer::OnMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayer::OnMoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);


	//Action Event
	PlayerInputComponent->BindAction("Walk", IE_Pressed, this, &ACPlayer::OnWalk);
	PlayerInputComponent->BindAction("Walk", IE_Released, this, &ACPlayer::OffWalk);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACPlayer::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACPlayer::StopJumping);
}

void ACPlayer::OnMoveForward(float Axis)
{
	if (!AttributeComp->IsCanMove()) return;

	FRotator ControlRot = FRotator(0, GetControlRotation().Yaw, 0);
	FVector Direction = FQuat(ControlRot).GetForwardVector().GetSafeNormal2D();

	AddMovementInput(Direction, Axis);
}

void ACPlayer::OnMoveRight(float Axis)
{
	if (!AttributeComp->IsCanMove()) return;

	FRotator ControlRot = FRotator(0, GetControlRotation().Yaw, 0);
	FVector Direction = FQuat(ControlRot).GetRightVector().GetSafeNormal2D();

	AddMovementInput(Direction, Axis);
}

void ACPlayer::OnTrun(float Axis)
{
}

void ACPlayer::OnLookUp(float Axis)
{
}

void ACPlayer::OnWalk()
{
	GetCharacterMovement()->MaxWalkSpeed = AttributeComp->GetWalkSpeed();
}

void ACPlayer::OffWalk()
{
	GetCharacterMovement()->MaxWalkSpeed = AttributeComp->GetSprintSpeed();
}

