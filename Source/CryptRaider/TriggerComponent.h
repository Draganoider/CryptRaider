#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Mover.h"
#include "RMover.h"
#include "TriggerComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CRYPTRAIDER_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	UTriggerComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetMover(UMover *NewMover);

	UFUNCTION(BlueprintCallable)
	void SetRMover(URMover *NewRMover);

private:
	UPROPERTY(EditAnywhere)
	FName AcceptableActorTag;

	UMover *Mover;
	URMover *RMover;

	AActor *GetAcceptableActor() const;
};
