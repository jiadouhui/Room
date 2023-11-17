// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ActorAndComponentLibrary.generated.h"

/**
 * 
 */
UCLASS()
class EXTENSIONBLUEPRINTNODE_API UActorAndComponentLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(DefaultToSelf="Target", DeterminesOutputType = "ComponentType", Category="Extension Node | Actor"))
	static UActorComponent* GetComponentByName(const AActor* Target, TSubclassOf<UActorComponent> ComponentType, FString Name);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(DefaultToSelf="Target", DeterminesOutputType = "ComponentType", Category="Extension Node | Component"))
	static UActorComponent* GetComponentByClassOnOwner(const UActorComponent* Target, TSubclassOf<UActorComponent> ComponentType)
		{ return Target->GetOwner()->GetComponentByClass(ComponentType); }
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(DefaultToSelf="Target", DeterminesOutputType = "ComponentType", Category="Extension Node | Component"))
	static TArray<UActorComponent*> GetComponentsByClassOnOwner(const UActorComponent* Target, TSubclassOf<UActorComponent> ComponentType)
		{ return Target->GetOwner()->K2_GetComponentsByClass(ComponentType); }
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(DefaultToSelf="Target", DeterminesOutputType = "InterfaceType", Category="Extension Node | Component"))
	static TArray<UActorComponent*> GetComponentsByInterfaceOnOwner(const UActorComponent* Target, TSubclassOf<UInterface> InterfaceType)
		{ return Target->GetOwner()->GetComponentsByInterface(InterfaceType); }
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(DefaultToSelf="Target", DeterminesOutputType = "ComponentType", Category="Extension Node | Component"))
	static TArray<UActorComponent*> GetComponentsByTagOnOwner(const UActorComponent* Target, TSubclassOf<UActorComponent> ComponentType, FName Tag)
		{ return Target->GetOwner()->GetComponentsByTag(ComponentType, Tag); }
		
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(DefaultToSelf="Target", DeterminesOutputType = "ComponentType", Category="Extension Node | Component"))
	static UActorComponent* GetComponentsByNameOnOwner(const UActorComponent* Target, TSubclassOf<UActorComponent> ComponentType, FString Name)
		{ return GetComponentByName(Target->GetOwner(), ComponentType, Name); }
};
