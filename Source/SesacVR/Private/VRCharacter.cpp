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
		//EnhancedInputComponent->BindAction(IA_LeftThumbstick_X, ETriggerEvent::Triggered, this, &AVRCharacter::MoveHorizontal);
		//EnhancedInputComponent->BindAction(IA_LeftThumbstick_Y, ETriggerEvent::Triggered, this, &AVRCharacter::MoveVertical);
		//EnhancedInputComponent->BindAction(IA_RightThumbstick_X, ETriggerEvent::Triggered, this, &AVRCharacter::SmoothTurn);
		

	}
}

void AVRCharacter::MoveVertical(const FInputActionValue& Value)
{
	// ���� ��Ʈ�ѷ��� Thumbstick ���� ������
	float ThumbstickInput = Value.Get<float>();

	// Thumbstick�� ���� �̿��Ͽ� ���� �Ǵ� ���� ����� �ӵ� ����
	FVector MovementDirection = GetActorForwardVector() * ThumbstickInput * 1000.f; // �յ� �̵�

	SetActorLocation(GetActorLocation() + MovementDirection);
	// ĳ���� �̵�
	//AddMovementInput(MovementDirection, 1.0f); // 1.0f�� �̵� �ӵ�

	// �̵��� ������ ȭ�鿡 ǥ��
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("MoveVertical - Thumbstick Value: %f"), ThumbstickInput));
}

void AVRCharacter::MoveHorizontal(const FInputActionValue& Value)
{
	// ���� ��Ʈ�ѷ��� Thumbstick ���� ������
	float ThumbstickInput = Value.Get<float>();

	// Thumbstick�� ���� �̿��Ͽ� ���� �Ǵ� ���� ����� �ӵ� ����
	FVector MovementDirection = GetActorRightVector() * ThumbstickInput * 1000.f; // �յ� �̵�

	// ĳ���� �̵�
	AddMovementInput(MovementDirection, 1.0f); // 1.0f�� �̵� �ӵ�

	// �̵��� ������ ȭ�鿡 ǥ��
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("MoveHorizontal - Thumbstick Value: %f"), ThumbstickInput));
}

void AVRCharacter::SmoothTurn(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("LeftTrigger"));

	// ������ ��Ʈ�ѷ��� Thumbstick X ���� ������
	float ThumbstickXInput = Value.Get<float>();

	// Thumbstick X�� ���� �̿��Ͽ� ĳ���� ȸ��
	
	FRotator NewRotation = FRotator(0.0f, ThumbstickXInput, 0.0f); // Yaw �� ����

	// ĳ���� ȸ��
	AddActorLocalRotation(NewRotation);

	// ȸ���� ������ ȭ�鿡 ǥ��
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("SmoothTurn - Thumbstick X Value: %f"), ThumbstickXInput));
}



