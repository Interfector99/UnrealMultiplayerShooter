// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerName(APawn* InPawn)
{
    if (!IsValid(InPawn)) 
    { 
        SetDisplayText(TEXT("")); 
        return; 
    }

    APlayerState* PlayerState = InPawn->GetPlayerState();
    if (!IsValid(PlayerState))
    {
        SetDisplayText(TEXT(""));
        return;
    }

    SetDisplayText(PlayerState->GetPlayerName());
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
