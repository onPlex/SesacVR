// Fill out your copyright notice in the Description page of Project Settings.


#include "VRCharacter.h"
#include "MotionControllerComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/SceneComponent.h"
#include "Components/ArrowComponent.h"

// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	SetRootComponent(GetCapsuleComponent());
	//GetCapsuleComponent()->SetCapsuleSize(1.f, 1.f);

	GetMesh()->SetupAttachment(RootComponent);
	GetArrowComponent()->SetupAttachment(RootComponent);


	VROrigin = CreateDefaultSubobject<USceneComponent>(TEXT("VROrigin"));
	VROrigin->SetupAttachment(RootComponent);

	LeftController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftCon"));
	LeftController->MotionSource = FName("Left");
	LeftController->SetupAttachment(VROrigin);
	
	RightController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightCon"));
	RightController->MotionSource = FName("Right");
	RightController->SetupAttachment(VROrigin);

	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("HMD"));
	CameraComp->SetupAttachment(VROrigin);
}

// Called when the game starts or when spawned
void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem
			= ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(PlayerMappingContext, 0);
		}
	}	
}

// Called every frame
void AVRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AVRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//EnhancedInputComponent->BindAction(IA_LeftThumbstick, ETriggerEvent::Triggered, this, &AVRCharacter::Func1);
		//EnhancedInputComponent->BindAction(IA_LeftTrigger, ETriggerEvent::Triggered, this, &AVRCharacter::Func2);
		//EnhancedInputComponent->BindAction(IA_RightThumbstick, ETriggerEvent::Triggered, this, &AVRCharacter::Func3);	
	}
}

void AVRCharacter::Func1(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("LeftThumbstick"));
}

void AVRCharacter::Func2(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("LeftTrigger"));
}

void AVRCharacter::Func3(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("RightThumbstick"));
} 

