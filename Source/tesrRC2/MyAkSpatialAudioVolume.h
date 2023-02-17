// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AkSpatialAudioVolume.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Engine/TriggerVolume.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AkLateReverbComponent.h"
#include "tesrRC2Character.h"
#include "MyAkSpatialAudioVolume.generated.h"

/**
 * 
 */


UCLASS()
class TESRRC2_API AMyAkSpatialAudioVolume : public AAkSpatialAudioVolume
{
	GENERATED_BODY()

public:

	AMyAkSpatialAudioVolume();


protected:
	virtual void BeginPlay() override;


public:

	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(VisibleAnywhere, Category = "Test")
		class UBoxComponent* BoxC;

	UPROPERTY(VisibleAnywhere, Category = "Test")
		class AtesrRC2Character* tesrRC2Character;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
		bool bIsCharacter = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
		bool bDebugDraw = false;

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

};
