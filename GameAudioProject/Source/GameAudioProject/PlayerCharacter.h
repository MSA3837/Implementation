// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class GAMEAUDIOPROJECT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Camera
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* Camera;

	// Flashlight
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flashlight")
	class USpotLightComponent* Light;

	// Enhanced Input
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* MoveIAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* LookIAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* LightIAction;

	// Movement
	void Move(const struct FInputActionValue& Value);
	void Look(const struct FInputActionValue& Value);

private:
	bool LightState{ false };

	void FlashLight(const struct FInputActionValue& Value);
	void ToggleFlashLight();

};
