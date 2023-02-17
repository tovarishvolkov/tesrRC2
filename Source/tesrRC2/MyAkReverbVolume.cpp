// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAkReverbVolume.h"
#include "AkAudioDevice.h"
#include "AkLateReverbComponent.h"
#include "AkGameplayStatics.h"
#include "Components/BrushComponent.h"
#include "tesrRC2Character.h"
#include "GameFramework/Volume.h"
#include "Engine/Engine.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Model.h"




AMyAkReverbVolume::AMyAkReverbVolume()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxC = CreateDefaultSubobject<UBoxComponent>("BoxC");
	BoxC->SetCollisionProfileName(TEXT("Trigger"));
	BoxC->SetupAttachment(RootComponent);
	BoxC->InitBoxExtent(GetActorScale() * 100);
	BoxC->SetCollisionResponseToAllChannels(ECR_Overlap);
	
	OnActorBeginOverlap.AddDynamic(this, &AMyAkReverbVolume::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AMyAkReverbVolume::OnOverlapEnd);

	
	
	
}
void AMyAkReverbVolume::BeginPlay()
{
	Super::BeginPlay();

	bIsCharacter = false;
	tesrRC2Character = Cast<AtesrRC2Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	UAkGameplayStatics::SetState(nullptr, "chr_indoor", "chr_outdoor");

	DrawDebugBox(GetWorld(), GetActorLocation(), GetActorScale() * 100, FColor::Cyan, true, -1, 0, 5);

}

void AMyAkReverbVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

		if (this->IsOverlappingActor(tesrRC2Character))
		{
			//UE_LOG(LogTemp, Display, TEXT("Other Actor NotOut = %s"), *tesrRC2Character->GetName())
			bIsCharacter = true;
			UAkGameplayStatics::SetState(nullptr, "chr_indoor", "chr_indoor");
		}

}

void AMyAkReverbVolume::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this)) {

		bIsCharacter = true;
		UAkGameplayStatics::SetState(nullptr, "chr_indoor", "chr_indoor");
		UE_LOG(LogTemp, Display, TEXT("Other Actor = %s"), *OtherActor->GetName())
	}
} 

void AMyAkReverbVolume::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this) )
	{
		bIsCharacter = false;
		UAkGameplayStatics::SetState(nullptr, "chr_indoor", "chr_outdoor");
		UE_LOG(LogTemp, Display, TEXT("Other Actor NotOut = %s"), *OtherActor->GetName())
	}
}






