// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "UMGPrivatePCH.h"

/////////////////////////////////////////////////////
// USlateWrapperComponent

USlateWrapperComponent::USlateWrapperComponent(const FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	bIsEnabled = true;
	bIsVariable = true;
}

bool USlateWrapperComponent::GetIsEnabled() const
{
	return MyWidget.IsValid() ? MyWidget->IsEnabled() : bIsEnabled;
}

void USlateWrapperComponent::SetIsEnabled(bool bInIsEnabled)
{
	bIsEnabled = bInIsEnabled;
	if ( MyWidget.IsValid() )
	{
		MyWidget->SetEnabled(bInIsEnabled);
	}
}

void USlateWrapperComponent::OnRegister()
{
	Super::OnRegister();
}

void USlateWrapperComponent::OnUnregister()
{
	MyWidget = NULL;
	Super::OnUnregister();
}

void USlateWrapperComponent::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	// TODO Rename?
}

TSharedRef<SWidget> USlateWrapperComponent::GetWidget()
{
	if ( !MyWidget.IsValid() )
	{
		MyWidget = RebuildWidget();
		MyWidget->SetEnabled(bIsEnabled);
	}

	return MyWidget.ToSharedRef();
}

TSharedRef<SWidget> USlateWrapperComponent::RebuildWidget()
{
	ensureMsg(false, TEXT("You must implement RebuildWidget() in your child class"));
	return SNullWidget::NullWidget;
}

EVisibility USlateWrapperComponent::ConvertSerializedVisibilityToRuntime(TEnumAsByte<ESlateVisibility::Type> Input)
{
	switch ( Input )
	{
	case ESlateVisibility::Visible:
		return EVisibility::Visible;
	case ESlateVisibility::Collapsed:
		return EVisibility::Collapsed;
	case ESlateVisibility::Hidden:
		return EVisibility::Hidden;
	case ESlateVisibility::HitTestInvisible:
		return EVisibility::HitTestInvisible;
	case ESlateVisibility::SelfHitTestInvisible:
		return EVisibility::SelfHitTestInvisible;
	default:
		check(false);
		return EVisibility::Visible;
	}
}

FSizeParam USlateWrapperComponent::ConvertSerializedSizeParamToRuntime(const FSlateChildSize& Input)
{
	switch ( Input.SizeRule )
	{
	default:
	case ESlateSizeRule::Automatic:
		return FAuto();
	case ESlateSizeRule::Fill:
		return FStretch(Input.Value);
	}
}