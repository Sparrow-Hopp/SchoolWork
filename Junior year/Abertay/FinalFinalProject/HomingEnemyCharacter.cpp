// Fill out your copyright notice in the Description page of Project Settings.


#include "HomingEnemyCharacter.h"

// Sets default values
AHomingEnemyCharacter::AHomingEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHomingEnemyCharacter::BeginPlay()
{
	srand(time(NULL));
	Super::BeginPlay();
	
}

void AHomingEnemyCharacter::MyAIMoveTo(APawn* pawn, const FVector& destination, const APawn* TargetActor)
{
	/*if (TargetActor != NULL)
		pawn->AddMovementInput(TargetActor->GetActorLocation(), 1);
	else
		pawn->AddMovementInput(destination, 1);*/
}

float AHomingEnemyCharacter::MyRandomInRange(const int& min, const int& max)
{
	int range = max - min;
	return rand() % range + min;
}

void AHomingEnemyCharacter::MyDelay(const float& seconds)
{
	time_t curTime = time(0);
	while (time(0) - curTime < seconds)
	{

	}
}

FVector AHomingEnemyCharacter::myGetActorLocation(const AActor* target)
{
	return target->GetActorLocation();
}

FVector AHomingEnemyCharacter::myGetRandLocationInRadius(const FVector& origin, const int& radius)
{
	FVector randLocation;
	randLocation.X = rand() % (2 * radius) + origin.X - radius;
	randLocation.Y = rand() % (2 * radius) + origin.Y - radius;
	randLocation.Z = rand() % (2 * radius) + origin.Z - radius;
	return randLocation;
}

/*AActor* AHomingEnemyCharacter::myGetReferenceToSelf()
{

}*/

// Called every frame
void AHomingEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHomingEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

