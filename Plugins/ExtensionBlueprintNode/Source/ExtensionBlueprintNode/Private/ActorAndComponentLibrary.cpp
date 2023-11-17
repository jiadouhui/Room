// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorAndComponentLibrary.h"

UActorComponent* UActorAndComponentLibrary::GetComponentByName(const AActor* Target,
	TSubclassOf<UActorComponent> ComponentType, FString Name)
{
	for (UActorComponent* Component : Target->K2_GetComponentsByClass(ComponentType))
	{
		if (Component->GetName() == Name) return Component;
	}
	return nullptr;
	
	
}
