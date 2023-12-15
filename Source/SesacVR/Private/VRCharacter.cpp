// Fill out your copyright notice in the Description page of Project Settings.


#include "VRCharacter.h"
#include "MotionControllerComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LeftController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftCon"));
	LeftController->MotionSource = FName("Left");
	
	RightController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightCon"));
	LeftController->MotionSource = FName("Right");

	GetCapsuleComponent()->SetCapsuleSize(1.f,1.f);
}

// Called when the game starts or when spawned
void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();
	
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

}

