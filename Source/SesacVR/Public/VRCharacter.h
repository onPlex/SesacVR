// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "VRCharacter.generated.h"


UCLASS()
class SESACVR_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Controller")
	class UMotionControllerComponent* LeftController;

	UPROPERTY(EditAnywhere, Category = "Controller")
	class UMotionControllerComponent* RightController;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditAnywhere, Category = "HMD")
	class UCameraComponent* CameraComp;


protected:
      
	 UPROPERTY(EditAnywhere, Category = "Input")
	 class UInputAction* IA_LeftThumbstick;
	 UPROPERTY(EditAnywhere, Category = "Input")
	 class UInputAction* IA_LeftTrigger;
	 UPROPERTY(EditAnywhere, Category = "Input")
	 class UInputAction* IA_RightThumbstick;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void Func1(const FInputActionValue& Value);
	UFUNCTION()
	void Func2(const FInputActionValue& Value);
	UFUNCTION()
	void Func3(const FInputActionValue& Value);

};
