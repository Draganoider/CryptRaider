#include "RMover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
URMover::URMover()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void URMover::BeginPlay()
{
	Super::BeginPlay();
	OriginalRotation = GetOwner()->GetActorRotation();
}

// Called every frame
void URMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FRotator TargetRotation = OriginalRotation;

	if (ShouldMove)
	{
		TargetRotation = OriginalRotation + RotateOffset;
	}

	FRotator CurrentRotation = GetOwner()->GetActorRotation();

	float Speed = RotateOffset.GetManhattanDistance(FRotator::ZeroRotator) / MoveTime;

	FRotator NewRotation = FMath::RInterpConstantTo(CurrentRotation, TargetRotation, DeltaTime, Speed);
	GetOwner()->SetActorRotation(NewRotation);
}

void URMover::SetShouldMove(bool NewShouldMove)
{
	ShouldMove = NewShouldMove;
}
