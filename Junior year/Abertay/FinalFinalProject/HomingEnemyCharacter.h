// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "HomingEnemyCharacter.generated.h"

using namespace std;
UCLASS()
class FINALPROJECT_API AHomingEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHomingEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
		void MyAIMoveTo(APawn* pawn, const FVector& destination, const APawn* TargetActor);
	UFUNCTION(BlueprintPure)
		float MyRandomInRange(const int& min, const int& max);
	UFUNCTION(BlueprintCallable)
		void MyDelay(const float& time);
	UFUNCTION(BlueprintPure)
		FVector myGetActorLocation(const AActor* target);
	UFUNCTION(BlueprintPure)
		FVector myGetRandLocationInRadius(const FVector& origin, const int& radius);
	//UFUNCTION(BlueprintPure)
		//AActor* myGetReferenceToSelf();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool m_Can_See_Enemy = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int m_minWaitTime = 2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int m_maxWaitTime = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int m_radius = 500;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector m_nullVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float m_delayTime = 0.5;
};
