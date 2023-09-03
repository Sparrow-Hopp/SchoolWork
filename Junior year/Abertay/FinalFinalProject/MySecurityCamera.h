// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySecurityCamera.generated.h"

UCLASS()
class FINALPROJECT_API AMySecurityCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMySecurityCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float m_delayTime = 0.5;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
