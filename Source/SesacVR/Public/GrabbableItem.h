// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction.h"
#include "GrabbableItem.generated.h"

UCLASS()
class SESACVR_API AGrabbableItem : public AActor, public IInteraction
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrabbableItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Grab(UMotionControllerComponent* GrabController) override;
	virtual void Release() override;


	UMotionControllerComponent* CurrentController;
};
