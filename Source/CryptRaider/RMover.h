// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RMover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API URMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URMover();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetShouldMove(bool ShouldMove);

private:
	UPROPERTY(EditAnywhere)
	FRotator RotateOffset;

	UPROPERTY(EditAnywhere)
	float MoveTime = 4;

	bool ShouldMove = false;

	FRotator OriginalRotation;
};
