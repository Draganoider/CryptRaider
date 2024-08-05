#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Mover == nullptr && RMover == nullptr)
		return;

	AActor* Actor = GetAcceptableActor();

	if (Actor != nullptr)
	{
		UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
		if (Component != nullptr)
		{
			Component->SetSimulatePhysics(false);
		}

		Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);

		if (Mover != nullptr)
		{
			Mover->SetShouldMove(true);
		}
		else if (RMover != nullptr)
		{
			RMover->SetShouldMove(true);
		}
	}
	else
	{
		if (Mover != nullptr)
		{
			Mover->SetShouldMove(false);
		}
		else if (RMover != nullptr)
		{
			RMover->SetShouldMove(false);
		}
	}
}

void UTriggerComponent::SetMover(UMover* NewMover)
{
	Mover = NewMover;
	RMover = nullptr;  // Убедитесь, что RMover не установлен
}

void UTriggerComponent::SetRMover(URMover* NewRMover)
{
	RMover = NewRMover;
	Mover = nullptr;  // Убедитесь, что Mover не установлен
}

AActor* UTriggerComponent::GetAcceptableActor() const
{
	TArray<AActor *> Actors;
	GetOverlappingActors(Actors);

	for (AActor *Actor : Actors)
	{
		bool HasAcceptedActor = Actor->ActorHasTag(AcceptableActorTag);
		bool IsGrabbed = Actor->ActorHasTag("Grabbed");

		if (HasAcceptedActor && !IsGrabbed)
		{
			return Actor;
		}
	}

	return nullptr;
}
