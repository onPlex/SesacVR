// Fill out your copyright notice in the Description page of Project Settings.


#include "GrabbableItem.h"
#include "MotionControllerComponent.h"

// Sets default values
AGrabbableItem::AGrabbableItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGrabbableItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrabbableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGrabbableItem::Grab(UMotionControllerComponent* GrabController)
{

}

void AGrabbableItem::Release()
{

}

