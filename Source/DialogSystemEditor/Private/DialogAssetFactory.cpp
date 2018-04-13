// Copyright 2017-2018 Krivosheya Mikhail. All Rights Reserved.
#include "DialogSystemEditor.h"
#include "DialogAssetFactory.h"
#include "DialogEditorNodes.h"
#include "DialogAsset.h"
#include "DialogScript.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"

UDialogAssetFactory::UDialogAssetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UDialogAsset::StaticClass();
}

UObject* UDialogAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UDialogAsset* asset = NewObject<UDialogAsset>(InParent, Class, Name, Flags | RF_Transactional);
	asset->Name = Name;

	return asset;
}

bool UDialogAssetFactory::CanCreateNew() const
{
	return true;
}